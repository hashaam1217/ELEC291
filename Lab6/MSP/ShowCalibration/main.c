#include <msp430.h>
#include <stdio.h>
#include "uart.h"

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

#define RXD BIT1 // Receive Data (RXD) at P1.1
#define TXD BIT2 // Transmit Data (TXD) at P1.2
#define CLK 16000000L
#define BAUD 115200

void uart_puts(const char *str);
//char pfbuf[128]; // used by sprintf()
//#define printf(...) sprintf(pfbuf, __VA_ARGS__); uart_puts(pfbuf)

void uart_init(void)
{
	P1SEL  |= (RXD | TXD);                       
  	P1SEL2 |= (RXD | TXD);                       
  	UCA0CTL1 |= UCSSEL_2; // SMCLK
  	UCA0BR0 = (CLK/BAUD)%0x100;
  	UCA0BR1 = (CLK/BAUD)/0x100;
  	UCA0MCTL = UCBRS0; // Modulation UCBRSx = 1
  	UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine
}

unsigned char uart_getc()
{
    while (!(IFG2&UCA0RXIFG)); // USCI_A0 RX buffer ready?
	return UCA0RXBUF;
}

void uart_putc(unsigned char c)
{
	while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
  	UCA0TXBUF = c; // TX
}

void uart_puts(const char *str)
{
     while(*str) uart_putc(*str++);
}

char ASCII[]="0123456789ABCDEF";

void OutByte(unsigned char c)
{
	uart_putc(ASCII[c/0x10]);
	uart_putc(ASCII[c%0x10]);
}

void Out_hex (unsigned int Flash_Start, unsigned int Flash_Len)
{
	unsigned int k, chksum;
	unsigned int long j;
	unsigned char * p;
	
	p=(unsigned char *)Flash_Start;
	
	for(j=0; j<Flash_Len; j+=16)
	{
		uart_putc(':');
		OutByte(0x10);
		k=Flash_Start+j;
		OutByte((k/0x100));				
		OutByte((k%0x100));				
		OutByte(0x00);				
		chksum=0x10+(k/0x100)+(k%0x100);
		for(k=0; k<16; k++)
		{
			OutByte(p[j+k]);
			chksum+=p[j+k];
		}
		OutByte(-chksum&0xff);
		uart_putc('\n');
		uart_putc('\r');
	}
	uart_puts(":00000001FF\n\r"); // End record
}

#define DELAY_FREQ_HZ 1000 // 1ms
#define MS_DELAY_CYCLES (CLK / DELAY_FREQ_HZ) // Number of cycles to delay based on CLK

void delayms(int len)
{
	unsigned char k;
	
	while(len--) // Wait the desired number of ms
	{
	    __delay_cycles(MS_DELAY_CYCLES); 
	}
}

int main(void)
{   
    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
 
	P1DIR |= (BIT0 | BIT6); 		// P1.0 and P1.6 are the red+green LEDs	
	P1OUT |= (BIT0 | BIT6); 		// All LEDs off

    uart_init();

	delayms(500); // Give some time to putty to start
    uart_puts((char *)"Info memory (using Intel's HEX format):\n\r");
	Out_hex(0x1000, 0x100);

    uart_puts("Jump table and interrupt vector table:\n\r");
	Out_hex((unsigned int)0xff80, 0x80);
	
    while(1)
    {
		P1OUT ^= BIT0;
		delayms(500);
    } 
}

