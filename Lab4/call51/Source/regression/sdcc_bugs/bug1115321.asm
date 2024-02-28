;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Nov 28 2012) (MSVC)
; This file was generated Sun Dec 09 00:50:40 2012
;--------------------------------------------------------
$name bug1115321
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
	public _test_s
	public _snprintf
	public _main
	public __c51_external_startup
	public ___fail_PARM_4
	public ___fail_PARM_3
	public ___fail_PARM_2
	public ___numFailures
	public ___numTests
	public ___prints
	public ___printn
	public ___printf
	public ___fail
	public _putchar
;--------------------------------------------------------
; Special Function Registers
;--------------------------------------------------------
_ACC            DATA 0xe0
_B              DATA 0xf0
_DPH            DATA 0x83
_DP0H           DATA 0x83
_DPL            DATA 0x82
_DP0L           DATA 0x82
_IE             DATA 0xa8
_IP             DATA 0xb8
_P0             DATA 0x80
_P1             DATA 0x90
_P2             DATA 0xa0
_P3             DATA 0xb0
_PCON           DATA 0x87
_PSW            DATA 0xd0
_SBUF           DATA 0x99
_SBUF0          DATA 0x99
_SCON           DATA 0x98
_SP             DATA 0x81
_TCON           DATA 0x88
_TH0            DATA 0x8c
_TH1            DATA 0x8d
_TL0            DATA 0x8a
_TL1            DATA 0x8b
_TMOD           DATA 0x89
_PSBANK         DATA 0x90
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
_BREG_F0        BIT 0xf0
_BREG_F1        BIT 0xf1
_BREG_F2        BIT 0xf2
_BREG_F3        BIT 0xf3
_BREG_F4        BIT 0xf4
_BREG_F5        BIT 0xf5
_BREG_F6        BIT 0xf6
_BREG_F7        BIT 0xf7
_EX0            BIT 0xa8
_ET0            BIT 0xa9
_EX1            BIT 0xaa
_ET1            BIT 0xab
_ES             BIT 0xac
_EA             BIT 0xaf
_PX0            BIT 0xb8
_PT0            BIT 0xb9
_PX1            BIT 0xba
_PT1            BIT 0xbb
_PS             BIT 0xbc
_P0_0           BIT 0x80
_P0_1           BIT 0x81
_P0_2           BIT 0x82
_P0_3           BIT 0x83
_P0_4           BIT 0x84
_P0_5           BIT 0x85
_P0_6           BIT 0x86
_P0_7           BIT 0x87
_P1_0           BIT 0x90
_P1_1           BIT 0x91
_P1_2           BIT 0x92
_P1_3           BIT 0x93
_P1_4           BIT 0x94
_P1_5           BIT 0x95
_P1_6           BIT 0x96
_P1_7           BIT 0x97
_P2_0           BIT 0xa0
_P2_1           BIT 0xa1
_P2_2           BIT 0xa2
_P2_3           BIT 0xa3
_P2_4           BIT 0xa4
_P2_5           BIT 0xa5
_P2_6           BIT 0xa6
_P2_7           BIT 0xa7
_P3_0           BIT 0xb0
_P3_1           BIT 0xb1
_P3_2           BIT 0xb2
_P3_3           BIT 0xb3
_P3_4           BIT 0xb4
_P3_5           BIT 0xb5
_P3_6           BIT 0xb6
_P3_7           BIT 0xb7
_RXD            BIT 0xb0
_RXD0           BIT 0xb0
_TXD            BIT 0xb1
_TXD0           BIT 0xb1
_INT0           BIT 0xb2
_INT1           BIT 0xb3
_T0             BIT 0xb4
_T1             BIT 0xb5
_WR             BIT 0xb6
_RD             BIT 0xb7
_P              BIT 0xd0
_F1             BIT 0xd1
_OV             BIT 0xd2
_RS0            BIT 0xd3
_RS1            BIT 0xd4
_F0             BIT 0xd5
_AC             BIT 0xd6
_CY             BIT 0xd7
_RI             BIT 0x98
_TI             BIT 0x99
_RB8            BIT 0x9a
_TB8            BIT 0x9b
_REN            BIT 0x9c
_SM2            BIT 0x9d
_SM1            BIT 0x9e
_SM0            BIT 0x9f
_IT0            BIT 0x88
_IE0            BIT 0x89
_IT1            BIT 0x8a
_IE1            BIT 0x8b
_TR0            BIT 0x8c
_TF0            BIT 0x8d
_TR1            BIT 0x8e
_TF1            BIT 0x8f
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	rbank0 segment data overlay
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	rseg R_DSEG
___numTests:
	ds 2
___numFailures:
	ds 2
___fail_PARM_2:
	ds 2
___fail_PARM_3:
	ds 2
___fail_PARM_4:
	ds 2
___fail_sloc0_1_0:
	ds 3
_test_s_buffer_1_1:
	ds 32
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg R_OSEG
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	rseg R_ISEG
___printn_buf_2_3:
	ds 6
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
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:16: int __numTests = 0;
	clr	a
	mov	___numTests,a
	mov	(___numTests + 1),a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:18: int __numFailures = 0;
	clr	a
	mov	___numFailures,a
	mov	(___numFailures + 1),a
	; The linker places a 'ret' at the end of segment R_DINIT.
;--------------------------------------------------------
; code
;--------------------------------------------------------
	rseg R_CSEG
;------------------------------------------------------------
;Allocation info for local variables in function '__prints'
;------------------------------------------------------------
;s                         Allocated to registers r2 r3 r4 
;c                         Allocated to registers r6 
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:106: __prints (const char *s)
;	-----------------------------------------
;	 function __prints
;	-----------------------------------------
___prints:
	using	0
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:110: while ('\0' != (c = *s))
L002001?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	mov	r6,a
	cjne	r5,#0x00,L002009?
	ret
L002009?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:112: putchar(c);
	mov	dpl,r6
	push	ar2
	push	ar3
	push	ar4
	lcall	_putchar
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:113: ++s;
	inc	r2
	cjne	r2,#0x00,L002001?
	inc	r3
	sjmp	L002001?
;------------------------------------------------------------
;Allocation info for local variables in function '__printn'
;------------------------------------------------------------
;n                         Allocated to registers r2 r3 
;p                         Allocated to registers r4 
;neg                       Allocated to registers r5 
;buf                       Allocated with name '___printn_buf_2_3'
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:118: __printn (int n)
;	-----------------------------------------
;	 function __printn
;	-----------------------------------------
___printn:
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:120: if (0 == n)
	cjne	r2,#0x00,L003009?
	cjne	r3,#0x00,L003009?
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:122: putchar('0');
	mov	dpl,#0x30
	ljmp	_putchar
L003009?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:127: char MEMSPACE_BUF *p = &buf[sizeof (buf) - 1];
	mov	r4,#(___printn_buf_2_3 + 0x0005)
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:128: char neg = 0;
	mov	r5,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:130: buf[sizeof(buf) - 1] = '\0';
	mov	r0,#(___printn_buf_2_3 + 0x0005)
	mov	@r0,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:132: if (0 > n)
	mov	a,r3
	jnb	acc.7,L003016?
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:134: n = -n;
	clr	c
	clr	a
	subb	a,r2
	mov	r2,a
	clr	a
	subb	a,r3
	mov	r3,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:135: neg = 1;
	mov	r5,#0x01
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:138: while (0 != n)
L003016?:
	mov	ar0,r4
L003003?:
	cjne	r2,#0x00,L003022?
	cjne	r3,#0x00,L003022?
	sjmp	L003018?
L003022?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:140: *--p = '0' + __mod (n, 10);
	dec	r0
	mov	__modsint_PARM_2,#0x0A
	clr	a
	mov	(__modsint_PARM_2 + 1),a
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	push	ar5
	push	ar0
	lcall	__modsint
	mov	r6,dpl
	pop	ar0
	pop	ar5
	pop	ar3
	pop	ar2
	mov	a,#0x30
	add	a,r6
	mov	@r0,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:141: n = __div (n, 10);
	mov	__divsint_PARM_2,#0x0A
	clr	a
	mov	(__divsint_PARM_2 + 1),a
	mov	dpl,r2
	mov	dph,r3
	push	ar5
	push	ar0
	lcall	__divsint
	mov	r2,dpl
	mov	r3,dph
	pop	ar0
	pop	ar5
	sjmp	L003003?
L003018?:
	mov	ar4,r0
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:144: if (neg)
	mov	a,r5
	jz	L003007?
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:145: putchar('-');
	mov	dpl,#0x2D
	push	ar4
	lcall	_putchar
	pop	ar4
L003007?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:147: __prints(p);
	mov	r2,#0x00
	mov	r3,#0x40
	mov	dpl,r4
	mov	dph,r2
	mov	b,r3
	ljmp	___prints
;------------------------------------------------------------
;Allocation info for local variables in function '_c51_external_startup'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:155: _c51_external_startup (void)
;	-----------------------------------------
;	 function _c51_external_startup
;	-----------------------------------------
__c51_external_startup:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:159: TI = 1;
	setb	_TI
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:160: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__printf'
;------------------------------------------------------------
;szFormat                  Allocated to stack - offset -5
;ap                        Allocated to registers r2 
;sz                        Allocated to registers r3 r4 r5 
;i                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:166: __printf (const char *szFormat, ...)
;	-----------------------------------------
;	 function __printf
;	-----------------------------------------
___printf:
	push	_bp
	mov	_bp,sp
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:169: va_start (ap, szFormat);
	mov	a,_bp
	add	a,#0xfb
	mov	r2,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:171: while (*szFormat)
L005009?:
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	jnz	L005020?
	ljmp	L005012?
L005020?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:173: if (*szFormat == '%')
	cjne	r6,#0x25,L005021?
	sjmp	L005022?
L005021?:
	ljmp	L005007?
L005022?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:175: switch (*++szFormat)
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,#0x01
	add	a,r3
	mov	@r0,a
	clr	a
	addc	a,r4
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar5
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	cjne	r3,#0x25,L005023?
	sjmp	L005003?
L005023?:
	cjne	r3,#0x73,L005024?
	sjmp	L005001?
L005024?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:177: case 's':
	cjne	r3,#0x75,L005008?
	sjmp	L005002?
L005001?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:179: char *sz = va_arg (ap, char *);
	mov	a,r2
	add	a,#0xfd
	mov	r0,a
	mov	r2,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	dec	r0
	dec	r0
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:180: __prints(sz);
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	push	ar2
	lcall	___prints
	pop	ar2
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:181: break;
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:184: case 'u':
	sjmp	L005008?
L005002?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:186: int i = va_arg (ap, int);
	mov	a,r2
	add	a,#0xfe
	mov	r0,a
	mov	r2,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	dec	r0
	mov	dpl,r3
	mov	dph,r4
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:187: __printn (i);
	push	ar2
	lcall	___printn
	pop	ar2
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:188: break;
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:191: case '%':
	sjmp	L005008?
L005003?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:192: putchar ('%');
	mov	dpl,#0x25
	push	ar2
	lcall	_putchar
	pop	ar2
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:193: break;
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:197: }
	sjmp	L005008?
L005007?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:201: putchar (*szFormat);
	mov	dpl,r6
	push	ar2
	lcall	_putchar
	pop	ar2
L005008?:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:203: szFormat++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L005026?
	inc	r0
	inc	@r0
L005026?:
	ljmp	L005009?
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:205: va_end (ap);
L005012?:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__fail'
;------------------------------------------------------------
;szCond                    Allocated with name '___fail_PARM_2'
;szFile                    Allocated with name '___fail_PARM_3'
;line                      Allocated with name '___fail_PARM_4'
;szMsg                     Allocated to registers r2 r3 
;sloc0                     Allocated with name '___fail_sloc0_1_0'
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:209: __fail (code const char *szMsg, code const char *szCond, code const char *szFile, int line)
;	-----------------------------------------
;	 function __fail
;	-----------------------------------------
___fail:
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:211: __printf("--- FAIL: \"%s\" on %s at %s:%u\n", szMsg, szCond, szFile, line);
	mov	r4,___fail_PARM_3
	mov	r5,(___fail_PARM_3 + 1)
	mov	r6,#0x80
	mov	___fail_sloc0_1_0,___fail_PARM_2
	mov	(___fail_sloc0_1_0 + 1),(___fail_PARM_2 + 1)
	mov	(___fail_sloc0_1_0 + 2),#0x80
	mov	r7,#0x80
	push	___fail_PARM_4
	push	(___fail_PARM_4 + 1)
	push	ar4
	push	ar5
	push	ar6
	push	___fail_sloc0_1_0
	push	(___fail_sloc0_1_0 + 1)
	push	(___fail_sloc0_1_0 + 2)
	push	ar2
	push	ar3
	push	ar7
	mov	a,#__str_0
	push	acc
	mov	a,#(__str_0 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	___printf
	mov	a,sp
	add	a,#0xf2
	mov	sp,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:212: __numFailures++;
	inc	___numFailures
	clr	a
	cjne	a,___numFailures,L006003?
	inc	(___numFailures + 1)
L006003?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:216: main (void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:218: __printf("--- Running: %s\n", __getSuiteName());
	lcall	___getSuiteName
	mov	r2,dpl
	mov	r3,dph
	mov	r4,#0x80
	push	ar2
	push	ar3
	push	ar4
	mov	a,#__str_1
	push	acc
	mov	a,#(__str_1 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	___printf
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:220: __runSuite();
	lcall	___runSuite
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:224: __numFailures, __numTests, __numCases
	mov	dptr,#___numCases
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	mov	a,#0x01
	movc	a,@a+dptr
	mov	r3,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:222: __printf("--- Summary: %u/%u/%u: %u failed of %u tests in %u cases.\n",
	push	ar2
	push	ar3
	push	___numTests
	push	(___numTests + 1)
	push	___numFailures
	push	(___numFailures + 1)
	push	ar2
	push	ar3
	push	___numTests
	push	(___numTests + 1)
	push	___numFailures
	push	(___numFailures + 1)
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	___printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:227: IE=0;
	mov	_IE,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\/../fwk/include/testfwk.h:228: return 0;
	mov	dptr,#0x0000
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'snprintf'
;------------------------------------------------------------
;buffer                    Allocated to stack - offset -5
;size                      Allocated to stack - offset -6
;format                    Allocated to stack - offset -9
;args                      Allocated to stack - offset 1
;start                     Allocated to stack - offset 2
;end                       Allocated to registers r5 r6 r7 
;padding                   Allocated to stack - offset 5
;digits                    Allocated to stack - offset 6
;val                       Allocated to stack - offset 8
;val_end                   Allocated to registers r2 r3 r4 
;length                    Allocated to stack - offset 11
;sloc0                     Allocated to stack - offset 13
;sloc1                     Allocated to stack - offset 14
;sloc2                     Allocated to stack - offset 15
;sloc3                     Allocated to stack - offset 17
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:105: unsigned char C51_SNPRINTF( char *buffer, const unsigned char size,
;	-----------------------------------------
;	 function snprintf
;	-----------------------------------------
_snprintf:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x13
	mov	sp,a
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:109: char *start = buffer;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	r1,_bp
	inc	r1
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:110: char *end   = &buffer[size];
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0xfa
	mov	r1,a
	mov	a,@r1
	add	a,@r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:112: va_start( args, format );
	mov	a,_bp
	add	a,#0xf7
	mov	r2,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar2
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:114: while( (buffer <  end) && ('\0' != *format) ) {
L008034?:
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r5
	inc	r0
	mov	a,@r0
	subb	a,r6
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jc	L008071?
	ljmp	L008037?
L008071?:
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar2,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r2
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	cjne	@r0,#0x00,L008072?
	ljmp	L008037?
L008072?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:115: if( '%' == *format ) {
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	cjne	@r0,#0x25,L008073?
	sjmp	L008074?
L008073?:
	ljmp	L008031?
L008074?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:116: format++;
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	a,#0x01
	add	a,r3
	mov	@r0,a
	clr	a
	addc	a,r4
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar2
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:117: switch( *format ) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	cjne	r2,#0x25,L008075?
	sjmp	L008002?
L008075?:
	cjne	r2,#0x63,L008076?
	sjmp	L008077?
L008076?:
	ljmp	L008003?
L008077?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:120: *buffer = VA_ARG( args, VA_ARG_CHAR );
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	dec	a
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar6,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	mov	a,r6
	lcall	__gptrput
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:121: buffer++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,#0x01
	add	a,r3
	mov	@r0,a
	clr	a
	addc	a,r4
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:122: break;
	pop	ar7
	pop	ar6
	pop	ar5
	ljmp	L008032?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:125: case '%':
L008002?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:126: *buffer = '%';
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	mov	a,#0x25
	lcall	__gptrput
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:127: buffer++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,#0x01
	add	a,r3
	mov	@r0,a
	clr	a
	addc	a,r4
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:128: break;
	pop	ar7
	pop	ar6
	pop	ar5
	ljmp	L008032?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:130: default:
L008003?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:132: char padding = ' ';
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0x20
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:133: short digits = 0;
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:136: switch( *format ) {
	cjne	r2,#0x20,L008078?
	sjmp	L008005?
L008078?:
	cjne	r2,#0x30,L008053?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:138: padding = '0';
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0x30
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:139: case ' ':
L008005?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:140: format++;
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L008081?
	inc	r0
	inc	@r0
L008081?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:145: while(    ('\0' != *format)
L008053?:
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
L008009?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	cjne	@r0,#0x00,L008082?
	ljmp	L008067?
L008082?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:146: && ((*format >= '0') && (*format <= '9')) )
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	clr	c
	mov	a,@r0
	xrl	a,#0x80
	subb	a,#0xb0
	jnc	L008083?
	ljmp	L008067?
L008083?:
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	clr	c
	mov	a,#(0x39 ^ 0x80)
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	L008084?
	ljmp	L008067?
L008084?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:148: digits = digits * 10 + (*format - '0');
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	__mulint_PARM_2,@r0
	inc	r0
	mov	(__mulint_PARM_2 + 1),@r0
	mov	dptr,#0x000A
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	lcall	__mulint
	xch	a,r0
	mov	a,_bp
	add	a,#0x0f
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	ar7,@r0
	mov	a,@r0
	rlc	a
	subb	a,acc
	mov	r5,a
	mov	a,r7
	add	a,#0xd0
	mov	r7,a
	mov	a,r5
	addc	a,#0xff
	mov	r5,a
	mov	a,_bp
	add	a,#0x0f
	mov	r0,a
	mov	a,r7
	add	a,@r0
	mov	r7,a
	mov	a,r5
	inc	r0
	addc	a,@r0
	mov	r5,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	@r0,ar7
	inc	r0
	mov	@r0,ar5
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:149: format++;
	inc	r2
	cjne	r2,#0x00,L008085?
	inc	r3
L008085?:
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	pop	ar7
	pop	ar6
	pop	ar5
	ljmp	L008009?
L008067?:
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:152: switch( *format ) {
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	cjne	r2,#0x73,L008086?
	sjmp	L008087?
L008086?:
	ljmp	L008037?
L008087?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:158: val = VA_ARG( args, char * );
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfd
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	dec	r0
	dec	r0
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:162: while( '\0' != *val_end ) { val_end++; }
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
L008013?:
	push	ar5
	push	ar6
	push	ar7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	cjne	r5,#0x00,L008088?
	pop	ar7
	pop	ar6
	pop	ar5
	sjmp	L008015?
L008088?:
	pop	ar7
	pop	ar6
	pop	ar5
	inc	r2
	cjne	r2,#0x00,L008013?
	inc	r3
	sjmp	L008013?
L008015?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:164: length = val_end - val;
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,r2
	clr	c
	subb	a,@r0
	mov	r2,a
	mov	a,r3
	inc	r0
	subb	a,@r0
	mov	r3,a
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:167: if( (digits > 0) && (length > digits) ) {
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	clr	c
	clr	a
	subb	a,@r0
	clr	a
	xrl	a,#0x80
	inc	r0
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	L008061?
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,_bp
	add	a,#0x06
	mov	r1,a
	clr	c
	mov	a,@r1
	subb	a,@r0
	inc	r1
	mov	a,@r1
	xrl	a,#0x80
	inc	r0
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	L008061?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:168: length = digits;
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,_bp
	add	a,#0x0b
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:172: while( (digits > length) && (buffer < end) ) {
L008061?:
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,_bp
	add	a,#0x0f
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
L008020?:
	mov	a,_bp
	add	a,#0x0f
	mov	r0,a
	mov	a,_bp
	add	a,#0x0b
	mov	r1,a
	clr	c
	mov	a,@r1
	subb	a,@r0
	inc	r1
	mov	a,@r1
	xrl	a,#0x80
	inc	r0
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	L008064?
	clr	c
	mov	a,r4
	subb	a,r5
	mov	a,r2
	subb	a,r6
	mov	a,r3
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	L008064?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:173: *buffer = padding;
	mov	dpl,r4
	mov	dph,r2
	mov	b,r3
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	mov	r4,dpl
	mov	r2,dph
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:174: buffer++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:175: digits--;
	mov	a,_bp
	add	a,#0x0f
	mov	r0,a
	dec	@r0
	cjne	@r0,#0xff,L008020?
	inc	r0
	dec	@r0
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:179: while( (length > 0) && (buffer < end) ) {
	sjmp	L008020?
L008064?:
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,_bp
	add	a,#0x11
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,_bp
	add	a,#0x0f
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
L008024?:
	mov	a,_bp
	add	a,#0x0f
	mov	r0,a
	clr	c
	clr	a
	subb	a,@r0
	clr	a
	xrl	a,#0x80
	inc	r0
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jc	L008094?
	ljmp	L008070?
L008094?:
	clr	c
	mov	a,r4
	subb	a,r5
	mov	a,r2
	subb	a,r6
	mov	a,r3
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jc	L008095?
	ljmp	L008070?
L008095?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:180: *buffer = *val;
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	dec	r0
	dec	r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	mov	dpl,r4
	mov	dph,r2
	mov	b,r3
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	r4,dpl
	mov	r2,dph
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:181: buffer++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:182: val++;
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:183: length--;
	mov	a,_bp
	add	a,#0x0f
	mov	r0,a
	dec	@r0
	cjne	@r0,#0xff,L008096?
	inc	r0
	dec	@r0
L008096?:
	pop	ar7
	pop	ar6
	pop	ar5
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:194: }
	sjmp	L008024?
L008031?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:196: *buffer = *format;
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:197: buffer++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,#0x01
	add	a,r5
	mov	@r0,a
	clr	a
	addc	a,r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:213: return (buffer - start);
	pop	ar7
	pop	ar6
	pop	ar5
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:197: buffer++;
	sjmp	L008032?
L008070?:
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
L008032?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:200: format++;
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L008097?
	inc	r0
	inc	@r0
L008097?:
	ljmp	L008034?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:203: clean_and_bail:
L008037?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:204: if( buffer < end ) {
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r5
	inc	r0
	mov	a,@r0
	subb	a,r6
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	L008039?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:205: *buffer = '\0';
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:206: buffer++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,#0x01
	add	a,r2
	mov	@r0,a
	clr	a
	addc	a,r3
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar4
	sjmp	L008040?
L008039?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:208: *(buffer-1) = '\0';
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	add	a,#0xff
	mov	r2,a
	inc	r0
	mov	a,@r0
	addc	a,#0xff
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
L008040?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:213: return (buffer - start);
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	r1,_bp
	inc	r1
	inc	r1
	mov	a,@r0
	clr	c
	subb	a,@r1
	mov	r2,a
	inc	r0
	mov	a,@r0
	inc	r1
	subb	a,@r1
	mov	dpl,r2
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'test_s'
;------------------------------------------------------------
;buffer                    Allocated with name '_test_s_buffer_1_1'
;ret                       Allocated to registers r2 r3 
;i                         Allocated to registers r2 r3 
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:216: void test_s( void )
;	-----------------------------------------
;	 function test_s
;	-----------------------------------------
_test_s:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:222: for( i = 0; i < 31; i++ ) {
	mov	r2,#0x00
	mov	r3,#0x00
L009001?:
	clr	c
	mov	a,r2
	subb	a,#0x1F
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	L009004?
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:223: buffer[i] = 'P';
	mov	a,r2
	add	a,#_test_s_buffer_1_1
	mov	r0,a
	mov	@r0,#0x50
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:222: for( i = 0; i < 31; i++ ) {
	inc	r2
	cjne	r2,#0x00,L009001?
	inc	r3
	sjmp	L009001?
L009004?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:225: buffer[31] = '\0';
	mov	(_test_s_buffer_1_1 + 0x001f),#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:227: ret = C51_SNPRINTF( buffer, 32, "->|%%|<-" );
	mov	a,#__str_3
	push	acc
	mov	a,#(__str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#_test_s_buffer_1_1
	push	acc
	mov	a,#(_test_s_buffer_1_1 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_snprintf
	mov	r2,dpl
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
	mov	r3,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:229: ASSERT (strcmp(buffer, "->|%|<-") == 0);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009047?
	inc	(___numTests + 1)
L009047?:
	mov	_strcmp_PARM_2,#__str_4
	mov	(_strcmp_PARM_2 + 1),#(__str_4 >> 8)
	mov	(_strcmp_PARM_2 + 2),#0x80
	mov	dptr,#_test_s_buffer_1_1
	mov	b,#0x40
	push	ar2
	push	ar3
	lcall	_strcmp
	mov	r4,dpl
	mov	r5,dph
	pop	ar3
	pop	ar2
	mov	a,r4
	orl	a,r5
	cjne	a,#0x01,L009048?
L009048?:
	clr	a
	rlc	a
	mov	r4,a
	jnz	L009008?
	mov	___fail_PARM_2,#__str_6
	mov	(___fail_PARM_2 + 1),#(__str_6 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xE5
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	push	ar2
	push	ar3
	lcall	___fail
	pop	ar3
	pop	ar2
L009008?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:230: ASSERT (ret == 8);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009050?
	inc	(___numTests + 1)
L009050?:
	cjne	r2,#0x08,L009051?
	cjne	r3,#0x00,L009051?
	sjmp	L009010?
L009051?:
	mov	___fail_PARM_2,#__str_8
	mov	(___fail_PARM_2 + 1),#(__str_8 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xE6
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	lcall	___fail
L009010?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:231: ret = C51_SNPRINTF( buffer, 32, "%s, %s.", "Hello", "world" );
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_9
	push	acc
	mov	a,#(__str_9 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#_test_s_buffer_1_1
	push	acc
	mov	a,#(_test_s_buffer_1_1 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_snprintf
	mov	r4,dpl
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	mov	ar2,r4
	mov	r3,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:233: ASSERT (strcmp(buffer, "Hello, world.") == 0);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009052?
	inc	(___numTests + 1)
L009052?:
	mov	_strcmp_PARM_2,#__str_12
	mov	(_strcmp_PARM_2 + 1),#(__str_12 >> 8)
	mov	(_strcmp_PARM_2 + 2),#0x80
	mov	dptr,#_test_s_buffer_1_1
	mov	b,#0x40
	push	ar2
	push	ar3
	lcall	_strcmp
	mov	r4,dpl
	mov	r5,dph
	pop	ar3
	pop	ar2
	mov	a,r4
	orl	a,r5
	cjne	a,#0x01,L009053?
L009053?:
	clr	a
	rlc	a
	mov	r4,a
	jnz	L009012?
	mov	___fail_PARM_2,#__str_13
	mov	(___fail_PARM_2 + 1),#(__str_13 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xE9
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	push	ar2
	push	ar3
	lcall	___fail
	pop	ar3
	pop	ar2
L009012?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:234: ASSERT (ret == 14);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009055?
	inc	(___numTests + 1)
L009055?:
	cjne	r2,#0x0E,L009056?
	cjne	r3,#0x00,L009056?
	sjmp	L009014?
L009056?:
	mov	___fail_PARM_2,#__str_14
	mov	(___fail_PARM_2 + 1),#(__str_14 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xEA
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	lcall	___fail
L009014?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:235: ret = C51_SNPRINTF( buffer, 32, "% 10s, % 10s.", "Hello", "world" );
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_15
	push	acc
	mov	a,#(__str_15 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#_test_s_buffer_1_1
	push	acc
	mov	a,#(_test_s_buffer_1_1 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_snprintf
	mov	r4,dpl
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	mov	ar2,r4
	mov	r3,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:237: ASSERT (strcmp(buffer, "     Hello,      world.") == 0);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009057?
	inc	(___numTests + 1)
L009057?:
	mov	_strcmp_PARM_2,#__str_16
	mov	(_strcmp_PARM_2 + 1),#(__str_16 >> 8)
	mov	(_strcmp_PARM_2 + 2),#0x80
	mov	dptr,#_test_s_buffer_1_1
	mov	b,#0x40
	push	ar2
	push	ar3
	lcall	_strcmp
	mov	r4,dpl
	mov	r5,dph
	pop	ar3
	pop	ar2
	mov	a,r4
	orl	a,r5
	cjne	a,#0x01,L009058?
L009058?:
	clr	a
	rlc	a
	mov	r4,a
	jnz	L009016?
	mov	___fail_PARM_2,#__str_17
	mov	(___fail_PARM_2 + 1),#(__str_17 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xED
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	push	ar2
	push	ar3
	lcall	___fail
	pop	ar3
	pop	ar2
L009016?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:238: ASSERT (ret == 24);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009060?
	inc	(___numTests + 1)
L009060?:
	cjne	r2,#0x18,L009061?
	cjne	r3,#0x00,L009061?
	sjmp	L009018?
L009061?:
	mov	___fail_PARM_2,#__str_18
	mov	(___fail_PARM_2 + 1),#(__str_18 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xEE
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	lcall	___fail
L009018?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:239: ret = C51_SNPRINTF( buffer, 32, "% 3s, % 3s.", "Hello", "world" );
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_19
	push	acc
	mov	a,#(__str_19 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#_test_s_buffer_1_1
	push	acc
	mov	a,#(_test_s_buffer_1_1 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_snprintf
	mov	r4,dpl
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	mov	ar2,r4
	mov	r3,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:241: ASSERT (strcmp(buffer, "Hel, wor.") == 0);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009062?
	inc	(___numTests + 1)
L009062?:
	mov	_strcmp_PARM_2,#__str_20
	mov	(_strcmp_PARM_2 + 1),#(__str_20 >> 8)
	mov	(_strcmp_PARM_2 + 2),#0x80
	mov	dptr,#_test_s_buffer_1_1
	mov	b,#0x40
	push	ar2
	push	ar3
	lcall	_strcmp
	mov	r4,dpl
	mov	r5,dph
	pop	ar3
	pop	ar2
	mov	a,r4
	orl	a,r5
	cjne	a,#0x01,L009063?
L009063?:
	clr	a
	rlc	a
	mov	r4,a
	jnz	L009020?
	mov	___fail_PARM_2,#__str_21
	mov	(___fail_PARM_2 + 1),#(__str_21 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xF1
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	push	ar2
	push	ar3
	lcall	___fail
	pop	ar3
	pop	ar2
L009020?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:242: ASSERT (ret == 10);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009065?
	inc	(___numTests + 1)
L009065?:
	cjne	r2,#0x0A,L009066?
	cjne	r3,#0x00,L009066?
	sjmp	L009022?
L009066?:
	mov	___fail_PARM_2,#__str_22
	mov	(___fail_PARM_2 + 1),#(__str_22 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xF2
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	lcall	___fail
L009022?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:243: ret = C51_SNPRINTF( buffer, 32, "%03s, %03s.", "Hello", "world" );
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_23
	push	acc
	mov	a,#(__str_23 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#_test_s_buffer_1_1
	push	acc
	mov	a,#(_test_s_buffer_1_1 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_snprintf
	mov	r4,dpl
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	mov	ar2,r4
	mov	r3,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:245: ASSERT (strcmp(buffer, "Hel, wor.") == 0);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009067?
	inc	(___numTests + 1)
L009067?:
	mov	_strcmp_PARM_2,#__str_20
	mov	(_strcmp_PARM_2 + 1),#(__str_20 >> 8)
	mov	(_strcmp_PARM_2 + 2),#0x80
	mov	dptr,#_test_s_buffer_1_1
	mov	b,#0x40
	push	ar2
	push	ar3
	lcall	_strcmp
	mov	r4,dpl
	mov	r5,dph
	pop	ar3
	pop	ar2
	mov	a,r4
	orl	a,r5
	cjne	a,#0x01,L009068?
L009068?:
	clr	a
	rlc	a
	mov	r4,a
	jnz	L009024?
	mov	___fail_PARM_2,#__str_21
	mov	(___fail_PARM_2 + 1),#(__str_21 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xF5
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	push	ar2
	push	ar3
	lcall	___fail
	pop	ar3
	pop	ar2
L009024?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:246: ASSERT (ret == 10);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009070?
	inc	(___numTests + 1)
L009070?:
	cjne	r2,#0x0A,L009071?
	cjne	r3,#0x00,L009071?
	sjmp	L009026?
L009071?:
	mov	___fail_PARM_2,#__str_22
	mov	(___fail_PARM_2 + 1),#(__str_22 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xF6
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	lcall	___fail
L009026?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:247: ret = C51_SNPRINTF( buffer, 10, "%s", "Hello, world" );
	mov	a,#__str_25
	push	acc
	mov	a,#(__str_25 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#__str_24
	push	acc
	mov	a,#(__str_24 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x0A
	push	acc
	mov	a,#_test_s_buffer_1_1
	push	acc
	mov	a,#(_test_s_buffer_1_1 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_snprintf
	mov	r4,dpl
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	ar2,r4
	mov	r3,#0x00
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:249: ASSERT (strcmp(buffer, "Hello, wo") == 0);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009072?
	inc	(___numTests + 1)
L009072?:
	mov	_strcmp_PARM_2,#__str_26
	mov	(_strcmp_PARM_2 + 1),#(__str_26 >> 8)
	mov	(_strcmp_PARM_2 + 2),#0x80
	mov	dptr,#_test_s_buffer_1_1
	mov	b,#0x40
	push	ar2
	push	ar3
	lcall	_strcmp
	mov	r4,dpl
	mov	r5,dph
	pop	ar3
	pop	ar2
	mov	a,r4
	orl	a,r5
	cjne	a,#0x01,L009073?
L009073?:
	clr	a
	rlc	a
	mov	r4,a
	jnz	L009028?
	mov	___fail_PARM_2,#__str_27
	mov	(___fail_PARM_2 + 1),#(__str_27 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xF9
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	push	ar2
	push	ar3
	lcall	___fail
	pop	ar3
	pop	ar2
L009028?:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:250: ASSERT (ret == 10);
	inc	___numTests
	clr	a
	cjne	a,___numTests,L009075?
	inc	(___numTests + 1)
L009075?:
	cjne	r2,#0x0A,L009076?
	cjne	r3,#0x00,L009076?
	ret
L009076?:
	mov	___fail_PARM_2,#__str_22
	mov	(___fail_PARM_2 + 1),#(__str_22 >> 8)
	mov	___fail_PARM_3,#__str_7
	mov	(___fail_PARM_3 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_4,#0xFA
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_5
	ljmp	___fail
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:256: void putchar(char c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
;	C:\Source\call51\Source\regression\sdcc_bugs\bug1115321.c:258: _putchar(c);
	ljmp	__putchar
	rseg R_CSEG

	rseg R_CONST
__str_0:
	db '--- FAIL: '
	db 0x22
	db '%s'
	db 0x22
	db ' on %s at %s:%u'
	db 0x0A
	db 0x00
__str_1:
	db '--- Running: %s'
	db 0x0A
	db 0x00
__str_2:
	db '--- Summary: %u/%u/%u: %u failed of %u tests in %u cases.'
	db 0x0A
	db 0x00
__str_3:
	db '->|%%|<-'
	db 0x00
__str_4:
	db '->|%|<-'
	db 0x00
__str_5:
	db 'Assertion failed'
	db 0x00
__str_6:
	db 'strcmp(buffer, '
	db 0x22
	db '->|%|<-'
	db 0x22
	db ') == 0'
	db 0x00
__str_7:
	db 'C:'
	db 0x5C
	db 'Source'
	db 0x5C
	db 'call51'
	db 0x5C
	db 'Source'
	db 0x5C
	db 'regression'
	db 0x5C
	db 'sdcc_bugs'
	db 0x5C
	db 'bug1115321.c'
	db 0x00
__str_8:
	db 'ret == 8'
	db 0x00
__str_9:
	db '%s, %s.'
	db 0x00
__str_10:
	db 'Hello'
	db 0x00
__str_11:
	db 'world'
	db 0x00
__str_12:
	db 'Hello, world.'
	db 0x00
__str_13:
	db 'strcmp(buffer, '
	db 0x22
	db 'Hello, world.'
	db 0x22
	db ') == 0'
	db 0x00
__str_14:
	db 'ret == 14'
	db 0x00
__str_15:
	db '% 10s, % 10s.'
	db 0x00
__str_16:
	db '     Hello,      world.'
	db 0x00
__str_17:
	db 'strcmp(buffer, '
	db 0x22
	db '     Hello,      world.'
	db 0x22
	db ') == 0'
	db 0x00
__str_18:
	db 'ret == 24'
	db 0x00
__str_19:
	db '% 3s, % 3s.'
	db 0x00
__str_20:
	db 'Hel, wor.'
	db 0x00
__str_21:
	db 'strcmp(buffer, '
	db 0x22
	db 'Hel, wor.'
	db 0x22
	db ') == 0'
	db 0x00
__str_22:
	db 'ret == 10'
	db 0x00
__str_23:
	db '%03s, %03s.'
	db 0x00
__str_24:
	db '%s'
	db 0x00
__str_25:
	db 'Hello, world'
	db 0x00
__str_26:
	db 'Hello, wo'
	db 0x00
__str_27:
	db 'strcmp(buffer, '
	db 0x22
	db 'Hello, wo'
	db 0x22
	db ') == 0'
	db 0x00

	rseg R_XINIT

	CSEG

end
