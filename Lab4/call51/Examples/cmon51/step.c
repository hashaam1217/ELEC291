/*
CMON51: C Monitor for the 8051
Copyright (C) 2005-2013 Jesus Calvino-Fraga / jesusc at ece.ubc.ca

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

extern volatile xdata char iram_save[128];
extern volatile xdata unsigned char A_save;
extern volatile xdata unsigned char PSW_save;
extern volatile xdata unsigned char B_save;
extern volatile xdata unsigned char IE_save;
extern volatile xdata unsigned int  DPL_save;
extern volatile xdata unsigned int  DPH_save;
extern volatile xdata unsigned char SP_save;
extern volatile xdata unsigned int  PC_save;
extern volatile xdata unsigned char gotbreak;
extern volatile xdata unsigned int  step_start;
extern volatile xdata unsigned char saved_jmp[3];
extern volatile xdata unsigned char saved_int[3];

//This is the function that enters after just one assembly instruction of user code
//is executed in single step mode.  Don't be deceived by the interupt number here, as sdcc will
//use the number defined in the external function protoype in the main file of each proccessor.
//For instance, some ports (p89v51rd2 and at89c51ed2) are using interrupt vector 0 to save some
//code space.
void step_and_break (void) interrupt 3 _naked
{
    _asm
		clr		ET1				; Disable timer 1 interrupt (just in case!)

    	; Save the IE register and disable interrupts ASAP since the user code
    	; may have interrupts running which may modify the internal RAM
        push	IE
		clr		EA
		
        ; Save the user DPTR on the stack so it can be used to address XRAM.
        push    DPH
        push    DPL

        ; Save user program registers
        mov     DPTR,#_A_save
        movx    @DPTR,A

        mov     DPTR,#_PSW_save
        mov     A,PSW
        movx    @DPTR,A

        mov     DPTR,#_B_save
        mov     A,B
        movx    @DPTR,A

        mov     DPTR,#_DPL_save
        pop     ACC
        movx    @DPTR,A
        mov     DPTR,#_DPH_save
        pop     ACC
        movx    @DPTR,A
        
        mov     DPTR,#_IE_save
        pop     ACC
        movx    @DPTR,A

        ;The address of the next instrurtion is in the stack
        mov     DPTR,#_PC_save+1
        pop     ACC
        movx    @DPTR,A
        mov     DPTR,#_PC_save
        pop     ACC
        movx    @DPTR,A

        ;NOW we can save the user stack pointer
        mov     DPTR,#_SP_save
        mov     A,SP
        movx    @DPTR,A

        ; Save the user internal ram.
        mov     DPTR,#_iram_save
        mov     PSW,#0  ; Select register bank 0.
        mov     A,R0    ; Save R0.
        movx    @DPTR,A
        mov     R0,#1
sab_l:
        inc     DPTR
        mov     A,@R0
        movx    @DPTR,A
        inc     R0
        cjne    R0,#128,sab_l

        ;Tell the monitor that the code got here
        mov     DPTR,#_gotbreak
        mov     A,#1
        movx    @DPTR,A

        ; Now the tricky part... going back to the monitor
        
        ; Initialize the monitor stack
        mov     sp,#_stack_start - 1
        
        ; Call the monitor hardware initialization
        lcall   __c51_external_startup
        
        ; Notice that crt0 initialization is skiped, otherwise the expanded RAM
        ; variables holding important variables will be clear.

        ; Go directly to the main routine
        ljmp    _main

    _endasm;
}

//Run one instruction of user code or go.  The interrupts are already disabled.
void dostep (void) _naked
{
_asm
        ; Restore the user internal ram.
        mov     R0,#127
        mov     DPTR,#(_iram_save+127)
ds_l:
        movx    A,@DPTR
        mov     @R0,A
        dec     DPL
        djnz    R0,ds_l
        movx    A,@DPTR
        mov     @R0,A

        ; Restore user registers
        mov     DPTR,#_IE_save
        movx    A,@DPTR
        mov     IE, A
        
        mov     DPTR,#_B_save
        movx    A,@DPTR
        mov     B,A

        mov     DPTR,#_PSW_save
        movx    A,@DPTR
        mov     PSW,A

        mov     DPTR,#_SP_save
        movx    A,@DPTR
        mov     SP,A

        ; if it is a 'go' push a 'break' into the stack
        mov     DPTR,#_gostep ; 1 is "go" 0 is step
        movx    A,@DPTR
        jz      ds_3
        mov		A, #0x1B
        push	ACC
        clr		A
        push	ACC
        mov		A, #0x1B
        push	ACC
        clr		A
        push	ACC
ds_3:
		;Put the user code start in the stack.  The reti or ret at the end will get us there.
        mov     DPTR,#_step_start
        movx    A,@DPTR
        push    ACC
        inc     DPTR
        movx    A,@DPTR
        push    ACC

        mov     DPTR,#_DPL_save
        movx    A,@DPTR
        push    ACC
        mov     DPTR,#_DPH_save
        movx    A,@DPTR
        push    ACC
        
        ; Here use the accumulator to check if it is a go or a step
        mov     DPTR,#_gostep ; 1 is "go" 0 is step
        movx    A,@DPTR
        jz      ds_2

        ; go - restore the user accumulator.
        mov     DPTR,#_A_save
        movx    A,@DPTR

        ; and pop the user DPTR from the stack.
        pop     DPH
        pop     DPL
        
        reti

ds_2:
        ; step - restore the user accumulator.
        mov     DPTR,#_A_save
        movx    A,@DPTR

        ; pop the user DPTR from the user stack.
        pop     DPH
        pop     DPL

        ; Set up the timer 1 interrupt.
        
        ;Timer 1 must have the highest priority, otherwise in step by step
        ;execution instructions may look as if they are skept when interrupts
        ;of a higher priority are served.  Since this is microcontroller dependent
        ;have it at the microcotnroller file (8052.c for example)
        lcall _set_timer1_priority
        setb    EA				; enable interrupts
        setb	IT1				; force timer 1 interrupt 
        setb	ET1				; Enable timer 1 interrupt
       	reti					; 'Return' to the user.
_endasm;
}
