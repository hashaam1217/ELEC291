;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1028 (Nov 13 2012) (MSVC)
; This file was generated Sat Nov 24 21:15:43 2012
;--------------------------------------------------------
$name t_abs
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
	public _testAbs
	public _main
	public ___fail_PARM_4
	public ___fail_PARM_3
	public ___fail_PARM_2
	public ___numTests
	public ___prints
	public ___printn
	public ___printf
	public ___fail
;--------------------------------------------------------
; Special Function Registers
;--------------------------------------------------------
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:68: int __numTests = 0;
	clr	a
	mov	___numTests,a
	mov	(___numTests + 1),a
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:69: static int __numFailures = 0;
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:99: __prints (const char *s)
;	-----------------------------------------
;	 function __prints
;	-----------------------------------------
___prints:
	using	0
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:103: while ('\0' != (c = *s))
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:105: _putchar(c);
	mov	dpl,r6
	push	ar2
	push	ar3
	push	ar4
	lcall	__putchar
	pop	ar4
	pop	ar3
	pop	ar2
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:106: ++s;
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:111: __printn (int n)
;	-----------------------------------------
;	 function __printn
;	-----------------------------------------
___printn:
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:113: if (0 == n)
	cjne	r2,#0x00,L003009?
	cjne	r3,#0x00,L003009?
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:115: _putchar('0');
	mov	dpl,#0x30
	ljmp	__putchar
L003009?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:120: char MEMSPACE_BUF *p = &buf[sizeof (buf) - 1];
	mov	r4,#(___printn_buf_2_3 + 0x0005)
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:121: char neg = 0;
	mov	r5,#0x00
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:123: buf[sizeof(buf) - 1] = '\0';
	mov	r0,#(___printn_buf_2_3 + 0x0005)
	mov	@r0,#0x00
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:125: if (0 > n)
	mov	a,r3
	jnb	acc.7,L003016?
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:127: n = -n;
	clr	c
	clr	a
	subb	a,r2
	mov	r2,a
	clr	a
	subb	a,r3
	mov	r3,a
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:128: neg = 1;
	mov	r5,#0x01
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:131: while (0 != n)
L003016?:
	mov	ar0,r4
L003003?:
	cjne	r2,#0x00,L003022?
	cjne	r3,#0x00,L003022?
	sjmp	L003018?
L003022?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:133: *--p = '0' + __mod (n, 10);
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:134: n = __div (n, 10);
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:137: if (neg)
	mov	a,r5
	jz	L003007?
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:138: _putchar('-');
	mov	dpl,#0x2D
	push	ar4
	lcall	__putchar
	pop	ar4
L003007?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:140: __prints(p);
	mov	r2,#0x00
	mov	r3,#0x40
	mov	dpl,r4
	mov	dph,r2
	mov	b,r3
	ljmp	___prints
;------------------------------------------------------------
;Allocation info for local variables in function '__printf'
;------------------------------------------------------------
;szFormat                  Allocated to stack - offset -5
;ap                        Allocated to registers r2 
;sz                        Allocated to registers r3 r4 r5 
;i                         Allocated to registers 
;------------------------------------------------------------
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:146: __printf (const char *szFormat, ...)
;	-----------------------------------------
;	 function __printf
;	-----------------------------------------
___printf:
	push	_bp
	mov	_bp,sp
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:149: va_start (ap, szFormat);
	mov	a,_bp
	add	a,#0xfb
	mov	r2,a
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:151: while (*szFormat)
L004009?:
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
	jnz	L004020?
	ljmp	L004012?
L004020?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:153: if (*szFormat == '%')
	cjne	r6,#0x25,L004021?
	sjmp	L004022?
L004021?:
	ljmp	L004007?
L004022?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:155: switch (*++szFormat)
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
	cjne	r3,#0x25,L004023?
	sjmp	L004003?
L004023?:
	cjne	r3,#0x73,L004024?
	sjmp	L004001?
L004024?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:157: case 's':
	cjne	r3,#0x75,L004008?
	sjmp	L004002?
L004001?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:159: char *sz = va_arg (ap, char *);
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:160: __prints(sz);
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	push	ar2
	lcall	___prints
	pop	ar2
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:161: break;
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:164: case 'u':
	sjmp	L004008?
L004002?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:166: int i = va_arg (ap, int);
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:167: __printn (i);
	push	ar2
	lcall	___printn
	pop	ar2
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:168: break;
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:171: case '%':
	sjmp	L004008?
L004003?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:172: _putchar ('%');
	mov	dpl,#0x25
	push	ar2
	lcall	__putchar
	pop	ar2
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:173: break;
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:177: }
	sjmp	L004008?
L004007?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:181: _putchar (*szFormat);
	mov	dpl,r6
	push	ar2
	lcall	__putchar
	pop	ar2
L004008?:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:183: szFormat++;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,L004026?
	inc	r0
	inc	@r0
L004026?:
	ljmp	L004009?
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:185: va_end (ap);
L004012?:
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:189: __fail (code const char *szMsg, code const char *szCond, code const char *szFile, int line)
;	-----------------------------------------
;	 function __fail
;	-----------------------------------------
___fail:
	mov	r2,dpl
	mov	r3,dph
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:191: __printf("--- FAIL: \"%s\" on %s at %s:%u\n", szMsg, szCond, szFile, line);
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:192: __numFailures++;
	inc	___numFailures
	clr	a
	cjne	a,___numFailures,L005003?
	inc	(___numFailures + 1)
L005003?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:196: main (void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:198: _initEmu();
	lcall	__initEmu
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:200: __printf("--- Running: %s\n", __getSuiteName());
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:202: __runSuite();
	lcall	___runSuite
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:206: __numFailures, __numTests, __numCases
	mov	dptr,#___numCases
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	mov	a,#0x01
	movc	a,@a+dptr
	mov	r3,a
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:204: __printf("--- Summary: %u/%u/%u: %u failed of %u tests in %u cases.\n",
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
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:209: _exitEmu();
	lcall	__exitEmu
;	C:\Source\call51\regression\tests\/../fwk/include/testfwk.h:211: return 0;
	mov	dptr,#0x0000
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'testAbs'
;------------------------------------------------------------
;------------------------------------------------------------
;	C:\Source\call51\regression\tests\t_abs.c:7: testAbs(void)
;	-----------------------------------------
;	 function testAbs
;	-----------------------------------------
_testAbs:
;	C:\Source\call51\regression\tests\t_abs.c:9: ASSERT( abs(0x7fff) == 0x7fff );
	inc	___numTests
	clr	a
	cjne	a,___numTests,L007021?
	inc	(___numTests + 1)
L007021?:
	mov	dptr,#0x7FFF
	lcall	_abs
	mov	r2,dpl
	mov	r3,dph
	cjne	r2,#0xFF,L007022?
	cjne	r3,#0x7F,L007022?
	sjmp	L007004?
L007022?:
	mov	___fail_PARM_2,#__str_4
	mov	(___fail_PARM_2 + 1),#(__str_4 >> 8)
	mov	___fail_PARM_3,#__str_5
	mov	(___fail_PARM_3 + 1),#(__str_5 >> 8)
	mov	___fail_PARM_4,#0x09
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_3
	lcall	___fail
L007004?:
;	C:\Source\call51\regression\tests\t_abs.c:10: ASSERT( abs(-1000)  == 1000 );
	inc	___numTests
	clr	a
	cjne	a,___numTests,L007023?
	inc	(___numTests + 1)
L007023?:
	mov	dptr,#0xFC18
	lcall	_abs
	mov	r2,dpl
	mov	r3,dph
	cjne	r2,#0xE8,L007024?
	cjne	r3,#0x03,L007024?
	sjmp	L007006?
L007024?:
	mov	___fail_PARM_2,#__str_6
	mov	(___fail_PARM_2 + 1),#(__str_6 >> 8)
	mov	___fail_PARM_3,#__str_5
	mov	(___fail_PARM_3 + 1),#(__str_5 >> 8)
	mov	___fail_PARM_4,#0x0A
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_3
	lcall	___fail
L007006?:
;	C:\Source\call51\regression\tests\t_abs.c:11: ASSERT( abs(-32767) == 32767 );
	inc	___numTests
	clr	a
	cjne	a,___numTests,L007025?
	inc	(___numTests + 1)
L007025?:
	mov	dptr,#0x8001
	lcall	_abs
	mov	r2,dpl
	mov	r3,dph
	cjne	r2,#0xFF,L007026?
	cjne	r3,#0x7F,L007026?
	sjmp	L007008?
L007026?:
	mov	___fail_PARM_2,#__str_7
	mov	(___fail_PARM_2 + 1),#(__str_7 >> 8)
	mov	___fail_PARM_3,#__str_5
	mov	(___fail_PARM_3 + 1),#(__str_5 >> 8)
	mov	___fail_PARM_4,#0x0B
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_3
	lcall	___fail
L007008?:
;	C:\Source\call51\regression\tests\t_abs.c:13: ASSERT( labs(0x7FFFffffuL) == 0x7FFFffffuL );
	inc	___numTests
	clr	a
	cjne	a,___numTests,L007027?
	inc	(___numTests + 1)
L007027?:
	mov	dptr,#0xFFFF
	mov	b,#0xFF
	mov	a,#0x7F
	lcall	_labs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	cjne	r2,#0xFF,L007028?
	cjne	r3,#0xFF,L007028?
	cjne	r4,#0xFF,L007028?
	cjne	r5,#0x7F,L007028?
	sjmp	L007010?
L007028?:
	mov	___fail_PARM_2,#__str_8
	mov	(___fail_PARM_2 + 1),#(__str_8 >> 8)
	mov	___fail_PARM_3,#__str_5
	mov	(___fail_PARM_3 + 1),#(__str_5 >> 8)
	mov	___fail_PARM_4,#0x0D
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_3
	lcall	___fail
L007010?:
;	C:\Source\call51\regression\tests\t_abs.c:14: ASSERT( labs(-1000000L)    == 1000000L );
	inc	___numTests
	clr	a
	cjne	a,___numTests,L007029?
	inc	(___numTests + 1)
L007029?:
	mov	dptr,#0xBDC0
	mov	b,#0xF0
	mov	a,#0xFF
	lcall	_labs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	cjne	r2,#0x40,L007030?
	cjne	r3,#0x42,L007030?
	cjne	r4,#0x0F,L007030?
	cjne	r5,#0x00,L007030?
	sjmp	L007012?
L007030?:
	mov	___fail_PARM_2,#__str_9
	mov	(___fail_PARM_2 + 1),#(__str_9 >> 8)
	mov	___fail_PARM_3,#__str_5
	mov	(___fail_PARM_3 + 1),#(__str_5 >> 8)
	mov	___fail_PARM_4,#0x0E
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_3
	lcall	___fail
L007012?:
;	C:\Source\call51\regression\tests\t_abs.c:15: ASSERT( labs(-2147483647L) == 2147483647L );
	inc	___numTests
	clr	a
	cjne	a,___numTests,L007031?
	inc	(___numTests + 1)
L007031?:
	mov	dptr,#(0x01&0x00ff)
	clr	a
	mov	b,a
	mov	a,#0x80
	lcall	_labs
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	cjne	r2,#0xFF,L007032?
	cjne	r3,#0xFF,L007032?
	cjne	r4,#0xFF,L007032?
	cjne	r5,#0x7F,L007032?
	ret
L007032?:
	mov	___fail_PARM_2,#__str_10
	mov	(___fail_PARM_2 + 1),#(__str_10 >> 8)
	mov	___fail_PARM_3,#__str_5
	mov	(___fail_PARM_3 + 1),#(__str_5 >> 8)
	mov	___fail_PARM_4,#0x0F
	clr	a
	mov	(___fail_PARM_4 + 1),a
	mov	dptr,#__str_3
	ljmp	___fail
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
	db 'Assertion failed'
	db 0x00
__str_4:
	db 'abs(0x7fff) == 0x7fff'
	db 0x00
__str_5:
	db 'C:'
	db 0x5C
	db 'Source'
	db 0x5C
	db 'call51'
	db 0x5C
	db 'regression'
	db 0x5C
	db 'tests'
	db 0x5C
	db 't_abs.c'
	db 0x00
__str_6:
	db 'abs(-1000) == 1000'
	db 0x00
__str_7:
	db 'abs(-32767) == 32767'
	db 0x00
__str_8:
	db 'labs(0x7FFFffffuL) == 0x7FFFffffuL'
	db 0x00
__str_9:
	db 'labs(-1000000L) == 1000000L'
	db 0x00
__str_10:
	db 'labs(-2147483647L) == 2147483647L'
	db 0x00

	rseg R_XINIT

	CSEG

end
