/*
    interrupts.c: interrupt processing functions

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
#include "s51.h"

unsigned char int_level[5]={0,0,0,0,0};
unsigned char int_level_cur=0;

int check_interrupts (void)
{
	#define NUMINT 6
	unsigned char priority[NUMINT]; // Used to compute the actual priority of an interrupt
	int j;

	if((IE&0x80)==0) return 0; // Interrupts globally disabled?  Nothing to do here!
	if((IE&0x3f)==0) return 0; // Interrupts individually disabled?  Nothing to do here!

	/*
	External 0	IE0 	0003h Highest priority
	Timer 0 	TF0 	000Bh
	External 1	IE1 	0013h
	Timer 1 	TF1 	001Bh
	Serial 		RI/TI	0023h
	Timer 2 	TF2 	002Bh Lowest default priority
	
	IE SFR (A8h)
	Bit	Name	Bit Function
	7	EA		AFh	Global Interrupt Enable/Disable
	6	-		AEh	Undefined
	5	ET2		ADh	Enable Timer 2 Interrupt
	4	ES		ACh	Enable Serial Interrupt
	3	ET1		ABh	Enable Timer 1 Interrupt
	2	EX1		AAh	Enable External 1 Interrupt
	1	ET0		A9h	Enable Timer 0 Interrupt
	0	EX0		A8h	Enable External 0 Interrupt
	
	IPL SFR (B8h) and IPH SFR (B7H)
	Bit	Name	Bit Function
	7	-		-	Undefined
	6	-		-	Undefined
	5	PT2		BDh	Timer 2 Interrupt Priority
	4	PS		BCh	Serial Interrupt Priority
	3	PT1		BBh	Timer 1 Interrupt Priority
	2	PX1		BAh	External 1 Interrupt Priority
	1	PT0		B9h	Timer 0 Interrupt Priority
	0	PX0		B8h	External 0 Interrupt Priority
	*/
	
	// Compute the priority of each interrupt
	for(j=0; j<NUMINT; j++)
	{
		priority[j]=0;
		
		if(IPH&(0x01<<j)) priority[j]|=0x02;
		if(IPL&(0x01<<j)) priority[j]|=0x01;

		priority[j]++; // Make it from 1 to 4 instead of 0 to 3. Zero means no interrupt pending.
	}

	for(j=4; j>int_level[int_level_cur]; j--) // Check from high priority down to low priority
	{
		if( (TCON&0x02) && (IE&0x01) && (j==priority[0]) ) // IE0 is bit 2 of TCON
		{
			TCON&=(~0x02);
			int_level[++int_level_cur]=priority[0];
			Data[++SP] = PC%0x100;
			Data[++SP] = PC/0x100;
			PC=0x0003;
			return 1;
		}
		else if ( (TCON&0x20) && (IE&0x02) && (j==priority[1]) ) // TF0 is bit 6 of TCON
		{
			TCON&=(~0x20);
			int_level[++int_level_cur]=priority[1];
			Data[++SP] = PC%0x100;
			Data[++SP] = PC/0x100;
			PC=0x000b;
			return 1;
		}
		else if ( (TCON&0x08) && (IE&0x04) && (j==priority[2]) ) // IE1 is bit 4 of TCON
		{
			TCON&=(~0x08);
			int_level[++int_level_cur]=priority[2];
			Data[++SP] = PC%0x100;
			Data[++SP] = PC/0x100;
			PC=0x0013;
			return 1;
		}
		else if ( (TCON&0x80) && (IE&0x08) && (j==priority[3]) ) // TF1 is bit 8 of TCON
		{
			TCON&=(~0x80);
			int_level[++int_level_cur]=priority[3];
			Data[++SP] = PC%0x100;
			Data[++SP] = PC/0x100;
			PC=0x001b;
			return 1;
		}
		else if ( ((SCON&0x01) || (SCON&0x02)) && (IE&0x10) && (j==priority[4]) ) // RI and TI
		{
			int_level[++int_level_cur]=priority[4];
			Data[++SP] = PC%0x100;
			Data[++SP] = PC/0x100;
			PC=0x0023;
			return 1;
		}
		else if ( (T2CON&0x80) && (IE&0x20) && (j==priority[5]) ) // TF2
		{
			int_level[++int_level_cur]=priority[5];
			Data[++SP] = PC%0x100;
			Data[++SP] = PC/0x100;
			PC=0x002b;
			return 1;
		}
	}

	return 0;
}