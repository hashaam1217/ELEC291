/*
CMON51: C Monitor for the 8051
Copyright (C) 2005-2013  Jesus Calvino-Fraga / jesusc at ece.ubc.ca

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

//This file covers the specifics of the Generic 8052 microcontroller
//with overlaped XRAM and CODE memory

#include <8052.h>
#include "baud.h"
#include "proto.h"

#pragma disable_warning 196

#ifndef SFR_CODE_LOC
#define SFR_CODE_LOC 0x7ff8
#endif

#ifndef XRAM_CODE_LOC
#define XRAM_CODE_LOC 0x2000
#endif

#define CPUPID "Port: 8052 V2.0\n"

extern volatile xdata unsigned int  PC_save;

extern const unsigned char code_sfr[];

//Since the special function registers are only accesible directly, write into the
//XRAM/CODE an small piece of code to access them. The 0xff will be replaced with
//the address of the sfr.
void asm_code_sfr (void) _naked
{
    _asm
    	_code_sfr:
		; Write  sfr
		mov 0xff, dpl
		ret
		; Read sfr
		sfr_addr_dummy data 0xff ; The assembler warns about constants without '#'
		mov dpl, sfr_addr_dummy
		ret
    _endasm;
}

//These are the Special Function Register names for the
//plain 8051/8052 microcontroller
code unsigned char sfrn[] =
{
    "\200" "P0"      \/*80*/
    "\201" "SP"      \/*81*/
    "\202" "DPL"     \/*82*/
    "\203" "DPH"     \/*83*/
    "\207" "PCON"    \/*87*/
    "\210" "TCON"    \/*88*/
    "\211" "TMOD"    \/*89*/
    "\212" "TL0"     \/*8A*/
    "\213" "TL1"     \/*8B*/
    "\214" "TH0"     \/*8C*/
    "\215" "TH1"     \/*8D*/
    "\220" "P1"      \/*90*/
    "\230" "SCON"    \/*98*/
    "\231" "SBUF"    \/*99*/
    "\240" "P2"      \/*A0*/
    "\250" "IE"      \/*A8*/
    "\260" "P3"      \/*B0*/
    "\270" "IP"      \/*B8*/
    "\310" "T2CON"   \/*C8*/
    "\311" "T2MOD"   \/*C9*/
    "\312" "RCAP2L"  \/*CA*/
    "\313" "RCAP2H"  \/*CB*/
    "\314" "TL2"     \/*CC*/
    "\315" "TH2"     \/*CD*/
    "\320" "PSW"     \/*D0*/
    "\340" "ACC"     \/*E0*/
    "\340" "A"       \/*E0 for dissasembly "ACC" will be used instead */
    "\360" "B"       \/*F0*/
    "\200" "\000" /*The end of the list*/
};

//These are the bit names...
code unsigned char bitn[] =
{
    "\210" "IT0"     \/*88*/ 
    "\211" "IE0"     \/*89*/ 
    "\212" "IT1"     \/*8A*/ 
    "\213" "IE1"     \/*8B*/ 
    "\214" "TR0"     \/*8C*/ 
    "\215" "TF0"     \/*8D*/ 
    "\216" "TR1"     \/*8E*/ 
    "\217" "TF1"     \/*8F*/ 
    "\230" "RI"      \/*98*/ 
    "\231" "TI"      \/*99*/ 
    "\232" "RB8"     \/*9A*/ 
    "\233" "TB8"     \/*9B*/ 
    "\234" "REN"     \/*9C*/ 
    "\250" "EX0"     \/*A8*/ 
    "\251" "ET0"     \/*A9*/ 
    "\252" "EX1"     \/*AA*/ 
    "\253" "ET1"     \/*AB*/ 
    "\254" "ES"      \/*AC*/ 
    "\255" "ET2"     \/*AD*/ 
    "\257" "EA"      \/*AF*/ 
    "\270" "PX0"     \/*B8*/ 
    "\271" "PT0"     \/*B9*/ 
    "\272" "PX1"     \/*BA*/ 
    "\273" "PT1"     \/*BB*/ 
    "\274" "PS"      \/*BC*/ 
    "\275" "PT2"     \/*BD*/ 
    "\320" "P"       \/*D0*/ 
    "\321" "F1"      \/*D1*/ 
    "\322" "OV"      \/*D2*/ 
    "\323" "RS0"     \/*D3*/ 
    "\324" "RS1"     \/*D4*/ 
    "\325" "F0"      \/*D5*/ 
    "\326" "AC"      \/*D6*/ 
    "\327" "CY"      \/*D7*/ 
    "\310" "CP_RL2"  \/*C8*/ 
    "\311" "C_T2"    \/*C9*/ 
    "\312" "TR2"     \/*CA*/ 
    "\313" "EXEN2"   \/*CB*/ 
    "\314" "TCLK"    \/*CC*/ 
    "\315" "RCLK"    \/*CD*/ 
    "\316" "EXF2"    \/*CE*/ 
    "\317" "TF2"     \/*CF*/ 
    "\377" "\000"/*The end of the list*/
};

void main (void)
{
	_asm
	    ljmp _do_cmd
	_endasm; //All the work is done in cmon51.c
}

unsigned char _c51_external_startup(void)
{
	IE=0;
	TR1=0;
	TMOD=(TMOD&0x0f)|0x20;
	PCON|=0x80; //x2 baudrate
	TH1=TIMER1_K2_115200;
	TR1=1;
	SCON=0x52;
	
	return 0;
}

char getchar(void)
{
	while (!RI);
	RI=0;
	return SBUF;
}

void putnl (void)
{
	while (!TI);
	TI=0;
	SBUF='\r';
	while (!TI);
	TI=0;
	SBUF='\n';
}

void loadintelhex (void)
{
	unsigned int j, address;
	unsigned char size, type, check, n;
	unsigned char * xptr;
	unsigned char * cptr;
	bit errorbit, errorprog;

	putsp("Send file or <Esc>\n");
	
	errorbit=0;
	errorprog=0;
	
	while(1)
	{
		n=getchar();
		
		if(n==0x1b) break; //Provide a way out
		
		if(n==(unsigned char)':')
		{
			size=getbytene();
			check=size;
			
			address=getbytene();
			check+=address;
			address*=0x100;
			n=getbytene();
			check+=n;
			address+=n;
			
			type=getbytene();
			check+=type;

			//Use xptr to write to XDATA
			xptr=(unsigned char xdata *)address;
			//Use cptr to verify the byte is visible as code memory
			cptr=(unsigned char code *)address;
			
			for(j=0; j<size; j++)
			{
				n=getbytene();
				check+=n;
				if(type==0x00)
				{
					*xptr=n;
					if(*cptr!=n) errorprog=1;
				}
				xptr++;
				cptr++;
			}
	
			check+=getbytene();
	
			if(type!=0x00) break; //Most likely end record (type=0x01)
			if(check!=0)
			{
				errorbit=1;
				putc('X'); //This means there was a checksum error in the record
			}
			else putc('.');
		}
	}

	if(errorbit) putsp("\nChecksum error!\n");
	else if (errorprog) putsp("\nWrite error!\n");
	else putsp("\nDone.\n");

	if(RI) getchar();//Last newline from final record
	
	restorePC();
}

unsigned char read_sfr (unsigned char x)
{
	unsigned char j;
	xdata unsigned char * ptr;

    ptr=(xdata unsigned char *) SFR_CODE_LOC;
	for(j=0; j<8; j++) ptr[j]=code_sfr[j];
	ptr[2]=x;
	ptr[5]=x;
	
	_asm
		ljmp SFR_CODE_LOC+4;
	_endasm;
	
	return 0;
}

//For this function to work, a call to read_sfr must precede it
void write_sfr (unsigned char val)
{
	_asm
		ljmp SFR_CODE_LOC
	_endasm;
	val; //To prevent a sdcc warning. Optimized out by sdcc.
}

void restorePC (void)
{
	PC_save=XRAM_CODE_LOC;
}

void cpuid (void)
{
	putsp(CPUPID);
}

void set_timer1_priority (void) _naked
{
	_asm
        setb    PT1				; Highest priority for timer 1 interrupt
        ret
    _endasm;
}

//Leave this code at the end of the file, or the absolute area will force the whole code
//generated for this file to be at area JUMPCSEG at the begining of the memory.
void JumpToMonitor (void) _naked
{
    _asm
    CSEG at 0x0003
    ljmp XRAM_CODE_LOC+0x03
    
    CSEG at 0x000B
    ljmp XRAM_CODE_LOC+0x0B
 
    CSEG at 0x0013
    ljmp XRAM_CODE_LOC+0x13
    
    ;Vector 0x001B used by cmon51!

    CSEG at 0x0023
    ljmp XRAM_CODE_LOC+0x23

    CSEG at 0x002B
    ljmp XRAM_CODE_LOC+0x2B
    _endasm;
}
