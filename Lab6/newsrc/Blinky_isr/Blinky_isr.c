//  Blinky_isr.c: Use TIMERA0 CCRO ISR to Toggle P1.0
//
//  By Jesus Calvino-Fraga (c) 2018

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

volatile unsigned int msec_cnt0=0;
volatile unsigned int msec_cnt1=100;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
	P1DIR |= 0x01; // Set P1.0 to output direction (pin 2 of DIP-20)
	P2DIR |= 0x02; // Set P2.1 to output direction (pin 9 of DIP-20)
    
    if (CALBC1_16MHZ != 0xFF) // Warning: calibration lost after mass erase
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}

    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CCR0 = CCR_1MS_RELOAD;
    // For the fun of it, interrupt also with the other CCR of timer0
    TA0CCTL1 = CCIE; // CCR1 interrupt enabled
    TA0CCR1 = CCR_1MS_RELOAD;
    TA0CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
    _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
}

// Information on how to setup interrupts in GCC for the MSP430 is available at:
// http://www.ti.com/lit/ug/slau646b/slau646b.pdf
// Check section 4.5: "MSP430 GCC Interrupts Definition"

// Notice that timer0 has two interrupt vectors as shown in MSP430G2553.h:
// TIMER0_A1_VECTOR for CC1/TA0 and TIMER0_A0_VECTOR for CC0.  The MSP430G2553 has not CC2.

// Timer0 A0 interrupt service routine (ISR).  Only used by CC0.  
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer0_A0_ISR (void)
{
   TA0CCR0 += CCR_1MS_RELOAD; // Add Offset to CCR0
   msec_cnt0++;
   if (msec_cnt0==500)
   {
      msec_cnt0=0;
      P1OUT ^= 0x01; // Toggle P1.0: 0.5s LED on, 0.5s LED off.
   }
}

// Timer0 A1 interrupt service routine (ISR).  Used by CC1 and TA0.  
void __attribute__ ((interrupt(TIMER0_A1_VECTOR))) Timer0_A1_ISR (void)
{
   unsigned int intsrc;
   
   intsrc=TA0IV;
   if ((intsrc&TA0IV_TACCR1)!=0)
   {
	   TA0CCR1 += CCR_1MS_RELOAD; // Add Offset to CCR1
	   msec_cnt1++;
	   if (msec_cnt1==250)
	   {
	      msec_cnt1=0;
	      P2OUT ^= 0x02;
	   }
   }
}
