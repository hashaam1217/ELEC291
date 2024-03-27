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

typedef void (*pfn_outputchar)(char c);
void set_stdout_to(pfn_outputchar p);
int printf2 (const char *format, ...);

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

// Use TA0 configure as a free running timer to delay 1 ms
void wait_1ms (void)
{
	unsigned int saved_TA0R;

	// Configure TA0 as a free running timer.  See page 370 of SLAU144J (MSP430x2xx Family User's Guide)
	TA0CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
	TA0R; // Timer A0 free running count
	
	saved_TA0R=TA0R;
	while ((TA0R-saved_TA0R)<(16000000L/1000L));
}

void waitms(int ms)
{
	while(--ms) wait_1ms();
}

int main(void)
{
    char buff[20];
    double x=1.23456789012345;
    
    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
 
	P1DIR |= (BIT0 | BIT6); 		// P1.0 and P1.6 are the red+green LEDs	
	P1OUT |= (BIT0 | BIT6); 		// All LEDs off

    uart_init();
	set_stdout_to(uart_putc);
	
	waitms(500);

	printf("printf() tests.\n");

	printf("float: %f\n", (float)(355.0/113.0));
	printf("float: %g\n", (float)(355.0/113.0));
	printf("float: %e\n", (float)(355.0/113.0));
	printf("float: %e\n", 0.1);
	printf("float: %f\n", 0.1);
	printf("float: %g\n", 0.1);
	printf("string: %s\n", "my string");
	printf("int: %d\n", 42);
	printf("int: %08x\n", 0xABCD);
	printf("char: %c\n", 'a');
	printf("pointer: %p\n", "some string");
	
	printf(" %08.3f, %8.3f, %20.6e, %15.8E\n", 355.0/113.0, 355.0/113.0, -355.0/113.0, (355.0/113.0)*1.0e22);
	sprintf(buff, "%+10.2f", 355.0/113.0);
	printf("Created string:`%s`\n", buff);
	printf("double: %20.16lf\n", x);
	
    while(1)
    {
		P1OUT ^= BIT0;
		waitms(500);
    } 
}
