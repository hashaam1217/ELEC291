/*
    timers.c: timer functions

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

void do_timer_0_1 (void)
{
	if( ((TCON&0x10)==0x10) && ((TMOD&0x04)==0) ) // If TR0 is 1 and setup as timer
	{
		if((TMOD&0x03)==0x00) // Timer 0 in mode 0
		{
			TL0++;
			if(TL0&0xe0) // 5-bit overflow?
			{
				TL0=0x00;
				TH0++;
				if(TH0==0x00) // Overflow?
				{
					TCON|=0x20;
				}
			}
		}
		else if((TMOD&0x03)==0x01) // Timer 0 in mode 1
		{
			TL0++;
			if(TL0==0)
			{
				TH0++;
				if(TH0==0x00) // Overflow?
				{
					TCON|=0x20;
				}
			}
		}
		else if((TMOD&0x03)==0x02) // Timer 0 in mode 2
		{
			TL0++;
			if(TL0==0x00) // Overflow?
			{
				TCON|=0x20;
				TL0=TH0;
			}
		}
		else if((TMOD&0x03)==0x03) // Timer 0 in mode 3
		{
			TL0++;
			if(TL0==0x00) TCON|=0x20; // Set TF0 to 1
			if ((TCON&0x40)==0x40) // If TR1 is 1
			{
				TH0++;
				if(TH0==0x00) TCON|=0x80; // Set TF1 to 1
			}
		}
	}

	if( ((TCON&0x40)==0x40) && ((TMOD&0x40)==0) ) // If TR1 is 1 and setup as timer
	{
		if((TMOD&0x30)==0x03) // Timer 1 in mode 0
		{
			TL1++;
			if(TL1&0xe0) // 5-bit overflow?
			{
				TL1=0x00;
				TH1++;
				if(TH1==0) // Overflow?
				{
					if((TMOD&0x03)!=0x03) TCON|=0x80; // Set TF1 only if timer 0 is not in mode 3
				}
			}
		}
		else if((TMOD&0x30)==0x10) // Timer 1 in mode 1
		{
			TL1++;
			if(TL1==0x00)
			{
				TH1++;
				if(TH1==0x00) // Overflow?
				{
					if((TMOD&0x03)!=0x03) TCON|=0x80; // Set TF1 only if timer 0 is not in mode 3
				}
			}
		}
		else if((TMOD&0x30)==0x20) // Timer 1 in mode 2
		{
			TL1++;
			if(TL1==0x00) // Overflow?
			{
				if((TMOD&0x03)!=0x03) TCON|=0x80;  // Set TF1 only if timer 0 is not in mode 3
				TL1=TH1;
			}
		}
		else if((TMOD&0x30)==0x30) // Timer 1 in mode 3 is disabled
		{
		}
	}
}

void do_timer_2 (void)
{
	if( ((T2CON&0x04)==0x40) && ((T2CON&0x02)==0) ) // If TR2 is 1 and setup as timer
	{
		TL2++;
		if(TL2==0)
		{
			TH2++;
			if(TH2==0)
			{
				T2CON|=0x80; // Set overflow flag
				if ( ( ((T2CON&0x01)==0) && ((T2CON&0x08)==0) ) ||  (T2CON&0x10) || (T2CON&0x20) )// Autoreload?
				{
					TH2=RCAP2H;
					TL2=RCAP2L;
				}
				else // Capture mode?  Pending...
				{
				}
			}
		}
	}
}

