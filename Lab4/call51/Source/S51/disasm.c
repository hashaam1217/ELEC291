/*
    dis51.c: dissasembles 8051 instructions

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
#include <stdio.h>
#include <stdlib.h>
#include "s51.h"

#define MAXBUFF 0x200
char buff[0x200];
const char hexval[]={"0123456789abcdef"};
int cur;
int discnt;

#define addchar(c) (buff[cur++]=c)
#define outbyte(value) printf("%02x", value)
#define outword(value) printf("%04x", value)
#define putch(value) printf("%c", value)
#define putsp(value) printf("%s", value)

void addbyte (unsigned char x)
{
	addchar(hexval[x/0x10]);
	addchar(hexval[x&0xf]);
	outbyte(x);
	putch(' ');
}

void addstr(unsigned char * x)
{
	while ((*x!=0)&&(*x<0x80))
	{
		addchar(*x);
		x++;
	}
}

void addword (unsigned int x)
{
	addchar(hexval[(x/0x1000)&0xf]);
	addchar(hexval[(x/0x100)&0xf]);
	addchar(hexval[(x/0x10)&0xf]);
	addchar(hexval[x&0xf]);
}

//Disassemble code starting at 'address'.
int disassemble (unsigned char * code_memory, int address, int endaddress)
{
	unsigned int j, k;
	unsigned char n, opcode, i=0;
	unsigned int absadd;
	char bitncheck;
	char opcode0x85;
	int linecounter=0;

	if(discnt==0) discnt=1;

	while(address<endaddress)
	{
		if(address>0xffff) address=0;

		outword(address);
		putsp(": ");
		opcode=code_memory[address];
		outbyte(opcode);
		putch(' ');
		cur=0;
		addchar('\t');

		if(opcode==0x85) opcode0x85=1;
		else opcode0x85=0;
		
		//Parse the mnemonic format string
		for(j=0; op[opcode].mnemonic[j]!=0; j++)
		{
			n=op[opcode].mnemonic[j];
			
			bitncheck=0;
			
			switch (n)
			{
				case '#': //Numeric constant (in hex)
					addchar('#');
					addbyte(code_memory[++address]);
					if(opcode==0x90) //"mov dptr,#1234" uses two bytes (Only exception)
					{
						addbyte(code_memory[++address]);
					}
					break;
					
				case '%': //Direct bit addressing
					n=code_memory[++address];

					if(n>0x7f)
					{
						if(bitn[n-0x80][0]!=0)
						{
							outbyte(code_memory[address]);
							putch(' ');
							for(k=0; bitn[n-0x80][k]!=0; k++) addchar(bitn[n-0x80][k]);
						}
						else
						{
							if(sfrn[(n&0xf8)-0x80][0]!=0)
							{
								outbyte(code_memory[address]);
								putch(' ');
								for(k=0; sfrn[(n&0xf8)-0x80][k]!=0; k++) addchar(sfrn[(n&0xf8)-0x80][k]);
								addchar('.');
								addchar('0'+(n&0x07));
							}
							else
							{
								addbyte(n); // Not in table.  Print the number.
							}
						}
					}
					else
					{
						addbyte(n); //Not an sfr name, print the number
					}
					
					break;
				case '!': //Direct memory addressing including sfrs
					/*WARNING: 'mov direct2, direct1' is flipped;
					85 81(sp) 83(dph) = mov DPH, SP*/
					switch(opcode0x85)
					{
						case 0:
							n=code_memory[++address];
						break;
						case 1:
							n=code_memory[address+2];
							address++;
							opcode0x85++;
						break;
						case 2:
							n=code_memory[address];
							address++;
						break;
					}


					if(n>0x7f)  //Search for sfr name
					{
						if(sfrn[n-0x80][0]!=0)
						{
							outbyte(code_memory[address]);
							putch(' ');
							for(k=0; sfrn[n-0x80][k]!=0; k++) addchar(sfrn[n-0x80][k]);
						}
						else
						{
							addbyte(n); // Not in table.  Print the number.
						}
					}
					else addbyte(n); //Not an sfr name print the number
					break;
					
				case '.': //8 bit relative address
					absadd=address;
					address++;
					//absadd+=(char)code_memory[address] + 1;
					absadd+=(char)code_memory[address]+2;
					addword(absadd);
					outbyte(code_memory[address]);
					putch(' ');
					break;
					
				case '&': //11 bit paged address
					n=(code_memory[address]/0x20)|(((address+2)/0x100)&0xf8);
					address++;
					absadd=(n*0x100)+(code_memory[address]);
					addword(absadd);
					outbyte(code_memory[address]);
					putch(' ');
					break;
					
				case ':': // 16 bit absolute address
					absadd=code_memory[++address]*0x100;
					outbyte(code_memory[address]);
					putch(' ');
					outbyte(code_memory[++address]);
					putch(' ');
					absadd+=code_memory[address];
					addword(absadd);
					break;
					
				default:
					addchar(n);
					break;
			}
		}
		addchar('\n');
		addchar(0);
		putsp(buff);
		address++; //points to next opcode
	}

	return address;
}
