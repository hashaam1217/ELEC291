;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Dec 11 2012) (MSVC)
; This file was generated Mon Jan 07 19:38:33 2013
;--------------------------------------------------------
$name p89v51rd2
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
	public _FlashByte_PARM_2
	public _bitn
	public _sfrn
	public _JumpToMonitor
	public _set_timer1_priority
	public _getchar
	public __sdcc_external_startup
	public _main
	public _asm_code_sfr
	public _putnl
	public _FlashByte
	public _erasesector
	public _loadintelhex
	public _read_sfr
	public _write_sfr
	public _restorePC
	public _cpuid
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
_AUXR           DATA 0x8e
_AUXR1          DATA 0xa2
_CCAP0H         DATA 0xfa
_CCAP1H         DATA 0xfb
_CCAP2H         DATA 0xfc
_CCAP3H         DATA 0xfd
_CCAP4H         DATA 0xfe
_CCAP0L         DATA 0xea
_CCAP1L         DATA 0xeb
_CCAP2L         DATA 0xec
_CCAP3L         DATA 0xed
_CCAP4L         DATA 0xee
_CCAPM0         DATA 0xda
_CCAPM1         DATA 0xdb
_CCAPM2         DATA 0xdc
_CCAPM3         DATA 0xdd
_CCAPM4         DATA 0xde
_CCON           DATA 0xd8
_CH             DATA 0xf9
_CL             DATA 0xe9
_CMOD           DATA 0xd9
_FST            DATA 0xb6
_FCF            DATA 0xb1
_IEN0           DATA 0xa8
_IEN1           DATA 0xe8
_IP0            DATA 0xb8
_IP0H           DATA 0xb7
_IP1            DATA 0xf8
_IP1H           DATA 0xf7
_SADDR          DATA 0xa9
_SADEN          DATA 0xb9
_SPCR           DATA 0xd5
_SPCTL          DATA 0xd5
_SPSR           DATA 0xaa
_SPCFG          DATA 0xaa
_SPDR           DATA 0x86
_SPDAT          DATA 0x86
_WDTC           DATA 0xc0
_WDTD           DATA 0x85
_T2MOD          DATA 0xc9
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
_ET2            BIT 0xad
_PT2            BIT 0xbd
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
_CF             BIT 0xdf
_CR             BIT 0xde
_CCF4           BIT 0xdc
_CCF3           BIT 0xdb
_CCF2           BIT 0xda
_CCF1           BIT 0xd9
_CCF0           BIT 0xd8
_EC             BIT 0xae
_EBO            BIT 0xeb
_PPC            BIT 0xbe
_PBO            BIT 0xfb
_WDOUT          BIT 0xc4
_WDRE           BIT 0xc3
_WDTS           BIT 0xc2
_WDT            BIT 0xc1
_SWDT           BIT 0xc0
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
	rseg	R_OSEG
_FlashByte_PARM_2:
	ds 1
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
_loadintelhex_errorbit_1_38:
	DBIT	1
_loadintelhex_errorprog_1_38:
	DBIT	1
_loadintelhex_wroteat1b_1_38:
	DBIT	1
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
	CSEG at 0xe000
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
;Allocation info for local variables in function 'asm_code_sfr'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:47: void asm_code_sfr (void) _naked
;	-----------------------------------------
;	 function asm_code_sfr
;	-----------------------------------------
_asm_code_sfr:
;	naked function: no prologue.
;	.\p89v51rd2.c:58: _endasm;
	
	     dumm_sfr_address data 0xff
	     _code_sfr:
  ; Write sfr
	  mov dumm_sfr_address, dpl
	  ret
  ; Read sfr
	  mov dpl, dumm_sfr_address
	  ret
	    
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:195: void main (void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	using	0
;	.\p89v51rd2.c:199: _endasm; //All the work is done in cmon51.c
	
	  ljmp _do_cmd
	 
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_sdcc_external_startup'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:202: unsigned char _sdcc_external_startup(void)
;	-----------------------------------------
;	 function _sdcc_external_startup
;	-----------------------------------------
__sdcc_external_startup:
;	.\p89v51rd2.c:204: IE=0;
	mov	_IE,#0x00
;	.\p89v51rd2.c:205: TR1=0;
	clr	_TR1
;	.\p89v51rd2.c:206: TMOD=(TMOD&0x0f)|0x20;
	mov	a,#0x0F
	anl	a,_TMOD
	orl	a,#0x20
	mov	_TMOD,a
;	.\p89v51rd2.c:207: PCON|=0x80; //x2 baudrate
	orl	_PCON,#0x80
;	.\p89v51rd2.c:208: TH1=TIMER1_K2_115200;
	mov	_TH1,#0xFF
;	.\p89v51rd2.c:209: TR1=1;
	setb	_TR1
;	.\p89v51rd2.c:210: SCON=0x52;
	mov	_SCON,#0x52
;	.\p89v51rd2.c:212: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getchar'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:215: char getchar(void)
;	-----------------------------------------
;	 function getchar
;	-----------------------------------------
_getchar:
;	.\p89v51rd2.c:217: while (!RI);
L005001?:
;	.\p89v51rd2.c:218: RI=0;
	jbc	_RI,L005008?
	sjmp	L005001?
L005008?:
;	.\p89v51rd2.c:219: return SBUF;
	mov	dpl,_SBUF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putnl'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:222: void putnl (void)
;	-----------------------------------------
;	 function putnl
;	-----------------------------------------
_putnl:
;	.\p89v51rd2.c:224: while (!TI);
L006001?:
;	.\p89v51rd2.c:225: TI=0;
	jbc	_TI,L006013?
	sjmp	L006001?
L006013?:
;	.\p89v51rd2.c:226: SBUF='\r';
	mov	_SBUF,#0x0D
;	.\p89v51rd2.c:227: while (!TI);
L006004?:
;	.\p89v51rd2.c:228: TI=0;
	jbc	_TI,L006014?
	sjmp	L006004?
L006014?:
;	.\p89v51rd2.c:229: SBUF='\n';
	mov	_SBUF,#0x0A
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'FlashByte'
;------------------------------------------------------------
;value                     Allocated with name '_FlashByte_PARM_2'
;address                   Allocated to registers r2 r3 
;------------------------------------------------------------
;	.\p89v51rd2.c:233: void FlashByte (unsigned int address, unsigned char value)
;	-----------------------------------------
;	 function FlashByte
;	-----------------------------------------
_FlashByte:
	mov	r2,dpl
	mov	r3,dph
;	.\p89v51rd2.c:235: if(address>=MONITOR_LOC) return; //Protect the monitor
	mov	a,#0x100 - 0xE0
	add	a,r3
	jnc	L007002?
	ret
L007002?:
;	.\p89v51rd2.c:236: FCF=0; //Flash routines are in block 0
	mov	_FCF,#0x00
;	.\p89v51rd2.c:243: _endasm;
	
	  mov R1, #0x02
  ;DPH contains the high part of the sector
  ;DPL contains the low part of the sector
	  mov a,_FlashByte_PARM_2
	  lcall 0x1ff0
	 
;	.\p89v51rd2.c:244: FCF=BSEL; //Go back to block 1
	mov	_FCF,#0x01
;	.\p89v51rd2.c:246: value; 
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'erasesector'
;------------------------------------------------------------
;address                   Allocated to registers r2 r3 
;------------------------------------------------------------
;	.\p89v51rd2.c:252: void erasesector (unsigned int address)
;	-----------------------------------------
;	 function erasesector
;	-----------------------------------------
_erasesector:
	mov	r2,dpl
	mov	r3,dph
;	.\p89v51rd2.c:254: if(address<MONITOR_LOC)
	mov	a,#0x100 - 0xE0
	add	a,r3
	jnc	L008009?
	ljmp	L008002?
L008009?:
;	.\p89v51rd2.c:256: FCF=0; //Flash routines are in block 0
	mov	_FCF,#0x00
;	.\p89v51rd2.c:262: _endasm;
	
	   mov R1, #0x08
   ;DPH contains the high part of the sector
   ;DPL contains the low part of the sector
	   lcall 0x1ff0 ;Entry point
	  
;	.\p89v51rd2.c:263: FCF=BSEL; //Go back to block 1
	mov	_FCF,#0x01
L008002?:
;	.\p89v51rd2.c:265: if(address<0x0080)
	clr	c
	mov	a,r2
	subb	a,#0x80
	mov	a,r3
	subb	a,#0x00
	jnc	L008005?
;	.\p89v51rd2.c:268: FlashByte(0x0000, 0x02);
	mov	_FlashByte_PARM_2,#0x02
	mov	dptr,#0x0000
	lcall	_FlashByte
;	.\p89v51rd2.c:269: FlashByte(0x0001, MONITOR_LOC/0x100);
	mov	_FlashByte_PARM_2,#0xE0
	mov	dptr,#0x0001
	lcall	_FlashByte
;	.\p89v51rd2.c:270: FlashByte(0x0002, 0x00);
	mov	_FlashByte_PARM_2,#0x00
	mov	dptr,#0x0002
	lcall	_FlashByte
;	.\p89v51rd2.c:273: FlashByte(0x001b, 0x02);
	mov	_FlashByte_PARM_2,#0x02
	mov	dptr,#0x001B
	lcall	_FlashByte
;	.\p89v51rd2.c:274: FlashByte(0x001c, MONITOR_LOC/0x100);
	mov	_FlashByte_PARM_2,#0xE0
	mov	dptr,#0x001C
	lcall	_FlashByte
;	.\p89v51rd2.c:275: FlashByte(0x001d, 0x03);
	mov	_FlashByte_PARM_2,#0x03
	mov	dptr,#0x001D
	ljmp	_FlashByte
L008005?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'loadintelhex'
;------------------------------------------------------------
;j                         Allocated to registers r3 r0 
;address                   Allocated to registers r4 r5 
;size                      Allocated to registers r3 
;type                      Allocated to registers r7 
;check                     Allocated to registers r6 
;n                         Allocated to registers r2 
;ptr                       Allocated to registers 
;------------------------------------------------------------
;	.\p89v51rd2.c:279: void loadintelhex (void)
;	-----------------------------------------
;	 function loadintelhex
;	-----------------------------------------
_loadintelhex:
;	.\p89v51rd2.c:286: saved_jmp[0]=0;        	
	mov	dptr,#_saved_jmp
;	.\p89v51rd2.c:287: saved_int[0]=0;        	
	clr	a
	movx	@dptr,a
	mov	dptr,#_saved_int
	movx	@dptr,a
;	.\p89v51rd2.c:289: putsp("Erasing");
	mov	dptr,#__str_0
	mov	b,#0x80
	lcall	_putsp
;	.\p89v51rd2.c:290: for(j=0; j<MONITOR_LOC; j+=0x80)
	mov	r2,#0x00
	mov	r3,#0x00
L009049?:
	mov	a,#0x100 - 0xE0
	add	a,r3
	jc	L009052?
;	.\p89v51rd2.c:292: if((j%0x800)==0) putc('.');
	mov	a,r2
	jnz	L009088?
	mov	a,r3
	anl	a,#0x07
	jz	L009089?
L009088?:
	sjmp	L009005?
L009089?:
L009001?:
	jbc	_TI,L009090?
	sjmp	L009001?
L009090?:
	mov	_SBUF,#0x2E
L009005?:
;	.\p89v51rd2.c:293: erasesector(j);
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	lcall	_erasesector
	pop	ar3
	pop	ar2
;	.\p89v51rd2.c:290: for(j=0; j<MONITOR_LOC; j+=0x80)
	mov	a,#0x80
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	sjmp	L009049?
L009052?:
;	.\p89v51rd2.c:295: putsp("\nSend file or <Esc>\n");
	mov	dptr,#__str_1
	mov	b,#0x80
	lcall	_putsp
;	.\p89v51rd2.c:297: errorbit=0;
	clr	_loadintelhex_errorbit_1_38
;	.\p89v51rd2.c:298: errorprog=0;
	clr	_loadintelhex_errorprog_1_38
;	.\p89v51rd2.c:299: wroteat1b=0;
	clr	_loadintelhex_wroteat1b_1_38
;	.\p89v51rd2.c:301: while(1)
L009034?:
;	.\p89v51rd2.c:303: n=getchar();
	lcall	_getchar
	mov	r2,dpl
;	.\p89v51rd2.c:305: if(n==0x1b) break; //Provide a way out
	cjne	r2,#0x1B,L009091?
	ljmp	L009035?
L009091?:
;	.\p89v51rd2.c:307: if(n==(unsigned char)':')
	cjne	r2,#0x3A,L009034?
;	.\p89v51rd2.c:309: size=getbytene();
	lcall	_getbytene
	mov	r3,dpl
;	.\p89v51rd2.c:312: address=getbytene();
	push	ar3
	lcall	_getbytene
	mov	r4,dpl
	pop	ar3
;	.\p89v51rd2.c:313: check+=address;
	mov	a,r4
	add	a,r3
	mov	r6,a
;	.\p89v51rd2.c:314: address*=0x100;
	mov	ar5,r4
	mov	r4,#0x00
;	.\p89v51rd2.c:315: n=getbytene();
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_getbytene
	mov	r2,dpl
	pop	ar6
	pop	ar5
	pop	ar4
;	.\p89v51rd2.c:316: check+=n;
	mov	a,r2
	add	a,r6
	mov	r6,a
;	.\p89v51rd2.c:317: address+=n;
	mov	ar7,r2
	mov	r0,#0x00
	mov	a,r7
	add	a,r4
	mov	r4,a
	mov	a,r0
	addc	a,r5
	mov	r5,a
;	.\p89v51rd2.c:319: type=getbytene();
	push	ar4
	push	ar5
	push	ar6
	lcall	_getbytene
	mov	r7,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
;	.\p89v51rd2.c:320: check+=type;
	mov	a,r7
	add	a,r6
	mov	r6,a
;	.\p89v51rd2.c:322: for(j=address+size; address<j; address++)
	mov	r0,#0x00
	mov	a,r3
	add	a,r4
	mov	r3,a
	mov	a,r0
	addc	a,r5
	mov	r0,a
L009053?:
	clr	c
	mov	a,r4
	subb	a,r3
	mov	a,r5
	subb	a,r0
	jc	L009094?
	ljmp	L009056?
L009094?:
;	.\p89v51rd2.c:324: n=getbytene();
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar0
	lcall	_getbytene
	mov	r2,dpl
	pop	ar0
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
;	.\p89v51rd2.c:325: check+=n;
	mov	a,r2
	add	a,r6
	mov	r6,a
;	.\p89v51rd2.c:326: if(type==0x00)
	mov	a,r7
	jnz	L009055?
;	.\p89v51rd2.c:328: if((address>2) && ((address<0x1b)||(address>0x1d)))
	clr	c
	mov	a,#0x02
	subb	a,r4
	clr	a
	subb	a,r5
	jnc	L009014?
	clr	c
	mov	a,r4
	subb	a,#0x1B
	mov	a,r5
	subb	a,#0x00
	jc	L009013?
	mov	a,#0x1D
	subb	a,r4
	clr	a
	subb	a,r5
	jnc	L009014?
L009013?:
;	.\p89v51rd2.c:330: FlashByte(address, n);
	mov	_FlashByte_PARM_2,r2
	mov	dpl,r4
	mov	dph,r5
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar0
	lcall	_FlashByte
	pop	ar0
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	.\p89v51rd2.c:331: ptr=(unsigned char code *)address;
	mov	dpl,r4
	mov	dph,r5
;	.\p89v51rd2.c:332: if(*ptr!=n) errorprog=1;
	clr	a
	movc	a,@a+dptr
	mov	r1,a
	cjne	a,ar2,L009099?
	sjmp	L009055?
L009099?:
	setb	_loadintelhex_errorprog_1_38
	sjmp	L009055?
L009014?:
;	.\p89v51rd2.c:336: if (address<0x3)
	clr	c
	mov	a,r4
	subb	a,#0x03
	mov	a,r5
	subb	a,#0x00
	jnc	L009011?
;	.\p89v51rd2.c:338: saved_jmp[address]=n;
	mov	a,r4
	add	a,#_saved_jmp
	mov	dpl,a
	mov	a,r5
	addc	a,#(_saved_jmp >> 8)
	mov	dph,a
	mov	a,r2
	movx	@dptr,a
	sjmp	L009055?
L009011?:
;	.\p89v51rd2.c:342: saved_int[address-0x1b]=n;
	mov	ar1,r4
	mov	a,r1
	add	a,#0xe5
	add	a,#_saved_int
	mov	dpl,a
	clr	a
	addc	a,#(_saved_int >> 8)
	mov	dph,a
	mov	a,r2
	movx	@dptr,a
;	.\p89v51rd2.c:343: wroteat1b=1;
	setb	_loadintelhex_wroteat1b_1_38
L009055?:
;	.\p89v51rd2.c:322: for(j=address+size; address<j; address++)
	inc	r4
	cjne	r4,#0x00,L009101?
	inc	r5
L009101?:
	ljmp	L009053?
L009056?:
;	.\p89v51rd2.c:349: check+=getbytene();
	push	ar6
	push	ar7
	lcall	_getbytene
	mov	r2,dpl
	pop	ar7
	pop	ar6
	mov	a,r2
	add	a,r6
	mov	r6,a
;	.\p89v51rd2.c:351: if(type!=0x00) break; //Most likely end record (type=0x01)
	mov	a,r7
	jnz	L009035?
;	.\p89v51rd2.c:352: if(check!=0)
	mov	a,r6
	jz	L009025?
;	.\p89v51rd2.c:354: errorbit=1;
	setb	_loadintelhex_errorbit_1_38
;	.\p89v51rd2.c:355: putc('X'); //This means there was a checksum error in the record
L009022?:
	jbc	_TI,L009104?
	sjmp	L009022?
L009104?:
	mov	_SBUF,#0x58
	ljmp	L009034?
;	.\p89v51rd2.c:357: else putc('.');
L009025?:
	jbc	_TI,L009105?
	sjmp	L009025?
L009105?:
	mov	_SBUF,#0x2E
	ljmp	L009034?
L009035?:
;	.\p89v51rd2.c:361: if(errorbit) putsp("\nChecksum error!\n");
	jnb	_loadintelhex_errorbit_1_38,L009040?
	mov	dptr,#__str_2
	mov	b,#0x80
	lcall	_putsp
	sjmp	L009041?
L009040?:
;	.\p89v51rd2.c:362: else if (errorprog) putsp("\nFlash error!\n");
	jnb	_loadintelhex_errorprog_1_38,L009037?
	mov	dptr,#__str_3
	mov	b,#0x80
	lcall	_putsp
	sjmp	L009041?
L009037?:
;	.\p89v51rd2.c:363: else putsp("\nDone.\n");
	mov	dptr,#__str_4
	mov	b,#0x80
	lcall	_putsp
L009041?:
;	.\p89v51rd2.c:365: if(RI) getchar();//Last newline from final record
	jnb	_RI,L009043?
	lcall	_getchar
L009043?:
;	.\p89v51rd2.c:367: if(saved_jmp[0]==0x02)
	mov	dptr,#_saved_jmp
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x02,L009045?
;	.\p89v51rd2.c:370: FlashByte(MONITOR_LOC-2, saved_jmp[2]);
	mov	dptr,#(_saved_jmp + 0x0002)
	movx	a,@dptr
	mov	_FlashByte_PARM_2,a
	mov	dptr,#0xDFFE
	lcall	_FlashByte
;	.\p89v51rd2.c:371: FlashByte(MONITOR_LOC-1, saved_jmp[1]);
	mov	dptr,#(_saved_jmp + 0x0001)
	movx	a,@dptr
	mov	_FlashByte_PARM_2,a
	mov	dptr,#0xDFFF
	lcall	_FlashByte
;	.\p89v51rd2.c:372: restorePC();
	lcall	_restorePC
L009045?:
;	.\p89v51rd2.c:375: if((saved_int[0]!=0x02)&&(wroteat1b)) putsp("WARNING: missing Timer1 jmp\n");
	mov	dptr,#_saved_int
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x02,L009111?
	ret
L009111?:
	jnb	_loadintelhex_wroteat1b_1_38,L009057?
	mov	dptr,#__str_5
	mov	b,#0x80
	ljmp	_putsp
L009057?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_sfr'
;------------------------------------------------------------
;x                         Allocated to registers r2 
;d                         Allocated to registers r3 
;------------------------------------------------------------
;	.\p89v51rd2.c:378: unsigned char read_sfr (unsigned char x)
;	-----------------------------------------
;	 function read_sfr
;	-----------------------------------------
_read_sfr:
	mov	r2,dpl
;	.\p89v51rd2.c:382: erasesector(MONITOR_LOC-0x100);
	mov	dptr,#0xDF00
	push	ar2
	lcall	_erasesector
	pop	ar2
;	.\p89v51rd2.c:383: for(d=0; d<8; d++) FlashByte((MONITOR_LOC-0x100)+d, code_sfr[d]);
	mov	r3,#0x00
L010001?:
	cjne	r3,#0x08,L010010?
L010010?:
	jnc	L010004?
	mov	ar4,r3
	mov	r5,#0x00
	mov	a,#0xDF
	add	a,r5
	mov	r5,a
	mov	a,r3
	mov	dptr,#_code_sfr
	movc	a,@a+dptr
	mov	_FlashByte_PARM_2,a
	mov	dpl,r4
	mov	dph,r5
	push	ar2
	push	ar3
	lcall	_FlashByte
	pop	ar3
	pop	ar2
	inc	r3
	sjmp	L010001?
L010004?:
;	.\p89v51rd2.c:385: FlashByte((MONITOR_LOC-0x100)+2, x);
	mov	_FlashByte_PARM_2,r2
	mov	dptr,#0xDF02
	push	ar2
	lcall	_FlashByte
	pop	ar2
;	.\p89v51rd2.c:386: FlashByte((MONITOR_LOC-0x100)+5, x);
	mov	_FlashByte_PARM_2,r2
	mov	dptr,#0xDF05
	lcall	_FlashByte
;	.\p89v51rd2.c:390: _endasm;
	
	  ljmp (0xe000 -0x100)+04
	 
;	.\p89v51rd2.c:392: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_sfr'
;------------------------------------------------------------
;val                       Allocated to registers 
;------------------------------------------------------------
;	.\p89v51rd2.c:396: void write_sfr (unsigned char val)
;	-----------------------------------------
;	 function write_sfr
;	-----------------------------------------
_write_sfr:
;	.\p89v51rd2.c:400: _endasm;
	
	  ljmp (0xe000 -0x100)
	 
;	.\p89v51rd2.c:401: val; //To prevent a sdcc warning. Optimized out by sdcc.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restorePC'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:404: void restorePC (void)
;	-----------------------------------------
;	 function restorePC
;	-----------------------------------------
_restorePC:
;	.\p89v51rd2.c:406: PC_save=*(unsigned int code *)(MONITOR_LOC-2); //A copy of the user jump should be there
	mov	dptr,#0xDFFE
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	mov	dptr,#_PC_save
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'cpuid'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:409: void cpuid (void)
;	-----------------------------------------
;	 function cpuid
;	-----------------------------------------
_cpuid:
;	.\p89v51rd2.c:411: putsp(CPUPID);
	mov	dptr,#__str_6
	mov	b,#0x80
	ljmp	_putsp
;------------------------------------------------------------
;Allocation info for local variables in function 'set_timer1_priority'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:414: void set_timer1_priority (void) _naked
;	-----------------------------------------
;	 function set_timer1_priority
;	-----------------------------------------
_set_timer1_priority:
;	naked function: no prologue.
;	.\p89v51rd2.c:420: _endasm;
	
	        setb PT1 ; Highest priority for timer 1 interrupt
	        orl _IP0H, #0x80 ; Highest priority for timer 1 interrupt
	        ret
	    
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'JumpToMonitor'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\p89v51rd2.c:425: void JumpToMonitor (void) _naked
;	-----------------------------------------
;	 function JumpToMonitor
;	-----------------------------------------
_JumpToMonitor:
;	naked function: no prologue.
;	.\p89v51rd2.c:437: _endasm;
	
	
	    cseg at 0x0000 ; Where the monitor is
	    ljmp 0xe000
	
	    cseg at 0x001B ; Timer 1 interrupt vector used for step by step execution.
	    ljmp 0xe000 + 0x0003
	
	    cseg at 0xe000 - 2
	    db 0x00, 0x00 ; Here the user PC will be saved. Default it to zero.
	    
;	naked function: no epilogue.
	rseg R_CSEG

	rseg R_CONST
_sfrn:
	db 0x80
	db 'P0'
	db 0x81
	db 'SP'
	db 0x82
	db 'DPL'
	db 0x83
	db 'DPH'
	db 0x85
	db 'WDTD'
	db 0x86
	db 'SPDR'
	db 0x86
	db 'SPDAT'
	db 0x87
	db 'PCON'
	db 0x88
	db 'TCON'
	db 0x89
	db 'TMOD'
	db 0x8A
	db 'TL0'
	db 0x8B
	db 'TL1'
	db 0x8C
	db 'TH0'
	db 0x8D
	db 'TH'
	db '1'
	db 0x8E
	db 'AUXR'
	db 0x90
	db 'P1'
	db 0x98
	db 'SCON'
	db 0x99
	db 'SBUF'
	db 0xA0
	db 'P2'
	db 0xA2
	db 'AUXR1'
	db 0xA8
	db 'IE'
	db 0xA9
	db 'SADDR'
	db 0xAA
	db 'SPSR'
	db 0xAA
	db 'SPCFG'
	db 0xB0
	db 'P3'
	db 0xB1
	db 'FCF'
	db 0xB6
	db 'FST'
	db 0xB7
	db 'IP0H'
	db 0xB8
	db 'IP'
	db 0xB9
	db 'SADEN'
	db 0xC0
	db 'WDTC'
	db 0xC8
	db 'T2CON'
	db 0xC9
	db 'T2MOD'
	db 0xCA
	db 'RCAP2L'
	db 0xCB
	db 'RCAP2H'
	db 0xCC
	db 'TL2'
	db 0xCD
	db 'TH2'
	db 0xD0
	db 'PSW'
	db 0xD5
	db 'SPC'
	db 'R'
	db 0xD5
	db 'SPCTL'
	db 0xD8
	db 'CCON'
	db 0xD9
	db 'CMOD'
	db 0xDA
	db 'CCAPM0'
	db 0xDB
	db 'CCAPM1'
	db 0xDC
	db 'CCAPM2'
	db 0xDD
	db 'CCAPM3'
	db 0xDE
	db 'CCAPM4'
	db 0xE0
	db 'ACC'
	db 0xE0
	db 'A'
	db 0xE8
	db 'I'
	db 'EN1'
	db 0xE9
	db 'CL'
	db 0xEA
	db 'CCAP0L'
	db 0xEB
	db 'CCAP1L'
	db 0xEC
	db 'CCAP2L'
	db 0xED
	db 'CCAP3L'
	db 0xEE
	db 'CCAP4L'
	db 0xF0
	db 'B'
	db 0xF7
	db 'IP1H'
	db 0xF8
	db 'IP1'
	db 0xF9
	db 'CH'
	db 0xFA
	db 'CCAP'
	db '0H'
	db 0xFB
	db 'CCAP1H'
	db 0xFC
	db 'CCAP2H'
	db 0xFD
	db 'CCAP3H'
	db 0xFE
	db 'CCAP4H'
	db 0xFF
	db 0x00
	db 0x00
_bitn:
	db 0x88
	db 'IT0'
	db 0x89
	db 'IE0'
	db 0x8A
	db 'IT1'
	db 0x8B
	db 'IE1'
	db 0x8C
	db 'TR0'
	db 0x8D
	db 'TF0'
	db 0x8E
	db 'TR1'
	db 0x8F
	db 'TF1'
	db 0x98
	db 'RI'
	db 0x99
	db 'TI'
	db 0x9A
	db 'RB8'
	db 0x9B
	db 'TB8'
	db 0x9C
	db 'REN'
	db 0x9D
	db 'SM2'
	db 0x9E
	db 'SM1'
	db 0x9F
	db 'S'
	db 'M0'
	db 0xA8
	db 'EX0'
	db 0xA9
	db 'ET0'
	db 0xAA
	db 'EX1'
	db 0xAB
	db 'ET1'
	db 0xAC
	db 'ES'
	db 0xAF
	db 'EA'
	db 0xB8
	db 'PX0'
	db 0xB9
	db 'PT0'
	db 0xBA
	db 'PX1'
	db 0xBB
	db 'PT1'
	db 0xBC
	db 'PS'
	db 0xBD
	db 'PT2'
	db 0xD0
	db 'P'
	db 0xD1
	db 'F1'
	db 0xD2
	db 'OV'
	db 0xD3
	db 'RS0'
	db 0xD4
	db 'RS1'
	db 0xD5
	db 'F0'
	db 0xD6
	db 'AC'
	db 0xD7
	db 'CY'
	db 0xC8
	db 'CP_RL2'
	db 0xC9
	db 'C_T2'
	db 0xCA
	db 'TR2'
	db 0xCB
	db 'EXEN2'
	db 0xCC
	db 'TCLK'
	db 0xCD
	db 'RCLK'
	db 0xCE
	db 'EXF2'
	db 0xCF
	db 'TF2'
	db 0xAD
	db 'ET2'
	db 0xDF
	db 'CF'
	db 0xDE
	db 'CR'
	db 0xDC
	db 'CCF4'
	db 0xDB
	db 'CCF3'
	db 0xDA
	db 'CCF2'
	db 0xD9
	db 'CCF1'
	db 0xD8
	db 'CCF0'
	db 0xAE
	db 'EC'
	db 0xEB
	db 'EBO'
	db 0xBE
	db 'PPC'
	db 0xFB
	db 'PBO'
	db 0xFF
	db 0x00
	db 0x00
__str_0:
	db 'Erasing'
	db 0x00
__str_1:
	db 0x0A
	db 'Send file or <Esc>'
	db 0x0A
	db 0x00
__str_2:
	db 0x0A
	db 'Checksum error!'
	db 0x0A
	db 0x00
__str_3:
	db 0x0A
	db 'Flash error!'
	db 0x0A
	db 0x00
__str_4:
	db 0x0A
	db 'Done.'
	db 0x0A
	db 0x00
__str_5:
	db 'WARNING: missing Timer1 jmp'
	db 0x0A
	db 0x00
__str_6:
	db 'Port: P89V51RD2 V1.1'
	db 0x0A
	db 0x00

	rseg R_XINIT

	CSEG

end
