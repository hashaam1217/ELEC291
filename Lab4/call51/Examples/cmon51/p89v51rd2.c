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

//This file covers the specifics of the Philips P89V51RD2 microcontroller

#include <p89v51rd2.h>
#include "baud.h"
#include "proto.h"

#define CPUPID "Port: P89V51RD2 V1.1\n"

#ifndef MONITOR_LOC
#define MONITOR_LOC 0xe000
#endif

//This is the function that enters after just one assembly instruction of user code
//is executed in single step mode.  Since the monitor for the p89v51d2 is located at
//the top of memory, we use vector 0 to save a bit of code space.  As a matter of fact
//this will come form vector 3, the timer 1 interrupt located at the bottom of memory. 
//void step_and_break (void) interrupt 0;

extern volatile xdata unsigned char saved_jmp[3];
extern volatile xdata unsigned char saved_int[3];
extern volatile xdata unsigned int  PC_save;

extern const unsigned char code_sfr[];

//Since the special function registers are only accesible directly, write into the
//flash an small piece of code to access them. (Hopefully the flash is rewritable
//a few thousand times!!!).  The 0xff will be replaced with the address of the sfr.
void asm_code_sfr (void) _naked
{
    _asm
    	dumm_sfr_address data 0xff
    	_code_sfr:
		; Write  sfr
		mov dumm_sfr_address, dpl
		ret
		; Read sfr		
		mov dpl, dumm_sfr_address
		ret
    _endasm;
}

//These are the Special Function Register names for the
//Philips P89V51RD2 microcontroller.
code unsigned char sfrn[] =
{
    "\200" "P0"      \/*80*/
    "\201" "SP"      \/*81*/
    "\202" "DPL"     \/*82*/
    "\203" "DPH"     \/*83*/
    "\205" "WDTD"    \/*85*/
    "\206" "SPDR"    \/*86*/
    "\206" "SPDAT"   \/*86 (This name appears also in the datasheet). */
    "\207" "PCON"    \/*87*/
    "\210" "TCON"    \/*88*/
    "\211" "TMOD"    \/*89*/
    "\212" "TL0"     \/*8A*/
    "\213" "TL1"     \/*8B*/
    "\214" "TH0"     \/*8C*/
    "\215" "TH1"     \/*8D*/
    "\216" "AUXR"    \/*8E*/
    "\220" "P1"      \/*90*/
    "\230" "SCON"    \/*98*/
    "\231" "SBUF"    \/*99*/
    "\240" "P2"      \/*A0*/
    "\242" "AUXR1"   \/*A2*/
    "\250" "IE"      \/*A8*/
    "\251" "SADDR"   \/*A9*/
    "\252" "SPSR"    \/*AA*/
    "\252" "SPCFG"   \/*AA (This name appears also in the datasheet)*/
    "\260" "P3"      \/*B0*/
    "\261" "FCF"     \/*B1*/
    "\266" "FST"     \/*B6*/
    "\267" "IP0H"    \/*B7*/
    "\270" "IP"      \/*B8*/
    "\271" "SADEN"   \/*B9*/
    "\300" "WDTC"    \/*C0*/
    "\310" "T2CON"   \/*C8*/
    "\311" "T2MOD"   \/*C9*/
    "\312" "RCAP2L"  \/*CA*/
    "\313" "RCAP2H"  \/*CB*/
    "\314" "TL2"     \/*CC*/
    "\315" "TH2"     \/*CD*/
    "\320" "PSW"     \/*D0*/
    "\325" "SPCR"    \/*D5*/
    "\325" "SPCTL"   \/*D5 (This name appears also in the datasheet)*/
    "\330" "CCON"    \/*D8*/
    "\331" "CMOD"    \/*D9*/
    "\332" "CCAPM0"  \/*DA*/
    "\333" "CCAPM1"  \/*DB*/
    "\334" "CCAPM2"  \/*DC*/
    "\335" "CCAPM3"  \/*DD*/
    "\336" "CCAPM4"  \/*DE*/
    "\340" "ACC"     \/*E0*/
    "\340" "A"       \/*E0 for dissasembly "ACC" will be used instead */
    "\350" "IEN1"    \/*E8*/
    "\351" "CL"      \/*E9*/
    "\352" "CCAP0L"  \/*EA*/
    "\353" "CCAP1L"  \/*EB*/
    "\354" "CCAP2L"  \/*EC*/
    "\355" "CCAP3L"  \/*ED*/
    "\356" "CCAP4L"  \/*EE*/
    "\360" "B"       \/*F0*/
    "\367" "IP1H"    \/*F7*/
    "\370" "IP1"     \/*F8*/
    "\371" "CH"      \/*F9*/
    "\372" "CCAP0H"  \/*FA*/
    "\373" "CCAP1H"  \/*FB*/
    "\374" "CCAP2H"  \/*FC*/
    "\375" "CCAP3H"  \/*FD*/
    "\376" "CCAP4H"  \/*FE*/
    "\377" "\000" /*The end of the list*/
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
    "\235" "SM2"     \/*9D*/ 
    "\236" "SM1"     \/*9E*/ 
    "\237" "SM0"     \/*9F*/ 
    "\250" "EX0"     \/*A8*/ 
    "\251" "ET0"     \/*A9*/ 
    "\252" "EX1"     \/*AA*/ 
    "\253" "ET1"     \/*AB*/ 
    "\254" "ES"      \/*AC*/ 
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
    "\255" "ET2"     \/*AD*/ 
    "\337" "CF"      \/*DF*/ 
    "\336" "CR"      \/*DE*/ 
    "\334" "CCF4"    \/*DC*/ 
    "\333" "CCF3"    \/*DB*/ 
    "\332" "CCF2"    \/*DA*/ 
    "\331" "CCF1"    \/*D9*/ 
    "\330" "CCF0"    \/*D8*/ 
    "\256" "EC"      \/*AE*/ 
    "\353" "EBO"     \/*EB*/ 
    "\276" "PPC"     \/*BE*/ 
    "\373" "PBO"     \/*FB*/
    "\377" "\000"/*The end of the list*/
};

void main (void)
{
	_asm
		ljmp _do_cmd
	_endasm; //All the work is done in cmon51.c
}

unsigned char _sdcc_external_startup(void)
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

//Write a byte in to the flash using the IAP routines of the p89v51rd2.
void FlashByte (unsigned int address, unsigned char value)
{
	if(address>=MONITOR_LOC) return; //Protect the monitor
	FCF=0; //Flash routines are in block 0
	_asm
		mov R1, #0x02
		;DPH contains the high part of the sector
		;DPL contains the low part of the sector
		mov	a,_FlashByte_PARM_2
		lcall 0x1ff0
	_endasm;
	FCF=BSEL; //Go back to block 1
	//get rid of sdcc warnings
	value; 
}

//Erase one flash sector of 128 bytes using the IAP routines of the p89v51rd2.  Take care
//not to erase the last 64 sectors where the monitor resides.  Also, after erasing
//sector 0, the jumps to the monitor locations are restored.
void erasesector (unsigned int address)
{
	if(address<MONITOR_LOC)
	{
		FCF=0; //Flash routines are in block 0
		_asm
			mov R1, #0x08
			;DPH contains the high part of the sector
			;DPL contains the low part of the sector
			lcall 0x1ff0 ;Entry point
		_endasm;
		FCF=BSEL; //Go back to block 1
	}
	if(address<0x0080)
	{
		//Restore power on reset
		FlashByte(0x0000, 0x02);
		FlashByte(0x0001, MONITOR_LOC/0x100);
		FlashByte(0x0002, 0x00);
		//Restore timer 1 interrupt vector to point to the service interrupt for
		//the step function located at address MONITOR_LOC+3
		FlashByte(0x001b, 0x02);
		FlashByte(0x001c, MONITOR_LOC/0x100);
		FlashByte(0x001d, 0x03);
	}
}

void loadintelhex (void)
{
	unsigned int j, address;
	unsigned char size, type, check, n;
	code unsigned char * ptr;
	bit errorbit, errorprog, wroteat1b;

	saved_jmp[0]=0;        	
	saved_int[0]=0;        	

	putsp("Erasing");
	for(j=0; j<MONITOR_LOC; j+=0x80)
	{
		if((j%0x800)==0) putc('.');
		erasesector(j);
	}
	putsp("\nSend file or <Esc>\n");
	
	errorbit=0;
	errorprog=0;
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
			
			for(j=address+size; address<j; address++)
			{
				n=getbytene();
				check+=n;
				if(type==0x00)
				{
					if((address>2) && ((address<0x1b)||(address>0x1d)))
					{
						FlashByte(address, n);
						ptr=(unsigned char code *)address;
						if(*ptr!=n) errorprog=1;
					}
					else
					{
						if (address<0x3)
						{
							saved_jmp[address]=n;
						}
						else //If is not a jump, it will trigger a warning
						{
							saved_int[address-0x1b]=n;
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
			else putc('.');
		}
	}

	if(errorbit) putsp("\nChecksum error!\n");
	else if (errorprog) putsp("\nFlash error!\n");
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
}

unsigned char read_sfr (unsigned char x)
{
	unsigned char d;
	
    erasesector(MONITOR_LOC-0x100);
    for(d=0; d<8; d++) FlashByte((MONITOR_LOC-0x100)+d, code_sfr[d]);
	//Write the address of the sfr into the flash
	FlashByte((MONITOR_LOC-0x100)+2, x);
	FlashByte((MONITOR_LOC-0x100)+5, x);

	_asm
		ljmp (MONITOR_LOC-0x100)+04
	_endasm;
	
	return 0;
}

//For this function to work, a call to read_sfr must precede it
void write_sfr (unsigned char val)
{
	_asm
		ljmp (MONITOR_LOC-0x100)
	_endasm;
	val; //To prevent a sdcc warning. Optimized out by sdcc.
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
        orl		_IP0H, #0x80	; Highest priority for timer 1 interrupt
        ret
    _endasm;
}

//Leave this code at the end of the file, or the absolute area will force the whole code
//generated for this file to be at area JUMPCSEG at the begining of the code memory.
void JumpToMonitor (void) _naked
{
    _asm

    cseg at 0x0000    ; Where the monitor is
    ljmp MONITOR_LOC
    
    cseg at 0x001B    ; Timer 1 interrupt vector used for step by step execution.
    ljmp MONITOR_LOC + 0x0003

    cseg at MONITOR_LOC - 2
    db 0x00, 0x00 ; Here the user PC will be saved.  Default it to zero.
    _endasm;
}

