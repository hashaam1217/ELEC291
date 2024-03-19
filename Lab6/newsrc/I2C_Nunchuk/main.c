// This program communicates with a WII nunchuck using I2C.  Please check the attached picture
// for wiring details.
//
// Jesus Calvino-Fraga (2018-2020)

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

#define DELAY_FREQ_HZ 1000 // 1ms
#define MS_DELAY_CYCLES (CLK / DELAY_FREQ_HZ) // Number of cycles to delay based on CLK

void delayMs(int len)
{
	unsigned char k;
	
	while(len--) // Wait the desired number of ms
	{
	    __delay_cycles(MS_DELAY_CYCLES); 
	}
}

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

void I2C_Setup (void)
{
    // Connect the SDA/SCL pins to the I2C module
    P1SEL  |= BIT7 + BIT6;
    P1SEL2 |= BIT7 + BIT6;
    
    UCB0CTL1 = UCSWRST;

    // Set master mode, I2C operation, and synchronous mode
    UCB0CTL0 = UCMST + UCMODE1 + UCMODE0 + UCSYNC;

    UCB0CTL1 |= UCSSEL0 + UCSSEL1; // Use SMCLK
    UCB0BR0 = 160; // Set 100kHz baud rate
    UCB0BR1 = 0;

    UCB0CTL1 &= ~UCSWRST; // Enable the USCI
}

void I2C_byte_write(unsigned char saddr, unsigned char maddr, unsigned char data)
{
    UCB0I2CSA = saddr; // Set the slave address to write to
	
	while (UCB0CTL1 & UCTXSTP); // Ensure stop condition got sent
	UCB0CTL1 |= UCTR + UCTXSTT; // I2C TX, start condition.  Sends also slave address.
	
	while((IFG2 & UCB0TXIFG) == 0);
	UCB0TXBUF = maddr;
	
	while((IFG2 & UCB0TXIFG) == 0);
	UCB0TXBUF = data;
	
	while((IFG2 & UCB0TXIFG) == 0);
	UCB0CTL1 |= UCTXSTP; // I2C stop condition
}

int I2C_burst_write(unsigned char saddr, unsigned char maddr, int byteCount, unsigned char* data)
{
    UCB0I2CSA = saddr; // Set the slave address to write to
	
	while (UCB0CTL1 & UCTXSTP); // Ensure stop condition got sent
	UCB0CTL1 |= UCTR + UCTXSTT; // I2C TX, start condition.  Sends also slave address.
	
	while((IFG2 & UCB0TXIFG) == 0);
	UCB0TXBUF = maddr;

    for (; byteCount > 0; byteCount--)
    {
		while((IFG2 & UCB0TXIFG) == 0);
		UCB0TXBUF = *data++; // send data
	}

	while((IFG2 & UCB0TXIFG) == 0);
	UCB0CTL1 |= UCTXSTP; // I2C stop condition

	return 0;
}

int I2C_burstRead(char saddr, char maddr, int byteCount, unsigned char* data)
{
	// First we send the address we want to read from:
    UCB0I2CSA = saddr; // Set the slave address to write to
	
	while (UCB0CTL1 & UCTXSTP); // Ensure stop condition got sent
	UCB0CTL1 |= UCTR + UCTXSTT; // I2C TX, start condition.  Sends also slave address.
	
	while((IFG2 & UCB0TXIFG) == 0);
	UCB0TXBUF = maddr;

	while((IFG2 & UCB0TXIFG) == 0);
	UCB0CTL1 |= UCTXSTP; // I2C stop condition.
	while (UCB0CTL1 & UCTXSTP); // Ensure stop condition got sent.
	
	// Second: we gatter the data sent by the slave device.
	UCB0CTL1 &= ~UCTR; // Set as receiver
	UCB0CTL1 |= UCTXSTT; // Start.
	while(UCB0CTL1 & UCTXSTT); // Wait till start bit transmitted.
	
    for (; byteCount > 0; byteCount--)
    {
		while((IFG2 & UCB0RXIFG) == 0);
		*data++=UCB0RXBUF;
		if(byteCount==2) // Next byte is the last, so after that byte we need to send NACK and STOP...
		{
			UCB0CTL1 |= UCTXNACK; // Send a NACK
			UCB0CTL1 |= UCTXSTP; // I2C STOP.
		}
	}
	
	return 0;
}

void nunchuck_init(int print_extension_type)
{
	unsigned char buf[6];
	
	I2C_byte_write(0x52, 0xF0, 0x55);
	I2C_byte_write(0x52, 0xFB, 0x00);
		 
	// Read the extension type from the register block.
	// For the original Nunchuk it should be: 00 00 A4 20 00 00.
	I2C_burstRead(0x52, 0xFA, 6, buf);
	if(print_extension_type)
	{
		printf("Extension type: %02x  %02x  %02x  %02x  %02x  %02x\r\n", 
			buf[0],  buf[1], buf[2], buf[3], buf[4], buf[5]);
	}

	// Send the crypto key (zeros), in 3 blocks of 6, 6 & 4.
	buf[0]=0; buf[1]=0; buf[2]=0; buf[3]=0; buf[4]=0; buf[5]=0;
	
	I2C_byte_write(0x52, 0xF0, 0xAA);
	I2C_burst_write(0x52, 0x40, 6, buf);
	I2C_burst_write(0x52, 0x40, 6, buf);
	I2C_burst_write(0x52, 0x40, 4, buf);
}

void nunchuck_getdata(unsigned char * s)
{
	unsigned char i;

	// Start measurement
	I2C_burstRead(0x52, 0x00, 6, s);

	// Decrypt received data
	for(i=0; i<6; i++)
	{
		s[i]=(s[i]^0x17)+0x17;
	}
}

int main(void)
{    
	static unsigned char rbuf[6];
 	int joy_x, joy_y, off_x, off_y, acc_x, acc_y, acc_z;
 	char but1, but2;

    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT.
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO.
	  	DCOCTL  = CALDCO_16MHZ;
	}

    uart_init();
	set_stdout_to(uart_putc);
    I2C_Setup(); // Configure I2C.

	delayMs(1000); // Give PuTTY a chance to start before sending text.
	
	printf("\x1b[2J\x1b[1;1H"); // Clear screen using ANSI escape sequence.
	printf ("MSP430G2553 I2C WII Nunchuck test program\r\n"
	        "File: %s\r\n"
	        "Compiled: %s, %s\r\n\r\n",
	        __FILE__, __DATE__, __TIME__);
    
	nunchuck_init(1);
	delayMs(100);

	nunchuck_getdata(rbuf);

	off_x=(int)rbuf[0]-128;
	off_y=(int)rbuf[1]-128;
	printf("Offset_X:%4d Offset_Y:%4d\r\n", off_x, off_y);

	while(1)
	{
		nunchuck_getdata(rbuf);

		joy_x=(int)rbuf[0]-128-off_x;
		joy_y=(int)rbuf[1]-128-off_y;
		acc_x=rbuf[2]*4; 
		acc_y=rbuf[3]*4;
		acc_z=rbuf[4]*4;

		but1=(rbuf[5] & 0x01)?1:0;
		but2=(rbuf[5] & 0x02)?1:0;
		if (rbuf[5] & 0x04) acc_x+=2;
		if (rbuf[5] & 0x08) acc_x+=1;
		if (rbuf[5] & 0x10) acc_y+=2;
		if (rbuf[5] & 0x20) acc_y+=1;
		if (rbuf[5] & 0x40) acc_z+=2;
		if (rbuf[5] & 0x80) acc_z+=1;
		
		printf("Buttons(Z:%c, C:%c) Joystick(%4d, %4d) Accelerometer(%3d, %3d, %3d)\x1b[0J\r",
			   but1?'1':'0', but2?'1':'0', joy_x, joy_y, acc_x, acc_y, acc_z);
		delayMs(100);
	}
}

