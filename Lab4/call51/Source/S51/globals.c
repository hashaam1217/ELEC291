/*
    globals.c: global variables definitions

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

#define NOEXTERNALS 1
#include "s51.h"

unsigned char Code[0x10000];
unsigned char Breaks[0x10000/8];
unsigned char Xdata[0x10000];
unsigned char Data[0x100];
unsigned char Sfr[0x100];
unsigned short int PC;
unsigned char opcode;

// WARNING: This table uses the following tokens that are expanded
//          during disassembly time:
// TOKEN  ACTION
// &      11 bit paged address
// .      8 bit relative address
// :      16 bit absolute address
// #      eight bit constant (except opcode 0x90 for which is a 16 bit constant)
// !      eight bit address or register name (if found)
// %      eight bit address or bit name (if found)

struct _op op[0x100] = {
 /* 0x00 */ { "nop",  1, 1, do_nop}, /* nop */
 /* 0x01 */ { "ajmp &", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0x02 */ { "ljmp\t:", 3, 2, do_ljmp}, /* ljmp 16bit*/
 /* 0x03 */ { "rr\ta", 1, 1, do_rr},  /* rr a*/
 /* 0x04 */ { "inc\ta", 1, 1, do_inc_dec}, /* inc a*/
 /* 0x05 */ { "inc\t!", 2, 1, do_inc_dec}, /* inc direct*/
 /* 0x06 */ { "inc\t@r0", 1, 1, do_inc_dec}, /* inc @r0*/
 /* 0x07 */ { "inc\t@r1", 1, 1, do_inc_dec}, /* inc @r1*/
 /* 0x08 */ { "inc\tr0", 1, 1, do_inc_dec}, /* inc r0*/
 /* 0x09 */ { "inc\tr1", 1, 1, do_inc_dec}, /* inc r1*/
 /* 0x0A */ { "inc\tr2", 1, 1, do_inc_dec}, /* inc r2*/
 /* 0x0B */ { "inc\tr3", 1, 1, do_inc_dec}, /* inc r3*/
 /* 0x0C */ { "inc\tr4", 1, 1, do_inc_dec}, /* inc r4*/
 /* 0x0D */ { "inc\tr5", 1, 1, do_inc_dec}, /* inc r5*/
 /* 0x0E */ { "inc\tr6", 1, 1, do_inc_dec}, /* inc r6*/
 /* 0x0F */ { "inc\tr7", 1, 1, do_inc_dec}, /* inc r7*/
 /* 0x10 */ { "jbc\t%, .", 3, 2, do_jbc}, /* jbc bit_direct, relative*/
 /* 0x11 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0x12 */ { "lcall\t:", 3, 2, do_lcall}, /* lcall 16bit*/
 /* 0x13 */ { "rrc\ta", 1, 1, do_rrc}, /* rrc a*/
 /* 0x14 */ { "dec\ta", 1, 1, do_inc_dec}, /* dec a*/
 /* 0x15 */ { "dec\t!", 2, 1, do_inc_dec}, /* dec direct*/
 /* 0x16 */ { "dec\t@r0", 1, 1, do_inc_dec}, /* dec @r0*/
 /* 0x17 */ { "dec\t@r1", 1, 1, do_inc_dec}, /* dec @r1*/
 /* 0x18 */ { "dec\tr0", 1, 1, do_inc_dec}, /* dec r0*/
 /* 0x19 */ { "dec\tr1", 1, 1, do_inc_dec}, /* dec r1*/
 /* 0x1A */ { "dec\tr2", 1, 1, do_inc_dec}, /* dec r2*/
 /* 0x1B */ { "dec\tr3", 1, 1, do_inc_dec}, /* dec r3*/
 /* 0x1C */ { "dec\tr4", 1, 1, do_inc_dec}, /* dec r4*/
 /* 0x1D */ { "dec\tr5", 1, 1, do_inc_dec}, /* dec r5*/
 /* 0x1E */ { "dec\tr6", 1, 1, do_inc_dec}, /* dec r6*/
 /* 0x1F */ { "dec\tr7", 1, 1, do_inc_dec}, /* dec r7*/
 /* 0x20 */ { "jb\t%, .", 3, 2, do_jb},  /* jb bit_direct, relative*/
 /* 0x21 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0x22 */ { "ret",  1, 2, do_ret}, /* ret */
 /* 0x23 */ { "rl\ta", 1, 1, do_rl},  /* rl a*/
 /* 0x24 */ { "add\ta, #", 2, 1, do_add}, /* add a, #*/
 /* 0x25 */ { "add\ta, !", 2, 1, do_add}, /* add a, direct*/
 /* 0x26 */ { "add\ta, @r0", 1, 1, do_add}, /* add a, @r0*/
 /* 0x27 */ { "add\ta, @r1", 1, 1, do_add}, /* add a, @r1*/
 /* 0x28 */ { "add\ta, r0", 1, 1, do_add}, /* add a, r0*/
 /* 0x29 */ { "add\ta, r1", 1, 1, do_add}, /* add a, r1*/
 /* 0x2A */ { "add\ta, r2", 1, 1, do_add}, /* add a, r2*/
 /* 0x2B */ { "add\ta, r3", 1, 1, do_add}, /* add a, r3*/
 /* 0x2C */ { "add\ta, r4", 1, 1, do_add}, /* add a, r4*/
 /* 0x2D */ { "add\ta, r5", 1, 1, do_add}, /* add a, r5*/
 /* 0x2E */ { "add\ta, r6", 1, 1, do_add}, /* add a, r6*/
 /* 0x2F */ { "add\ta, r7", 1, 1, do_add}, /* add a, r7*/
 /* 0x30 */ { "jnb\t%, .", 3, 2, do_jnb}, /* jnb bit_direct, relative*/
 /* 0x31 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0x32 */ { "reti", 1, 2, do_reti}, /* reti */
 /* 0x33 */ { "rlc\ta", 1, 1, do_rlc}, /* rlc a*/
 /* 0x34 */ { "addc\ta, #", 2, 1, do_add}, /* addc a, #*/
 /* 0x35 */ { "addc\ta, !", 2, 1, do_add}, /* addc a, direct*/
 /* 0x36 */ { "addc\ta, @r0", 1, 1, do_add}, /* addc a, @r0*/
 /* 0x37 */ { "addc\ta, @r1", 1, 1, do_add}, /* addc a, @r1*/
 /* 0x38 */ { "addc\ta, r0", 1, 1, do_add}, /* addc a, r0*/
 /* 0x39 */ { "addc\ta, r1", 1, 1, do_add}, /* addc a, r1*/
 /* 0x3A */ { "addc\ta, r2", 1, 1, do_add}, /* addc a, r2*/
 /* 0x3B */ { "addc\ta, r3", 1, 1, do_add}, /* addc a, r3*/
 /* 0x3C */ { "addc\ta, r4", 1, 1, do_add}, /* addc a, r4*/
 /* 0x3D */ { "addc\ta, r5", 1, 1, do_add}, /* addc a, r5*/
 /* 0x3E */ { "addc\ta, r6", 1, 1, do_add}, /* addc a, r6*/
 /* 0x3F */ { "addc\ta, r7", 1, 1, do_add}, /* addc a, r7*/
 /* 0x40 */ { "jc\t.", 2, 2, do_jc},  /* jc relative*/
 /* 0x41 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0x42 */ { "orl\t!, a", 2, 1, do_orl}, /* orl direct, a*/
 /* 0x43 */ { "orl\t!, #", 3, 1, do_orl}, /* orl direct, #*/
 /* 0x44 */ { "orl\ta, #", 2, 1, do_orl}, /* orl a, #*/
 /* 0x45 */ { "orl\ta, !", 2, 1, do_orl}, /* orl a, direct*/
 /* 0x46 */ { "orl\ta, @r0", 1, 1, do_orl}, /* orl a, @r0*/
 /* 0x47 */ { "orl\ta, @r1", 1, 1, do_orl}, /* orl a, @r1*/
 /* 0x48 */ { "orl\ta, r0", 1, 1, do_orl}, /* orl a, r0*/
 /* 0x49 */ { "orl\ta, r1", 1, 1, do_orl}, /* orl a, r1*/
 /* 0x4A */ { "orl\ta, r2", 1, 1, do_orl}, /* orl a, r2*/
 /* 0x4B */ { "orl\ta, r3", 1, 1, do_orl}, /* orl a, r3*/
 /* 0x4C */ { "orl\ta, r4", 1, 1, do_orl}, /* orl a, r4*/
 /* 0x4D */ { "orl\ta, r5", 1, 1, do_orl}, /* orl a, r5*/
 /* 0x4E */ { "orl\ta, r6", 1, 1, do_orl}, /* orl a, r6*/
 /* 0x4F */ { "orl\ta, r7", 1, 1, do_orl}, /* orl a, r7*/
 /* 0x50 */ { "jnc\t.", 2, 2, do_jnc}, /* jnc relative*/
 /* 0x51 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0x52 */ { "anl\t!, a", 2, 1, do_anl}, /* anl direct, a*/
 /* 0x53 */ { "anl\t!, #", 3, 2, do_anl}, /* anl direct, #*/
 /* 0x54 */ { "anl\ta, #", 2, 1, do_anl}, /* anl a, #*/
 /* 0x55 */ { "anl\ta, !", 2, 1, do_anl}, /* anl a, direct*/
 /* 0x56 */ { "anl\ta, @r0", 1, 1, do_anl}, /* anl a, @r0*/
 /* 0x57 */ { "anl\ta, @r1", 1, 1, do_anl}, /* anl a, @r1*/
 /* 0x58 */ { "anl\ta, r0", 1, 1, do_anl}, /* anl a, r0*/
 /* 0x59 */ { "anl\ta, r1", 1, 1, do_anl}, /* anl a, r1*/
 /* 0x5A */ { "anl\ta, r2", 1, 1, do_anl}, /* anl a, r2*/
 /* 0x5B */ { "anl\ta, r3", 1, 1, do_anl}, /* anl a, r3*/
 /* 0x5C */ { "anl\ta, r4", 1, 1, do_anl}, /* anl a, r4*/
 /* 0x5D */ { "anl\ta, r5", 1, 1, do_anl}, /* anl a, r5*/
 /* 0x5E */ { "anl\ta, r6", 1, 1, do_anl}, /* anl a, r6*/
 /* 0x5F */ { "anl\ta, r7", 1, 1, do_anl}, /* anl a, r7*/
 /* 0x60 */ { "jz\t.", 2, 2, do_jz},  /* jz relative*/
 /* 0x61 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0x62 */ { "xrl\t!, a", 2, 1, do_xrl}, /* xrl direct, a*/
 /* 0x63 */ { "xrl\t!, #", 3, 2, do_xrl}, /* xrl direct, #*/
 /* 0x64 */ { "xrl\ta, #", 2, 1, do_xrl}, /* xrl a, #*/
 /* 0x65 */ { "xrl\ta, !", 2, 1, do_xrl}, /* xrl a, direct*/
 /* 0x66 */ { "xrl\ta, @r0", 1, 1, do_xrl}, /* xrl a, @r0*/
 /* 0x67 */ { "xrl\ta, @r1", 1, 1, do_xrl}, /* xrl a, @r1*/
 /* 0x68 */ { "xrl\ta, r0", 1, 1, do_xrl}, /* xrl a, r0*/
 /* 0x69 */ { "xrl\ta, r1", 1, 1, do_xrl}, /* xrl a, r1*/
 /* 0x6A */ { "xrl\ta, r2", 1, 1, do_xrl}, /* xrl a, r2*/
 /* 0x6B */ { "xrl\ta, r3", 1, 1, do_xrl}, /* xrl a, r3*/
 /* 0x6C */ { "xrl\ta, r4", 1, 1, do_xrl}, /* xrl a, r4*/
 /* 0x6D */ { "xrl\ta, r5", 1, 1, do_xrl}, /* xrl a, r5*/
 /* 0x6E */ { "xrl\ta, r6", 1, 1, do_xrl}, /* xrl a, r6*/
 /* 0x6F */ { "xrl\ta, r7", 1, 1, do_xrl}, /* xrl a, r7*/
 /* 0x70 */ { "jnz\t.", 2, 2, do_jnz}, /* jnz relative*/
 /* 0x71 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0x72 */ { "orl\tc, %", 2, 2, do_orlc}, /* orl c, bit_direct*/
 /* 0x73 */ { "jmp\t@a+dptr",1, 2, do_jmpdptr}, /* jmp @a+dptr*/
 /* 0x74 */ { "mov\ta, #", 2, 1, do_mov}, /* mov a, #*/
 /* 0x75 */ { "mov\t!, #", 3, 2, do_mov}, /* mov direct, #*/
 /* 0x76 */ { "mov\t@r0, #", 2, 1, do_mov}, /* mov @r0, #*/
 /* 0x77 */ { "mov\t@r1, #", 2, 1, do_mov}, /* mov @r1, #*/
 /* 0x78 */ { "mov\tr0, #", 2, 1, do_mov}, /* mov r0, #*/
 /* 0x79 */ { "mov\tr1, #", 2, 1, do_mov}, /* mov r1, #*/
 /* 0x7A */ { "mov\tr2, #", 2, 1, do_mov}, /* mov r2, #*/
 /* 0x7B */ { "mov\tr3, #", 2, 1, do_mov}, /* mov r3, #*/
 /* 0x7C */ { "mov\tr4, #", 2, 1, do_mov}, /* mov r4, #*/
 /* 0x7D */ { "mov\tr5, #", 2, 1, do_mov}, /* mov r5, #*/
 /* 0x7E */ { "mov\tr6, #", 2, 1, do_mov}, /* mov r6, #*/
 /* 0x7F */ { "mov\tr7, #", 2, 1, do_mov}, /* mov r7, #*/
 /* 0x80 */ { "sjmp\t.", 2, 2, do_sjmp}, /* sjmp relative*/
 /* 0x81 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0x82 */ { "anl c, %", 2, 2, do_anlc}, /* anl c, bit_direct*/
 /* 0x83 */ { "movc\ta, @a+pc", 1, 2, do_movc}, /* movc a, @a+pc*/
 /* 0x84 */ { "div\tab", 1, 4, do_divab}, /* div ab*/
 /* 0x85 */ { "mov\t!, !", 3, 2, do_mov}, /* mov direct, direct WARNING: 85 81(sp) 83(dph) = mov DPH, SP*/ 
 /* 0x86 */ { "mov\t!, @r0", 2, 2, do_mov}, /* mov direct, @r0*/
 /* 0x87 */ { "mov\t!, @r1", 2, 2, do_mov}, /* mov direct, @r1*/
 /* 0x88 */ { "mov\t!, r0", 2, 2, do_mov}, /* mov direct, r0*/
 /* 0x89 */ { "mov\t!, r1", 2, 2, do_mov}, /* mov direct, r1*/
 /* 0x8A */ { "mov\t!, r2", 2, 2, do_mov}, /* mov direct, r2*/
 /* 0x8B */ { "mov\t!, r3", 2, 2, do_mov}, /* mov direct, r3*/
 /* 0x8C */ { "mov\t!, r4", 2, 2, do_mov}, /* mov direct, r4*/
 /* 0x8D */ { "mov\t!, r5", 2, 2, do_mov}, /* mov direct, r5*/
 /* 0x8E */ { "mov\t!, r6", 2, 2, do_mov}, /* mov direct, r6*/
 /* 0x8F */ { "mov\t!, r7", 2, 2, do_mov}, /* mov direct, r7*/
 /* 0x90 */ { "mov\tdptr, #", 3, 2, do_mov}, /* mov dptr, # WARNING: only exception to # use*/
 /* 0x91 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0x92 */ { "mov\t%, c", 2, 2, do_movcy}, /* mov bit_direct, c*/
 /* 0x93 */ { "movc\ta, @a+dptr", 1, 2, do_movc}, /* movc a, @a+dptr*/
 /* 0x94 */ { "subb\ta, #", 2, 1, do_subb}, /* subb a, #*/
 /* 0x95 */ { "subb\ta, !", 2, 1, do_subb}, /* subb a, direct*/
 /* 0x96 */ { "subb\ta, @r0", 1, 1, do_subb}, /* subb a, @r0*/
 /* 0x97 */ { "subb\ta, @r1", 1, 1, do_subb}, /* subb a, @r1*/
 /* 0x98 */ { "subb\ta, r0", 1, 1, do_subb}, /* subb a, r0*/
 /* 0x99 */ { "subb\ta, r1", 1, 1, do_subb}, /* subb a, r1*/
 /* 0x9A */ { "subb\ta, r2", 1, 1, do_subb}, /* subb a, r2*/
 /* 0x9B */ { "subb\ta, r3", 1, 1, do_subb}, /* subb a, r3*/
 /* 0x9C */ { "subb\ta, r4", 1, 1, do_subb}, /* subb a, r4*/
 /* 0x9D */ { "subb\ta, r5", 1, 1, do_subb}, /* subb a, r5*/
 /* 0x9E */ { "subb\ta, r6", 1, 1, do_subb}, /* subb a, r6*/
 /* 0x9F */ { "subb\ta, r7", 1, 1, do_subb}, /* subb a, r7*/
 /* 0xA0 */ { "orl\tc, /.", 2, 2, do_orlc}, /* orl c, /*/
 /* 0xA1 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0xA2 */ { "mov\tc, %", 2, 1, do_movcy}, /* mov c, bit_direct*/
 /* 0xA3 */ { "inc\tdptr", 1, 2, do_incdptr}, /* inc dptr*/
 /* 0xA4 */ { "mul\tab", 1, 4, do_mulab}, /* mul ab*/
 /* 0xA5 */ { "db\ta5", 1, 1, do_ilegal}, /* db a5*/
 /* 0xA6 */ { "mov\t@r0, !", 2, 2, do_mov}, /* mov @r0, direct*/
 /* 0xA7 */ { "mov\t@r1, !", 2, 2, do_mov}, /* mov @r1, direct*/
 /* 0xA8 */ { "mov\tr0, !", 2, 2, do_mov}, /* mov r0, direct*/
 /* 0xA9 */ { "mov\tr1, !", 2, 2, do_mov}, /* mov r1, direct*/
 /* 0xAA */ { "mov\tr2, !", 2, 2, do_mov}, /* mov r2, direct*/
 /* 0xAB */ { "mov\tr3, !", 2, 2, do_mov}, /* mov r3, direct*/
 /* 0xAC */ { "mov\tr4, !", 2, 2, do_mov}, /* mov r4, direct*/
 /* 0xAD */ { "mov\tr5, !", 2, 2, do_mov}, /* mov r5, direct*/
 /* 0xAE */ { "mov\tr6, !", 2, 2, do_mov}, /* mov r6, direct*/
 /* 0xAF */ { "mov\tr7, !", 2, 2, do_mov}, /* mov r7, direct*/
 /* 0xB0 */ { "anl\tc, /.", 2, 2, do_anlc}, /* anl c, /*/
 /* 0xB1 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0xB2 */ { "cpl\t%", 2, 1, do_cpl}, /* cpl */
 /* 0xB3 */ { "cpl\tc", 1, 1, do_cplcy}, /* cpl c*/
 /* 0xB4 */ { "cjne\ta, # .",3, 2, do_cjne}, /* cjne a, # relative*/
 /* 0xB5 */ { "cjne\ta, ! .",3, 2, do_cjne}, /* cjne a, direct relative*/
 /* 0xB6 */ { "cjne\t@r0, # .",3, 2, do_cjne}, /* cjne @r0, # relative*/
 /* 0xB7 */ { "cjne\t@r1, # .",3, 2, do_cjne}, /* cjne @r1, # relative*/
 /* 0xB8 */ { "cjne\tr0, # .",3, 2, do_cjne}, /* cjne r0, # relative*/
 /* 0xB9 */ { "cjne\tr1, # .",3, 2, do_cjne}, /* cjne r1, # relative*/
 /* 0xBA */ { "cjne\tr2, # .",3, 2, do_cjne}, /* cjne r2, # relative*/
 /* 0xBB */ { "cjne\tr3, # .",3, 2, do_cjne}, /* cjne r3, # relative*/
 /* 0xBC */ { "cjne\tr4, # .",3, 2, do_cjne}, /* cjne r4, # relative*/
 /* 0xBD */ { "cjne\tr5, # .",3, 2, do_cjne}, /* cjne r5, # relative*/
 /* 0xBE */ { "cjne\tr6, # .",3, 2, do_cjne}, /* cjne r6, # relative*/
 /* 0xBF */ { "cjne\tr7, # .",3, 2, do_cjne}, /* cjne r7, # relative*/
 /* 0xC0 */ { "push\t!", 2, 2, do_push}, /* push direct*/
 /* 0xC1 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0xC2 */ { "clr\t%", 2, 1, do_clr}, /* clr bit_direct*/
 /* 0xC3 */ { "clr\tc", 1, 1, do_clrcy}, /* clr c*/
 /* 0xC4 */ { "swap\ta", 1, 1, do_swapa}, /* swap a*/
 /* 0xC5 */ { "xch\ta, !", 2, 1, do_xch}, /* xch a, direct*/
 /* 0xC6 */ { "xch\ta, @r0", 1, 1, do_xch}, /* xch a, @r0*/
 /* 0xC7 */ { "xch\ta, @r1", 1, 1, do_xch}, /* xch a, @r1*/
 /* 0xC8 */ { "xch\ta, r0", 1, 1, do_xch}, /* xch a, r0*/
 /* 0xC9 */ { "xch\ta, r1", 1, 1, do_xch}, /* xch a, r1*/
 /* 0xCA */ { "xch\ta, r2", 1, 1, do_xch}, /* xch a, r2*/
 /* 0xCB */ { "xch\ta, r3", 1, 1, do_xch}, /* xch a, r3*/
 /* 0xCC */ { "xch\ta, r4", 1, 1, do_xch}, /* xch a, r4*/
 /* 0xCD */ { "xch\ta, r5", 1, 1, do_xch}, /* xch a, r5*/
 /* 0xCE */ { "xch\ta, r6", 1, 1, do_xch}, /* xch a, r6*/
 /* 0xCF */ { "xch\ta, r7", 1, 1, do_xch}, /* xch a, r7*/
 /* 0xD0 */ { "pop\t!", 2, 2, do_pop}, /* pop direct*/
 /* 0xD1 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0xD2 */ { "setb\t%", 2, 1, do_setb}, /* setb bit_direct*/
 /* 0xD3 */ { "setb\tc", 1, 1, do_setbcy}, /* setb c*/
 /* 0xD4 */ { "da\ta", 1, 1, do_daa}, /* da a*/
 /* 0xD5 */ { "djnz\t! .", 3, 2, do_djnz}, /* djnz direct relative*/
 /* 0xD6 */ { "xchd\ta, @r0", 1, 1, do_xchd}, /* xchd a, @r0*/
 /* 0xD7 */ { "xchd\ta, @r1", 1, 1, do_xchd}, /* xchd a, @r1*/
 /* 0xD8 */ { "djnz\tr0, .", 2, 2, do_djnz}, /* djnz r0, relative*/
 /* 0xD9 */ { "djnz\tr1, .", 2, 2, do_djnz}, /* djnz r1, relative*/
 /* 0xDA */ { "djnz\tr2, .", 2, 2, do_djnz}, /* djnz r2, relative*/
 /* 0xDB */ { "djnz\tr3, .", 2, 2, do_djnz}, /* djnz r3, relative*/
 /* 0xDC */ { "djnz\tr4, .", 2, 2, do_djnz}, /* djnz r4, relative*/
 /* 0xDD */ { "djnz\tr5, .", 2, 2, do_djnz}, /* djnz r5, relative*/
 /* 0xDE */ { "djnz\tr6, .", 2, 2, do_djnz}, /* djnz r6, relative*/
 /* 0xDF */ { "djnz\tr7, .", 2, 2, do_djnz}, /* djnz r7, relative*/
 /* 0xE0 */ { "movx\ta, @dptr", 1, 2, do_movx}, /* movx a, @dptr*/
 /* 0xE1 */ { "ajmp\t&", 2, 2, do_ajmp}, /* ajmp 11bit*/
 /* 0xE2 */ { "movx\ta, @r0", 1, 2, do_movx}, /* movx a, @r0*/
 /* 0xE3 */ { "movx\ta, @r1", 1, 2, do_movx}, /* movx a, @r1*/
 /* 0xE4 */ { "clr\ta", 1, 1, do_clra}, /* clr a*/
 /* 0xE5 */ { "mov\ta, !", 2, 1, do_mov}, /* mov a, direct*/
 /* 0xE6 */ { "mov\ta, @r0", 1, 1, do_mov}, /* mov a, @r0*/
 /* 0xE7 */ { "mov\ta, @r1", 1, 1, do_mov}, /* mov a, @r1*/
 /* 0xE8 */ { "mov\ta, r0", 1, 1, do_mov}, /* mov a, r0*/
 /* 0xE9 */ { "mov\ta, r1", 1, 1, do_mov}, /* mov a, r1*/
 /* 0xEA */ { "mov\ta, r2", 1, 1, do_mov}, /* mov a, r2*/
 /* 0xEB */ { "mov\ta, r3", 1, 1, do_mov}, /* mov a, r3*/
 /* 0xEC */ { "mov\ta, r4", 1, 1, do_mov}, /* mov a, r4*/
 /* 0xED */ { "mov\ta, r5", 1, 1, do_mov}, /* mov a, r5*/
 /* 0xEE */ { "mov\ta, r6", 1, 1, do_mov}, /* mov a, r6*/
 /* 0xEF */ { "mov\ta, r7", 1, 1, do_mov}, /* mov a, r7*/
 /* 0xF0 */ { "movx\t@dptr, a", 1, 2, do_movx}, /* movx @dptr, a*/
 /* 0xF1 */ { "acall\t&", 2, 2, do_acall}, /* acall 11bit*/
 /* 0xF2 */ { "movx\t@r0, a", 1, 2, do_movx}, /* movx @r0, a*/
 /* 0xF3 */ { "movx\t@r1, a", 1, 2, do_movx}, /* movx @r1, a*/
 /* 0xF4 */ { "cpl\ta", 1, 1, do_cpla}, /* cpl a*/
 /* 0xF5 */ { "mov\t!, a", 2, 1, do_mov}, /* mov direct, a*/
 /* 0xF6 */ { "mov\t@r0, a", 1, 1, do_mov}, /* mov @r0, a*/
 /* 0xF7 */ { "mov\t@r1, a", 1, 1, do_mov}, /* mov @r1, a*/
 /* 0xF8 */ { "mov\tr0, a", 1, 1, do_mov}, /* mov r0, a*/
 /* 0xF9 */ { "mov\tr1, a", 1, 1, do_mov}, /* mov r1, a*/
 /* 0xFA */ { "mov\tr2, a", 1, 1, do_mov}, /* mov r2, a*/
 /* 0xFB */ { "mov\tr3, a", 1, 1, do_mov}, /* mov r3, a*/
 /* 0xFC */ { "mov\tr4, a", 1, 1, do_mov}, /* mov r4, a*/
 /* 0xFD */ { "mov\tr5, a", 1, 1, do_mov}, /* mov r5, a*/
 /* 0xFE */ { "mov\tr6, a", 1, 1, do_mov}, /* mov r6, a*/
 /* 0xFF */ { "mov\tr7, a", 1, 1, do_mov}, /* mov r7, a*/
};

// The especial function register names.  This one is based on the P89V51RD2
unsigned char * sfrn[0x80] =
{
    "P0",      /*80*/
    "SP",      /*81*/
    "DPL",     /*82*/
    "DPH",     /*83*/
	"",        /*84*/
    "WDTD",    /*85*/
    "SPDR",    /*86*/
    "PCON",    /*87*/
    "TCON",    /*88*/
    "TMOD",    /*89*/
    "TL0",     /*8A*/
    "TL1",     /*8B*/
    "TH0",     /*8C*/
    "TH1",     /*8D*/
    "AUXR",    /*8E*/
	"",        /*8F*/

    "P1",      /*90*/
	"",        /*91*/
	"",        /*92*/
	"",        /*93*/
	"",        /*94*/
	"",        /*95*/
	"",        /*96*/
	"",        /*97*/
    "SCON",    /*98*/
    "SBUF",    /*99*/
	"",        /*9A*/
	"",        /*9B*/
	"",        /*9C*/
	"",        /*9D*/
	"",        /*9E*/
	"",        /*9F*/

    "P2",      /*A0*/
	"",        /*A1*/
    "AUXR1",   /*A2*/
	"",        /*A3*/
	"",        /*A4*/
	"",        /*A5*/
	"",        /*A6*/
	"",        /*A7*/
    "IE",      /*A8*/
    "SADDR",   /*A9*/
    "SPSR",    /*AA*/
	"",        /*AB*/
	"",        /*AC*/
	"",        /*AD*/
	"",        /*AE*/
	"",        /*AF*/

    "P3",      /*B0*/
    "FCF",     /*B1*/
	"",        /*B2*/
	"",        /*B3*/
	"",        /*B4*/
	"",        /*B5*/
    "FST",     /*B6*/
    "IPH",     /*B7*/
    "IP",      /*B8*/
    "SADEN",   /*B9*/
	"",        /*BA*/
	"",        /*BB*/
	"",        /*BC*/
	"",        /*BD*/
	"",        /*BE*/
	"",        /*BF*/

    "WDTC",    /*C0*/
	"",        /*C1*/
	"",        /*C2*/
	"",        /*C3*/
	"",        /*C4*/
	"",        /*C5*/
	"",        /*C6*/
	"",        /*C7*/
    "T2CON",   /*C8*/
    "T2MOD",   /*C9*/
    "RCAP2L",  /*CA*/
    "RCAP2H",  /*CB*/
    "TL2",     /*CC*/
    "TH2",     /*CD*/
 	"",        /*CE*/
	"",        /*CF*/
    
	"PSW",     /*D0*/
	"",        /*D1*/
	"",        /*D2*/
	"",        /*D3*/
	"",        /*D4*/
    "SPCR",    /*D5*/
	"",        /*D6*/
	"",        /*D7*/
    "CCON",    /*D8*/
    "CMOD",    /*D9*/
    "CCAPM0",  /*DA*/
    "CCAPM1",  /*DB*/
    "CCAPM2",  /*DC*/
    "CCAPM3",  /*DD*/
    "CCAPM4",  /*DE*/
	"",        /*DF*/

    "ACC",     /*E0*/
	"",        /*E1*/
	"",        /*E2*/
	"",        /*E3*/
	"",        /*E4*/
	"",        /*E5*/
	"",        /*E6*/
	"",        /*E7*/
    "IEN1",    /*E8*/
    "CL",      /*E9*/
    "CCAP0L",  /*EA*/
    "CCAP1L",  /*EB*/
    "CCAP2L",  /*EC*/
    "CCAP3L",  /*ED*/
    "CCAP4L",  /*EE*/
	"",        /*EF*/

    "B",       /*F0*/
	"",        /*F1*/
	"",        /*F2*/
	"",        /*F3*/
	"",        /*F4*/
	"",        /*F5*/
	"",        /*F6*/
    "IP1H",    /*F7*/
    "IP1",     /*F8*/
    "CH",      /*F9*/
    "CCAP0H",  /*FA*/
    "CCAP1H",  /*FB*/
    "CCAP2H",  /*FC*/
    "CCAP3H",  /*FD*/
    "CCAP4H",  /*FE*/
	"",        /*F6*/
};

//These are the bit names...
unsigned char * bitn[0x80] =
{
	"",        /*80*/
	"",        /*81*/
	"",        /*82*/
	"",        /*83*/
	"",        /*84*/
	"",        /*85*/
	"",        /*86*/
	"",        /*87*/
    "IT0",     /*88*/ 
    "IE0",     /*89*/ 
    "IT1",     /*8A*/ 
    "IE1",     /*8B*/ 
    "TR0",     /*8C*/ 
    "TF0",     /*8D*/ 
    "TR1",     /*8E*/ 
    "TF1",     /*8F*/ 

	"",        /*90*/
	"",        /*91*/
	"",        /*92*/
	"",        /*93*/
	"",        /*94*/
	"",        /*95*/
	"",        /*96*/
	"",        /*97*/
    "RI",      /*98*/
    "TI",      /*99*/ 
    "RB8",     /*9A*/ 
    "TB8",     /*9B*/ 
    "REN",     /*9C*/ 
    "SM2",     /*9D*/ 
    "SM1",     /*9E*/ 
    "SM0",     /*9F*/ 

	"",        /*A0*/
	"",        /*A1*/
	"",        /*A2*/
	"",        /*A3*/
	"",        /*A4*/
	"",        /*A5*/
	"",        /*A6*/
	"",        /*A7*/
    "EX0",     /*A8*/ 
	"ET0",     /*A9*/ 
    "EX1",     /*AA*/ 
    "ET1",     /*AB*/ 
    "ES",      /*AC*/ 
    "ET2",     /*AD*/ 
    "EC",      /*AE*/ 
    "EA",      /*AF*/ 
    
	"",        /*B0*/
	"",        /*B1*/
	"",        /*B2*/
	"",        /*B3*/
	"",        /*B4*/
	"",        /*B5*/
	"",        /*B6*/
	"",        /*B7*/
	"PX0",     /*B8*/ 
    "PT0",     /*B9*/ 
    "PX1",     /*BA*/ 
    "PT1",     /*BB*/ 
    "PS",      /*BC*/ 
    "PT2",     /*BD*/
    "PPC",     /*BE*/
    "",        /*BF*/

	"",        /*C0*/
	"",        /*C1*/
	"",        /*C2*/
	"",        /*C3*/
	"",        /*C4*/
	"",        /*C5*/
	"",        /*C6*/
	"",        /*C7*/
	"CP_RL2",  /*C8*/ 
    "C_T2",    /*C9*/ 
    "TR2",     /*CA*/ 
    "EXEN2",   /*CB*/ 
    "TCLK",    /*CC*/ 
    "RCLK",    /*CD*/ 
    "EXF2",    /*CE*/ 
    "TF2",     /*CF*/ 

    "P",       /*D0*/ 
    "F1",      /*D1*/ 
    "OV",      /*D2*/ 
    "RS0",     /*D3*/ 
    "RS1",     /*D4*/ 
    "F0",      /*D5*/ 
    "AC",      /*D6*/ 
    "CY",      /*D7*/ 
    "CCF0",    /*D8*/
    "CCF1",    /*D9*/
    "CCF2",    /*DA*/ 
    "CCF3",    /*DB*/ 
    "CCF4",    /*DC*/ 
    "",        /*DD*/ 
    "CR",      /*DE*/ 
    "CF",      /*DF*/ 
  
    "",        /*E0*/ 
    "",        /*E1*/ 
    "",        /*E2*/ 
    "",        /*E3*/ 
    "",        /*E4*/ 
    "",        /*E5*/ 
    "",        /*E6*/ 
    "",        /*E7*/ 
    "",        /*E8*/ 
    "",        /*E9*/ 
    "",        /*EA*/ 
	"EBO",     /*EB*/ 
    "",        /*EC*/ 
    "",        /*ED*/ 
    "",        /*EE*/ 
    "",        /*EF*/ 
    
	"",        /*F0*/ 
    "",        /*F1*/ 
    "",        /*F2*/ 
    "",        /*F3*/ 
    "",        /*F4*/ 
    "",        /*F5*/ 
    "",        /*F6*/ 
    "",        /*F7*/ 
    "",        /*F8*/ 
    "",        /*F9*/ 
    "",        /*FA*/ 
    "PBO",     /*FB*/
    "",        /*FC*/ 
    "",        /*FD*/ 
    "",        /*FE*/ 
    "",        /*FF*/ 
};
