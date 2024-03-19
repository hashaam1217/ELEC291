// MSP430_prog: FT230XS SPI in synchronous bit bang mode to program
// the MSP430G2553 microcontroller.
//
//
//  (c) Jesus Calvino-Fraga (2017)
//
// On Windows compile using visual C:
// cl MSP430_prog
//
/////////////////////////////////////////////////////////////////////////
//
//  On Linux using gcc:
//
//  $ gcc MSP430_prog.c -lpthread libftd2xx.a -o MSP430_prog
//
//  To use on Linux the default ftdi driver needs to be disabled first:
//
//  $ sudo rmmod ftdi_sio
//
//  Then we can send the hex file to the AVR micro:
//
//  $ sudo ./MSP430_prog -p -v Blinky.hex
//
//  Then re-enable the default ftdi driver to use the serial port again:
//
//  $ sudo modprobe ftdi_sio

#ifdef __APPLE__
	#define __unix__ 1
#endif

#ifdef __unix__ 
	#ifdef __APPLE__
		#include <termios.h>
	#else
		#include <termio.h>
	#endif
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/signal.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <math.h>
	#include <time.h>
	#include <string.h>
	#include <errno.h>
	#include <ctype.h>
	#include <string.h>
	#include <stdbool.h>
	#include <limits.h>
	#include "WinTypes.h"
	
	#define strnicmp strncasecmp 
	#define _strnicmp strncasecmp 
	#define stricmp strcasecmp
	#define _stricmp strcasecmp
	#define MAX_PATH PATH_MAX
#else
	#include <windows.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
#endif

#pragma comment(lib, "FTD2XX.lib")
#define FTD2XX_STATIC
#include "ftd2xx.h"

#define BAUDRATE (9600/4)
#define CLOCKSPERBIT (16/4)
#define CHUNK 32

#define BSL_TXD   0x01  // FT230XS TXD pin
#define NOT_USED1 0x02  // FT230XS RXD pin
#define NOT_USED2 0x04  // FT230XS RTS pin
#define BSL_RXD   0x08  // FT230XS CTS pin
#define OUTPUTS (BSL_RXD)

unsigned char bitloc[]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

#define BUFFSIZE 0x10000

FT_HANDLE handle;
DWORD bytes;

unsigned char BitBangBuff[BUFFSIZE]; // Buffer used to transmit and receive bit-banged bits
DWORD BitBangBuff_cnt;
unsigned char Transmit_Serial[BUFFSIZE/(11*CLOCKSPERBIT)]; // Bytes to encode and transmit
unsigned char Received_Serial[BUFFSIZE/(11*CLOCKSPERBIT)]; // Received and decoded input bytes
DWORD Received_Serial_cnt;

#define MEMSIZE 0x10000
#define MAXHEXFILE 0x08
unsigned char Flash_Buffer[MEMSIZE];
int HexName_cnt=0;
char HexName[MAXHEXFILE][MAX_PATH];
char PassFileName[MAX_PATH]="";
unsigned char PassWord[0x20];

clock_t startm, stopm;
#define START if ( (startm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define STOP if ( (stopm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define PRINTTIME printf( "%.1f seconds.", ((double)stopm-startm)/CLOCKS_PER_SEC);

int Selected_Device=-1;
BOOL b_program=FALSE;
BOOL b_run=FALSE;
BOOL b_test=FALSE;
BOOL b_oldway=FALSE;
BOOL b_default_CBUS=FALSE;
int m_Time2Start;

#ifdef __unix__
int Sleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}
#endif

void GetOut (int val)
{
	if(handle!=NULL)
	{
		FT_SetBitMode(handle, 0x00, FT_BITMODE_CBUS_BITBANG); // Set CBUS3 and CBUS0 as input
		FT_SetBitMode(handle, 0x0, FT_BITMODE_RESET); // Back to serial port mode
		FT_Close(handle);
	}
	exit(val);
}

void Load_Byte (unsigned char val)
{
	int j, k, parity=0;
	
	if((BitBangBuff_cnt+(CLOCKSPERBIT*11))>=BUFFSIZE)
	{
		printf("ERROR: Unable to load %d bytes in buffer.  Max is %d.\n", BitBangBuff_cnt+(CLOCKSPERBIT*11), BUFFSIZE);
		GetOut(0);
	}
	
	// Load start bit
	for(k=0; k<CLOCKSPERBIT; k++)	BitBangBuff[BitBangBuff_cnt++]=0;
	
	// Load 8 data bits
	for(j=0; j<8; j++)
	{
		if((val&bitloc[j]))
		{
			for(k=0; k<CLOCKSPERBIT; k++)	BitBangBuff[BitBangBuff_cnt++]=BSL_RXD;
			parity++;
		}
		else
		{
			for(k=0; k<CLOCKSPERBIT; k++)	BitBangBuff[BitBangBuff_cnt++]=0;
		}
	}
	
	// Load parity bit
	for(k=0; k<CLOCKSPERBIT; k++)	BitBangBuff[BitBangBuff_cnt++]=(parity & 0x01)?BSL_RXD:0;
	
	// Load stop bit
	for(k=0; k<CLOCKSPERBIT; k++)	BitBangBuff[BitBangBuff_cnt++]=BSL_RXD;
}

int Decode_BitBangBuff (int skip, int total)
{
	int j, k, parity=0;
	int time2start=0;
		
	for(j=skip; j<total; j++)
	{
		if ((BitBangBuff[j]&BSL_TXD)!=BSL_TXD)
		{
			// Got a start bit
			if(time2start==0) time2start=j; // Save the position of the first start bit
			
			j+=(CLOCKSPERBIT+(CLOCKSPERBIT/2)); // Skip start bit and point to the middle of bit0
			Received_Serial[Received_Serial_cnt]=0;
			parity=0;
			// Decode 8 data bits.  LSB first.
			for(k=0; k<8; k++)
			{
				if((BitBangBuff[j]&BSL_TXD)==BSL_TXD)
				{
					Received_Serial[Received_Serial_cnt]|=bitloc[k];
					parity++;
				}
				j+=CLOCKSPERBIT; // Point to the middle of next bit
			}
			Received_Serial_cnt++;
			// Get the parity bit
			if((BitBangBuff[j]&BSL_TXD)==BSL_TXD) parity++;
			
			if((parity&1)==0)
			{
				//printf("Parity is even\n");
			}
			else
			{
				printf("Parity Error\n");
				fflush(stdout);
			}

			j+=(CLOCKSPERBIT/2); // Skip to stop bit
		}
	}
	return time2start;
}

void Reset_BitBangBuff(void)
{
	int j;
	BitBangBuff_cnt=0;
	Received_Serial_cnt=0;
	memset(BitBangBuff, 0x0f, BUFFSIZE); // Load buffer with default value
}

int hex2dec (char hex_digit)
{
   int j;
   j=toupper(hex_digit)-'0';
   if (j>9) j -= 7;
   return j;
}

unsigned char GetByte(char * buffer)
{
	return hex2dec(buffer[0])*0x10+hex2dec(buffer[1]);
}

unsigned short GetWord(char * buffer)
{
	return hex2dec(buffer[0])*0x1000+hex2dec(buffer[1])*0x100+hex2dec(buffer[2])*0x10+hex2dec(buffer[3]);
}

int Read_Hex_File(void)
{
	char buffer[1024];
	FILE * filein;
	int j, k;
	unsigned char linesize, recordtype, rchksum, value;
	unsigned short address;
	int chksum;
	int line_counter;
	int TotalBytes;
	int GranTotal=0;

	//Set the flash buffer to its default value
	memset(Flash_Buffer, 0xff, MEMSIZE);

	for(k=0; k<HexName_cnt; k++)
	{
	    if ( (filein=fopen(HexName[k], "r")) == NULL )
	    {
	       printf("Error: Can't open file `%s`.\r\n", HexName[k]);
	       return -1;
	    }
	
		line_counter=0;
		TotalBytes=0;
	    while(fgets(buffer, sizeof(buffer), filein)!=NULL)
	    {
	    	line_counter++;
	    	if(buffer[0]==':')
	    	{
				linesize = GetByte(&buffer[1]);
				address = GetWord(&buffer[3]);
				recordtype = GetByte(&buffer[7]);
				rchksum = GetByte(&buffer[9]+(linesize*2));
				chksum=linesize+(address/0x100)+(address%0x100)+recordtype+rchksum;
	
				if (recordtype==1) break; /*End of record*/
	
				for(j=0; j<linesize; j++)
				{
					value=GetByte(&buffer[9]+(j*2));
					chksum+=value;
					if(recordtype==0)
					{
						if((address+j)<MEMSIZE)
						{
							Flash_Buffer[address+j]=value;
							TotalBytes++;
						}
					}
				}
	
				if((chksum%0x100)!=0)
				{
					printf("ERROR: Bad checksum in file '%s' at line %d\r\n", HexName[k], line_counter);
					return -1;
				}
			}
	    }
	    fclose(filein);
	    printf("%s: Loaded %d bytes.\n", HexName[k], TotalBytes);
	    fflush(stdout);
	    GranTotal+=TotalBytes;
	}

    return GranTotal;
}

int Read_Pass_File(void)
{
	char buffer[1024];
	FILE * filein;
	int j, k;
	unsigned char linesize, recordtype, rchksum, value;
	unsigned short address;
	int chksum;
	int line_counter;
	int TotalBytes;

	memset(PassWord, 0xff, 0x20); // Password is 32 bytes long

    if ( (filein=fopen(PassFileName, "r")) == NULL )
    {
       printf("Error: Can't open file `%s`.\r\n", PassFileName);
       return -1;
    }
	
	line_counter=0;
	TotalBytes=0;
    while(fgets(buffer, sizeof(buffer), filein)!=NULL)
    {
    	line_counter++;
    	if(buffer[0]==':')
    	{
			linesize = GetByte(&buffer[1]);
			address = GetWord(&buffer[3]);
			recordtype = GetByte(&buffer[7]);
			rchksum = GetByte(&buffer[9]+(linesize*2));
			chksum=linesize+(address/0x100)+(address%0x100)+recordtype+rchksum;

			if (recordtype==1) break; /*End of record*/

			for(j=0; j<linesize; j++)
			{
				value=GetByte(&buffer[9]+(j*2));
				chksum+=value;
				if(recordtype==0)
				{
					if((address+j)>=0xffe0)
					{
						PassWord[address+j]=value;
						TotalBytes++;
					}
				}
			}

			if((chksum%0x100)!=0)
			{
				printf("ERROR: Bad checksum in file '%s' at line %d\r\n", PassFileName, line_counter);
				return -1;
			}
		}
    }
    fclose(filein);
    printf("%s: Loaded %d password bytes.\n", PassFileName, TotalBytes);
    fflush(stdout);
    return 0;
}

int List_FTDI_Devices (void)
{
	FT_STATUS ftStatus;
	FT_HANDLE ftHandleTemp;
	DWORD numDevs;
	DWORD Flags;
	DWORD ID;
	DWORD Type;
	DWORD LocId;
	char SerialNumber[16];
	char Description[64];
	int j, toreturn=0;
	LONG PortNumber;
	
	if (Selected_Device>=0) return Selected_Device;
	
	// create the device information list
	ftStatus = FT_CreateDeviceInfoList(&numDevs);
	if (ftStatus == FT_OK)
	{
		//printf("Number of devices is %d\n",numDevs);
	}
	
	if (numDevs > 1)
	{
		printf("More than one device detected.  Use option -d to select device to use:\n");
		for(j=0; j<numDevs; j++)
		{
			ftStatus = FT_GetDeviceInfoDetail(j, &Flags, &Type, &ID, &LocId, SerialNumber, Description, &ftHandleTemp);
			if (ftStatus == FT_OK)
			{
				printf("-d%d: ", j);
				//printf("Flags=0x%x ",Flags);
				//printf("Type=0x%x ",Type);
				printf("ID=0x%x ",ID);
				//printf("LocId=0x%x ",LocId);
				printf("Serial=%s ",SerialNumber);
				printf("Description='%s' ",Description);
				//printf(" ftHandle=0x%x",ftHandleTemp);
				FT_Open(j, &handle);
				FT_GetComPortNumber(handle, &PortNumber);				
				FT_Close(handle);
				printf("Port=COM%d\n", PortNumber); fflush(stdout);
			}
		}
		fflush(stdout);
		exit(-1);
	}
	
	return toreturn;
}

void print_help (char * prn)
{
	printf("Some examples:\n"
	       "%s -p -v -r somefile.hex   --- program, verify, and run.\n",
	       prn);
}

unsigned char Default_Password[]=
{
	0x80, 0x10, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0x00, 0x00 // Place holders for checksum
	//0x5B, 0xCB // Actual checksum, but let us calculate it
};

unsigned char Fixed_Password[]=
{
	0x80, 0x10, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00,
	0x80, 0xFF, 0x84, 0xFF, 0x88, 0xFF, 0x8c, 0xFF,
	0x90, 0xFF, 0x94, 0xFF, 0x98, 0xFF, 0x9c, 0xFF,
	0xa0, 0xFF, 0xa4, 0xFF, 0xa8, 0xFF, 0xac, 0xFF,
	0xb0, 0xFF, 0xb4, 0xFF, 0xb8, 0xFF, 0xbc, 0xFF,
	0x00, 0x00 // Place holders for checksum
};

/*
The upper 16 bytes of the boot-ROM (0FF0h to 0FFFh) hold information about the device and BSL
version number in BCD representation. This is common for all devices and BSL versions:
	0FF0h to 0FF1h: Chip identification (for example, F413h for an F41x device).
	0FFAh to 0FFBh: BSL version number (for example, 0130h for BSL version V1.30).
*/

unsigned char BSL_Version[]=
{
	0x80, 0x14, 0x04, 0x04, 0xF0, 0x0F, 0x10, 0x00, 0xFF, 0xFF
};

unsigned char Mass_erase[]=
{
	0x80, 0x18, 0x04, 0x04, 0x00, 0x00, 0x06, 0xA5, 0x00, 0x00
};

// "The erase main or info command erases specific flash memory section. It is password protected.
// The address bytes AL (low byte) and AH (high byte) select the appropriate section of flash (main or
// information). Any even-numbered address within the section to be erased is valid."
// 80 16 04 04 AL AH 04 A5 CKL CKH
unsigned char Erase_main[]=
{
	0x80, 0x16, 0x04, 0x04, 0x00, 0xf0, 0x04, 0xA5, 0x00, 0x00
};

void Calculate_Check_Sum (unsigned char * TXbuffer, unsigned int Length)
{
	int k;
	int temp1 = TXbuffer[0];
	int temp2 = TXbuffer[1];
	
	for (k = 2; k < Length-2 ; k += 2) // bytes to encode for checksum 
	{               
	    temp1 ^= TXbuffer[k];
	    temp2 ^= TXbuffer[k+1];
	}
	TXbuffer[Length-2]= (unsigned char)~temp1; // fill in the checksum low
	TXbuffer[Length-1]= (unsigned char)~temp2; // fill in the checksum high
}

// CBUS3 and CBUS0 are used as RESET and TEST respectevely, to activate BSL mode.
// They must be configured for GPIO first.
void FTDI_Set_CBUS_Mode (int pinmode)
{
	FT_STATUS status;
	char Manufacturer[64];
	char ManufacturerId[64];
	char Description[64];
	char SerialNumber[64];
	int j;
	
	FT_EEPROM_HEADER ft_eeprom_header;
	FT_EEPROM_X_SERIES ft_eeprom_x_series;
	
	ft_eeprom_header.deviceType = FT_DEVICE_X_SERIES; // FTxxxx device type to be accessed
	ft_eeprom_x_series.common = ft_eeprom_header;
	ft_eeprom_x_series.common.deviceType = FT_DEVICE_X_SERIES;
	
	status = FT_EEPROM_Read(handle, &ft_eeprom_x_series, sizeof(ft_eeprom_x_series),
							Manufacturer, ManufacturerId, Description, SerialNumber);
	// FT_X_SERIES_CBUS_IOMODE configure pin to this mode for bit bang mode
	// FT_X_SERIES_CBUS_SLEEP Factory default setting for CBUS3
	// FT_X_SERIES_CBUS_TXLED Factory default setting for CBUS2
	// FT_X_SERIES_CBUS_RXLED Factory default setting for CBUS1
	// FT_X_SERIES_CBUS_TXDEN Factory default setting for CBUS0
	if (status == FT_OK)
	{
		if(pinmode==1)
		{
			if ((ft_eeprom_x_series.Cbus3!=FT_X_SERIES_CBUS_IOMODE) ||  (ft_eeprom_x_series.Cbus0!=FT_X_SERIES_CBUS_IOMODE))
			{
				ft_eeprom_x_series.Cbus3=FT_X_SERIES_CBUS_IOMODE;
				ft_eeprom_x_series.Cbus0=FT_X_SERIES_CBUS_IOMODE;
				status = FT_EEPROM_Program(handle, &ft_eeprom_x_series, sizeof(ft_eeprom_x_series),
										Manufacturer, ManufacturerId, Description, SerialNumber);
				if (status == FT_OK)
				{
					FT_CyclePort(handle); // It takes about 5 seconds to cycle port
					FT_Close(handle);
					printf("Pins CBUS3 and CBUS0 configured as 'IO Mode for CBUS bit-bang'.\n");					
					fflush(stdout);
					
					for(j=0; j<20; j++)
					{
						if(FT_Open(List_FTDI_Devices(), &handle) != FT_OK)
						{
							Sleep(1000);
							printf(".");
							fflush(stdout);
						}
						else
						{
							printf("\n");
							fflush(stdout);
							break;
						}
					}
					if(j==20)
					{
				        printf("Can not open FTDI adapter.\n");
						fflush(stdout);
						exit(1);
					}    
				}
			}
		}
		else
		{
			if ((ft_eeprom_x_series.Cbus3!=FT_X_SERIES_CBUS_SLEEP) || (ft_eeprom_x_series.Cbus0!=FT_X_SERIES_CBUS_TXDEN))
			{
				ft_eeprom_x_series.Cbus3=FT_X_SERIES_CBUS_SLEEP;
				ft_eeprom_x_series.Cbus0=FT_X_SERIES_CBUS_TXDEN;
				status = FT_EEPROM_Program(handle, &ft_eeprom_x_series, sizeof(ft_eeprom_x_series),
										Manufacturer, ManufacturerId, Description, SerialNumber);
				if (status == FT_OK)
				{
					FT_ResetDevice(handle);
					Sleep(100);
					printf("WARNING: Pins CBUS3 and CBUS0 have been configured as factory default.\n");
					printf("Please unplug/plug the BO230XS board for the changes to take effect\n"
					       "and try again.\n");
					fflush(stdout);
					GetOut(0);
				}
			}
		}
	}
}

void Activate_BSL (void)
{
	// Bits 7 down to 4 set CBUSx as either input or ouput.  Bits 3 down to 0 is the actual output.
	// For example 0x90 configures CBUS3 and CBUS0 as outputs and set their values to zero.
	unsigned char Seq[7]={0x90, 0x91, 0x90, 0x91, 0x99, 0x98, 0x00};
	unsigned char c;

    FT_SetBaudRate(handle, BAUDRATE);

	// Set the RXD_BSL pin to high before activating BSL
	FT_SetBitMode(handle, OUTPUTS, FT_BITMODE_SYNC_BITBANG);
	c=0xff;
    FT_Write(handle, &c, 1, &bytes);
    FT_Read(handle, &c, 1, &bytes);
	
	FTDI_Set_CBUS_Mode(1); // Make sure both CBUS3 and CBUS0 are in "CBUS IOMODE"
	
	for(c=0; c<7; c++)
	{
		FT_SetBitMode(handle, Seq[c], FT_BITMODE_CBUS_BITBANG); // RESET=0, TEST=0
		Sleep(1); // Sleep mili seconds
	}
	
	FT_Purge(handle, FT_PURGE_RX | FT_PURGE_TX);
	FT_SetBitMode(handle, OUTPUTS, FT_BITMODE_SYNC_BITBANG);
	FT_SetLatencyTimer (handle, 2); // 2 ms is the minimum allowed...

	Sleep(10);
}

void Display_Received (void)
{
	int j;
	printf("Number of bytes in buffer: %d\n", Received_Serial_cnt);
	for(j=0; j<Received_Serial_cnt; j++)
	{
		printf("%02x ", Received_Serial[j]);
	}
	printf("\n");
	fflush(stdout);
}

void Send_Command (unsigned char * Buffer, int nTX, int nRX)
{
	int j;
	
	Reset_BitBangBuff();
	Load_Byte(0x80);
	
	// Add space between the synchronization and the actual command.  About two milliseconds...
	for(j=0; j<(CLOCKSPERBIT*11*2); j++) BitBangBuff_cnt++;

	Calculate_Check_Sum(Buffer, nTX);
	for(j=0; j<nTX; j++) Load_Byte(Buffer[j]);
	// Send the command and acquire the response
    FT_Write(handle, BitBangBuff, BitBangBuff_cnt+(CLOCKSPERBIT*11*(nRX+1)), &bytes);
    // Get the response
    FT_Read(handle, BitBangBuff, BitBangBuff_cnt+(CLOCKSPERBIT*11*(nRX+1)), &bytes);
    // Decode the response
	m_Time2Start=Decode_BitBangBuff(BitBangBuff_cnt, BitBangBuff_cnt+(CLOCKSPERBIT*11*(nRX+1)));
	Display_Received();
}

void Send_Command_ne (unsigned char * Buffer, int nTX, int nRX)
{
	int j;
	
	Reset_BitBangBuff();
	Load_Byte(0x80);
	
	// Add space between the synchronization and the actual command.  About two milliseconds...
	for(j=0; j<(CLOCKSPERBIT*11*2); j++) BitBangBuff_cnt++;

	Calculate_Check_Sum(Buffer, nTX);
	for(j=0; j<nTX; j++) Load_Byte(Buffer[j]);
	// Send the command and acquire the response
    FT_Write(handle, BitBangBuff, BitBangBuff_cnt+(CLOCKSPERBIT*11*(nRX+1)), &bytes);
    // Get the response
    FT_Read(handle, BitBangBuff, BitBangBuff_cnt+(CLOCKSPERBIT*11*(nRX+1)), &bytes);
    // Decode the response
	m_Time2Start=Decode_BitBangBuff(BitBangBuff_cnt, BitBangBuff_cnt+(CLOCKSPERBIT*11*(nRX+1)));
}

void Write_to_File (char * prefix, int Flash_Start, int Flash_Len)
{
	int chksum;
	FILE * fileout;
	char text[0x100];
	unsigned char buff[256];
	char File_Name[MAX_PATH];
	int j, k;
	
	time_t now = time(NULL);
	struct tm *t = localtime(&now);

	strftime(text, sizeof(text)-1, "%d_%m_%Y_%H_%M_%S", t);
	sprintf(File_Name, "%s_%s.hex", prefix, text);

	printf("Reading memory from 0x%04x to 0x%04x to file '%s'... ", Flash_Start, (Flash_Start+Flash_Len), File_Name);
	fflush(stdout);
	
	if ( (fileout=fopen(File_Name, "w")) == NULL )
    {
		printf(" Error: Can't create file `%s`.\n", File_Name);
		fflush(stdout);
		return;
    }

	for(j=Flash_Start; j<(Flash_Start+Flash_Len); j+=16)
	{			
		buff[0]=0x80;
		buff[1]=0x14; // Read command
		buff[2]=4;
		buff[3]=4;
		buff[4]=(unsigned char)(j%0x100);
		buff[5]=(unsigned char)(j/0x100);
		buff[6]=16;
		buff[7]=0;
		buff[8]=0;
		buff[9]=0;
		Send_Command_ne(buff, 10, 16+6);
	
		fprintf(fileout, ":10%04X00", j);
		chksum=0x10+(j/0x100)+(j%0x100);
		for(k=0; k<16; k++)
		{
			fprintf(fileout, "%02X", Received_Serial[4+k]);
			chksum+=Received_Serial[4+k];
		}
		fprintf(fileout, "%02X\n", -chksum&0xff);
	}
	fprintf(fileout, ":00000001FF\n"); // End record
	fclose(fileout);
	printf(" Done.\n");
	fflush(stdout);
}

void Flash_MSP430 (void)
{
    int j, k, dot;
	unsigned char buff[256];
	BOOL Data_is_0xff;

	START;
	
	if(b_oldway==FALSE) // Use the new way of dealing with the password
	{
		Activate_BSL();
		if(strlen(PassFileName)>0) // In case a hex file password file is provided
		{
			Read_Pass_File();
			buff[0]=0x80;
			buff[1]=0x10;
			buff[2]=0x24;
			buff[3]=0x24;
			buff[4]=0x00;
			buff[5]=0x00;
			buff[6]=0x00;
			buff[7]=0x00;
			for(k=0; k<0x20; k++) buff[8+k]=PassWord[k];		
			buff[k+0]=0; // placeholder for CLK
			buff[k+1]=0; // placeholder for CKH
			Send_Command_ne(buff, k+1, 1);
		}
		else
		{
			Send_Command_ne(Default_Password, sizeof(Default_Password), 1); // When the device is brand new it has the default password.
		}
		if(Received_Serial[0]!=0x90)
		{
			Activate_BSL();
			Send_Command_ne(Fixed_Password, sizeof(Fixed_Password), 1); // Previously programmed device.  Try the fixed password.
			if(Received_Serial[0]!=0x90)
			{
				printf("ERROR: Could not get a password to work with this device.\nYou may have to use option -q.\n");
				fflush(stdout);
				return;
			}
		}
		else // Found a new device with default password. Just in case, save the calibration for this new IC
		{
			if(strlen(PassFileName)==0) // Do this only for factory default password
			{
				printf("\nNew device detected!  Reading calibration data to file.\n");
				fflush(stdout);
				
				Write_to_File ("Calibration_Data", 0x1000, 0x0100);
				printf("Rename and treasure this file!  It is the only way "
				       "to restore the factory calibration data to _this_IC_ \n"
				       "in case it is accidentaly erased.\n\n");
				fflush(stdout);
			}
		}
				
		// The space for the jump table must be empty
		for(j=0xff80; j<0xffbf; j++)
		{
			if(Flash_Buffer[j]!=0xff)
			{
				printf("ERROR: Memory locations from 0xff80 to 0xffbf are not empty.\n"
				       "They are used to store an intermediate jump table. Can not proceed.\n");
				fflush(stdout);
				return;
			}
		}
		
		if ( (Flash_Buffer[0xffde]!=0xff) || (Flash_Buffer[0xffdf]!=0xff) )
		{
			printf("ERROR: Word at memory location 0xffde is not empty.\n"
			       "It is used as the BSL security key.  Can not proceed.\n");
			fflush(stdout);
			return;
		}
		
		// Set the BSL flag that prevents 'mass erase' in case of incorrect password.  From the datasheet:
		// 0FFDEh: This location is used as bootstrap loader security key (BSLSKEY). A 0xAA55 at this location disables the
		// BSL completely. A zero (0h) disables the erasure of the flash if an invalid password is supplied.
		// We need to do this because we may try two passords (the default and the fixed) to activate the bootloader.
		Flash_Buffer[0xffde]=0;
		Flash_Buffer[0xffdf]=0;
		
		// Set the jump table.  The following was obtained using the odjump program to dissasemble some test code:
		// c0b2:	30 40 d4 c0 	br	#0xc0d4		; The 'opcode' for br is 0x4030
		
		for(j=0; j<16; j++)
		{
			Flash_Buffer[0xff80+((j*4)+0)]=0x30;
			Flash_Buffer[0xff80+((j*4)+1)]=0x40;
			Flash_Buffer[0xff80+((j*4)+2)]=Flash_Buffer[0xffe0+((j*2)+0)];
			Flash_Buffer[0xff80+((j*4)+3)]=Flash_Buffer[0xffe0+((j*2)+1)];
		}		
			
		// Set the interrupt table so it points to the jump table
		for(j=0; j<16; j++)
		{
			Flash_Buffer[0xffe0+((j*2)+0)]=0x80+(j*4);
			Flash_Buffer[0xffe0+((j*2)+1)]=0xff;
		}

		printf("Erasing main memory.  Please wait... ");
		fflush(stdout);

		Send_Command_ne(Erase_main, sizeof(Erase_main), 600); // Needs at least 500ms to complete.  Assume 1ms per byte.
		if(Received_Serial[0]!=0x90)
		{
			printf("\nERROR: Command to erase main memory failed.\n");
			fflush(stdout);
			return;
		}
		printf("done.\n");
		fflush(stdout);
		
		// Before programming, make sure the calibration data in infoA is not overwriten by leaving it blank in the buffer
		for(j=0x10C0; j<0x1100; j++) Flash_Buffer[j]=0xff;
	}
	else // The old way of dealing with the password.  It may be useful for in some cases...
	{
		Activate_BSL();
		if(strlen(PassFileName)>0) // In case a hex file password file is provided
		{
			Read_Pass_File();
			buff[0]=0x80;
			buff[1]=0x10;
			buff[2]=0x24;
			buff[3]=0x24;
			buff[4]=0x00;
			buff[5]=0x00;
			buff[6]=0x00;
			buff[7]=0x00;
			for(k=0; k<0x20; k++) buff[8+k]=PassWord[k];		
			buff[k+0]=0; // placeholder for CLK
			buff[k+1]=0; // placeholder for CKH
			Send_Command_ne(buff, k+1, 1);
		}
		else
		{
			Send_Command_ne(Default_Password, sizeof(Default_Password), 1);
		}
		
		if(Received_Serial[0]==0x90)
		{
			printf("\nBlank Device. Reading calibration data to file.\n");
			fflush(stdout);
			
			Write_to_File ("Calibration_Data", 0x1000, 0x0100);
			printf("Rename and treasure this file!  It must be loaded to _this_device_only_\n"
			       "to restore the factory calibration data after a 'mass erase' command.\n\n");
			fflush(stdout);
			for(j=0x10C0; j<0x1100; j++) Flash_Buffer[j]=0xff;

			printf("Erasing main memory.  Please wait... ");
			fflush(stdout);
			Send_Command_ne(Erase_main, sizeof(Erase_main), 600); // Needs at least 500ms to complete.  Assume 1ms per byte.
			if(Received_Serial[0]!=0x90)
			{
				printf("\nERROR: Command to erase main memory failed.\n");
				fflush(stdout);
				return;
			}
			printf("done.\n");
			fflush(stdout);			
		}
		else // We don't know the password...
		{
			printf("Erasing device...");
			fflush(stdout);
			Send_Command_ne(Mass_erase, sizeof(Mass_erase), 600); // Needs at least 500ms to complete.  Assume 1ms per byte.
			printf(" Done\n");
			fflush(stdout);
			
			// Start over with default password.
			Activate_BSL();
			Send_Command_ne(Default_Password, sizeof(Default_Password), 1);
		}
	}
	
	Send_Command_ne(BSL_Version, sizeof(BSL_Version), 22);
	printf("MSP430x%02x%02x detected.  ", Received_Serial[4], Received_Serial[5]);
	printf("BSL Version: %d.%02X\n", Received_Serial[14], Received_Serial[15]);
	fflush(stdout);
	
	// Load the flash
	printf("Loading flash memory: \n");
	fflush(stdout);
	dot=0;
	for(j=0; j<0x10000; j+=CHUNK)
	{
		//RX data block: 80 12 n n AL AH n–4 0 D1 D2 … Dn–4 CKL CKH
		buff[0]=0x80;
		buff[1]=0x12;
		buff[2]=CHUNK+4;
		buff[3]=CHUNK+4;
		buff[4]=(unsigned char)(j%0x100);
		buff[5]=(unsigned char)(j/0x100);
		buff[6]=CHUNK;
		buff[7]=0;
		Data_is_0xff=TRUE;
		for(k=0; k<CHUNK; k++)
		{
			buff[8+k]=Flash_Buffer[j+k];
			if(Flash_Buffer[j+k]!=0xff) Data_is_0xff=FALSE;
		}
		buff[8+CHUNK]=0x00;
		buff[8+CHUNK+1]=0x00;
		
		if(Data_is_0xff==FALSE)
		{
			Send_Command_ne(buff, 8+CHUNK+2, 1);
			
			dot++;
			if(dot==64)
			{
				dot=0;
				printf("\n");	
			}
			if(Received_Serial[0]==0x90)
			{
				printf(".");
				fflush(stdout);
			}
			else
			{
				printf("\nFlash write ERROR at location %04x.\n", j);
				fflush(stdout);
				GetOut(0);
			}
		}		
	}
	printf(" Done\n");

    printf("Actions completed in ");
    STOP;
	PRINTTIME;
	printf("\n"); fflush(stdout);
}

void MSP430_Run (void)
{
	printf("Running program... ");
	fflush(stdout);
	
	// Set the reset pin to zero.  Just before exiting the programmer the pin
	// is set as input, and the RC circuit connected to the MSP430 reset takes over.
	FT_SetBitMode(handle, 0x90, FT_BITMODE_CBUS_BITBANG); // RESET=0, TEST=0

	printf("Done\n");
	fflush(stdout);
}

int main(int argc, char ** argv)
{
    int j;
	unsigned char buff[32];
	LONG lComPortNumber;

    printf("MSP430 programmer using BO230X board. (C) Jesus Calvino-Fraga (2017)\n");
    
    for(j=1; j<argc; j++)
    {		
		if(stricmp("-p", argv[j])==0) b_program=TRUE;
		else if(stricmp("-r", argv[j])==0) b_run=TRUE;
		else if(stricmp("-t", argv[j])==0) b_test=TRUE;
		else if(stricmp("-q", argv[j])==0) b_oldway=TRUE;
    	else if((argv[j][0]=='-') && (toupper(argv[j][1])=='P'))
    	{
    		strcpy(PassFileName, &argv[j][2]);
    	}
		else if(stricmp("-h", argv[j])==0)
		{
    		print_help(argv[0]);
    		return 0;
		}
		else if(strnicmp("-d", argv[j], 2)==0)
		{
			Selected_Device=atoi(&argv[j][2]);
		}
		else if(stricmp("-cbus", argv[j])==0) b_default_CBUS=TRUE;

    	else
    	{
    		if(HexName_cnt<MAXHEXFILE)
    		{
	    		strcpy(HexName[HexName_cnt++], argv[j]);
    		}
    	}
    }
    
    if ( (HexName_cnt==0) && (b_program))
    {
    	printf("Need a filename to proceed.  ");
    	print_help(argv[0]);
    	return 1;
    }
    
    if (b_program)
    {
	    if(Read_Hex_File()<0)
	    {
	    	return 2;
	    }
    }

    if(FT_Open(List_FTDI_Devices(), &handle) != FT_OK)
    {
        puts("Can not open FTDI adapter.\n");
        return 3;
    }
    
    if (FT_GetComPortNumber(handle, &lComPortNumber) == FT_OK)
    { 
    	if (lComPortNumber != -1)
    	{
    		printf("Connected to COM%d\n", lComPortNumber); fflush(stdout);
    		sprintf(buff,"echo COM%d>COMPORT.inc", lComPortNumber);
    		system(buff);
    	}
    }
    
    if(b_default_CBUS)
    {
		FTDI_Set_CBUS_Mode(0); // Restore default operation of CBUS0 and CBUS3
		GetOut(0);
    }
    
	if(b_program) Flash_MSP430();    
	if(b_run) MSP430_Run();

	GetOut(0);
		
    return 0;
}
