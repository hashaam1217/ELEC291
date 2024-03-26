//  Tone.c: Use TIMERA0 CCRO ISR to produce a tone at P1.0
//
//  By Jesus Calvino-Fraga (c) 2018-2023
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

volatile unsigned int CCR0_reload;

#define RXD BIT1 // Receive Data (RXD) at P1.1
#define TXD BIT2 // Transmit Data (TXD) at P1.2
#define CLK 16000000L
#define BAUD 115200

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

unsigned char uart_getc()
{
	unsigned char c;
    while (!(IFG2&UCA0RXIFG)); // USCI_A0 RX buffer ready?
    c=UCA0RXBUF;
    uart_putc(c);
	return UCA0RXBUF;
}

void uart_puts(const char *str)
{
	while(*str) uart_putc(*str++);
}

unsigned int uart_gets(char *str, unsigned int max)
{
	char c;
	unsigned int cnt=0;
	while(1)
	{
	    c=uart_getc();
	    if( (c=='\n') || (c=='\r') )
	    {
	    	*str=0;
	    	break;
	    }
		*str=c;
		str++;
		cnt++;
		if(cnt==(max-1))
		{
		    *str=0;
	    	break;
		}
	}
	return cnt;
}

char HexDigit[]="0123456789ABCDEF";

void PrintNumber(unsigned long int val, int Base, int digits)
{ 
	int j;
	#define NBITS 32
	char buff[NBITS+1];
	buff[NBITS]=0;

	j=NBITS-1;
	while ( (val>0) | (digits>0) )
	{
		buff[j--]=HexDigit[val%Base];
		val/=Base;
		if(digits!=0) digits--;
	}
	uart_puts(&buff[j+1]);
}

#define DELAY_FREQ_HZ 1000 // 1ms
#define MS_DELAY_CYCLES (CLK / DELAY_FREQ_HZ) // Number of cycles to delay based on CLK

void delayms(int len)
{
	while(len--) // Wait the desired number of ms
	{
	    __delay_cycles(MS_DELAY_CYCLES); 
	}
}

int main(void)
{
	char buff[0x20];
	unsigned long int frequency=1000;
	unsigned long int actual_f;
	
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
	P1DIR |= 0x01; // Set P1.0 to output direction (pin 2 of DIP-20)
    
    if (CALBC1_16MHZ != 0xFF) // Warning: calibration lost after mass erase
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
    uart_init();

	CCR0_reload=(16000000L/(2L*frequency));
	
    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CCR0 = CCR0_reload;
    TA0CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
    _BIS_SR(GIE); // Enable interrupt

	delayms(500); // Give putty some time to start before sending text.
	uart_puts("\nTone generator program.  The signal comes out of P1.0 (pin 2)\n");
	while(1)
	{
	    uart_puts("\nDesired frequency: ");
		uart_gets(buff, 0x20-1);
		frequency=atol(buff);
		CCR0_reload=16000000L/(2L*frequency);
		actual_f=16000000L/(2L*CCR0_reload);
		uart_puts("\nGenerated frequency: ");
		PrintNumber(actual_f, 10, 6);
		uart_puts("\n");
	}
}

// Timer0 A0 interrupt service routine (ISR).  Only used by CC0.  
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer0_A0_ISR (void)
{
   TA0CCR0 += CCR0_reload; // Add Offset to CCR0
   P1OUT ^= 0x01;
}

