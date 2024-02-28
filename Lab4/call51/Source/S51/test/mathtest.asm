;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1028 (Jul 17 2012) (MSVC)
; This file was generated Sun Nov 11 13:21:30 2012
;--------------------------------------------------------
$name mathtest
$optc51 --model-small
$printf_float
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
	public _main_fstr_1_1
	public _main
	public _timer1dummy
	public __c51_external_startup
	public _ClockTicks
	public _ClockIrqHandler
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
_milliSeconds:
	ds 4
_main_x_1_1:
	ds 4
_main_y_1_1:
	ds 4
_main_z_1_1:
	ds 4
_main_ysin_1_1:
	ds 4
_main_i_1_1:
	ds 2
_main_j_1_1:
	ds 2
_main_etime_1_1:
	ds 4
_main_ltime_1_1:
	ds 4
_main_expo_1_1:
	ds 2
_main_mant_1_1:
	ds 4
_main_xx_1_1:
	ds 4
_main_sloc0_1_0:
	ds 4
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
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
	CSEG at 0x000b
	ljmp	_ClockIrqHandler
	CSEG at 0x001b
	ljmp	_timer1dummy
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
;Allocation info for local variables in function 'ClockIrqHandler'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\S51\test\mathtest.c:42: void ClockIrqHandler (void) interrupt 1 {
;	-----------------------------------------
;	 function ClockIrqHandler
;	-----------------------------------------
_ClockIrqHandler:
	using	0
	push	acc
	push	psw
	mov	psw,#0x00
;	C:\Source\call51\Source\S51\test\mathtest.c:43: TL0 = TIMER0_RELOAD_VALUE&0xff;
	mov	_TL0,#0x0A
;	C:\Source\call51\Source\S51\test\mathtest.c:44: TH0 = TIMER0_RELOAD_VALUE>>8;
	mov	_TH0,#0xFE
;	C:\Source\call51\Source\S51\test\mathtest.c:45: milliSeconds++;
	inc	_milliSeconds
	clr	a
	cjne	a,_milliSeconds,L002003?
	inc	(_milliSeconds + 1)
	cjne	a,(_milliSeconds + 1),L002003?
	inc	(_milliSeconds + 2)
	cjne	a,(_milliSeconds + 2),L002003?
	inc	(_milliSeconds + 3)
L002003?:
	pop	psw
	pop	acc
	reti
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function 'ClockTicks'
;------------------------------------------------------------
;ms                        Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Source\S51\test\mathtest.c:49: unsigned long ClockTicks(void) {
;	-----------------------------------------
;	 function ClockTicks
;	-----------------------------------------
_ClockTicks:
;	C:\Source\call51\Source\S51\test\mathtest.c:51: ET0=0;
	clr	_ET0
;	C:\Source\call51\Source\S51\test\mathtest.c:52: ms=milliSeconds;
	mov	r2,_milliSeconds
	mov	r3,(_milliSeconds + 1)
	mov	r4,(_milliSeconds + 2)
	mov	r5,(_milliSeconds + 3)
;	C:\Source\call51\Source\S51\test\mathtest.c:53: ET0=1;
	setb	_ET0
;	C:\Source\call51\Source\S51\test\mathtest.c:54: return ms;
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_c51_external_startup'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\S51\test\mathtest.c:57: unsigned char _c51_external_startup()
;	-----------------------------------------
;	 function _c51_external_startup
;	-----------------------------------------
__c51_external_startup:
;	C:\Source\call51\Source\S51\test\mathtest.c:60: TR0=0; // stop timer 0
	clr	_TR0
;	C:\Source\call51\Source\S51\test\mathtest.c:61: TMOD =(TMOD&0xf0)|0x01; // T0=16bit timer
	mov	a,#0xF0
	anl	a,_TMOD
	mov	b,a
	mov	a,#0x01
	orl	a,b
	mov	_TMOD,a
;	C:\Source\call51\Source\S51\test\mathtest.c:63: TL0 = -TIMER0_RELOAD_VALUE&0xff;
	mov	_TL0,#0xF6
;	C:\Source\call51\Source\S51\test\mathtest.c:64: TH0 = -TIMER0_RELOAD_VALUE>>8;
	mov	_TH0,#0x01
;	C:\Source\call51\Source\S51\test\mathtest.c:65: milliSeconds=0; // reset system time
	clr	a
	mov	_milliSeconds,a
	mov	(_milliSeconds + 1),a
	mov	(_milliSeconds + 2),a
	mov	(_milliSeconds + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:66: TR0=1; // start timer 0
	setb	_TR0
;	C:\Source\call51\Source\S51\test\mathtest.c:67: ET0=1; // enable timer 0 interrupt
	setb	_ET0
;	C:\Source\call51\Source\S51\test\mathtest.c:70: TR1=0; // stop timer 1
	clr	_TR1
;	C:\Source\call51\Source\S51\test\mathtest.c:71: TMOD = (TMOD&0x0f)|0x20; // T1=8bit autoreload timer
	mov	a,#0x0F
	anl	a,_TMOD
	mov	b,a
	mov	a,#0x20
	orl	a,b
	mov	_TMOD,a
;	C:\Source\call51\Source\S51\test\mathtest.c:72: PCON |= 0x80; // SMOD=1 ---> k=2: double baudrate
	orl	_PCON,#0x80
;	C:\Source\call51\Source\S51\test\mathtest.c:73: TH1=TL1=TIMER1_K2_115200;
	mov	_TL1,#0xFF
	mov	_TH1,#0xFF
;	C:\Source\call51\Source\S51\test\mathtest.c:74: TR1=1; // start timer 1
	setb	_TR1
;	C:\Source\call51\Source\S51\test\mathtest.c:76: SCON=0x52; // mode 1, ren, txrdy, rxempty
	mov	_SCON,#0x52
;	C:\Source\call51\Source\S51\test\mathtest.c:78: EA=1; // enable global interrupt
	setb	_EA
;	C:\Source\call51\Source\S51\test\mathtest.c:80: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer1dummy'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\S51\test\mathtest.c:83: void timer1dummy (void) interrupt 3 _naked
;	-----------------------------------------
;	 function timer1dummy
;	-----------------------------------------
_timer1dummy:
;	naked function: no prologue.
;	C:\Source\call51\Source\S51\test\mathtest.c:85: puts("Monitor not present\n");
	mov	dptr,#__str_0
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:86: while(1);
L005002?:
	sjmp	L005002?
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;x                         Allocated with name '_main_x_1_1'
;y                         Allocated with name '_main_y_1_1'
;z                         Allocated with name '_main_z_1_1'
;ysin                      Allocated with name '_main_ysin_1_1'
;ycos                      Allocated to registers r4 r5 r6 r7 
;i                         Allocated with name '_main_i_1_1'
;j                         Allocated with name '_main_j_1_1'
;etime                     Allocated with name '_main_etime_1_1'
;ltime                     Allocated with name '_main_ltime_1_1'
;expo                      Allocated with name '_main_expo_1_1'
;mant                      Allocated with name '_main_mant_1_1'
;xx                        Allocated with name '_main_xx_1_1'
;ci                        Allocated to registers r6 
;sloc0                     Allocated with name '_main_sloc0_1_0'
;------------------------------------------------------------
;	C:\Source\call51\Source\S51\test\mathtest.c:89: void main (void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Source\S51\test\mathtest.c:105: printf("Built %s, %s\n", __DATE__, __TIME__);
	mov	a,#__str_15
	push	acc
	mov	a,#(__str_15 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_14
	push	acc
	mov	a,#(__str_14 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_13
	push	acc
	mov	a,#(__str_13 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf7
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:107: puts("\n*** Testing atof ***");
	mov	dptr,#__str_16
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:108: for(j=0; fstr[j][0]!='x'; j++)
	clr	a
	mov	_main_j_1_1,a
	mov	(_main_j_1_1 + 1),a
L006013?:
	mov	a,_main_j_1_1
	add	a,_main_j_1_1
	mov	r4,a
	mov	a,(_main_j_1_1 + 1)
	rlc	a
	mov	r5,a
	mov	a,r4
	add	a,#_main_fstr_1_1
	mov	r4,a
	mov	a,r5
	addc	a,#(_main_fstr_1_1 >> 8)
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	cjne	r2,#0x78,L006141?
	sjmp	L006016?
L006141?:
;	C:\Source\call51\Source\S51\test\mathtest.c:110: x=atof(fstr[j]);
	mov	r2,#0x80
	mov	dpl,r6
	mov	dph,r7
	mov	b,r2
	push	ar4
	push	ar5
	lcall	_atof
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	pop	ar5
	pop	ar4
;	C:\Source\call51\Source\S51\test\mathtest.c:111: printf("%s=%14.10f\n", fstr[j], x);
	mov	dpl,r4
	mov	dph,r5
	clr	a
	movc	a,@a+dptr
	mov	r4,a
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r2,#0x80
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	push	ar4
	push	ar5
	push	ar2
	mov	a,#__str_17
	push	acc
	mov	a,#(__str_17 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:108: for(j=0; fstr[j][0]!='x'; j++)
	inc	_main_j_1_1
	clr	a
	cjne	a,_main_j_1_1,L006142?
	inc	(_main_j_1_1 + 1)
L006142?:
	ljmp	L006013?
L006016?:
;	C:\Source\call51\Source\S51\test\mathtest.c:114: xx.f=1001.0;
	mov	_main_xx_1_1,#0x00
	mov	(_main_xx_1_1 + 1),#0x40
	mov	(_main_xx_1_1 + 2),#0x7A
	mov	(_main_xx_1_1 + 3),#0x44
;	C:\Source\call51\Source\S51\test\mathtest.c:115: printf("\n0x%08x=", xx.l);
	push	_main_xx_1_1
	push	(_main_xx_1_1 + 1)
	push	(_main_xx_1_1 + 2)
	push	(_main_xx_1_1 + 3)
	mov	a,#__str_18
	push	acc
	mov	a,#(__str_18 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:116: printf("%11.8f\n", xx.f);
	push	_main_xx_1_1
	push	(_main_xx_1_1 + 1)
	push	(_main_xx_1_1 + 2)
	push	(_main_xx_1_1 + 3)
	mov	a,#__str_19
	push	acc
	mov	a,#(__str_19 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:118: puts("\n*** Testing frexp ***");
	mov	dptr,#__str_20
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:120: mant=frexpf(x, &expo);
	mov	_frexpf_PARM_2,#_main_expo_1_1
	mov	(_frexpf_PARM_2 + 1),#0x00
	mov	(_frexpf_PARM_2 + 2),#0x40
	mov	dptr,#0x0000
	mov	b,#0x7A
	mov	a,#0x44
	lcall	_frexpf
	mov	_main_mant_1_1,dpl
	mov	(_main_mant_1_1 + 1),dph
	mov	(_main_mant_1_1 + 2),b
	mov	(_main_mant_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:121: printf("%11.8f=%11.8f*(2^%d)\n", x, mant, expo);
	push	_main_expo_1_1
	push	(_main_expo_1_1 + 1)
	push	_main_mant_1_1
	push	(_main_mant_1_1 + 1)
	push	(_main_mant_1_1 + 2)
	push	(_main_mant_1_1 + 3)
	clr	a
	push	acc
	push	acc
	mov	a,#0x7A
	push	acc
	mov	a,#0x44
	push	acc
	mov	a,#__str_21
	push	acc
	mov	a,#(__str_21 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:123: puts("\n*** Testing ldexp ***");
	mov	dptr,#__str_22
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:124: y=ldexpf(mant, expo);
	mov	_ldexpf_PARM_2,_main_expo_1_1
	mov	(_ldexpf_PARM_2 + 1),(_main_expo_1_1 + 1)
	mov	dpl,_main_mant_1_1
	mov	dph,(_main_mant_1_1 + 1)
	mov	b,(_main_mant_1_1 + 2)
	mov	a,(_main_mant_1_1 + 3)
	lcall	_ldexpf
	mov	r6,dpl
	mov	r7,dph
	mov	r2,b
	mov	r3,a
	mov	_main_y_1_1,r6
	mov	(_main_y_1_1 + 1),r7
	mov	(_main_y_1_1 + 2),r2
	mov	(_main_y_1_1 + 3),r3
;	C:\Source\call51\Source\S51\test\mathtest.c:125: printf("%11.8f*(2^%d)=%11.8f\n", mant, expo, y);
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	push	_main_expo_1_1
	push	(_main_expo_1_1 + 1)
	push	_main_mant_1_1
	push	(_main_mant_1_1 + 1)
	push	(_main_mant_1_1 + 2)
	push	(_main_mant_1_1 + 3)
	mov	a,#__str_23
	push	acc
	mov	a,#(__str_23 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:127: ltime=ClockTicks();
	lcall	_ClockTicks
	mov	_main_ltime_1_1,dpl
	mov	(_main_ltime_1_1 + 1),dph
	mov	(_main_ltime_1_1 + 2),b
	mov	(_main_ltime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:128: for(ci=0; ci<100; ci++);
	mov	r6,#0x64
L006019?:
	djnz	r6,L006019?
;	C:\Source\call51\Source\S51\test\mathtest.c:129: ltime=ClockTicks()-ltime;
	lcall	_ClockTicks
	mov	r6,dpl
	mov	r7,dph
	mov	r2,b
	mov	r3,a
	mov	a,r6
	clr	c
	subb	a,_main_ltime_1_1
	mov	_main_ltime_1_1,a
	mov	a,r7
	subb	a,(_main_ltime_1_1 + 1)
	mov	(_main_ltime_1_1 + 1),a
	mov	a,r2
	subb	a,(_main_ltime_1_1 + 2)
	mov	(_main_ltime_1_1 + 2),a
	mov	a,r3
	subb	a,(_main_ltime_1_1 + 3)
	mov	(_main_ltime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:131: puts("\n*** Testing sqrt(x) ****");
	mov	dptr,#__str_24
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:133: etime=ClockTicks();
	lcall	_ClockTicks
	mov	_main_etime_1_1,dpl
	mov	(_main_etime_1_1 + 1),dph
	mov	(_main_etime_1_1 + 2),b
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:134: for(ci=0; ci<100; ci++)
	mov	r6,#0x00
L006020?:
	clr	c
	mov	a,r6
	xrl	a,#0x80
	subb	a,#0xe4
	jnc	L006023?
;	C:\Source\call51\Source\S51\test\mathtest.c:136: sqrtf(0.1*ci);
	mov	dpl,r6
	push	ar6
	lcall	___schar2fs
	mov	r7,dpl
	mov	r2,dph
	mov	r3,b
	mov	r4,a
	push	ar7
	push	ar2
	push	ar3
	push	ar4
	mov	dptr,#0xCCCD
	mov	b,#0xCC
	mov	a,#0x3D
	lcall	___fsmul
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
	lcall	_sqrtf
	pop	ar6
;	C:\Source\call51\Source\S51\test\mathtest.c:134: for(ci=0; ci<100; ci++)
	inc	r6
	sjmp	L006020?
L006023?:
;	C:\Source\call51\Source\S51\test\mathtest.c:138: etime=ClockTicks()-etime;
	lcall	_ClockTicks
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,r2
	clr	c
	subb	a,_main_etime_1_1
	mov	_main_etime_1_1,a
	mov	a,r3
	subb	a,(_main_etime_1_1 + 1)
	mov	(_main_etime_1_1 + 1),a
	mov	a,r4
	subb	a,(_main_etime_1_1 + 2)
	mov	(_main_etime_1_1 + 2),a
	mov	a,r5
	subb	a,(_main_etime_1_1 + 3)
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:139: printf("      Average sqrtf(x) execution time: %f ms\n", (etime-ltime)/100.0);
	mov	a,_main_etime_1_1
	clr	c
	subb	a,_main_ltime_1_1
	mov	r2,a
	mov	a,(_main_etime_1_1 + 1)
	subb	a,(_main_ltime_1_1 + 1)
	mov	r3,a
	mov	a,(_main_etime_1_1 + 2)
	subb	a,(_main_ltime_1_1 + 2)
	mov	r4,a
	mov	a,(_main_etime_1_1 + 3)
	subb	a,(_main_ltime_1_1 + 3)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	___slong2fs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	clr	a
	push	acc
	push	acc
	mov	a,#0xC8
	push	acc
	mov	a,#0x42
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
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
	mov	a,#__str_25
	push	acc
	mov	a,#(__str_25 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:141: for(i=0; i<10; i++)
	mov	r2,#0x00
	mov	r3,#0x00
L006024?:
	clr	c
	mov	a,r2
	subb	a,#0x0A
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	L006027?
;	C:\Source\call51\Source\S51\test\mathtest.c:143: x=i;
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
;	C:\Source\call51\Source\S51\test\mathtest.c:144: y=sqrtf(x);
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	lcall	_sqrtf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	_main_y_1_1,r4
	mov	(_main_y_1_1 + 1),r5
	mov	(_main_y_1_1 + 2),r6
	mov	(_main_y_1_1 + 3),r7
;	C:\Source\call51\Source\S51\test\mathtest.c:145: printf("%5.2f %11.8f\n", x, y);
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_26
	push	acc
	mov	a,#(__str_26 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf5
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:141: for(i=0; i<10; i++)
	inc	r2
	cjne	r2,#0x00,L006024?
	inc	r3
	sjmp	L006024?
L006027?:
;	C:\Source\call51\Source\S51\test\mathtest.c:148: puts("\n*** Testing log(x) and log10(x) ***");
	mov	dptr,#__str_27
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:149: for(i=1; i<20; i++)
	mov	_main_i_1_1,#0x01
	clr	a
	mov	(_main_i_1_1 + 1),a
L006028?:
	clr	c
	mov	a,_main_i_1_1
	subb	a,#0x14
	mov	a,(_main_i_1_1 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006148?
	ljmp	L006031?
L006148?:
;	C:\Source\call51\Source\S51\test\mathtest.c:151: x=i*4.0;
	mov	dpl,_main_i_1_1
	mov	dph,(_main_i_1_1 + 1)
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x40
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:152: printf("%6.2f %11.8f %11.8f\n", x, logf(x), log10f(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_log10f
	mov	_main_sloc0_1_0,dpl
	mov	(_main_sloc0_1_0 + 1),dph
	mov	(_main_sloc0_1_0 + 2),b
	mov	(_main_sloc0_1_0 + 3),a
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_logf
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	_main_sloc0_1_0
	push	(_main_sloc0_1_0 + 1)
	push	(_main_sloc0_1_0 + 2)
	push	(_main_sloc0_1_0 + 3)
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_28
	push	acc
	mov	a,#(__str_28 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:149: for(i=1; i<20; i++)
	inc	_main_i_1_1
	clr	a
	cjne	a,_main_i_1_1,L006149?
	inc	(_main_i_1_1 + 1)
L006149?:
	ljmp	L006028?
L006031?:
;	C:\Source\call51\Source\S51\test\mathtest.c:154: printf("%6.4f %11.8f %11.8f\n", 45.67, logf(45.67), log10f(45.67));
	mov	dptr,#0xAE14
	mov	b,#0x36
	mov	a,#0x42
	lcall	_log10f
	mov	_main_sloc0_1_0,dpl
	mov	(_main_sloc0_1_0 + 1),dph
	mov	(_main_sloc0_1_0 + 2),b
	mov	(_main_sloc0_1_0 + 3),a
	mov	dptr,#0xAE14
	mov	b,#0x36
	mov	a,#0x42
	lcall	_logf
	mov	r6,dpl
	mov	r7,dph
	mov	r2,b
	mov	r3,a
	push	_main_sloc0_1_0
	push	(_main_sloc0_1_0 + 1)
	push	(_main_sloc0_1_0 + 2)
	push	(_main_sloc0_1_0 + 3)
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	mov	a,#0x14
	push	acc
	mov	a,#0xAE
	push	acc
	mov	a,#0x36
	push	acc
	mov	a,#0x42
	push	acc
	mov	a,#__str_29
	push	acc
	mov	a,#(__str_29 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:157: puts("\n*** Testing exp(x) ***");
	mov	dptr,#__str_30
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:158: for(i=1; i<15; i++)
	mov	r2,#0x01
	mov	r3,#0x00
L006032?:
	clr	c
	mov	a,r2
	subb	a,#0x0F
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	L006035?
;	C:\Source\call51\Source\S51\test\mathtest.c:160: x=i*4.0;
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x40
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:161: printf("%6.2f %11.8f\n", x, expf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_expf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_31
	push	acc
	mov	a,#(__str_31 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf5
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:158: for(i=1; i<15; i++)
	inc	r2
	cjne	r2,#0x00,L006151?
	inc	r3
L006151?:
	ljmp	L006032?
L006035?:
;	C:\Source\call51\Source\S51\test\mathtest.c:164: puts("\n*** Testing pow(x) ***");
	mov	dptr,#__str_32
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:165: for(i=0; i<20; i++)
	mov	r2,#0x00
	mov	r3,#0x00
L006036?:
	clr	c
	mov	a,r2
	subb	a,#0x14
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006152?
	ljmp	L006039?
L006152?:
;	C:\Source\call51\Source\S51\test\mathtest.c:167: x=i*2.976545;
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x7FB7
	mov	b,#0x3E
	mov	a,#0x40
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:168: y=powf(x, 2.0);
	mov	_powf_PARM_2,#0x00
	mov	(_powf_PARM_2 + 1),#0x00
	mov	(_powf_PARM_2 + 2),#0x00
	mov	(_powf_PARM_2 + 3),#0x40
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_powf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	_main_y_1_1,r4
	mov	(_main_y_1_1 + 1),r5
	mov	(_main_y_1_1 + 2),r6
	mov	(_main_y_1_1 + 3),r7
;	C:\Source\call51\Source\S51\test\mathtest.c:169: printf("(%5.2f)^2= %11.8f\n", x, y);
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_33
	push	acc
	mov	a,#(__str_33 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf5
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:165: for(i=0; i<20; i++)
	inc	r2
	cjne	r2,#0x00,L006153?
	inc	r3
L006153?:
	ljmp	L006036?
L006039?:
;	C:\Source\call51\Source\S51\test\mathtest.c:172: puts("\n*** Testing sin(x) and cos(x) ***");
	mov	dptr,#__str_34
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:173: puts("    Please wait...");
	mov	dptr,#__str_35
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:175: x=100000.0;
	mov	_main_x_1_1,#0x00
	mov	(_main_x_1_1 + 1),#0x50
	mov	(_main_x_1_1 + 2),#0xC3
	mov	(_main_x_1_1 + 3),#0x47
;	C:\Source\call51\Source\S51\test\mathtest.c:176: etime=ClockTicks();
	lcall	_ClockTicks
	mov	_main_etime_1_1,dpl
	mov	(_main_etime_1_1 + 1),dph
	mov	(_main_etime_1_1 + 2),b
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:177: for(ci=0; ci<50; ci++)
	mov	r2,#0x32
L006042?:
;	C:\Source\call51\Source\S51\test\mathtest.c:179: x*=1.01;
	push	ar2
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	dptr,#0x47AE
	mov	b,#0x81
	mov	a,#0x3F
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	djnz	r2,L006042?
;	C:\Source\call51\Source\S51\test\mathtest.c:177: for(ci=0; ci<50; ci++)
;	C:\Source\call51\Source\S51\test\mathtest.c:181: etime=ClockTicks()-etime;
	lcall	_ClockTicks
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,r2
	clr	c
	subb	a,_main_etime_1_1
	mov	_main_etime_1_1,a
	mov	a,r3
	subb	a,(_main_etime_1_1 + 1)
	mov	(_main_etime_1_1 + 1),a
	mov	a,r4
	subb	a,(_main_etime_1_1 + 2)
	mov	(_main_etime_1_1 + 2),a
	mov	a,r5
	subb	a,(_main_etime_1_1 + 3)
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:182: printf("      Average `*` execution time: %f ms\n", (etime-ltime)/50.0);
	mov	a,_main_etime_1_1
	clr	c
	subb	a,_main_ltime_1_1
	mov	r2,a
	mov	a,(_main_etime_1_1 + 1)
	subb	a,(_main_ltime_1_1 + 1)
	mov	r3,a
	mov	a,(_main_etime_1_1 + 2)
	subb	a,(_main_ltime_1_1 + 2)
	mov	r4,a
	mov	a,(_main_etime_1_1 + 3)
	subb	a,(_main_ltime_1_1 + 3)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	___slong2fs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	clr	a
	push	acc
	push	acc
	mov	a,#0x48
	push	acc
	mov	a,#0x42
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
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
	mov	a,#__str_36
	push	acc
	mov	a,#(__str_36 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:184: etime=ClockTicks();
	lcall	_ClockTicks
	mov	_main_etime_1_1,dpl
	mov	(_main_etime_1_1 + 1),dph
	mov	(_main_etime_1_1 + 2),b
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:185: for(ci=0; ci<100; ci++)
	mov	r2,#0x64
L006045?:
;	C:\Source\call51\Source\S51\test\mathtest.c:187: sinf(0.1);
	mov	dptr,#0xCCCD
	mov	b,#0xCC
	mov	a,#0x3D
	push	ar2
	lcall	_sinf
	pop	ar2
	djnz	r2,L006045?
;	C:\Source\call51\Source\S51\test\mathtest.c:185: for(ci=0; ci<100; ci++)
;	C:\Source\call51\Source\S51\test\mathtest.c:189: etime=ClockTicks()-etime;
	lcall	_ClockTicks
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,r2
	clr	c
	subb	a,_main_etime_1_1
	mov	_main_etime_1_1,a
	mov	a,r3
	subb	a,(_main_etime_1_1 + 1)
	mov	(_main_etime_1_1 + 1),a
	mov	a,r4
	subb	a,(_main_etime_1_1 + 2)
	mov	(_main_etime_1_1 + 2),a
	mov	a,r5
	subb	a,(_main_etime_1_1 + 3)
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:190: printf("      Average sin(x) execution time: %f ms\n", (etime-ltime)/100.0);
	mov	a,_main_etime_1_1
	clr	c
	subb	a,_main_ltime_1_1
	mov	r2,a
	mov	a,(_main_etime_1_1 + 1)
	subb	a,(_main_ltime_1_1 + 1)
	mov	r3,a
	mov	a,(_main_etime_1_1 + 2)
	subb	a,(_main_ltime_1_1 + 2)
	mov	r4,a
	mov	a,(_main_etime_1_1 + 3)
	subb	a,(_main_ltime_1_1 + 3)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	___slong2fs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	clr	a
	push	acc
	push	acc
	mov	a,#0xC8
	push	acc
	mov	a,#0x42
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
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
	mov	a,#__str_37
	push	acc
	mov	a,#(__str_37 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:192: puts("    Please wait...");
	mov	dptr,#__str_35
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:194: etime=ClockTicks();
	lcall	_ClockTicks
	mov	_main_etime_1_1,dpl
	mov	(_main_etime_1_1 + 1),dph
	mov	(_main_etime_1_1 + 2),b
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:195: for(ci=0; ci<100; ci++)
	mov	r2,#0x64
L006048?:
;	C:\Source\call51\Source\S51\test\mathtest.c:197: cosf(0.1);
	mov	dptr,#0xCCCD
	mov	b,#0xCC
	mov	a,#0x3D
	push	ar2
	lcall	_cosf
	pop	ar2
	djnz	r2,L006048?
;	C:\Source\call51\Source\S51\test\mathtest.c:195: for(ci=0; ci<100; ci++)
;	C:\Source\call51\Source\S51\test\mathtest.c:199: etime=ClockTicks()-etime;
	lcall	_ClockTicks
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,r2
	clr	c
	subb	a,_main_etime_1_1
	mov	_main_etime_1_1,a
	mov	a,r3
	subb	a,(_main_etime_1_1 + 1)
	mov	(_main_etime_1_1 + 1),a
	mov	a,r4
	subb	a,(_main_etime_1_1 + 2)
	mov	(_main_etime_1_1 + 2),a
	mov	a,r5
	subb	a,(_main_etime_1_1 + 3)
	mov	(_main_etime_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:200: printf("      Average cos(x) execution time: %f ms\n\n", (etime-ltime)/100.0);
	mov	a,_main_etime_1_1
	clr	c
	subb	a,_main_ltime_1_1
	mov	r2,a
	mov	a,(_main_etime_1_1 + 1)
	subb	a,(_main_ltime_1_1 + 1)
	mov	r3,a
	mov	a,(_main_etime_1_1 + 2)
	subb	a,(_main_ltime_1_1 + 2)
	mov	r4,a
	mov	a,(_main_etime_1_1 + 3)
	subb	a,(_main_ltime_1_1 + 3)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	___slong2fs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	clr	a
	push	acc
	push	acc
	mov	a,#0xC8
	push	acc
	mov	a,#0x42
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
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
	mov	a,#__str_38
	push	acc
	mov	a,#(__str_38 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:202: for(i=0; i<35; i++)
	mov	r2,#0x00
	mov	r3,#0x00
L006049?:
	clr	c
	mov	a,r2
	subb	a,#0x23
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006160?
	ljmp	L006052?
L006160?:
;	C:\Source\call51\Source\S51\test\mathtest.c:205: if(i==31) x=1.57079633;
	cjne	r2,#0x1F,L006011?
	cjne	r3,#0x00,L006011?
	mov	_main_x_1_1,#0xDB
	mov	(_main_x_1_1 + 1),#0x0F
	mov	(_main_x_1_1 + 2),#0xC9
	mov	(_main_x_1_1 + 3),#0x3F
	sjmp	L006012?
L006011?:
;	C:\Source\call51\Source\S51\test\mathtest.c:206: else if(i==32) x=0.78539816;
	cjne	r2,#0x20,L006008?
	cjne	r3,#0x00,L006008?
	mov	_main_x_1_1,#0xDB
	mov	(_main_x_1_1 + 1),#0x0F
	mov	(_main_x_1_1 + 2),#0x49
	mov	(_main_x_1_1 + 3),#0x3F
	sjmp	L006012?
L006008?:
;	C:\Source\call51\Source\S51\test\mathtest.c:207: else if(i==33) x=3.14159265;
	cjne	r2,#0x21,L006005?
	cjne	r3,#0x00,L006005?
	mov	_main_x_1_1,#0xDB
	mov	(_main_x_1_1 + 1),#0x0F
	mov	(_main_x_1_1 + 2),#0x49
	mov	(_main_x_1_1 + 3),#0x40
	sjmp	L006012?
L006005?:
;	C:\Source\call51\Source\S51\test\mathtest.c:208: else if(i==34) x=6.28318531;
	cjne	r2,#0x22,L006002?
	cjne	r3,#0x00,L006002?
	mov	_main_x_1_1,#0xDB
	mov	(_main_x_1_1 + 1),#0x0F
	mov	(_main_x_1_1 + 2),#0xC9
	mov	(_main_x_1_1 + 3),#0x40
	sjmp	L006012?
L006002?:
;	C:\Source\call51\Source\S51\test\mathtest.c:209: else x=i*0.2;
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0xCCCD
	mov	b,#0x4C
	mov	a,#0x3E
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	pop	ar2
L006012?:
;	C:\Source\call51\Source\S51\test\mathtest.c:211: ysin=sinf(x);
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	push	ar2
	push	ar3
	lcall	_sinf
	mov	_main_ysin_1_1,dpl
	mov	(_main_ysin_1_1 + 1),dph
	mov	(_main_ysin_1_1 + 2),b
	mov	(_main_ysin_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:212: ycos=cosf(x);
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_cosf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
;	C:\Source\call51\Source\S51\test\mathtest.c:214: printf("%5.2f %11.8f %11.8f\n", x, ysin, ycos);
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_ysin_1_1
	push	(_main_ysin_1_1 + 1)
	push	(_main_ysin_1_1 + 2)
	push	(_main_ysin_1_1 + 3)
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_39
	push	acc
	mov	a,#(__str_39 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:202: for(i=0; i<35; i++)
	inc	r2
	cjne	r2,#0x00,L006169?
	inc	r3
L006169?:
	ljmp	L006049?
L006052?:
;	C:\Source\call51\Source\S51\test\mathtest.c:217: puts("\n*** Testing tan(x) and cot(x) ***");
	mov	dptr,#__str_40
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:218: for(i=0; i<35; i++)
	clr	a
	mov	_main_i_1_1,a
	mov	(_main_i_1_1 + 1),a
L006053?:
	clr	c
	mov	a,_main_i_1_1
	subb	a,#0x23
	mov	a,(_main_i_1_1 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006170?
	ljmp	L006056?
L006170?:
;	C:\Source\call51\Source\S51\test\mathtest.c:220: x=i*0.2;
	mov	dpl,_main_i_1_1
	mov	dph,(_main_i_1_1 + 1)
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0xCCCD
	mov	b,#0x4C
	mov	a,#0x3E
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:221: printf("%5.2f %12.8f %12.8f\n", x, tanf(x), cotf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_cotf
	mov	_main_sloc0_1_0,dpl
	mov	(_main_sloc0_1_0 + 1),dph
	mov	(_main_sloc0_1_0 + 2),b
	mov	(_main_sloc0_1_0 + 3),a
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_tanf
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	_main_sloc0_1_0
	push	(_main_sloc0_1_0 + 1)
	push	(_main_sloc0_1_0 + 2)
	push	(_main_sloc0_1_0 + 3)
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_41
	push	acc
	mov	a,#(__str_41 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:218: for(i=0; i<35; i++)
	inc	_main_i_1_1
	clr	a
	cjne	a,_main_i_1_1,L006171?
	inc	(_main_i_1_1 + 1)
L006171?:
	ljmp	L006053?
L006056?:
;	C:\Source\call51\Source\S51\test\mathtest.c:224: puts("\n*** Testing asin(x) and acos(x) ***");
	mov	dptr,#__str_42
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:225: for(i=-10; i<11; i++)
	mov	_main_i_1_1,#0xF6
	mov	(_main_i_1_1 + 1),#0xFF
L006057?:
	clr	c
	mov	a,_main_i_1_1
	subb	a,#0x0B
	mov	a,(_main_i_1_1 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006172?
	ljmp	L006060?
L006172?:
;	C:\Source\call51\Source\S51\test\mathtest.c:227: x=i*0.1;
	mov	dpl,_main_i_1_1
	mov	dph,(_main_i_1_1 + 1)
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0xCCCD
	mov	b,#0xCC
	mov	a,#0x3D
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:228: printf("%5.2f %12.8f %12.8f\n", x, asinf(x), acosf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_acosf
	mov	_main_sloc0_1_0,dpl
	mov	(_main_sloc0_1_0 + 1),dph
	mov	(_main_sloc0_1_0 + 2),b
	mov	(_main_sloc0_1_0 + 3),a
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_asinf
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	_main_sloc0_1_0
	push	(_main_sloc0_1_0 + 1)
	push	(_main_sloc0_1_0 + 2)
	push	(_main_sloc0_1_0 + 3)
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_41
	push	acc
	mov	a,#(__str_41 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:225: for(i=-10; i<11; i++)
	inc	_main_i_1_1
	clr	a
	cjne	a,_main_i_1_1,L006173?
	inc	(_main_i_1_1 + 1)
L006173?:
	ljmp	L006057?
L006060?:
;	C:\Source\call51\Source\S51\test\mathtest.c:231: puts("\n*** Testing atan(x) ***");
	mov	dptr,#__str_43
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:232: for(i=-10; i<11; i++)
	mov	r2,#0xF6
	mov	r3,#0xFF
L006061?:
	clr	c
	mov	a,r2
	subb	a,#0x0B
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	L006064?
;	C:\Source\call51\Source\S51\test\mathtest.c:234: x=i*0.5;
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#(0x00&0x00ff)
	clr	a
	mov	b,a
	mov	a,#0x3F
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:235: printf("%5.2f %12.8f\n", x, atanf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_atanf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_44
	push	acc
	mov	a,#(__str_44 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf5
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:232: for(i=-10; i<11; i++)
	inc	r2
	cjne	r2,#0x00,L006175?
	inc	r3
L006175?:
	ljmp	L006061?
L006064?:
;	C:\Source\call51\Source\S51\test\mathtest.c:238: puts("\n*** Testing atan2(x) ***");
	mov	dptr,#__str_45
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:239: printf("atan( 1.0,  1.0)=%12.8f\n", atan2f( 1.0,  1.0));
	mov	_atan2f_PARM_2,#0x00
	mov	(_atan2f_PARM_2 + 1),#0x00
	mov	(_atan2f_PARM_2 + 2),#0x80
	mov	(_atan2f_PARM_2 + 3),#0x3F
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	_atan2f
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,#__str_46
	push	acc
	mov	a,#(__str_46 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:240: printf("atan(-1.0,  1.0)=%12.8f\n", atan2f(-1.0,  1.0));
	mov	_atan2f_PARM_2,#0x00
	mov	(_atan2f_PARM_2 + 1),#0x00
	mov	(_atan2f_PARM_2 + 2),#0x80
	mov	(_atan2f_PARM_2 + 3),#0x3F
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0xBF
	lcall	_atan2f
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,#__str_47
	push	acc
	mov	a,#(__str_47 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:241: printf("atan(-1.0, -1.0)=%12.8f\n", atan2f(-1.0, -1.0));
	mov	_atan2f_PARM_2,#0x00
	mov	(_atan2f_PARM_2 + 1),#0x00
	mov	(_atan2f_PARM_2 + 2),#0x80
	mov	(_atan2f_PARM_2 + 3),#0xBF
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0xBF
	lcall	_atan2f
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,#__str_48
	push	acc
	mov	a,#(__str_48 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:242: printf("atan( 1.0, -1.0)=%12.8f\n", atan2f( 1.0, -1.0));
	mov	_atan2f_PARM_2,#0x00
	mov	(_atan2f_PARM_2 + 1),#0x00
	mov	(_atan2f_PARM_2 + 2),#0x80
	mov	(_atan2f_PARM_2 + 3),#0xBF
	mov	dptr,#0x0000
	mov	b,#0x80
	mov	a,#0x3F
	lcall	_atan2f
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,#__str_49
	push	acc
	mov	a,#(__str_49 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:244: puts("\n*** Testing sinh(x) and cosh(x) ***");
	mov	dptr,#__str_50
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:245: for(i=0; i<16; i++)
	clr	a
	mov	_main_i_1_1,a
	mov	(_main_i_1_1 + 1),a
L006065?:
	clr	c
	mov	a,_main_i_1_1
	subb	a,#0x10
	mov	a,(_main_i_1_1 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006176?
	ljmp	L006068?
L006176?:
;	C:\Source\call51\Source\S51\test\mathtest.c:247: x=i*0.5;
	mov	dpl,_main_i_1_1
	mov	dph,(_main_i_1_1 + 1)
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#(0x00&0x00ff)
	clr	a
	mov	b,a
	mov	a,#0x3F
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:248: printf("%5.2f %12.8f %12.8f\n", x, sinhf(x), coshf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_coshf
	mov	_main_sloc0_1_0,dpl
	mov	(_main_sloc0_1_0 + 1),dph
	mov	(_main_sloc0_1_0 + 2),b
	mov	(_main_sloc0_1_0 + 3),a
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_sinhf
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	push	_main_sloc0_1_0
	push	(_main_sloc0_1_0 + 1)
	push	(_main_sloc0_1_0 + 2)
	push	(_main_sloc0_1_0 + 3)
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_41
	push	acc
	mov	a,#(__str_41 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:245: for(i=0; i<16; i++)
	inc	_main_i_1_1
	clr	a
	cjne	a,_main_i_1_1,L006177?
	inc	(_main_i_1_1 + 1)
L006177?:
	ljmp	L006065?
L006068?:
;	C:\Source\call51\Source\S51\test\mathtest.c:251: puts("\n*** Testing tanh(x) ***");
	mov	dptr,#__str_51
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:252: for(i=0; i<22; i++)
	mov	r2,#0x00
	mov	r3,#0x00
L006069?:
	clr	c
	mov	a,r2
	subb	a,#0x16
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	L006072?
;	C:\Source\call51\Source\S51\test\mathtest.c:254: x=i*0.5;
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#(0x00&0x00ff)
	clr	a
	mov	b,a
	mov	a,#0x3F
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:255: printf("%5.2f %12.8f\n", x, tanhf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_tanhf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_44
	push	acc
	mov	a,#(__str_44 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf5
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:252: for(i=0; i<22; i++)
	inc	r2
	cjne	r2,#0x00,L006179?
	inc	r3
L006179?:
	ljmp	L006069?
L006072?:
;	C:\Source\call51\Source\S51\test\mathtest.c:258: puts("\n*** Testing exp(x) ***");
	mov	dptr,#__str_30
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:259: for(i=0; i<20; i++)
	mov	r2,#0x00
	mov	r3,#0x00
L006073?:
	clr	c
	mov	a,r2
	subb	a,#0x14
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	L006076?
;	C:\Source\call51\Source\S51\test\mathtest.c:261: x=i*(-1.0/10.0);
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0xCCCD
	mov	b,#0xCC
	mov	a,#0xBD
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:262: printf("%5.2f %12.8f\n", x, expf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_expf
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_44
	push	acc
	mov	a,#(__str_44 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf5
	mov	sp,a
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\S51\test\mathtest.c:259: for(i=0; i<20; i++)
	inc	r2
	cjne	r2,#0x00,L006181?
	inc	r3
L006181?:
	ljmp	L006073?
L006076?:
;	C:\Source\call51\Source\S51\test\mathtest.c:265: puts("\n*** Testing floor(x), ceil(x), and modf(x) ***");
	mov	dptr,#__str_52
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:266: puts("x     int   frc   floor  ceil");
	mov	dptr,#__str_53
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:267: for(i=-10; i<11; i++)
	mov	_main_i_1_1,#0xF6
	mov	(_main_i_1_1 + 1),#0xFF
L006077?:
	clr	c
	mov	a,_main_i_1_1
	subb	a,#0x0B
	mov	a,(_main_i_1_1 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	L006182?
	ljmp	L006080?
L006182?:
;	C:\Source\call51\Source\S51\test\mathtest.c:269: x=i*0.33;
	mov	dpl,_main_i_1_1
	mov	dph,(_main_i_1_1 + 1)
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0xF5C3
	mov	b,#0xA8
	mov	a,#0x3E
	lcall	___fsmul
	mov	_main_x_1_1,dpl
	mov	(_main_x_1_1 + 1),dph
	mov	(_main_x_1_1 + 2),b
	mov	(_main_x_1_1 + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:270: z=modff(x, &y);
	mov	_modff_PARM_2,#_main_y_1_1
	mov	(_modff_PARM_2 + 1),#0x00
	mov	(_modff_PARM_2 + 2),#0x40
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_modff
	mov	_main_z_1_1,dpl
	mov	(_main_z_1_1 + 1),dph
	mov	(_main_z_1_1 + 2),b
	mov	(_main_z_1_1 + 3),a
;	C:\Source\call51\Source\S51\test\mathtest.c:272: x, y, z, floorf(x), ceilf(x));
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_ceilf
	mov	_main_sloc0_1_0,dpl
	mov	(_main_sloc0_1_0 + 1),dph
	mov	(_main_sloc0_1_0 + 2),b
	mov	(_main_sloc0_1_0 + 3),a
	mov	dpl,_main_x_1_1
	mov	dph,(_main_x_1_1 + 1)
	mov	b,(_main_x_1_1 + 2)
	mov	a,(_main_x_1_1 + 3)
	lcall	_floorf
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
;	C:\Source\call51\Source\S51\test\mathtest.c:271: printf("%5.2f %5.2f %5.2f %5.2f %5.2f\n",
	push	_main_sloc0_1_0
	push	(_main_sloc0_1_0 + 1)
	push	(_main_sloc0_1_0 + 2)
	push	(_main_sloc0_1_0 + 3)
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	_main_z_1_1
	push	(_main_z_1_1 + 1)
	push	(_main_z_1_1 + 2)
	push	(_main_z_1_1 + 3)
	push	_main_y_1_1
	push	(_main_y_1_1 + 1)
	push	(_main_y_1_1 + 2)
	push	(_main_y_1_1 + 3)
	push	_main_x_1_1
	push	(_main_x_1_1 + 1)
	push	(_main_x_1_1 + 2)
	push	(_main_x_1_1 + 3)
	mov	a,#__str_54
	push	acc
	mov	a,#(__str_54 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xe9
	mov	sp,a
;	C:\Source\call51\Source\S51\test\mathtest.c:267: for(i=-10; i<11; i++)
	inc	_main_i_1_1
	clr	a
	cjne	a,_main_i_1_1,L006183?
	inc	(_main_i_1_1 + 1)
L006183?:
	ljmp	L006077?
L006080?:
;	C:\Source\call51\Source\S51\test\mathtest.c:274: puts("\nTest completed.");
	mov	dptr,#__str_55
	mov	b,#0x80
	lcall	_puts
;	C:\Source\call51\Source\S51\test\mathtest.c:277: _endasm; //Go back to the monitor
	
	 ljmp 0x1b
	 
	ret
	rseg R_CSEG

	rseg R_CONST
__str_0:
	db 'Monitor not present'
	db 0x0A
	db 0x00
_main_fstr_1_1:
	db __str_1,(__str_1 >> 8)
	db __str_2,(__str_2 >> 8)
	db __str_3,(__str_3 >> 8)
	db __str_4,(__str_4 >> 8)
	db __str_5,(__str_5 >> 8)
	db __str_6,(__str_6 >> 8)
	db __str_7,(__str_7 >> 8)
	db __str_8,(__str_8 >> 8)
	db __str_9,(__str_9 >> 8)
	db __str_10,(__str_10 >> 8)
	db __str_11,(__str_11 >> 8)
	db __str_12,(__str_12 >> 8)
__str_1:
	db 0x00
__str_2:
	db '0.0'
	db 0x00
__str_3:
	db '1.0'
	db 0x00
__str_4:
	db '-1.0'
	db 0x00
__str_5:
	db '3.1416'
	db 0x00
__str_6:
	db '-31416e-4'
	db 0x00
__str_7:
	db '   -0.031416e2'
	db 0x00
__str_8:
	db 0x09
	db '0.031416E+2'
	db 0x00
__str_9:
	db '1e4'
	db 0x00
__str_10:
	db '000001.0000'
	db 0x00
__str_11:
	db '-0.27e-7'
	db 0x00
__str_12:
	db 'x'
	db 0x00
__str_13:
	db 'Built %s, %s'
	db 0x0A
	db 0x00
__str_14:
	db 'Nov 11 2012'
	db 0x00
__str_15:
	db '13:21:29'
	db 0x00
__str_16:
	db 0x0A
	db '*** Testing atof ***'
	db 0x00
__str_17:
	db '%s=%14.10f'
	db 0x0A
	db 0x00
__str_18:
	db 0x0A
	db '0x%08x='
	db 0x00
__str_19:
	db '%11.8f'
	db 0x0A
	db 0x00
__str_20:
	db 0x0A
	db '*** Testing frexp ***'
	db 0x00
__str_21:
	db '%11.8f=%11.8f*(2^%d)'
	db 0x0A
	db 0x00
__str_22:
	db 0x0A
	db '*** Testing ldexp ***'
	db 0x00
__str_23:
	db '%11.8f*(2^%d)=%11.8f'
	db 0x0A
	db 0x00
__str_24:
	db 0x0A
	db '*** Testing sqrt(x) ****'
	db 0x00
__str_25:
	db '      Average sqrtf(x) execution time: %f ms'
	db 0x0A
	db 0x00
__str_26:
	db '%5.2f %11.8f'
	db 0x0A
	db 0x00
__str_27:
	db 0x0A
	db '*** Testing log(x) and log10(x) ***'
	db 0x00
__str_28:
	db '%6.2f %11.8f %11.8f'
	db 0x0A
	db 0x00
__str_29:
	db '%6.4f %11.8f %11.8f'
	db 0x0A
	db 0x00
__str_30:
	db 0x0A
	db '*** Testing exp(x) ***'
	db 0x00
__str_31:
	db '%6.2f %11.8f'
	db 0x0A
	db 0x00
__str_32:
	db 0x0A
	db '*** Testing pow(x) ***'
	db 0x00
__str_33:
	db '(%5.2f)^2= %11.8f'
	db 0x0A
	db 0x00
__str_34:
	db 0x0A
	db '*** Testing sin(x) and cos(x) ***'
	db 0x00
__str_35:
	db '    Please wait...'
	db 0x00
__str_36:
	db '      Average `*` execution time: %f ms'
	db 0x0A
	db 0x00
__str_37:
	db '      Average sin(x) execution time: %f ms'
	db 0x0A
	db 0x00
__str_38:
	db '      Average cos(x) execution time: %f ms'
	db 0x0A
	db 0x0A
	db 0x00
__str_39:
	db '%5.2f %11.8f %11.8f'
	db 0x0A
	db 0x00
__str_40:
	db 0x0A
	db '*** Testing tan(x) and cot(x) ***'
	db 0x00
__str_41:
	db '%5.2f %12.8f %12.8f'
	db 0x0A
	db 0x00
__str_42:
	db 0x0A
	db '*** Testing asin(x) and acos(x) ***'
	db 0x00
__str_43:
	db 0x0A
	db '*** Testing atan(x) ***'
	db 0x00
__str_44:
	db '%5.2f %12.8f'
	db 0x0A
	db 0x00
__str_45:
	db 0x0A
	db '*** Testing atan2(x) ***'
	db 0x00
__str_46:
	db 'atan( 1.0,  1.0)=%12.8f'
	db 0x0A
	db 0x00
__str_47:
	db 'atan(-1.0,  1.0)=%12.8f'
	db 0x0A
	db 0x00
__str_48:
	db 'atan(-1.0, -1.0)=%12.8f'
	db 0x0A
	db 0x00
__str_49:
	db 'atan( 1.0, -1.0)=%12.8f'
	db 0x0A
	db 0x00
__str_50:
	db 0x0A
	db '*** Testing sinh(x) and cosh(x) ***'
	db 0x00
__str_51:
	db 0x0A
	db '*** Testing tanh(x) ***'
	db 0x00
__str_52:
	db 0x0A
	db '*** Testing floor(x), ceil(x), and modf(x) ***'
	db 0x00
__str_53:
	db 'x     int   frc   floor  ceil'
	db 0x00
__str_54:
	db '%5.2f %5.2f %5.2f %5.2f %5.2f'
	db 0x0A
	db 0x00
__str_55:
	db 0x0A
	db 'Test completed.'
	db 0x00

	rseg R_XINIT

	CSEG

end
