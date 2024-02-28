/*
CMON51: C Monitor for the 8051
Copyright (C) 2005, 2006  Jesus Calvino-Fraga / jesusc at ece.ubc.ca

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

//This file covers the specifics of the Atmel AT89C51RD2/ED2 microcontroller

#include <at89c51ed2.h>
#include "baud.h"
#include "proto.h"

#define CPUPID "Port: AT89C51RD2/ED2 V1.1\n"

#ifndef MONITOR_LOC
#define MONITOR_LOC 0xe000
#endif

//This is the function that enters after just one assembly instruction of user code
//is executed in single step mode.  Since the monitor for the p89v51d2 is located at
//the top of memory, we use vector 0 to save a bit of code space.  As a matter of fact
//this will come form vector 3, the timer 1 interrupt located at the bottom of memory. 
//void step_and_break (void) interrupt 0; c51 doesn't allow interrupt prototypes

extern volatile xdata unsigned char saved_jmp[3];
extern volatile xdata unsigned char saved_int[3];
extern volatile xdata unsigned int  PC_save;
extern volatile xdata char iram_save[128];

//These are the Special Function Register names for the
//Atmel AT89C51RD2/ED2 microcontroller.
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
	"\242" "AUXR1"	 \/*A2*/
	"\216" "AUXR"	 \/*8E*/
	"\227" "CKRL"	 \/*97*/
	"\217" "CKCKON0" \/*8F*/
	"\217" "CKCKON1" \/*8F*/
	"\372" "CCAP0H"	 \/*FA*/
	"\373" "CCAP1H"	 \/*FB*/
	"\374" "CCAP2H"	 \/*FC*/
	"\375" "CCAP3H"	 \/*FD*/
	"\376" "CCAP4H"	 \/*FE*/
	"\352" "CCAP0L"	 \/*EA*/
	"\353" "CCAP1L"	 \/*EB*/
	"\354" "CCAP2L"	 \/*EC*/
	"\355" "CCAP3L"	 \/*ED*/
	"\356" "CCAP4L"	 \/*EE*/
	"\332" "CCAPM0"	 \/*DA*/
	"\333" "CCAPM1"	 \/*DB*/
	"\334" "CCAPM2"	 \/*DC*/
	"\335" "CCAPM3"	 \/*DD*/
	"\336" "CCAPM4"	 \/*DE*/
	"\330" "CCON"	 \/*D8*/
	"\371" "CH"	     \/*F9*/
	"\351" "CL"	     \/*E9*/
	"\331" "CMOD"	 \/*D9*/
	"\250" "IEN0"	 \/*A8 Same as IE above*/
	"\261" "IEN1"	 \/*B1*/
	"\270" "IPL0"	 \/*B8 Same as IP above*/
	"\267" "IPH0"	 \/*B7*/
	"\262" "IPL1"	 \/*B2*/
	"\263" "IPH1"	 \/*B3*/
	"\300" "P4"	     \/*C0*/
	"\330" "P5"	     \/*D8*/
	"\246" "WDTRST"	 \/*A6*/
	"\247" "WDTPRG"	 \/*A7*/
	"\251" "SADDR"	 \/*A9*/
	"\271" "SADEN"	 \/*B9*/
	"\303" "SPCON"	 \/*C3*/
	"\304" "SPSTA"	 \/*C4*/
	"\305" "SPDAT"	 \/*C5*/
	"\311" "T2MOD"	 \/*C9*/
	"\233" "BDRCON"	 \/*9B*/
	"\232" "BRL"	 \/*9A*/
	"\234" "KBLS"	 \/*9C*/
	"\235" "KBE"	 \/*9D*/
	"\236" "KBF"	 \/*9E*/
	"\322" "EECON"	 \/*D2*/
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
    "\257" "EA"      \/*AF*/ 
    "\274" "PS"      \/*BC*/ 
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
    "\255" "ET2"     \/*AD*/ 
    "\337" "CF"      \/*DF*/ 
    "\336" "CR"      \/*DE*/ 
    "\256" "EC"      \/*AE*/ 
    "\353" "EBO"     \/*EB*/ 
    "\276" "PPC"     \/*BE*/ 
    "\373" "PBO"     \/*FB*/
	"\337" "CF"	     \/*DF*/
	"\336" "CR"	     \/*DE*/
	"\334" "CCF4"	 \/*DC*/
	"\333" "CCF3"	 \/*DB*/
	"\332" "CCF2"	 \/*DA*/
	"\331" "CCF1"	 \/*D9*/
	"\330" "CCF0"	 \/*D8*/
	"\256" "EC"	     \/*AE*/
	"\276" "PPCL"	 \/*BE*/
	"\275" "PT2L"	 \/*BD*/
	"\274" "PLS"	 \/*BC*/
	"\273" "PT1L"	 \/*BB*/
	"\272" "PX1L"	 \/*BA*/
	"\271" "PT0L"	 \/*B9*/
	"\270" "PX0L"	 \/*B8*/
	"\210" "\000"/*The end of the list*/
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
	
	//Enable all the built in expanded RAM
	AUXR=XRS2;
	
	//Disable the Bootprom
	AUXR&=(~ENBOOT);
	
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

//Write a byte in to the flash using the IAP routines of the AT89C51RD2/ED2.
void FlashByte (unsigned int address, unsigned char value)
{
	if(address>=MONITOR_LOC) return; //Protect the monitor

	_asm
		mov R1, #0x02
		;DPH contains the high part of the sector
		;DPL contains the low part of the sector
		mov	a,_FlashByte_PARM_2
		mov _AUXR1,#0x20
		lcall 0xfff0 ; The entry point of the default at89c51rd2 bootloader
		mov _AUXR1,#0x00
	_endasm;
	
	value; //get rid of c51 warnings
}


void erasesector (unsigned int sector)
{
	_asm
		mov r1, #0x01
		mov _AUXR1,#0x01
		mov dpl, #00
		mov dph, #00
		mov _AUXR1,#00
		mov dph, r3
		mov _AUXR1,#0x20
		lcall 0xfff0 ;
		mov _AUXR1,#0x00
	_endasm;
	if (sector==0x0000)
	{
		FlashByte(0x00, 0x02);
		FlashByte(0x01, MONITOR_LOC/0x100);
		FlashByte(0x02, MONITOR_LOC%0x100);
		FlashByte(0x1b, 0x02);
		FlashByte(0x1c, MONITOR_LOC/0x100);
		FlashByte(0x1d, (MONITOR_LOC%0x100)+3);
	}
}

void WriteBlock (unsigned int src, unsigned int dst, unsigned char size)
{
	_asm
		mov r1, #0x09
		push dpl ; src comes in dpl,dph
		push dph
		mov _AUXR1,#0x01
		pop dph
		pop dpl
		mov _AUXR1, #0x00
		mov dpl, _WriteBlock_PARM_2
		mov dph, _WriteBlock_PARM_2+1
		mov a, _WriteBlock_PARM_3
		mov _AUXR1,#0x20
		lcall 0xfff0 ; The entry point of the default at89c51rd2 bootloader
		mov _AUXR1,#0x00
	_endasm;
	src; dst; size;
}

void loadintelhex (void)
{
	unsigned char j;
	unsigned char size, type, check, n;
	code unsigned char * ptr;
	bit errorbit, wroteat1b;
	unsigned int address, curradd;

	saved_jmp[0]=0;        	
	saved_int[0]=0;        	

	putsp("Erasing...");
	erasesector(0x0000);
	erasesector(0x2000);
	erasesector(0x4000);
	erasesector(0x8000);
	putsp("\nSend file or <Esc>\n");
	
	errorbit=0;
	wroteat1b=0;
	
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
			
			for(j=0; j<size; j++)
			{
				n=getbytene();
				check+=n;
				if(type==0x00)
				{
					curradd=address+j;
					
					if((curradd>2) && ((curradd<0x1b)||(curradd>0x1d)))
					{
						iram_save[j]=n;
					}
					else
					{
						ptr=(code unsigned char *)curradd;
						iram_save[j]=*ptr;
						
						if (curradd<0x3)
						{
							saved_jmp[curradd]=n;
						}
						else //If is not a jump, it will trigger a warning
						{
							saved_int[curradd-0x1b]=n;
							wroteat1b=1;
						}
					}
				}
			}
	
			check+=getbytene();
	
			if(type!=0x00) break; //Most likely end record (type=0x01)
			if(check!=0)
			{
				errorbit=1;
				putc('X'); //This means there was a checksum error in the record
			}
			else
			{
				WriteBlock((unsigned int)iram_save, address, size);
				putc('.');
			}
		}
	}

	if(errorbit) putsp("\nChecksum error!\n");
	else putsp("\nDone.\n");

	if(RI) getchar();//Last newline from final record
	
    if(saved_jmp[0]==0x02)
    {
		//Copy the jump into the flash so it is accesible after reset
		FlashByte(MONITOR_LOC-2, saved_jmp[2]);
		FlashByte(MONITOR_LOC-1, saved_jmp[1]);
		restorePC();
	}
	
	if((saved_int[0]!=0x02)&&(wroteat1b)) putsp("WARNING: missing Timer1 jmp\n");
	fillmem(&iram_save[0], 0x80, 0);
}

unsigned char read_sfr (unsigned char x)
{
	IE=0;
	_asm 
			mov a, dpl		; x is passed in dpl
			push acc
			mov r1, #0x02	; program data byte
			mov dptr, #read_sfr_loc+1
			mov _AUXR1,#0x20
			lcall 0xfff0	; The entry point of the default at89c51rd2 bootloader
			mov _AUXR1,#0x00
			pop acc
			mov r1, #0x02	; program data byte
			mov dptr, #write_sfr_loc+2
			mov _AUXR1,#0x20
			lcall 0xfff0	; The entry point of the default at89c51rd2 bootloader
			mov _AUXR1,#0x00

		read_sfr_loc:
			__dummy_sfr_location data 0xff ; Done this way to prevent an a51 warning.
	    	mov dpl, __dummy_sfr_location ; The default 0xff will be replaced by 'x'
	    	ret
	_endasm;
	x;
	return 0;
}

//A read_sfr must preced write_sfr
void write_sfr (unsigned char val)
{

	_asm
		write_sfr_loc:
			mov 0xff, dpl
	    	ret
	_endasm;
	val; //To prevent a c51 warning. Optimized out by c51.
}

void restorePC (void)
{
	PC_save=*(unsigned int code *)(MONITOR_LOC-2); //A copy of the user jump should be there
}

void cpuid (void)
{
	putsp(CPUPID);
}

void set_timer1_priority (void) _naked
{
	_asm
        setb    PT1				; Highest priority for timer 1 interrupt
        orl		_IPH0, #0x80	; Highest priority for timer 1 interrupt
        ret
    _endasm;
}

//Leave this code at the end of the file, or the absolute area will force the whole code
//generated for this file to be at area JUMPCSEG at the begining of the code memory.
void JumpToMonitor (void) _naked
{
    _asm
    cseg at 0x0000    ; Jump to where the monitor is
    ljmp MONITOR_LOC
    
    cseg at 0x001B    ; Timer 1 interrupt vector used for step by step execution.
    ljmp MONITOR_LOC + 0x0003

    cseg at MONITOR_LOC - 2
    db 0x00, 0x00 ; Here the user PC will be saved.  Default it to zero.
    _endasm;
}

