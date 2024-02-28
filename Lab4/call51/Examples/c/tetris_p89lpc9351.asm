;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #120317 (Feb 14 2012) (MSVC)
; This file was generated Sat Mar 17 00:29:08 2012
;--------------------------------------------------------
$name tetris_p89lpc9351
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
	public _collapse_bonus_1_1
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
	public _init
	public _dummyint3
	public _rscr
	public _wscr
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
_ACC            DATA 0xe0
_ADCON0         DATA 0x8e
_ADCON1         DATA 0x97
_ADINS          DATA 0xa3
_ADMODA         DATA 0xc0
_ADMODB         DATA 0xa1
_AD0BH          DATA 0xbb
_AD0BL          DATA 0xa6
_AD0DAT0        DATA 0xc5
_AD0DAT1        DATA 0xc6
_AD0DAT2        DATA 0xc7
_AD0DAT3        DATA 0xf4
_AD1BH          DATA 0xc4
_AD1BL          DATA 0xbc
_AD1DAT0        DATA 0xd5
_AD1DAT1        DATA 0xd6
_AD1DAT2        DATA 0xd7
_AD1DAT3        DATA 0xf5
_AUXR1          DATA 0xa2
_B              DATA 0xf0
_BRGR0          DATA 0xbe
_BRGR1          DATA 0xbf
_BRGCON         DATA 0xbd
_CCCRA          DATA 0xea
_CCCRB          DATA 0xeb
_CCCRC          DATA 0xec
_CCCRD          DATA 0xed
_CMP1           DATA 0xac
_CMP2           DATA 0xad
_DEECON         DATA 0xf1
_DEEDAT         DATA 0xf2
_DEEADR         DATA 0xf3
_DIVM           DATA 0x95
_DPH            DATA 0x83
_DPL            DATA 0x82
_FMADRH         DATA 0xe7
_FMADRL         DATA 0xe6
_FMCON          DATA 0xe4
_FMDATA         DATA 0xe5
_I2ADR          DATA 0xdb
_I2CON          DATA 0xd8
_I2DAT          DATA 0xda
_I2SCLH         DATA 0xdd
_I2SCLL         DATA 0xdc
_I2STAT         DATA 0xd9
_ICRAH          DATA 0xab
_ICRAL          DATA 0xaa
_ICRBH          DATA 0xaf
_ICRBL          DATA 0xae
_IEN0           DATA 0xa8
_IEN1           DATA 0xe8
_IP0            DATA 0xb8
_IP0H           DATA 0xb7
_IP1            DATA 0xf8
_IP1H           DATA 0xf7
_KBCON          DATA 0x94
_KBMASK         DATA 0x86
_KBPATN         DATA 0x93
_OCRAH          DATA 0xef
_OCRAL          DATA 0xee
_OCRBH          DATA 0xfb
_OCRBL          DATA 0xfa
_OCRCH          DATA 0xfd
_OCRCL          DATA 0xfc
_OCRDH          DATA 0xff
_OCRDL          DATA 0xfe
_P0             DATA 0x80
_P1             DATA 0x90
_P2             DATA 0xa0
_P3             DATA 0xb0
_P0M1           DATA 0x84
_P0M2           DATA 0x85
_P1M1           DATA 0x91
_P1M2           DATA 0x92
_P2M1           DATA 0xa4
_P2M2           DATA 0xa5
_P3M1           DATA 0xb1
_P3M2           DATA 0xb2
_PCON           DATA 0x87
_PCONA          DATA 0xb5
_PSW            DATA 0xd0
_PT0AD          DATA 0xf6
_RSTSRC         DATA 0xdf
_RTCCON         DATA 0xd1
_RTCH           DATA 0xd2
_RTCL           DATA 0xd3
_SADDR          DATA 0xa9
_SADEN          DATA 0xb9
_SBUF           DATA 0x99
_SCON           DATA 0x98
_SSTAT          DATA 0xba
_SP             DATA 0x81
_SPCTL          DATA 0xe2
_SPSTAT         DATA 0xe1
_SPDAT          DATA 0xe3
_TAMOD          DATA 0x8f
_TCON           DATA 0x88
_TCR20          DATA 0xc8
_TCR21          DATA 0xf9
_TH0            DATA 0x8c
_TH1            DATA 0x8d
_TH2            DATA 0xcd
_TICR2          DATA 0xc9
_TIFR2          DATA 0xe9
_TISE2          DATA 0xde
_TL0            DATA 0x8a
_TL1            DATA 0x8b
_TL2            DATA 0xcc
_TMOD           DATA 0x89
_TOR2H          DATA 0xcf
_TOR2L          DATA 0xce
_TPCR2H         DATA 0xcb
_TPCR2L         DATA 0xca
_TRIM           DATA 0x96
_WDCON          DATA 0xa7
_WDL            DATA 0xc1
_WFEED1         DATA 0xc2
_WFEED2         DATA 0xc3
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
_ACC_7          BIT 0xe7
_ACC_6          BIT 0xe6
_ACC_5          BIT 0xe5
_ACC_4          BIT 0xe4
_ACC_3          BIT 0xe3
_ACC_2          BIT 0xe2
_ACC_1          BIT 0xe1
_ACC_0          BIT 0xe0
_ADMODA_7       BIT 0xc7
_ADMODA_6       BIT 0xc6
_ADMODA_5       BIT 0xc5
_ADMODA_4       BIT 0xc4
_ADMODA_3       BIT 0xc3
_ADMODA_2       BIT 0xc2
_ADMODA_1       BIT 0xc1
_ADMODA_0       BIT 0xc0
_BNDI1          BIT 0xc7
_BURST1         BIT 0xc6
_SCC1           BIT 0xc5
_SCAN1          BIT 0xc4
_BNDI0          BIT 0xc3
_BURST0         BIT 0xc2
_SCC0           BIT 0xc1
_SCAN0          BIT 0xc0
_B_7            BIT 0xf7
_B_6            BIT 0xf6
_B_5            BIT 0xf5
_B_4            BIT 0xf4
_B_3            BIT 0xf3
_B_2            BIT 0xf2
_B_1            BIT 0xf1
_B_0            BIT 0xf0
_I2CON_7        BIT 0xdf
_I2CON_6        BIT 0xde
_I2CON_5        BIT 0xdd
_I2CON_4        BIT 0xdc
_I2CON_3        BIT 0xdb
_I2CON_2        BIT 0xda
_I2CON_1        BIT 0xd9
_I2CON_0        BIT 0xd8
_I2EN           BIT 0xde
_STA            BIT 0xdd
_STO            BIT 0xdc
_SI             BIT 0xdb
_AA             BIT 0xda
_CRSEL          BIT 0xd8
_IEN0_7         BIT 0xaf
_IEN0_6         BIT 0xae
_IEN0_5         BIT 0xad
_IEN0_4         BIT 0xac
_IEN0_3         BIT 0xab
_IEN0_2         BIT 0xaa
_IEN0_1         BIT 0xa9
_IEN0_0         BIT 0xa8
_EA             BIT 0xaf
_EWDRT          BIT 0xae
_EBO            BIT 0xad
_ES             BIT 0xac
_ESR            BIT 0xac
_ET1            BIT 0xab
_EX1            BIT 0xaa
_ET0            BIT 0xa9
_EX0            BIT 0xa8
_IEN1_7         BIT 0xef
_IEN1_6         BIT 0xee
_IEN1_5         BIT 0xed
_IEN1_4         BIT 0xec
_IEN1_3         BIT 0xeb
_IEN1_2         BIT 0xea
_IEN1_1         BIT 0xe9
_IEN1_0         BIT 0xe8
_EADEE          BIT 0xef
_EST            BIT 0xee
_ECCU           BIT 0xec
_ESPI           BIT 0xeb
_EC             BIT 0xea
_EKBI           BIT 0xe9
_EI2C           BIT 0xe8
_IP0_7          BIT 0xbf
_IP0_6          BIT 0xbe
_IP0_5          BIT 0xbd
_IP0_4          BIT 0xbc
_IP0_3          BIT 0xbb
_IP0_2          BIT 0xba
_IP0_1          BIT 0xb9
_IP0_0          BIT 0xb8
_PWDRT          BIT 0xbe
_PBO            BIT 0xbd
_PS             BIT 0xbc
_PSR            BIT 0xbc
_PT1            BIT 0xbb
_PX1            BIT 0xba
_PT0            BIT 0xb9
_PX0            BIT 0xb8
_IP1_7          BIT 0xff
_IP1_6          BIT 0xfe
_IP1_5          BIT 0xfd
_IP1_4          BIT 0xfc
_IP1_3          BIT 0xfb
_IP1_2          BIT 0xfa
_IP1_1          BIT 0xf9
_IP1_0          BIT 0xf8
_PADEE          BIT 0xff
_PST            BIT 0xfe
_PCCU           BIT 0xfc
_PSPI           BIT 0xfb
_PC             BIT 0xfa
_PKBI           BIT 0xf9
_PI2C           BIT 0xf8
_P0_7           BIT 0x87
_P0_6           BIT 0x86
_P0_5           BIT 0x85
_P0_4           BIT 0x84
_P0_3           BIT 0x83
_P0_2           BIT 0x82
_P0_1           BIT 0x81
_P0_0           BIT 0x80
_T1             BIT 0x87
_KB7            BIT 0x87
_CMP_1          BIT 0x86
_KB6            BIT 0x86
_CMPREF         BIT 0x85
_KB5            BIT 0x85
_CIN1A          BIT 0x84
_KB4            BIT 0x84
_CIN1B          BIT 0x83
_KB3            BIT 0x83
_CIN2A          BIT 0x82
_KB2            BIT 0x82
_CIN2B          BIT 0x81
_KB1            BIT 0x81
_CMP_2          BIT 0x80
_KB0            BIT 0x80
_P1_7           BIT 0x97
_P1_6           BIT 0x96
_P1_5           BIT 0x95
_P1_4           BIT 0x94
_P1_3           BIT 0x93
_P1_2           BIT 0x92
_P1_1           BIT 0x91
_P1_0           BIT 0x90
_OCC            BIT 0x97
_OCB            BIT 0x96
_RST            BIT 0x95
_INT1           BIT 0x94
_INT0           BIT 0x93
_SDA            BIT 0x93
_T0             BIT 0x92
_SCL            BIT 0x92
_RXD            BIT 0x91
_TXD            BIT 0x90
_P2_7           BIT 0xa7
_P2_6           BIT 0xa6
_P2_5           BIT 0xa5
_P2_4           BIT 0xa4
_P2_3           BIT 0xa3
_P2_2           BIT 0xa2
_P2_1           BIT 0xa1
_P2_0           BIT 0xa0
_ICA            BIT 0xa7
_OCA            BIT 0xa6
_SPICLK         BIT 0xa5
_SS             BIT 0xa4
_MISO           BIT 0xa3
_MOSI           BIT 0xa2
_OCD            BIT 0xa1
_ICB            BIT 0xa0
_P3_7           BIT 0xb7
_P3_6           BIT 0xb6
_P3_5           BIT 0xb5
_P3_4           BIT 0xb4
_P3_3           BIT 0xb3
_P3_2           BIT 0xb2
_P3_1           BIT 0xb1
_P3_0           BIT 0xb0
_XTAL1          BIT 0xb1
_XTAL2          BIT 0xb0
_PSW_7          BIT 0xd7
_PSW_6          BIT 0xd6
_PSW_5          BIT 0xd5
_PSW_4          BIT 0xd4
_PSW_3          BIT 0xd3
_PSW_2          BIT 0xd2
_PSW_1          BIT 0xd1
_PSW_0          BIT 0xd0
_CY             BIT 0xd7
_AC             BIT 0xd6
_F0             BIT 0xd5
_RS1            BIT 0xd4
_RS0            BIT 0xd3
_OV             BIT 0xd2
_F1             BIT 0xd1
_P              BIT 0xd0
_SCON_7         BIT 0x9f
_SCON_6         BIT 0x9e
_SCON_5         BIT 0x9d
_SCON_4         BIT 0x9c
_SCON_3         BIT 0x9b
_SCON_2         BIT 0x9a
_SCON_1         BIT 0x99
_SCON_0         BIT 0x98
_SM0            BIT 0x9f
_FE             BIT 0x9f
_SM1            BIT 0x9e
_SM2            BIT 0x9d
_REN            BIT 0x9c
_TB8            BIT 0x9b
_RB8            BIT 0x9a
_TI             BIT 0x99
_RI             BIT 0x98
_TCON_7         BIT 0x8f
_TCON_6         BIT 0x8e
_TCON_5         BIT 0x8d
_TCON_4         BIT 0x8c
_TCON_3         BIT 0x8b
_TCON_2         BIT 0x8a
_TCON_1         BIT 0x89
_TCON_0         BIT 0x88
_TF1            BIT 0x8f
_TR1            BIT 0x8e
_TF0            BIT 0x8d
_TR0            BIT 0x8c
_IE1            BIT 0x8b
_IT1            BIT 0x8a
_IE0            BIT 0x89
_IT0            BIT 0x88
_TCR20_7        BIT 0xcf
_TCR20_6        BIT 0xce
_TCR20_5        BIT 0xcd
_TCR20_4        BIT 0xcc
_TCR20_3        BIT 0xcb
_TCR20_2        BIT 0xca
_TCR20_1        BIT 0xc9
_TCR20_0        BIT 0xc8
_PLEEN          BIT 0xcf
_HLTRN          BIT 0xce
_HLTEN          BIT 0xcd
_ALTCD          BIT 0xcc
_ALTAB          BIT 0xcb
_TDIR2          BIT 0xca
_TMOD21         BIT 0xc9
_TMOD20         BIT 0xc8
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	rbank0 segment data overlay
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	rseg BIT_BANK
bits:
	ds 1
	b0 equ  bits.0 
	b1 equ  bits.1 
	b2 equ  bits.2 
	b3 equ  bits.3 
	b4 equ  bits.4 
	b5 equ  bits.5 
	b6 equ  bits.6 
	b7 equ  bits.7 
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
_main_Shape_1_1:
	ds 1
_main_X_1_1:
	ds 1
_main_Y_1_1:
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
_BODCFG         XDATA 0xffc8
_CLKCON         XDATA 0xffde
_PGACON1        XDATA 0xffe1
_PGACON1B       XDATA 0xffe4
_PGA1TRIM8X16X  XDATA 0xffe3
_PGA1TRIM2X4X   XDATA 0xffe2
_PGACON0        XDATA 0xffca
_PGACON0B       XDATA 0xffce
_PGA0TRIM8X16X  XDATA 0xffcd
_PGA0TRIM2X4X   XDATA 0xffcc
_RTCDATH        XDATA 0xffbf
_RTCDATL        XDATA 0xffbe
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
	CSEG at 0x001b
	ljmp	_dummyint3
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:29: unsigned char delay=((XTAL/7373000L)*40);
	mov	_delay,#0x28
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:136: unsigned int Level=0;
	clr	a
	mov	_Level,a
	mov	(_Level + 1),a
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:137: unsigned int Score=0;
	clr	a
	mov	_Score,a
	mov	(_Score + 1),a
	; The linker places a 'ret' at the end of segment R_DINIT.
;--------------------------------------------------------
; code
;--------------------------------------------------------
	rseg R_CSEG
;------------------------------------------------------------
;Allocation info for local variables in function 'wscr'
;------------------------------------------------------------
;y                         Allocated with name '_wscr_PARM_2'
;val                       Allocated with name '_wscr_PARM_3'
;x                         Allocated to registers r2 
;j                         Allocated to registers r4 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:139: void wscr (unsigned char x, unsigned char y, unsigned char val)
;	-----------------------------------------
;	 function wscr
;	-----------------------------------------
_wscr:
	using	0
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:142: j=Screen[x/2][y];
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:143: if((x&1)==0)
	mov	a,r2
	jb	acc.0,L002002?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:145: j&=0xf0;
	anl	ar4,#0xF0
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:146: Screen[x/2][y]=(j|(val&0x7)|(val&0x80?8:0));
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
	jnb	acc.7,L002006?
	mov	r6,#0x08
	sjmp	L002007?
L002006?:
	mov	r6,#0x00
L002007?:
	mov	a,r6
	orl	a,r2
	mov	@r0,a
	ret
L002002?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:150: j&=0xf;
	anl	ar4,#0x0F
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:151: Screen[x/2][y]=j|((val*0x10)&0x70)|(val&0x80);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:155: unsigned char rscr (unsigned char x, unsigned char y)
;	-----------------------------------------
;	 function rscr
;	-----------------------------------------
_rscr:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:158: j=Screen[x/2][y];
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:159: if(x&1) j/=0x10;
	mov	a,r2
	jnb	acc.0,L003002?
	mov	a,r3
	swap	a
	anl	a,#0x0f
	mov	r3,a
L003002?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:160: return ((j&0x7)|(j&0x8?0x80:0));
	mov	a,#0x07
	anl	a,r3
	mov	r2,a
	mov	a,r3
	jnb	acc.3,L003005?
	mov	r3,#0x80
	sjmp	L003006?
L003005?:
	mov	r3,#0x00
L003006?:
	mov	a,r3
	orl	a,r2
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dummyint3'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:163: void dummyint3 (void) interrupt 3
;	-----------------------------------------
;	 function dummyint3
;	-----------------------------------------
_dummyint3:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:165: printf("Not running under the debugger!\n");
	mov	a,#__str_0
	push	acc
	mov	a,#(__str_0 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:166: while(1);
L004002?:
	sjmp	L004002?
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'init'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:169: unsigned char init (void)
;	-----------------------------------------
;	 function init
;	-----------------------------------------
_init:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:171: BRGCON=0;
	mov	_BRGCON,#0x00
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:172: BRGR1=BRGR/0x100;
	mov	_BRGR1,#0x00
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:173: BRGR0=BRGR%0x100;
	mov	_BRGR0,#0x30
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:174: BRGCON=3;
	mov	_BRGCON,#0x03
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:175: SCON=0x52;
	mov	_SCON,#0x52
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:177: P1M1=0;
	mov	_P1M1,#0x00
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:178: P1M2=0;
	mov	_P1M2,#0x00
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:180: TR0=0;
	clr	_TR0
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:181: TMOD=0x02;  //Timer 0 in autoreload mode
	mov	_TMOD,#0x02
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:182: TH0=TL0=0-91; //Use a prime number to generate 'ramdom' numbers
	mov	_TL0,#0xA5
	mov	_TH0,#0xA5
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:183: TR0=1;
	setb	_TR0
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:185: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:188: void putchar(char c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:190: if (c=='\n')
	cjne	r2,#0x0A,L006006?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:192: while (!TI);
L006001?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:193: TI=0;
	jbc	_TI,L006017?
	sjmp	L006001?
L006017?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:194: SBUF='\r';
	mov	_SBUF,#0x0D
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:196: while (!TI);
L006006?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:197: TI=0;
	jbc	_TI,L006018?
	sjmp	L006006?
L006018?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:198: SBUF=c;
	mov	_SBUF,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'refresh'
;------------------------------------------------------------
;XPos                      Allocated to registers r3 
;YPos                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:211: void refresh(void)
;	-----------------------------------------
;	 function refresh
;	-----------------------------------------
_refresh:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:215: for(YPos=0; YPos < SCN_HT; YPos++)
	mov	r2,#0x00
L007007?:
	clr	c
	mov	a,r2
	xrl	a,#0x80
	subb	a,#0x98
	jc	L007020?
	ljmp	L007010?
L007020?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:217: for(XPos=0; XPos < SCN_WID; XPos++)
	mov	r3,#0x00
L007003?:
	clr	c
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x8f
	jc	L007021?
	ljmp	L007009?
L007021?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:219: if((rscr(XPos, YPos)&0x80)==0x80)
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
	cjne	r4,#0x80,L007022?
	sjmp	L007023?
L007022?:
	ljmp	L007005?
L007023?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:221: wscr(XPos, YPos, rscr(XPos, YPos)&0x7f);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:223: printf(GOTO_YX, YPos + 1, (XPos*2)+1);/* gotoxy(XPos, YPos) */
	clr	F0
	mov	b,#0x02
	mov	a,r3
	jnb	acc.7,L007024?
	cpl	F0
	cpl	a
	inc	a
L007024?:
	mul	ab
	jnb	F0,L007025?
	cpl	a
	add	a,#0x01
	xch	a,b
	cpl	a
	addc	a,#0x00
	xch	a,b
L007025?:
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
	cjne	r6,#0x00,L007026?
	inc	r7
L007026?:
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	a,#__str_1
	push	acc
	mov	a,#(__str_1 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:225: printf("\x1B[3%dm\xDB\xDB", rscr(XPos, YPos));
	mov	_rscr_PARM_2,r2
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_rscr
	mov	r4,dpl
	mov	r5,#0x00
	push	ar4
	push	ar5
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	pop	ar2
L007005?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:217: for(XPos=0; XPos < SCN_WID; XPos++)
	inc	r3
	ljmp	L007003?
L007009?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:215: for(YPos=0; YPos < SCN_HT; YPos++)
	inc	r2
	ljmp	L007007?
L007010?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:230: printf(BKF_WTB);
	mov	a,#__str_3
	push	acc
	mov	a,#(__str_3 >> 8)
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:242: void blockDraw(char XPos, char YPos, unsigned char Color)
;	-----------------------------------------
;	 function blockDraw
;	-----------------------------------------
_blockDraw:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:244: if(XPos >= SCN_WID) XPos=SCN_WID - 1;
	clr	c
	mov	a,r2
	xrl	a,#0x80
	subb	a,#0x8f
	jc	L008002?
	mov	r2,#0x0E
L008002?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:245: if(YPos >= SCN_HT) YPos=SCN_HT - 1;
	clr	c
	mov	a,_blockDraw_PARM_2
	xrl	a,#0x80
	subb	a,#0x98
	jc	L008004?
	mov	_blockDraw_PARM_2,#0x17
L008004?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:247: wscr(XPos, YPos, Color|0x80);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:257: char blockHit(char XPos, char YPos)
;	-----------------------------------------
;	 function blockHit
;	-----------------------------------------
_blockHit:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:259: return(rscr(XPos, YPos)&0x7f);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:271: void shapeDraw(char XPos, char YPos, char WhichShape)
;	-----------------------------------------
;	 function shapeDraw
;	-----------------------------------------
_shapeDraw:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:275: for(Index=0; Index < 4; Index++)
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
L010001?:
	clr	c
	mov	a,r6
	xrl	a,#0x80
	subb	a,#0x84
	jnc	L010004?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:277: blockDraw(XPos, YPos, Shapes[WhichShape].Color);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:278: XPos += Shapes[WhichShape].Dir[Index].DeltaX;
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:279: YPos += Shapes[WhichShape].Dir[Index].DeltaY;
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:275: for(Index=0; Index < 4; Index++)
	inc	r6
	sjmp	L010001?
L010004?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:281: blockDraw(XPos, YPos, Shapes[WhichShape].Color);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:289: void shapeErase(char XPos, char YPos, char WhichShape)
;	-----------------------------------------
;	 function shapeErase
;	-----------------------------------------
_shapeErase:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:293: for(Index=0; Index < 4; Index++)
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
L011001?:
	clr	c
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x84
	jnc	L011004?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:295: blockDraw(XPos, YPos, COLOR_BLACK);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:296: XPos += Shapes[WhichShape].Dir[Index].DeltaX;
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:297: YPos += Shapes[WhichShape].Dir[Index].DeltaY;
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:293: for(Index=0; Index < 4; Index++)
	inc	r5
	sjmp	L011001?
L011004?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:299: blockDraw(XPos, YPos, COLOR_BLACK);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:309: char shapeHit(char XPos, char YPos, char WhichShape)
;	-----------------------------------------
;	 function shapeHit
;	-----------------------------------------
_shapeHit:
	mov	r2,dpl
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:313: for(Index=0; Index < 4; Index++)
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
L012005?:
	clr	c
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x84
	jnc	L012008?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:315: if(blockHit(XPos, YPos)) return(1);
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
	jz	L012002?
	mov	dpl,#0x01
	ret
L012002?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:316: XPos += Shapes[WhichShape].Dir[Index].DeltaX;
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:317: YPos += Shapes[WhichShape].Dir[Index].DeltaY;
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:313: for(Index=0; Index < 4; Index++)
	inc	r5
	sjmp	L012005?
L012008?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:319: if(blockHit(XPos, YPos)) return(1);
	mov	_blockHit_PARM_2,_shapeHit_PARM_2
	mov	dpl,r2
	lcall	_blockHit
	mov	a,dpl
	jz	L012004?
	mov	dpl,#0x01
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:320: return(0);
	ret
L012004?:
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'screenInit'
;------------------------------------------------------------
;XPos                      Allocated to registers r3 
;YPos                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:332: void screenInit(void)
;	-----------------------------------------
;	 function screenInit
;	-----------------------------------------
_screenInit:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:336: for(YPos=0; YPos < SCN_HT; YPos++)
	mov	r2,#0x00
L013005?:
	cjne	r2,#0x18,L013024?
L013024?:
	jnc	L013008?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:338: for(XPos=1; XPos < (SCN_WID - 1); XPos++) wscr(XPos,YPos,0x80);
	mov	r3,#0x01
L013001?:
	cjne	r3,#0x0E,L013026?
L013026?:
	jnc	L013004?
	mov	_wscr_PARM_2,r2
	mov	_wscr_PARM_3,#0x80
	mov	dpl,r3
	push	ar2
	push	ar3
	lcall	_wscr
	pop	ar3
	pop	ar2
	inc	r3
	sjmp	L013001?
L013004?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:340: wscr(0, YPos, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,r2
	mov	_wscr_PARM_3,#0x84
	mov	dpl,#0x00
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:341: wscr(SCN_WID - 1, YPos, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,r2
	mov	_wscr_PARM_3,#0x84
	mov	dpl,#0x0E
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:336: for(YPos=0; YPos < SCN_HT; YPos++)
	inc	r2
	sjmp	L013005?
L013008?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:343: for(XPos=0; XPos < SCN_WID; XPos++)
	mov	r2,#0x00
L013009?:
	cjne	r2,#0x0F,L013028?
L013028?:
	jnc	L013013?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:346: wscr(XPos, 0, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,#0x00
	mov	_wscr_PARM_3,#0x84
	mov	dpl,r2
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:347: wscr(XPos, SCN_HT-1, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,#0x17
	mov	_wscr_PARM_3,#0x84
	mov	dpl,r2
	push	ar2
	lcall	_wscr
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:343: for(XPos=0; XPos < SCN_WID; XPos++)
	inc	r2
	sjmp	L013009?
L013013?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'collapse'
;------------------------------------------------------------
;SolidRows                 Allocated to registers r2 
;Row                       Allocated to registers r3 
;Col                       Allocated to registers r5 
;Temp                      Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:351: void collapse(void)
;	-----------------------------------------
;	 function collapse
;	-----------------------------------------
_collapse:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:359: for(Row=1; Row < SCN_HT - 1; Row++)
	mov	r2,#0x00
	mov	r3,#0x01
L014017?:
	clr	c
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x97
	jnc	L014020?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:362: for(Col=1; Col < SCN_WID - 1; Col++)
	mov	r4,#0x00
	mov	r5,#0x01
L014013?:
	clr	c
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L014016?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:363: if(rscr(Col, Row)&0x7f) Temp++;
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
	jz	L014015?
	inc	r4
L014015?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:362: for(Col=1; Col < SCN_WID - 1; Col++)
	inc	r5
	sjmp	L014013?
L014016?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:364: if(Temp == SCN_WID - 2)
	cjne	r4,#0x0D,L014019?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:367: wscr(0, Row, COLOR_BLUE|0x80);
	mov	_wscr_PARM_2,r3
	mov	_wscr_PARM_3,#0x84
	mov	dpl,#0x00
	push	ar2
	push	ar3
	lcall	_wscr
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:368: SolidRows++;
	inc	r2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:369: Level++;
	inc	_Level
	clr	a
	cjne	a,_Level,L014061?
	inc	(_Level + 1)
L014061?:
L014019?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:359: for(Row=1; Row < SCN_HT - 1; Row++)
	inc	r3
	sjmp	L014017?
L014020?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:372: if(SolidRows == 0) return;
	mov	a,r2
	jnz	L014006?
	ret
L014006?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:374: Score+=bonus[SolidRows]; /* Bonus! */
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	dptr,#_collapse_bonus_1_1
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:377: for(Temp=Row=SCN_HT - 2; Row > 0; Row--, Temp--)
	mov	r2,#0x16
	mov	r3,#0x16
L014029?:
	clr	c
	clr	a
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jc	L014063?
	ljmp	L014032?
L014063?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:379: while(rscr(0, Temp)&0x80) Temp--;
	mov	ar4,r2
L014007?:
	mov	_rscr_PARM_2,r4
	mov	dpl,#0x00
	push	ar3
	push	ar4
	lcall	_rscr
	mov	a,dpl
	pop	ar4
	pop	ar3
	jnb	acc.7,L014051?
	dec	r4
	mov	ar2,r4
	sjmp	L014007?
L014051?:
	mov	ar2,r4
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:380: if(Temp < 1)
	clr	c
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x81
	jnc	L014048?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:382: for(Col=1; Col < SCN_WID - 1; Col++)
	mov	r4,#0x01
L014021?:
	clr	c
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L014031?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:383: wscr(Col, Row, COLOR_BLACK|0x80);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:382: for(Col=1; Col < SCN_WID - 1; Col++)
	inc	r4
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:387: for(Col=1; Col < SCN_WID - 1; Col++)
	sjmp	L014021?
L014048?:
	mov	r4,#0x01
L014025?:
	clr	c
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L014031?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:388: wscr(Col, Row, rscr(Col,Temp)|0x80);
	mov	_rscr_PARM_2,r2
	mov	dpl,r4
	push	ar2
	push	ar3
	push	ar4
	lcall	_rscr
	mov	a,dpl
	pop	ar4
	pop	ar3
	mov	b,a
	mov	a,#0x80
	orl	a,b
	mov	_wscr_PARM_3,a
	mov	_wscr_PARM_2,r3
	mov	dpl,r4
	push	ar3
	push	ar4
	lcall	_wscr
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:387: for(Col=1; Col < SCN_WID - 1; Col++)
	inc	r4
	sjmp	L014025?
L014031?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:377: for(Temp=Row=SCN_HT - 2; Row > 0; Row--, Temp--)
	dec	r3
	dec	r2
	ljmp	L014029?
L014032?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:391: refresh();
	ljmp	_refresh
;------------------------------------------------------------
;Allocation info for local variables in function 'getKey'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:394: char getKey(void)
;	-----------------------------------------
;	 function getKey
;	-----------------------------------------
_getKey:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:396: if(!RI) return 0;
	jb	_RI,L015002?
	mov	dpl,#0x00
	ret
L015002?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:398: RI=0;
	clr	_RI
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:399: switch(toupper(SBUF))
	mov	dpl,_SBUF
	lcall	_islower
	mov	a,dpl
	jz	L015020?
	mov	r2,_SBUF
	anl	ar2,#0xDF
	sjmp	L015021?
L015020?:
	mov	r2,_SBUF
L015021?:
	cjne	r2,#0x2C,L015038?
	sjmp	L015010?
L015038?:
	cjne	r2,#0x42,L015039?
	sjmp	L015011?
L015039?:
	cjne	r2,#0x49,L015040?
	sjmp	L015008?
L015040?:
	cjne	r2,#0x4A,L015041?
	sjmp	L015006?
L015041?:
	cjne	r2,#0x4B,L015042?
	sjmp	L015004?
L015042?:
	cjne	r2,#0x4C,L015043?
	sjmp	L015007?
L015043?:
	cjne	r2,#0x4D,L015044?
	sjmp	L015010?
L015044?:
	cjne	r2,#0x50,L015045?
	sjmp	L015013?
L015045?:
	cjne	r2,#0x51,L015046?
	sjmp	L015003?
L015046?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:401: case 'Q': return KEY_QUIT;
	cjne	r2,#0x55,L015017?
	sjmp	L015005?
L015003?:
	mov	dpl,#0x01
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:402: case 'K': return KEY_CCW;
	ret
L015004?:
	mov	dpl,#0x03
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:403: case 'U': return KEY_CW;
	ret
L015005?:
	mov	dpl,#0x02
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:404: case 'J': return KEY_LEFT;
	ret
L015006?:
	mov	dpl,#0x05
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:405: case 'L': return KEY_RIGHT;
	ret
L015007?:
	mov	dpl,#0x04
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:406: case 'I': return KEY_UP;
	ret
L015008?:
	mov	dpl,#0x06
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:408: case 'M': return KEY_DOWN;
	ret
L015010?:
	mov	dpl,#0x07
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:409: case 'B': return KEY_BEGIN;
	ret
L015011?:
	mov	dpl,#0x08
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:411: while(!RI);
	ret
L015013?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:412: RI=0;
	jbc	_RI,L015048?
	sjmp	L015013?
L015048?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:415: }
L015017?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:416: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'wastetime'
;------------------------------------------------------------
;j                         Allocated to registers r2 r3 
;k                         Allocated to registers r4 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:419: void wastetime(int j)
;	-----------------------------------------
;	 function wastetime
;	-----------------------------------------
_wastetime:
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:422: while((j--)&&(RI==0))
L016008?:
	mov	ar4,r2
	mov	ar5,r3
	dec	r2
	cjne	r2,#0xff,L016020?
	dec	r3
L016020?:
	mov	a,r4
	orl	a,r5
	jz	L016011?
	jb	_RI,L016011?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:424: for(k=0; k<delay; k++) if (RI) break;
	mov	r4,#0x00
L016003?:
	clr	c
	mov	a,r4
	subb	a,_delay
	jnc	L016008?
	jb	_RI,L016008?
	inc	r4
	sjmp	L016003?
L016011?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'exit'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:428: void exit (void)
;	-----------------------------------------
;	 function exit
;	-----------------------------------------
_exit:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:430: printf(CLEAR_SCREEN CURSOR_ON BKF_WTB);
	mov	a,#__str_4
	push	acc
	mov	a,#(__str_4 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:433: _endasm; //Go back to the debugger, if present...
	
	    lcall 0x1b
	    
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;Fell                      Allocated to registers r3 
;NewShape                  Allocated to registers r4 
;NewX                      Allocated to registers r5 
;NewY                      Allocated to registers r6 
;Shape                     Allocated with name '_main_Shape_1_1'
;X                         Allocated with name '_main_X_1_1'
;Y                         Allocated with name '_main_Y_1_1'
;Key                       Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:436: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:444: init();
	lcall	_init
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:447: printf(CLEAR_SCREEN CURSOR_OFF);
	mov	a,#__str_5
	push	acc
	mov	a,#(__str_5 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:448: printf(GOTO_YX "TETRIS by Alexei Pazhitnov", 1, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:449: printf(GOTO_YX "Originally by Chris Giese", 2, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:450: printf(GOTO_YX "8052/C51 port by Jesus Calvino-Fraga", 3, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:451: printf(GOTO_YX "'K':Rotate, 'P':Pause, 'Q':Quit", 5, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:452: printf(GOTO_YX "'J':Left, 'L':Right, 'M':Down", 6, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:453: screenInit();
	lcall	_screenInit
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:454: refresh();
	lcall	_refresh
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:455: NEW_GAME:
L018001?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:456: printf(BKF_WTB GOTO_YX "Press 'B' to begin", 8, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:457: do
L018004?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:459: Key=getKey();
	lcall	_getKey
	mov	r2,dpl
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:460: if(Key==KEY_QUIT) exit();
	cjne	r2,#0x01,L018005?
	push	ar2
	lcall	_exit
	pop	ar2
L018005?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:461: } while (Key!=KEY_BEGIN);
	cjne	r2,#0x08,L018004?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:462: screenInit();
	lcall	_screenInit
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:464: Level=1;
	mov	_Level,#0x01
	clr	a
	mov	(_Level + 1),a
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:465: Score=0;
	clr	a
	mov	_Score,a
	mov	(_Score + 1),a
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:466: printf(BKF_WTB GOTO_YX CLR_TO_END_LINE, 8, TEXT_POS);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:467: goto NEW_SHAPE;
	ljmp	L018039?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:469: while(1)
L018048?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:471: Fell=0;
	mov	r3,#0x00
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:472: NewShape=Shape;
	mov	r4,_main_Shape_1_1
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:473: NewX=X;
	mov	r5,_main_X_1_1
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:474: NewY=Y;
	mov	r6,_main_Y_1_1
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:475: Key=getKey();
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:476: if(Key == 0)
	mov	a,r2
	jnz	L018008?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:478: NewY++;
	mov	a,_main_Y_1_1
	inc	a
	mov	r6,a
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:479: Fell=1;
	mov	r3,#0x01
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:481: wastetime(2500-((Level<42?Level:42)*50));
	clr	c
	mov	a,_Level
	subb	a,#0x2A
	mov	a,(_Level + 1)
	subb	a,#0x00
	jnc	L018052?
	mov	r7,_Level
	mov	r0,(_Level + 1)
	sjmp	L018053?
L018052?:
	mov	r7,#0x2A
	mov	r0,#0x00
L018053?:
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
L018008?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:484: if(RI) Key=getKey();
	jnb	_RI,L018010?
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
L018010?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:486: if(Key != 0)
	mov	a,r2
	jz	L018034?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:488: NewY=Y;
	mov	r6,_main_Y_1_1
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:489: if(Key == KEY_QUIT) break;
	cjne	r2,#0x01,L018084?
	ljmp	L018049?
L018084?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:490: if(Key == KEY_CCW)
	cjne	r2,#0x03,L018031?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:491: NewShape=Shapes[Shape].Plus90;
	mov	a,_main_Shape_1_1
	mov	b,#0x0B
	mul	ab
	mov	dptr,#_Shapes
	movc	a,@a+dptr
	mov	r4,a
	sjmp	L018032?
L018031?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:492: else if(Key == KEY_CW)
	cjne	r2,#0x02,L018028?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:493: NewShape=Shapes[Shape].Minus90;
	mov	a,_main_Shape_1_1
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
	sjmp	L018032?
L018028?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:494: else if(Key == KEY_LEFT)
	cjne	r2,#0x05,L018025?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:495: {	if(X) NewX=X - 1; }
	mov	a,_main_X_1_1
	jz	L018032?
	mov	a,_main_X_1_1
	dec	a
	mov	r5,a
	sjmp	L018032?
L018025?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:496: else if(Key == KEY_RIGHT)
	cjne	r2,#0x04,L018022?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:497: {	if(X < SCN_WID - 1) NewX=X + 1; }
	clr	c
	mov	a,_main_X_1_1
	xrl	a,#0x80
	subb	a,#0x8e
	jnc	L018032?
	mov	a,_main_X_1_1
	inc	a
	mov	r5,a
	sjmp	L018032?
L018022?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:500: else if(Key == KEY_DOWN)
	cjne	r2,#0x07,L018032?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:501: {	if(Y < SCN_HT - 1) NewY=Y + 1; }
	clr	c
	mov	a,_main_Y_1_1
	xrl	a,#0x80
	subb	a,#0x97
	jnc	L018032?
	mov	a,_main_Y_1_1
	inc	a
	mov	r6,a
L018032?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:502: Fell=0;
	mov	r3,#0x00
L018034?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:505: if((NewX == X) && (NewY == Y) && (NewShape == Shape))
	mov	a,r5
	cjne	a,_main_X_1_1,L018036?
	mov	a,r6
	cjne	a,_main_Y_1_1,L018036?
	mov	a,r4
	cjne	a,_main_Shape_1_1,L018102?
	ljmp	L018048?
L018102?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:506: continue;
L018036?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:508: shapeErase(X, Y, Shape);
	mov	_shapeErase_PARM_2,_main_Y_1_1
	mov	_shapeErase_PARM_3,_main_Shape_1_1
	mov	dpl,_main_X_1_1
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_shapeErase
	pop	ar6
	pop	ar5
	pop	ar4
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:510: if(shapeHit(NewX, NewY, NewShape) == 0) /* no, update pos'n */
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
	jnz	L018045?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:512: X=NewX;
	mov	_main_X_1_1,r5
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:513: Y=NewY;
	mov	_main_Y_1_1,r6
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:514: Shape=NewShape;
	mov	_main_Shape_1_1,r4
	ljmp	L018046?
L018045?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:516: else if(Fell) /* Yes -- did the piece hit something while falling on its own? */
	mov	a,r3
	jnz	L018104?
	ljmp	L018046?
L018104?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:518: shapeDraw(X, Y, Shape); /* Yes, draw it at the old pos'n... */
	mov	_shapeDraw_PARM_2,_main_Y_1_1
	mov	_shapeDraw_PARM_3,_main_Shape_1_1
	mov	dpl,_main_X_1_1
	lcall	_shapeDraw
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:520: NEW_SHAPE:
L018039?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:521: Y=3;
	mov	_main_Y_1_1,#0x03
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:522: X=SCN_WID / 2;
	mov	_main_X_1_1,#0x07
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:523: Shape=TL0 % 19; //rand() was here, use timer 0 register instead...
	mov	b,#0x13
	mov	a,_TL0
	div	ab
	mov	_main_Shape_1_1,b
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:524: collapse();
	lcall	_collapse
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:526: if(shapeHit(X, Y, Shape))
	mov	_shapeHit_PARM_2,#0x03
	mov	_shapeHit_PARM_3,_main_Shape_1_1
	mov	dpl,#0x07
	lcall	_shapeHit
	mov	a,dpl
	jz	L018041?
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:528: printf(BKF_WTB GOTO_YX " GAME OVER ", SCN_HT/2, (SCN_WID-5));
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:529: goto NEW_GAME;
	ljmp	L018001?
L018041?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:531: Score+=Level;
	mov	a,_Level
	add	a,_Score
	mov	_Score,a
	mov	a,(_Level + 1)
	addc	a,(_Score + 1)
	mov	(_Score + 1),a
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:532: printf(GOTO_YX CLR_TO_END_LINE "Level: %u", 15, TEXT_POS, Level);
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
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:533: printf(GOTO_YX CLR_TO_END_LINE "Score: %u", 16, TEXT_POS, Score);
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
L018046?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:536: shapeDraw(X, Y, Shape);
	mov	_shapeDraw_PARM_2,_main_Y_1_1
	mov	_shapeDraw_PARM_3,_main_Shape_1_1
	mov	dpl,_main_X_1_1
	lcall	_shapeDraw
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:537: refresh();
	lcall	_refresh
	ljmp	L018048?
L018049?:
;	C:\Source\call51\Examples\c\tetris_p89lpc9351.c:539: exit();
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
	db 'Not running under the debugger!'
	db 0x0A
	db 0x00
__str_1:
	db 0x1B
	db '[%d;%dH'
	db 0x00
__str_2:
	db 0x1B
	db '[3%dm'
	db 0xDB
	db 0xDB
	db 0x00
__str_3:
	db 0x1B
	db '[0;30;47m'
	db 0x00
_collapse_bonus_1_1:
	db 0x00,0x00	; 0
	db 0x32,0x00	; 50
	db 0x64,0x00	; 100
	db 0xC8,0x00	; 200
	db 0x90,0x01	; 400
__str_4:
	db 0x1B
	db '[2J'
	db 0x1B
	db '[?25h'
	db 0x1B
	db '[0;30;47m'
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
	db '[0;30;47m'
	db 0x1B
	db '[%d;%dHPress '
	db 0x27
	db 'B'
	db 0x27
	db ' to begin'
	db 0x00
__str_12:
	db 0x1B
	db '[0;30;47m'
	db 0x1B
	db '[%d;%dH'
	db 0x1B
	db '[K'
	db 0x00
__str_13:
	db 0x1B
	db '[0;30;47m'
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
