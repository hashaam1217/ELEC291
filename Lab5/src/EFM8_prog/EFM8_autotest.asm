;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1170 (Feb 16 2022) (MSVC)
; This file was generated Thu Mar 07 02:27:10 2024
;--------------------------------------------------------
$name EFM8_autotest
$optc51 --model-small
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
	public _main
	public _Initial_Check
	public _Check_Pin_Zero
	public _Test_Pair
	public _dopass
	public _dofailb
	public _dofail
	public _Read_Pin
	public _Set_Pin_Zero
	public _Set_Pin_One
	public _Set_Pin_Input
	public _Set_Pin_Output
	public _countzero
	public _WaitXms
	public _Timer3us
	public __c51_external_startup
	public _Test_Pair_PARM_2
;--------------------------------------------------------
; Special Function Registers
;--------------------------------------------------------
_ACC            DATA 0xe0
_ADC0ASAH       DATA 0xb6
_ADC0ASAL       DATA 0xb5
_ADC0ASCF       DATA 0xa1
_ADC0ASCT       DATA 0xc7
_ADC0CF0        DATA 0xbc
_ADC0CF1        DATA 0xb9
_ADC0CF2        DATA 0xdf
_ADC0CN0        DATA 0xe8
_ADC0CN1        DATA 0xb2
_ADC0CN2        DATA 0xb3
_ADC0GTH        DATA 0xc4
_ADC0GTL        DATA 0xc3
_ADC0H          DATA 0xbe
_ADC0L          DATA 0xbd
_ADC0LTH        DATA 0xc6
_ADC0LTL        DATA 0xc5
_ADC0MX         DATA 0xbb
_B              DATA 0xf0
_CKCON0         DATA 0x8e
_CKCON1         DATA 0xa6
_CLEN0          DATA 0xc6
_CLIE0          DATA 0xc7
_CLIF0          DATA 0xe8
_CLKSEL         DATA 0xa9
_CLOUT0         DATA 0xd1
_CLU0CF         DATA 0xb1
_CLU0FN         DATA 0xaf
_CLU0MX         DATA 0x84
_CLU1CF         DATA 0xb3
_CLU1FN         DATA 0xb2
_CLU1MX         DATA 0x85
_CLU2CF         DATA 0xb6
_CLU2FN         DATA 0xb5
_CLU2MX         DATA 0x91
_CLU3CF         DATA 0xbf
_CLU3FN         DATA 0xbe
_CLU3MX         DATA 0xae
_CMP0CN0        DATA 0x9b
_CMP0CN1        DATA 0x99
_CMP0MD         DATA 0x9d
_CMP0MX         DATA 0x9f
_CMP1CN0        DATA 0xbf
_CMP1CN1        DATA 0xac
_CMP1MD         DATA 0xab
_CMP1MX         DATA 0xaa
_CRC0CN0        DATA 0xce
_CRC0CN1        DATA 0x86
_CRC0CNT        DATA 0xd3
_CRC0DAT        DATA 0xcb
_CRC0FLIP       DATA 0xcf
_CRC0IN         DATA 0xca
_CRC0ST         DATA 0xd2
_DAC0CF0        DATA 0x91
_DAC0CF1        DATA 0x92
_DAC0H          DATA 0x85
_DAC0L          DATA 0x84
_DAC1CF0        DATA 0x93
_DAC1CF1        DATA 0x94
_DAC1H          DATA 0x8a
_DAC1L          DATA 0x89
_DAC2CF0        DATA 0x95
_DAC2CF1        DATA 0x96
_DAC2H          DATA 0x8c
_DAC2L          DATA 0x8b
_DAC3CF0        DATA 0x9a
_DAC3CF1        DATA 0x9c
_DAC3H          DATA 0x8e
_DAC3L          DATA 0x8d
_DACGCF0        DATA 0x88
_DACGCF1        DATA 0x98
_DACGCF2        DATA 0xa2
_DERIVID        DATA 0xad
_DEVICEID       DATA 0xb5
_DPH            DATA 0x83
_DPL            DATA 0x82
_EIE1           DATA 0xe6
_EIE2           DATA 0xf3
_EIP1           DATA 0xbb
_EIP1H          DATA 0xee
_EIP2           DATA 0xed
_EIP2H          DATA 0xf6
_EMI0CN         DATA 0xe7
_FLKEY          DATA 0xb7
_HFO0CAL        DATA 0xc7
_HFO1CAL        DATA 0xd6
_HFOCN          DATA 0xef
_I2C0ADM        DATA 0xff
_I2C0CN0        DATA 0xba
_I2C0DIN        DATA 0xbc
_I2C0DOUT       DATA 0xbb
_I2C0FCN0       DATA 0xad
_I2C0FCN1       DATA 0xab
_I2C0FCT        DATA 0xf5
_I2C0SLAD       DATA 0xbd
_I2C0STAT       DATA 0xb9
_IE             DATA 0xa8
_IP             DATA 0xb8
_IPH            DATA 0xf2
_IT01CF         DATA 0xe4
_LFO0CN         DATA 0xb1
_P0             DATA 0x80
_P0MASK         DATA 0xfe
_P0MAT          DATA 0xfd
_P0MDIN         DATA 0xf1
_P0MDOUT        DATA 0xa4
_P0SKIP         DATA 0xd4
_P1             DATA 0x90
_P1MASK         DATA 0xee
_P1MAT          DATA 0xed
_P1MDIN         DATA 0xf2
_P1MDOUT        DATA 0xa5
_P1SKIP         DATA 0xd5
_P2             DATA 0xa0
_P2MASK         DATA 0xfc
_P2MAT          DATA 0xfb
_P2MDIN         DATA 0xf3
_P2MDOUT        DATA 0xa6
_P2SKIP         DATA 0xcc
_P3             DATA 0xb0
_P3MDIN         DATA 0xf4
_P3MDOUT        DATA 0x9c
_PCA0CENT       DATA 0x9e
_PCA0CLR        DATA 0x9c
_PCA0CN0        DATA 0xd8
_PCA0CPH0       DATA 0xfc
_PCA0CPH1       DATA 0xea
_PCA0CPH2       DATA 0xec
_PCA0CPH3       DATA 0xf5
_PCA0CPH4       DATA 0x85
_PCA0CPH5       DATA 0xde
_PCA0CPL0       DATA 0xfb
_PCA0CPL1       DATA 0xe9
_PCA0CPL2       DATA 0xeb
_PCA0CPL3       DATA 0xf4
_PCA0CPL4       DATA 0x84
_PCA0CPL5       DATA 0xdd
_PCA0CPM0       DATA 0xda
_PCA0CPM1       DATA 0xdb
_PCA0CPM2       DATA 0xdc
_PCA0CPM3       DATA 0xae
_PCA0CPM4       DATA 0xaf
_PCA0CPM5       DATA 0xcc
_PCA0H          DATA 0xfa
_PCA0L          DATA 0xf9
_PCA0MD         DATA 0xd9
_PCA0POL        DATA 0x96
_PCA0PWM        DATA 0xf7
_PCON0          DATA 0x87
_PCON1          DATA 0xcd
_PFE0CN         DATA 0xc1
_PRTDRV         DATA 0xf6
_PSCTL          DATA 0x8f
_PSTAT0         DATA 0xaa
_PSW            DATA 0xd0
_REF0CN         DATA 0xd1
_REG0CN         DATA 0xc9
_REVID          DATA 0xb6
_RSTSRC         DATA 0xef
_SBCON1         DATA 0x94
_SBRLH1         DATA 0x96
_SBRLL1         DATA 0x95
_SBUF           DATA 0x99
_SBUF0          DATA 0x99
_SBUF1          DATA 0x92
_SCON           DATA 0x98
_SCON0          DATA 0x98
_SCON1          DATA 0xc8
_SFRPAGE        DATA 0xa7
_SFRPGCN        DATA 0xbc
_SFRSTACK       DATA 0xd7
_SMB0ADM        DATA 0xd6
_SMB0ADR        DATA 0xd7
_SMB0CF         DATA 0xc1
_SMB0CN0        DATA 0xc0
_SMB0DAT        DATA 0xc2
_SMB0FCN0       DATA 0xc3
_SMB0FCN1       DATA 0xc4
_SMB0FCT        DATA 0xef
_SMB0RXLN       DATA 0xc5
_SMB0TC         DATA 0xac
_SMOD1          DATA 0x93
_SP             DATA 0x81
_SPI0CFG        DATA 0xa1
_SPI0CKR        DATA 0xa2
_SPI0CN0        DATA 0xf8
_SPI0DAT        DATA 0xa3
_SPI0FCN0       DATA 0x9a
_SPI0FCN1       DATA 0x9b
_SPI0FCT        DATA 0xf7
_SPI0PCF        DATA 0xdf
_TCON           DATA 0x88
_TH0            DATA 0x8c
_TH1            DATA 0x8d
_TL0            DATA 0x8a
_TL1            DATA 0x8b
_TMOD           DATA 0x89
_TMR2CN0        DATA 0xc8
_TMR2CN1        DATA 0xfd
_TMR2H          DATA 0xcf
_TMR2L          DATA 0xce
_TMR2RLH        DATA 0xcb
_TMR2RLL        DATA 0xca
_TMR3CN0        DATA 0x91
_TMR3CN1        DATA 0xfe
_TMR3H          DATA 0x95
_TMR3L          DATA 0x94
_TMR3RLH        DATA 0x93
_TMR3RLL        DATA 0x92
_TMR4CN0        DATA 0x98
_TMR4CN1        DATA 0xff
_TMR4H          DATA 0xa5
_TMR4L          DATA 0xa4
_TMR4RLH        DATA 0xa3
_TMR4RLL        DATA 0xa2
_TMR5CN0        DATA 0xc0
_TMR5CN1        DATA 0xf1
_TMR5H          DATA 0xd5
_TMR5L          DATA 0xd4
_TMR5RLH        DATA 0xd3
_TMR5RLL        DATA 0xd2
_UART0PCF       DATA 0xd9
_UART1FCN0      DATA 0x9d
_UART1FCN1      DATA 0xd8
_UART1FCT       DATA 0xfa
_UART1LIN       DATA 0x9e
_UART1PCF       DATA 0xda
_VDM0CN         DATA 0xff
_WDTCN          DATA 0x97
_XBR0           DATA 0xe1
_XBR1           DATA 0xe2
_XBR2           DATA 0xe3
_XOSC0CN        DATA 0x86
_DPTR           DATA 0x8382
_TMR2RL         DATA 0xcbca
_TMR3RL         DATA 0x9392
_TMR4RL         DATA 0xa3a2
_TMR5RL         DATA 0xd3d2
_TMR0           DATA 0x8c8a
_TMR1           DATA 0x8d8b
_TMR2           DATA 0xcfce
_TMR3           DATA 0x9594
_TMR4           DATA 0xa5a4
_TMR5           DATA 0xd5d4
_SBRL1          DATA 0x9695
_PCA0           DATA 0xfaf9
_PCA0CP0        DATA 0xfcfb
_PCA0CP1        DATA 0xeae9
_PCA0CP2        DATA 0xeceb
_PCA0CP3        DATA 0xf5f4
_PCA0CP4        DATA 0x8584
_PCA0CP5        DATA 0xdedd
_ADC0ASA        DATA 0xb6b5
_ADC0GT         DATA 0xc4c3
_ADC0           DATA 0xbebd
_ADC0LT         DATA 0xc6c5
_DAC0           DATA 0x8584
_DAC1           DATA 0x8a89
_DAC2           DATA 0x8c8b
_DAC3           DATA 0x8e8d
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
_ACC_0          BIT 0xe0
_ACC_1          BIT 0xe1
_ACC_2          BIT 0xe2
_ACC_3          BIT 0xe3
_ACC_4          BIT 0xe4
_ACC_5          BIT 0xe5
_ACC_6          BIT 0xe6
_ACC_7          BIT 0xe7
_TEMPE          BIT 0xe8
_ADGN0          BIT 0xe9
_ADGN1          BIT 0xea
_ADWINT         BIT 0xeb
_ADBUSY         BIT 0xec
_ADINT          BIT 0xed
_IPOEN          BIT 0xee
_ADEN           BIT 0xef
_B_0            BIT 0xf0
_B_1            BIT 0xf1
_B_2            BIT 0xf2
_B_3            BIT 0xf3
_B_4            BIT 0xf4
_B_5            BIT 0xf5
_B_6            BIT 0xf6
_B_7            BIT 0xf7
_C0FIF          BIT 0xe8
_C0RIF          BIT 0xe9
_C1FIF          BIT 0xea
_C1RIF          BIT 0xeb
_C2FIF          BIT 0xec
_C2RIF          BIT 0xed
_C3FIF          BIT 0xee
_C3RIF          BIT 0xef
_D1SRC0         BIT 0x88
_D1SRC1         BIT 0x89
_D1AMEN         BIT 0x8a
_D01REFSL       BIT 0x8b
_D3SRC0         BIT 0x8c
_D3SRC1         BIT 0x8d
_D3AMEN         BIT 0x8e
_D23REFSL       BIT 0x8f
_D0UDIS         BIT 0x98
_D1UDIS         BIT 0x99
_D2UDIS         BIT 0x9a
_D3UDIS         BIT 0x9b
_EX0            BIT 0xa8
_ET0            BIT 0xa9
_EX1            BIT 0xaa
_ET1            BIT 0xab
_ES0            BIT 0xac
_ET2            BIT 0xad
_ESPI0          BIT 0xae
_EA             BIT 0xaf
_PX0            BIT 0xb8
_PT0            BIT 0xb9
_PX1            BIT 0xba
_PT1            BIT 0xbb
_PS0            BIT 0xbc
_PT2            BIT 0xbd
_PSPI0          BIT 0xbe
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
_P3_0           BIT 0xb0
_P3_1           BIT 0xb1
_P3_2           BIT 0xb2
_P3_3           BIT 0xb3
_P3_4           BIT 0xb4
_P3_7           BIT 0xb7
_CCF0           BIT 0xd8
_CCF1           BIT 0xd9
_CCF2           BIT 0xda
_CCF3           BIT 0xdb
_CCF4           BIT 0xdc
_CCF5           BIT 0xdd
_CR             BIT 0xde
_CF             BIT 0xdf
_PARITY         BIT 0xd0
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
_CE             BIT 0x9d
_SMODE          BIT 0x9e
_RI1            BIT 0xc8
_TI1            BIT 0xc9
_RBX1           BIT 0xca
_TBX1           BIT 0xcb
_REN1           BIT 0xcc
_PERR1          BIT 0xcd
_OVR1           BIT 0xce
_SI             BIT 0xc0
_ACK            BIT 0xc1
_ARBLOST        BIT 0xc2
_ACKRQ          BIT 0xc3
_STO            BIT 0xc4
_STA            BIT 0xc5
_TXMODE         BIT 0xc6
_MASTER         BIT 0xc7
_SPIEN          BIT 0xf8
_TXNF           BIT 0xf9
_NSSMD0         BIT 0xfa
_NSSMD1         BIT 0xfb
_RXOVRN         BIT 0xfc
_MODF           BIT 0xfd
_WCOL           BIT 0xfe
_SPIF           BIT 0xff
_IT0            BIT 0x88
_IE0            BIT 0x89
_IT1            BIT 0x8a
_IE1            BIT 0x8b
_TR0            BIT 0x8c
_TF0            BIT 0x8d
_TR1            BIT 0x8e
_TF1            BIT 0x8f
_T2XCLK0        BIT 0xc8
_T2XCLK1        BIT 0xc9
_TR2            BIT 0xca
_T2SPLIT        BIT 0xcb
_TF2CEN         BIT 0xcc
_TF2LEN         BIT 0xcd
_TF2L           BIT 0xce
_TF2H           BIT 0xcf
_T4XCLK0        BIT 0x98
_T4XCLK1        BIT 0x99
_TR4            BIT 0x9a
_T4SPLIT        BIT 0x9b
_TF4CEN         BIT 0x9c
_TF4LEN         BIT 0x9d
_TF4L           BIT 0x9e
_TF4H           BIT 0x9f
_T5XCLK0        BIT 0xc0
_T5XCLK1        BIT 0xc1
_TR5            BIT 0xc2
_T5SPLIT        BIT 0xc3
_TF5CEN         BIT 0xc4
_TF5LEN         BIT 0xc5
_TF5L           BIT 0xc6
_TF5H           BIT 0xc7
_RIE            BIT 0xd8
_RXTO0          BIT 0xd9
_RXTO1          BIT 0xda
_RFRQ           BIT 0xdb
_TIE            BIT 0xdc
_TXHOLD         BIT 0xdd
_TXNF1          BIT 0xde
_TFRQ           BIT 0xdf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	rbank0 segment data overlay
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	rseg R_DSEG
_Test_Pair_PARM_2:
	ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	rseg	R_OSEG
	rseg	R_OSEG
	rseg	R_OSEG
	rseg	R_OSEG
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
	rseg R_PSEG
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
;Allocation info for local variables in function '_c51_external_startup'
;------------------------------------------------------------
;------------------------------------------------------------
;	EFM8_autotest.c:27: char _c51_external_startup (void)
;	-----------------------------------------
;	 function _c51_external_startup
;	-----------------------------------------
__c51_external_startup:
	using	0
;	EFM8_autotest.c:30: SFRPAGE = 0x00;
	mov	_SFRPAGE,#0x00
;	EFM8_autotest.c:31: WDTCN = 0xDE; //First key
	mov	_WDTCN,#0xDE
;	EFM8_autotest.c:32: WDTCN = 0xAD; //Second key
	mov	_WDTCN,#0xAD
;	EFM8_autotest.c:35: SFRPAGE = 0x10;
	mov	_SFRPAGE,#0x10
;	EFM8_autotest.c:36: PFE0CN  = 0x10; // SYSCLK < 50 MHz.
	mov	_PFE0CN,#0x10
;	EFM8_autotest.c:37: SFRPAGE = 0x00;
	mov	_SFRPAGE,#0x00
;	EFM8_autotest.c:54: CLKSEL = 0x00;
	mov	_CLKSEL,#0x00
;	EFM8_autotest.c:55: CLKSEL = 0x00;
	mov	_CLKSEL,#0x00
;	EFM8_autotest.c:56: while ((CLKSEL & 0x80) == 0);
L002001?:
	mov	a,_CLKSEL
	jnb	acc.7,L002001?
;	EFM8_autotest.c:57: CLKSEL = 0x07;
	mov	_CLKSEL,#0x07
;	EFM8_autotest.c:58: CLKSEL = 0x07;
	mov	_CLKSEL,#0x07
;	EFM8_autotest.c:59: while ((CLKSEL & 0x80) == 0);
L002004?:
	mov	a,_CLKSEL
	jnb	acc.7,L002004?
;	EFM8_autotest.c:72: P0MDOUT |= 0x10; // Enable UART0 TX as push-pull output
	orl	_P0MDOUT,#0x10
;	EFM8_autotest.c:73: XBR0     = 0x01; // Enable UART0 on P0.4(TX) and P0.5(RX)                     
	mov	_XBR0,#0x01
;	EFM8_autotest.c:74: XBR1     = 0X00;
	mov	_XBR1,#0x00
;	EFM8_autotest.c:75: XBR2     = 0x40; // Enable crossbar and weak pull-ups
	mov	_XBR2,#0x40
;	EFM8_autotest.c:81: SCON0 = 0x10;
	mov	_SCON0,#0x10
;	EFM8_autotest.c:82: CKCON0 |= 0b_0000_1000 ; // Timer 1 uses the system clock.
	orl	_CKCON0,#0x08
;	EFM8_autotest.c:83: TH1 = 0x100-((SYSCLK/BAUDRATE)/2L);
	mov	_TH1,#0x30
;	EFM8_autotest.c:84: TL1 = TH1;      // Init Timer1
	mov	_TL1,_TH1
;	EFM8_autotest.c:85: TMOD &= ~0xf0;  // TMOD: timer 1 in 8-bit auto-reload
	anl	_TMOD,#0x0F
;	EFM8_autotest.c:86: TMOD |=  0x20;                       
	orl	_TMOD,#0x20
;	EFM8_autotest.c:87: TR1 = 1; // START Timer1
	setb	_TR1
;	EFM8_autotest.c:88: TI = 1;  // Indicate TX0 ready
	setb	_TI
;	EFM8_autotest.c:90: return 0;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Timer3us'
;------------------------------------------------------------
;us                        Allocated to registers r2 
;i                         Allocated to registers r3 
;------------------------------------------------------------
;	EFM8_autotest.c:95: void Timer3us(unsigned char us)
;	-----------------------------------------
;	 function Timer3us
;	-----------------------------------------
_Timer3us:
	mov	r2,dpl
;	EFM8_autotest.c:100: CKCON0|=0b_0100_0000;
	orl	_CKCON0,#0x40
;	EFM8_autotest.c:102: TMR3RL = (-(SYSCLK)/1000000L); // Set Timer3 to overflow in 1us.
	mov	_TMR3RL,#0xD0
	mov	(_TMR3RL >> 8),#0xFF
;	EFM8_autotest.c:103: TMR3 = TMR3RL;                 // Initialize Timer3 for first overflow
	mov	_TMR3,_TMR3RL
	mov	(_TMR3 >> 8),(_TMR3RL >> 8)
;	EFM8_autotest.c:105: TMR3CN0 = 0x04;                 // Sart Timer3 and clear overflow flag
	mov	_TMR3CN0,#0x04
;	EFM8_autotest.c:106: for (i = 0; i < us; i++)       // Count <us> overflows
	mov	r3,#0x00
L003004?:
	clr	c
	mov	a,r3
	subb	a,r2
	jnc	L003007?
;	EFM8_autotest.c:108: while (!(TMR3CN0 & 0x80));  // Wait for overflow
L003001?:
	mov	a,_TMR3CN0
	jnb	acc.7,L003001?
;	EFM8_autotest.c:109: TMR3CN0 &= ~(0x80);         // Clear overflow indicator
	anl	_TMR3CN0,#0x7F
;	EFM8_autotest.c:106: for (i = 0; i < us; i++)       // Count <us> overflows
	inc	r3
	sjmp	L003004?
L003007?:
;	EFM8_autotest.c:111: TMR3CN0 = 0 ;                   // Stop Timer3 and clear overflow flag
	mov	_TMR3CN0,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'WaitXms'
;------------------------------------------------------------
;ms                        Allocated to registers r2 r3 
;j                         Allocated to registers r2 r3 
;------------------------------------------------------------
;	EFM8_autotest.c:114: void WaitXms (unsigned int ms)
;	-----------------------------------------
;	 function WaitXms
;	-----------------------------------------
_WaitXms:
	mov	r2,dpl
	mov	r3,dph
;	EFM8_autotest.c:117: for(j=ms; j!=0; j--)
L004001?:
	cjne	r2,#0x00,L004010?
	cjne	r3,#0x00,L004010?
	ret
L004010?:
;	EFM8_autotest.c:119: Timer3us(249);
	mov	dpl,#0xF9
	push	ar2
	push	ar3
	lcall	_Timer3us
;	EFM8_autotest.c:120: Timer3us(249);
	mov	dpl,#0xF9
	lcall	_Timer3us
;	EFM8_autotest.c:121: Timer3us(249);
	mov	dpl,#0xF9
	lcall	_Timer3us
;	EFM8_autotest.c:122: Timer3us(250);
	mov	dpl,#0xFA
	lcall	_Timer3us
	pop	ar3
	pop	ar2
;	EFM8_autotest.c:117: for(j=ms; j!=0; j--)
	dec	r2
	cjne	r2,#0xff,L004011?
	dec	r3
L004011?:
	sjmp	L004001?
;------------------------------------------------------------
;Allocation info for local variables in function 'countzero'
;------------------------------------------------------------
;j                         Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:126: unsigned char countzero(void)
;	-----------------------------------------
;	 function countzero
;	-----------------------------------------
_countzero:
;	EFM8_autotest.c:130: j=0;
	mov	r2,#0x00
;	EFM8_autotest.c:132: if (P0_0==0) j++;
	jb	_P0_0,L005002?
	mov	r2,#0x01
L005002?:
;	EFM8_autotest.c:133: if (P0_1==0) j++;
	jb	_P0_1,L005004?
	inc	r2
L005004?:
;	EFM8_autotest.c:134: if (P0_2==0) j++;
	jb	_P0_2,L005006?
	inc	r2
L005006?:
;	EFM8_autotest.c:135: if (P0_3==0) j++;
	jb	_P0_3,L005008?
	inc	r2
L005008?:
;	EFM8_autotest.c:138: if (P0_6==0) j++;
	jb	_P0_6,L005010?
	inc	r2
L005010?:
;	EFM8_autotest.c:139: if (P0_7==0) j++;
	jb	_P0_7,L005012?
	inc	r2
L005012?:
;	EFM8_autotest.c:141: if (P1_0==0) j++;
	jb	_P1_0,L005014?
	inc	r2
L005014?:
;	EFM8_autotest.c:142: if (P1_1==0) j++;
	jb	_P1_1,L005016?
	inc	r2
L005016?:
;	EFM8_autotest.c:143: if (P1_2==0) j++;
	jb	_P1_2,L005018?
	inc	r2
L005018?:
;	EFM8_autotest.c:144: if (P1_3==0) j++;
	jb	_P1_3,L005020?
	inc	r2
L005020?:
;	EFM8_autotest.c:145: if (P1_4==0) j++;
	jb	_P1_4,L005022?
	inc	r2
L005022?:
;	EFM8_autotest.c:146: if (P1_5==0) j++;
	jb	_P1_5,L005024?
	inc	r2
L005024?:
;	EFM8_autotest.c:147: if (P1_6==0) j++;
	jb	_P1_6,L005026?
	inc	r2
L005026?:
;	EFM8_autotest.c:148: if (P1_7==0) j++;
	jb	_P1_7,L005028?
	inc	r2
L005028?:
;	EFM8_autotest.c:150: if (P2_0==0) j++;
	jb	_P2_0,L005030?
	inc	r2
L005030?:
;	EFM8_autotest.c:151: if (P2_1==0) j++;
	jb	_P2_1,L005032?
	inc	r2
L005032?:
;	EFM8_autotest.c:152: if (P2_2==0) j++;
	jb	_P2_2,L005034?
	inc	r2
L005034?:
;	EFM8_autotest.c:153: if (P2_3==0) j++;
	jb	_P2_3,L005036?
	inc	r2
L005036?:
;	EFM8_autotest.c:154: if (P2_4==0) j++;
	jb	_P2_4,L005038?
	inc	r2
L005038?:
;	EFM8_autotest.c:155: if (P2_5==0) j++;
	jb	_P2_5,L005040?
	inc	r2
L005040?:
;	EFM8_autotest.c:156: if (P2_6==0) j++;
	jb	_P2_6,L005042?
	inc	r2
L005042?:
;	EFM8_autotest.c:158: if (P3_0==0) j++;
	jb	_P3_0,L005044?
	inc	r2
L005044?:
;	EFM8_autotest.c:159: if (P3_1==0) j++;
	jb	_P3_1,L005046?
	inc	r2
L005046?:
;	EFM8_autotest.c:160: if (P3_2==0) j++;
	jb	_P3_2,L005048?
	inc	r2
L005048?:
;	EFM8_autotest.c:161: if (P3_3==0) j++;
	jb	_P3_3,L005050?
	inc	r2
L005050?:
;	EFM8_autotest.c:162: if (P3_7==0) j++;
	jb	_P3_7,L005052?
	inc	r2
L005052?:
;	EFM8_autotest.c:164: return j;
	mov	dpl,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Set_Pin_Output'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;mask                      Allocated to registers r3 
;------------------------------------------------------------
;	EFM8_autotest.c:167: void Set_Pin_Output (unsigned char pin)
;	-----------------------------------------
;	 function Set_Pin_Output
;	-----------------------------------------
_Set_Pin_Output:
	mov	r2,dpl
;	EFM8_autotest.c:171: mask=(1<<(pin&0x7));
	mov	a,#0x07
	anl	a,r2
	mov	b,a
	inc	b
	mov	a,#0x01
	sjmp	L006011?
L006009?:
	add	a,acc
L006011?:
	djnz	b,L006009?
	mov	r3,a
;	EFM8_autotest.c:172: switch(pin/0x10)
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov  r2,a
	add	a,#0xff - 0x03
	jc	L006006?
	mov	a,r2
	add	a,r2
	add	a,r2
	mov	dptr,#L006013?
	jmp	@a+dptr
L006013?:
	ljmp	L006001?
	ljmp	L006002?
	ljmp	L006003?
	ljmp	L006004?
;	EFM8_autotest.c:174: case 0: P0MDOUT |= mask; break;
L006001?:
	mov	a,r3
	orl	_P0MDOUT,a
;	EFM8_autotest.c:175: case 1: P1MDOUT |= mask; break;
	ret
L006002?:
	mov	a,r3
	orl	_P1MDOUT,a
;	EFM8_autotest.c:176: case 2: P2MDOUT |= mask; break; 
	ret
L006003?:
	mov	a,r3
	orl	_P2MDOUT,a
;	EFM8_autotest.c:177: case 3: P3MDOUT |= mask; break; 
	ret
L006004?:
	mov	a,r3
	orl	_P3MDOUT,a
;	EFM8_autotest.c:178: }	
L006006?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Set_Pin_Input'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;mask                      Allocated to registers r3 
;------------------------------------------------------------
;	EFM8_autotest.c:181: void Set_Pin_Input (unsigned char pin)
;	-----------------------------------------
;	 function Set_Pin_Input
;	-----------------------------------------
_Set_Pin_Input:
	mov	r2,dpl
;	EFM8_autotest.c:185: mask=(1<<(pin&0x7));
	mov	a,#0x07
	anl	a,r2
	mov	b,a
	inc	b
	mov	a,#0x01
	sjmp	L007011?
L007009?:
	add	a,acc
L007011?:
	djnz	b,L007009?
;	EFM8_autotest.c:186: mask=~mask;
	cpl	a
	mov	r3,a
;	EFM8_autotest.c:187: switch(pin/0x10)
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov  r2,a
	add	a,#0xff - 0x03
	jc	L007006?
	mov	a,r2
	add	a,r2
	add	a,r2
	mov	dptr,#L007013?
	jmp	@a+dptr
L007013?:
	ljmp	L007001?
	ljmp	L007002?
	ljmp	L007003?
	ljmp	L007004?
;	EFM8_autotest.c:189: case 0: P0MDOUT &= mask; break;
L007001?:
	mov	a,r3
	anl	_P0MDOUT,a
;	EFM8_autotest.c:190: case 1: P1MDOUT &= mask; break;
	ret
L007002?:
	mov	a,r3
	anl	_P1MDOUT,a
;	EFM8_autotest.c:191: case 2: P2MDOUT &= mask; break; 
	ret
L007003?:
	mov	a,r3
	anl	_P2MDOUT,a
;	EFM8_autotest.c:192: case 3: P3MDOUT &= mask; break; 
	ret
L007004?:
	mov	a,r3
	anl	_P3MDOUT,a
;	EFM8_autotest.c:193: }	
L007006?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Set_Pin_One'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;mask                      Allocated to registers r3 
;------------------------------------------------------------
;	EFM8_autotest.c:196: void Set_Pin_One (unsigned char pin)
;	-----------------------------------------
;	 function Set_Pin_One
;	-----------------------------------------
_Set_Pin_One:
	mov	r2,dpl
;	EFM8_autotest.c:200: mask=(1<<(pin&0x7));
	mov	a,#0x07
	anl	a,r2
	mov	b,a
	inc	b
	mov	a,#0x01
	sjmp	L008011?
L008009?:
	add	a,acc
L008011?:
	djnz	b,L008009?
	mov	r3,a
;	EFM8_autotest.c:201: switch(pin/0x10)
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov  r2,a
	add	a,#0xff - 0x03
	jc	L008006?
	mov	a,r2
	add	a,r2
	add	a,r2
	mov	dptr,#L008013?
	jmp	@a+dptr
L008013?:
	ljmp	L008001?
	ljmp	L008002?
	ljmp	L008003?
	ljmp	L008004?
;	EFM8_autotest.c:203: case 0: P0 |= mask; break;
L008001?:
	mov	a,r3
	orl	_P0,a
;	EFM8_autotest.c:204: case 1: P1 |= mask; break;
	ret
L008002?:
	mov	a,r3
	orl	_P1,a
;	EFM8_autotest.c:205: case 2: P2 |= mask; break; 
	ret
L008003?:
	mov	a,r3
	orl	_P2,a
;	EFM8_autotest.c:206: case 3: P3 |= mask; break; 
	ret
L008004?:
	mov	a,r3
	orl	_P3,a
;	EFM8_autotest.c:207: }	
L008006?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Set_Pin_Zero'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;mask                      Allocated to registers r3 
;------------------------------------------------------------
;	EFM8_autotest.c:210: void Set_Pin_Zero (unsigned char pin)
;	-----------------------------------------
;	 function Set_Pin_Zero
;	-----------------------------------------
_Set_Pin_Zero:
	mov	r2,dpl
;	EFM8_autotest.c:214: mask=(1<<(pin&0x7));
	mov	a,#0x07
	anl	a,r2
	mov	b,a
	inc	b
	mov	a,#0x01
	sjmp	L009011?
L009009?:
	add	a,acc
L009011?:
	djnz	b,L009009?
;	EFM8_autotest.c:215: mask=~mask;
	cpl	a
	mov	r3,a
;	EFM8_autotest.c:216: switch(pin/0x10)
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov  r2,a
	add	a,#0xff - 0x03
	jc	L009006?
	mov	a,r2
	add	a,r2
	add	a,r2
	mov	dptr,#L009013?
	jmp	@a+dptr
L009013?:
	ljmp	L009001?
	ljmp	L009002?
	ljmp	L009003?
	ljmp	L009004?
;	EFM8_autotest.c:218: case 0: P0 &= mask; break;
L009001?:
	mov	a,r3
	anl	_P0,a
;	EFM8_autotest.c:219: case 1: P1 &= mask; break;
	ret
L009002?:
	mov	a,r3
	anl	_P1,a
;	EFM8_autotest.c:220: case 2: P2 &= mask; break; 
	ret
L009003?:
	mov	a,r3
	anl	_P2,a
;	EFM8_autotest.c:221: case 3: P3 &= mask; break; 
	ret
L009004?:
	mov	a,r3
	anl	_P3,a
;	EFM8_autotest.c:222: }	
L009006?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Read_Pin'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;mask                      Allocated to registers r3 
;result                    Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:225: bit Read_Pin (unsigned char pin)
;	-----------------------------------------
;	 function Read_Pin
;	-----------------------------------------
_Read_Pin:
	mov	r2,dpl
;	EFM8_autotest.c:229: mask=(1<<(pin&0x7));
	mov	a,#0x07
	anl	a,r2
	mov	b,a
	inc	b
	mov	a,#0x01
	sjmp	L010012?
L010010?:
	add	a,acc
L010012?:
	djnz	b,L010010?
	mov	r3,a
;	EFM8_autotest.c:230: switch(pin/0x10)
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov  r2,a
	add	a,#0xff - 0x03
	jc	L010002?
	mov	a,r2
	add	a,r2
	add	a,r2
	mov	dptr,#L010014?
	jmp	@a+dptr
L010014?:
	ljmp	L010002?
	ljmp	L010003?
	ljmp	L010004?
	ljmp	L010005?
;	EFM8_autotest.c:233: case 0: result = P0 & mask; break;
L010002?:
	mov	a,r3
	anl	a,_P0
	mov	r2,a
;	EFM8_autotest.c:234: case 1: result = P1 & mask; break;
	sjmp	L010006?
L010003?:
	mov	a,r3
	anl	a,_P1
	mov	r2,a
;	EFM8_autotest.c:235: case 2: result = P2 & mask; break; 
	sjmp	L010006?
L010004?:
	mov	a,r3
	anl	a,_P2
	mov	r2,a
;	EFM8_autotest.c:236: case 3: result = P3 & mask; break; 
	sjmp	L010006?
L010005?:
	mov	a,r3
	anl	a,_P3
	mov	r2,a
;	EFM8_autotest.c:237: }
L010006?:
;	EFM8_autotest.c:238: return (result?1:0);
	mov	a,r2
	add	a,#0xff
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dofail'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:241: void dofail(unsigned char pin)
;	-----------------------------------------
;	 function dofail
;	-----------------------------------------
_dofail:
	mov	r2,dpl
;	EFM8_autotest.c:243: printf("P%d.%d FAILED (OPEN)\n", pin/0x10, pin&7);
	mov	a,#0x07
	anl	a,r2
	mov	r3,a
	mov	r4,#0x00
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov	r2,a
	mov	r5,#0x00
	push	ar3
	push	ar4
	push	ar2
	push	ar5
	mov	a,#__str_0
	push	acc
	mov	a,#(__str_0 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	EFM8_autotest.c:244: while(1);
L011002?:
	sjmp	L011002?
;------------------------------------------------------------
;Allocation info for local variables in function 'dofailb'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:247: void dofailb(unsigned char pin)
;	-----------------------------------------
;	 function dofailb
;	-----------------------------------------
_dofailb:
	mov	r2,dpl
;	EFM8_autotest.c:249: printf("P%d.%d FAILED (SHORT)\n", pin/0x10, pin&7);
	mov	a,#0x07
	anl	a,r2
	mov	r3,a
	mov	r4,#0x00
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov	r2,a
	mov	r5,#0x00
	push	ar3
	push	ar4
	push	ar2
	push	ar5
	mov	a,#__str_1
	push	acc
	mov	a,#(__str_1 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	EFM8_autotest.c:250: while(1);
L012002?:
	sjmp	L012002?
;------------------------------------------------------------
;Allocation info for local variables in function 'dopass'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:253: void dopass(unsigned char pin)
;	-----------------------------------------
;	 function dopass
;	-----------------------------------------
_dopass:
	mov	r2,dpl
;	EFM8_autotest.c:255: printf("P%d.%d, ", pin/0x10, pin&7);
	mov	a,#0x07
	anl	a,r2
	mov	r3,a
	mov	r4,#0x00
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov	r2,a
	mov	r5,#0x00
	push	ar3
	push	ar4
	push	ar2
	push	ar5
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Test_Pair'
;------------------------------------------------------------
;pin2                      Allocated with name '_Test_Pair_PARM_2'
;pin1                      Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:258: void Test_Pair (unsigned char pin1, unsigned char pin2)
;	-----------------------------------------
;	 function Test_Pair
;	-----------------------------------------
_Test_Pair:
;	EFM8_autotest.c:260: Set_Pin_Output(pin1);
	mov  r2,dpl
	push	ar2
	lcall	_Set_Pin_Output
;	EFM8_autotest.c:261: Set_Pin_Input(pin2);
	mov	dpl,_Test_Pair_PARM_2
	lcall	_Set_Pin_Input
	pop	ar2
;	EFM8_autotest.c:262: Set_Pin_Zero(pin1);
	mov	dpl,r2
	push	ar2
	lcall	_Set_Pin_Zero
;	EFM8_autotest.c:263: WaitXms(2);
	mov	dptr,#0x0002
	lcall	_WaitXms
;	EFM8_autotest.c:264: if(Read_Pin(pin2)==1) dofail(pin2);
	mov	dpl,_Test_Pair_PARM_2
	lcall	_Read_Pin
	clr	a
	rlc	a
	mov	r3,a
	pop	ar2
	cjne	r3,#0x01,L014002?
	mov	dpl,_Test_Pair_PARM_2
	push	ar2
	lcall	_dofail
	pop	ar2
L014002?:
;	EFM8_autotest.c:265: if (countzero()!=2) dofailb(pin2);
	push	ar2
	lcall	_countzero
	mov	r3,dpl
	pop	ar2
	cjne	r3,#0x02,L014017?
	sjmp	L014004?
L014017?:
	mov	dpl,_Test_Pair_PARM_2
	push	ar2
	lcall	_dofailb
	pop	ar2
L014004?:
;	EFM8_autotest.c:266: dopass(pin2);
	mov	dpl,_Test_Pair_PARM_2
	push	ar2
	lcall	_dopass
;	EFM8_autotest.c:268: Set_Pin_Output(pin2);
	mov	dpl,_Test_Pair_PARM_2
	lcall	_Set_Pin_Output
	pop	ar2
;	EFM8_autotest.c:269: Set_Pin_Input(pin1);
	mov	dpl,r2
	push	ar2
	lcall	_Set_Pin_Input
;	EFM8_autotest.c:270: Set_Pin_Zero(pin2);
	mov	dpl,_Test_Pair_PARM_2
	lcall	_Set_Pin_Zero
;	EFM8_autotest.c:271: WaitXms(2);
	mov	dptr,#0x0002
	lcall	_WaitXms
	pop	ar2
;	EFM8_autotest.c:272: if(Read_Pin(pin1)==1) dofail(pin1);
	mov	dpl,r2
	push	ar2
	lcall	_Read_Pin
	clr	a
	rlc	a
	mov	r3,a
	pop	ar2
	cjne	r3,#0x01,L014006?
	mov	dpl,r2
	push	ar2
	lcall	_dofail
	pop	ar2
L014006?:
;	EFM8_autotest.c:273: if (countzero()!=2) dofailb(pin1);
	push	ar2
	lcall	_countzero
	mov	r3,dpl
	pop	ar2
	cjne	r3,#0x02,L014020?
	sjmp	L014008?
L014020?:
	mov	dpl,r2
	push	ar2
	lcall	_dofailb
	pop	ar2
L014008?:
;	EFM8_autotest.c:274: dopass(pin1);
	mov	dpl,r2
	push	ar2
	lcall	_dopass
	pop	ar2
;	EFM8_autotest.c:276: Set_Pin_One(pin1);
	mov	dpl,r2
	push	ar2
	lcall	_Set_Pin_One
;	EFM8_autotest.c:277: Set_Pin_One(pin2);
	mov	dpl,_Test_Pair_PARM_2
	lcall	_Set_Pin_One
	pop	ar2
;	EFM8_autotest.c:278: Set_Pin_Input(pin1);
	mov	dpl,r2
	lcall	_Set_Pin_Input
;	EFM8_autotest.c:279: Set_Pin_Input(pin2);
	mov	dpl,_Test_Pair_PARM_2
	ljmp	_Set_Pin_Input
;------------------------------------------------------------
;Allocation info for local variables in function 'Check_Pin_Zero'
;------------------------------------------------------------
;pin                       Allocated to registers r2 
;------------------------------------------------------------
;	EFM8_autotest.c:282: void Check_Pin_Zero (unsigned char pin)
;	-----------------------------------------
;	 function Check_Pin_Zero
;	-----------------------------------------
_Check_Pin_Zero:
;	EFM8_autotest.c:284: if(Read_Pin(pin)==0)
	mov  r2,dpl
	push	ar2
	lcall	_Read_Pin
	pop	ar2
	jc	L015003?
;	EFM8_autotest.c:286: printf("P%d.%d is connected to ground\n", pin/0x10, pin&7);
	mov	a,#0x07
	anl	a,r2
	mov	r3,a
	mov	r4,#0x00
	mov	a,r2
	swap	a
	anl	a,#0x0f
	mov	r2,a
	mov	r5,#0x00
	push	ar3
	push	ar4
	push	ar2
	push	ar5
	mov	a,#__str_3
	push	acc
	mov	a,#(__str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
L015003?:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Initial_Check'
;------------------------------------------------------------
;------------------------------------------------------------
;	EFM8_autotest.c:290: void Initial_Check (void)
;	-----------------------------------------
;	 function Initial_Check
;	-----------------------------------------
_Initial_Check:
;	EFM8_autotest.c:292: if (countzero()!=0)
	lcall	_countzero
	mov	a,dpl
	jnz	L016010?
	ret
L016010?:
;	EFM8_autotest.c:294: Check_Pin_Zero(0x00);
	mov	dpl,#0x00
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:295: Check_Pin_Zero(0x01);
	mov	dpl,#0x01
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:296: Check_Pin_Zero(0x02);
	mov	dpl,#0x02
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:297: Check_Pin_Zero(0x03);
	mov	dpl,#0x03
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:300: Check_Pin_Zero(0x06);
	mov	dpl,#0x06
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:301: Check_Pin_Zero(0x07);
	mov	dpl,#0x07
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:302: Check_Pin_Zero(0x10);
	mov	dpl,#0x10
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:303: Check_Pin_Zero(0x11);
	mov	dpl,#0x11
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:304: Check_Pin_Zero(0x12);
	mov	dpl,#0x12
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:305: Check_Pin_Zero(0x13);
	mov	dpl,#0x13
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:306: Check_Pin_Zero(0x14);
	mov	dpl,#0x14
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:307: Check_Pin_Zero(0x15);
	mov	dpl,#0x15
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:308: Check_Pin_Zero(0x16);
	mov	dpl,#0x16
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:309: Check_Pin_Zero(0x17);
	mov	dpl,#0x17
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:310: Check_Pin_Zero(0x20);
	mov	dpl,#0x20
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:311: Check_Pin_Zero(0x21);
	mov	dpl,#0x21
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:312: Check_Pin_Zero(0x22);
	mov	dpl,#0x22
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:313: Check_Pin_Zero(0x23);
	mov	dpl,#0x23
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:314: Check_Pin_Zero(0x24);
	mov	dpl,#0x24
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:315: Check_Pin_Zero(0x25);
	mov	dpl,#0x25
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:316: Check_Pin_Zero(0x26);
	mov	dpl,#0x26
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:317: Check_Pin_Zero(0x30);
	mov	dpl,#0x30
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:318: Check_Pin_Zero(0x31);
	mov	dpl,#0x31
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:319: Check_Pin_Zero(0x32);
	mov	dpl,#0x32
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:320: Check_Pin_Zero(0x33);
	mov	dpl,#0x33
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:321: Check_Pin_Zero(0x37);
	mov	dpl,#0x37
	lcall	_Check_Pin_Zero
;	EFM8_autotest.c:322: while(1);
L016002?:
	sjmp	L016002?
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	EFM8_autotest.c:326: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	EFM8_autotest.c:330: WaitXms(TOUT); // Give PuTTY a chance to start
	mov	dptr,#0x01F4
	lcall	_WaitXms
;	EFM8_autotest.c:332: printf("\n\nEFM8 board autotest\n");
	mov	a,#__str_4
	push	acc
	mov	a,#(__str_4 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	EFM8_autotest.c:333: Initial_Check();
	lcall	_Initial_Check
;	EFM8_autotest.c:335: Test_Pair(0x00, 0x01); // P0.0 and P0.1
	mov	_Test_Pair_PARM_2,#0x01
	mov	dpl,#0x00
	lcall	_Test_Pair
;	EFM8_autotest.c:336: Test_Pair(0x02, 0x03); // P0.2 and P0.3
	mov	_Test_Pair_PARM_2,#0x03
	mov	dpl,#0x02
	lcall	_Test_Pair
;	EFM8_autotest.c:337: Test_Pair(0x37, 0x06); // P3.7 and P0.6
	mov	_Test_Pair_PARM_2,#0x06
	mov	dpl,#0x37
	lcall	_Test_Pair
;	EFM8_autotest.c:338: Test_Pair(0x33, 0x07); // etc.
	mov	_Test_Pair_PARM_2,#0x07
	mov	dpl,#0x33
	lcall	_Test_Pair
;	EFM8_autotest.c:339: printf("\n");
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
;	EFM8_autotest.c:340: Test_Pair(0x32, 0x10);
	mov	_Test_Pair_PARM_2,#0x10
	mov	dpl,#0x32
	lcall	_Test_Pair
;	EFM8_autotest.c:341: Test_Pair(0x31, 0x11);
	mov	_Test_Pair_PARM_2,#0x11
	mov	dpl,#0x31
	lcall	_Test_Pair
;	EFM8_autotest.c:342: Test_Pair(0x30, 0x12);
	mov	_Test_Pair_PARM_2,#0x12
	mov	dpl,#0x30
	lcall	_Test_Pair
;	EFM8_autotest.c:343: Test_Pair(0x26, 0x13);
	mov	_Test_Pair_PARM_2,#0x13
	mov	dpl,#0x26
	lcall	_Test_Pair
;	EFM8_autotest.c:344: printf("\n");
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
;	EFM8_autotest.c:345: Test_Pair(0x25, 0x14);
	mov	_Test_Pair_PARM_2,#0x14
	mov	dpl,#0x25
	lcall	_Test_Pair
;	EFM8_autotest.c:346: Test_Pair(0x24, 0x15);
	mov	_Test_Pair_PARM_2,#0x15
	mov	dpl,#0x24
	lcall	_Test_Pair
;	EFM8_autotest.c:347: Test_Pair(0x23, 0x16);
	mov	_Test_Pair_PARM_2,#0x16
	mov	dpl,#0x23
	lcall	_Test_Pair
;	EFM8_autotest.c:348: Test_Pair(0x22, 0x17);
	mov	_Test_Pair_PARM_2,#0x17
	mov	dpl,#0x22
	lcall	_Test_Pair
;	EFM8_autotest.c:349: printf("\n");
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
;	EFM8_autotest.c:350: Test_Pair(0x21, 0x20);
	mov	_Test_Pair_PARM_2,#0x20
	mov	dpl,#0x21
	lcall	_Test_Pair
;	EFM8_autotest.c:352: printf("\n\nSuccess!\n");
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
;	EFM8_autotest.c:354: Set_Pin_Output(0x21);
	mov	dpl,#0x21
	lcall	_Set_Pin_Output
;	EFM8_autotest.c:355: while(1)
L017002?:
;	EFM8_autotest.c:357: P2_1=0;
	clr	_P2_1
;	EFM8_autotest.c:358: WaitXms(TOUT);
	mov	dptr,#0x01F4
	lcall	_WaitXms
;	EFM8_autotest.c:359: P2_1=1;
	setb	_P2_1
;	EFM8_autotest.c:360: WaitXms(TOUT);
	mov	dptr,#0x01F4
	lcall	_WaitXms
	sjmp	L017002?
	rseg R_CSEG

	rseg R_XINIT

	rseg R_CONST
__str_0:
	db 'P%d.%d FAILED (OPEN)'
	db 0x0A
	db 0x00
__str_1:
	db 'P%d.%d FAILED (SHORT)'
	db 0x0A
	db 0x00
__str_2:
	db 'P%d.%d, '
	db 0x00
__str_3:
	db 'P%d.%d is connected to ground'
	db 0x0A
	db 0x00
__str_4:
	db 0x0A
	db 0x0A
	db 'EFM8 board autotest'
	db 0x0A
	db 0x00
__str_5:
	db 0x0A
	db 0x00
__str_6:
	db 0x0A
	db 0x0A
	db 'Success!'
	db 0x0A
	db 0x00

	CSEG

end
