//  blink.c: MSP430 Blink example.  Connect LED+resistor to P1.0 (pin 2 of MSP430G2553 20 DIP)

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

#define LED_BLINK_FREQ_HZ 1 //LED blinking frequency
#define LED_DELAY_CYCLES (1000000 / (2 * LED_BLINK_FREQ_HZ)) // Number of cycles to delay based on 1MHz MCLK

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT
	P1DIR |= 0x01;            // Configure P1.0 as output
	while (1)
	{
	    __delay_cycles(LED_DELAY_CYCLES); // Wait for LED_DELAY_CYCLES cycles
	    P1OUT ^= 0x01; // Toggle P1.0 output
	}
}

