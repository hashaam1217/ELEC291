;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Dec 11 2012) (MSVC)
; This file was generated Sat Jan 05 20:09:21 2013
;--------------------------------------------------------
$name Tetris52
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
	public _rscr_PARM_2
	public _wscr_PARM_3
	public _wscr_PARM_2
	public _collapse_bonus_1_71
	public _Shapes
	public _main
	public _exit
	public _wastetime
	public _getKey
	public _collapse
	public _screenInit
	public _shapeHit
	public _shapeErase
	public _shapeDraw
	public _blockHit
	public _blockDraw
	public _refresh
	public _sendstr
	public __c51_external_startup
	public _rscr
	public _wscr
	public _de2_8052_crt0
	public _Screen
	public _shapeHit_PARM_3
	public _shapeHit_PARM_2
	public _shapeErase_PARM_3
	public _shapeErase_PARM_2
	public _shapeDraw_PARM_3
	public _shapeDraw_PARM_2
	public _blockHit_PARM_2
	public _blockDraw_PARM_3
	public _blockDraw_PARM_2
	public _Score
	public _Level
	public _delay
	public _putchar
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
_delay:
	ds 1
_Level:
	ds 2
_Score:
	ds 2
_blockDraw_PARM_2:
	ds 1
_blockDraw_PARM_3:
	ds 1
_blockHit_PARM_2:
	ds 1
_shapeDraw_PARM_2:
	ds 1
_shapeDraw_PARM_3:
	ds 1
_shapeErase_PARM_2:
	ds 1
_shapeErase_PARM_3:
	ds 1
_shapeHit_PARM_2:
	ds 1
_shapeHit_PARM_3:
	ds 1
_main_Shape_1_86:
	ds 1
_main_X_1_86:
	ds 1
_main_Y_1_86:
	ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg	R_OSEG
_wscr_PARM_2:
	ds 1
_wscr_PARM_3:
	ds 1
	rseg	R_OSEG
_rscr_PARM_2:
	ds 1
	rseg	R_OSEG
	rseg	R_OSEG
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	rseg R_ISEG
_Screen:
	ds 192
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
;	C:\Source\call51\Examples\c\Tetris52.c:37: unsigned char delay=0xff;
	mov	_delay,#0xFF
;	C:\Source\call51\Examples\c\Tetris52.c:150: unsigned int Level=0;
	clr	a
	mov	_Level,a
	mov	(_Level + 1),a
;	C:\Source\call51\Examples\c\Tetris52.c:151: unsigned int Score=0;
	clr	a
	mov	_Score,a
	mov	(_Score + 1),a
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
;Allocation info for local variables in function 'wscr'
;------------------------------------------------------------
;y                         Allocated with name '_wscr_PARM_2'
;val                       Allocated with name '_wscr_PARM_3'
;x                         Allocated to registers r2 
;j                         Allocated to registers r4 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:153: void wscr (unsigned char x, unsigned char y, unsigned char val)
;	-----------------------------------------
;	 function wscr
;	-----------------------------------------
_wscr:
	using	0
;	C:\Source\call51\Examples\c\Tetris52.c:156: j=Screen[x/2][y];
	mov	a,dpl
	mov	r2,a
	clr	c
	rrc	a
	mov	b,#0x18
	mul	ab
	mov	r3,a
	add	a,#_Screen
	mov	r4,a
	mov	r5,_wscr_PARM_2
	mov	a,r5
	add	a,r4
	mov	r0,a
	mov	ar4,@r0
;	C:\Source\call51\Examples\c\Tetris52.c:157: if((x&1)==0)
	mov	a,r2
	jb	acc.0,L003002?
;	C:\Source\call51\Examples\c\Tetris52.c:159: j&=0xf0;
	anl	ar4,#0xF0
;	C:\Source\call51\Examples\c\Tetris52.c:160: Screen[x/2][y]=(j|(val&0x7)|(val&0x80?8:0));
	mov	a,r3
	add	a,#_Screen
	mov	r2,a
	mov	a,r5
	add	a,r2
	mov	r0,a
	mov	a,#0x07
	anl	a,_wscr_PARM_3
	orl	a,r4
	mov	r2,a
	mov	a,_wscr_PARM_3
	jnb	acc.7,L003006?
	mov	r6,#0x08
	sjmp	L003007?
L003006?:
	mov	r6,#0x00
L003007?:
	mov	a,r6
	orl	a,r2
	mov	@r0,a
	ret
L003002?:
;	C:\Source\call51\Examples\c\Tetris52.c:164: j&=0xf;
	anl	ar4,#0x0F
;	C:\Source\call51\Examples\c\Tetris52.c:165: Screen[x/2][y]=j|((val*0x10)&0x70)|(val&0x80);
	mov	a,r3
	add	a,#_Screen
	mov	r3,a
	mov	a,r5
	add	a,r3
	mov	r0,a
	mov	a,_wscr_PARM_3
	swap	a
	anl	a,#0xf0
	mov	r2,a
	mov	a,#0x70
	anl	a,r2
	orl	ar4,a
	mov	a,#0x80
	anl	a,_wscr_PARM_3
	orl	a,r4
	mov	@r0,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'rscr'
;------------------------------------------------------------
;y                         Allocated with name '_rscr_PARM_2'
;x                         Allocated to registers r2 
;j                         Allocated to registers r3 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:169: unsigned char rscr (unsigned char x, unsigned char y)
;	-----------------------------------------
;	 function rscr
;	-----------------------------------------
_rscr:
;	C:\Source\call51\Examples\c\Tetris52.c:172: j=Screen[x/2][y];
	mov	a,dpl
	mov	r2,a
	clr	c
	rrc	a
	mov	b,#0x18
	mul	ab
	add	a,#_Screen
	mov	r3,a
	mov	a,_rscr_PARM_2
	add	a,r3
	mov	r0,a
	mov	ar3,@r0
;	C:\Source\call51\Examples\c\Tetris52.c:173: if(x&1) j/=0x10;
	mov	a,r2
	jnb	acc.0,L004002?
	mov	a,r3
	swap	a
	anl	a,#0x0f
	mov	r3,a
L004002?:
;	C:\Source\call51\Examples\c\Tetris52.c:174: return ((j&0x7)|(j&0x8?0x80:0));
	mov	a,#0x07
	anl	a,r3
	mov	r2,a
	mov	a,r3
	jnb	acc.3,L004005?
	mov	r3,#0x80
	sjmp	L004006?
L004005?:
	mov	r3,#0x00
L004006?:
	mov	a,r3
	orl	a,r2
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_c51_external_startup'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:177: unsigned char _c51_external_startup(void)
;	-----------------------------------------
;	 function _c51_external_startup
;	-----------------------------------------
__c51_external_startup:
;	C:\Source\call51\Examples\c\Tetris52.c:179: RCAP2H=HIGH(TIMER_2_RELOAD);
	mov	_RCAP2H,#0xFF
;	C:\Source\call51\Examples\c\Tetris52.c:180: RCAP2L=LOW(TIMER_2_RELOAD);
	mov	_RCAP2L,#0xFD
;	C:\Source\call51\Examples\c\Tetris52.c:181: T2CON=0x34; // #00110100B
	mov	_T2CON,#0x34
;	C:\Source\call51\Examples\c\Tetris52.c:182: SCON=0x52; // Serial port in mode 1, ren, txrdy, rxempty
	mov	_SCON,#0x52
;	C:\Source\call51\Examples\c\Tetris52.c:184: TR0=0;
	clr	_TR0
;	C:\Source\call51\Examples\c\Tetris52.c:185: TMOD=0x02;  //Both timer 0 and 1 in autoreload mode
	mov	_TMOD,#0x02
;	C:\Source\call51\Examples\c\Tetris52.c:186: TH0=TL0=0-91; //Use a prime number to generate 'ramdom' numbers
	mov	_TL0,#0xA5
	mov	_TH0,#0xA5
;	C:\Source\call51\Examples\c\Tetris52.c:187: TR0=1;
	setb	_TR0
;	C:\Source\call51\Examples\c\Tetris52.c:189: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:192: void putchar(char c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\Tetris52.c:194: if (c=='\n')
	cjne	r2,#0x0A,L006006?
;	C:\Source\call51\Examples\c\Tetris52.c:196: while (!TI);
L006001?:
;	C:\Source\call51\Examples\c\Tetris52.c:197: TI=0;
	jbc	_TI,L006017?
	sjmp	L006001?
L006017?:
;	C:\Source\call51\Examples\c\Tetris52.c:198: SBUF='\r';
	mov	_SBUF,#0x0D
;	C:\Source\call51\Examples\c\Tetris52.c:200: while (!TI);
L006006?:
;	C:\Source\call51\Examples\c\Tetris52.c:201: TI=0;
	jbc	_TI,L006018?
	sjmp	L006006?
L006018?:
;	C:\Source\call51\Examples\c\Tetris52.c:202: SBUF=c;
	mov	_SBUF,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'sendstr'
;------------------------------------------------------------
;s                         Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:205: void sendstr (char * s)
;	-----------------------------------------
;	 function sendstr
;	-----------------------------------------
_sendstr:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\Examples\c\Tetris52.c:207: while(*s)
L007004?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	jz	L007007?
;	C:\Source\call51\Examples\c\Tetris52.c:209: if(*s=='~') putchar(0x1b);
	cjne	r5,#0x7E,L007002?
	mov	dpl,#0x1B
	push	ar2
	push	ar3
	push	ar4
	lcall	_putchar
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	L007003?
L007002?:
;	C:\Source\call51\Examples\c\Tetris52.c:210: else putchar(*s);
	mov	dpl,r5
	push	ar2
	push	ar3
	push	ar4
	lcall	_putchar
	pop	ar4
	pop	ar3
	pop	ar2
L007003?:
;	C:\Source\call51\Examples\c\Tetris52.c:211: s++;
	inc	r2
	cjne	r2,#0x00,L007004?
	inc	r3
	sjmp	L007004?
L007007?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'refresh'
;------------------------------------------------------------
;XPos                      Allocated to registers r3 
;YPos                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:226: void refresh(void)
;	-----------------------------------------
;	 function refresh
;	-----------------------------------------
_refresh:
;	C:\Source\call51\Examples\c\Tetris52.c:229: for(YPos=0; YPos < SCN_HT; YPos++)
	mov	r2,#0x00
L008007?:
	clr	c
	mov	a,r2
	xrl	a,#0x80
	subb	a,#0x98
	jc	L008020?
	ljmp	L008010?
L008020?:
;	C:\Source\call51\Examples\c\Tetris52.c:231: for(XPos=0; XPos < SCN_WID; XPos++)
	mov	r3,#0x00
L008003?:
	clr	c
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x8f
	jc	L008021?
	ljmp	L008009?
L008021?:
;	C:\Source\call51\Examples\c\Tetris52.c:233: if((rscr(XPos, YPos)&0x80)==0x80)
	mov	_rscr_PARM_2,r2
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_rscr
	mov	a,dpl
	pop	ar3
	pop	ar2
	anl	a,#0x80
	mov	r4,a
	cjne	r4,#0x80,L008022?
	sjmp	L008023?
L008022?:
	ljmp	L008005?
L008023?:
;	C:\Source\call51\Examples\c\Tetris52.c:235: wscr(XPos, YPos, rscr(XPos, YPos)&0x7f);
	mov	_rscr_PARM_2,r2
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_rscr
	mov	a,dpl
	pop	ar3
	pop	ar2
	anl	a,#0x7F
	mov	_wscr_PARM_3,a
	mov	_wscr_PARM_2,r2
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_wscr
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:236: printf(GOTO_YX, YPos + 1, (XPos*2)+1); /* gotoxy(XPos, YPos) */
	clr	F0
	mov	b,#0x02
	mov	a,r3
	jnb	acc.7,L008024?
	cpl	F0
	cpl	a
	inc	a
L008024?:
	mul	ab
	jnb	F0,L008025?
	cpl	a
	add	a,#0x01
	xch	a,b
	cpl	a
	addc	a,#0x00
	xch	a,b
L008025?:
	add	a,#0x01
	mov	r4,a
	clr	a
	addc	a,b
	mov	r5,a
	mov	a,r2
	mov	r6,a
	rlc	a
	subb	a,acc
	mov	r7,a
	inc	r6
	cjne	r6,#0x00,L008026?
	inc	r7
L008026?:
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	a,#__str_0
	push	acc
	mov	a,#(__str_0 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:237: printf(DRAW_BLOCK, rscr(XPos, YPos));
	mov	_rscr_PARM_2,r2
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_rscr
	mov	r4,dpl
	mov	r5,#0x00
	push	ar4
	push	ar5
	mov	a,#__str_1
	push	acc
	mov	a,#(__str_1 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	pop	ar2
L008005?:
;	C:\Source\call51\Examples\c\Tetris52.c:231: for(XPos=0; XPos < SCN_WID; XPos++)
	inc	r3
	ljmp	L008003?
L008009?:
;	C:\Source\call51\Examples\c\Tetris52.c:229: for(YPos=0; YPos < SCN_HT; YPos++)
	inc	r2
	ljmp	L008007?
L008010?:
;	C:\Source\call51\Examples\c\Tetris52.c:242: printf(BKF_WTB);
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'blockDraw'
;------------------------------------------------------------
;YPos                      Allocated with name '_blockDraw_PARM_2'
;Color                     Allocated with name '_blockDraw_PARM_3'
;XPos                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:254: void blockDraw(char XPos, char YPos, unsigned char Color)
;	-----------------------------------------
;	 function blockDraw
;	-----------------------------------------
_blockDraw:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\Tetris52.c:256: if(XPos >= SCN_WID) XPos=SCN_WID - 1;
	clr	c
	mov	a,r2
	xrl	a,#0x80
	subb	a,#0x8f
	jc	L009002?
	mov	r2,#0x0E
L009002?:
;	C:\Source\call51\Examples\c\Tetris52.c:257: if(YPos >= SCN_HT) YPos=SCN_HT - 1;
	clr	c
	mov	a,_blockDraw_PARM_2
	xrl	a,#0x80
	subb	a,#0x98
	jc	L009004?
	mov	_blockDraw_PARM_2,#0x17
L009004?:
;	C:\Source\call51\Examples\c\Tetris52.c:259: wscr(XPos, YPos, Color|0x80);
	mov	_wscr_PARM_2,_blockDraw_PARM_2
	mov	a,#0x80
	orl	a,_blockDraw_PARM_3
	mov	_wscr_PARM_3,a
	mov	dpl,r2
	ljmp	_wscr
;------------------------------------------------------------
;Allocation info for local variables in function 'blockHit'
;------------------------------------------------------------
;YPos                      Allocated with name '_blockHit_PARM_2'
;XPos                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:269: char blockHit(char XPos, char YPos)
;	-----------------------------------------
;	 function blockHit
;	-----------------------------------------
_blockHit:
;	C:\Source\call51\Examples\c\Tetris52.c:271: return(rscr(XPos, YPos)&0x7f);
	mov	_rscr_PARM_2,_blockHit_PARM_2
	lcall	_rscr
	mov	a,dpl
	anl	a,#0x7F
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'shapeDraw'
;------------------------------------------------------------
;YPos                      Allocated with name '_shapeDraw_PARM_2'
;WhichShape                Allocated with name '_shapeDraw_PARM_3'
;XPos                      Allocated to registers r2 
;Index                     Allocated to registers r6 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:283: void shapeDraw(char XPos, char YPos, char WhichShape)
;	-----------------------------------------
;	 function shapeDraw
;	-----------------------------------------
_shapeDraw:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\Tetris52.c:287: for(Index=0; Index < 4; Index++)
	mov	a,_shapeDraw_PARM_3
	mov	b,#0x0B
	mul	ab
	mov	r3,a
	add	a,#_Shapes
	mov	r4,a
	clr	a
	addc	a,#(_Shapes >> 8)
	mov	r5,a
	mov	a,#0x03
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	r6,#0x00
L011001?:
	clr	c
	mov	a,r6
	xrl	a,#0x80
	subb	a,#0x84
	jnc	L011004?
;	C:\Source\call51\Examples\c\Tetris52.c:289: blockDraw(XPos, YPos, Shapes[WhichShape].Color);
	mov	a,r3
	add	a,#_Shapes
	mov	r7,a
	clr	a
	addc	a,#(_Shapes >> 8)
	mov	r0,a
	mov	dpl,r7
	mov	dph,r0
	inc	dptr
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	_blockDraw_PARM_3,a
	mov	_blockDraw_PARM_2,_shapeDraw_PARM_2
	mov	dpl,r2
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_blockDraw
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:290: XPos += Shapes[WhichShape].Dir[Index].DeltaX;
	mov	a,r6
	add	a,r6
	mov	r7,a
	add	a,r4
	mov	dpl,a
	clr	a
	addc	a,r5
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	add	a,r2
	mov	r2,a
;	C:\Source\call51\Examples\c\Tetris52.c:291: YPos += Shapes[WhichShape].Dir[Index].DeltaY;
	mov	a,r7
	add	a,r4
	mov	r7,a
	clr	a
	addc	a,r5
	mov	r0,a
	mov	dpl,r7
	mov	dph,r0
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	add	a,_shapeDraw_PARM_2
	mov	_shapeDraw_PARM_2,a
;	C:\Source\call51\Examples\c\Tetris52.c:287: for(Index=0; Index < 4; Index++)
	inc	r6
	sjmp	L011001?
L011004?:
;	C:\Source\call51\Examples\c\Tetris52.c:293: blockDraw(XPos, YPos, Shapes[WhichShape].Color);
	mov	a,r3
	add	a,#_Shapes
	mov	r3,a
	clr	a
	addc	a,#(_Shapes >> 8)
	mov	r4,a
	mov	dpl,r3
	mov	dph,r4
	inc	dptr
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	_blockDraw_PARM_3,a
	mov	_blockDraw_PARM_2,_shapeDraw_PARM_2
	mov	dpl,r2
	ljmp	_blockDraw
;------------------------------------------------------------
;Allocation info for local variables in function 'shapeErase'
;------------------------------------------------------------
;YPos                      Allocated with name '_shapeErase_PARM_2'
;WhichShape                Allocated with name '_shapeErase_PARM_3'
;XPos                      Allocated to registers r2 
;Index                     Allocated to registers r5 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:301: void shapeErase(char XPos, char YPos, char WhichShape)
;	-----------------------------------------
;	 function shapeErase
;	-----------------------------------------
_shapeErase:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\Tetris52.c:305: for(Index=0; Index < 4; Index++)
	mov	a,_shapeErase_PARM_3
	mov	b,#0x0B
	mul	ab
	add	a,#_Shapes
	mov	r3,a
	clr	a
	addc	a,#(_Shapes >> 8)
	mov	r4,a
	mov	a,#0x03
	add	a,r3
	mov	r3,a
	clr	a
	addc	a,r4
	mov	r4,a
	mov	r5,#0x00
L012001?:
	clr	c
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x84
	jnc	L012004?
;	C:\Source\call51\Examples\c\Tetris52.c:307: blockDraw(XPos, YPos, COLOR_BLACK);
	mov	_blockDraw_PARM_2,_shapeErase_PARM_2
	mov	_blockDraw_PARM_3,#0x00
	mov	dpl,r2
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_blockDraw
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:308: XPos += Shapes[WhichShape].Dir[Index].DeltaX;
	mov	a,r5
	add	a,r5
	mov	r6,a
	add	a,r3
	mov	dpl,a
	clr	a
	addc	a,r4
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	add	a,r2
	mov	r2,a
;	C:\Source\call51\Examples\c\Tetris52.c:309: YPos += Shapes[WhichShape].Dir[Index].DeltaY;
	mov	a,r6
	add	a,r3
	mov	r6,a
	clr	a
	addc	a,r4
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	add	a,_shapeErase_PARM_2
	mov	_shapeErase_PARM_2,a
;	C:\Source\call51\Examples\c\Tetris52.c:305: for(Index=0; Index < 4; Index++)
	inc	r5
	sjmp	L012001?
L012004?:
;	C:\Source\call51\Examples\c\Tetris52.c:311: blockDraw(XPos, YPos, COLOR_BLACK);
	mov	_blockDraw_PARM_2,_shapeErase_PARM_2
	mov	_blockDraw_PARM_3,#0x00
	mov	dpl,r2
	ljmp	_blockDraw
;------------------------------------------------------------
;Allocation info for local variables in function 'shapeHit'
;------------------------------------------------------------
;YPos                      Allocated with name '_shapeHit_PARM_2'
;WhichShape                Allocated with name '_shapeHit_PARM_3'
;XPos                      Allocated to registers r2 
;Index                     Allocated to registers r5 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:321: char shapeHit(char XPos, char YPos, char WhichShape)
;	-----------------------------------------
;	 function shapeHit
;	-----------------------------------------
_shapeHit:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\Tetris52.c:325: for(Index=0; Index < 4; Index++)
	mov	a,_shapeHit_PARM_3
	mov	b,#0x0B
	mul	ab
	add	a,#_Shapes
	mov	r3,a
	clr	a
	addc	a,#(_Shapes >> 8)
	mov	r4,a
	mov	a,#0x03
	add	a,r3
	mov	r3,a
	clr	a
	addc	a,r4
	mov	r4,a
	mov	r5,#0x00
L013005?:
	clr	c
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x84
	jnc	L013008?
;	C:\Source\call51\Examples\c\Tetris52.c:327: if(blockHit(XPos, YPos)) return(1);
	mov	_blockHit_PARM_2,_shapeHit_PARM_2
	mov	dpl,r2
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_blockHit
	mov	a,dpl
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	jz	L013002?
	mov	dpl,#0x01
	ret
L013002?:
;	C:\Source\call51\Examples\c\Tetris52.c:328: XPos += Shapes[WhichShape].Dir[Index].DeltaX;
	mov	a,r5
	add	a,r5
	mov	r6,a
	add	a,r3
	mov	dpl,a
	clr	a
	addc	a,r4
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	add	a,r2
	mov	r2,a
;	C:\Source\call51\Examples\c\Tetris52.c:329: YPos += Shapes[WhichShape].Dir[Index].DeltaY;
	mov	a,r6
	add	a,r3
	mov	r6,a
	clr	a
	addc	a,r4
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	add	a,_shapeHit_PARM_2
	mov	_shapeHit_PARM_2,a
;	C:\Source\call51\Examples\c\Tetris52.c:325: for(Index=0; Index < 4; Index++)
	inc	r5
	sjmp	L013005?
L013008?:
;	C:\Source\call51\Examples\c\Tetris52.c:331: if(blockHit(XPos, YPos)) return(1);
	mov	_blockHit_PARM_2,_shapeHit_PARM_2
	mov	dpl,r2
	lcall	_blockHit
	mov	a,dpl
	jz	L013004?
	mov	dpl,#0x01
;	C:\Source\call51\Examples\c\Tetris52.c:332: return(0);
	ret
L013004?:
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'screenInit'
;------------------------------------------------------------
;XPos                      Allocated to registers r3 
;YPos                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:344: void screenInit(void)
;	-----------------------------------------
;	 function screenInit
;	-----------------------------------------
_screenInit:
;	C:\Source\call51\Examples\c\Tetris52.c:348: for(YPos=0; YPos < SCN_HT; YPos++)
	mov	r2,#0x00
L014005?:
	cjne	r2,#0x18,L014024?
L014024?:
	jnc	L014008?
;	C:\Source\call51\Examples\c\Tetris52.c:350: for(XPos=1; XPos < (SCN_WID - 1); XPos++) wscr(XPos,YPos,0x80);
	mov	r3,#0x01
L014001?:
	cjne	r3,#0x0E,L014026?
L014026?:
	jnc	L014004?
	mov	_wscr_PARM_2,r2
	mov	_wscr_PARM_3,#0x80
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_wscr
	pop	ar3
	pop	ar2
	inc	r3
	sjmp	L014001?
L014004?:
;	C:\Source\call51\Examples\c\Tetris52.c:352: wscr(0, YPos, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,r2
	mov	_wscr_PARM_3,#0x84
	mov	dpl,#0x00
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:353: wscr(SCN_WID - 1, YPos, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,r2
	mov	_wscr_PARM_3,#0x84
	mov	dpl,#0x0E
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:348: for(YPos=0; YPos < SCN_HT; YPos++)
	inc	r2
	sjmp	L014005?
L014008?:
;	C:\Source\call51\Examples\c\Tetris52.c:355: for(XPos=0; XPos < SCN_WID; XPos++)
	mov	r2,#0x00
L014009?:
	cjne	r2,#0x0F,L014028?
L014028?:
	jnc	L014013?
;	C:\Source\call51\Examples\c\Tetris52.c:358: wscr(XPos, 0, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,#0x00
	mov	_wscr_PARM_3,#0x84
	mov	dpl,r2
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:359: wscr(XPos, SCN_HT-1, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,#0x17
	mov	_wscr_PARM_3,#0x84
	mov	dpl,r2
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:355: for(XPos=0; XPos < SCN_WID; XPos++)
	inc	r2
	sjmp	L014009?
L014013?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'collapse'
;------------------------------------------------------------
;SolidRows                 Allocated to registers r2 
;Row                       Allocated to registers r3 
;Col                       Allocated to registers r5 
;Temp                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:363: void collapse(void)
;	-----------------------------------------
;	 function collapse
;	-----------------------------------------
_collapse:
;	C:\Source\call51\Examples\c\Tetris52.c:371: for(Row=1; Row < SCN_HT - 1; Row++)
	mov	r2,#0x00
	mov	r3,#0x01
L015017?:
	clr	c
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x97
	jnc	L015020?
;	C:\Source\call51\Examples\c\Tetris52.c:374: for(Col=1; Col < SCN_WID - 1; Col++)
	mov	r4,#0x00
	mov	r5,#0x01
L015013?:
	clr	c
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L015016?
;	C:\Source\call51\Examples\c\Tetris52.c:375: if(rscr(Col, Row)&0x7f) Temp++;
	mov	_rscr_PARM_2,r3
	mov	dpl,r5
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_rscr
	mov	a,dpl
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	anl	a,#0x7F
	jz	L015015?
	inc	r4
L015015?:
;	C:\Source\call51\Examples\c\Tetris52.c:374: for(Col=1; Col < SCN_WID - 1; Col++)
	inc	r5
	sjmp	L015013?
L015016?:
;	C:\Source\call51\Examples\c\Tetris52.c:376: if(Temp == SCN_WID - 2)
	cjne	r4,#0x0D,L015019?
;	C:\Source\call51\Examples\c\Tetris52.c:379: wscr(0, Row, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,r3
	mov	_wscr_PARM_3,#0x84
	mov	dpl,#0x00
	push	ar2
	push	ar3
	lcall	_wscr
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:380: SolidRows++;
	inc	r2
;	C:\Source\call51\Examples\c\Tetris52.c:381: Level++;
	inc	_Level
	clr	a
	cjne	a,_Level,L015061?
	inc	(_Level + 1)
L015061?:
L015019?:
;	C:\Source\call51\Examples\c\Tetris52.c:371: for(Row=1; Row < SCN_HT - 1; Row++)
	inc	r3
	sjmp	L015017?
L015020?:
;	C:\Source\call51\Examples\c\Tetris52.c:384: if(SolidRows == 0) return;
	mov	a,r2
	jnz	L015006?
	ret
L015006?:
;	C:\Source\call51\Examples\c\Tetris52.c:386: Score+=bonus[SolidRows]; /* Bonus! */
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	dptr,#_collapse_bonus_1_71
	movc	a,@a+dptr
	xch	a,r2
	inc	dptr
	movc	a,@a+dptr
	mov	r3,a
	mov	a,r2
	add	a,_Score
	mov	_Score,a
	mov	a,r3
	addc	a,(_Score + 1)
	mov	(_Score + 1),a
;	C:\Source\call51\Examples\c\Tetris52.c:389: for(Temp=Row=SCN_HT - 2; Row > 0; Row--, Temp--)
	mov	r2,#0x16
	mov	r3,#0x16
L015029?:
	clr	c
	clr	a
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jc	L015063?
	ljmp	L015032?
L015063?:
;	C:\Source\call51\Examples\c\Tetris52.c:391: while(rscr(0, Temp)&0x80) Temp--;
	mov	ar4,r2
L015007?:
	mov	_rscr_PARM_2,r4
	mov	dpl,#0x00
	push	ar3
	push	ar4
	lcall	_rscr
	mov	a,dpl
	pop	ar4
	pop	ar3
	jnb	acc.7,L015051?
	dec	r4
	mov	ar2,r4
	sjmp	L015007?
L015051?:
	mov	ar2,r4
;	C:\Source\call51\Examples\c\Tetris52.c:392: if(Temp < 1)
	clr	c
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x81
	jnc	L015048?
;	C:\Source\call51\Examples\c\Tetris52.c:394: for(Col=1; Col < SCN_WID - 1; Col++)
	mov	r4,#0x01
L015021?:
	clr	c
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L015031?
;	C:\Source\call51\Examples\c\Tetris52.c:395: wscr(Col, Row, COLOR_BLACK|0x80);
	mov	_wscr_PARM_2,r3
	mov	_wscr_PARM_3,#0x80
	mov	dpl,r4
	push	ar2
	push	ar3
	push	ar4
	lcall	_wscr
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:394: for(Col=1; Col < SCN_WID - 1; Col++)
	inc	r4
;	C:\Source\call51\Examples\c\Tetris52.c:399: for(Col=1; Col < SCN_WID - 1; Col++)
	sjmp	L015021?
L015048?:
	mov	r4,#0x01
L015025?:
	clr	c
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L015031?
;	C:\Source\call51\Examples\c\Tetris52.c:400: wscr(Col, Row, rscr(Col,Temp)|0x80);
	mov	_rscr_PARM_2,r2
	mov	dpl,r4
	push	ar2
	push	ar3
	push	ar4
	lcall	_rscr
	mov	a,dpl
	pop	ar4
	pop	ar3
	orl	a,#0x80
	mov	_wscr_PARM_3,a
	mov	_wscr_PARM_2,r3
	mov	dpl,r4
	push	ar3
	push	ar4
	lcall	_wscr
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\Tetris52.c:399: for(Col=1; Col < SCN_WID - 1; Col++)
	inc	r4
	sjmp	L015025?
L015031?:
;	C:\Source\call51\Examples\c\Tetris52.c:389: for(Temp=Row=SCN_HT - 2; Row > 0; Row--, Temp--)
	dec	r3
	dec	r2
	ljmp	L015029?
L015032?:
;	C:\Source\call51\Examples\c\Tetris52.c:403: refresh();
	ljmp	_refresh
;------------------------------------------------------------
;Allocation info for local variables in function 'getKey'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:406: char getKey(void)
;	-----------------------------------------
;	 function getKey
;	-----------------------------------------
_getKey:
;	C:\Source\call51\Examples\c\Tetris52.c:408: if(!RI) return 0;
	jb	_RI,L016002?
	mov	dpl,#0x00
	ret
L016002?:
;	C:\Source\call51\Examples\c\Tetris52.c:410: RI=0;
	clr	_RI
;	C:\Source\call51\Examples\c\Tetris52.c:411: switch(toupper(SBUF))
	mov	dpl,_SBUF
	lcall	_islower
	mov	a,dpl
	jz	L016020?
	mov	r2,_SBUF
	anl	ar2,#0xDF
	sjmp	L016021?
L016020?:
	mov	r2,_SBUF
L016021?:
	cjne	r2,#0x2C,L016038?
	sjmp	L016010?
L016038?:
	cjne	r2,#0x42,L016039?
	sjmp	L016011?
L016039?:
	cjne	r2,#0x49,L016040?
	sjmp	L016008?
L016040?:
	cjne	r2,#0x4A,L016041?
	sjmp	L016006?
L016041?:
	cjne	r2,#0x4B,L016042?
	sjmp	L016004?
L016042?:
	cjne	r2,#0x4C,L016043?
	sjmp	L016007?
L016043?:
	cjne	r2,#0x4D,L016044?
	sjmp	L016010?
L016044?:
	cjne	r2,#0x50,L016045?
	sjmp	L016013?
L016045?:
	cjne	r2,#0x51,L016046?
	sjmp	L016003?
L016046?:
;	C:\Source\call51\Examples\c\Tetris52.c:413: case 'Q': return KEY_QUIT;
	cjne	r2,#0x55,L016017?
	sjmp	L016005?
L016003?:
	mov	dpl,#0x01
;	C:\Source\call51\Examples\c\Tetris52.c:414: case 'K': return KEY_CCW;
	ret
L016004?:
	mov	dpl,#0x03
;	C:\Source\call51\Examples\c\Tetris52.c:415: case 'U': return KEY_CW;
	ret
L016005?:
	mov	dpl,#0x02
;	C:\Source\call51\Examples\c\Tetris52.c:416: case 'J': return KEY_LEFT;
	ret
L016006?:
	mov	dpl,#0x05
;	C:\Source\call51\Examples\c\Tetris52.c:417: case 'L': return KEY_RIGHT;
	ret
L016007?:
	mov	dpl,#0x04
;	C:\Source\call51\Examples\c\Tetris52.c:418: case 'I': return KEY_UP;
	ret
L016008?:
	mov	dpl,#0x06
;	C:\Source\call51\Examples\c\Tetris52.c:420: case 'M': return KEY_DOWN;
	ret
L016010?:
	mov	dpl,#0x07
;	C:\Source\call51\Examples\c\Tetris52.c:421: case 'B': return KEY_BEGIN;
	ret
L016011?:
	mov	dpl,#0x08
;	C:\Source\call51\Examples\c\Tetris52.c:423: while(!RI);
	ret
L016013?:
;	C:\Source\call51\Examples\c\Tetris52.c:424: RI=0;
	jbc	_RI,L016048?
	sjmp	L016013?
L016048?:
;	C:\Source\call51\Examples\c\Tetris52.c:427: }
L016017?:
;	C:\Source\call51\Examples\c\Tetris52.c:428: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'wastetime'
;------------------------------------------------------------
;j                         Allocated to registers r2 r3 
;k                         Allocated to registers r4 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:431: void wastetime(int j)
;	-----------------------------------------
;	 function wastetime
;	-----------------------------------------
_wastetime:
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\Examples\c\Tetris52.c:434: while((j--)&&(RI==0))
L017008?:
	mov	ar4,r2
	mov	ar5,r3
	dec	r2
	cjne	r2,#0xff,L017020?
	dec	r3
L017020?:
	mov	a,r4
	orl	a,r5
	jz	L017011?
	jb	_RI,L017011?
;	C:\Source\call51\Examples\c\Tetris52.c:436: for(k=0; k<delay; k++) if (RI) break;
	mov	r4,#0x00
L017003?:
	clr	c
	mov	a,r4
	subb	a,_delay
	jnc	L017008?
	jb	_RI,L017008?
	inc	r4
	sjmp	L017003?
L017011?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'exit'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:440: void exit (void)
;	-----------------------------------------
;	 function exit
;	-----------------------------------------
_exit:
;	C:\Source\call51\Examples\c\Tetris52.c:442: printf(CLEAR_SCREEN CURSOR_ON BKF_WTB);
	mov	a,#__str_3
	push	acc
	mov	a,#(__str_3 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\Tetris52.c:443: printf("Bye!");
	mov	a,#__str_4
	push	acc
	mov	a,#(__str_4 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\Tetris52.c:444: while(1);
L018002?:
	sjmp	L018002?
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;Fell                      Allocated to registers r3 
;NewShape                  Allocated to registers r4 
;NewX                      Allocated to registers r5 
;NewY                      Allocated to registers r6 
;Shape                     Allocated with name '_main_Shape_1_86'
;X                         Allocated with name '_main_X_1_86'
;Y                         Allocated with name '_main_Y_1_86'
;Key                       Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\Tetris52.c:448: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Examples\c\Tetris52.c:456: LEDRA=0;
;	C:\Source\call51\Examples\c\Tetris52.c:457: LEDRB=0;
;	C:\Source\call51\Examples\c\Tetris52.c:458: LEDRC=0;
;	C:\Source\call51\Examples\c\Tetris52.c:459: LEDG=0;
;	C:\Source\call51\Examples\c\Tetris52.c:462: printf(CLEAR_SCREEN CURSOR_OFF);
	clr	a
	mov	_LEDRA,a
	mov	_LEDRB,a
	mov	_LEDRC,a
	mov	_LEDG,a
	mov	a,#__str_5
	push	acc
	mov	a,#(__str_5 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\Tetris52.c:463: printf(GOTO_YX "TETRIS by Alexei Pazhitnov", 1, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	a,#__str_6
	push	acc
	mov	a,#(__str_6 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:464: printf(GOTO_YX "Originally by Chris Giese", 2, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	a,#__str_7
	push	acc
	mov	a,#(__str_7 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:465: printf(GOTO_YX "8052/C51 port by Jesus Calvino-Fraga", 3, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	a,#__str_8
	push	acc
	mov	a,#(__str_8 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:466: printf(GOTO_YX "'K':Rotate, 'P':Pause, 'Q':Quit", 5, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x05
	push	acc
	clr	a
	push	acc
	mov	a,#__str_9
	push	acc
	mov	a,#(__str_9 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:467: printf(GOTO_YX "'J':Left, 'L':Right, 'M':Down", 6, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x06
	push	acc
	clr	a
	push	acc
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:469: screenInit();
	lcall	_screenInit
;	C:\Source\call51\Examples\c\Tetris52.c:470: refresh();
	lcall	_refresh
;	C:\Source\call51\Examples\c\Tetris52.c:472: NEW_GAME:
L019001?:
;	C:\Source\call51\Examples\c\Tetris52.c:473: printf(BKF_WTB GOTO_YX "Press 'B' to begin", 8, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x08
	push	acc
	clr	a
	push	acc
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:475: do
L019004?:
;	C:\Source\call51\Examples\c\Tetris52.c:477: Key=getKey();
	lcall	_getKey
	mov	r2,dpl
;	C:\Source\call51\Examples\c\Tetris52.c:478: if(Key==KEY_QUIT) exit();
	cjne	r2,#0x01,L019005?
	push	ar2
	lcall	_exit
	pop	ar2
L019005?:
;	C:\Source\call51\Examples\c\Tetris52.c:479: } while (Key!=KEY_BEGIN);
	cjne	r2,#0x08,L019004?
;	C:\Source\call51\Examples\c\Tetris52.c:480: screenInit();
	lcall	_screenInit
;	C:\Source\call51\Examples\c\Tetris52.c:482: Level=1;
	mov	_Level,#0x01
	clr	a
	mov	(_Level + 1),a
;	C:\Source\call51\Examples\c\Tetris52.c:483: Score=0;
	clr	a
	mov	_Score,a
	mov	(_Score + 1),a
;	C:\Source\call51\Examples\c\Tetris52.c:484: printf(BKF_WTB GOTO_YX CLR_TO_END_LINE, 8, TEXT_POS);
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x08
	push	acc
	clr	a
	push	acc
	mov	a,#__str_12
	push	acc
	mov	a,#(__str_12 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:485: goto NEW_SHAPE;
	ljmp	L019039?
;	C:\Source\call51\Examples\c\Tetris52.c:487: while(1)
L019048?:
;	C:\Source\call51\Examples\c\Tetris52.c:489: Fell=0;
	mov	r3,#0x00
;	C:\Source\call51\Examples\c\Tetris52.c:490: NewShape=Shape;
	mov	r4,_main_Shape_1_86
;	C:\Source\call51\Examples\c\Tetris52.c:491: NewX=X;
	mov	r5,_main_X_1_86
;	C:\Source\call51\Examples\c\Tetris52.c:492: NewY=Y;
	mov	r6,_main_Y_1_86
;	C:\Source\call51\Examples\c\Tetris52.c:493: Key=getKey();
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_getKey
	mov	r2,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
;	C:\Source\call51\Examples\c\Tetris52.c:494: if(Key == 0)
	mov	a,r2
	jnz	L019008?
;	C:\Source\call51\Examples\c\Tetris52.c:496: NewY++;
	mov	a,_main_Y_1_86
	inc	a
	mov	r6,a
;	C:\Source\call51\Examples\c\Tetris52.c:497: Fell=1;
	mov	r3,#0x01
;	C:\Source\call51\Examples\c\Tetris52.c:499: wastetime(2500-((Level<42?Level:42)*50));
	clr	c
	mov	a,_Level
	subb	a,#0x2A
	mov	a,(_Level + 1)
	subb	a,#0x00
	jnc	L019052?
	mov	r7,_Level
	mov	r0,(_Level + 1)
	sjmp	L019053?
L019052?:
	mov	r7,#0x2A
	mov	r0,#0x00
L019053?:
	mov	__mulint_PARM_2,r7
	mov	(__mulint_PARM_2 + 1),r0
	mov	dptr,#0x0032
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	__mulint
	mov	r7,dpl
	mov	r0,dph
	mov	a,#0xC4
	clr	c
	subb	a,r7
	mov	dpl,a
	mov	a,#0x09
	subb	a,r0
	mov	dph,a
	lcall	_wastetime
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
L019008?:
;	C:\Source\call51\Examples\c\Tetris52.c:502: if(RI) Key=getKey();
	jnb	_RI,L019010?
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_getKey
	mov	r2,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
L019010?:
;	C:\Source\call51\Examples\c\Tetris52.c:504: if(Key != 0)
	mov	a,r2
	jz	L019034?
;	C:\Source\call51\Examples\c\Tetris52.c:506: NewY=Y;
	mov	r6,_main_Y_1_86
;	C:\Source\call51\Examples\c\Tetris52.c:507: if(Key == KEY_QUIT) break;
	cjne	r2,#0x01,L019084?
	ljmp	L019049?
L019084?:
;	C:\Source\call51\Examples\c\Tetris52.c:508: if(Key == KEY_CCW)
	cjne	r2,#0x03,L019031?
;	C:\Source\call51\Examples\c\Tetris52.c:509: NewShape=Shapes[Shape].Plus90;
	mov	a,_main_Shape_1_86
	mov	b,#0x0B
	mul	ab
	mov	dptr,#_Shapes
	movc	a,@a+dptr
	mov	r4,a
	sjmp	L019032?
L019031?:
;	C:\Source\call51\Examples\c\Tetris52.c:510: else if(Key == KEY_CW)
	cjne	r2,#0x02,L019028?
;	C:\Source\call51\Examples\c\Tetris52.c:511: NewShape=Shapes[Shape].Minus90;
	mov	a,_main_Shape_1_86
	mov	b,#0x0B
	mul	ab
	add	a,#_Shapes
	mov	r7,a
	clr	a
	addc	a,#(_Shapes >> 8)
	mov	r0,a
	mov	dpl,r7
	mov	dph,r0
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r4,a
	sjmp	L019032?
L019028?:
;	C:\Source\call51\Examples\c\Tetris52.c:512: else if(Key == KEY_LEFT)
	cjne	r2,#0x05,L019025?
;	C:\Source\call51\Examples\c\Tetris52.c:513: {	if(X) NewX=X - 1; }
	mov	a,_main_X_1_86
	jz	L019032?
	mov	a,_main_X_1_86
	dec	a
	mov	r5,a
	sjmp	L019032?
L019025?:
;	C:\Source\call51\Examples\c\Tetris52.c:514: else if(Key == KEY_RIGHT)
	cjne	r2,#0x04,L019022?
;	C:\Source\call51\Examples\c\Tetris52.c:515: {	if(X < SCN_WID - 1) NewX=X + 1; }
	clr	c
	mov	a,_main_X_1_86
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L019032?
	mov	a,_main_X_1_86
	inc	a
	mov	r5,a
	sjmp	L019032?
L019022?:
;	C:\Source\call51\Examples\c\Tetris52.c:518: else if(Key == KEY_DOWN)
	cjne	r2,#0x07,L019032?
;	C:\Source\call51\Examples\c\Tetris52.c:519: {	if(Y < SCN_HT - 1) NewY=Y + 1; }
	clr	c
	mov	a,_main_Y_1_86
	xrl	a,#0x80
	subb	a,#0x97
	jnc	L019032?
	mov	a,_main_Y_1_86
	inc	a
	mov	r6,a
L019032?:
;	C:\Source\call51\Examples\c\Tetris52.c:520: Fell=0;
	mov	r3,#0x00
L019034?:
;	C:\Source\call51\Examples\c\Tetris52.c:523: if((NewX == X) && (NewY == Y) && (NewShape == Shape))
	mov	a,r5
	cjne	a,_main_X_1_86,L019036?
	mov	a,r6
	cjne	a,_main_Y_1_86,L019036?
	mov	a,r4
	cjne	a,_main_Shape_1_86,L019102?
	ljmp	L019048?
L019102?:
;	C:\Source\call51\Examples\c\Tetris52.c:524: continue;
L019036?:
;	C:\Source\call51\Examples\c\Tetris52.c:526: shapeErase(X, Y, Shape);
	mov	_shapeErase_PARM_2,_main_Y_1_86
	mov	_shapeErase_PARM_3,_main_Shape_1_86
	mov	dpl,_main_X_1_86
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_shapeErase
	pop	ar6
	pop	ar5
	pop	ar4
;	C:\Source\call51\Examples\c\Tetris52.c:528: if(shapeHit(NewX, NewY, NewShape) == 0) /* no, update pos'n */
	mov	_shapeHit_PARM_2,r6
	mov	_shapeHit_PARM_3,r4
	mov	dpl,r5
	push	ar4
	push	ar5
	push	ar6
	lcall	_shapeHit
	mov	a,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	jnz	L019045?
;	C:\Source\call51\Examples\c\Tetris52.c:530: X=NewX;
	mov	_main_X_1_86,r5
;	C:\Source\call51\Examples\c\Tetris52.c:531: Y=NewY;
	mov	_main_Y_1_86,r6
;	C:\Source\call51\Examples\c\Tetris52.c:532: Shape=NewShape;
	mov	_main_Shape_1_86,r4
	ljmp	L019046?
L019045?:
;	C:\Source\call51\Examples\c\Tetris52.c:534: else if(Fell) /* Yes -- did the piece hit something while falling on its own? */
	mov	a,r3
	jnz	L019104?
	ljmp	L019046?
L019104?:
;	C:\Source\call51\Examples\c\Tetris52.c:536: shapeDraw(X, Y, Shape); /* Yes, draw it at the old pos'n... */
	mov	_shapeDraw_PARM_2,_main_Y_1_86
	mov	_shapeDraw_PARM_3,_main_Shape_1_86
	mov	dpl,_main_X_1_86
	lcall	_shapeDraw
;	C:\Source\call51\Examples\c\Tetris52.c:538: NEW_SHAPE:
L019039?:
;	C:\Source\call51\Examples\c\Tetris52.c:539: Y=3;
	mov	_main_Y_1_86,#0x03
;	C:\Source\call51\Examples\c\Tetris52.c:540: X=SCN_WID / 2;
	mov	_main_X_1_86,#0x07
;	C:\Source\call51\Examples\c\Tetris52.c:541: Shape=TL0 % 19; //rand() was here, use timer 0 register instead...
	mov	b,#0x13
	mov	a,_TL0
	div	ab
	mov	_main_Shape_1_86,b
;	C:\Source\call51\Examples\c\Tetris52.c:543: collapse();
	lcall	_collapse
;	C:\Source\call51\Examples\c\Tetris52.c:545: if(shapeHit(X, Y, Shape))
	mov	_shapeHit_PARM_2,#0x03
	mov	_shapeHit_PARM_3,_main_Shape_1_86
	mov	dpl,#0x07
	lcall	_shapeHit
	mov	a,dpl
	jz	L019041?
;	C:\Source\call51\Examples\c\Tetris52.c:547: printf(BKF_WTB GOTO_YX " GAME OVER ", SCN_HT/2, (SCN_WID-5));
	mov	a,#0x0A
	push	acc
	clr	a
	push	acc
	mov	a,#0x0C
	push	acc
	clr	a
	push	acc
	mov	a,#__str_13
	push	acc
	mov	a,#(__str_13 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:548: goto NEW_GAME;
	ljmp	L019001?
L019041?:
;	C:\Source\call51\Examples\c\Tetris52.c:550: Score+=Level;
	mov	a,_Level
	add	a,_Score
	mov	_Score,a
	mov	a,(_Level + 1)
	addc	a,(_Score + 1)
	mov	(_Score + 1),a
;	C:\Source\call51\Examples\c\Tetris52.c:551: printf(GOTO_YX CLR_TO_END_LINE "Level: %u", 15, TEXT_POS, Level);
	push	_Level
	push	(_Level + 1)
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x0F
	push	acc
	clr	a
	push	acc
	mov	a,#__str_14
	push	acc
	mov	a,#(__str_14 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	C:\Source\call51\Examples\c\Tetris52.c:552: printf(GOTO_YX CLR_TO_END_LINE "Score: %u", 16, TEXT_POS, Score);
	push	_Score
	push	(_Score + 1)
	mov	a,#0x20
	push	acc
	clr	a
	push	acc
	mov	a,#0x10
	push	acc
	clr	a
	push	acc
	mov	a,#__str_15
	push	acc
	mov	a,#(__str_15 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
L019046?:
;	C:\Source\call51\Examples\c\Tetris52.c:555: shapeDraw(X, Y, Shape);
	mov	_shapeDraw_PARM_2,_main_Y_1_86
	mov	_shapeDraw_PARM_3,_main_Shape_1_86
	mov	dpl,_main_X_1_86
	lcall	_shapeDraw
;	C:\Source\call51\Examples\c\Tetris52.c:556: refresh();
	lcall	_refresh
	ljmp	L019048?
L019049?:
;	C:\Source\call51\Examples\c\Tetris52.c:558: exit();
	ljmp	_exit
	rseg R_CSEG

	rseg R_CONST
_Shapes:
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x04	;  4 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x02	;  2 
	db 0x02	;  2 
	db 0x02	;  2 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x01	;  1 
	db 0x02	;  2 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x04	;  4 
	db 0x04	;  4 
	db 0x06	;  6 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x03	;  3 
	db 0x03	;  3 
	db 0x06	;  6 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x06	;  6 
	db 0x06	;  6 
	db 0x01	;  1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x05	;  5 
	db 0x05	;  5 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x08	;  8 
	db 0x0a	;  10 
	db 0x05	;  5 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x09	;  9 
	db 0x07	;  7 
	db 0x05	;  5 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x0a	;  10 
	db 0x08	;  8 
	db 0x05	;  5 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x07	;  7 
	db 0x09	;  9 
	db 0x05	;  5 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x0c	;  12 
	db 0x0e	;  14 
	db 0x03	;  3 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x0d	;  13 
	db 0x0b	;  11 
	db 0x03	;  3 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x0e	;  14 
	db 0x0c	;  12 
	db 0x03	;  3 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x0b	;  11 
	db 0x0d	;  13 
	db 0x03	;  3 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x10	;  16 
	db 0x12	;  18 
	db 0x07	;  7 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x02	;  2 
	db 0x00	;  0 
	db 0x11	;  17 
	db 0x0f	;  15 
	db 0x07	;  7 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x02	;  2 
	db 0x12	;  18 
	db 0x10	;  16 
	db 0x07	;  7 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xfe	; -2 	þ
	db 0x00	;  0 
	db 0x0f	;  15 
	db 0x11	;  17 
	db 0x07	;  7 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xff	; -1 
	db 0x00	;  0 
	db 0x00	;  0 
	db 0x01	;  1 
	db 0x00	;  0 
	db 0xfe	; -2 	þ
__str_0:
	db 0x1B
	db '[%d;%dH'
	db 0x00
__str_1:
	db 0x1B
	db '[0;4%d;37m  '
	db 0x00
__str_2:
	db 0x1B
	db '[0;47;30m'
	db 0x00
_collapse_bonus_1_71:
	db 0x00,0x00	; 0
	db 0x32,0x00	; 50
	db 0x64,0x00	; 100
	db 0xC8,0x00	; 200
	db 0x90,0x01	; 400
__str_3:
	db 0x1B
	db '[2J'
	db 0x1B
	db '[?25h'
	db 0x1B
	db '[0;47;30m'
	db 0x00
__str_4:
	db 'Bye!'
	db 0x00
__str_5:
	db 0x1B
	db '[2J'
	db 0x1B
	db '[?25l'
	db 0x00
__str_6:
	db 0x1B
	db '[%d;%dHTETRIS by Alexei Pazhitnov'
	db 0x00
__str_7:
	db 0x1B
	db '[%d;%dHOriginally by Chris Giese'
	db 0x00
__str_8:
	db 0x1B
	db '[%d;%dH8052/C51 port by Jesus Calvino-Fraga'
	db 0x00
__str_9:
	db 0x1B
	db '[%d;%dH'
	db 0x27
	db 'K'
	db 0x27
	db ':Rotate, '
	db 0x27
	db 'P'
	db 0x27
	db ':Pause, '
	db 0x27
	db 'Q'
	db 0x27
	db ':Quit'
	db 0x00
__str_10:
	db 0x1B
	db '[%d;%dH'
	db 0x27
	db 'J'
	db 0x27
	db ':Left, '
	db 0x27
	db 'L'
	db 0x27
	db ':Right, '
	db 0x27
	db 'M'
	db 0x27
	db ':Down'
	db 0x00
__str_11:
	db 0x1B
	db '[0;47;30m'
	db 0x1B
	db '[%d;%dHPress '
	db 0x27
	db 'B'
	db 0x27
	db ' to begin'
	db 0x00
__str_12:
	db 0x1B
	db '[0;47;30m'
	db 0x1B
	db '[%d;%dH'
	db 0x1B
	db '[K'
	db 0x00
__str_13:
	db 0x1B
	db '[0;47;30m'
	db 0x1B
	db '[%d;%dH GAME OVER '
	db 0x00
__str_14:
	db 0x1B
	db '[%d;%dH'
	db 0x1B
	db '[KLevel: %u'
	db 0x00
__str_15:
	db 0x1B
	db '[%d;%dH'
	db 0x1B
	db '[KScore: %u'
	db 0x00

	rseg R_XINIT

	CSEG

end
