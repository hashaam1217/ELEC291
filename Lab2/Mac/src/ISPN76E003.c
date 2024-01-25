/////////////////////////////////////////////////////////////////////////////
//
//   ISPN76E003.c: ISP programer for the N76E003 microcontroller.
//                 For Windows, Linux, and macOS.
// 
// Copyright (C) 2023  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca
// 
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option) any
// later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
/////////////////////////////////////////////////////////////////////////////
//
// To compile on Linux and macOS, in a terminal type:
//
// gcc ISPN76E003.c -o ISPN76E003
//
// To compile on Windows with Visual C, in command prompt type:
//
// cl ISPN76E003.c
//
// To compile on Windows with GCC, in a command prompt type:
//
// gcc ISPN76E003.c -o ISPN76E003.exe

#ifdef __APPLE__
	#define __unix__ 1
#endif

#ifdef __unix__
	#include <limits.h>
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
	
	#define strnicmp strncasecmp 
	#define TRUE true
	#define FALSE false
	#define EQ(X,Y)  (stricmp(X, Y)==0)
	#define NEQ(X,Y) (stricmp(X, Y)!=0)
	#define MAX_PATH PATH_MAX
	#define DWORD unsigned long int
	#define stricmp strcasecmp
	#define BOOL bool
#else
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <windows.h>
	#include <time.h>
	#define EQ(X,Y)  (_stricmp(X, Y)==0)
	#define NEQ(X,Y) (_stricmp(X, Y)!=0)
	#ifdef _MSC_VER
		#pragma comment(lib, "FTD2XX.lib")
		#define FTD2XX_STATIC
		#include "ftd2xx.h"
		FT_HANDLE ft_handle;
	#endif
#endif

time_t start_t, stop_t;
#define T_START time(&start_t);
#define T_STOP time(&stop_t);
#define T_PRINTTIME printf( "%d seconds.", (int)(stop_t-start_t));

char Rcv_Str[0x100];
unsigned int memsize=1024*16;
unsigned int pagesize=128;
unsigned char FlashBuff[1024*16]; // The Bootloader takes 1024*2 bytes

#ifdef __unix__
	#define MAX_PATH PATH_MAX
	#define DWORD unsigned long int
	#define stricmp strcasecmp
	#define BOOL bool
	int fd;
	char SerialPort[MAX_PATH]="/dev/ttyUSB0";
	struct termios comio;
#else
	HANDLE hComm=INVALID_HANDLE_VALUE;
	int SerialPort=1;
#endif

char m_FileName[MAX_PATH]="";
char m_Serial[0x100]="";
int m_memsize=0;
int m_timeout=15;
int m_Reset=0;
char m_Baud[0x20]="115200";
int Selected_Device=-1;
int m_FlashDebugger=0;
char m_DebuggerFilename[MAX_PATH]="";

#ifdef __unix__

int Select_Baud (int Baud_Rate)
{
	switch (Baud_Rate)
	{
		case 115200: return B115200;
		case 57600:  return B57600;
		case 38400:  return B38400;
		case 19200:  return B19200;
		case 9600:   return B9600;
		case 4800:   return B4800;
		case 2400:   return B2400;
		case 1800:   return B1800;
		case 1200:   return B1200;
		default:     return B4800;
	}
}

//CSIZE  Character size mask.  Values are CS5, CS6, CS7, or CS8.
//CSTOPB Set two stop bits, rather than one.
//PARENB Enable parity generation on output and parity checking for input.
//PARODD If set, then parity for input and output is odd; otherwise even parity is used.
#define ONESTOPBIT 0 
#define TWOSTOPBITS CSTOPB 
#define NOPARITY 0

int OpenSerialPort(char * devicename, int baud, int parity, int numbits, int numstop)
{
    struct termios options;
	speed_t BAUD;
	
	BAUD=Select_Baud(baud);
	if(BAUD==B4800)	printf("Baud rate set to 4800\n");
	
	//open the device(com port) to be non-blocking (read will return immediately)
	fd = open(devicename, O_RDWR | O_NOCTTY | O_NDELAY );
	if (fd < 0)
	{
		perror(devicename);
		return(1);
	}
	
	/*Reading data from a port is a little trickier. When you operate the port
	in raw data mode, each read system call will return however many characters
	are actually available in the serial input buffers. If no characters are
	available, the call will block (wait) until characters come in, an interval
	timer expires, or an error occurs. The read function can be made to return
	immediately by doing the following:*/	

	/* The FNDELAY option causes the read function to return 0 if no characters
	are available on the port. To restore normal (blocking) behavior, call
	fcntl() without the FNDELAY option:*/
	
 	//fcntl(fd, F_SETFL, FNDELAY);
    fcntl(fd, F_SETFL, 0);
	
	/*This is also used after opening a serial port with the O_NDELAY option.*/

	// Make the file descriptor asynchronous 
	
	tcgetattr(fd, &comio);
	
	//newtio.sg_ispeed = newtio.sg_ospeed = BAUD;
	cfsetospeed(&comio, (speed_t)BAUD);
	cfsetispeed(&comio, (speed_t)BAUD);
	
	comio.c_cflag = BAUD | CS8 | CSTOPB | CLOCAL | CREAD;
	comio.c_cflag &= ~(CRTSCTS); /* No hardware flow control */
	comio.c_iflag = IGNPAR;
	comio.c_iflag &= ~(IXON | IXOFF | IXANY); /* No software flow control */
	comio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); /* Raw input mode*/
	comio.c_oflag &= ~OPOST; /* Raw ouput mode */
	comio.c_cc[VMIN]=0;
	comio.c_cc[VTIME]=1;
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &comio);

	return(0);
}

void CloseSerialPort(void)
{
	close(fd);
}

void Sleep (int msec)
{
	struct timespec req;

	req.tv_sec=0;
	req.tv_nsec=1000000L*msec;
    nanosleep (&req, NULL);
}

void Delay (int usec)
{
	struct timespec req;

	req.tv_sec=0;
	req.tv_nsec=1000L*usec;
    nanosleep (&req, NULL);
}

#else

int OpenSerialPort (char * Port, DWORD baud, BYTE parity, BYTE bits, BYTE stop)
{
	char sPort[16];
	DCB dcb;
	COMMTIMEOUTS Timeouts;

	sprintf(sPort, "\\\\.\\%s", Port);
	
	hComm = CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hComm == INVALID_HANDLE_VALUE)
	{
		printf("Failed to open up the comunication port %s\n", Port);
		return -1;
	}
	
	if (!GetCommState(hComm, &dcb))
	{
		printf("Failed in call to GetCommState()\n");
		return -1;
	}

	dcb.fAbortOnError=FALSE;
	dcb.BaudRate = baud; 
	dcb.Parity = parity;
	dcb.ByteSize = bits;
	dcb.StopBits = stop;
	dcb.fDsrSensitivity = FALSE;
	dcb.fOutxCtsFlow = FALSE;
	dcb.fOutxDsrFlow = FALSE;
	dcb.fOutX = FALSE;
	dcb.fInX = FALSE;

	//Now that we have all the settings in place, make the changes
	if (!SetCommState(hComm, &dcb))
	{
		printf("Failed in call to SetCommState()\n");
		return -1;
	}	

	ZeroMemory(&Timeouts, sizeof(COMMTIMEOUTS));
	Timeouts.ReadIntervalTimeout = 250;
	Timeouts.ReadTotalTimeoutMultiplier = 10;
	Timeouts.ReadTotalTimeoutConstant = 250;
	Timeouts.WriteTotalTimeoutMultiplier = 10;
	Timeouts.WriteTotalTimeoutConstant = 250;
	if (!SetCommTimeouts(hComm, &Timeouts))
	{
		printf("Failed in call to SetCommTimeouts\n");
		return -1;
	}

	return 0;
}

int CloseSerialPort (void)
{
	BOOL bSuccess;
	bSuccess = CloseHandle(hComm);
    hComm = INVALID_HANDLE_VALUE;
    if (!bSuccess)
    {
		printf("Failed to close serial port, GetLastError:%d\n", GetLastError());
		return -1;
	}
	return 0;
}

#endif

// Functions to read write hex/bin files
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
	return	hex2dec(buffer[0])*0x1000+
			hex2dec(buffer[1])*0x100+
			hex2dec(buffer[2])*0x10+
			hex2dec(buffer[3]);
}

long filesize(FILE *stream)
{
   long curpos, length;

   curpos = ftell(stream);
   fseek(stream, 0L, SEEK_END);
   length = ftell(stream);
   fseek(stream, curpos, SEEK_SET);
   return length;
}

int ReadHexFile(char * filename, BOOL isdebugger)
{
	char buffer[1024];
	FILE * filein;
	int j, numbytes;
	unsigned char linesize, recordtype, rchksum, value;
	unsigned short address;
	int MaxAddress=0;
	int chksum;
	int line_counter=0;
	int numread=0;
	int LoadedBytes=0;

	if(isdebugger==FALSE)
	{
		//Set the buffer to its default value
		for(j=0; j<0x4000; j++) FlashBuff[j]=0xff;
	}

    if ( (filein=fopen(filename, "r")) == NULL )
    {
       printf("Error: Can't open file `%s`.\r\n", filename);
       fflush(stdout);
       return -1;
    }
    
	numbytes=filesize(filein);

    while(fgets(buffer, sizeof(buffer), filein)!=NULL)
    {
    	numread+=(strlen(buffer)+1);

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
				if((address+j)<0x10000)
				{
					FlashBuff[address+j]=value;
					LoadedBytes++;
				}
			}
			if(MaxAddress<(address+linesize-1)) MaxAddress=(address+linesize-1);

			if((chksum%0x100)!=0)
			{
				printf("ERROR: Bad checksum in file '%s' at line %d\r\n", filename, line_counter);
				fflush(stdout);
				return -1;
			}
		}
    }
    fclose(filein);
	
	printf("%s: loaded %d bytes\n", filename, LoadedBytes); 

    return MaxAddress;
}

BOOL PortWrRd(char x, DWORD delay)
{
	DWORD j;
    char s=0;
    
#ifdef __unix__
    j=write(fd, &x, 1);  // For Unix/Apple
#else
    WriteFile(hComm, &x, 1, &j, NULL);
#endif

    Sleep(delay+1);
    
#ifdef __unix__
	j = read(fd, &s, 1); // For Unix/Apple
#else
    ReadFile(hComm, &s, 1, &j, NULL);
#endif

	return (s==x)?TRUE:FALSE;
}


BOOL PortWrStr(char * x, int sleeptime, int timeout)
{
    time_t ltime1, ltime2;
	char val[2];
	int baud=atoi(m_Baud);
	int nmsec;
	DWORD j;
	char c;
	
	strcpy(Rcv_Str,"");
	// Prolific Serial port hack...
	nmsec=(115200*20)/baud;

#ifdef __unix__
    write(fd, x, strlen(x));
#else
    WriteFile(hComm, x, strlen(x), &j, NULL);
#endif
	Sleep(sleeptime+nmsec);

    c='$';
    time(&ltime2);
    ltime1=ltime2+(timeout?timeout:6);

    while((c!='.') && (ltime2<ltime1) )
    {
#ifdef __unix__
    	j=read(fd, &c, 1);
#else
    	ReadFile(hComm, &c, 1, &j, NULL);
#endif
        if(j==1)
		{
			if(c!='.')
			{
				val[0]=c; val[1]=0;
				if ( strlen(Rcv_Str)<sizeof(Rcv_Str) ) strcat(Rcv_Str, val);
			}
		}
		else
		{
			//printf(",");
		}
		
		time(&ltime2);

    }
    return (c=='.')?TRUE:FALSE;
}

BOOL PrepareIntelLine(char * x, int address, int len) 
{
	int j;
	unsigned char chk_sum;
	char buff[0x300];
	BOOL toret=0;

	sprintf(x, ":%02X%04X00", len, address);
	chk_sum= (unsigned char) (len + (address%0x100) + (address/0x100));

	for (j=0; j<len; j++)
	{
		sprintf(buff, "%02X", FlashBuff[address+j]);
		chk_sum += (unsigned char) FlashBuff[address+j];
		strcat(x, buff);
		if (FlashBuff[address+j]!=0xff) toret=1; //Don't send empty lines
	}
	sprintf(buff,"%02X\r\n", (unsigned char)(0x100-chk_sum));
	strcat(x, buff);
	return toret;
}

int CheckPage(int j)
{
	int k;

	for(k=j; k<(j+pagesize); k++)
	{
		if(FlashBuff[k]!=0xff) return 1;
	}
	return 0;
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


/******************************************************************************/
unsigned short crc16_ccitt(
        const unsigned char     block[],
        unsigned int            blockLength,
        unsigned short          crc)
{
    unsigned int i;

    for(i=0U; i<blockLength; i++){
        unsigned short tmp = (crc >> 8) ^ (unsigned short) block[i];
        crc = ((unsigned short)(crc << 8U)) ^ crc16_ccitt_table[tmp];
    }
    return crc;
}

void Flash(void) 
{
    int portn, baud, GoodU=0, Utries=0;
    DWORD delay;
	char buff[0x300];
	unsigned long int j;
	int dash_cnt;
	int N76E003_crc, calculated_crc;

	#define LINESIZE 32

    baud=atoi(m_Baud);
    delay=14000/baud;
   
    if(OpenSerialPort(m_Serial, baud, NOPARITY, 8, ONESTOPBIT)<0)
    {
        printf("ERROR: Could not open serial port.");
        return;
    }

	printf("Waiting for bootloader activation...\n");
	fflush(stdout);

    for(Utries=0; Utries<200 ; Utries++)
    {
        if(PortWrRd('U', delay)) GoodU++;
        else GoodU=0;
        if(GoodU==25) break; //Assume we got the N76E003 bootloader running
    }
    if(GoodU!=25)
    {
    	printf("Couldn't communicate with the N76E003 bootloader.\n");
    	return;
    }

	T_START; // Measure the time it takes to program the microcontroller
	
	//Identify the microcontroller
	if(!PortWrStr(":00000005FB", 100, 0))
	{
		printf("ERROR: Part identification command failed.\n");
		goto The_end;
	}
	
	printf("Identification string received: %s\n", Rcv_Str);
	
	if(strcmp(Rcv_Str, "N76E003")!=0)
	{
		printf("ERROR: Not a N76E003 with serial bootloader!\n");
		fflush(stdout);
		goto The_end;
	}

    printf("Loading file...\n");  fflush(stdout);
	if(ReadHexFile(m_FileName, FALSE)<0)
    {
        printf("ERROR: Could not load HEX file.\n");
        return;
    }
    
    // Load the debugger
	if(m_FlashDebugger==TRUE)
	{
	}

    printf("Erasing flash memory, please wait...\n");  fflush(stdout);
	//Send erase flash command
	if(!PortWrStr(":00000003FD", 0, 10 /*Second*/)) // 10 seconds should be enough
	{
		printf("ERROR: Flash erase command failed.\n");
		goto The_end;
	}
	printf("Flash memory erased.\n"); 

    printf("Programming flash memory...\n");  fflush(stdout);
	printf("#");
	for(j=0, dash_cnt=0; j<memsize; j+=LINESIZE)
    {
		PrepareIntelLine(buff, j, LINESIZE);

		if(CheckPage(j)) // Any byte in page needs to be written?
		{
			dash_cnt++;
			if(dash_cnt==60)
			{
				dash_cnt=0;
				printf("\n");
			}
			printf("#");
			fflush(stdout);
			if(!PortWrStr(buff, 0, 1))
			{
                printf("\nERROR: Flash program command failed.\n");
				fflush(stdout);
                goto The_end;
			}
		}
	}
	printf("\nDone\n");
	fflush(stdout);

	printf("Verifiying flash memory...\n"); fflush(stdout);
	fflush(stdout);
	
	calculated_crc=crc16_ccitt(FlashBuff, memsize, 0);
	sprintf(buff, "%04X", calculated_crc);
	if(!PortWrStr(":00000004FC", 0, 10 /*Second*/)) // 10 seconds should be enough
	{
		printf("ERROR: Verify command failed.\n");
		goto The_end;
	}

	if(strcmp(Rcv_Str, buff)==0)
	{
		printf("Verify success.  CRC: 0x%s\n", Rcv_Str);
		fflush(stdout);
	}
	else
	{
		printf("ERROR: File CRC: 0x%s; Flash CRC: 0x%s\n", buff, Rcv_Str);
		fflush(stdout);
		goto The_end;
	}

	if(m_Reset==1)
	{
		printf("Sending reset command...\n"); fflush(stdout);
		fflush(stdout);

#ifdef __unix__
    	write(fd, ":00000002FE", 11);
#else
    	WriteFile(hComm, ":00000002FE", 11, &j, NULL);
#endif
		Sleep(500);
	}
	else
	{
		//Send the end record
		if(!PortWrStr(":00000001FF", 0, 0))
		{
			printf("ERROR: Flash end failed.\n");  fflush(stdout);
			goto The_end;
		}
	}

    printf("Flash program command completed!\n");  fflush(stdout);
    
The_end:
    CloseSerialPort();
    Sleep(200);
    
    printf("Actions completed in ");
    T_STOP;
	T_PRINTTIME;
	printf("\n");
	fflush(stdout);
}

void GetOut (int val)
{
	exit(val);
}

void print_help (char * prn)
{
	printf("Usage example:\n"
#ifdef __unix__
	#ifdef __APPLE__
	       "%s -p/dev/cu.usbserial-DN05FVT8 somefile.hex\n"
	#else
	       "%s -p/dev/ttyUSB0 somefile.hex\n"
	#endif
#else
	       "%s -pCOM3 somefile.hex\n"
#endif
	       "(load flash memory with file 'somefile.hex' via the port specified after '-p')\n"
	       "\n"
	       "Options available:\n"
	       "   -p[portname] (use this serial port).\n"
	       "   -r reset after flashing.\n"
	       "   -d[debugger.hex] also flash the debugger from the indicated hex file.\n"
#ifdef _MSC_VER
	       "   -f Use FT230XS to activate bootloader.\n"
#endif
	       "   -h (this help).\n"
	       "\n"
#ifdef __unix__
	#ifdef __APPLE__
		   "To check what serial ports are available, on a Mac terminal type:\n"
		   "ls -l /dev | grep \"usb\"\n"
	#else
		   "To check what serial ports are available, on a Linux terminal type:\n"
		   "ls -l /dev | grep \"USB\"\n"
	#endif
#else
		   "To check what serial ports are available, on command prompt type:\n"
		   "mode | find /i \"Status\""
#endif
	       , prn);
	fflush(stdout);
}

// This works only on Windows when compiled with MS Visual C.
#ifdef _MSC_VER
// CBUS3 and CBUs0 are used as RESET and BOOT respectevely, to activate bootload mode.
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
	
	status = FT_EEPROM_Read(ft_handle, &ft_eeprom_x_series, sizeof(ft_eeprom_x_series),
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
				status = FT_EEPROM_Program(ft_handle, &ft_eeprom_x_series, sizeof(ft_eeprom_x_series),
										Manufacturer, ManufacturerId, Description, SerialNumber);
				if (status == FT_OK)
				{
					FT_CyclePort(ft_handle); // It takes about 5 seconds to cycle port
					FT_Close(ft_handle);

					printf("Congiguring FT230XS IC.  Please wait.\n");  fflush(stdout);
	
					for(j=0; j<40; j++)
					{
						if(FT_Open(0, &ft_handle) != FT_OK)
						{
							Sleep(200);
						}
						else
						{
							break;
						}
					}
					if(j==40)
					{
				        printf("ERROR: Can not open FTDI adapter.");
						GetOut(0);
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
				status = FT_EEPROM_Program(ft_handle, &ft_eeprom_x_series, sizeof(ft_eeprom_x_series),
										Manufacturer, ManufacturerId, Description, SerialNumber);
				if (status == FT_OK)
				{
					FT_CyclePort(ft_handle); // It takes about 5 seconds to cycle port
					FT_Close(ft_handle);
					printf("WARNING: Pins CBUS3 and CBUS0 have been configured as factory default. ");
					GetOut(0);
				}
			}
		}
	}
}

void Activate_Bootloader (void)
{
	// Bits 7 down to 4 set CBUSx as either input or ouput.  Bits 3 down to 0 is the actual output.
	// For example 0x90 configures CBUS3 and CBUS0 as outputs and set their values to zero.
	// 0x10 makes CBUS3 an input but keeps CBUS0 to logic zero
	// 0x00 makes both CBUS3 and CBUS0 inputs
	unsigned char Seq[3]={0x90, 0x10, 0x00};
	unsigned char c;

    FT_SetBaudRate(ft_handle, 115200);
	
	FTDI_Set_CBUS_Mode(1); // Make sure both CBUS3 and CBUS0 are in "CBUS IOMODE"
	
	for(c=0; c<3; c++)
	{ 
		FT_SetBitMode(ft_handle, Seq[c], FT_BITMODE_CBUS_BITBANG); // RESET=0, TEST=0; RESET=1, TEST=0; RESET=1, TEST=1;
		Sleep(50); // Sleep mili seconds
	}
	
	FT_Purge(ft_handle, FT_PURGE_RX | FT_PURGE_TX);
	//FT_SetBitMode(ft_handle, 0x00, FT_BITMODE_CBUS_BITBANG); // Set CBUS3 and CBUS0 as input
	FT_SetBitMode(ft_handle, 0x0, FT_BITMODE_RESET); // Back to serial port mode

	Sleep(10);
}

#endif

int main(int argc, char **argv)
{
	int j;
	
	unsigned char buff[32];
	BOOL use_ft230=FALSE;
	long int portn;

    printf("Serial flash programmer for the N76E003. (C) Jesus Calvino-Fraga 2023\n");
    fflush(stdout);
	
    for(j=1; j<argc; j++)
    {
    		 if(EQ("-h", argv[j])) {print_help(argv[0]); return 0;}
		else if(strnicmp("-p", argv[j], 2)==0) { sprintf(m_Serial, "%s", &argv[j][2]); }
		else if(strnicmp("-d", argv[j], 2)==0) { sprintf(m_DebuggerFilename, "%s", &argv[j][2]); m_FlashDebugger=TRUE; }
		//else if(strnicmp("-b", argv[j], 2)==0) { sprintf(m_Baud, "%s", &argv[j][2]); }
		else if(strnicmp("-r", argv[j], 2)==0) { m_Reset=1; }
		else if(stricmp("-ft230", argv[j])==0) { use_ft230=TRUE; }
		else if(strnicmp("-f", argv[j], 2)==0) { use_ft230=1; }
    	else strcpy(m_FileName, argv[j]);
    }
    
// This works only on Windows when compiled with MS Visual C.
#ifdef _MSC_VER
    if(use_ft230)
	{
	    if(FT_Open(0, &ft_handle) == FT_OK)
	    {	    
			if(stricmp("CBUS", m_Serial)==0)
			{
				FTDI_Set_CBUS_Mode(0); // Restore default operation of CBUS0 and CBUS3
			}
			else
			{
				if (FT_GetComPortNumber(ft_handle, &portn) == FT_OK)
				{ 
	    			if (portn != -1)
	    			{
						sprintf(m_Serial, "COM%d", portn);
			    		printf("Connected to %s\n", m_Serial); fflush(stdout);
			    		sprintf(buff,"echo %s>COMPORT.inc", m_Serial);
			    		system(buff);
	    			}
				}
				
				Activate_Bootloader();
				FT_Close(ft_handle); // The port will be re-open as an standard serial port
			}
	    }
	}
#endif

    if(strlen(m_FileName)==0)
    {
    	printf("ERROR: Need an Intel Hex file to proceed.\n");
    	print_help(argv[0]);
    	return 1;
    }
    if(strlen(m_Serial)==0)
    {
    	printf("ERROR: Serial port empty or not detected.\n");
    	print_help(argv[0]);
    	return 1;
    }

    Flash();
    return 0;
}
