/*
    opcodes.c: mcs51 opcode implementation

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
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include "s51.h"

/* The interrupt system generates an LCALL to the appropriate
service routine, provided that the instruction in progress
is not a RETI or any write to the IE or IP registers. 
The ensures that at least one more instruction is executed
before any interrupt is vectored to.*/
unsigned char interrupt_stall=0;
int sjmp_intself=0;

extern int connected;
void send_telnet(char * buff, int size);
extern FILE * sof;

extern unsigned char int_level[5];
extern unsigned char int_level_cur;

extern unsigned int overlap_start;
extern unsigned int overlap_end;

/////////////////////////////////////////////////////////////////////////////////////
//
// Utility functions used by opcode routines
//
/////////////////////////////////////////////////////////////////////////////////////

void relative (unsigned char val)
{
	PC+=(signed char)val;
}

void set_bit_to (unsigned char Addr, unsigned char val)
{
	unsigned char Byte, Mask;
	unsigned char * MemSpace;

	Mask=(1<<(Addr&0x07));
	
	if(Addr<0x80)  // For data bits
	{
		Byte=(Addr/8)+0x20;
		MemSpace=Data;
	}
	else // For SFR bits
	{
		Byte=Addr&0xF8;
		MemSpace=Sfr;

		// If writting to IE or IPL then stall interrupts
		if ( ((Addr&0xf8)==0xa8) || ((Addr&0xf8)==0xb8)  )
		{
			interrupt_stall=1;
		}
	}

	if(val)
	{ 
		MemSpace[Byte]|=Mask; // Set the bit
    }
    else
    {
		MemSpace[Byte]&=(~Mask); // Clear the bit
    }
}

unsigned char get_bit (unsigned char Addr)
{
	unsigned char Byte, Mask;
	unsigned char * MemSpace;

	Mask=(1<<(Addr&0x07));
	
	if(Addr<0x80)  // For data bits
	{
		Byte=(Addr/8)+0x20;
		MemSpace=Data;
	}
	else // For SFR bits
	{
		Byte=Addr&0xF8;
		MemSpace=Sfr;
	}

	return (MemSpace[Byte]&Mask)?1:0;
}

void update_parity (void)
{
	if ( ((ACC&0x80)?1:0) ^ ((ACC&0x40)?1:0) ^ ((ACC&0x20)?1:0) ^ ((ACC&0x10)?1:0) ^
		 ((ACC&0x08)?1:0) ^ ((ACC&0x04)?1:0) ^ ((ACC&0x02)?1:0) ^ ((ACC&0x01)?1:0) )
		PSW|=0x01;
	else
		PSW&=0xfe;
}

void set_direct_to (unsigned char Addr, unsigned char val)
{
	unsigned char tx_buf[10];

	// If writting to IE, IPL, or IPH, stall interrupts
	if ( (Addr==0xa8) || (Addr==0xb8) || (Addr==0xb9) )
	{
		interrupt_stall=1;
	}

	if(Addr==0x99) // SBUF
	{
		if(sof!=NULL)
		{
			fprintf(sof, "%c", val);
		}
		else if(connected)
		{
			tx_buf[0]=val; tx_buf[1]=0;
			send_telnet(tx_buf,1);
		}
		SCON|=0x02; // Set TI bit in SFR SCON		
	}
	else
	{
		if(Addr<0x80)
			Data[Addr]=val;
		else
			Sfr[Addr]=val;
	}
}

unsigned char get_direct (unsigned char Addr)
{
	if(Addr<0x80)
		return Data[Addr];
	else
		return Sfr[Addr];
}

unsigned char get_code (unsigned int Addr)
{
	return(Code[Addr & 0xffff]);
}

unsigned char get_xdata (unsigned int Addr)
{
	if( (Addr>=overlap_start) && (Addr<=overlap_end) )
		return(Code[Addr & 0xffff]);
	else
		return(Xdata[Addr & 0xffff]);
}

void set_xdata_to (unsigned int Addr, unsigned char Val)
{
	if( (Addr>=overlap_start) && (Addr<=overlap_end) )
		Code[Addr & 0xffff]=Val;
	else
		Xdata[Addr & 0xffff]=Val;
}

void invalid (char * fname)
{
	printf("Invalid opcode (0x%04x=0x%02x) detected in %s()\n", PC, opcode, fname);
}

/////////////////////////////////////////////////////////////////////////////////////
//
// Instruction decoding routines
//
/////////////////////////////////////////////////////////////////////////////////////

void do_nop(void)
{
	PC++;
}

void do_ajmp(void)
{
	PC=((opcode>>5)*0x100+get_code(PC+1))|((PC+2)&0xF800);
}

void do_sjmp(void)
{
	unsigned char disp;
	
	disp=get_code(PC+1);
	if( (disp==0xfe) && ( ((IE&0x80)==0) || ((IE&0x7f)==0) ) )
	{
		// sjmp $ with interrupts disable detected, may stop simulation
		sjmp_intself=1;
		//printf("do_sjmp trap!\n");
		//disassemble (Code, PC, PC+1);
	}
	PC+=2;
	relative(disp);
}

void do_ljmp(void)
{
	PC=get_code(PC+1)*0x100+get_code(PC+2);
}

void do_jmpdptr(void)
{
	PC=ACC+(DPH*0x100+DPL);
}

void do_rr(void)
{
	unsigned char b0;
	b0=(ACC&0x01)?1:0;
	ACC>>=1;
	if(b0)
		ACC|=0x80;
	else
		ACC&=0x7f;
	PC++;
}

void do_rl(void)
{
	unsigned char b7;
	b7=(ACC&0x80)?1:0;
	ACC<<=1;
	if(b7)
		ACC|=0x01;
	else
		ACC&=0xfe;
	PC++;
}

void do_inc_dec(void)
{
    unsigned char rbank, off;
    
	rbank=(PSW>>3)&0x3;

	if(opcode==0x04 || opcode==0x14) // INC A ; DEC A
	{
		ACC+=(opcode==0x04)?1:-1;
		PC+=1;
	}
	else if(opcode==0x05 || opcode==0x15) // INC Direct ; DEC Direct
	{
		set_direct_to(get_code(PC+1), (unsigned char)
		(get_direct(get_code(PC+1)) + ((opcode==0x05)?1:-1)) );
		PC+=2;
	}
	else if(opcode==0x06 || opcode==0x16 || opcode==0x07 || opcode==0x17) // INC @R0, DEC @R0, INC @R1, DEC @R1
	{
		off=opcode&0x01;
		Data[Data[(rbank*8)+off]]+=(opcode<0x16)?1:-1;
		PC+=1;
	}
	else if((opcode>=0x08 && opcode<=0x0f) || (opcode>=0x18 && opcode<=0x1f)) // INC Rn and DEC Rn
	{
		off=opcode&0x07;
		Data[(rbank*8)+off]+=(opcode<0x18)?1:-1;
		PC+=1;
	}
	else
	{
		invalid("do_inc_dec");
		PC+=1;
	}
}

void do_jbc (void)
{
	unsigned char Addr, Disp;

	Disp=get_code(PC+2);
	Addr=get_code(PC+1);

	PC+=3;
	if(get_bit(Addr)==1)
	{
		set_bit_to(Addr, 0); // Clear the bit
		relative(Disp); // Now Jump
	}
}

void do_jb (void)
{
	unsigned char Addr, Disp;

	Disp=get_code(PC+2);
	Addr=get_code(PC+1);

	PC+=3;
	if(get_bit(Addr)==1)
	{
		relative(Disp); // Jump
	}
}

void do_jnb (void)
{
	unsigned char Addr, Disp;
	
	Disp=get_code(PC+2);
	Addr=get_code(PC+1);

	PC+=3;
	if(get_bit(Addr)==0)
	{
		relative(Disp); // Jump
	}
}

void do_setbcy (void)
{
	PSW|=0x80;
	PC++;
}

void do_clrcy (void)
{
	PSW&=0x7f;
	PC++;
}

void do_jc(void)
{
	unsigned char Disp;
	Disp=get_code(PC+1);
	PC+=2;
	if( PSW & 0x80 )
	{ 
		relative(Disp);
    }
}

void do_jnc(void)
{
	unsigned char Disp;
	Disp=get_code(PC+1);
	PC+=2;
	if( (PSW & 0x80 ) == 0 )
	{ 
		relative(Disp);
    }
}

void do_jz(void)
{
	unsigned char Disp;
	Disp=get_code(PC+1);
	PC+=2;
	if( ACC==0x00 )
	{ 
		relative(Disp);
    }
}

void do_jnz(void)
{
	unsigned char disp;
	disp=get_code(PC+1);
	PC+=2;
	if( ACC!=0x00 )
	{ 
		relative(disp);
    }
}

void do_acall(void)
{
	// Save the return address into the stack
	Data[++SP]=(PC+2)%0x100;
	Data[++SP]=(PC+2)/0x100;
	PC=((opcode>>5)*0x100+get_code(PC+1))|((PC+2)&0xF800);
}

void do_lcall(void)
{
	// Save the return address into the stack
	Data[++SP]=(PC+3)%0x100;
	Data[++SP]=(PC+3)/0x100;
	PC=(get_code(PC+1)*0x100)+get_code(PC+2);
}

void do_rrc(void)
{
    unsigned char b0;
    b0=(ACC&0x01)?1:0;
    ACC>>=1;
    if(PSW&0x80)
		ACC|=0x80;
	else
		ACC&=0x7f;

    if(b0)
       PSW|=0x80;
    else
       PSW&=0x7f;
	PC++;
}

void do_rlc(void)
{
    unsigned char b7;
    b7=(ACC&0x80)?1:0;
    ACC<<=1;
    if(PSW&0x80)
		ACC|=0x01;
	else
		ACC&=0xfe;

    if(b7)
       PSW|=0x80;
    else
       PSW&=0x7f;
	PC++;
}

void do_ret (void)
{
   unsigned char PCL, PCH;
   PCH=Data[SP--];
   PCL=Data[SP--];
   PC=PCH*0x100+PCL;
}

void do_incdptr (void)
{
	DPL++;
	if(DPL==0) DPH++;
	PC++;
}

void do_mulab (void)
{
	unsigned int result;
   
	result = ACC * B;
	ACC = (result % 0x100 );
	B = (result / 0x100);
	
	if(B>0)
		PSW |= 0x04; // set OV flag
	else
		PSW &= 0xfb; // reset OV flag...
	
	PSW &= 0x7f;    // CY=0 always
	
	PC++;
}

void do_divab (void)
{
	unsigned char num, den;
	
	num = ACC;
	den = B;

	if(B!=0)
	{
		ACC = num / den;
		B = num % den;
		PSW &= 0xfb ; // OV flag=0
	}
	else
		PSW |= 0x04; // OV flag=1

	PSW &= 0x7f; // CY=0 always
	
	PC++;
}

void do_add_common ( unsigned char x, unsigned char y, unsigned char cy)
{
	unsigned int lacc, lacc2, lacc3;
	
	lacc=x+y+(cy&0x1);
	lacc2=(x&0x7f)+(y&0x7f)+(cy&0x1);
	lacc3=(x&0x0f)+(y&0x0f)+(cy&0x1);

	ACC=lacc%0x100; // The accumulator can hold only 8 bits
	
	if(lacc>0xff) // Set the Carry flag
		PSW|=0x80;
	else
		PSW&=0x7f;
	
	if(lacc3>0xf) // Set the Half Carry Flag
		PSW|=0x40;
	else
		PSW&=0xbf;

	if( ((lacc>0xff)?1:0) ^ ((lacc2>0x7f)?1:0) ) // Set the OV Flag
		PSW|=0x04;
	else
		PSW&=0xfb;
}

void do_add(void)
{
    unsigned char rbank, CYin, off;
    
	rbank=(PSW>>3)&0x3;

	if((opcode>=0x34) && (opcode<=0x3f) ) // All the ADDC instructions
	   CYin=(PSW & 0x80)?1:0;
	else
	   CYin=0;

	if(opcode==0x24 || opcode==0x34) // "ADD A, #" and "ADDC A, #"
	{
		do_add_common(ACC, get_code(PC+1), CYin);
		PC+=2;
	}
    else if(opcode==0x25 || opcode==0x35) // "ADD A, direct" and "ADDC A, direct"
	{
		do_add_common(ACC, get_direct(get_code(PC+1)), CYin);
		PC+=2;
	}
    else if(opcode==0x26 || opcode==0x36 || opcode==0x27 || opcode==0x37) // "ADD A, @Ri" and "ADDC A, @Ri"
	{
		off=opcode&0x01;
		do_add_common(ACC, Data[Data[(rbank*8)+off]], CYin);
		PC+=1;
	}
	else if ( ((opcode>=0x28) && (opcode<=0x2f)) || // "ADD A, Rn" and "ADDC A, Rn"
			  ((opcode>=0x38) && (opcode<=0x3f)) )
	{
		off=opcode&0x07;
		do_add_common(ACC, Data[(rbank*8)+off], CYin);
		PC+=1;
	}
	else
	{
		invalid("do_add");
		PC+=1;
	}
}

void do_subb_common ( unsigned char x, unsigned char y, unsigned char cy)
{
	unsigned int lacc, lacc2, lacc3;
	
	lacc=x-y-(cy&0x1);
	lacc2=(x&0x7f)-(y&0x7f)-(cy&0x1);
	lacc3=(x&0x0f)-(y&0x0f)-(cy&0x1);
	
	ACC=lacc%0x100; // The accumulator can hold only 8 bits
	
	if(lacc>0xff) // Set the Carry flag
		PSW|=0x80;
	else
		PSW&=0x7f;
	
	if(lacc3>0xf) // Set the Half Carry Flag
		PSW|=0x40;
	else
		PSW&=0xbf;

	if( ((lacc>0xff)?1:0) ^ ((lacc2>0x7f)?1:0) ) // Set the OV Flag
		PSW|=0x04;
	else
		PSW&=0xfb;
}

void do_subb(void)
{
    unsigned char rbank, CYin, off;
    
	rbank=(PSW>>3)&0x3;
	CYin=(PSW & 0x80)?1:0;

	if(opcode==0x94) //"SUBB A, #"
	{
		do_subb_common(ACC, get_code(PC+1), CYin);
		PC+=2;
	}
    else if(opcode==0x95) //"SUBB A, direct"
	{
		do_subb_common(ACC, get_direct(get_code(PC+1)), CYin);
		PC+=2;
	}
    else if( (opcode==0x96) || (opcode==0x97) )// "SUBB A, @Ri"
	{
		off=opcode&0x1;
		do_subb_common(ACC, Data[Data[(rbank*8)+off]], CYin);
		PC+=1;
	}
	else if( (opcode>=0x98) && (opcode<=0x9f) ) // "SUBB A, Rn"
	{
		off=opcode&0x7;
		do_subb_common(ACC, Data[(rbank*8)+off], CYin);
		PC+=1;
	}
	else
	{
		invalid("do_subb");
		PC+=1;
	}
}

void do_daa(void)
{
	int tACC;
	
	tACC=ACC;
	
	if( ((tACC & 0x0f)>0x09) || ( PSW & 0x40) )
	tACC = tACC + 0x06;
	
	if(tACC&0x100) PSW|=0x80;
	tACC = tACC%0x100;
	
	if( ((tACC & 0xf0)>0x90) || ( PSW & 0x80) )
	tACC = tACC + 0x60;

	if(tACC&0x100) PSW|=0x80;
	ACC = tACC%0x100;
	
	PC+=1;
}

void do_cpla(void)
{
	ACC=~ACC;
	PC+=1;
}

void do_clra(void)
{
	ACC=0;
	PC+=1;
}

void do_swapa(void)
{
	unsigned char hi, lo;
	hi=ACC/0x10;
	lo=ACC%0x10;
	ACC=lo*0x10+hi;
	PC+=1;
}

void do_clr(void)
{
	unsigned char Addr;
	
	Addr=get_code(PC+1);
	set_bit_to(Addr, 0);

	PC+=2;
}

void do_setb(void)
{
	unsigned char Addr;
	
	Addr=get_code(PC+1);
	set_bit_to(Addr, 1);

	PC+=2;
}

void do_cpl(void)
{
	unsigned char Addr;
	
	Addr=get_code(PC+1);
	//printf("Before: Bit %d=%d\n", Addr, get_bit(Addr));
	set_bit_to(Addr, (unsigned char) (get_bit(Addr)?0:1) );
	//printf("After:  Bit %d=%d\n", Addr, get_bit(Addr));

	PC+=2;
}

void do_cplcy(void)
{
	if(PSW&0x80)
		PSW&=0x7f;
	else
		PSW|=0x80;
	PC+=1;
}

void do_anlc(void)
{
	unsigned char Addr;
	unsigned char myCY, myBit, myResult;
	
	Addr=get_code(PC+1);
	
	myCY=(PSW&0x80)?1:0;
	
	if(opcode==0x82) // "ANL C, bit"
		myBit=get_bit(Addr)?1:0;
	else // "ANL C, /bit"
		myBit=get_bit(Addr)?0:1;
	
	myResult=myCY & myBit;
	
	if(myResult)
		PSW|=0x80;
	else
		PSW&=0x7f;

	PC+=2;
}

void do_orlc(void)
{
	unsigned char Addr;
	unsigned char myCY, myBit, myResult;
	
	Addr=get_code(PC+1);
	
	myCY=(PSW&0x80)?1:0;
	
	if(opcode==0x72) // "ORL C, bit"
		myBit=get_bit(Addr)?1:0;
	else // "ORL C, /bit"
		myBit=get_bit(Addr)?0:1;
	
	myResult=myCY | myBit;
	
	if(myResult)
		PSW|=0x80;
	else
		PSW&=0x7f;

	PC+=2;
}

void do_xch(void)
{
	unsigned char tACC, rbank, off;
	
	rbank=(PSW>>3)&0x3;
	tACC=ACC;
			
	if(opcode==0xc5) // XCH A, direct
	{
		ACC=get_direct(get_code(PC+1));
		set_direct_to(get_code(PC+1), tACC);
		PC+=2;
	}
	else if( (opcode==0xc6) || (opcode==0xc7) ) // XCH A, @R0 and  XCH A, @R1
	{
		off=opcode&0x01;
		ACC=Data[Data[(rbank*8)+off]];
		Data[Data[(rbank*8)+off]]=tACC;
		PC+=1;
	}
	else if( (opcode>=0xc8) && (opcode<=0xcf) ) // XCH A, Rn
	{
		off=opcode&0x07;
		ACC=Data[(rbank*8)+off];
		Data[(rbank*8)+off]=tACC;
		PC+=1;
	}
	else
	{
		invalid("do_xch");
		PC+=1;
	}
}

void do_xchd(void)
{
	unsigned char tACC, rbank, off;

	rbank=(PSW>>3)&0x3;
	tACC=ACC;
	off=Data[(rbank*8)+(opcode&0x01)];

	ACC = (ACC&0xf0) | (Data[off]&0x0f) ;
	Data[off] = (Data[off]&0xf0) | (tACC&0x0f) ;
	
	PC+=1;
}

void do_push(void)
{
	Data[++SP] = get_direct(get_code(PC+1));
	PC+=2;
}

void do_pop(void)
{
	set_direct_to(get_code(PC+1), Data[SP--]);
	PC+=2;
}

void do_djnz(void)
{
	unsigned char rbank, off, tval, Addr_j, Addr_d;

	rbank=(PSW>>3)&0x3;
	off=opcode&0x07;
	
	if ( opcode==0xd5 ) // "DJNZ direct
	{
		Addr_d=get_code(PC+1);
		Addr_j=get_code(PC+2);
		PC+=3;
		tval=get_direct(Addr_d);
		tval--;
		set_direct_to(Addr_d, tval);
		if(tval)
		{
			relative(Addr_j);
		}
	}
	else if ( (opcode>=0xd8) && (opcode<=0xdf) ) // "DJNZ Rn, addr"
    {
    	Addr_j=get_code(PC+1);
    	PC+=2;
		Data[(rbank*8)+off]--;
		if(Data[(rbank*8)+off]) // Not zero, then jump
		{
			relative(Addr_j);
		}
	}
	else
	{
		invalid("do_djnz");
		PC+=2;
	}
}

void do_cjne(void)
{
	unsigned char rbank, off, tval1, tval2, Addr;

	rbank=(PSW>>3)&0x3;
	
	if(opcode==0xb4) // "CJNE A, #"
	{
		tval1=ACC;
		tval2=get_code(PC+1);
	}
	else if(opcode==0xb5) // "CJNE A, direct"
    {
		tval1=ACC;
		tval2=get_direct(get_code(PC+1));
    }
	else if( (opcode==0xb6) || (opcode==0xb7) ) // "CJNE @R0, #" and  "CJNE @R1, #"
    {
		off=opcode&0x01;
		tval1=Data[Data[(rbank*8)+off]];
		tval2=get_code(PC+1);
    }
	else if(opcode>=0xb8 && opcode<=0xbf) // "CJNE Rn, #"
	{
		off=opcode&0x07;
		tval1=Data[(rbank*8)+off];
		tval2=get_code(PC+1);
	}
	else
	{
		invalid("do_cjne");
	}
	
	Addr= get_code(PC+2);
	PC+=3;
	
	if(tval1<tval2)
    	PSW |= 0x80;
	else
    	PSW &= 0x7f;
    	
    if(tval1!=tval2)
    {
    	relative(Addr);
    }
}

void do_ilegal(void)
{
	printf("Ilegal opcode detected at address %04x.\n", PC);
	PC+=1;
}

void do_xrl(void)
{
	unsigned char rbank, off, tval, Addr;

	rbank=(PSW>>3)&0x3;
	
	if(opcode==0x62) // XRL direct, A
	{
		Addr=get_code(PC+1);
		tval=ACC ^ get_direct(Addr);
		set_direct_to(Addr, tval);
		PC+=2;
	}
	else if(opcode==0x63) // XRL direct, #data
	{
		Addr=get_code(PC+1);
		tval=get_code(PC+2) ^ get_direct(Addr);
		set_direct_to(Addr, tval);
		PC+=3;
	}
	else if(opcode==0x64) // XRL A, #data
	{
		ACC=ACC ^ get_code(PC+1);
		PC+=2;
	}
	else if(opcode==0x65) // XRL A, direct
	{
		Addr=get_code(PC+1);
		ACC=ACC ^ get_direct(Addr);
		PC+=2;
	}
	else if( (opcode==0x66) || (opcode==0x67) ) // XRL A, @Ri
	{
		off=opcode&0x01;
		ACC=ACC ^ Data[Data[(rbank*8)+off]];
		PC+=1;
	}
	else if(opcode>=0x68 && opcode<=0x6f) // "XRL A, Rn"
	{
		off=opcode&0x07;
		ACC=ACC ^ Data[(rbank*8)+off];
		PC+=1;
	}
	else
	{
		invalid("do_xrl");
		PC+=1;
	}
}

void do_anl(void)
{
	unsigned char rbank, off, tval, Addr;

	rbank=(PSW>>3)&0x3;
	
	if(opcode==0x52) // ANL direct, A
	{
		Addr=get_code(PC+1);
		tval=ACC & get_direct(Addr);
		set_direct_to(Addr, tval);
		PC+=2;
	}
	else if(opcode==0x53) // ANL direct, #data
	{
		Addr=get_code(PC+1);
		tval=get_code(PC+2) & get_direct(Addr);
		set_direct_to(Addr, tval);
		PC+=3;
	}
	else if(opcode==0x54) // ANL A, #data
	{
		ACC=ACC & get_code(PC+1);
		PC+=2;
	}
	else if(opcode==0x55) // ANL A, direct
	{
		Addr=get_code(PC+1);
		ACC=ACC & get_direct(Addr);
		PC+=2;
	}
	else if( (opcode==0x56) || (opcode==0x57) ) // ANL A, @Ri
	{
		off=opcode&0x01;
		ACC=ACC & Data[Data[(rbank*8)+off]];
		PC+=1;
	}
	else if(opcode>=0x58 && opcode<=0x5f) // "ANL A, Rn"
	{
		off=opcode&0x07;
		ACC=ACC & Data[(rbank*8)+off];
		PC+=1;
	}
	else
	{
		invalid("do_anl");
		PC+=1;
	}
}

void do_orl(void)
{
	unsigned char rbank, off, tval, Addr;

	rbank=(PSW>>3)&0x3;
	
	if(opcode==0x42) // ORL direct, A
	{
		Addr=get_code(PC+1);
		tval=ACC | get_direct(Addr);
		set_direct_to(Addr, tval);
		PC+=2;
	}
	else if(opcode==0x43) // ORL direct, #data
	{
		Addr=get_code(PC+1);
		tval=get_code(PC+2) | get_direct(Addr);
		set_direct_to(Addr, tval);
		PC+=3;
	}
	else if(opcode==0x44) // ORL A, #data
	{
		ACC=ACC | get_code(PC+1);
		PC+=2;
	}
	else if(opcode==0x45) // ORL A, direct
	{
		Addr=get_code(PC+1);
		ACC=ACC | get_direct(Addr);
		PC+=2;
	}
	else if( (opcode==0x46) || (opcode==0x47) ) // ORL A, @Ri
	{
		off=opcode&0x01;
		ACC=ACC | Data[Data[(rbank*8)+off]];
		PC+=1;
	}
	else if(opcode>=0x48 && opcode<=0x4f) // "ORL A, Rn"
	{
		off=opcode&0x07;
		ACC=ACC | Data[(rbank*8)+off];
		PC+=1;
	}
	else
	{
		invalid("do_orl");
		PC+=1;
	}
}

void do_movx(void)
{
	unsigned char rbank, off;

	rbank=(PSW>>3)&0x3;
	off=opcode&0x01;
	
	if(opcode==0xe0) // "MOVX A, @DPTR"
	{
		ACC=get_xdata((DPH*0x100)+DPL);
		PC+=1;
	}
	else if( (opcode==0xe2) || (opcode==0xe3) ) // "MOVX A, @Ri"
	{
		ACC=get_xdata((P2*0x100)+Data[(rbank*8)+off]);
		PC+=1;
	}
	else if(opcode==0xf0) // "MOVX @DPTR, A"
	{
		set_xdata_to( (DPH*0x100)+DPL, ACC);
		PC+=1;
	}
	else if( (opcode==0xf2) || (opcode==0xf3) ) // "MOVX @Ri, A"
	{
		set_xdata_to( (P2*0x100)+Data[(rbank*8)+off], ACC);
		PC+=1;
	}
	else
	{
		invalid("do_movx");
		PC+=1;
	}
}

void do_movc(void)
{
	if(opcode==0x83) // "MOVC A, @A+PC"
	{
		PC+=1;
		ACC=get_code(PC+ACC);
	}
	else if(opcode==0x93) // "MOVC A, @A+DPTR"
	{
		ACC=get_code((DPH*0x100)+DPL+ACC);
		PC+=1;
	}
	else
	{
		invalid("do_movc");
		PC+=1;
	}
}

void do_movcy(void)
{
	if(opcode==0x92) // "MOV bit, C"
	{
		set_bit_to(get_code(PC+1), (unsigned char)((PSW&0x80)?1:0) ) ;
		PC+=2;
	}
	else if(opcode==0xa2) // "MOV C, bit"
	{
		if(get_bit(get_code(PC+1))==0)
			PSW&=0x7f;
		else
			PSW|=0x80;
		PC+=2;
	}
	else
	{
		invalid("do_movcy");
		PC+=2;
	}
}

void do_mov(void)
{
	unsigned char rbank, off;

	rbank=(PSW>>3)&0x3;

	if(opcode==0x74) // "MOV A, #"
	{
		ACC=get_code(PC+1);
		PC+=2;
	}
	else if(opcode==0x75) // "MOV direct, #"
	{
		set_direct_to(get_code(PC+1), get_code(PC+2));
		PC+=3;
	}
	else if( (opcode==0x76) || (opcode==0x77) ) // "MOV @Ri, #"
	{
		off=opcode&0x01;
		Data[Data[(rbank*8)+off]]=get_code(PC+1);
		PC+=2;
	}
	else if( (opcode>=0x78) && (opcode<=0x7f) ) // "MOV Rn, #"
	{
		off=opcode&0x07;
		Data[(rbank*8)+off]=get_code(PC+1);
		PC+=2;
	}
	else if (opcode==0x85) // "MOV direct, direct"
	{
		set_direct_to(get_code(PC+2), get_direct(get_code(PC+1)));
		PC+=3;
	}
	else if( (opcode==0x86) || (opcode==0x87) ) // "MOV direct, @Ri"
	{
		off=opcode&0x01;
		set_direct_to( get_code(PC+1), Data[Data[(rbank*8)+off]] );
		PC+=2;
	}
	else if( (opcode>=0x88) && (opcode<=0x8f) ) // "MOV direct, Rn"
	{
		off=opcode&0x07;
		set_direct_to( get_code(PC+1), Data[(rbank*8)+off] );
		PC+=2;
	}
	else if (opcode==0x90) // "MOV DPTR, #"
	{
		DPH=get_code(PC+1);
		DPL=get_code(PC+2);
		PC+=3;
	}
	else if( (opcode==0xa6) || (opcode==0xa7) ) // "MOV @Ri, direct"
	{
		off=opcode&0x01;
		Data[Data[(rbank*8)+off]]=get_direct(get_code(PC+1));
		PC+=2;
	}
	else if( (opcode>=0xa8) && (opcode<=0xaf) ) // "MOV Rn, direct"
	{
		off=opcode&0x07;
		Data[(rbank*8)+off]=get_direct(get_code(PC+1));
		PC+=2;
	}
	else if (opcode==0xe5) // "MOV A, direct"
	{
		ACC=get_direct(get_code(PC+1));
		PC+=2;
	}
	else if( (opcode==0xe6) || (opcode==0xe7) ) // "MOV A, @Ri"
	{
		off=opcode&0x01;
		ACC=Data[Data[(rbank*8)+off]];
		PC+=1;
	}
	else if( (opcode>=0xe8) && (opcode<=0xef) ) // "MOV A, Rn"
	{
		off=opcode&0x07;
		ACC=Data[(rbank*8)+off];
		PC+=1;
	}
	else if (opcode==0xf5) // "MOV direct, A"
	{
		set_direct_to(get_code(PC+1), ACC);
		PC+=2;
	}
	else if( (opcode==0xf6) || (opcode==0xf7) ) // "MOV @Ri, A"
	{
		off=opcode&0x01;
		Data[Data[(rbank*8)+off]]=ACC;
		PC+=1;
	}
	else if( (opcode>=0xf8) && (opcode<=0xff) ) // "MOV Rn, A"
	{
		off=opcode&0x07;
		Data[(rbank*8)+off]=ACC;
		PC+=1;
	}
	else
	{
		invalid("do_mov");
		PC+=1;
	}
}

void do_reti (void)
{
   unsigned char PCL, PCH;
   PCH=Data[SP--];
   PCL=Data[SP--];
   PC=PCH*0x100+PCL;
   // Reset interrupt level
   if(int_level_cur!=0) int_level_cur--;
   // No interrupts allowed inmediatly after a reti
   interrupt_stall=1;
}
