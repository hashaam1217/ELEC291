//  Period.c: Use TA0 free running counter to measure the period of the signal at pin P2.2 (pin 10).
//
//  By Jesus Calvino-Fraga (c) 2018-2023

#include <msp430.h>				

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

#define CCR_1MS_RELOAD (16000000L/1000L)
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

char HexDigit[]="0123456789ABCDEF";

void PrintNumber(long int val, int Base, int digits)
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

// Use TA0 configured as a free running timer to delay 1 ms
void wait_1ms (void)
{
	unsigned int saved_TA0R;
	
	saved_TA0R=TA0R; // Save timer A0 free running count
	while ((TA0R-saved_TA0R)<(16000000L/1000L));
}

void waitms(int ms)
{
	while(--ms) wait_1ms();
}

#define PIN_PERIOD ( P2IN & BIT2 ) // Read period from pin P2.2

// GetPeriod() seems to work fine for frequencies between 30Hz and 300kHz.
long int GetPeriod (int n)
{
	int i, overflow;
	unsigned int saved_TCNT1a, saved_TCNT1b;
	
	overflow=0;
	TA0CTL&=0xfffe; // Clear the overflow flag
	while (PIN_PERIOD!=0) // Wait for square wave to be 0
	{
		if(TA0CTL&1) { TA0CTL&=0xfffe; overflow++; if(overflow>5) return 0;}
	}
	overflow=0;
	TA0CTL&=0xfffe; // Clear the overflow flag
	while (PIN_PERIOD==0) // Wait for square wave to be 1
	{
		if(TA0CTL&1) { TA0CTL&=0xfffe; overflow++; if(overflow>5) return 0;}
	}
	
	overflow=0;
	TA0CTL&=0xfffe; // Clear the overflow flag
	saved_TCNT1a=TA0R;
	for(i=0; i<n; i++) // Measure the time of 'n' periods
	{
		while (PIN_PERIOD!=0) // Wait for square wave to be 0
		{
			if(TA0CTL&1) { TA0CTL&=0xfffe; overflow++; if(overflow>1024) return 0;}
		}
		while (PIN_PERIOD==0) // Wait for square wave to be 1
		{
			if(TA0CTL&1) { TA0CTL&=0xfffe; overflow++; if(overflow>1024) return 0;}
		}
	}
	saved_TCNT1b=TA0R;
	if(saved_TCNT1b<saved_TCNT1a) overflow--; // Added an extra overflow.  Get rid of it.

	return overflow*0x10000L+(saved_TCNT1b-saved_TCNT1a);
}

int main(void)
{
	long int count;
	float T, f;
	
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    
    if (CALBC1_16MHZ != 0xFF) // Warning: calibration lost after mass erase
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}

	// Configure TA0 as a free running timer.  See page 370 of SLAU144J (MSP430x2xx Family User's Guide)
    TA0CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
	TA0R; // Timer A0 free running count
	
	// Configure P2.2.  Check section 8.2 of the reference manual (slau144j.pdf)
	P2DIR &= ~(BIT2); // P2.2 is an input	
	P2OUT |= BIT2;    // Select pull-up for P2.2
	P2REN |= BIT2;    // Enable pull-up for P2.2

    uart_init();
	
	waitms(500); // Wait for putty to start.
	uart_puts("Period measurement using the free running counter of timer TA0.\n"
	          "Connect signal to P2.2 (pin 10).\n");

	while(1)
	{
		count=GetPeriod(100);
		if(count>0)
		{
			T=count/(CLK*100.0);
			f=1/T;
			uart_puts("f=");
			PrintNumber(f, 10, 6);
			uart_puts("Hz, count=");
			PrintNumber(count, 10, 6);
			uart_puts("        \r");
		}
		else
		{
			uart_puts("NO SIGNAL                     \r");
		}
		waitms(200);
	}
}

