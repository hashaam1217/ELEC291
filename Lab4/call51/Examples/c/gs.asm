;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1005 (Jun 25 2012) (MSVC)
; This file was generated Tue Jun 26 21:13:35 2012
;--------------------------------------------------------
$name gs
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
	public __c51_heap_size
	public _main
	public _exit
	public _inituart
	public _de2_8052_crt0
	public __c51_heap
	public _putchar
	public _getchar
	public _add_syseq
	public _create_syseq
	public _free_syseq
	public _eval_syseq
	public _print_syseq_x
	public _solve_syseq
	public _zero_start_syseq
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
_T2CON          DATA 0xc8
_RCAP2L         DATA 0xca
_RCAP2H         DATA 0xcb
_TL2            DATA 0xcc
_TH2            DATA 0xcd
_DPS            DATA 0x86
_DPH1           DATA 0x85
_DPL1           DATA 0x84
_HEX0           DATA 0x91
_HEX1           DATA 0x92
_HEX2           DATA 0x93
_HEX3           DATA 0x94
_HEX4           DATA 0x8e
_HEX5           DATA 0x8f
_HEX6           DATA 0x96
_HEX7           DATA 0x97
_LEDRA          DATA 0xe8
_LEDRB          DATA 0x95
_LEDRC          DATA 0x9e
_LEDG           DATA 0xf8
_SWA            DATA 0xe8
_SWB            DATA 0x95
_SWC            DATA 0x9e
_KEY            DATA 0xf8
_P0MOD          DATA 0x9a
_P1MOD          DATA 0x9b
_P2MOD          DATA 0x9c
_P3MOD          DATA 0x9d
_LCD_CMD        DATA 0xd8
_LCD_DATA       DATA 0xd9
_LCD_MOD        DATA 0xda
_JCMD           DATA 0xc0
_JBUF           DATA 0xc1
_JCNT           DATA 0xc2
_REP_ADD_L      DATA 0xf1
_REP_ADD_H      DATA 0xf2
_REP_VALUE      DATA 0xf3
_DEBUG_CALL_L   DATA 0xfa
_DEBUG_CALL_H   DATA 0xfb
_BPC            DATA 0xfc
_BPS            DATA 0xfd
_BPAL           DATA 0xfe
_BPAH           DATA 0xff
_LBPAL          DATA 0xfa
_LBPAH          DATA 0xfb
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
_ET2            BIT 0xad
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
_PT2            BIT 0xbd
_P              BIT 0xd0
_F1             BIT 0xd1
_OV             BIT 0xd2
_RS0            BIT 0xd3
_RS1            BIT 0xd4
_F0             BIT 0xd5
_AC             BIT 0xd6
_CY             BIT 0xd7
_T2CON_0        BIT 0xc8
_T2CON_1        BIT 0xc9
_T2CON_2        BIT 0xca
_T2CON_3        BIT 0xcb
_T2CON_4        BIT 0xcc
_T2CON_5        BIT 0xcd
_T2CON_6        BIT 0xce
_T2CON_7        BIT 0xcf
_CP_RL2         BIT 0xc8
_C_T2           BIT 0xc9
_TR2            BIT 0xca
_EXEN2          BIT 0xcb
_TCLK           BIT 0xcc
_RCLK           BIT 0xcd
_EXF2           BIT 0xce
_TF2            BIT 0xcf
_LEDRA_0        BIT 0xe8
_LEDRA_1        BIT 0xe9
_LEDRA_2        BIT 0xea
_LEDRA_3        BIT 0xeb
_LEDRA_4        BIT 0xec
_LEDRA_5        BIT 0xed
_LEDRA_6        BIT 0xee
_LEDRA_7        BIT 0xef
_SWA_0          BIT 0xe8
_SWA_1          BIT 0xe9
_SWA_2          BIT 0xea
_SWA_3          BIT 0xeb
_SWA_4          BIT 0xec
_SWA_5          BIT 0xed
_SWA_6          BIT 0xee
_SWA_7          BIT 0xef
_LEDG_0         BIT 0xf8
_LEDG_1         BIT 0xf9
_LEDG_2         BIT 0xfa
_LEDG_3         BIT 0xfb
_LEDG_4         BIT 0xfc
_LEDG_5         BIT 0xfd
_LEDG_6         BIT 0xfe
_LEDG_7         BIT 0xff
_KEY_1          BIT 0xf9
_KEY_2          BIT 0xfa
_KEY_3          BIT 0xfb
_LCD_RW         BIT 0xd8
_LCD_EN         BIT 0xd9
_LCD_RS         BIT 0xda
_LCD_ON         BIT 0xdb
_LCD_BLON       BIT 0xdc
_JRXRDY         BIT 0xc0
_JTXRDY         BIT 0xc1
_JRXEN          BIT 0xc2
_JTXEN          BIT 0xc3
_JTXFULL        BIT 0xc4
_JRXFULL        BIT 0xc5
_JTXEMPTY       BIT 0xc6
_JTDI           BIT 0xc7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	rbank0 segment data overlay
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	rseg R_DSEG
_main_syseq_1_1:
	ds 3
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg	R_OSEG
	rseg	R_OSEG
	rseg	R_OSEG
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
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	rseg R_XSEG
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	rseg R_XSEG
__c51_heap:
	ds 384
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
; Reset entry point and interrupt vectors
;--------------------------------------------------------
	CSEG at 0x0000
	ljmp	_crt0
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
;Allocation info for local variables in function 'de2_8052_crt0'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:/Source/call51/bin/../include/mcs51/DE2_8052.h:304: void de2_8052_crt0 (void) _naked
;	-----------------------------------------
;	 function de2_8052_crt0
;	-----------------------------------------
_de2_8052_crt0:
;	naked function: no prologue.
;	C:/Source/call51/bin/../include/mcs51/DE2_8052.h:373: _endasm;
	
	
	 rseg R_GSINIT
	 public _crt0
	_crt0:
	 mov sp,#_stack_start-1
	 lcall __c51_external_startup
	 mov a,dpl
	 jz __c51_init_data
	 ljmp __c51_program_startup
	__c51_init_data:
	
; Initialize xdata variables
	
	 mov dpl, #_R_XINIT_start
	 mov dph, #(_R_XINIT_start>>8)
	 mov _DPL1, #_R_IXSEG_start
	 mov _DPH1, #(_R_IXSEG_start>>8)
	 mov r0, #_R_IXSEG_size
	 mov r1, #(_R_IXSEG_size>>8)
	
	XInitLoop?repeat?:
	 mov a, r0
	 orl a, r1
	 jz XInitLoop?done?
	 clr a
	 mov _DPS, #0 ; Using dpl, dph
	 movc a,@a+dptr
	 inc dptr
	 mov _DPS, #1 ; Using DPL1, DPH1
	 movx @dptr, a
	 inc dptr
	 dec r0
	 cjne r0, #0xff, XInitLoop?repeat?
	 dec r1
	 sjmp XInitLoop?repeat?
	
	XInitLoop?done?:
	
; Clear xdata variables
	 mov _DPS, #0 ; Make sure we are using dpl, dph
	 mov dpl, #_R_XSEG_start
	 mov dph, #(_R_XSEG_start>>8)
	 mov r4, #_R_XSEG_size
	 mov r5, #(_R_XSEG_size>>8)
	
	XClearLoop?repeat?:
	 mov a, r4
	 orl a, r5
	 jz XClearLoop?done?
	 clr a
	 movx @dptr, a
	 inc dptr
	 dec r4
	 cjne r4, #0xff, XClearLoop?repeat?
	 dec r5
	 sjmp XClearLoop?repeat?
	
	XClearLoop?done?:
	 lcall _R_DINIT_start ; Initialize data/idata variables
	
	__c51_program_startup:
	 lcall _main
	
	forever?home?:
	 sjmp forever?home?
	
	 
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'inituart'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:28: void inituart (void)
;	-----------------------------------------
;	 function inituart
;	-----------------------------------------
_inituart:
	using	0
;	C:\Source\call51\Examples\c\gs.c:30: RCAP2H=HIGH(TIMER_2_RELOAD);
	mov	_RCAP2H,#0xFF
;	C:\Source\call51\Examples\c\gs.c:31: RCAP2L=LOW(TIMER_2_RELOAD);
	mov	_RCAP2L,#0xFD
;	C:\Source\call51\Examples\c\gs.c:32: T2CON=0x34; // #00110100B
	mov	_T2CON,#0x34
;	C:\Source\call51\Examples\c\gs.c:33: SCON=0x52; // Serial port in mode 1, ren, txrdy, rxempty
	mov	_SCON,#0x52
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:36: void putchar (char c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\gs.c:38: if (c=='\n')
	cjne	r2,#0x0A,L004006?
;	C:\Source\call51\Examples\c\gs.c:40: while (!TI);
L004001?:
;	C:\Source\call51\Examples\c\gs.c:41: TI=0;
	jbc	_TI,L004017?
	sjmp	L004001?
L004017?:
;	C:\Source\call51\Examples\c\gs.c:42: SBUF='\r';
	mov	_SBUF,#0x0D
;	C:\Source\call51\Examples\c\gs.c:44: while (!TI);
L004006?:
;	C:\Source\call51\Examples\c\gs.c:45: TI=0;
	jbc	_TI,L004018?
	sjmp	L004006?
L004018?:
;	C:\Source\call51\Examples\c\gs.c:46: SBUF=c;
	mov	_SBUF,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getchar'
;------------------------------------------------------------
;c                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:49: char getchar (void)
;	-----------------------------------------
;	 function getchar
;	-----------------------------------------
_getchar:
;	C:\Source\call51\Examples\c\gs.c:53: while (!RI);
L005001?:
;	C:\Source\call51\Examples\c\gs.c:54: RI=0;
	jbc	_RI,L005008?
	sjmp	L005001?
L005008?:
;	C:\Source\call51\Examples\c\gs.c:55: c=SBUF;
	mov	dpl,_SBUF
;	C:\Source\call51\Examples\c\gs.c:56: return c;
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'exit'
;------------------------------------------------------------
;j                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:59: void exit (int j)
;	-----------------------------------------
;	 function exit
;	-----------------------------------------
_exit:
;	C:\Source\call51\Examples\c\gs.c:61: while(1);
L006002?:
;	C:\Source\call51\Examples\c\gs.c:62: j;
	sjmp	L006002?
;------------------------------------------------------------
;Allocation info for local variables in function 'add_syseq'
;------------------------------------------------------------
;row                       Allocated to stack - offset -4
;col                       Allocated to stack - offset -6
;value                     Allocated to stack - offset -10
;syseq                     Allocated to registers r2 r3 r4 
;i                         Allocated to stack - offset 1
;sloc0                     Allocated to stack - offset 3
;sloc1                     Allocated to stack - offset 6
;sloc2                     Allocated to stack - offset 13
;sloc3                     Allocated to stack - offset 10
;sloc4                     Allocated to stack - offset 13
;sloc5                     Allocated to stack - offset 16
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:73: void add_syseq(_syseq * syseq, int row, int col, double value) reentrant
;	-----------------------------------------
;	 function add_syseq
;	-----------------------------------------
_add_syseq:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x13
	mov	sp,a
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\Examples\c\gs.c:77: if(value==0.0) return; //Preserve sparsity
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	jnz	L007002?
	ljmp	L007015?
L007002?:
;	C:\Source\call51\Examples\c\gs.c:80: if(row==col)
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,_bp
	add	a,#0xfa
	mov	r1,a
	mov	b,@r0
	mov	a,@r1
	cjne	a,b,L007025?
	inc	r0
	mov	b,@r0
	inc	r1
	mov	a,@r1
	cjne	a,b,L007025?
	sjmp	L007026?
L007025?:
	ljmp	L007004?
L007026?:
;	C:\Source\call51\Examples\c\gs.c:82: syseq->eq[row].g+=value;
	mov	a,#0x10
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	__mulint_PARM_2,@r0
	inc	r0
	mov	(__mulint_PARM_2 + 1),@r0
	mov	dptr,#0x0014
	push	ar2
	push	ar3
	push	ar4
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	pop	ar4
	pop	ar3
	pop	ar2
	mov	a,r5
	add	a,r2
	mov	r5,a
	mov	a,r6
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	a,#0x04
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x06
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	inc	r0
	mov	@r0,b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar3
	pop	ar2
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:83: return;
	ljmp	L007015?
L007004?:
;	C:\Source\call51\Examples\c\gs.c:87: for(i=0; i < syseq->eq[row].n; i++)
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,#0x10
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	__mulint_PARM_2,@r0
	inc	r0
	mov	(__mulint_PARM_2 + 1),@r0
	mov	dptr,#0x0014
	push	ar2
	push	ar3
	push	ar4
	lcall	__mulint
	xch	a,r0
	mov	a,_bp
	add	a,#0x06
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	pop	ar4
	pop	ar3
	pop	ar2
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L007011?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,_bp
	add	a,#0x0d
	mov	r1,a
	mov	a,@r0
	add	a,r6
	mov	@r1,a
	inc	r0
	mov	a,@r0
	addc	a,r5
	inc	r1
	mov	@r1,a
	inc	r1
	mov	@r1,ar7
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,#0x12
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	r0,_bp
	inc	r0
	clr	c
	mov	a,@r0
	subb	a,r5
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	pop	ar4
	pop	ar3
	pop	ar2
	jc	L007027?
	ljmp	L007014?
L007027?:
;	C:\Source\call51\Examples\c\gs.c:89: if (col==syseq->eq[row].eqn[i])
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,#0x0F
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	r0,_bp
	inc	r0
	mov	ar2,@r0
	inc	r0
	mov	a,@r0
	xch	a,r2
	add	a,acc
	xch	a,r2
	rlc	a
	mov	r3,a
	mov	a,r2
	add	a,r5
	mov	r2,a
	mov	a,r3
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	cjne	a,ar2,L007028?
	inc	r0
	mov	a,@r0
	cjne	a,ar3,L007028?
	sjmp	L007029?
L007028?:
	pop	ar4
	pop	ar3
	pop	ar2
	ljmp	L007013?
L007029?:
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\gs.c:91: syseq->eq[row].gij[i]+=value;
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,#0x0C
	add	a,@r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	a,@r0
	xch	a,r5
	add	a,acc
	xch	a,r5
	rlc	a
	xch	a,r5
	add	a,acc
	xch	a,r5
	rlc	a
	mov	r6,a
	mov	a,r5
	add	a,r2
	mov	r2,a
	mov	a,r6
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x10
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	inc	r0
	mov	@r0,b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar3
	pop	ar2
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:92: return;
	ljmp	L007015?
L007013?:
;	C:\Source\call51\Examples\c\gs.c:87: for(i=0; i < syseq->eq[row].n; i++)
	mov	r0,_bp
	inc	r0
	inc	@r0
	cjne	@r0,#0x00,L007030?
	inc	r0
	inc	@r0
L007030?:
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x03
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	ljmp	L007011?
L007014?:
;	C:\Source\call51\Examples\c\gs.c:97: syseq->eq[row].gij=realloc(syseq->eq[row].gij, (syseq->eq[row].n+1)*sizeof(double));
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,_bp
	add	a,#0x10
	mov	r1,a
	mov	a,#0x0C
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x0d
	mov	r1,a
	lcall	__gptrget
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	inc	r5
	cjne	r5,#0x00,L007031?
	inc	r6
L007031?:
	mov	_realloc_PARM_2,r5
	mov	a,r6
	xch	a,_realloc_PARM_2
	add	a,acc
	xch	a,_realloc_PARM_2
	rlc	a
	xch	a,_realloc_PARM_2
	add	a,acc
	xch	a,_realloc_PARM_2
	rlc	a
	mov	(_realloc_PARM_2 + 1),a
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	push	ar2
	push	ar3
	push	ar4
	lcall	_realloc
	mov	r5,dpl
	mov	r6,dph
	pop	ar4
	pop	ar3
	pop	ar2
	mov	r7,#0x00
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:98: if((void *)syseq->eq[row].gij==NULL)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r0
	add	a,r5
	mov	r5,a
	inc	r0
	mov	a,@r0
	addc	a,r6
	mov	r6,a
	mov	a,#0x0C
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	cjne	r5,#0x00,L007008?
	cjne	r6,#0x00,L007008?
	cjne	r7,#0x00,L007008?
;	C:\Source\call51\Examples\c\gs.c:100: printf("ERROR: not enough memory for 'gij' array.\n");
	push	ar2
	push	ar3
	push	ar4
	mov	a,#__str_0
	push	acc
	mov	a,#(__str_0 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
L007008?:
;	C:\Source\call51\Examples\c\gs.c:103: syseq->eq[row].eqn=realloc(syseq->eq[row].eqn, (syseq->eq[row].n+1)*sizeof(int));
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r0
	add	a,r5
	mov	r5,a
	inc	r0
	mov	a,@r0
	addc	a,r6
	mov	r6,a
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,#0x0F
	add	a,r5
	mov	@r0,a
	clr	a
	addc	a,r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
	lcall	__gptrget
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	mov	a,#0x12
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	r5
	cjne	r5,#0x00,L007034?
	inc	r6
L007034?:
	mov	_realloc_PARM_2,r5
	mov	a,r6
	xch	a,_realloc_PARM_2
	add	a,acc
	xch	a,_realloc_PARM_2
	rlc	a
	mov	(_realloc_PARM_2 + 1),a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	push	ar2
	push	ar3
	push	ar4
	lcall	_realloc
	mov	r5,dpl
	mov	r6,dph
	pop	ar4
	pop	ar3
	pop	ar2
	mov	r7,#0x00
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:104: if((void *)syseq->eq[row].eqn==NULL)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r0
	add	a,r5
	mov	r5,a
	inc	r0
	mov	a,@r0
	addc	a,r6
	mov	r6,a
	mov	a,#0x0F
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	cjne	r5,#0x00,L007010?
	cjne	r6,#0x00,L007010?
	cjne	r7,#0x00,L007010?
;	C:\Source\call51\Examples\c\gs.c:106: printf("ERROR: not enough memory for 'eq' array.\n");
	push	ar2
	push	ar3
	push	ar4
	mov	a,#__str_1
	push	acc
	mov	a,#(__str_1 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
L007010?:
;	C:\Source\call51\Examples\c\gs.c:110: syseq->eq[row].gij[syseq->eq[row].n]=value;
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r0
	add	a,r2
	mov	r2,a
	inc	r0
	mov	a,@r0
	addc	a,r3
	mov	r3,a
	mov	a,#0x0C
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,#0x12
	add	a,r2
	mov	@r0,a
	clr	a
	addc	a,r3
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar4
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
	lcall	__gptrget
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	ar7,@r0
	inc	r0
	mov	a,@r0
	xch	a,r7
	add	a,acc
	xch	a,r7
	rlc	a
	xch	a,r7
	add	a,acc
	xch	a,r7
	rlc	a
	mov	r5,a
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	a,r7
	add	a,@r0
	mov	r7,a
	mov	a,r5
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r7
	mov	dph,r5
	mov	b,r6
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:111: syseq->eq[row].eqn[syseq->eq[row].n]=col;
	mov	a,#0x0F
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	a,@r0
	xch	a,r5
	add	a,acc
	xch	a,r5
	rlc	a
	mov	r6,a
	mov	a,r5
	add	a,r2
	mov	r2,a
	mov	a,r6
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:112: syseq->eq[row].n++;
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,#0x01
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r2
	lcall	__gptrput
	inc	dptr
	mov	a,r3
	lcall	__gptrput
L007015?:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'create_syseq'
;------------------------------------------------------------
;maxiter                   Allocated to stack - offset -4
;tol                       Allocated to stack - offset -8
;alpha                     Allocated to stack - offset -12
;order                     Allocated to stack - offset 1
;j                         Allocated to stack - offset 3
;syseq                     Allocated to stack - offset 5
;sloc0                     Allocated to stack - offset 8
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:116: _syseq * create_syseq(int order, int maxiter, double tol, double alpha) reentrant
;	-----------------------------------------
;	 function create_syseq
;	-----------------------------------------
_create_syseq:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	mov	a,sp
	add	a,#0x09
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:121: syseq=malloc(sizeof(_syseq));
	mov	dptr,#0x0013
	lcall	_malloc
	mov	r4,dpl
	mov	r5,dph
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,#0x00
;	C:\Source\call51\Examples\c\gs.c:122: if(syseq==NULL)
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	cjne	@r0,#0x00,L008002?
	inc	r0
	cjne	@r0,#0x00,L008002?
	inc	r0
	cjne	@r0,#0x00,L008002?
;	C:\Source\call51\Examples\c\gs.c:124: printf("ERROR: not enough memory for system of equations.\n");
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\gs.c:125: exit(1);
	mov	dptr,#0x0001
	lcall	_exit
L008002?:
;	C:\Source\call51\Examples\c\gs.c:128: syseq->eq=malloc(order*sizeof(_eq));
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x10
	add	a,@r0
	mov	r7,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r2,a
	inc	r0
	mov	ar3,@r0
	mov	r0,_bp
	inc	r0
	mov	__mulint_PARM_2,@r0
	inc	r0
	mov	(__mulint_PARM_2 + 1),@r0
	mov	dptr,#0x0014
	push	ar2
	push	ar3
	push	ar7
	lcall	__mulint
	lcall	_malloc
	mov	r4,dpl
	mov	r5,dph
	pop	ar7
	pop	ar3
	pop	ar2
	mov	r6,#0x00
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	mov	a,r4
	lcall	__gptrput
	inc	dptr
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:129: if(syseq->eq==NULL)
	cjne	r4,#0x00,L008004?
	cjne	r5,#0x00,L008004?
	cjne	r6,#0x00,L008004?
;	C:\Source\call51\Examples\c\gs.c:131: printf("ERROR: not enough memory for equation.\n");
	push	ar2
	push	ar3
	push	ar7
	mov	a,#__str_3
	push	acc
	mov	a,#(__str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\gs.c:132: exit(1);
	mov	dptr,#0x0001
	lcall	_exit
	pop	ar7
	pop	ar3
	pop	ar2
L008004?:
;	C:\Source\call51\Examples\c\gs.c:135: syseq->order=order;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:136: syseq->alpha=alpha;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x0A
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:137: syseq->maxiter=maxiter;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x02
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:138: syseq->tol=tol;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x06
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:139: syseq->debug=0;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x0E
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:141: for(j=0; j<order; j++)
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L008005?:
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	r1,_bp
	inc	r1
	clr	c
	mov	a,@r0
	subb	a,@r1
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	inc	r1
	mov	b,@r1
	xrl	b,#0x80
	subb	a,b
	jc	L008020?
	ljmp	L008008?
L008020?:
;	C:\Source\call51\Examples\c\gs.c:143: syseq->eq[j].gij=NULL;
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a,r6
	mov	r6,a
	inc	r0
	mov	a,@r0
	addc	a,r4
	mov	r4,a
	mov	a,#0x0C
	add	a,r6
	mov	r6,a
	clr	a
	addc	a,r4
	mov	r4,a
	mov	dpl,r6
	mov	dph,r4
	mov	b,r5
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:144: syseq->eq[j].eqn=NULL;
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a,r4
	mov	r4,a
	inc	r0
	mov	a,@r0
	addc	a,r5
	mov	r5,a
	mov	a,#0x0F
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:145: syseq->eq[j].n=0;
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a,r4
	mov	r4,a
	inc	r0
	mov	a,@r0
	addc	a,r5
	mov	r5,a
	mov	a,#0x12
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:146: syseq->eq[j].x=0;
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a,r4
	mov	r4,a
	inc	r0
	mov	a,@r0
	addc	a,r5
	mov	r5,a
	mov	a,#0x08
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:147: syseq->eq[j].b=0;
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a,r4
	mov	r4,a
	inc	r0
	mov	a,@r0
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:148: syseq->eq[j].g=0;
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a,r4
	mov	r4,a
	inc	r0
	mov	a,@r0
	addc	a,r5
	mov	r5,a
	mov	a,#0x04
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:141: for(j=0; j<order; j++)
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,#0x14
	add	a,@r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L008021?
	inc	r0
	inc	@r0
L008021?:
	ljmp	L008005?
L008008?:
;	C:\Source\call51\Examples\c\gs.c:150: return syseq;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'free_syseq'
;------------------------------------------------------------
;syseq                     Allocated to registers r2 r3 r4 
;j                         Allocated to stack - offset 1
;sloc0                     Allocated to stack - offset 3
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:154: void free_syseq(_syseq * syseq) reentrant
;	-----------------------------------------
;	 function free_syseq
;	-----------------------------------------
_free_syseq:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x04
	mov	sp,a
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\Examples\c\gs.c:157: for(j=0; j<syseq->order; j++)
	mov	a,#0x10
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L009001?:
	push	ar5
	push	ar6
	push	ar7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	r0,_bp
	inc	r0
	clr	c
	mov	a,@r0
	subb	a,r5
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	pop	ar7
	pop	ar6
	pop	ar5
	jc	L009010?
	ljmp	L009005?
L009010?:
;	C:\Source\call51\Examples\c\gs.c:159: free(syseq->eq[j].gij);
	push	ar2
	push	ar3
	push	ar4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,@r0
	add	a,r2
	mov	r2,a
	inc	r0
	mov	a,@r0
	addc	a,r3
	mov	r3,a
	mov	a,#0x0C
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	lcall	_free
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\gs.c:160: free(syseq->eq[j].eqn);
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,@r0
	add	a,r2
	mov	r2,a
	inc	r0
	mov	a,@r0
	addc	a,r3
	mov	r3,a
	mov	a,#0x0F
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	lcall	_free
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\gs.c:157: for(j=0; j<syseq->order; j++)
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,#0x14
	add	a,@r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	r0,_bp
	inc	r0
	inc	@r0
	cjne	@r0,#0x00,L009011?
	inc	r0
	inc	@r0
L009011?:
	pop	ar4
	pop	ar3
	pop	ar2
	ljmp	L009001?
L009005?:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eval_syseq'
;------------------------------------------------------------
;syseq                     Allocated to stack - offset 1
;i                         Allocated to stack - offset 4
;j                         Allocated to stack - offset 6
;intol                     Allocated to stack - offset 8
;x                         Allocated to stack - offset 10
;sloc0                     Allocated to stack - offset 14
;sloc1                     Allocated to stack - offset 17
;sloc2                     Allocated to stack - offset 20
;sloc3                     Allocated to stack - offset 22
;sloc4                     Allocated to stack - offset 24
;sloc5                     Allocated to stack - offset 27
;sloc6                     Allocated to stack - offset 30
;sloc7                     Allocated to stack - offset 30
;sloc8                     Allocated to stack - offset 33
;sloc9                     Allocated to stack - offset 37
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:166: int eval_syseq(_syseq * syseq) reentrant
;	-----------------------------------------
;	 function eval_syseq
;	-----------------------------------------
_eval_syseq:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x28
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:168: int i, j, intol=1;
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	@r0,#0x01
	clr	a
	inc	r0
	mov	@r0,a
;	C:\Source\call51\Examples\c\gs.c:171: for(j=0; j<syseq->order; j++)
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x18
	mov	r1,a
	mov	a,#0x10
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x0e
	mov	r1,a
	mov	a,#0x0A
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x11
	mov	r1,a
	mov	a,#0x06
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x16
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L010007?:
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r4
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jc	L010020?
	ljmp	L010010?
L010020?:
;	C:\Source\call51\Examples\c\gs.c:173: x=0.0;
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	C:\Source\call51\Examples\c\gs.c:174: for(i=0; i<syseq->eq[j].n; i++)
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L010003?:
	mov	a,_bp
	add	a,#0x18
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x1b
	mov	r1,a
	lcall	__gptrget
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x1b
	mov	r0,a
	mov	a,_bp
	add	a,#0x14
	mov	r1,a
	mov	a,@r1
	add	a,@r0
	push	acc
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x20
	mov	r0,a
	pop	acc
	mov	@r0,a
	dec	r0
	pop	acc
	mov	@r0,a
	dec	r0
	pop	acc
	mov	@r0,a
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	a,#0x12
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r2
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	jc	L010021?
	ljmp	L010006?
L010021?:
;	C:\Source\call51\Examples\c\gs.c:176: x-=syseq->eq[j].gij[i]*syseq->eq[syseq->eq[j].eqn[i]].x;
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	a,#0x0C
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	a,@r0
	xch	a,r2
	add	a,acc
	xch	a,r2
	rlc	a
	xch	a,r2
	add	a,acc
	xch	a,r2
	rlc	a
	mov	r6,a
	mov	a,r2
	add	a,r3
	mov	r2,a
	mov	a,r6
	addc	a,r4
	mov	r6,a
	mov	ar7,r5
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x21
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	a,#0x0F
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar2,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r2
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	a,@r0
	xch	a,r3
	add	a,acc
	xch	a,r3
	rlc	a
	mov	r6,a
	mov	a,r3
	add	a,r4
	mov	r4,a
	mov	a,r6
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r2
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x0014
	lcall	__mulint
	mov	r2,dpl
	mov	r3,dph
	mov	a,_bp
	add	a,#0x1b
	mov	r0,a
	mov	a,r2
	add	a,@r0
	mov	r2,a
	mov	a,r3
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	a,#0x08
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x21
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsmul
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fssub
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Examples\c\gs.c:174: for(i=0; i<syseq->eq[j].n; i++)
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L010022?
	inc	r0
	inc	@r0
L010022?:
	ljmp	L010003?
L010006?:
;	C:\Source\call51\Examples\c\gs.c:178: x+=syseq->eq[j].b;
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsadd
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Examples\c\gs.c:179: x*=(syseq->alpha/syseq->eq[j].g);
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x21
	mov	r1,a
	lcall	__gptrget
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	inc	dptr
	lcall	__gptrget
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	a,#0x04
	add	a,@r0
	mov	r6,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r7,a
	inc	r0
	mov	ar2,@r0
	mov	dpl,r6
	mov	dph,r7
	mov	b,r2
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	mov	a,_bp
	add	a,#0x21
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsdiv
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsmul
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Examples\c\gs.c:180: x+=((1.0-syseq->alpha)*syseq->eq[j].x);
	mov	a,_bp
	add	a,#0x21
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x21
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	inc	r0
	mov	@r0,b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	a,#0x08
	add	a,@r0
	mov	r6,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r7,a
	inc	r0
	mov	ar2,@r0
	mov	dpl,r6
	mov	dph,r7
	mov	b,r2
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x21
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsmul
	mov	r4,dpl
	mov	r5,dph
	mov	r2,b
	mov	r3,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar4
	push	ar5
	push	ar2
	push	ar3
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsadd
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Examples\c\gs.c:183: if((fabs(x-syseq->eq[j].x)/fabs(x))>syseq->tol) intol=0;
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fssub
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	_fabsf
	xch	a,r0
	mov	a,_bp
	add	a,#0x25
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	inc	r0
	mov	@r0,b
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	_fabsf
	mov	r6,dpl
	mov	r7,dph
	mov	r2,b
	mov	r3,a
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsdiv
	xch	a,r0
	mov	a,_bp
	add	a,#0x25
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	inc	r0
	mov	@r0,b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsgt
	mov	r2,dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r2
	jz	L010002?
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L010002?:
;	C:\Source\call51\Examples\c\gs.c:185: syseq->eq[j].x=x;
	mov	a,_bp
	add	a,#0x18
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x16
	mov	r0,a
	mov	a,@r0
	add	a,r2
	mov	r2,a
	inc	r0
	mov	a,@r0
	addc	a,r3
	mov	r3,a
	mov	a,#0x08
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:171: for(j=0; j<syseq->order; j++)
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	mov	a,#0x14
	add	a,@r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x16
	mov	r0,a
	mov	a,#0x14
	add	a,@r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L010024?
	inc	r0
	inc	@r0
L010024?:
	ljmp	L010007?
L010010?:
;	C:\Source\call51\Examples\c\gs.c:187: return intol;
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'print_syseq_x'
;------------------------------------------------------------
;syseq                     Allocated to stack - offset 1
;j                         Allocated to stack - offset 4
;digits                    Allocated to registers r2 r3 
;outfmt                    Allocated to stack - offset 6
;sloc0                     Allocated to stack - offset 26
;sloc1                     Allocated to stack - offset 28
;sloc2                     Allocated to stack - offset 29
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:191: void print_syseq_x(_syseq * syseq) reentrant
;	-----------------------------------------
;	 function print_syseq_x
;	-----------------------------------------
_print_syseq_x:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x20
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:197: digits=(int)log10(1.0/syseq->tol);
	mov	r0,_bp
	inc	r0
	mov	a,#0x06
	add	a,@r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	push	ar5
	push	ar6
	push	ar7
	push	ar2
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	___fsdiv
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	_log10f
	lcall	___fs2sint
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\Examples\c\gs.c:198: sprintf(outfmt, "%%%d.%df", digits+3, digits-1);
	mov	a,r2
	add	a,#0xff
	mov	r4,a
	mov	a,r3
	addc	a,#0xff
	mov	r5,a
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	a,#0x03
	add	a,r2
	mov	@r0,a
	clr	a
	addc	a,r3
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x06
	mov	r6,a
	mov	r7,a
	mov	r2,#0x00
	mov	r3,#0x40
	push	ar6
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,#__str_4
	push	acc
	mov	a,#(__str_4 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	push	ar7
	push	ar2
	push	ar3
	lcall	_sprintf
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	pop	ar6
;	C:\Source\call51\Examples\c\gs.c:200: for(j=0; j<syseq->order; j++)
	mov	r0,_bp
	inc	r0
	mov	a,#0x10
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	mov	@r0,ar6
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L011004?:
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r5
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	jc	L011014?
	ljmp	L011008?
L011014?:
;	C:\Source\call51\Examples\c\gs.c:202: printf(outfmt, syseq->eq[j].x);
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	a,@r0
	add	a,r6
	mov	r6,a
	inc	r0
	mov	a,@r0
	addc	a,r7
	mov	r7,a
	mov	a,#0x08
	add	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	push	ar2
	push	ar3
	push	ar4
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	mov	a,_bp
	add	a,#0x1d
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	mov	ar3,@r0
	mov	r4,#0x00
	mov	r2,#0x40
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0x1d
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	push	ar3
	push	ar4
	push	ar2
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\gs.c:203: if(j<(syseq->order-1))
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	dec	r2
	cjne	r2,#0xff,L011015?
	dec	r3
L011015?:
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r2
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	pop	ar4
	pop	ar3
	pop	ar2
	jnc	L011002?
;	C:\Source\call51\Examples\c\gs.c:204: printf(", ");
	push	ar2
	push	ar3
	push	ar4
	mov	a,#__str_5
	push	acc
	mov	a,#(__str_5 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	L011006?
L011002?:
;	C:\Source\call51\Examples\c\gs.c:206: printf("\n");
	push	ar2
	push	ar3
	push	ar4
	mov	a,#__str_6
	push	acc
	mov	a,#(__str_6 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
L011006?:
;	C:\Source\call51\Examples\c\gs.c:200: for(j=0; j<syseq->order; j++)
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	a,#0x14
	add	a,@r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L011017?
	inc	r0
	inc	@r0
L011017?:
	ljmp	L011004?
L011008?:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'solve_syseq'
;------------------------------------------------------------
;syseq                     Allocated to stack - offset 1
;intol                     Allocated to registers r2 r3 
;sloc0                     Allocated to stack - offset 4
;sloc1                     Allocated to stack - offset 9
;sloc2                     Allocated to stack - offset 7
;sloc3                     Allocated to stack - offset 10
;sloc4                     Allocated to stack - offset 17
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:212: int solve_syseq(_syseq * syseq) reentrant
;	-----------------------------------------
;	 function solve_syseq
;	-----------------------------------------
_solve_syseq:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x0c
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:214: if(syseq->debug)
	mov	r0,_bp
	inc	r0
	mov	a,#0x0E
	add	a,@r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	orl	a,r2
	jz	L012002?
;	C:\Source\call51\Examples\c\gs.c:216: printf("x(%d)= ", 0);
	push	ar5
	push	ar6
	push	ar7
	clr	a
	push	acc
	push	acc
	mov	a,#__str_7
	push	acc
	mov	a,#(__str_7 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:217: print_syseq_x(syseq);
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	_print_syseq_x
	pop	ar7
	pop	ar6
	pop	ar5
L012002?:
;	C:\Source\call51\Examples\c\gs.c:220: for(syseq->numiter=1; syseq->numiter!=syseq->maxiter; syseq->numiter++)
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
	mov	a,#0x04
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,#0x01
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x02
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
L012011?:
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,r2
	cjne	a,ar7,L012025?
	mov	a,r3
	cjne	a,ar5,L012025?
	pop	ar7
	pop	ar6
	pop	ar5
	ljmp	L012014?
L012025?:
	pop	ar7
;	C:\Source\call51\Examples\c\gs.c:223: intol=eval_syseq(syseq);
	push	ar7
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	push	ar7
	lcall	_eval_syseq
	mov	r5,dpl
	mov	r6,dph
	pop	ar7
	mov	ar2,r5
	mov	ar3,r6
;	C:\Source\call51\Examples\c\gs.c:225: if(syseq->debug)
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x07
	mov	r1,a
	mov	a,#0x0E
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	orl	a,r5
	pop	ar7
	pop	ar6
	pop	ar5
	jz	L012004?
;	C:\Source\call51\Examples\c\gs.c:227: printf("x(%d)= ", syseq->numiter);
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	push	ar2
	push	ar3
	push	ar5
	push	ar6
	push	ar7
	push	ar5
	push	ar6
	mov	a,#__str_7
	push	acc
	mov	a,#(__str_7 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:228: print_syseq_x(syseq);
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	_print_syseq_x
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\gs.c:241: return 0;
	pop	ar7
	pop	ar6
	pop	ar5
;	C:\Source\call51\Examples\c\gs.c:228: print_syseq_x(syseq);
L012004?:
;	C:\Source\call51\Examples\c\gs.c:231: if(intol)
	mov	a,r2
	orl	a,r3
	jnz	L012027?
	ljmp	L012013?
L012027?:
;	C:\Source\call51\Examples\c\gs.c:233: if(syseq->debug)
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	orl	a,r2
	jnz	L012028?
	ljmp	L012006?
L012028?:
;	C:\Source\call51\Examples\c\gs.c:234: printf("%d-digit accuracy reached in %d iterations\n", (int) log10(1.0/syseq->tol), syseq->numiter);
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	r0,_bp
	inc	r0
	mov	a,#0x06
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r2,a
	inc	r0
	mov	ar3,@r0
	mov	dpl,r4
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	push	ar5
	push	ar6
	push	ar4
	push	ar2
	push	ar3
	push	ar7
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	___fsdiv
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r7
	lcall	_log10f
	lcall	___fs2sint
	mov	r2,dpl
	mov	r3,dph
	push	ar2
	push	ar3
	mov	a,#__str_8
	push	acc
	mov	a,#(__str_8 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
L012006?:
;	C:\Source\call51\Examples\c\gs.c:235: return 1;
	mov	dptr,#0x0001
	ljmp	L012015?
L012013?:
;	C:\Source\call51\Examples\c\gs.c:220: for(syseq->numiter=1; syseq->numiter!=syseq->maxiter; syseq->numiter++)
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	r2
	cjne	r2,#0x00,L012029?
	inc	r3
L012029?:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r2
	lcall	__gptrput
	inc	dptr
	mov	a,r3
	lcall	__gptrput
	ljmp	L012011?
L012014?:
;	C:\Source\call51\Examples\c\gs.c:239: if(syseq->debug)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	orl	a,r5
	jnz	L012030?
	ljmp	L012010?
L012030?:
;	C:\Source\call51\Examples\c\gs.c:240: printf("ERROR: %d-digit accuracy not reached in %d iterations\n", (int) log10(1.0/syseq->tol), syseq->numiter);
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	r0,_bp
	inc	r0
	mov	a,#0x06
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	___fsdiv
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,r7
	lcall	_log10f
	lcall	___fs2sint
	mov	r4,dpl
	mov	r5,dph
	push	ar4
	push	ar5
	mov	a,#__str_9
	push	acc
	mov	a,#(__str_9 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
L012010?:
;	C:\Source\call51\Examples\c\gs.c:241: return 0;
	mov	dptr,#0x0000
L012015?:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'zero_start_syseq'
;------------------------------------------------------------
;syseq                     Allocated to registers r2 r3 r4 
;j                         Allocated to stack - offset 1
;sloc0                     Allocated to stack - offset 3
;sloc1                     Allocated to stack - offset 5
;sloc2                     Allocated to stack - offset 8
;sloc3                     Allocated to stack - offset 14
;sloc4                     Allocated to stack - offset 11
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:246: void zero_start_syseq(_syseq * syseq) reentrant
;	-----------------------------------------
;	 function zero_start_syseq
;	-----------------------------------------
_zero_start_syseq:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0e
	mov	sp,a
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\Examples\c\gs.c:249: for(j=0; j<syseq->order; j++)
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x10
	add	a,r2
	mov	@r0,a
	clr	a
	addc	a,r3
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar4
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
L013001?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	r0,_bp
	inc	r0
	clr	c
	mov	a,@r0
	subb	a,r5
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	jc	L013010?
	ljmp	L013005?
L013010?:
;	C:\Source\call51\Examples\c\gs.c:250: syseq->eq[j].x=syseq->eq[j].b/syseq->eq[j].g;
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,@r0
	add	a,r2
	mov	r5,a
	inc	r0
	mov	a,@r0
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,#0x08
	add	a,r5
	mov	@r0,a
	clr	a
	addc	a,r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	mov	a,#0x04
	add	a,r5
	mov	r3,a
	clr	a
	addc	a,r6
	mov	r4,a
	mov	ar2,r7
	mov	dpl,r3
	mov	dph,r4
	mov	b,r2
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	push	ar3
	push	ar4
	push	ar2
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	___fsdiv
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r2
	lcall	__gptrput
	inc	dptr
	mov	a,r3
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	inc	dptr
	mov	a,r5
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:249: for(j=0; j<syseq->order; j++)
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,#0x14
	add	a,@r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	r0,_bp
	inc	r0
	inc	@r0
	cjne	@r0,#0x00,L013011?
	inc	r0
	inc	@r0
L013011?:
	pop	ar4
	pop	ar3
	pop	ar2
	ljmp	L013001?
L013005?:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;syseq                     Allocated with name '_main_syseq_1_1'
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\gs.c:253: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Examples\c\gs.c:257: inituart();
	lcall	_inituart
;	C:\Source\call51\Examples\c\gs.c:258: LEDRA=0;
	mov	_LEDRA,#0x00
;	C:\Source\call51\Examples\c\gs.c:259: LEDRB=0;
;	C:\Source\call51\Examples\c\gs.c:260: LEDRC=0;
;	C:\Source\call51\Examples\c\gs.c:261: LEDG=0;
;	C:\Source\call51\Examples\c\gs.c:263: printf("\n\nGauss-Seidel Solution of linear systems\nBy Jesus Calvino-Fraga (c) 2006-2011\n\n");	
	clr	a
	mov	_LEDRB,a
	mov	_LEDRC,a
	mov	_LEDG,a
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\gs.c:266: syseq=create_syseq(4, 25, 1.0e-7, 1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x3F
	push	acc
	mov	a,#0x95
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0xD6
	push	acc
	mov	a,#0x33
	push	acc
	mov	a,#0x19
	push	acc
	clr	a
	push	acc
	mov	dptr,#0x0004
	lcall	_create_syseq
	mov	_main_syseq_1_1,dpl
	mov	(_main_syseq_1_1 + 1),dph
	mov	(_main_syseq_1_1 + 2),b
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:268: add_syseq(syseq, 0, 0, 10.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#0x41
	push	acc
	clr	a
	push	acc
	push	acc
	clr	a
	push	acc
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:269: add_syseq(syseq, 0, 1, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	clr	a
	push	acc
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:270: add_syseq(syseq, 0, 2, 2.0);
	clr	a
	push	acc
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	clr	a
	push	acc
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:271: syseq->eq[0].b=6.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0xC0
	lcall	__gptrput
	inc	dptr
	mov	a,#0x40
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:273: add_syseq(syseq, 1, 0, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	clr	a
	push	acc
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:274: add_syseq(syseq, 1, 1, 11.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x30
	push	acc
	mov	a,#0x41
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:275: add_syseq(syseq, 1, 2, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:276: add_syseq(syseq, 1, 3, 3.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:277: syseq->eq[1].b=25.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,#0x14
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0xC8
	lcall	__gptrput
	inc	dptr
	mov	a,#0x41
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:279: add_syseq(syseq, 2, 0, 2.0);
	clr	a
	push	acc
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	clr	a
	push	acc
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:280: add_syseq(syseq, 2, 1, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:281: add_syseq(syseq, 2, 2, 10.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#0x41
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:282: add_syseq(syseq, 2, 3, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:283: syseq->eq[2].b=-11.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,#0x28
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0x30
	lcall	__gptrput
	inc	dptr
	mov	a,#0xC1
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:285: add_syseq(syseq, 3, 1, 3.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:286: add_syseq(syseq, 3, 2, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:287: add_syseq(syseq, 3, 3, 8.0);
	clr	a
	push	acc
	push	acc
	push	acc
	mov	a,#0x41
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:288: syseq->eq[3].b=15.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,#0x3C
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0x70
	lcall	__gptrput
	inc	dptr
	mov	a,#0x41
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:291: syseq->debug=1;
	mov	a,#0x0E
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,#0x01
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:292: solve_syseq(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_solve_syseq
;	C:\Source\call51\Examples\c\gs.c:293: free_syseq(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_free_syseq
;	C:\Source\call51\Examples\c\gs.c:294: free(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_free
;	C:\Source\call51\Examples\c\gs.c:299: syseq=create_syseq(3, 25, 1.0e-7, 1.25);
	clr	a
	push	acc
	push	acc
	mov	a,#0xA0
	push	acc
	mov	a,#0x3F
	push	acc
	mov	a,#0x95
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0xD6
	push	acc
	mov	a,#0x33
	push	acc
	mov	a,#0x19
	push	acc
	clr	a
	push	acc
	mov	dptr,#0x0003
	lcall	_create_syseq
	mov	_main_syseq_1_1,dpl
	mov	(_main_syseq_1_1 + 1),dph
	mov	(_main_syseq_1_1 + 2),b
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:301: add_syseq(syseq, 0, 0, 4.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x40
	push	acc
	clr	a
	push	acc
	push	acc
	clr	a
	push	acc
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:302: add_syseq(syseq, 0, 1, 3.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	clr	a
	push	acc
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:303: syseq->eq[0].b=24.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0xC0
	lcall	__gptrput
	inc	dptr
	mov	a,#0x41
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:305: add_syseq(syseq, 1, 0, 3.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	push	acc
	clr	a
	push	acc
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:306: add_syseq(syseq, 1, 1, 4.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:307: add_syseq(syseq, 1, 2, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:308: syseq->eq[1].b=30.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,#0x14
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0xF0
	lcall	__gptrput
	inc	dptr
	mov	a,#0x41
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:310: add_syseq(syseq, 2, 1, -1.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0xBF
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:311: add_syseq(syseq, 2, 2, 4.0);
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_add_syseq
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:312: syseq->eq[2].b=-24.0;
	mov	a,#0x10
	add	a,_main_syseq_1_1
	mov	r5,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r6,a
	mov	r7,(_main_syseq_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,#0x28
	add	a,r5
	mov	r0,a
	clr	a
	addc	a,r6
	mov	r1,a
	mov	ar2,r7
	mov	dpl,r0
	mov	dph,r1
	mov	b,r2
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0xC0
	lcall	__gptrput
	inc	dptr
	mov	a,#0xC1
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:314: syseq->eq[0].x=1;
	mov	a,#0x08
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0x80
	lcall	__gptrput
	inc	dptr
	mov	a,#0x3F
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:315: syseq->eq[1].x=1;
	mov	a,#0x1C
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0x80
	lcall	__gptrput
	inc	dptr
	mov	a,#0x3F
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:316: syseq->eq[2].x=1;
	mov	a,#0x30
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	inc	dptr
	mov	a,#0x80
	lcall	__gptrput
	inc	dptr
	mov	a,#0x3F
	lcall	__gptrput
;	C:\Source\call51\Examples\c\gs.c:318: solve_syseq(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_solve_syseq
;	C:\Source\call51\Examples\c\gs.c:320: syseq->numiter, (int) log10(1.0/syseq->tol));
	mov	a,#0x06
	add	a,_main_syseq_1_1
	mov	r2,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r3,a
	mov	r4,(_main_syseq_1_1 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	___fsdiv
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	_log10f
	lcall	___fs2sint
	mov	r2,dpl
	mov	r3,dph
	mov	a,#0x04
	add	a,_main_syseq_1_1
	mov	r4,a
	clr	a
	addc	a,(_main_syseq_1_1 + 1)
	mov	r5,a
	mov	r6,(_main_syseq_1_1 + 2)
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
;	C:\Source\call51\Examples\c\gs.c:319: printf("\nThe second system was solved in %d iterations with %d-digit accuracy:\n",
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Examples\c\gs.c:321: print_syseq_x(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_print_syseq_x
;	C:\Source\call51\Examples\c\gs.c:322: free_syseq(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	lcall	_free_syseq
;	C:\Source\call51\Examples\c\gs.c:323: free(syseq);
	mov	dpl,_main_syseq_1_1
	mov	dph,(_main_syseq_1_1 + 1)
	mov	b,(_main_syseq_1_1 + 2)
	ljmp	_free
	rseg R_CSEG

	rseg R_CONST
__c51_heap_size:
	db 0x80,0x01	; 384
__str_0:
	db 'ERROR: not enough memory for '
	db 0x27
	db 'gij'
	db 0x27
	db ' array.'
	db 0x0A
	db 0x00
__str_1:
	db 'ERROR: not enough memory for '
	db 0x27
	db 'eq'
	db 0x27
	db ' array.'
	db 0x0A
	db 0x00
__str_2:
	db 'ERROR: not enough memory for system of equations.'
	db 0x0A
	db 0x00
__str_3:
	db 'ERROR: not enough memory for equation.'
	db 0x0A
	db 0x00
__str_4:
	db '%%%d.%df'
	db 0x00
__str_5:
	db ', '
	db 0x00
__str_6:
	db 0x0A
	db 0x00
__str_7:
	db 'x(%d)= '
	db 0x00
__str_8:
	db '%d-digit accuracy reached in %d iterations'
	db 0x0A
	db 0x00
__str_9:
	db 'ERROR: %d-digit accuracy not reached in %d iterations'
	db 0x0A
	db 0x00
__str_10:
	db 0x0A
	db 0x0A
	db 'Gauss-Seidel Solution of linear systems'
	db 0x0A
	db 'By Jesus Calvino-F'
	db 'raga (c) 2006-2011'
	db 0x0A
	db 0x0A
	db 0x00
__str_11:
	db 0x0A
	db 'The second system was solved in %d iterations with %d-digit'
	db ' accuracy:'
	db 0x0A
	db 0x00

	rseg R_XINIT

	CSEG

end
