;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Dec 11 2012) (MSVC)
; This file was generated Fri Jan 18 22:55:10 2013
;--------------------------------------------------------
$name gcc_torture_execute_20000731_1
$optc51 --model-large
	R_DSEG    segment data
	R_CSEG    segment code
	R_BSEG    segment bit
	R_XSEG    segment xdata
	R_PSEG    segment xdata
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
	public ___numCases
	public _testTortureExecute
	public _do_sibcall
	public _foo
	public _main
	public __c51_external_startup
	public ___numFailures
	public ___numTests
	public ___fail_PARM_4
	public ___fail_PARM_3
	public ___fail_PARM_2
	public ___prints
	public ___printn
	public ___printf
	public ___fail
	public ___runSuite
	public ___getSuiteName
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
___fail_sloc0_1_0:
	ds 3
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg R_OSEG
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	rseg R_ISEG
___printn_buf_2_54:
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
	rseg R_PSEG
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	rseg R_XSEG
___prints_s_1_48:
	ds 3
___printn_n_1_51:
	ds 2
___printn_neg_2_54:
	ds 1
___fail_PARM_2:
	ds 2
___fail_PARM_3:
	ds 2
___fail_PARM_4:
	ds 2
___fail_szMsg_1_68:
	ds 2
_testTortureExecute_x_1_77:
	ds 4
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	XSEG
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	rseg R_IXSEG
___numTests:
	ds 2
___numFailures:
	ds 2
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
;Allocation info for local variables in function '__prints'
;------------------------------------------------------------
;s                         Allocated with name '___prints_s_1_48'
;c                         Allocated with name '___prints_c_1_49'
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:110: __prints (const char *s)
;	-----------------------------------------
;	 function __prints
;	-----------------------------------------
___prints:
	using	0
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#___prints_s_1_48
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:114: while ('\0' != (c = *s))
	mov	dptr,#___prints_s_1_48
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
L002001?:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	jz	L002008?
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:116: putchar(c);
	mov	dpl,r5
	push	ar2
	push	ar3
	push	ar4
	lcall	_putchar
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:117: ++s;
	inc	r2
	cjne	r2,#0x00,L002010?
	inc	r3
L002010?:
	mov	dptr,#___prints_s_1_48
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	sjmp	L002001?
L002008?:
	mov	dptr,#___prints_s_1_48
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__printn'
;------------------------------------------------------------
;n                         Allocated with name '___printn_n_1_51'
;p                         Allocated with name '___printn_p_2_54'
;neg                       Allocated with name '___printn_neg_2_54'
;buf                       Allocated with name '___printn_buf_2_54'
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:122: __printn (int n)
;	-----------------------------------------
;	 function __printn
;	-----------------------------------------
___printn:
	mov	r2,dph
	mov	a,dpl
	mov	dptr,#___printn_n_1_51
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:124: if (0 == n)
	mov	dptr,#___printn_n_1_51
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	cjne	r2,#0x00,L003009?
	cjne	r3,#0x00,L003009?
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:126: putchar('0');
	mov	dpl,#0x30
	ljmp	_putchar
L003009?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:131: char MEMSPACE_BUF *p = &buf[sizeof (buf) - 1];
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:132: char neg = 0;
	mov	dptr,#___printn_neg_2_54
	clr	a
	movx	@dptr,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:134: buf[sizeof(buf) - 1] = '\0';
	mov	r0,#(___printn_buf_2_54 + 0x0005)
	mov	@r0,#0x00
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:136: if (0 > n)
	mov	a,r3
	jnb	acc.7,L003016?
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:138: n = -n;
	mov	dptr,#___printn_n_1_51
	clr	c
	clr	a
	subb	a,r2
	movx	@dptr,a
	clr	a
	subb	a,r3
	inc	dptr
	movx	@dptr,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:139: neg = 1;
	mov	dptr,#___printn_neg_2_54
	mov	a,#0x01
	movx	@dptr,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:142: while (0 != n)
L003016?:
	mov	r0,#(___printn_buf_2_54 + 0x0005)
L003003?:
	mov	dptr,#___printn_n_1_51
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	cjne	r2,#0x00,L003022?
	cjne	r3,#0x00,L003022?
	sjmp	L003005?
L003022?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:144: *--p = '0' + __mod (n, 10);
	dec	r0
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x0A
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	push	ar0
	lcall	__modsint
	mov	r4,dpl
	pop	ar0
	pop	ar3
	pop	ar2
	mov	a,#0x30
	add	a,r4
	mov	@r0,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:145: n = __div (n, 10);
	mov	dptr,#__divsint_PARM_2
	mov	a,#0x0A
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	push	ar0
	lcall	__divsint
	mov	a,dpl
	mov	b,dph
	pop	ar0
	mov	dptr,#___printn_n_1_51
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	sjmp	L003003?
L003005?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:148: if (neg)
	mov	dptr,#___printn_neg_2_54
	movx	a,@dptr
	mov	r2,a
	jz	L003007?
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:149: putchar('-');
	mov	dpl,#0x2D
	push	ar0
	lcall	_putchar
	pop	ar0
L003007?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:151: __prints(p);
	mov	ar2,r0
	mov	r3,#0x00
	mov	r4,#0x40
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	___prints
;------------------------------------------------------------
;Allocation info for local variables in function '_c51_external_startup'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:159: _c51_external_startup (void)
;	-----------------------------------------
;	 function _c51_external_startup
;	-----------------------------------------
__c51_external_startup:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:163: TI = 1;
	setb	_TI
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:164: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__printf'
;------------------------------------------------------------
;szFormat                  Allocated to stack - offset -5
;ap                        Allocated to registers r2 
;sz                        Allocated to registers r3 r4 r5 
;i                         Allocated to registers r3 r4 
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:170: __printf (const char *szFormat, ...)
;	-----------------------------------------
;	 function __printf
;	-----------------------------------------
___printf:
	push	_bp
	mov	_bp,sp
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:173: va_start (ap, szFormat);
	mov	a,_bp
	add	a,#0xfb
	mov	r2,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:175: while (*szFormat)
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
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:177: if (*szFormat == '%')
	cjne	r6,#0x25,L005021?
	sjmp	L005022?
L005021?:
	ljmp	L005007?
L005022?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:179: switch (*++szFormat)
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
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:181: case 's':
	cjne	r3,#0x75,L005008?
	sjmp	L005002?
L005001?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:183: char *sz = va_arg (ap, char *);
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
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:184: __prints(sz);
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	push	ar2
	lcall	___prints
	pop	ar2
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:185: break;
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:188: case 'u':
	sjmp	L005008?
L005002?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:190: int i = va_arg (ap, int);
	mov	a,r2
	add	a,#0xfe
	mov	r0,a
	mov	r2,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	dec	r0
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:191: __printn (i);
	mov	dpl,r3
	mov	dph,r4
	push	ar2
	lcall	___printn
	pop	ar2
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:192: break;
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:195: case '%':
	sjmp	L005008?
L005003?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:196: putchar ('%');
	mov	dpl,#0x25
	push	ar2
	lcall	_putchar
	pop	ar2
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:197: break;
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:201: }
	sjmp	L005008?
L005007?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:205: putchar (*szFormat);
	mov	dpl,r6
	push	ar2
	lcall	_putchar
	pop	ar2
L005008?:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:207: szFormat++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L005026?
	inc	r0
	inc	@r0
L005026?:
	ljmp	L005009?
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:209: va_end (ap);
L005012?:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__fail'
;------------------------------------------------------------
;sloc0                     Allocated with name '___fail_sloc0_1_0'
;szCond                    Allocated with name '___fail_PARM_2'
;szFile                    Allocated with name '___fail_PARM_3'
;line                      Allocated with name '___fail_PARM_4'
;szMsg                     Allocated with name '___fail_szMsg_1_68'
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:213: __fail (code const char *szMsg, code const char *szCond, code const char *szFile, int line)
;	-----------------------------------------
;	 function __fail
;	-----------------------------------------
___fail:
	mov	r2,dph
	mov	a,dpl
	mov	dptr,#___fail_szMsg_1_68
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:215: __printf("--- FAIL: \"%s\" on %s at %s:%u\n", szMsg, szCond, szFile, line);
	mov	dptr,#___fail_PARM_3
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x80
	mov	dptr,#___fail_PARM_2
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	___fail_sloc0_1_0,r5
	mov	(___fail_sloc0_1_0 + 1),r6
	mov	(___fail_sloc0_1_0 + 2),#0x80
	mov	dptr,#___fail_szMsg_1_68
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	mov	r5,#0x80
	mov	dptr,#___fail_PARM_4
	movx	a,@dptr
	push	acc
	inc	dptr
	movx	a,@dptr
	push	acc
	push	ar2
	push	ar3
	push	ar4
	push	___fail_sloc0_1_0
	push	(___fail_sloc0_1_0 + 1)
	push	(___fail_sloc0_1_0 + 2)
	push	ar0
	push	ar1
	push	ar5
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
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:216: __numFailures++;
	mov	dptr,#___numFailures
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:220: main (void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:222: __printf("--- Running: %s\n", __getSuiteName());
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
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:224: __runSuite();
	lcall	___runSuite
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:228: __numFailures, __numTests, __numCases
	mov	dptr,#___numCases
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	mov	a,#0x01
	movc	a,@a+dptr
	mov	r3,a
	mov	dptr,#___numTests
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#___numFailures
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:226: __printf("--- Summary: %u/%u/%u: %u failed of %u tests in %u cases.\n",
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
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
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:231: IE=0;
	mov	_IE,#0x00
;	C:\Source\call51\Source\regression\cases_gcc\/../fwk/include/testfwk.h:232: return 0;
	mov	dptr,#0x0000
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'foo'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:13: foo (void)
;	-----------------------------------------
;	 function foo
;	-----------------------------------------
_foo:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:15: return 0.0;
	mov	dptr,#(0x00&0x00ff)
	clr	a
	mov	b,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'do_sibcall'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:19: do_sibcall (void)
;	-----------------------------------------
;	 function do_sibcall
;	-----------------------------------------
_do_sibcall:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:21: (void) foo ();
	ljmp	_foo
;------------------------------------------------------------
;Allocation info for local variables in function 'testTortureExecute'
;------------------------------------------------------------
;x                         Allocated with name '_testTortureExecute_x_1_77'
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:25: testTortureExecute (void)
;	-----------------------------------------
;	 function testTortureExecute
;	-----------------------------------------
_testTortureExecute:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:29: for (x = 0; x < 20; x++)
	mov	dptr,#_testTortureExecute_x_1_77
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
L010003?:
	mov	dptr,#_testTortureExecute_x_1_77
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	clr	a
	push	acc
	push	acc
	mov	a,#0xA0
	push	acc
	mov	a,#0x41
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	___fslt
	mov	r6,dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	mov	a,r6
	jz	L010006?
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:30: do_sibcall ();
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_do_sibcall
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:29: for (x = 0; x < 20; x++)
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x3F
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	___fsadd
	mov	r6,dpl
	mov	r7,dph
	mov	r0,b
	mov	r1,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dptr,#_testTortureExecute_x_1_77
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	ljmp	L010003?
L010006?:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:31: if (!(x >= 10))
	clr	a
	push	acc
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#0x41
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	___fslt
	mov	r2,dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r2
	jz	L010002?
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:32: ASSERT (0);
	mov	dptr,#___numTests
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
	mov	dptr,#___fail_PARM_2
	mov	a,#__str_4
	movx	@dptr,a
	inc	dptr
	mov	a,#(__str_4 >> 8)
	movx	@dptr,a
	mov	dptr,#___fail_PARM_3
	mov	a,#__str_5
	movx	@dptr,a
	inc	dptr
	mov	a,#(__str_5 >> 8)
	movx	@dptr,a
	mov	dptr,#___fail_PARM_4
	mov	a,#0x20
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#__str_3
	lcall	___fail
L010002?:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:33: return;
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__runSuite'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:38: __runSuite(void)
;	-----------------------------------------
;	 function __runSuite
;	-----------------------------------------
___runSuite:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:40: __prints("Running testTortureExecute\n");
	mov	dptr,#__str_6
	mov	b,#0x80
	lcall	___prints
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:41: testTortureExecute();
	ljmp	_testTortureExecute
;------------------------------------------------------------
;Allocation info for local variables in function '__getSuiteName'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:47: __getSuiteName(void)
;	-----------------------------------------
;	 function __getSuiteName
;	-----------------------------------------
___getSuiteName:
;	C:\Source\call51\Source\regression\cases_gcc\gcc-torture-execute-20000731-1.c:49: return "cases_gcc\\gcc-torture-execute-20000731-1";
	mov	dptr,#__str_7
	ret
	rseg R_CSEG

	rseg R_XINIT
__xinit____numTests:
	db 0x00,0x00	;  0
__xinit____numFailures:
	db 0x00,0x00	;  0

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
	db 'Assertion failed'
	db 0x00
__str_4:
	db '0'
	db 0x00
__str_5:
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
	db 'cases_gcc'
	db 0x5C
	db 'gcc-torture-exe'
	db 'cute-20000731-1.c'
	db 0x00
__str_6:
	db 'Running testTortureExecute'
	db 0x0A
	db 0x00
___numCases:
	db 0x01,0x00	;  1
__str_7:
	db 'cases_gcc'
	db 0x5C
	db 'gcc-torture-execute-20000731-1'
	db 0x00

	CSEG

end
