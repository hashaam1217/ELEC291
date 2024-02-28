/*
    s51.h: function prototypes and other definitions

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
void do_nop (void);
void do_ajmp (void);
void do_ljmp (void);
void do_rr (void);
void do_inc_dec (void);
void do_jbc (void);
void do_acall (void);
void do_lcall (void);
void do_inc_dec (void);
void do_jbc (void);
void do_rrc (void);
void do_jb (void);
void do_ret (void);
void do_rl (void);
void do_add (void);
void do_jnb (void);
void do_reti (void);
void do_rlc (void);
void do_jc (void);
void do_orl (void);
void do_jnc (void);
void do_anl (void);
void do_jz (void);
void do_xrl (void);
void do_jnz (void);
void do_orlc (void);
void do_jmpdptr (void);
void do_mov (void);
void do_sjmp (void);
void do_anlc (void);
void do_divab (void);
void do_subb (void);
void do_incdptr (void);
void do_mulab (void);
void do_ilegal (void);
void do_cpl (void);
void do_cjne (void);
void do_push (void);
void do_clr (void);
void do_swapa (void);
void do_xch (void);
void do_pop (void);
void do_setb (void);
void do_daa (void);
void do_xchd (void);
void do_movx (void);
void do_movc (void);
void do_cpla (void);
void do_djnz (void);
void do_clra (void);
void do_setbcy (void);
void do_clrcy (void);
void do_cplcy (void);
void do_movcy (void);

struct _op {
 char *mnemonic;
 unsigned char nbytes;
 unsigned char cycles;
 void (*do_ptr)(void);
};

#define ACC  Sfr[0xe0]
#define B    Sfr[0xf0]
#define DPH  Sfr[0x83]
#define DPL  Sfr[0x82]
#define SP   Sfr[0x81]
#define P0   Sfr[0x80]
#define P1   Sfr[0x90]
#define P2   Sfr[0xa0]
#define P3   Sfr[0xb0]
#define PSW  Sfr[0xd0]
#define SCON Sfr[0x98]
#define SBUF Sfr[0x99]
#define TMOD Sfr[0x89]
#define TCON Sfr[0x88]
#define TL0  Sfr[0x8a]
#define TL1  Sfr[0x8b]
#define TH0  Sfr[0x8c]
#define TH1  Sfr[0x8d]
#define IE   Sfr[0xa8]
#define IPH  Sfr[0xb9]
#define IPL  Sfr[0xb8]
#define T2CON  Sfr[0xc8]
#define T2MOD  Sfr[0xc9]
#define TH2    Sfr[0xcd]
#define TL2    Sfr[0xcc]
#define RCAP2H Sfr[0xcb]
#define RCAP2L Sfr[0xca]

#ifndef NOEXTERNALS
extern unsigned char Code[0x10000];
extern unsigned char Breaks[0x10000/8];
extern unsigned char Xdata[0x10000];
extern unsigned char Data[0x100];
extern unsigned char Sfr[0x100];
extern unsigned short int PC;
extern unsigned char opcode;
extern struct _op op[0x100];
extern unsigned char * sfrn[0x80];
extern unsigned char * bitn[0x80];
#endif

int ReadHexFile(char * filename, unsigned char * Code);
int disassemble (unsigned char * code_memory, int address, int endaddress);

