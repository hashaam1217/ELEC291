//  SoftwareUart.c: Implements a software uart for the MSP430G2553.
//  Note that we are using P1.2 and P1.1 for TXD/RXD which are the
//  pins normally used for the HARDWARE uart.  We do this because
//  we are testing this program.  For an user application, different
//  pins should be selected as shown bellow.
//
//  By Jesus Calvino-Fraga (c) 2018

#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>			

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

#define CLK 16000000L
#define sBAUD 9600
// Pins and corresponding registers to use
// For a test, just use the same pin of the hardware uart
#define sTXD (0x04) // Transmit Data (TXD) at P1.2
#define sTXD_REG P1OUT
#define sTXD_DIR P1DIR
#define sRXD (0x02) // Receive Data (RXD) at P1.1
#define sRXD_REG P1IN
#define sRXD_DIR P1DIR

// If for example we want to use P2.0 as TXD and P1.0 as RXD we do this instead:
//#define sTXD (0x01) // Transmit Data (TXD) at P2.0
//#define sTXD_REG P2OUT
//#define sTXD_DIR P2DIR
//#define sRXD (0x01) // Receive Data (RXD) at P1.0
//#define sRXD_REG P1IN
//#define sRXD_DIR P1DIR

unsigned char echo=0;

void ConfigureSoftwareUART (void)
{
    sTXD_DIR |= sTXD;    // Configure pin sTXD as output
	sTXD_REG |= sTXD;    // Default state of transmit pin is 1
	sRXD_DIR &= (~sRXD); // Configure pin sRXD as input
}

void SendByte (unsigned char c)
{
	unsigned char i;
	
	// Send start bit
	sTXD_REG &= (~sTXD);
	__delay_cycles(CLK/sBAUD);
  	// Send 8 data bits
	for (i=0; i<8; i++)
  	{
    	if( c & 1 )
    	{
      		sTXD_REG |= sTXD;
      	}
    	else
      	{
      		sTXD_REG &= (~sTXD);
      	}
    	c >>= 1;
		__delay_cycles(CLK/sBAUD);
 	}
 	// Send the stop bit
	sTXD_REG |= sTXD;
	__delay_cycles(CLK/sBAUD);
}

unsigned char GetByte (void)
{
	unsigned char c, i;
	
	while(sRXD_REG&sRXD); // Wait for input pin to change to zero (start bit)
	__delay_cycles((3*CLK)/(2*sBAUD)); // Wait one and a half bit-time to sample in the middle of incomming bits
	
	for (i=0, c=0; i<8; i++) // Receive 8 data bits
  	{
  		c>>=1;
  		if(sRXD_REG&sRXD) c|=0x80;
		__delay_cycles(CLK/sBAUD);
	}
	if(echo==1) SendByte(c); // If echo activated send back what was received
	if(c==0x05) // Control+E activates echo
	{
		echo=1;
	}
	if(c==0x06) // Control+F de-activates echo
	{
		echo=0;
	}
	return c;
}

void SendString(char * s)
{
	while(*s != 0) SendByte(*s++);
}

void GetString(char * s, int nmax)
{
	unsigned char c;
	int n;
	
	while(1)
	{
		c=GetByte();
		if( (c=='\n') || (c=='\r') || n==(nmax-1) )
		{
			*s=0;
			return;
		}
		else
		{
			*s=c;
			s++;
			n++;
		}
	}
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
	char buff[80];
	unsigned char i;
	
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer   
    if (CALBC1_16MHZ != 0xFF) // Warning: calibration lost after mass erase
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO
	  	DCOCTL  = CALDCO_16MHZ;
	}
	
	ConfigureSoftwareUART();
	delayms(500); // Give putty some time to start.
	SendString("Hello, World!  Using software (bit-bang) UART\r\n");
	SendString("CTRL+E: echo on, CTRL+F echo off\r\n");
	while(1) 
	{
		SendString("\r\nType Something and press <Enter>\r\n");
		GetString(buff, sizeof(buff)-1);
		SendString("\r\nYou typed: ");
		SendString(buff);		
	}
	return 0;
}
