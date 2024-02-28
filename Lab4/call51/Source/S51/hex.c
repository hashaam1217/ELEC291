/*
    hex.c: Functions used to read Intel hex files

    Copyright (C) 2009-2012  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca
    
	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation; either version 2, or (at your option) any
	later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

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

int ReadHexFile(char * filename, unsigned char * Code)
{
	char buffer[1024];
	FILE * filein;
	int j;
	unsigned char linesize, recordtype, rchksum, value;
	unsigned short address;
	int MaxAddress=0;
	int chksum;
	int line_counter=0;
	int numread=0;

	//Set the buffer to its default value
	memset(Code, 0xff, 0x10000);

    if ( (filein=fopen(filename, "r")) == NULL )
    {
       return -1;
    }
    
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
				if((address+j)<0x10000) Code[address+j]=value;
			}
			if(MaxAddress<(address+linesize-1)) MaxAddress=(address+linesize-1);

			if((chksum%0x100)!=0)
			{
				printf("ERROR: Bad checksum in file '%s' at line %d\r\n", filename, line_counter);
				return -1;
			}
		}
    }
    fclose(filein);

    return MaxAddress;
}
