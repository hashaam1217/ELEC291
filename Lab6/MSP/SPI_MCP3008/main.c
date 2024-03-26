// This program uses SPI to communicate with the MCP3008 ADC.
//
// Here is the wiring between the MSP430G2553 and the MCP3008.  There is also
// a picture attached to this project that shows the actual working circuit.
//
// P1.6 (pin 14 of DIP 20) – UCB0SOMI (MISO) -> Pin 12 of MCP3008
// P1.7 (pin 15 of DIP 20) – UCB0SIMO (MOSI) -> Pin 11 of MCP3008
// P1.5 (pin 7  of DIP 20) – UCB0CLK  (SCLK) -> Pin 13 of MCP3008
// P1.0 (pin 2  of DIP 20) - (CSn)           -> Pin 9  of MCP3008
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

#define RXD BIT1 // Receive Data (RXD) at P1.1
#define TXD BIT2 // Transmit Data (TXD) at P1.2
#define CLK 16000000L
#define BAUD 115200
#define SPI_CLK 100000L

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
    while (!(IFG2&UCA0RXIFG)); // USCI_A0 RX buffer ready?
	return UCA0RXBUF;
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
	UCB0CTL0 |=  UCMSB + UCMST + UCSYNC;  // Mode (0,0), 3-pin Master, 8-bit, MSB first.
	UCB0CTL1 |= UCSSEL_2; // SMCLK
	UCB0BR0 = (CLK/SPI_CLK)%0x100;
	UCB0BR1 = (CLK/SPI_CLK)/0x100; 
	UCB0CTL1 &= ~UCSWRST; // Initialize USCI state machine.
}

// Read 10 bits from the MCP3008 ADC converter using the recommended
// format in the datasheet.
unsigned int volatile GetADC(char channel)
{
	unsigned int adc;
	
	P1OUT &= ~BIT0; // Select/enable ADC.
	__delay_cycles(50);
	
	UCB0TXBUF = 0x01; // Transmit start bit.
	while(UCB0STAT & UCBUSY); // Wait for transmission to end.

	UCB0TXBUF=((channel*0x10)|0x80); // Send single/diff* bit, D2, D1, and D0 bits.
	while(UCB0STAT & UCBUSY); // Wait for transmission to end.
	adc=((UCB0RXBUF & 0x03)*0x100); // UCB0RXBUF contains the high part of the result.
	
	UCB0TXBUF=(0x55); // Dummy transmission to get low part of result.
	while(UCB0STAT & UCBUSY); // Wait for transmission to end.
	adc+=UCB0RXBUF; // UCB0RXBUF contains the low part of the result.

	P1OUT |= BIT0;  // Deselect ADC.
	
	return adc;
}

// The Voltage reference input to the MCP3008.  For best results, measure it and put here.
#define VREF 3.3

int main(void)
{    
    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT.
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO.
	  	DCOCTL  = CALDCO_16MHZ;
	}

    uart_init();
	set_stdout_to(uart_putc);
    Initialize_SPI();

	delayMs(1000); // Give PuTTY a chance to start before sending text.
	
	printf("\x1b[2J\x1b[1;1H"); // Clear screen using ANSI escape sequence.
	printf ("MCP3008 SPI test program\r\n"
	        "File: %s\r\n"
	        "Compiled: %s, %s\r\n\r\n",
	        __FILE__, __DATE__, __TIME__);
    
    while(1)
	{
		printf("V0=%5.3f, V1=%5.3f\r", (GetADC(0)*VREF)/1023.0, (GetADC(1)*VREF)/1023.0);
		delayMs(500);
	}

}

