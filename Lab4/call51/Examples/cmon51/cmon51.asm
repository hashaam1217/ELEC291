;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Dec 11 2012) (MSVC)
; This file was generated Mon Jan 07 19:38:35 2013
;--------------------------------------------------------
$name cmon51
$optc51 --model-small
	R_DSEG    segment data
	R_CSEG    segment code
	R_BSEG    segment bit
	R_XSEG    segment xdata
	R_ISEG    segment idata
	R_OSEG    segment data overlay
	BIT_BANK  segment data overlay
	R_HOME    segment code
	R_GSINIT  segment code
	R_IXSEG   segment xdata
	R_CONST   segment code
	R_XINIT   segment code
	R_DINIT   segment code

;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	public _fillmem_PARM_3
	public _fillmem_PARM_2
	public _maskbit
	public _hexval
	public _cmdlst
	public _breakorstep
	public _nlist
	public _outwordnl
	public _disp_regs
	public _showreg
	public _getwordn
	public _cleanbuff
	public _dispmem
	public _modifymem
	public _getbyte
	public _getsn
	public _clearline
	public _trace_type
	public _break_address
	public _gostep
	public _saved_int
	public _saved_jmp
	public _step_start
	public _gotbreak
	public _PC_save
	public _SP_save
	public _DPH_save
	public _DPL_save
	public _IE_save
	public _B_save
	public _PSW_save
	public _A_save
	public _br
	public _iram_save
	public _breakpoint
	public _buff_hasdot
	public _buff_haseq
	public _keepediting
	public _validbyte
	public _showreg_PARM_2
	public _dispmem_PARM_3
	public _dispmem_PARM_2
	public _modifymem_PARM_2
	public _cursor
	public _buff
	public _putsp
	public _chartohex
	public _outbyte
	public _outword
	public _fillmem
	public _getbytene
	public _hitanykey
	public _do_cmd
;--------------------------------------------------------
; Special Function Registers
;--------------------------------------------------------
_P0             DATA 0x80
_SP             DATA 0x81
_DPL            DATA 0x82
_DPH            DATA 0x83
_PCON           DATA 0x87
_TCON           DATA 0x88
_TMOD           DATA 0x89
_TL0            DATA 0x8a
_TL1            DATA 0x8b
_TH0            DATA 0x8c
_TH1            DATA 0x8d
_P1             DATA 0x90
_SCON           DATA 0x98
_SBUF           DATA 0x99
_P2             DATA 0xa0
_IE             DATA 0xa8
_P3             DATA 0xb0
_IP             DATA 0xb8
_PSW            DATA 0xd0
_ACC            DATA 0xe0
_B              DATA 0xf0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
_P0_0           BIT 0x80
_P0_1           BIT 0x81
_P0_2           BIT 0x82
_P0_3           BIT 0x83
_P0_4           BIT 0x84
_P0_5           BIT 0x85
_P0_6           BIT 0x86
_P0_7           BIT 0x87
_IT0            BIT 0x88
_IE0            BIT 0x89
_IT1            BIT 0x8a
_IE1            BIT 0x8b
_TR0            BIT 0x8c
_TF0            BIT 0x8d
_TR1            BIT 0x8e
_TF1            BIT 0x8f
_P1_0           BIT 0x90
_P1_1           BIT 0x91
_P1_2           BIT 0x92
_P1_3           BIT 0x93
_P1_4           BIT 0x94
_P1_5           BIT 0x95
_P1_6           BIT 0x96
_P1_7           BIT 0x97
_RI             BIT 0x98
_TI             BIT 0x99
_RB8            BIT 0x9a
_TB8            BIT 0x9b
_REN            BIT 0x9c
_SM2            BIT 0x9d
_SM1            BIT 0x9e
_SM0            BIT 0x9f
_P2_0           BIT 0xa0
_P2_1           BIT 0xa1
_P2_2           BIT 0xa2
_P2_3           BIT 0xa3
_P2_4           BIT 0xa4
_P2_5           BIT 0xa5
_P2_6           BIT 0xa6
_P2_7           BIT 0xa7
_EX0            BIT 0xa8
_ET0            BIT 0xa9
_EX1            BIT 0xaa
_ET1            BIT 0xab
_ES             BIT 0xac
_EA             BIT 0xaf
_P3_0           BIT 0xb0
_P3_1           BIT 0xb1
_P3_2           BIT 0xb2
_P3_3           BIT 0xb3
_P3_4           BIT 0xb4
_P3_5           BIT 0xb5
_P3_6           BIT 0xb6
_P3_7           BIT 0xb7
_RXD            BIT 0xb0
_TXD            BIT 0xb1
_INT0           BIT 0xb2
_INT1           BIT 0xb3
_T0             BIT 0xb4
_T1             BIT 0xb5
_WR             BIT 0xb6
_RD             BIT 0xb7
_PX0            BIT 0xb8
_PT0            BIT 0xb9
_PX1            BIT 0xba
_PT1            BIT 0xbb
_PS             BIT 0xbc
_P              BIT 0xd0
_F1             BIT 0xd1
_OV             BIT 0xd2
_RS0            BIT 0xd3
_RS1            BIT 0xd4
_F0             BIT 0xd5
_AC             BIT 0xd6
_CY             BIT 0xd7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	rbank0 segment data overlay
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	rseg R_DSEG
_buff:
	ds 32
_cursor:
	ds 1
_modifymem_PARM_2:
	ds 1
_dispmem_PARM_2:
	ds 2
_dispmem_PARM_3:
	ds 1
_dispmem_begin_1_106:
	ds 3
_dispmem_k_1_107:
	ds 1
_showreg_PARM_2:
	ds 1
_do_cmd_i_1_150:
	ds 2
_do_cmd_j_1_150:
	ds 2
_do_cmd_n_1_150:
	ds 2
_do_cmd_q_1_150:
	ds 2
_do_cmd_d_1_150:
	ds 1
_do_cmd_y_1_150:
	ds 1
_do_cmd_cmd_1_150:
	ds 1
_do_cmd_sloc0_1_0:
	ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg	R_OSEG
	rseg	R_OSEG
	rseg	R_OSEG
	rseg	R_OSEG
_fillmem_PARM_2:
	ds 2
_fillmem_PARM_3:
	ds 1
	rseg	R_OSEG
_nlist_q_1_136:
	ds 1
_nlist_sloc0_1_0:
	ds 3
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	rseg R_ISEG
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	DSEG
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	rseg R_BSEG
_validbyte:
	DBIT	1
_keepediting:
	DBIT	1
_buff_haseq:
	DBIT	1
_buff_hasdot:
	DBIT	1
_breakpoint:
	DBIT	1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	rseg R_XSEG
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	rseg R_XSEG
_iram_save:
	ds 128
_br:
	ds 8
_A_save:
	ds 1
_PSW_save:
	ds 1
_B_save:
	ds 1
_IE_save:
	ds 1
_DPL_save:
	ds 2
_DPH_save:
	ds 2
_SP_save:
	ds 1
_PC_save:
	ds 2
_gotbreak:
	ds 1
_step_start:
	ds 2
_saved_jmp:
	ds 3
_saved_int:
	ds 3
_gostep:
	ds 1
_break_address:
	ds 2
_trace_type:
	ds 1
_getsn_buff2_1_63:
	ds 32
_getsn_count2_1_63:
	ds 1
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	XSEG
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	rseg R_IXSEG
	rseg R_HOME
	rseg R_GSINIT
	rseg R_CSEG
;--------------------------------------------------------
; Interrupt vectors
;--------------------------------------------------------
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	rseg R_HOME
	rseg R_GSINIT
	rseg R_GSINIT
;--------------------------------------------------------
; data variables initialization
;--------------------------------------------------------
	rseg R_DINIT
	; The linker places a 'ret' at the end of segment R_DINIT.
;--------------------------------------------------------
; code
;--------------------------------------------------------
	rseg R_CSEG
;------------------------------------------------------------
;Allocation info for local variables in function 'putsp'
;------------------------------------------------------------
;x                         Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	.\cmon51.c:58: void putsp(unsigned char * x)
;	-----------------------------------------
;	 function putsp
;	-----------------------------------------
_putsp:
	using	0
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	.\cmon51.c:60: while( ((*x)>0) && ((*x)<0x80) )
L002010?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	jz	L002013?
	cjne	r5,#0x80,L002024?
L002024?:
	jnc	L002013?
;	.\cmon51.c:62: if(*x==(unsigned char)'\n') putc('\r');
	cjne	r5,#0x0A,L002006?
L002001?:
	jbc	_TI,L002028?
	sjmp	L002001?
L002028?:
	mov	_SBUF,#0x0D
;	.\cmon51.c:63: putc(*x);
L002006?:
	jbc	_TI,L002029?
	sjmp	L002006?
L002029?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	_SBUF,a
	inc	dptr
	mov	r2,dpl
	mov	r3,dph
;	.\cmon51.c:64: x++;
	sjmp	L002010?
L002013?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'clearline'
;------------------------------------------------------------
;j                         Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:68: void clearline (void)
;	-----------------------------------------
;	 function clearline
;	-----------------------------------------
_clearline:
;	.\cmon51.c:71: putc('\r');
L003001?:
	jbc	_TI,L003024?
	sjmp	L003001?
L003024?:
	mov	_SBUF,#0x0D
;	.\cmon51.c:72: for(j=0; j<79; j++) putc(' ');
	mov	r2,#0x00
L003010?:
	cjne	r2,#0x4F,L003025?
L003025?:
	jnc	L003007?
L003004?:
	jbc	_TI,L003027?
	sjmp	L003004?
L003027?:
	mov	_SBUF,#0x20
	inc	r2
;	.\cmon51.c:73: putc('\r');
	sjmp	L003010?
L003007?:
	jbc	_TI,L003028?
	sjmp	L003007?
L003028?:
	mov	_SBUF,#0x0D
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getsn'
;------------------------------------------------------------
;c                         Allocated to registers r3 
;count                     Allocated to registers r2 
;buff2                     Allocated with name '_getsn_buff2_1_63'
;count2                    Allocated with name '_getsn_count2_1_63'
;------------------------------------------------------------
;	.\cmon51.c:79: void getsn (void)
;	-----------------------------------------
;	 function getsn
;	-----------------------------------------
_getsn:
;	.\cmon51.c:82: unsigned char count=0;
	mov	r2,#0x00
;	.\cmon51.c:84: volatile xdata unsigned char count2=0;
	mov	dptr,#_getsn_count2_1_63
	clr	a
	movx	@dptr,a
;	.\cmon51.c:86: while (1)
L004024?:
;	.\cmon51.c:88: c=getchar();
	push	ar2
	lcall	_getchar
	mov	r3,dpl
	pop	ar2
;	.\cmon51.c:90: switch(c)
	cjne	r3,#0x08,L004055?
	sjmp	L004001?
L004055?:
	cjne	r3,#0x0A,L004056?
	sjmp	L004005?
L004056?:
	cjne	r3,#0x0D,L004057?
	sjmp	L004005?
L004057?:
	cjne	r3,#0x16,L004058?
	sjmp	L004008?
L004058?:
	ljmp	L004012?
;	.\cmon51.c:92: case '\b': // backspace
L004001?:
;	.\cmon51.c:93: if (count)
	mov	a,r2
	jz	L004024?
;	.\cmon51.c:95: putsp("\b \b");
	mov	dptr,#__str_0
	mov	b,#0x80
	push	ar2
	lcall	_putsp
	pop	ar2
;	.\cmon51.c:96: buff[count--]=0;
	mov	ar4,r2
	dec	r2
	mov	a,r4
	add	a,#_buff
	mov	r0,a
	mov	@r0,#0x00
;	.\cmon51.c:98: break;
;	.\cmon51.c:100: case '\r': // CR or LF
	sjmp	L004024?
L004005?:
;	.\cmon51.c:101: putnl();
	push	ar2
	lcall	_putnl
	pop	ar2
;	.\cmon51.c:102: buff[count]=0;
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	@r0,#0x00
;	.\cmon51.c:103: if(count)
	mov	a,r2
	jz	L004007?
;	.\cmon51.c:105: count2=count;
	mov	dptr,#_getsn_count2_1_63
	mov	a,r2
	movx	@dptr,a
;	.\cmon51.c:106: for(c=0; c<=count; c++) buff2[c]=buff[c];
	mov	r4,#0x00
L004026?:
	clr	c
	mov	a,r2
	subb	a,r4
	jc	L004007?
	mov	a,r4
	add	a,#_getsn_buff2_1_63
	mov	dpl,a
	clr	a
	addc	a,#(_getsn_buff2_1_63 >> 8)
	mov	dph,a
	mov	a,r4
	add	a,#_buff
	mov	r0,a
	mov	a,@r0
	mov	r5,a
	movx	@dptr,a
	inc	r4
	sjmp	L004026?
L004007?:
;	.\cmon51.c:108: return;
;	.\cmon51.c:109: case 0x16: // <CTRL>+V
	ret
L004008?:
;	.\cmon51.c:110: clearline();
	lcall	_clearline
;	.\cmon51.c:111: count=count2;
	mov	dptr,#_getsn_count2_1_63
	movx	a,@dptr
	mov	r2,a
;	.\cmon51.c:112: putsp("> ");
	mov	dptr,#__str_1
	mov	b,#0x80
	push	ar2
	lcall	_putsp
	pop	ar2
;	.\cmon51.c:113: for(c=0; c<=count; c++) {buff[c]=buff2[c]; putc(buff[c]);}
	mov	r4,#0x00
L004030?:
	clr	c
	mov	a,r2
	subb	a,r4
	jnc	L004062?
	ljmp	L004024?
L004062?:
	mov	a,r4
	add	a,#_buff
	mov	r0,a
	mov	a,r4
	add	a,#_getsn_buff2_1_63
	mov	dpl,a
	clr	a
	addc	a,#(_getsn_buff2_1_63 >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r5,a
	mov	@r0,a
L004009?:
	jbc	_TI,L004063?
	sjmp	L004009?
L004063?:
	mov	a,r4
	add	a,#_buff
	mov	r0,a
	mov	_SBUF,@r0
	inc	r4
;	.\cmon51.c:115: default:
	sjmp	L004030?
L004012?:
;	.\cmon51.c:116: if(count<(BUFFSIZE-1))
	cjne	r2,#0x1F,L004064?
L004064?:
	jnc	L004016?
;	.\cmon51.c:118: buff[count++]=c;
	mov	ar4,r2
	inc	r2
	mov	a,r4
	add	a,#_buff
	mov	r0,a
	mov	@r0,ar3
;	.\cmon51.c:119: putc(c);
L004013?:
	jbc	_TI,L004066?
	sjmp	L004013?
L004066?:
	mov	_SBUF,r3
	ljmp	L004024?
;	.\cmon51.c:121: else putc('\a'); //Ding!
L004016?:
	jbc	_TI,L004067?
	sjmp	L004016?
L004067?:
	mov	_SBUF,#0x07
;	.\cmon51.c:123: }
	ljmp	L004024?
;------------------------------------------------------------
;Allocation info for local variables in function 'chartohex'
;------------------------------------------------------------
;c                         Allocated to registers r2 
;i                         Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:127: unsigned char chartohex(char c)
;	-----------------------------------------
;	 function chartohex
;	-----------------------------------------
_chartohex:
;	.\cmon51.c:130: i=toupper(c)-'0';
	mov  r2,dpl
	push	ar2
	lcall	_islower
	mov	a,dpl
	pop	ar2
	jz	L005005?
	mov	a,#0xDF
	anl	a,r2
	mov	r3,a
	sjmp	L005006?
L005005?:
	mov	ar3,r2
L005006?:
	mov	a,r3
	add	a,#0xd0
;	.\cmon51.c:131: if(i>9) i-=7; //letter from A to F
	mov  r2,a
	add	a,#0xff - 0x09
	jnc	L005002?
	mov	a,r2
	add	a,#0xf9
	mov	r2,a
L005002?:
;	.\cmon51.c:132: return i;
	mov	dpl,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'outbyte'
;------------------------------------------------------------
;x                         Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:135: void outbyte(unsigned char x)
;	-----------------------------------------
;	 function outbyte
;	-----------------------------------------
_outbyte:
	mov	r2,dpl
;	.\cmon51.c:137: putc(hexval[x/0x10]);
L006001?:
	jbc	_TI,L006013?
	sjmp	L006001?
L006013?:
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov	r3,a
	mov	dptr,#_hexval
	movc	a,@a+dptr
	mov	_SBUF,a
;	.\cmon51.c:138: putc(hexval[x&0xf]);
L006004?:
	jbc	_TI,L006014?
	sjmp	L006004?
L006014?:
	mov	a,#0x0F
	anl	a,r2
	mov	dptr,#_hexval
	movc	a,@a+dptr
	mov	_SBUF,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'outword'
;------------------------------------------------------------
;x                         Allocated to registers r2 r3 
;------------------------------------------------------------
;	.\cmon51.c:141: void outword(unsigned int x)
;	-----------------------------------------
;	 function outword
;	-----------------------------------------
_outword:
	mov	r2,dpl
	mov	r3,dph
;	.\cmon51.c:143: outbyte(highof(x));
	mov	ar4,r3
	mov	dpl,r4
	push	ar2
	push	ar3
	lcall	_outbyte
	pop	ar3
	pop	ar2
;	.\cmon51.c:144: outbyte(lowof(x));
	mov	dpl,r2
	ljmp	_outbyte
;------------------------------------------------------------
;Allocation info for local variables in function 'fillmem'
;------------------------------------------------------------
;len                       Allocated with name '_fillmem_PARM_2'
;val                       Allocated with name '_fillmem_PARM_3'
;begin                     Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	.\cmon51.c:148: void fillmem(unsigned char * begin,  unsigned int len, unsigned char val)
;	-----------------------------------------
;	 function fillmem
;	-----------------------------------------
_fillmem:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	.\cmon51.c:150: while(len)
	mov	r5,_fillmem_PARM_2
	mov	r6,(_fillmem_PARM_2 + 1)
L008001?:
	mov	a,r5
	orl	a,r6
	jz	L008004?
;	.\cmon51.c:152: *begin=val;
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_fillmem_PARM_3
	lcall	__gptrput
	inc	dptr
	mov	r2,dpl
	mov	r3,dph
;	.\cmon51.c:153: begin++;
;	.\cmon51.c:154: len--;
	dec	r5
	cjne	r5,#0xff,L008001?
	dec	r6
	sjmp	L008001?
L008004?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getbytene'
;------------------------------------------------------------
;j                         Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:159: unsigned char getbytene (void)
;	-----------------------------------------
;	 function getbytene
;	-----------------------------------------
_getbytene:
;	.\cmon51.c:163: j=chartohex(getchar());
	lcall	_getchar
	lcall	_chartohex
;	.\cmon51.c:164: return (j*0x10+chartohex(getchar()));
	mov	a,dpl
	swap	a
	anl	a,#0xf0
	mov	r2,a
	push	ar2
	lcall	_getchar
	lcall	_chartohex
	mov	r3,dpl
	pop	ar2
	mov	a,r3
	add	a,r2
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getbyte'
;------------------------------------------------------------
;i                         Allocated to registers r5 
;j                         Allocated to registers r2 
;k                         Allocated to registers r3 
;------------------------------------------------------------
;	.\cmon51.c:168: unsigned char getbyte (void)
;	-----------------------------------------
;	 function getbyte
;	-----------------------------------------
_getbyte:
;	.\cmon51.c:170: unsigned char i, j=0, k;
	mov	r2,#0x00
;	.\cmon51.c:172: for (k=0; k<2; k++)
	mov	r3,#0x00
	mov	r4,#0x00
L010014?:
	cjne	r4,#0x02,L010031?
L010031?:
	jc	L010032?
	ljmp	L010017?
L010032?:
;	.\cmon51.c:174: i=getchar();
	push	ar2
	push	ar3
	push	ar4
	lcall	_getchar
	mov	r5,dpl
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:175: putc(i==(unsigned char)' '?'x':i);
L010001?:
	jbc	_TI,L010033?
	sjmp	L010001?
L010033?:
	clr	a
	cjne	r5,#0x20,L010034?
	inc	a
L010034?:
	mov	r6,a
	jz	L010020?
	mov	r7,#0x78
	sjmp	L010021?
L010020?:
	mov	ar7,r5
L010021?:
	mov	_SBUF,r7
;	.\cmon51.c:176: if(!isxdigit(i))
	mov	dpl,r5
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_isxdigit
	mov	a,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	jnz	L010013?
;	.\cmon51.c:178: validbyte=0;
	clr	_validbyte
;	.\cmon51.c:179: if(i==(unsigned char)' ')
	mov	a,r6
	jz	L010010?
;	.\cmon51.c:181: keepediting=1;
	setb	_keepediting
;	.\cmon51.c:182: if(k==0) putc('x');
	mov	a,r3
	jnz	L010011?
L010004?:
	jbc	_TI,L010040?
	sjmp	L010004?
L010040?:
	mov	_SBUF,#0x78
	sjmp	L010011?
L010010?:
;	.\cmon51.c:184: else keepediting=0;
	clr	_keepediting
L010011?:
;	.\cmon51.c:185: return j;
	mov	dpl,r2
	ret
L010013?:
;	.\cmon51.c:187: j=j*0x10+chartohex(i);
	mov	a,r2
	swap	a
	anl	a,#0xf0
	mov	r6,a
	mov	dpl,r5
	push	ar4
	push	ar6
	lcall	_chartohex
	mov	r5,dpl
	pop	ar6
	pop	ar4
	mov	a,r5
	add	a,r6
	mov	r2,a
;	.\cmon51.c:172: for (k=0; k<2; k++)
	inc	r4
	mov	ar3,r4
	ljmp	L010014?
L010017?:
;	.\cmon51.c:189: keepediting=1;
	setb	_keepediting
;	.\cmon51.c:190: validbyte=1;
	setb	_validbyte
;	.\cmon51.c:191: return j;
	mov	dpl,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'modifymem'
;------------------------------------------------------------
;loc                       Allocated with name '_modifymem_PARM_2'
;ptr                       Allocated to registers r2 r3 r4 
;j                         Allocated to registers r6 
;k                         Allocated to registers r5 
;------------------------------------------------------------
;	.\cmon51.c:195: void modifymem(unsigned char * ptr,  char loc)
;	-----------------------------------------
;	 function modifymem
;	-----------------------------------------
_modifymem:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	.\cmon51.c:197: unsigned char j, k=0;
	mov	r5,#0x00
;	.\cmon51.c:199: while(1)
L011034?:
;	.\cmon51.c:201: if(k==0)
	mov	a,r5
	jnz	L011016?
;	.\cmon51.c:203: putnl();
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_putnl
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:204: putc(loc);
L011001?:
	jbc	_TI,L011059?
	sjmp	L011001?
L011059?:
	mov	r6,_modifymem_PARM_2
	mov	_SBUF,r6
;	.\cmon51.c:205: putc(':');
L011004?:
	jbc	_TI,L011060?
	sjmp	L011004?
L011060?:
	mov	_SBUF,#0x3A
;	.\cmon51.c:206: if((loc=='D')||(loc=='I'))
	cjne	r6,#0x44,L011061?
	sjmp	L011007?
L011061?:
	cjne	r6,#0x49,L011008?
L011007?:
;	.\cmon51.c:207: outbyte((unsigned char)ptr);
	mov	dpl,r2
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_outbyte
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	L011011?
L011008?:
;	.\cmon51.c:209: outword((unsigned int)ptr);
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_outword
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:210: putc(':');
L011011?:
	jbc	_TI,L011064?
	sjmp	L011011?
L011064?:
	mov	_SBUF,#0x3A
;	.\cmon51.c:212: putc(' ');
L011016?:
	jbc	_TI,L011065?
	sjmp	L011016?
L011065?:
	mov	_SBUF,#0x20
;	.\cmon51.c:213: outbyte(*ptr);
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	dpl,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_outbyte
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:214: putc('.');
L011019?:
	jbc	_TI,L011066?
	sjmp	L011019?
L011066?:
	mov	_SBUF,#0x2E
;	.\cmon51.c:215: j=getbyte();
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_getbyte
	mov	r6,dpl
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:216: if((!validbyte)&&(!keepediting)) break;
	jb	_validbyte,L011023?
	jnb	_keepediting,L011035?
L011023?:
;	.\cmon51.c:217: if(validbyte) *ptr=j;
	jnb	_validbyte,L011027?
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r6
	lcall	__gptrput
;	.\cmon51.c:218: putc('\b');
L011027?:
	jbc	_TI,L011070?
	sjmp	L011027?
L011070?:
	mov	_SBUF,#0x08
;	.\cmon51.c:219: putc('\b');
L011030?:
	jbc	_TI,L011071?
	sjmp	L011030?
L011071?:
	mov	_SBUF,#0x08
;	.\cmon51.c:220: outbyte(*ptr);
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	mov	r2,dpl
	mov	r3,dph
	mov	dpl,r6
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_outbyte
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:221: ptr++;
;	.\cmon51.c:222: k++;
	inc	r5
;	.\cmon51.c:223: k&=7;
	anl	ar5,#0x07
	ljmp	L011034?
L011035?:
;	.\cmon51.c:225: putnl();
	ljmp	_putnl
;------------------------------------------------------------
;Allocation info for local variables in function 'hitanykey'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\cmon51.c:228: unsigned char hitanykey (void)
;	-----------------------------------------
;	 function hitanykey
;	-----------------------------------------
_hitanykey:
;	.\cmon51.c:230: putsp("<Space>=line <Enter>=page <ESC>=stop\r");
	mov	dptr,#__str_2
	mov	b,#0x80
	lcall	_putsp
;	.\cmon51.c:231: while (!RI);
L012001?:
	jnb	_RI,L012001?
;	.\cmon51.c:232: clearline();
	lcall	_clearline
;	.\cmon51.c:233: RI=0;
	clr	_RI
;	.\cmon51.c:234: return (SBUF);
	mov	dpl,_SBUF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dispmem'
;------------------------------------------------------------
;len                       Allocated with name '_dispmem_PARM_2'
;loc                       Allocated with name '_dispmem_PARM_3'
;begin                     Allocated with name '_dispmem_begin_1_106'
;j                         Allocated to registers r6 r7 
;n                         Allocated to registers r2 
;i                         Allocated to registers r3 
;k                         Allocated with name '_dispmem_k_1_107'
;------------------------------------------------------------
;	.\cmon51.c:238: void dispmem(unsigned char * begin,  unsigned int len, char loc)
;	-----------------------------------------
;	 function dispmem
;	-----------------------------------------
_dispmem:
	mov	_dispmem_begin_1_106,dpl
	mov	(_dispmem_begin_1_106 + 1),dph
	mov	(_dispmem_begin_1_106 + 2),b
;	.\cmon51.c:241: unsigned char n, i, k=0;
	mov	_dispmem_k_1_107,#0x00
;	.\cmon51.c:243: if(len==0) len=0x80;
	mov	a,_dispmem_PARM_2
	orl	a,(_dispmem_PARM_2 + 1)
	jnz	L013002?
	mov	_dispmem_PARM_2,#0x80
	clr	a
	mov	(_dispmem_PARM_2 + 1),a
L013002?:
;	.\cmon51.c:245: buff[16]=0;
	mov	(_buff + 0x0010),#0x00
;	.\cmon51.c:247: for(j=0; j<len; j++)
	mov	r6,#0x00
	mov	r7,#0x00
L013033?:
	clr	c
	mov	a,r6
	subb	a,_dispmem_PARM_2
	mov	a,r7
	subb	a,(_dispmem_PARM_2 + 1)
	jc	L013061?
	ret
L013061?:
;	.\cmon51.c:249: n=begin[j];
	mov	a,r6
	add	a,_dispmem_begin_1_106
	mov	r5,a
	mov	a,r7
	addc	a,(_dispmem_begin_1_106 + 1)
	mov	r2,a
	mov	r3,(_dispmem_begin_1_106 + 2)
	mov	dpl,r5
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r2,a
;	.\cmon51.c:250: i=j&0xf;
	mov	a,#0x0F
	anl	a,r6
;	.\cmon51.c:252: if(i==0)
	mov	r3,a
	mov	r4,#0x00
	jnz	L013014?
;	.\cmon51.c:254: putc(loc);  //A letter to indicate Data, Xram, Code, Idata
L013003?:
	jbc	_TI,L013063?
	sjmp	L013003?
L013063?:
	mov	r4,_dispmem_PARM_3
	mov	_SBUF,r4
;	.\cmon51.c:255: putc(':');
L013006?:
	jbc	_TI,L013064?
	sjmp	L013006?
L013064?:
	mov	_SBUF,#0x3A
;	.\cmon51.c:256: if((loc=='D')||(loc=='I'))
	cjne	r4,#0x44,L013065?
	sjmp	L013009?
L013065?:
	cjne	r4,#0x49,L013010?
L013009?:
;	.\cmon51.c:257: outbyte((unsigned char)begin+j);
	mov	r4,_dispmem_begin_1_106
	mov	a,r6
	add	a,r4
	mov	dpl,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	lcall	_outbyte
	pop	ar7
	pop	ar6
	pop	ar3
	pop	ar2
	sjmp	L013011?
L013010?:
;	.\cmon51.c:259: outword((unsigned int)begin+j);
	mov	r4,_dispmem_begin_1_106
	mov	r5,(_dispmem_begin_1_106 + 1)
	mov	a,r6
	add	a,r4
	mov	dpl,a
	mov	a,r7
	addc	a,r5
	mov	dph,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	lcall	_outword
	pop	ar7
	pop	ar6
	pop	ar3
	pop	ar2
L013011?:
;	.\cmon51.c:260: putsp(":  ");
	mov	dptr,#__str_3
	mov	b,#0x80
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	lcall	_putsp
	pop	ar7
	pop	ar6
	pop	ar3
	pop	ar2
L013014?:
;	.\cmon51.c:262: outbyte(n);
	mov	dpl,r2
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	lcall	_outbyte
	pop	ar7
	pop	ar6
	pop	ar3
	pop	ar2
;	.\cmon51.c:263: putc(i==7?'-':' '); //A middle separator like the old good DOS debug
L013015?:
	jbc	_TI,L013068?
	sjmp	L013015?
L013068?:
	cjne	r3,#0x07,L013039?
	mov	r4,#0x2D
	sjmp	L013040?
L013039?:
	mov	r4,#0x20
L013040?:
	mov	_SBUF,r4
;	.\cmon51.c:265: if((n>0x20)&&(n<0x7f))
	mov	a,r2
	add	a,#0xff - 0x20
	jnc	L013019?
	cjne	r2,#0x7F,L013072?
L013072?:
	jnc	L013019?
;	.\cmon51.c:266: buff[i]=n;
	mov	a,r3
	add	a,#_buff
	mov	r0,a
	mov	@r0,ar2
	sjmp	L013020?
L013019?:
;	.\cmon51.c:268: buff[i]='.';
	mov	a,r3
	add	a,#_buff
	mov	r0,a
	mov	@r0,#0x2E
L013020?:
;	.\cmon51.c:270: if(i==0xf)
	cjne	r3,#0x0F,L013035?
;	.\cmon51.c:272: putsp("   ");
	mov	dptr,#__str_4
	mov	b,#0x80
	push	ar6
	push	ar7
	lcall	_putsp
;	.\cmon51.c:273: putsp(buff);
	mov	dptr,#_buff
	mov	b,#0x40
	lcall	_putsp
;	.\cmon51.c:274: putnl();
	lcall	_putnl
	pop	ar7
	pop	ar6
;	.\cmon51.c:275: if((++k==23) && (j<len))
	inc	_dispmem_k_1_107
	mov	a,#0x17
	cjne	a,_dispmem_k_1_107,L013035?
	clr	c
	mov	a,r6
	subb	a,_dispmem_PARM_2
	mov	a,r7
	subb	a,(_dispmem_PARM_2 + 1)
	jnc	L013035?
;	.\cmon51.c:277: n=hitanykey();
	push	ar6
	push	ar7
	lcall	_hitanykey
	mov	r2,dpl
	pop	ar7
	pop	ar6
;	.\cmon51.c:278: if (n==0x1b) break;
	cjne	r2,#0x1B,L013079?
	ret
L013079?:
;	.\cmon51.c:279: else if (n==(unsigned char)' ') k--;
	cjne	r2,#0x20,L013023?
	dec	_dispmem_k_1_107
	sjmp	L013035?
L013023?:
;	.\cmon51.c:280: else k=0;
	mov	_dispmem_k_1_107,#0x00
L013035?:
;	.\cmon51.c:247: for(j=0; j<len; j++)
	inc	r6
	cjne	r6,#0x00,L013082?
	inc	r7
L013082?:
	ljmp	L013033?
;------------------------------------------------------------
;Allocation info for local variables in function 'cleanbuff'
;------------------------------------------------------------
;j                         Allocated to registers r2 
;k                         Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:287: void cleanbuff (void)
;	-----------------------------------------
;	 function cleanbuff
;	-----------------------------------------
_cleanbuff:
;	.\cmon51.c:291: buff_haseq=0;
	clr	_buff_haseq
;	.\cmon51.c:292: buff_hasdot=0;
	clr	_buff_hasdot
;	.\cmon51.c:295: for(j=0; j<BUFFSIZE; j++)
	mov	r2,#0x00
L014013?:
	cjne	r2,#0x20,L014044?
L014044?:
	jnc	L014016?
;	.\cmon51.c:297: buff[j]=toupper(buff[j]);
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	dpl,@r0
	push	ar2
	push	ar0
	lcall	_islower
	mov	a,dpl
	pop	ar0
	pop	ar2
	jz	L014027?
	mov	a,r2
	add	a,#_buff
	mov	r1,a
	mov	ar3,@r1
	anl	ar3,#0xDF
	sjmp	L014028?
L014027?:
	mov	a,r2
	add	a,#_buff
	mov	r1,a
	mov	ar3,@r1
L014028?:
	mov	@r0,ar3
;	.\cmon51.c:298: if(isspace(buff[j])) buff[j]=0;
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	dpl,@r0
	push	ar2
	lcall	_isspace
	mov	a,dpl
	pop	ar2
	jz	L014002?
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	@r0,#0x00
L014002?:
;	.\cmon51.c:299: if(buff[j]=='=')
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	ar3,@r0
	cjne	r3,#0x3D,L014007?
;	.\cmon51.c:301: buff[j]=0;
	mov	@r0,#0x00
;	.\cmon51.c:302: buff_haseq=1;
	setb	_buff_haseq
	sjmp	L014015?
L014007?:
;	.\cmon51.c:304: else if((buff[j]=='.')||(buff[j]=='_'))
	mov	ar3,@r0
	cjne	r3,#0x2E,L014050?
	sjmp	L014003?
L014050?:
	cjne	r3,#0x5F,L014015?
L014003?:
;	.\cmon51.c:306: buff[j]=0;
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	@r0,#0x00
;	.\cmon51.c:307: buff_hasdot=1;
	setb	_buff_hasdot
L014015?:
;	.\cmon51.c:295: for(j=0; j<BUFFSIZE; j++)
	inc	r2
	sjmp	L014013?
L014016?:
;	.\cmon51.c:312: for(j=0, k=0; j<BUFFSIZE; j++)
	mov	r2,#0x00
	mov	r3,#0x00
L014017?:
	cjne	r3,#0x20,L014053?
L014053?:
	jnc	L014040?
;	.\cmon51.c:314: buff[k]=buff[j];
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	a,r3
	add	a,#_buff
	mov	r1,a
	mov	ar4,@r1
	mov	@r0,ar4
;	.\cmon51.c:315: if( ((buff[j]!=0)||(buff[j+1]!=0)) && buff[0]!=0) k++;
	mov	a,r4
	jnz	L014012?
	mov	a,r3
	inc	a
	add	a,#_buff
	mov	r0,a
	mov	a,@r0
	jz	L014019?
L014012?:
	mov	a,_buff
	jz	L014019?
	inc	r2
L014019?:
;	.\cmon51.c:312: for(j=0, k=0; j<BUFFSIZE; j++)
	inc	r3
	sjmp	L014017?
L014040?:
L014021?:
;	.\cmon51.c:317: for(; k<BUFFSIZE; k++) buff[k]=0;
	cjne	r2,#0x20,L014058?
L014058?:
	jnc	L014025?
	mov	a,r2
	add	a,#_buff
	mov	r0,a
	mov	@r0,#0x00
	inc	r2
	sjmp	L014021?
L014025?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getwordn'
;------------------------------------------------------------
;word                      Allocated to registers r2 r3 
;------------------------------------------------------------
;	.\cmon51.c:321: unsigned int getwordn(void)
;	-----------------------------------------
;	 function getwordn
;	-----------------------------------------
_getwordn:
;	.\cmon51.c:323: unsigned int word=0;
	mov	r2,#0x00
	mov	r3,#0x00
;	.\cmon51.c:330: cursor++;
L015003?:
;	.\cmon51.c:325: for( ; buff[cursor]!=0; cursor++)
	mov	a,_cursor
	add	a,#_buff
	mov	r0,a
	mov	ar4,@r0
	cjne	r4,#0x00,L015012?
	sjmp	L015006?
L015012?:
;	.\cmon51.c:327: if(isxdigit(buff[cursor]))
	mov	dpl,r4
	push	ar2
	push	ar3
	lcall	_isxdigit
	mov	a,dpl
	pop	ar3
	pop	ar2
	jz	L015005?
;	.\cmon51.c:328: word=(word*0x10)+chartohex(buff[cursor]);
	mov	ar4,r2
	mov	a,r3
	swap	a
	anl	a,#0xf0
	xch	a,r4
	swap	a
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	anl	a,#0xf0
	xch	a,r4
	xrl	a,r4
	mov	r5,a
	mov	a,_cursor
	add	a,#_buff
	mov	r0,a
	mov	dpl,@r0
	push	ar4
	push	ar5
	lcall	_chartohex
	mov	r6,dpl
	pop	ar5
	pop	ar4
	mov	r7,#0x00
	mov	a,r6
	add	a,r4
	mov	r2,a
	mov	a,r7
	addc	a,r5
	mov	r3,a
L015005?:
;	.\cmon51.c:325: for( ; buff[cursor]!=0; cursor++)
	inc	_cursor
	sjmp	L015003?
L015006?:
;	.\cmon51.c:330: cursor++;
	inc	_cursor
;	.\cmon51.c:331: return word;
	mov	dpl,r2
	mov	dph,r3
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'showreg'
;------------------------------------------------------------
;val                       Allocated with name '_showreg_PARM_2'
;name                      Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	.\cmon51.c:334: void showreg(char * name, unsigned char val)
;	-----------------------------------------
;	 function showreg
;	-----------------------------------------
_showreg:
;	.\cmon51.c:336: putsp(name);
	lcall	_putsp
;	.\cmon51.c:337: putc('=');
L016001?:
	jbc	_TI,L016018?
	sjmp	L016001?
L016018?:
	mov	_SBUF,#0x3D
;	.\cmon51.c:338: outbyte(val);
	mov	dpl,_showreg_PARM_2
	lcall	_outbyte
;	.\cmon51.c:339: putc(' ');
L016004?:
	jbc	_TI,L016019?
	sjmp	L016004?
L016019?:
	mov	_SBUF,#0x20
;	.\cmon51.c:340: putc(' ');
L016007?:
	jbc	_TI,L016020?
	sjmp	L016007?
L016020?:
	mov	_SBUF,#0x20
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disp_regs'
;------------------------------------------------------------
;j                         Allocated to registers r4 
;bank                      Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:343: void disp_regs(void)
;	-----------------------------------------
;	 function disp_regs
;	-----------------------------------------
_disp_regs:
;	.\cmon51.c:347: putnl();
	lcall	_putnl
;	.\cmon51.c:348: showreg("  A", A_save);
	mov	dptr,#_A_save
	movx	a,@dptr
	mov	_showreg_PARM_2,a
	mov	dptr,#__str_5
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:349: showreg("  B", B_save);
	mov	dptr,#_B_save
	movx	a,@dptr
	mov	_showreg_PARM_2,a
	mov	dptr,#__str_6
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:350: showreg(" SP", SP_save);
	mov	dptr,#_SP_save
	movx	a,@dptr
	mov	_showreg_PARM_2,a
	mov	dptr,#__str_7
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:351: showreg(" IE", IE_save);
	mov	dptr,#_IE_save
	movx	a,@dptr
	mov	_showreg_PARM_2,a
	mov	dptr,#__str_8
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:352: showreg("DPH", DPH_save);
	mov	dptr,#_DPH_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	_showreg_PARM_2,r2
	mov	dptr,#__str_9
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:353: showreg("DPL", DPL_save);
	mov	dptr,#_DPL_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	_showreg_PARM_2,r2
	mov	dptr,#__str_10
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:354: showreg("PSW", PSW_save);
	mov	dptr,#_PSW_save
	movx	a,@dptr
	mov	_showreg_PARM_2,a
	mov	dptr,#__str_11
	mov	b,#0x80
	lcall	_showreg
;	.\cmon51.c:355: putsp(" PC=");
	mov	dptr,#__str_12
	mov	b,#0x80
	lcall	_putsp
;	.\cmon51.c:356: outword(PC_save);
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_outword
;	.\cmon51.c:357: putnl();
	lcall	_putnl
;	.\cmon51.c:359: bank=(PSW_save/0x8)&0x3;
	mov	dptr,#_PSW_save
	movx	a,@dptr
	swap	a
	rl	a
	anl	a,#0x1f
	mov	r2,a
	anl	ar2,#0x03
;	.\cmon51.c:360: buff[0]=' ';
	mov	_buff,#0x20
;	.\cmon51.c:361: buff[1]='R';
	mov	(_buff + 0x0001),#0x52
;	.\cmon51.c:362: buff[3]=0;
	mov	(_buff + 0x0003),#0x00
;	.\cmon51.c:363: for(j=0; j<8; j++)
	mov	a,r2
	swap	a
	rr	a
	anl	a,#0xf8
	mov	r3,a
	mov	r4,#0x00
L017004?:
	cjne	r4,#0x08,L017015?
L017015?:
	jnc	L017007?
;	.\cmon51.c:365: buff[2]='0'+j;
	mov	a,#0x30
	add	a,r4
	mov	(_buff + 0x0002),a
;	.\cmon51.c:366: showreg(buff, iram_save[j+bank*8]);
	mov	a,r3
	add	a,r4
	add	a,#_iram_save
	mov	dpl,a
	clr	a
	addc	a,#(_iram_save >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	_showreg_PARM_2,a
	mov	dptr,#_buff
	mov	b,#0x40
	push	ar2
	push	ar3
	push	ar4
	lcall	_showreg
	pop	ar4
	pop	ar3
	pop	ar2
;	.\cmon51.c:363: for(j=0; j<8; j++)
	inc	r4
	sjmp	L017004?
L017007?:
;	.\cmon51.c:368: putsp(" BANK ");
	mov	dptr,#__str_13
	mov	b,#0x80
	push	ar2
	lcall	_putsp
	pop	ar2
;	.\cmon51.c:369: putc('0'+bank);
L017001?:
	jbc	_TI,L017017?
	sjmp	L017001?
L017017?:
	mov	a,#0x30
	add	a,r2
	mov	_SBUF,a
;	.\cmon51.c:370: putnl();
	ljmp	_putnl
;------------------------------------------------------------
;Allocation info for local variables in function 'outwordnl'
;------------------------------------------------------------
;val                       Allocated to registers r2 r3 
;------------------------------------------------------------
;	.\cmon51.c:373: void outwordnl (unsigned int val)
;	-----------------------------------------
;	 function outwordnl
;	-----------------------------------------
_outwordnl:
;	.\cmon51.c:375: outword(val);
	lcall	_outword
;	.\cmon51.c:376: putnl();
	ljmp	_putnl
;------------------------------------------------------------
;Allocation info for local variables in function 'nlist'
;------------------------------------------------------------
;slist                     Allocated to registers r2 r3 r4 
;x                         Allocated to registers r5 
;q                         Allocated with name '_nlist_q_1_136'
;sloc0                     Allocated with name '_nlist_sloc0_1_0'
;------------------------------------------------------------
;	.\cmon51.c:379: unsigned char nlist (unsigned char * slist)
;	-----------------------------------------
;	 function nlist
;	-----------------------------------------
_nlist:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	.\cmon51.c:381: unsigned char x=0xff, q;
	mov	r5,#0xFF
;	.\cmon51.c:383: while(*slist)
L019006?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r6,a
	jz	L019008?
;	.\cmon51.c:385: if((*slist)>0x7f)
	mov	a,r6
	add	a,#0xff - 0x7F
	jnc	L019005?
;	.\cmon51.c:387: x=*(slist++);
	mov	ar5,r6
	inc	r2
	cjne	r2,#0x00,L019029?
	inc	r3
L019029?:
;	.\cmon51.c:388: for(q=0; (*slist<=0x7f) && (*slist==(unsigned char)buff[q]) ; q++) slist++;
	mov	_nlist_sloc0_1_0,r2
	mov	(_nlist_sloc0_1_0 + 1),r3
	mov	(_nlist_sloc0_1_0 + 2),r4
	mov	_nlist_q_1_136,#0x00
L019012?:
	mov	dpl,_nlist_sloc0_1_0
	mov	dph,(_nlist_sloc0_1_0 + 1)
	mov	b,(_nlist_sloc0_1_0 + 2)
	lcall	__gptrget
	mov  r7,a
	add	a,#0xff - 0x7F
	jc	L019026?
	mov	a,_nlist_q_1_136
	add	a,#_buff
	mov	r0,a
	mov	ar6,@r0
	mov	a,r7
	cjne	a,ar6,L019026?
	inc	_nlist_sloc0_1_0
	clr	a
	cjne	a,_nlist_sloc0_1_0,L019033?
	inc	(_nlist_sloc0_1_0 + 1)
L019033?:
	inc	_nlist_q_1_136
	sjmp	L019012?
L019026?:
	mov	r2,_nlist_sloc0_1_0
	mov	r3,(_nlist_sloc0_1_0 + 1)
	mov	r4,(_nlist_sloc0_1_0 + 2)
;	.\cmon51.c:389: if((*slist>0x7f)&&(buff[q]==0)) break;
	mov	dpl,_nlist_sloc0_1_0
	mov	dph,(_nlist_sloc0_1_0 + 1)
	mov	b,(_nlist_sloc0_1_0 + 2)
	lcall	__gptrget
	mov  r6,a
	add	a,#0xff - 0x7F
	jnc	L019005?
	mov	a,_nlist_q_1_136
	add	a,#_buff
	mov	r0,a
	mov	a,@r0
	jz	L019008?
L019005?:
;	.\cmon51.c:391: slist++;
	inc	r2
	cjne	r2,#0x00,L019006?
	inc	r3
	sjmp	L019006?
L019008?:
;	.\cmon51.c:393: if(*slist) return x;//Found one!
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	jz	L019010?
	mov	dpl,r5
;	.\cmon51.c:394: return 0xff; //What if a sfr is located at 0xff?
	ret
L019010?:
	mov	dpl,#0xFF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'breakorstep'
;------------------------------------------------------------
;n                         Allocated to registers r2 
;------------------------------------------------------------
;	.\cmon51.c:397: void breakorstep (void)
;	-----------------------------------------
;	 function breakorstep
;	-----------------------------------------
_breakorstep:
;	.\cmon51.c:401: gotbreak=0;
	mov	dptr,#_gotbreak
	clr	a
	movx	@dptr,a
;	.\cmon51.c:402: breakpoint=0;
	clr	_breakpoint
;	.\cmon51.c:403: if (trace_type)
	mov	dptr,#_trace_type
	movx	a,@dptr
	mov	r2,a
	jnz	L020038?
	ljmp	L020015?
L020038?:
;	.\cmon51.c:405: if(trace_type==1) //Run in trace mode until a breapoint is hit
	mov	dptr,#_trace_type
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x01,L020004?
;	.\cmon51.c:407: for (n=0; n<4; n++)
	mov	r2,#0x00
L020019?:
	cjne	r2,#0x04,L020041?
L020041?:
	jnc	L020004?
;	.\cmon51.c:409: if(br[n]==PC_save)
	mov	a,r2
	add	a,r2
	add	a,#_br
	mov	dpl,a
	clr	a
	addc	a,#(_br >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	a,r3
	cjne	a,ar5,L020021?
	mov	a,r4
	cjne	a,ar6,L020021?
;	.\cmon51.c:411: breakpoint=1;
	setb	_breakpoint
L020021?:
;	.\cmon51.c:407: for (n=0; n<4; n++)
	inc	r2
	sjmp	L020019?
L020004?:
;	.\cmon51.c:415: if ((break_address!=PC_save))
	mov	dptr,#_break_address
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	a,r2
	cjne	a,ar4,L020045?
	mov	a,r3
	cjne	a,ar5,L020045?
	sjmp	L020015?
L020045?:
;	.\cmon51.c:417: if (trace_type>=2)
	mov	dptr,#_trace_type
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x02,L020046?
L020046?:
	jc	L020006?
;	.\cmon51.c:419: discnt=1;
	mov	_discnt,#0x01
	clr	a
	mov	(_discnt + 1),a
;	.\cmon51.c:420: unassemble(step_start); //The executed assembly instruction...
	mov	dptr,#_step_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_unassemble
L020006?:
;	.\cmon51.c:422: if((RI==0)&&(breakpoint==0))
	jb	_RI,L020015?
	jb	_breakpoint,L020015?
;	.\cmon51.c:424: if(trace_type==3) disp_regs();
	mov	dptr,#_trace_type
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x03,L020008?
	lcall	_disp_regs
L020008?:
;	.\cmon51.c:425: step_start=PC_save;
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_step_start
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
;	.\cmon51.c:426: dostep();
	lcall	_dostep
L020015?:
;	.\cmon51.c:430: if((trace_type>=2) && (RI==0))
	mov	dptr,#_trace_type
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x02,L020052?
L020052?:
	jc	L020017?
	jb	_RI,L020017?
;	.\cmon51.c:432: discnt=1;
	mov	_discnt,#0x01
	clr	a
	mov	(_discnt + 1),a
;	.\cmon51.c:433: unassemble(step_start); //The executed assembly instruction...
	mov	dptr,#_step_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_unassemble
L020017?:
;	.\cmon51.c:435: RI=0; //So the character does not show in the terminal
	clr	_RI
;	.\cmon51.c:437: disp_regs();
	lcall	_disp_regs
;	.\cmon51.c:438: discnt=1;
	mov	_discnt,#0x01
	clr	a
	mov	(_discnt + 1),a
;	.\cmon51.c:439: unassemble(PC_save); //The next assembly instruction...
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	ljmp	_unassemble
;------------------------------------------------------------
;Allocation info for local variables in function 'do_cmd'
;------------------------------------------------------------
;i                         Allocated with name '_do_cmd_i_1_150'
;j                         Allocated with name '_do_cmd_j_1_150'
;n                         Allocated with name '_do_cmd_n_1_150'
;p                         Allocated to registers r4 r5 
;q                         Allocated with name '_do_cmd_q_1_150'
;c                         Allocated to registers r6 
;d                         Allocated with name '_do_cmd_d_1_150'
;x                         Allocated to registers r7 
;y                         Allocated with name '_do_cmd_y_1_150'
;cmd                       Allocated with name '_do_cmd_cmd_1_150'
;sloc0                     Allocated with name '_do_cmd_sloc0_1_0'
;------------------------------------------------------------
;	.\cmon51.c:442: void do_cmd (void)
;	-----------------------------------------
;	 function do_cmd
;	-----------------------------------------
_do_cmd:
;	.\cmon51.c:449: if (gotbreak!=1) //Power-on reset
	mov	dptr,#_gotbreak
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x01,L021180?
	sjmp	L021002?
L021180?:
;	.\cmon51.c:451: putsp(BANNER);
	mov	dptr,#__str_14
	mov	b,#0x80
	lcall	_putsp
;	.\cmon51.c:452: cpuid();
	lcall	_cpuid
;	.\cmon51.c:453: SP_save=7; //Default user stack location
	mov	dptr,#_SP_save
	mov	a,#0x07
	movx	@dptr,a
;	.\cmon51.c:454: restorePC();
	lcall	_restorePC
;	.\cmon51.c:455: cmd=0;
	mov	_do_cmd_cmd_1_150,#0x00
	sjmp	L021123?
L021002?:
;	.\cmon51.c:457: else breakorstep(); //Got here from the beak/step interrupt
	lcall	_breakorstep
;	.\cmon51.c:459: while(1)
L021123?:
;	.\cmon51.c:461: putsp("> ");
	mov	dptr,#__str_1
	mov	b,#0x80
	lcall	_putsp
;	.\cmon51.c:462: fillmem(buff, BUFFSIZE, 0);;
	mov	_fillmem_PARM_2,#0x20
	clr	a
	mov	(_fillmem_PARM_2 + 1),a
	mov	_fillmem_PARM_3,#0x00
	mov	dptr,#_buff
	mov	b,#0x40
	lcall	_fillmem
;	.\cmon51.c:463: getsn();
	lcall	_getsn
;	.\cmon51.c:464: cleanbuff();
	lcall	_cleanbuff
;	.\cmon51.c:465: break_address=0;
	mov	dptr,#_break_address
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	.\cmon51.c:466: trace_type=0;
	mov	dptr,#_trace_type
	clr	a
	movx	@dptr,a
;	.\cmon51.c:469: cursor=0;
	mov	_cursor,#0x00
;	.\cmon51.c:470: getwordn();   //skip the command name
	lcall	_getwordn
;	.\cmon51.c:471: n=getwordn(); //n is the first parameter/number
	lcall	_getwordn
	mov	_do_cmd_n_1_150,dpl
	mov	(_do_cmd_n_1_150 + 1),dph
;	.\cmon51.c:472: p=getwordn(); //p is the second parameter/number
	lcall	_getwordn
	mov	r4,dpl
	mov	r5,dph
;	.\cmon51.c:473: q=getwordn(); //q is the third parameter/number
	push	ar4
	push	ar5
	lcall	_getwordn
	mov	_do_cmd_q_1_150,dpl
	mov	(_do_cmd_q_1_150 + 1),dph
	pop	ar5
	pop	ar4
;	.\cmon51.c:474: i=n&0xfff0;
	mov	a,#0xF0
	anl	a,_do_cmd_n_1_150
	mov	_do_cmd_i_1_150,a
	mov	(_do_cmd_i_1_150 + 1),(_do_cmd_n_1_150 + 1)
;	.\cmon51.c:475: j=(p+15)&0xfff0;
	mov	a,#0x0F
	add	a,r4
	mov	r6,a
	clr	a
	addc	a,r5
	mov	r7,a
	mov	a,#0xF0
	anl	a,r6
	mov	_do_cmd_j_1_150,a
	mov	(_do_cmd_j_1_150 + 1),r7
;	.\cmon51.c:476: c=n; // Sometimes for the first parameter we need an unsigned char
	mov	r6,_do_cmd_n_1_150
;	.\cmon51.c:478: cmd=nlist(cmdlst)&0x7f;
	mov	dptr,#_cmdlst
	mov	b,#0x80
	push	ar4
	push	ar5
	push	ar6
	lcall	_nlist
	mov	a,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	anl	a,#0x7F
	mov	_do_cmd_cmd_1_150,a
;	.\cmon51.c:480: switch(cmd)
	mov	a,_do_cmd_cmd_1_150
	mov	r7,a
	add	a,#0xff - 0x23
	jnc	L021181?
	ljmp	L021054?
L021181?:
	mov	a,r7
L021184?:
	add	a,#(L021182?-3-L021184?)
	movc	a,@a+pc
	push	acc
	mov	a,r7
L021185?:
	add	a,#(L021183?-3-L021185?)
	movc	a,@a+pc
	push	acc
	ret
L021182?:
	db	L021005?
	db	L021006?
	db	L021007?
	db	L021008?
	db	L021009?
	db	L021010?
	db	L021011?
	db	L021012?
	db	L021013?
	db	L021014?
	db	L021015?
	db	L021021?
	db	L021022?
	db	L021023?
	db	L021024?
	db	L021025?
	db	L021029?
	db	L021017?
	db	L021033?
	db	L021034?
	db	L021035?
	db	L021036?
	db	L021037?
	db	L021038?
	db	L021039?
	db	L021040?
	db	L021016?
	db	L021020?
	db	L021044?
	db	L021045?
	db	L021046?
	db	L021047?
	db	L021052?
	db	L021051?
	db	L021053?
	db	L021004?
L021183?:
	db	L021005?>>8
	db	L021006?>>8
	db	L021007?>>8
	db	L021008?>>8
	db	L021009?>>8
	db	L021010?>>8
	db	L021011?>>8
	db	L021012?>>8
	db	L021013?>>8
	db	L021014?>>8
	db	L021015?>>8
	db	L021021?>>8
	db	L021022?>>8
	db	L021023?>>8
	db	L021024?>>8
	db	L021025?>>8
	db	L021029?>>8
	db	L021017?>>8
	db	L021033?>>8
	db	L021034?>>8
	db	L021035?>>8
	db	L021036?>>8
	db	L021037?>>8
	db	L021038?>>8
	db	L021039?>>8
	db	L021040?>>8
	db	L021016?>>8
	db	L021020?>>8
	db	L021044?>>8
	db	L021045?>>8
	db	L021046?>>8
	db	L021047?>>8
	db	L021052?>>8
	db	L021051?>>8
	db	L021053?>>8
	db	L021004?>>8
;	.\cmon51.c:482: case ID_nothing:
L021004?:
;	.\cmon51.c:483: break;
	ljmp	L021123?
;	.\cmon51.c:485: case ID_display_data:
L021005?:
;	.\cmon51.c:486: dispmem(iram_save, 0, 'D');
	clr	a
	mov	_dispmem_PARM_2,a
	mov	(_dispmem_PARM_2 + 1),a
	mov	_dispmem_PARM_3,#0x44
	mov	dptr,#_iram_save
	mov	b,#0x00
	lcall	_dispmem
;	.\cmon51.c:487: break;
	ljmp	L021123?
;	.\cmon51.c:489: case ID_modify_data:
L021006?:
;	.\cmon51.c:490: modifymem(&iram_save[n&0x7f], 'D');
	mov	a,#0x7F
	anl	a,_do_cmd_n_1_150
	mov	r2,#0x00
	add	a,#_iram_save
	mov	r7,a
	mov	a,r2
	addc	a,#(_iram_save >> 8)
	mov	r2,a
	mov	r3,#0x00
	mov	_modifymem_PARM_2,#0x44
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	_modifymem
;	.\cmon51.c:491: break;
	ljmp	L021123?
;	.\cmon51.c:493: case ID_fill_data:
L021007?:
;	.\cmon51.c:494: fillmem(&iram_save[n&0x7f], (p>0x80)?0x80:p, (unsigned char) q);
	mov	a,#0x7F
	anl	a,_do_cmd_n_1_150
	mov	r3,#0x00
	add	a,#_iram_save
	mov	r2,a
	mov	a,r3
	addc	a,#(_iram_save >> 8)
	mov	r3,a
	mov	r7,#0x00
	clr	c
	mov	a,#0x80
	subb	a,r4
	clr	a
	subb	a,r5
	jnc	L021131?
	mov	_do_cmd_sloc0_1_0,#0x80
	clr	a
	mov	(_do_cmd_sloc0_1_0 + 1),a
	sjmp	L021132?
L021131?:
	mov	_do_cmd_sloc0_1_0,r4
	mov	(_do_cmd_sloc0_1_0 + 1),r5
L021132?:
	mov	_fillmem_PARM_3,_do_cmd_q_1_150
	mov	_fillmem_PARM_2,_do_cmd_sloc0_1_0
	mov	(_fillmem_PARM_2 + 1),(_do_cmd_sloc0_1_0 + 1)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_fillmem
;	.\cmon51.c:495: break;
	ljmp	L021123?
;	.\cmon51.c:497: case ID_display_idata:
L021008?:
;	.\cmon51.c:498: dispmem((unsigned char data *)(0x80), 0, 'I');
	clr	a
	mov	_dispmem_PARM_2,a
	mov	(_dispmem_PARM_2 + 1),a
	mov	_dispmem_PARM_3,#0x49
	mov	dptr,#0x4080
	mov	b,#0x00
	lcall	_dispmem
;	.\cmon51.c:499: break;
	ljmp	L021123?
;	.\cmon51.c:501: case ID_modify_idata:
L021009?:
;	.\cmon51.c:502: modifymem((unsigned char data *)((n&0x7f)|0x80), 'I');
	mov	a,#0x7F
	anl	a,_do_cmd_n_1_150
	mov	r2,a
	orl	ar2,#0x80
	mov	r3,#0x00
	mov	r7,#0x40
	mov	_modifymem_PARM_2,#0x49
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_modifymem
;	.\cmon51.c:503: break;
	ljmp	L021123?
;	.\cmon51.c:505: case ID_fill_idata:
L021010?:
;	.\cmon51.c:506: fillmem((unsigned char data *)((n&0x7f)|0x80), p>0x80?0x80:p, (unsigned char) q);
	mov	a,#0x7F
	anl	a,_do_cmd_n_1_150
	mov	r2,a
	orl	ar2,#0x80
	mov	r3,#0x00
	mov	r7,#0x40
	clr	c
	mov	a,#0x80
	subb	a,r4
	clr	a
	subb	a,r5
	jnc	L021133?
	mov	_do_cmd_sloc0_1_0,#0x80
	clr	a
	mov	(_do_cmd_sloc0_1_0 + 1),a
	sjmp	L021134?
L021133?:
	mov	_do_cmd_sloc0_1_0,r4
	mov	(_do_cmd_sloc0_1_0 + 1),r5
L021134?:
	mov	_fillmem_PARM_3,_do_cmd_q_1_150
	mov	_fillmem_PARM_2,_do_cmd_sloc0_1_0
	mov	(_fillmem_PARM_2 + 1),(_do_cmd_sloc0_1_0 + 1)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_fillmem
;	.\cmon51.c:507: break;
	ljmp	L021123?
;	.\cmon51.c:509: case ID_display_xdata:
L021011?:
;	.\cmon51.c:510: dispmem((unsigned char xdata *)i, j, 'X');
	mov	r2,_do_cmd_i_1_150
	mov	r3,(_do_cmd_i_1_150 + 1)
	mov	r7,#0x00
	mov	_dispmem_PARM_2,_do_cmd_j_1_150
	mov	(_dispmem_PARM_2 + 1),(_do_cmd_j_1_150 + 1)
	mov	_dispmem_PARM_3,#0x58
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_dispmem
;	.\cmon51.c:511: break;
	ljmp	L021123?
;	.\cmon51.c:513: case ID_modify_xdata:
L021012?:
;	.\cmon51.c:514: modifymem((unsigned char xdata *)n, 'X');
	mov	r2,_do_cmd_n_1_150
	mov	r3,(_do_cmd_n_1_150 + 1)
	mov	r7,#0x00
	mov	_modifymem_PARM_2,#0x58
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_modifymem
;	.\cmon51.c:515: break;
	ljmp	L021123?
;	.\cmon51.c:517: case ID_fill_xdata:
L021013?:
;	.\cmon51.c:518: fillmem((unsigned char xdata *)n, p, (unsigned char)q);
	mov	r2,_do_cmd_n_1_150
	mov	r3,(_do_cmd_n_1_150 + 1)
	mov	r7,#0x00
	mov	_fillmem_PARM_3,_do_cmd_q_1_150
	mov	_fillmem_PARM_2,r4
	mov	(_fillmem_PARM_2 + 1),r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_fillmem
;	.\cmon51.c:519: break;
	ljmp	L021123?
;	.\cmon51.c:521: case ID_display_code:
L021014?:
;	.\cmon51.c:522: dispmem((unsigned char code *)i, j, 'C');
	mov	r2,_do_cmd_i_1_150
	mov	r3,(_do_cmd_i_1_150 + 1)
	mov	r7,#0x80
	mov	_dispmem_PARM_2,_do_cmd_j_1_150
	mov	(_dispmem_PARM_2 + 1),(_do_cmd_j_1_150 + 1)
	mov	_dispmem_PARM_3,#0x43
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	_dispmem
;	.\cmon51.c:523: break;
	ljmp	L021123?
;	.\cmon51.c:525: case ID_unassemble:
L021015?:
;	.\cmon51.c:526: discnt=p;
	mov	_discnt,r4
	mov	(_discnt + 1),r5
;	.\cmon51.c:527: unassemble(n);
	mov	dpl,_do_cmd_n_1_150
	mov	dph,(_do_cmd_n_1_150 + 1)
	lcall	_unassemble
;	.\cmon51.c:528: break;
	ljmp	L021123?
;	.\cmon51.c:530: case ID_trace_reg:
L021016?:
;	.\cmon51.c:531: trace_type++;
	mov	dptr,#_trace_type
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
;	.\cmon51.c:533: case ID_trace:
L021017?:
;	.\cmon51.c:534: trace_type++;
	mov	dptr,#_trace_type
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
;	.\cmon51.c:535: if(n==0) break;
	mov	a,_do_cmd_n_1_150
	orl	a,(_do_cmd_n_1_150 + 1)
	jnz	L021188?
	ljmp	L021123?
L021188?:
;	.\cmon51.c:536: break_address=n;
	mov	dptr,#_break_address
	mov	a,_do_cmd_n_1_150
	movx	@dptr,a
	inc	dptr
	mov	a,(_do_cmd_n_1_150 + 1)
	movx	@dptr,a
;	.\cmon51.c:537: n=0;
	clr	a
	mov	_do_cmd_n_1_150,a
	mov	(_do_cmd_n_1_150 + 1),a
;	.\cmon51.c:539: case ID_go_breaks:
L021020?:
;	.\cmon51.c:540: trace_type++;
	mov	dptr,#_trace_type
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
;	.\cmon51.c:542: case ID_go:
L021021?:
;	.\cmon51.c:543: case ID_step:
L021022?:
;	.\cmon51.c:544: step_start=(n==0)?PC_save:n; //Next instruction to be executed
	mov	a,_do_cmd_n_1_150
	orl	a,(_do_cmd_n_1_150 + 1)
	cjne	a,#0x01,L021189?
L021189?:
	clr	a
	rlc	a
	mov	r2,a
	jz	L021135?
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	sjmp	L021136?
L021135?:
	mov	r2,_do_cmd_n_1_150
	mov	r3,(_do_cmd_n_1_150 + 1)
L021136?:
	mov	dptr,#_step_start
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
;	.\cmon51.c:545: gotbreak=0; //If changes to 1, the single step function worked!
	mov	dptr,#_gotbreak
	clr	a
	movx	@dptr,a
;	.\cmon51.c:546: gostep=(cmd==ID_go)?1:0;
	mov	a,#0x0B
	cjne	a,_do_cmd_cmd_1_150,L021137?
	mov	r2,#0x01
	sjmp	L021138?
L021137?:
	mov	r2,#0x00
L021138?:
	mov	dptr,#_gostep
	mov	a,r2
	movx	@dptr,a
;	.\cmon51.c:547: dostep();
	lcall	_dostep
;	.\cmon51.c:548: break;
	ljmp	L021123?
;	.\cmon51.c:550: case ID_registers:
L021023?:
;	.\cmon51.c:551: disp_regs();
	lcall	_disp_regs
;	.\cmon51.c:552: break;
	ljmp	L021123?
;	.\cmon51.c:554: case ID_load:
L021024?:
;	.\cmon51.c:555: loadintelhex();
	lcall	_loadintelhex
;	.\cmon51.c:556: break;
	ljmp	L021123?
;	.\cmon51.c:558: case ID_reg_dptr:
L021025?:
;	.\cmon51.c:559: if(buff_haseq)
	jnb	_buff_haseq,L021027?
;	.\cmon51.c:561: DPL_save=c;
	mov	dptr,#_DPL_save
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
;	.\cmon51.c:562: DPH_save=highof(n);
	mov	r2,(_do_cmd_n_1_150 + 1)
	mov	r3,#0x00
	mov	dptr,#_DPH_save
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	ljmp	L021123?
L021027?:
;	.\cmon51.c:564: else outwordnl((DPH_save*0x100)+DPL_save);
	mov	dptr,#_DPH_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	(_do_cmd_sloc0_1_0 + 1),r2
	mov	_do_cmd_sloc0_1_0,#0x00
	mov	dptr,#_DPL_save
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r2,a
	mov	a,r7
	add	a,_do_cmd_sloc0_1_0
	mov	dpl,a
	mov	a,r2
	addc	a,(_do_cmd_sloc0_1_0 + 1)
	mov	dph,a
	lcall	_outwordnl
;	.\cmon51.c:565: break;
	ljmp	L021123?
;	.\cmon51.c:567: case ID_reg_pc:
L021029?:
;	.\cmon51.c:568: if(buff_haseq) PC_save=n;
	jnb	_buff_haseq,L021031?
	mov	dptr,#_PC_save
	mov	a,_do_cmd_n_1_150
	movx	@dptr,a
	inc	dptr
	mov	a,(_do_cmd_n_1_150 + 1)
	movx	@dptr,a
	ljmp	L021123?
L021031?:
;	.\cmon51.c:569: else outwordnl(PC_save);
	mov	dptr,#_PC_save
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_outwordnl
;	.\cmon51.c:570: break;
	ljmp	L021123?
;	.\cmon51.c:572: case ID_reg_r0:
L021033?:
;	.\cmon51.c:573: case ID_reg_r1:
L021034?:
;	.\cmon51.c:574: case ID_reg_r2:
L021035?:
;	.\cmon51.c:575: case ID_reg_r3:
L021036?:
;	.\cmon51.c:576: case ID_reg_r4:
L021037?:
;	.\cmon51.c:577: case ID_reg_r5:
L021038?:
;	.\cmon51.c:578: case ID_reg_r6:
L021039?:
;	.\cmon51.c:579: case ID_reg_r7:
L021040?:
;	.\cmon51.c:580: d=(PSW_save&0x18)+buff[1]-'0';
	mov	dptr,#_PSW_save
	movx	a,@dptr
	mov	r2,a
	anl	ar2,#0x18
	mov	a,(_buff + 0x0001)
	add	a,r2
	add	a,#0xd0
	mov	r2,a
;	.\cmon51.c:581: if(buff_haseq) iram_save[d]=c;
	jnb	_buff_haseq,L021042?
	mov	a,r2
	add	a,#_iram_save
	mov	dpl,a
	clr	a
	addc	a,#(_iram_save >> 8)
	mov	dph,a
	mov	a,r6
	movx	@dptr,a
	ljmp	L021123?
L021042?:
;	.\cmon51.c:582: else { outbyte (iram_save[d]); putnl(); };
	mov	a,r2
	add	a,#_iram_save
	mov	dpl,a
	clr	a
	addc	a,#(_iram_save >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dpl,a
	lcall	_outbyte
	lcall	_putnl
;	.\cmon51.c:583: break;
	ljmp	L021123?
;	.\cmon51.c:585: case ID_br0:
L021044?:
;	.\cmon51.c:586: case ID_br1:
L021045?:
;	.\cmon51.c:587: case ID_br2:
L021046?:
;	.\cmon51.c:588: case ID_br3:
L021047?:
;	.\cmon51.c:589: d=buff[2]-'0';
	mov	a,(_buff + 0x0002)
	add	a,#0xd0
	mov	r2,a
;	.\cmon51.c:590: if(buff_haseq) br[d]=n;
	jnb	_buff_haseq,L021049?
	mov	a,r2
	add	a,r2
	mov	r3,a
	add	a,#_br
	mov	dpl,a
	clr	a
	addc	a,#(_br >> 8)
	mov	dph,a
	mov	a,_do_cmd_n_1_150
	movx	@dptr,a
	inc	dptr
	mov	a,(_do_cmd_n_1_150 + 1)
	movx	@dptr,a
	ljmp	L021123?
L021049?:
;	.\cmon51.c:591: else outwordnl(br[d]);
	mov	a,r2
	add	a,r2
	add	a,#_br
	mov	dpl,a
	clr	a
	addc	a,#(_br >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r3
	mov	dph,r7
	lcall	_outwordnl
;	.\cmon51.c:592: break;
	ljmp	L021123?
;	.\cmon51.c:594: case ID_br:
L021051?:
;	.\cmon51.c:595: for(d=0; d<4; d++) outwordnl(br[d]);
	mov	_do_cmd_d_1_150,#0x00
L021125?:
	mov	a,#0x100 - 0x04
	add	a,_do_cmd_d_1_150
	jnc	L021197?
	ljmp	L021123?
L021197?:
	mov	a,_do_cmd_d_1_150
	add	a,_do_cmd_d_1_150
	add	a,#_br
	mov	dpl,a
	clr	a
	addc	a,#(_br >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r7
	mov	dph,r3
	lcall	_outwordnl
	inc	_do_cmd_d_1_150
;	.\cmon51.c:598: case ID_brc:
	sjmp	L021125?
L021052?:
;	.\cmon51.c:599: fillmem((unsigned char xdata *)br, 8, 0);
	mov	_fillmem_PARM_2,#0x08
	clr	a
	mov	(_fillmem_PARM_2 + 1),a
	mov	_fillmem_PARM_3,#0x00
	mov	dptr,#_br
	mov	b,#0x00
	lcall	_fillmem
;	.\cmon51.c:600: break;
	ljmp	L021123?
;	.\cmon51.c:602: case ID_pcr:  //Restore the PC
L021053?:
;	.\cmon51.c:603: restorePC();
	lcall	_restorePC
;	.\cmon51.c:604: break;
	ljmp	L021123?
;	.\cmon51.c:606: default:
L021054?:
;	.\cmon51.c:608: y=nlist(bitn); //Search for bit names first
	mov	dptr,#_bitn
	mov	b,#0x80
	push	ar4
	push	ar5
	push	ar6
	lcall	_nlist
	mov	_do_cmd_y_1_150,dpl
	pop	ar6
	pop	ar5
	pop	ar4
;	.\cmon51.c:609: if (y!=0xff)
	mov	a,#0xFF
	cjne	a,_do_cmd_y_1_150,L021198?
	sjmp	L021058?
L021198?:
;	.\cmon51.c:611: x=y&0xf8;
	mov	a,#0xF8
	anl	a,_do_cmd_y_1_150
	mov	r7,a
;	.\cmon51.c:612: y=maskbit[y&0x7];
	mov	a,#0x07
	anl	a,_do_cmd_y_1_150
	mov	dptr,#_maskbit
	movc	a,@a+dptr
	mov	_do_cmd_y_1_150,a
	sjmp	L021059?
L021058?:
;	.\cmon51.c:616: x=nlist(sfrn); //Is not a bit, try a sfr
	mov	dptr,#_sfrn
	mov	b,#0x80
	push	ar4
	push	ar5
	push	ar6
	lcall	_nlist
	mov	r7,dpl
	pop	ar6
	pop	ar5
	pop	ar4
;	.\cmon51.c:617: if(buff_hasdot)
	jnb	_buff_hasdot,L021059?
;	.\cmon51.c:619: y=maskbit[c&0x7];
	mov	a,#0x07
	anl	a,r6
	mov	dptr,#_maskbit
	movc	a,@a+dptr
	mov	_do_cmd_y_1_150,a
;	.\cmon51.c:620: c=p;
	mov	ar6,r4
L021059?:
;	.\cmon51.c:624: if(x!=0xff)
	cjne	r7,#0xFF,L021200?
	ljmp	L021119?
L021200?:
;	.\cmon51.c:627: /**/ if (x==0xd0) d=PSW_save;
	clr	a
	cjne	r7,#0xD0,L021201?
	inc	a
L021201?:
	mov	r4,a
	jz	L021079?
	mov	dptr,#_PSW_save
	movx	a,@dptr
	mov	r2,a
	sjmp	L021080?
L021079?:
;	.\cmon51.c:628: else if (x==0xe0) d=A_save;
	cjne	r7,#0xE0,L021076?
	mov	dptr,#_A_save
	movx	a,@dptr
	mov	r2,a
	sjmp	L021080?
L021076?:
;	.\cmon51.c:629: else if (x==0xf0) d=B_save;
	cjne	r7,#0xF0,L021073?
	mov	dptr,#_B_save
	movx	a,@dptr
	mov	r2,a
	sjmp	L021080?
L021073?:
;	.\cmon51.c:630: else if (x==0xa8) d=IE_save;
	cjne	r7,#0xA8,L021070?
	mov	dptr,#_IE_save
	movx	a,@dptr
	mov	r2,a
	sjmp	L021080?
L021070?:
;	.\cmon51.c:631: else if (x==0x81) d=SP_save;
	cjne	r7,#0x81,L021067?
	mov	dptr,#_SP_save
	movx	a,@dptr
	mov	r2,a
	sjmp	L021080?
L021067?:
;	.\cmon51.c:632: else if (x==0x82) d=DPL_save;
	cjne	r7,#0x82,L021064?
	mov	dptr,#_DPL_save
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	ar2,r5
	sjmp	L021080?
L021064?:
;	.\cmon51.c:633: else if (x==0x83) d=DPH_save;
	cjne	r7,#0x83,L021061?
	mov	dptr,#_DPH_save
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	ar2,r3
	sjmp	L021080?
L021061?:
;	.\cmon51.c:634: else d=read_sfr(x);
	mov	dpl,r7
	push	ar4
	push	ar6
	push	ar7
	lcall	_read_sfr
	mov	r2,dpl
	pop	ar7
	pop	ar6
	pop	ar4
L021080?:
;	.\cmon51.c:637: if(y!=0xff)
	mov	a,#0xFF
	cjne	a,_do_cmd_y_1_150,L021216?
	mov	a,#0x01
	sjmp	L021217?
L021216?:
	clr	a
L021217?:
	mov	r3,a
	jnz	L021085?
;	.\cmon51.c:639: if(c) c=d|y;
	mov	a,r6
	jz	L021082?
	mov	a,_do_cmd_y_1_150
	orl	a,r2
	mov	r6,a
	sjmp	L021085?
L021082?:
;	.\cmon51.c:640: else c=d&(~y);
	mov	a,_do_cmd_y_1_150
	cpl	a
	mov	r5,a
	anl	a,r2
	mov	r6,a
L021085?:
;	.\cmon51.c:644: if(x==0xB0) c=(P3&0x3)|(c&0xfc);
	cjne	r7,#0xB0,L021087?
	mov	a,#0x03
	anl	a,_P3
	mov	r5,a
	mov	a,#0xFC
	anl	a,r6
	orl	a,r5
	mov	r6,a
L021087?:
;	.\cmon51.c:647: if(buff_haseq)
	jnb	_buff_haseq,L021116?
;	.\cmon51.c:649: /**/ if (x==0xd0) PSW_save=c;
	mov	a,r4
	jz	L021107?
	mov	dptr,#_PSW_save
	mov	a,r6
	movx	@dptr,a
	ljmp	L021123?
L021107?:
;	.\cmon51.c:650: else if (x==0xe0) A_save=c;
	cjne	r7,#0xE0,L021104?
	mov	dptr,#_A_save
	mov	a,r6
	movx	@dptr,a
	ljmp	L021123?
L021104?:
;	.\cmon51.c:651: else if (x==0xf0) B_save=c;
	cjne	r7,#0xF0,L021101?
	mov	dptr,#_B_save
	mov	a,r6
	movx	@dptr,a
	ljmp	L021123?
L021101?:
;	.\cmon51.c:652: else if (x==0xa8) IE_save=c;
	cjne	r7,#0xA8,L021098?
	mov	dptr,#_IE_save
	mov	a,r6
	movx	@dptr,a
	ljmp	L021123?
L021098?:
;	.\cmon51.c:653: else if (x==0x81) SP_save=c;
	cjne	r7,#0x81,L021095?
	mov	dptr,#_SP_save
	mov	a,r6
	movx	@dptr,a
	ljmp	L021123?
L021095?:
;	.\cmon51.c:654: else if (x==0x82) DPL_save=c;
	cjne	r7,#0x82,L021092?
	mov	dptr,#_DPL_save
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	ljmp	L021123?
L021092?:
;	.\cmon51.c:655: else if (x==0x83) DPH_save=c;
	cjne	r7,#0x83,L021089?
	mov	dptr,#_DPH_save
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	ljmp	L021123?
L021089?:
;	.\cmon51.c:656: else write_sfr(c);
	mov	dpl,r6
	lcall	_write_sfr
	ljmp	L021123?
L021116?:
;	.\cmon51.c:660: if(y==0xff)
	mov	a,r3
	jz	L021109?
;	.\cmon51.c:661: outbyte(d);
	mov	dpl,r2
	lcall	_outbyte
;	.\cmon51.c:663: putc((d&y)?'1':'0');
	sjmp	L021114?
L021109?:
	jbc	_TI,L021237?
	sjmp	L021109?
L021237?:
	mov	a,_do_cmd_y_1_150
	anl	a,r2
	jz	L021139?
	mov	r2,#0x31
	sjmp	L021140?
L021139?:
	mov	r2,#0x30
L021140?:
	mov	_SBUF,r2
L021114?:
;	.\cmon51.c:664: putnl();
	lcall	_putnl
	ljmp	L021123?
L021119?:
;	.\cmon51.c:667: else putsp("What?\n");
	mov	dptr,#__str_15
	mov	b,#0x80
	lcall	_putsp
;	.\cmon51.c:669: }
	ljmp	L021123?
	rseg R_CSEG

	rseg R_CONST
_cmdlst:
	db 0x80
	db 'D'
	db 0x81
	db 'MD'
	db 0x82
	db 'FD'
	db 0x83
	db 'I'
	db 0x84
	db 'MI'
	db 0x85
	db 'FI'
	db 0x86
	db 'X'
	db 0x87
	db 'MX'
	db 0x88
	db 'FX'
	db 0x89
	db 'C'
	db 0x8A
	db 'U'
	db 0x8B
	db 'G'
	db 0x8C
	db 'S'
	db 0x8D
	db 'R'
	db 0x8E
	db 'L'
	db 0x8F
	db 'DPTR'
	db 0x90
	db 'PC'
	db 0x91
	db 'T'
	db 0x92
	db 'R0'
	db 0x93
	db 'R1'
	db 0x94
	db 'R2'
	db 0x95
	db 'R3'
	db 0x96
	db 'R'
	db '4'
	db 0x97
	db 'R5'
	db 0x98
	db 'R6'
	db 0x99
	db 'R7'
	db 0x9A
	db 'TR'
	db 0x9B
	db 'GB'
	db 0x9C
	db 'BR0'
	db 0x9D
	db 'BR1'
	db 0x9E
	db 'BR2'
	db 0x9F
	db 'BR3'
	db 0xA0
	db 'BRC'
	db 0xA1
	db 'BR'
	db 0xA2
	db 'PCR'
	db 0xA3
	db 0xA4
	db 0x00
	db 0x00
_hexval:
	db '0123456789ABCDEF'
	db 0x00
_maskbit:
	db 0x01	; 1 
	db 0x02	; 2 
	db 0x04	; 4 
	db 0x08	; 8 
	db 0x10	; 16 
	db 0x20	; 32 
	db 0x40	; 64 
	db 0x80	; 128 	€
__str_0:
	db 0x08
	db ' '
	db 0x08
	db 0x00
__str_1:
	db '> '
	db 0x00
__str_2:
	db '<Space>=line <Enter>=page <ESC>=stop'
	db 0x0D
	db 0x00
__str_3:
	db ':  '
	db 0x00
__str_4:
	db '   '
	db 0x00
__str_5:
	db '  A'
	db 0x00
__str_6:
	db '  B'
	db 0x00
__str_7:
	db ' SP'
	db 0x00
__str_8:
	db ' IE'
	db 0x00
__str_9:
	db 'DPH'
	db 0x00
__str_10:
	db 'DPL'
	db 0x00
__str_11:
	db 'PSW'
	db 0x00
__str_12:
	db ' PC='
	db 0x00
__str_13:
	db ' BANK '
	db 0x00
__str_14:
	db 0x0A
	db 0x0A
	db 'CMON51 V2.0'
	db 0x0A
	db 'CopyRight (c) 2005-2013 Jesus Calvino-Fraga'
	db 0x0A
	db 0x00
__str_15:
	db 'What?'
	db 0x0A
	db 0x00

	rseg R_XINIT

	CSEG

end
