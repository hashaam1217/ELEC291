#include <msp430.h>
#include <stdio.h>

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

uint16_t ReadADC(uint8_t channel)
{
	ADC10CTL0 &= ~ENC; // disable ADC
	ADC10CTL0 = SREF_0 + ADC10SHT_3 + REFON + ADC10ON; // Use Vcc (around 3.3V) as reference
	ADC10AE0 |= (1<<channel);
	ADC10CTL1 = channel<<12;
	__delay_cycles(64); // Delay to allow Ref/Channel to settle
	ADC10CTL0 |= ENC + ADC10SC;    // Sampling and conversion start
	while (ADC10CTL1 & ADC10BUSY); // ADC10BUSY?
	return ADC10MEM;
}

#define PIN_PERIOD ( P1IN & BIT7 ) // Read period from P1.7 (pin 15)

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

void ConfigurePins(void)
{
	// Configure P1.7.  Check section 8.2 of the reference manual (slau144j.pdf)
	P1DIR &= ~(BIT7); // P1.7 is an input	
	P1OUT |= BIT7;    // Select pull-up for P1.7
	P1REN |= BIT7;    // Enable pull-up for P1.7
	
	// Configure output pins
	P2DIR |= 0b00111111; // Configure P2.0 to P2.5 (pins 8 to 13) as outputs
	P1DIR |= BIT6; // Configure P1.6 as output (pin 14)
}

// In order to keep this as nimble as possible, avoid
// using floating point or printf on any of its forms!
int main(void)
{
	volatile unsigned long int i; // volatile to prevent optimization
	char buff[16];
	uint16_t adc_val;
	unsigned long int v;
	long int count;
	long int f;
	uint8_t LED_toggle=0;
	
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
	
	// Configure TA0 as a free running timer.  See page 370 of SLAU144J (MSP430x2xx Family User's Guide)
    TA0CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
	TA0R; // Timer A0 free running count
	
	ConfigurePins();
    uart_init();
	
	waitms(500); // Give PuTTy time to start.
	uart_puts("\x1b[2J\x1b[1;1H"); // Clear screen using ANSI escape sequence.
	uart_puts("\nMSP430G2553 multi I/O example.\n");
	uart_puts("Measures the voltage at channels A0 and A3 (pins 2 and 5 of DIP20 package)\n");
	uart_puts("Measures period on P1.7 (pin 15 of DIP20 package)\n");
	uart_puts("Toggles P2.0, P2.1, P2.2, P2.3, P2.4, P2.5, P1.6 (pins 8, 9, 10, 11, 12, 13, 14 of DIP20 package)\n");
	
	while (1)
	{
		adc_val=ReadADC(0);
		uart_puts("ADC[A0]=0x");
		PrintNumber(adc_val, 16, 3);
		uart_puts(", ");
		v=(adc_val*3290L)/1023L; // 3.290 is VDD
		PrintNumber(v/1000, 10, 1);
		uart_puts(".");
		PrintNumber(v%1000, 10, 3);
		uart_puts("V ");

		adc_val=ReadADC(3);
		uart_puts("ADC[A3]=0x");
		PrintNumber(adc_val, 16, 3);
		uart_puts(", ");
		v=(adc_val*3290L)/1023L; // 3.290 is VDD
		PrintNumber(v/1000, 10, 1);
		uart_puts(".");
		PrintNumber(v%1000, 10, 3);
		uart_puts("V ");

		count=GetPeriod(100);
		if(count>0)
		{
			f=(CLK*100L)/count;
			uart_puts("f=");
			PrintNumber(f, 10, 6);
			uart_puts("Hz, count=");
			PrintNumber(count, 10, 6);
			uart_puts("\r");
		}
		else
		{
			uart_puts("NO SIGNAL                     \r");
		}
		
		// Now toggle the pins on/off to see if they are working.
		// First turn all off:
		P1OUT &= ~BIT6;
		P2OUT &= ~BIT5;
		P2OUT &= ~BIT4;
		P2OUT &= ~BIT3;
		P2OUT &= ~BIT2;
		P2OUT &= ~BIT1;
		P2OUT &= ~BIT0;
		// Now turn on one of them
		switch (LED_toggle++)
		{
			case 1: // P2.0 on all other off
				P2OUT |= BIT0;
				break;
			case 2: // P2.1 on all other off
				P2OUT |= BIT1;
				break;
			case 3: // P2.2 on all other off
				P2OUT |= BIT2;
				break;
			case 4: // P2.3 on all other off
				P2OUT |= BIT3;
				break;
			case 5: // P2.4 on all other off
				P2OUT |= BIT4;
				break;
			case 6: // P2.5 on all other off
				P2OUT |= BIT5;
				break;
			case 7: // P1.6 on all other off
				P1OUT |= BIT6;
				break;
			default:
				break;
		}
		if(LED_toggle>7) LED_toggle=0;
		
		waitms(200);
	}
}