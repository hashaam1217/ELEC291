CSEG

; Configure the serial port and baud rate
InitSerialPort:
	; Configure all the pins for biderectional I/O
	mov	P3M1,#0x00
	mov	P3M2,#0x00
	mov	P1M1,#0x00
	mov	P1M2,#0x00
	mov	P0M1,#0x00
	mov	P0M2,#0x00

    ; Since the reset button bounces, we need to wait a bit before
    ; sending messages, otherwise we risk displaying gibberish!
    mov R1, #200
    mov R0, #104
    djnz R0, $   ; 4 cycles->4*60.285ns*104=25us
    djnz R1, $-4 ; 25us*200=5.0ms

    ; Now we can proceed with the configuration of the serial port
	orl	CKCON, #0x10 ; CLK is the input for timer 1
	orl	PCON, #0x80 ; Bit SMOD=1, double baud rate
	mov	SCON, #0x52
	anl	T3CON, #0b11011111
	anl	TMOD, #0x0F ; Clear the configuration bits for timer 1
	orl	TMOD, #0x20 ; Timer 1 Mode 2
	mov	TH1, #TIMER1_RELOAD
	setb TR1
    ret

; Send a character using the serial port
putchar:
    jnb TI, putchar
    clr TI
    mov SBUF, a
    ret

; Send a constant-zero-terminated string using the serial port
SendString:
    clr A
    movc A, @A+DPTR
    jz SendStringDone
    lcall putchar
    inc DPTR
    sjmp SendString
SendStringDone:
    ret

Hello_World:
    DB  'Hello, World!', '\r', '\n', 0

MainProgram:
    mov SP, #7FH ; Set the stack pointer to the begining of idata

    lcall InitSerialPort
    ;mov DPTR, #0x38H
    ;mov DPTR, #Hello_World
    mov SBUF, #0x05
    lcall putchar
    ret
    lcall SendString

    ;sjmp $; This is equivalent to 'forever: sjmp forever'
    ret

END
