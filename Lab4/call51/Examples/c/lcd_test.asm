;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Dec 11 2012) (MSVC)
; This file was generated Sun Jan 06 21:53:34 2013
;--------------------------------------------------------
$name lcd_test
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
	public _main
	public _LCD_puts
	public _LCD_data
	public _LCD_command
	public _Wait40us
	public _de2_8052_crt0
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
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg R_OSEG
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
;Allocation info for local variables in function 'Wait40us'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\lcd_test.c:5: void Wait40us(void)
;	-----------------------------------------
;	 function Wait40us
;	-----------------------------------------
_Wait40us:
	using	0
;	C:\Source\call51\Examples\c\lcd_test.c:12: _endasm;
	
	  push AR0
	  mov R0, #200
	 X1:
	djnz R0, X1 ; 3 machine cycles-> 3*90ns*200>40us
	     pop AR0
	    
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_command'
;------------------------------------------------------------
;c                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\lcd_test.c:37: void LCD_command (unsigned char c)
;	-----------------------------------------
;	 function LCD_command
;	-----------------------------------------
_LCD_command:
	mov	_LCD_DATA,dpl
;	C:\Source\call51\Examples\c\lcd_test.c:40: LCD_RS=0;
	clr	_LCD_RS
;	C:\Source\call51\Examples\c\lcd_test.c:41: LCD_EN=1;
	setb	_LCD_EN
;	C:\Source\call51\Examples\c\lcd_test.c:42: LCD_EN=0;
	clr	_LCD_EN
;	C:\Source\call51\Examples\c\lcd_test.c:43: Wait40us();
	ljmp	_Wait40us
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_data'
;------------------------------------------------------------
;c                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\lcd_test.c:46: void LCD_data (unsigned char c)
;	-----------------------------------------
;	 function LCD_data
;	-----------------------------------------
_LCD_data:
	mov	_LCD_DATA,dpl
;	C:\Source\call51\Examples\c\lcd_test.c:49: LCD_RS=1;
	setb	_LCD_RS
;	C:\Source\call51\Examples\c\lcd_test.c:50: LCD_EN=1;
	setb	_LCD_EN
;	C:\Source\call51\Examples\c\lcd_test.c:51: LCD_EN=0;
	clr	_LCD_EN
;	C:\Source\call51\Examples\c\lcd_test.c:52: Wait40us();
	ljmp	_Wait40us
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_puts'
;------------------------------------------------------------
;str                       Allocated to registers r2 r3 r4 
;j                         Allocated to registers r5 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\lcd_test.c:56: void LCD_puts(char * str)
;	-----------------------------------------
;	 function LCD_puts
;	-----------------------------------------
_LCD_puts:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\Examples\c\lcd_test.c:59: for(j=0; str[j]!=0; j++)
	mov	r5,#0x00
L006001?:
	mov	a,r5
	add	a,r2
	mov	r6,a
	clr	a
	addc	a,r3
	mov	r7,a
	mov	ar0,r4
	mov	dpl,r6
	mov	dph,r7
	mov	b,r0
	lcall	__gptrget
	mov	r6,a
	jz	L006005?
;	C:\Source\call51\Examples\c\lcd_test.c:61: LCD_data(str[j]);
	mov	dpl,r6
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_LCD_data
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Examples\c\lcd_test.c:59: for(j=0; str[j]!=0; j++)
	inc	r5
	sjmp	L006001?
L006005?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;j                         Allocated to registers r2 
;------------------------------------------------------------
;	C:\Source\call51\Examples\c\lcd_test.c:65: void main (void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Examples\c\lcd_test.c:70: HEX0=0xff;
	mov	_HEX0,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:71: HEX1=0xff;
	mov	_HEX1,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:72: HEX2=0xff;
	mov	_HEX2,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:73: HEX3=0xff;
	mov	_HEX3,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:74: HEX4=0xff;
	mov	_HEX4,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:75: HEX5=0xff;
	mov	_HEX5,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:76: HEX6=0xff;
	mov	_HEX6,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:77: HEX7=0xff;
	mov	_HEX7,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:78: LEDRA=0;
	mov	_LEDRA,#0x00
;	C:\Source\call51\Examples\c\lcd_test.c:79: LEDRB=0;
	mov	_LEDRB,#0x00
;	C:\Source\call51\Examples\c\lcd_test.c:80: LEDRC=0;
	mov	_LEDRC,#0x00
;	C:\Source\call51\Examples\c\lcd_test.c:81: LEDG=0;
	mov	_LEDG,#0x00
;	C:\Source\call51\Examples\c\lcd_test.c:85: LCD_ON=1; // Turn LCD on, and wait a bit.
	setb	_LCD_ON
;	C:\Source\call51\Examples\c\lcd_test.c:86: Wait40us();
	lcall	_Wait40us
;	C:\Source\call51\Examples\c\lcd_test.c:88: LCD_MOD=0xff; // Use LCD_DATA as output port
	mov	_LCD_MOD,#0xFF
;	C:\Source\call51\Examples\c\lcd_test.c:89: LCD_RW=0; // Only writing to the LCD in this code.
	clr	_LCD_RW
;	C:\Source\call51\Examples\c\lcd_test.c:91: LCD_command(0x0c); // Display on command
	mov	dpl,#0x0C
	lcall	_LCD_command
;	C:\Source\call51\Examples\c\lcd_test.c:92: LCD_command(0x38); // 8-bits interface, 2 lines, 5x7 characters
	mov	dpl,#0x38
	lcall	_LCD_command
;	C:\Source\call51\Examples\c\lcd_test.c:93: LCD_command(0x01); // Clear screen (Warning, very slow command!)
	mov	dpl,#0x01
	lcall	_LCD_command
;	C:\Source\call51\Examples\c\lcd_test.c:94: for(j=0; j<100; j++) Wait40us(); // Delay loop needed for 'clear screen' command above
	mov	r2,#0x64
L007003?:
	push	ar2
	lcall	_Wait40us
	pop	ar2
	djnz	r2,L007003?
;	C:\Source\call51\Examples\c\lcd_test.c:96: LCD_command(0x80); // Move to first column of first row
	mov	dpl,#0x80
	lcall	_LCD_command
;	C:\Source\call51\Examples\c\lcd_test.c:97: LCD_puts("Hello World!");
	mov	dptr,#__str_0
	mov	b,#0x80
	lcall	_LCD_puts
;	C:\Source\call51\Examples\c\lcd_test.c:99: LCD_command(0xC0); // Move to first column of second row
	mov	dpl,#0xC0
	lcall	_LCD_command
;	C:\Source\call51\Examples\c\lcd_test.c:101: LCD_puts("Second LCD line.");
	mov	dptr,#__str_1
	mov	b,#0x80
	ljmp	_LCD_puts
	rseg R_CSEG

	rseg R_CONST
__str_0:
	db 'Hello World!'
	db 0x00
__str_1:
	db 'Second LCD line.'
	db 0x00

	rseg R_XINIT

	CSEG

end
