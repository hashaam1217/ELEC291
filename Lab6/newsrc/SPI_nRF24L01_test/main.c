// This program uses SPI to communicate with the nRF24L01.
//
// Jesus Calvino-Fraga (2018-2020)
//
// MSP430G2553 DIP20 pinout:
//                                                     -------
//                                              DVCC -|1    20|- DVSS
//                           P1.0/TA0CLK/ACLK/A0/CA0 -|2    19|- XIN/P2.6/TA0.1
//                P1.1/TA0.0/UCA0RXD/UCA0SOMI/A1/CA1 -|3    18|- XOUT/P2.7
//                P1.2/TA0.1/UCA0TXD/UCA0SIMO/A2/CA2 -|4    17|- TEST/SBWTCK
//           P1.3/ADC10CLK/CAOUT/VREF-/VEREF-/A3/CA3 -|5    16|- RST/NMI/SBWTDIO
//P1.4/SMCLK/UCB0STE/UCA0CLK/VREF+/VEREF+/A4/CA4/TCK -|6    15|- P1.7/CAOUT/UCB0SIMO/UCB0SDA/A7/CA7/TDO/TDI
//             P1.5/TA0.0/UCB0CLK/UCA0STE/A5/CA5/TMS -|7    14|- P1.6/TA0.1/UCB0SOMI/UCB0SCL/A6/CA6/TDI/TCLK
//                                        P2.0/TA1.0 -|8    13|- P2.5/TA1.2
//                                        P2.1/TA1.1 -|9    12|- P2.4/TA1.2
//                                        P2.2/TA1.1 -|10   11|- P2.3/TA1.0
//                                                     -------

#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nrf24.h"

#define RXD BIT1 // Receive Data (RXD) at P1.1
#define TXD BIT2 // Transmit Data (TXD) at P1.2
#define CLK 16000000L
#define BAUD 115200
#define SPI_CLK 2000000L

typedef void (*pfn_outputchar)(char c);
void set_stdout_to(pfn_outputchar p);
int printf2 (const char *format, ...);

#define DELAY_FREQ_HZ 1000 // 1ms
#define MS_DELAY_CYCLES (CLK / DELAY_FREQ_HZ) // Number of cycles to delay based on CLK.

void delayMs(int len)
{
	while(len--) // Wait the desired number of ms.
	{
	    __delay_cycles(MS_DELAY_CYCLES); 
	}
}

void uart_init(void)
{
	P1SEL  |= (RXD | TXD);                       
  	P1SEL2 |= (RXD | TXD);                       
  	UCA0CTL1 |= UCSSEL_2; // SMCLK.
  	UCA0BR0 = (CLK/BAUD)%0x100;
  	UCA0BR1 = (CLK/BAUD)/0x100;
  	UCA0MCTL = UCBRS0; // Modulation UCBRSx = 1.
  	UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine.
}

unsigned char uart_getc()
{
	char c;
    while (!(IFG2&UCA0RXIFG)); // USCI_A0 RX buffer ready?
    c=UCA0RXBUF;
	while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
  	UCA0TXBUF = c; // echo
    
	return c;
}

void uart_putc (char c)
{
	if(c=='\n')
	{
		while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
	  	UCA0TXBUF = '\r'; // TX
  	}
	while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
  	UCA0TXBUF = c; // TX
}

void uart_puts(const char *str)
{
     while(*str) uart_putc(*str++);
}

void Initialize_SPI (void)
{
	unsigned char channel=0;
	unsigned int adc;
	
	// Connect the MISO/MOSI/SCLK pins to the SPI module.
	P1SEL |= BIT5 + BIT6 + BIT7;
	P1SEL2 |= BIT5 + BIT6 + BIT7;
	
	// Using P1.0 for CEn.
	P1DIR |= 0x01;  // Configure P1.0 as output.
	P1OUT |= BIT0;  // deselect ADC.
	
	UCB0CTL1 = UCSWRST; // Reset USCI state machine.
	UCB0CTL0 |=  UCCKPH + UCMSB + UCMST + UCSYNC;  // Mode (0,1), 3-pin Master, 8-bit, MSB first.
	UCB0CTL1 |= UCSSEL_2; // SMCLK
	UCB0BR0 = (CLK/SPI_CLK)%0x100;
	UCB0BR1 = (CLK/SPI_CLK)/0x100; 
	UCB0CTL1 &= ~UCSWRST; // Initialize USCI state machine.
}

uint8_t spi_transfer(uint8_t tx)
{
	UCB0TXBUF = tx; // Transmit.
	while(UCB0STAT & UCBUSY); // Wait for transmission to end.
	return UCB0RXBUF;
}

void safe_gets(char *s, int n)
{
	unsigned char j=0;
	unsigned char c;
	
	while(1)
	{
		c=uart_getc();
		if ( (c=='\n') || (c=='\r') ) break;
		if(j<(n-1))
		{
			s[j]=c;
			j++;
		}
	}
	s[j]=0;
}

uint8_t temp;
uint8_t data_array[32];
uint8_t tx_address[] = "TXADD";
uint8_t rx_address[] = "RXADD";

int main(void)
{    
    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT.
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO.
	  	DCOCTL  = CALDCO_16MHZ;
	}

 	// Configure P2.3.  Check section 8.2 of the reference manual (slau144j.pdf)
	P2DIR &= ~(BIT3); // P2.3 is an input	
	P2OUT |= BIT3;    // Select pull-up for P2.3
	P2REN |= BIT3;    // Enable pull-up for P2.3
 	// Configure P1.4.  Check section 8.2 of the reference manual (slau144j.pdf)
	P1DIR &= ~(BIT4); // P1.4 is an input	
	P1OUT |= BIT4;    // Select pull-up for P1.4
	P1REN |= BIT4;    // Enable pull-up for P1.4

    uart_init();
	set_stdout_to(uart_putc);
    Initialize_SPI();

	delayMs(1000); // Give PuTTY a chance to start before sending text.
	
	printf("\x1b[2J\x1b[1;1H"); // Clear screen using ANSI escape sequence.
	printf ("nRF24 SPI test program\r\n"
	        "File: %s\r\n"
	        "Compiled: %s, %s\r\n\r\n",
	        __FILE__, __DATE__, __TIME__);
    
    nrf24_init(); // init hardware pins
    nrf24_config(120,32); // Configure channel and payload size

    /* Set the device addresses */
    if(P1IN&BIT4)
    {
    	printf("Set as transmitter\r\n");
	    nrf24_tx_address(tx_address);
	    nrf24_rx_address(rx_address);
    }
    else
    {
    	printf("Set as receiver\r\n");
	    nrf24_tx_address(rx_address);
	    nrf24_rx_address(tx_address);
    }

    while(1)
    {    
        if(nrf24_dataReady())
        {
            nrf24_getData(data_array);
        	printf("IN: %s\r\n", data_array);
        }
        
        if(IFG2&UCA0RXIFG) // Something arrived from the serial port?
        {
        	safe_gets(data_array, sizeof(data_array));
		    printf("\r\n");    
	        nrf24_send(data_array);        
		    while(nrf24_isSending());
		    temp = nrf24_lastMessageStatus();
			if(temp == NRF24_MESSAGE_LOST)
		    {                    
		        printf("> Message lost\r\n");    
		    }
			nrf24_powerDown();
    		nrf24_powerUpRx();
		}
		
		if((P2IN&BIT3)==0)
		{
			while((P2IN&BIT3)==0);
			strcpy(data_array, "Button test");
	        nrf24_send(data_array);
		    while(nrf24_isSending());
		    temp = nrf24_lastMessageStatus();
			if(temp == NRF24_MESSAGE_LOST)
		    {                    
		        printf("> Message lost\r\n");    
		    }
			nrf24_powerDown();
    		nrf24_powerUpRx();
		}
    }

}

