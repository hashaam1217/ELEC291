;--------------------------------------------------------
; File Created by C51
; Version 1.0.0 #1069 (Dec 11 2012) (MSVC)
; This file was generated Mon Jan 07 19:38:34 2013
;--------------------------------------------------------
$name step
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
	public _dostep
	public _step_and_break
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
; Interrupt vectors
;--------------------------------------------------------
	CSEG at 0xe01b
	ljmp	_step_and_break
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
;Allocation info for local variables in function 'step_and_break'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\step.c:39: void step_and_break (void) interrupt 3 _naked
;	-----------------------------------------
;	 function step_and_break
;	-----------------------------------------
_step_and_break:
;	naked function: no prologue.
;	.\step.c:121: _endasm;
	
	  clr ET1 ; Disable timer 1 interrupt (just in case!)
	
     ; Save the IE register and disable interrupts ASAP since the user code
     ; may have interrupts running which may modify the internal RAM
	        push IE
	  clr EA
	
        ; Save the user DPTR on the stack so it can be used to address XRAM.
	        push DPH
	        push DPL
	
        ; Save user program registers
	        mov DPTR,#_A_save
	        movx @DPTR,A
	
	        mov DPTR,#_PSW_save
	        mov A,PSW
	        movx @DPTR,A
	
	        mov DPTR,#_B_save
	        mov A,B
	        movx @DPTR,A
	
	        mov DPTR,#_DPL_save
	        pop ACC
	        movx @DPTR,A
	        mov DPTR,#_DPH_save
	        pop ACC
	        movx @DPTR,A
	
	        mov DPTR,#_IE_save
	        pop ACC
	        movx @DPTR,A
	
        ;The address of the next instrurtion is in the stack
	        mov DPTR,#_PC_save+1
	        pop ACC
	        movx @DPTR,A
	        mov DPTR,#_PC_save
	        pop ACC
	        movx @DPTR,A
	
        ;NOW we can save the user stack pointer
	        mov DPTR,#_SP_save
	        mov A,SP
	        movx @DPTR,A
	
        ; Save the user internal ram.
	        mov DPTR,#_iram_save
	        mov PSW,#0 ; Select register bank 0.
	        mov A,R0 ; Save R0.
	        movx @DPTR,A
	        mov R0,#1
	sab_l:
	        inc DPTR
	        mov A,@R0
	        movx @DPTR,A
	        inc R0
	        cjne R0,#128,sab_l
	
        ;Tell the monitor that the code got here
	        mov DPTR,#_gotbreak
	        mov A,#1
	        movx @DPTR,A
	
        ; Now the tricky part... going back to the monitor
	
        ; Initialize the monitor stack
	        mov sp,#_stack_start - 1
	
        ; Call the monitor hardware initialization
	        lcall __c51_external_startup
	
        ; Notice that crt0 initialization is skiped, otherwise the expanded RAM
        ; variables holding important variables will be clear.
	
        ; Go directly to the main routine
	        ljmp _main
	
	    
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'dostep'
;------------------------------------------------------------
;------------------------------------------------------------
;	.\step.c:125: void dostep (void) _naked
;	-----------------------------------------
;	 function dostep
;	-----------------------------------------
_dostep:
;	naked function: no prologue.
;	.\step.c:219: _endasm;
	
        ; Restore the user internal ram.
	        mov R0,#127
	        mov DPTR,#(_iram_save+127)
	ds_l:
	        movx A,@DPTR
	        mov @R0,A
	        dec DPL
	        djnz R0,ds_l
	        movx A,@DPTR
	        mov @R0,A
	
        ; Restore user registers
	        mov DPTR,#_IE_save
	        movx A,@DPTR
	        mov IE, A
	
	        mov DPTR,#_B_save
	        movx A,@DPTR
	        mov B,A
	
	        mov DPTR,#_PSW_save
	        movx A,@DPTR
	        mov PSW,A
	
	        mov DPTR,#_SP_save
	        movx A,@DPTR
	        mov SP,A
	
        ; if it is a 'go' push a 'break' into the stack
	        mov DPTR,#_gostep ; 1 is "go" 0 is step
	        movx A,@DPTR
	        jz ds_3
	        mov A, #0x1B
	        push ACC
	        clr A
	        push ACC
	        mov A, #0x1B
	        push ACC
	        clr A
	        push ACC
	ds_3:
  ;Put the user code start in the stack. The reti or ret at the end will get us there.
	        mov DPTR,#_step_start
	        movx A,@DPTR
	        push ACC
	        inc DPTR
	        movx A,@DPTR
	        push ACC
	
	        mov DPTR,#_DPL_save
	        movx A,@DPTR
	        push ACC
	        mov DPTR,#_DPH_save
	        movx A,@DPTR
	        push ACC
	
        ; Here use the accumulator to check if it is a go or a step
	        mov DPTR,#_gostep ; 1 is "go" 0 is step
	        movx A,@DPTR
	        jz ds_2
	
        ; go - restore the user accumulator.
	        mov DPTR,#_A_save
	        movx A,@DPTR
	
        ; and pop the user DPTR from the stack.
	        pop DPH
	        pop DPL
	
	        reti
	
	ds_2:
        ; step - restore the user accumulator.
	        mov DPTR,#_A_save
	        movx A,@DPTR
	
        ; pop the user DPTR from the user stack.
	        pop DPH
	        pop DPL
	
        ; Set up the timer 1 interrupt.
	
        ;Timer 1 must have the highest priority, otherwise in step by step
        ;execution instructions may look as if they are skept when interrupts
        ;of a higher priority are served. Since this is microcontroller dependent
        ;have it at the microcotnroller file (8052.c for example)
	        lcall _set_timer1_priority
	        setb EA ; enable interrupts
	        setb IT1 ; force timer 1 interrupt
	        setb ET1 ; Enable timer 1 interrupt
	        reti ; 'Return' to the user.
;	naked function: no epilogue.
	rseg R_CSEG

	rseg R_CONST

	rseg R_XINIT

	CSEG

end
