#include <msp430.h>
#include <stdio.h>
#include "lcd.h"

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
// The LCD signals are connected to the following pins:
//
//     (pin 1) GND --- GND
//      (pin 2) 5V --- 5V
//      (pin 3) V0 --- 2k + GND
//  (pin 4) LCD_RS --- P2.3 (pin 11)
//  (pin 5) LCD_RW --- GND
//  (pin 6) LCD_E  --- P2.4 (pin 12)
// (pin 11) LCD_D4 --- P2.5 (pin 13)
// (pin 12) LCD_D5 --- P1.6 (pin 14)
// (pin 13) LCD_D6 --- P1.7 (pin 15)
// (pin 14) LCD_D7 --- P2.7 (pin 18)
// 

#define RXD BIT1 // Receive Data (RXD) at P1.1
#define TXD BIT2 // Transmit Data (TXD) at P1.2
#define BAUD 115200

void TA0_init(void)
{
    TA0CCR0 = 0;
	// Configure TA0 as a free running timer.  See page 370 of SLAU144J (MSP430x2xx Family User's Guide)
    TA0CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
	TA0R; // Timer A0 free running count
}	

void uart_init(void)
{
	P1SEL  |= (RXD | TXD);                       
  	P1SEL2 |= (RXD | TXD);                       
  	UCA0CTL1 |= UCSSEL_2; // SMCLK
  	UCA0BR0 = (F_CPU/BAUD)%0x100;
  	UCA0BR1 = (F_CPU/BAUD)/0x100;
  	UCA0MCTL = UCBRS0; // Modulation UCBRSx = 1
  	UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine
}

unsigned char uart_getc(void)
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

unsigned int uart_gets(char *str, unsigned int max)
{
	char c;
	unsigned int cnt=0;
	while(1)
	{
	    c=uart_getc();
	    uart_putc(c); // echo back
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

void ConfigurePins(void)
{
	// Pin 18 is configured as XOUT by default. Configure it as P2.7:
	P2SEL2 &= ~BIT7;
	P2SEL  &= ~BIT7;
	
	// Configure pins connected to the LCD as outputs:
	P2DIR |= (BIT3 | BIT4 | BIT5 | BIT7); // Configure P2.3, P2.4, P2.5, and P2.7 as outputs (pins 11, 12, 13, and 18)
	P1DIR |= (BIT6 | BIT7); // Configure P1.6 and P1.7 as output (pins 14 and 15)
}

// In order to keep this as nimble as possible, avoid
// using floating point or printf on any of its forms!
int main(void)
{
	char buff[17];
	
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
	
	ConfigurePins();
    uart_init();
    TA0_init(); // Timer A0 Used for timming
	LCD_4BIT();
	
	waitms(500); // Give time to PuTTy to start.
	uart_puts("\x1b[2J\x1b[1;1H"); // Clear screen using ANSI escape sequence.
	uart_puts("\n4-bit mode LCD test using the MSP430G2553\n");
	
   	// Display something in the LCD
	LCDprint("LCD 4-bit test:", 1, 1);
	LCDprint("Hello, World!", 2, 1);
	while(1)
	{
		uart_puts("Type what you want to display in line 2 (16 char max): ");
		uart_gets(buff, sizeof(buff));
		uart_puts("\r\n");
		LCDprint(buff, 2, 1);
	}
}