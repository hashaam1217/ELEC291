// MSP430_Receiver.c:  This program implements a simple serial port
// communication protocol to program, verify, and read SPI flash memories.  Since
// the program was developed to store wav audio files, it also allows 
// for the playback of said audio.  It is assumed that the wav sampling rate is
// 22050Hz, 8-bit, mono.

#include <msp430.h>
#include <stdio.h>

#define RXD BIT1 // Receive Data (RXD) at P1.1
#define TXD BIT2 // Transmit Data (TXD) at P1.2
#define CLK 16000000L
#define BAUD 115200
#define SPI_CLK 2000000L

#define CLR_CS P1OUT &= ~BIT0
#define SET_CS P1OUT |= BIT0

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

// Flash memory commands
#define WRITE_ENABLE     0x06  // Address:0 Dummy:0 Num:0 fMax: 25MHz
#define WRITE_DISABLE    0x04  // Address:0 Dummy:0 Num:0 fMax: 25MHz
#define READ_STATUS      0x05  // Address:0 Dummy:0 Num:1 to infinite fMax: 32MHz
#define READ_BYTES       0x03  // Address:3 Dummy:0 Num:1 to infinite fMax: 20MHz
#define READ_SILICON_ID  0xab  // Address:0 Dummy:3 Num:1 to infinite fMax: 32MHz
#define FAST_READ        0x0b  // Address:3 Dummy:1 Num:1 to infinite fMax: 40MHz
#define WRITE_STATUS     0x01  // Address:0 Dummy:0 Num:1 fMax: 25MHz
#define WRITE_BYTES      0x02  // Address:3 Dummy:0 Num:1 to 256 fMax: 25MHz
#define ERASE_ALL        0xc7  // Address:0 Dummy:0 Num:0 fMax: 25MHz
#define ERASE_BLOCK      0xd8  // Address:3 Dummy:0 Num:0 fMax: 25MHz
#define READ_DEVICE_ID   0x9f  // Address:0 Dummy:2 Num:1 to infinite fMax: 25MHz

// SPI Flash Memory connections:
// P1.6 (pin 14 of DIP 20) – UCB0SOMI (MISO) -> Pin 2 of 25Q32
// P1.7 (pin 15 of DIP 20) – UCB0SIMO (MOSI) -> Pin 5 of 25Q32
// P1.5 (pin 7  of DIP 20) – UCB0CLK  (SCLK) -> Pin 6 of 25Q32
// P1.0 (pin 2  of DIP 20) - (CSn)           -> Pin 1 of 25Q32
// 3.3V: connected to pins 3, 7, and 8
// GND:  connected to pin 4

volatile unsigned long int playcnt=0;
volatile unsigned int CCR0_reload;
volatile unsigned char play_flag=0;

typedef void (*pfn_outuart_putc)(char c);
void set_stdout_to(pfn_outuart_putc p);
int printf2 (const char *format, ...);

#define DELAY_FREQ_HZ 1000 // 1ms
#define MS_DELAY_CYCLES (CLK / DELAY_FREQ_HZ) // Number of cycles to delay based on CLK.

void uart_init(void)
{
	P1SEL  |= (RXD | TXD);                       
  	P1SEL2 |= (RXD | TXD);                       
  	UCA0CTL1 |= UCSSEL_2; // SMCLK.
  	UCA0BR0 = (CLK/BAUD)%0x100;
  	UCA0BR1 = (CLK/BAUD)/0x100;
  	UCA0MCTL = UCBRS0; // Modulation UCBRSx = 1.
  	UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine.
}

unsigned char uart_getc()
{
    while (!(IFG2&UCA0RXIFG)); // USCI_A0 RX buffer ready?
	return UCA0RXBUF;
}

void uart_putc (unsigned char c)
{
	while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
  	UCA0TXBUF = c; // TX
}

void uart_puts(const char *str)
{
     while(*str) uart_putc(*str++);
}

void Initialize_SPI (void)
{
	// Connect the MISO/MOSI/SCLK pins to the SPI module.
	P1SEL |= BIT5 + BIT6 + BIT7;
	P1SEL2 |= BIT5 + BIT6 + BIT7;
	
	// Using P1.0 for CEn.
	P1DIR |= 0x01;  // Configure P1.0 as output.
	SET_CS;  // deselect ADC.
	
	UCB0CTL1 = UCSWRST; // Reset USCI state machine.
	UCB0CTL0 |=  UCCKPH + UCMSB + UCMST + UCSYNC;  // Mode (0,1), 3-pin Master, 8-bit, MSB first.
	UCB0CTL1 |= UCSSEL_2; // SMCLK
	UCB0BR0 = (CLK/SPI_CLK)%0x100;
	UCB0BR1 = (CLK/SPI_CLK)/0x100; 
	UCB0CTL1 &= ~UCSWRST; // Initialize USCI state machine.
}

unsigned char SPIWrite (unsigned char x)
{
	UCB0TXBUF=x;
	while(UCB0STAT & UCBUSY); // Wait for transmission to end.
	return UCB0RXBUF;
}

// Originally from https://www.kompulsa.com/example-code-msp430-pwm/ but using P2.6 as PWM output
// P2.6 is our 'analog' output.  It must be passed through a RC low pass filter (R=1k, C=0.1uF)
void configure_pwm(void)
{
    P2DIR |= BIT6; // Set pin 2.6 to the output direction.
	P2SEL |= BIT6; // Select pin 2.6 as our PWM output.
	P2SEL &=~BIT7; // optional just to make sure that this bit is cleared
	P2SEL2 &= ~(BIT6|BIT7); // optional, to make sure that they are cleared too
      
    TA0CCR0 = 0x100; //Set the period in the Timer A0 Capture/Compare 0 register
    TA0CCTL1 = OUTMOD_7;
    TA0CCR1 = 0x100/2; // The time the output is high.  Default to half.
    TA0CTL = TASSEL_2 + MC_1; //TASSEL_2 selects SMCLK as the clock source, and MC_1 tells it to count up to the value in TA0CCR0.
}

void Init_Timer1_A0 (void)
{
	CCR0_reload=(16000000L/22050L);
	
    TA1CCTL0 = CCIE; // CCR0 interrupt enabled
    TA1CCR0 = CCR0_reload;
    TA1CTL = TASSEL_2 + MC_2;  // SMCLK, contmode
    _BIS_SR(GIE); // Enable interrupt
    __asm__ __volatile__ ("nop"); // Check: https://e2e.ti.com/support/tools/ccs/f/code-composer-studio-forum/502857/inaccurate-gnu-as-warning-for-eint-dint
}

// Timer1 A0 interrupt service routine (ISR).  Only used by CC0.
// This ISR is the one doing the sound playback.  
void __attribute__ ((interrupt(TIMER1_A0_VECTOR))) Timer1_A0_ISR (void)
{
	unsigned char c;
	TA1CCR0 += CCR0_reload; // Add Offset to CCR0

	if (play_flag!=0)
	{  
		if(playcnt==0)
		{
			SET_CS; // Done playing: Disable 25Q32 SPI flash memory
			play_flag=0;
		}
		else
		{
			TA0R=0;  // Without this a crackling noise occurs (Why?  Some sort of synchronization problem?)
			TA0CCR1=SPIWrite(0x00); // Read from flash memory and output value to PWM (used as DAC)
			playcnt--;
		}
	}
}

void Start_Playback (unsigned long int address, unsigned long int numb)
{
    CLR_CS; // Select/enable 25Q32 SPI flash memory.
    SPIWrite(READ_BYTES);
    SPIWrite((unsigned char)((address>>16)&0xff));
    SPIWrite((unsigned char)((address>>8)&0xff));
    SPIWrite((unsigned char)(address&0xff));
    playcnt=numb;
    play_flag=1;
}

void Enable_Write (void)
{
    CLR_CS; // Enable 25Q32 SPI flash memory.
    SPIWrite(WRITE_ENABLE);
	SET_CS; // Disable 25Q32 SPI flash memory
}

void Check_WIP (void)
{
	unsigned char c;
	do
	{
    	CLR_CS; // Enable 25Q32 SPI flash memory.
	    SPIWrite(READ_STATUS);
	    c=SPIWrite(0x55);
		SET_CS; // Disable 25Q32 SPI flash memory
	} while (c&0x01);
}

static const unsigned short crc16_ccitt_table[256] = {
    0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50A5U, 0x60C6U, 0x70E7U,
    0x8108U, 0x9129U, 0xA14AU, 0xB16BU, 0xC18CU, 0xD1ADU, 0xE1CEU, 0xF1EFU,
    0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52B5U, 0x4294U, 0x72F7U, 0x62D6U,
    0x9339U, 0x8318U, 0xB37BU, 0xA35AU, 0xD3BDU, 0xC39CU, 0xF3FFU, 0xE3DEU,
    0x2462U, 0x3443U, 0x0420U, 0x1401U, 0x64E6U, 0x74C7U, 0x44A4U, 0x5485U,
    0xA56AU, 0xB54BU, 0x8528U, 0x9509U, 0xE5EEU, 0xF5CFU, 0xC5ACU, 0xD58DU,
    0x3653U, 0x2672U, 0x1611U, 0x0630U, 0x76D7U, 0x66F6U, 0x5695U, 0x46B4U,
    0xB75BU, 0xA77AU, 0x9719U, 0x8738U, 0xF7DFU, 0xE7FEU, 0xD79DU, 0xC7BCU,
    0x48C4U, 0x58E5U, 0x6886U, 0x78A7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U,
    0xC9CCU, 0xD9EDU, 0xE98EU, 0xF9AFU, 0x8948U, 0x9969U, 0xA90AU, 0xB92BU,
    0x5AF5U, 0x4AD4U, 0x7AB7U, 0x6A96U, 0x1A71U, 0x0A50U, 0x3A33U, 0x2A12U,
    0xDBFDU, 0xCBDCU, 0xFBBFU, 0xEB9EU, 0x9B79U, 0x8B58U, 0xBB3BU, 0xAB1AU,
    0x6CA6U, 0x7C87U, 0x4CE4U, 0x5CC5U, 0x2C22U, 0x3C03U, 0x0C60U, 0x1C41U,
    0xEDAEU, 0xFD8FU, 0xCDECU, 0xDDCDU, 0xAD2AU, 0xBD0BU, 0x8D68U, 0x9D49U,
    0x7E97U, 0x6EB6U, 0x5ED5U, 0x4EF4U, 0x3E13U, 0x2E32U, 0x1E51U, 0x0E70U,
    0xFF9FU, 0xEFBEU, 0xDFDDU, 0xCFFCU, 0xBF1BU, 0xAF3AU, 0x9F59U, 0x8F78U,
    0x9188U, 0x81A9U, 0xB1CAU, 0xA1EBU, 0xD10CU, 0xC12DU, 0xF14EU, 0xE16FU,
    0x1080U, 0x00A1U, 0x30C2U, 0x20E3U, 0x5004U, 0x4025U, 0x7046U, 0x6067U,
    0x83B9U, 0x9398U, 0xA3FBU, 0xB3DAU, 0xC33DU, 0xD31CU, 0xE37FU, 0xF35EU,
    0x02B1U, 0x1290U, 0x22F3U, 0x32D2U, 0x4235U, 0x5214U, 0x6277U, 0x7256U,
    0xB5EAU, 0xA5CBU, 0x95A8U, 0x8589U, 0xF56EU, 0xE54FU, 0xD52CU, 0xC50DU,
    0x34E2U, 0x24C3U, 0x14A0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U,
    0xA7DBU, 0xB7FAU, 0x8799U, 0x97B8U, 0xE75FU, 0xF77EU, 0xC71DU, 0xD73CU,
    0x26D3U, 0x36F2U, 0x0691U, 0x16B0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U,
    0xD94CU, 0xC96DU, 0xF90EU, 0xE92FU, 0x99C8U, 0x89E9U, 0xB98AU, 0xA9ABU,
    0x5844U, 0x4865U, 0x7806U, 0x6827U, 0x18C0U, 0x08E1U, 0x3882U, 0x28A3U,
    0xCB7DU, 0xDB5CU, 0xEB3FU, 0xFB1EU, 0x8BF9U, 0x9BD8U, 0xABBBU, 0xBB9AU,
    0x4A75U, 0x5A54U, 0x6A37U, 0x7A16U, 0x0AF1U, 0x1AD0U, 0x2AB3U, 0x3A92U,
    0xFD2EU, 0xED0FU, 0xDD6CU, 0xCD4DU, 0xBDAAU, 0xAD8BU, 0x9DE8U, 0x8DC9U,
    0x7C26U, 0x6C07U, 0x5C64U, 0x4C45U, 0x3CA2U, 0x2C83U, 0x1CE0U, 0x0CC1U,
    0xEF1FU, 0xFF3EU, 0xCF5DU, 0xDF7CU, 0xAF9BU, 0xBFBAU, 0x8FD9U, 0x9FF8U,
    0x6E17U, 0x7E36U, 0x4E55U, 0x5E74U, 0x2E93U, 0x3EB2U, 0x0ED1U, 0x1EF0U
};

unsigned short crc16_ccitt(unsigned char val, unsigned short crc)
{
    unsigned short tmp;

    tmp = (crc >> 8) ^ val;
    crc = ((unsigned short)(crc << 8U)) ^ crc16_ccitt_table[tmp];
    return crc;
}

// Get a 24-bit number from the serial port and store it into a unsigned long
void get_ulong(unsigned long * lptr)
{
    unsigned char * bytes;
    bytes=(unsigned char *) lptr;
	bytes[3]=0;
	bytes[2]=uart_getc();
	bytes[1]=uart_getc();
	bytes[0]=uart_getc();
}

int main(void)
{    
    unsigned char c;
    unsigned int j, n;
    unsigned long start, nbytes;
    unsigned short crc;
	
    WDTCTL  = WDTPW | WDTHOLD; 	// Stop WDT.
    
    if (CALBC1_16MHZ != 0xFF) 
    {
		BCSCTL1 = CALBC1_16MHZ; // Set DCO.
	  	DCOCTL  = CALDCO_16MHZ;
	}

    uart_init();
    Initialize_SPI();
    configure_pwm();
    Init_Timer1_A0();

	playcnt=0;
	play_flag=0;
	SET_CS; // Disable 25Q32 SPI flash memory
      
	while(1)
	{
		c=uart_getc();
		if(c=='#')
		{
			playcnt=0;
			play_flag=0;
			SET_CS; // Disable 25Q32 SPI flash memory

			c=uart_getc();
			switch(c)
			{
				case '0': // Identify command
				    CLR_CS; // Enable 25Q32 SPI flash memory.
				    SPIWrite(READ_DEVICE_ID);
				    c=SPIWrite((unsigned char)(0x00));
				    uart_putc(c);
				    c=SPIWrite((unsigned char)(0x00));
				    uart_putc(c);
				    c=SPIWrite((unsigned char)(0x00));
				    uart_putc(c);
				    SET_CS; // Disable 25Q32 SPI flash memory
				break;

				case '1': // Erase whole flash (takes a long time)
					Enable_Write();
				    CLR_CS; // Enable 25Q32 SPI flash memory.
				    SPIWrite(ERASE_ALL);
				    SET_CS; // Disable 25Q32 SPI flash memory
				    Check_WIP();
				    uart_putc(0x01);
				break;
				
				case '2': // Load flash page (256 bytes or less)
					Enable_Write();
				    CLR_CS; // Enable 25Q32 SPI flash memory.
				    SPIWrite(WRITE_BYTES);
				    c=uart_getc(); // Address bits 16 to 23
				    SPIWrite(c);
				    c=uart_getc(); // Address bits 8 to 15
				    SPIWrite(c);
				    c=uart_getc(); // Address bits 0 to 7
				    SPIWrite(c);
				    n=uart_getc(); // Number of bytes to write
				    if(n==0) n=256;
				    for(j=0; j<n; j++)
				    {
				    	c=uart_getc();
				    	SPIWrite(c);
				    }
				    SET_CS; // Disable 25Q32 SPI flash memory
				    Check_WIP();
				    uart_putc(0x01);
				break;
				
				case '3': // Read flash bytes (256 bytes or less)
				    CLR_CS; // Enable 25Q32 SPI flash memory.
				    SPIWrite(READ_BYTES);
				    c=uart_getc(); // Address bits 16 to 23
				    SPIWrite(c);
				    c=uart_getc(); // Address bits 8 to 15
				    SPIWrite(c);
				    c=uart_getc(); // Address bits 0 to 7
				    SPIWrite(c);
				    n=uart_getc(); // Number of bytes to write
				    if(n==0) n=256;
				    for(j=0; j<n; j++)
				    {
				    	c=SPIWrite(0x55);
				    	uart_putc(c);
				    }
				    SET_CS; // Disable 25Q32 SPI flash memory
				break;
				
				case '4': // Playback a portion of the stored wav file
					get_ulong(&start); // Get the start position
					get_ulong(&nbytes); // Get the number of bytes to playback
					Start_Playback(start, nbytes);
				break;
				
				// WARNING: CRC calculation here is way slower than in the EFM8 or SoC-8052.
				// Modify computer_sender.c so it doesn't time out.
				// Change line:
				//               maxwait=length/300000.0;
				// to:
				//               maxwait=length/30000.0;
				case '5': ; // Calculate and send CRC-16 of ISP flash memory from zero to the 24-bit passed value.
					get_ulong(&nbytes); // Get the total number of bytes used to calculate the crc
				
					crc=0;
				    CLR_CS; // Enable 25Q32 SPI flash memory.
				    SPIWrite(READ_BYTES);
				    SPIWrite(0x00); // Address bits 16 to 23
				    SPIWrite(0x00); // Address bits 8 to 1
				    SPIWrite(0x00); // Address bits 0 to 7
				    
					for(start=0; start<nbytes; start++)
					{
						c=SPIWrite(0x00);
						crc=crc16_ccitt(c, crc);
					}
				    SET_CS; // Disable 25Q32 SPI flash memory

					uart_putc(crc/0x100); // Send high byte of CRC
					uart_putc(crc%0x100); // Send low byte of CRC
				break;

				case '6': // Fill flash page (256 bytes or less).
					Enable_Write();
				    CLR_CS; // Enable 25Q32 SPI flash memory.
				    SPIWrite(WRITE_BYTES);
				    c=uart_getc(); // Address bits 16 to 23
				    SPIWrite(c);
				    c=uart_getc(); // Address bits 8 to 15
				    SPIWrite(c);
				    c=uart_getc(); // Address bits 0 to 7
				    SPIWrite(c);
				    c=uart_getc(); // byte to copy to page
				    for(j=0; j<256; j++)
				    {
				    	SPIWrite(c);
				    }
				    SET_CS; // Disable 25Q32 SPI flash memory
				    Check_WIP();
				    uart_putc(0x01);
				break;
			}
		}
    }  
}

