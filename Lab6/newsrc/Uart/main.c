/*
 * This file is part of the MSP430 hardware UART example.
 *
 * Copyright (C) 2012 Stefan Wendler <sw@kaltpost.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/******************************************************************************
 * Hardware UART example for MSP430.
 *
 * Stefan Wendler
 * sw@kaltpost.de
 * http://gpio.kaltpost.de
 *
 * Echos back each character received. Blinks green LED in main loop. Toggles
 * red LED on RX.
 *
 * Use /dev/ttyACM0 at 9600 Bauds (and 8,N,1).
 *
 * Note: RX-TX must be swaped when using the MSPg2553 with the Launchpad! 
 *       You could easliy do so by crossing RX/TX on the jumpers of the 
 *       Launchpad.
 ******************************************************************************/

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

#include "uart.h"

void uart_rx_isr(unsigned char c) {
	uart_putc(c);
	P1OUT ^= BIT0;		// toggle P1.0 (red led)
}

#define CLK 16000000L
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
    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT
    
    if (CALBC1_16MHZ != 0xFF) // Warning: calibration lost after mass erase
    {
		BCSCTL1 = CALBC1_16MHZ;      // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
 
	P1DIR |= (BIT0 | BIT6); 		// P1.0 and P1.6 are the red+green LEDs	
	P1OUT |= (BIT0 | BIT6); 		// All LEDs off

    uart_init();

    // Output MCLK on P1.4 to check frequency after changing BCSCTL1 and DCOCTL
    P1SEL |= BIT4;
    P1SEL2 &= ~(BIT4);
    P1DIR |= BIT4;

	// register ISR called when data was received
    uart_set_rx_isr_ptr(uart_rx_isr);

    __bis_SR_register(GIE);

	delayms(500); // Give putty some time to start up.
    uart_puts("MSP430 hardware uart test\r\n");
	uart_puts("PRESS any key to start echo example ... ");

	unsigned char c = uart_getc();

	uart_putc(c);
	uart_puts((char *)"\n\rOK\n\r");

  	IE2 |= UCA0RXIE; // Enable USCI_A0 RX interrupt

    volatile unsigned long i;

    while(1) {
	   P1OUT ^= BIT6; 			// Toggle P1.6 output (green LED) using exclusive-OR
	   delayms(500);            // Delay
    } 
}

