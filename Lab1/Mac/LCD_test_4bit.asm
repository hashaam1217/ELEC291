; LCD_test_4bit.asm: Initializes and uses an LCD in 4-bit mode
; using the most common procedure found on the internet and datasheets.
$NOLIST
$MODN76E003
$LIST

org 0000H
    ljmp myprogram

;  N76E003 pinout:
;                               -------
;       PWM2/IC6/T0/AIN4/P0.5 -|1    20|- P0.4/AIN5/STADC/PWM3/IC3
;               TXD/AIN3/P0.6 -|2    19|- P0.3/PWM5/IC5/AIN6
;               RXD/AIN2/P0.7 -|3    18|- P0.2/ICPCK/OCDCK/RXD_1/[SCL]
;                    RST/P2.0 -|4    17|- P0.1/PWM4/IC4/MISO
;        INT0/OSCIN/AIN1/P3.0 -|5    16|- P0.0/PWM3/IC3/MOSI/T1
;              INT1/AIN0/P1.7 -|6    15|- P1.0/PWM2/IC2/SPCLK
;                         GND -|7    14|- P1.1/PWM1/IC1/AIN7/CLO
;[SDA]/TXD_1/ICPDA/OCDDA/P1.6 -|8    13|- P1.2/PWM0/IC0
;                         VDD -|9    12|- P1.3/SCL/[STADC]
;            PWM5/IC7/SS/P1.5 -|10   11|- P1.4/SDA/FB/PWM1
;                               -------
;

; These 'equ' must match the hardware wiring
LCD_RS equ P1.3
;LCD_RW equ PX.X ; Not used in this code, connect the pin to GND
LCD_E  equ P1.4
LCD_D4 equ P0.0
LCD_D5 equ P0.1
LCD_D6 equ P0.2
LCD_D7 equ P0.3

; When using a 16.6MHz oscillator in the N76E003
; one cycle takes 1.0/16.6MHz = 60.24 ns

;---------------------------------;
; Wait 40 microseconds            ;
;---------------------------------;
Wait40uSec:
    push AR0
    mov R0, #133
L0:
    nop
    djnz R0, L0 ; 1+4 cycles->5*60.24ns*133=40us
    pop AR0
    ret

;---------------------------------;
; Wait 'R2' milliseconds          ;
;---------------------------------;
WaitmilliSec:
    push AR0
    push AR1
L3: mov R1, #40
L2: mov R0, #104
L1: djnz R0, L1 ; 4 cycles->4*60.24ns*104=25.0us
    djnz R1, L2 ; 25us*40=1.0ms
    djnz R2, L3 ; number of millisecons to wait passed in R2
    pop AR1
    pop AR0
    ret

;---------------------------------;
; Toggles the LCD's 'E' pin       ;
;---------------------------------;
LCD_pulse:
    setb LCD_E
    lcall Wait40uSec
    clr LCD_E
    ret

;---------------------------------;
; Writes data to LCD              ;
;---------------------------------;
WriteData:
    setb LCD_RS
    ljmp LCD_byte

;---------------------------------;
; Writes command to LCD           ;
;---------------------------------;
WriteCommand:
    clr LCD_RS
    ljmp LCD_byte

;---------------------------------;
; Writes acc to LCD in 4-bit mode ;
;---------------------------------;
LCD_byte:
    ; Write high 4 bits first
    mov c, ACC.7
    mov LCD_D7, c
    mov c, ACC.6
    mov LCD_D6, c
    mov c, ACC.5
    mov LCD_D5, c
    mov c, ACC.4
    mov LCD_D4, c
    lcall LCD_pulse

    ; Write low 4 bits next
    mov c, ACC.3
    mov LCD_D7, c
    mov c, ACC.2
    mov LCD_D6, c
    mov c, ACC.1
    mov LCD_D5, c
    mov c, ACC.0
    mov LCD_D4, c
    lcall LCD_pulse
    ret

;---------------------------------;
; Configure LCD in 4-bit mode     ;
;---------------------------------;
LCD_4BIT:
    clr LCD_E   ; Resting state of LCD's enable is zero
    ; clr LCD_RW  ; Not used, pin tied to GND

    ; After power on, wait for the LCD start up time before initializing
    mov R2, #40
    lcall WaitmilliSec

    ; First make sure the LCD is in 8-bit mode and then change to 4-bit mode
    mov a, #0x33
    lcall WriteCommand
    mov a, #0x33
    lcall WriteCommand
    mov a, #0x32 ; change to 4-bit mode
    lcall WriteCommand

    ; Configure the LCD
    mov a, #0x28
    lcall WriteCommand
    mov a, #0x0c
    lcall WriteCommand
    mov a, #0x01 ;  Clear screen command (takes some time)
    lcall WriteCommand

    ;Wait for clear screen command to finish. Usually takes 1.52ms.
    mov R2, #2
    lcall WaitmilliSec
    ret


print: 
    MOV A, #0
    MOV R1, #0
    sjmp nextchar
  
    
nextchar:
	MOV A, R1 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R3, A			;Saves character
	MOV A, R0		
	ADD A, R1 			;Updates cursor
    lcall WriteCommand  
    MOV A, R3			;Writes character
    lcall WriteData


    MOV R2, #0xFF		;Delay (250ms)
    lcall WaitmilliSec
    
	INC R1
	CJNE R1, #7, nextchar; end condition
	
	MOV A, R1
	MOVC A, @A+DPTR
    
    ; Final iteration to print the last character
    MOV A, R1 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R3, A			;Saves character
	MOV A, R0		
	ADD A, R1 			;Updates cursor
    lcall WriteCommand  
    MOV A, R3			;Writes character
    lcall WriteData


    MOV R2, #0xFF		;Delay (250ms)
    lcall WaitmilliSec
   
    RET
    
 
;---------------------------------;
; Main loop.  Initialize stack,   ;
; ports, LCD, and displays        ;
; letters on the LCD              ;
;---------------------------------;
myprogram:
    mov SP, #7FH
    ; Configure the pins as bi-directional so we can use them as input/output
    mov P0M1, #0x00
    mov P0M2, #0x00
    mov P1M1, #0x00
    mov P1M2, #0x00
    mov P3M2, #0x00
    mov P3M2, #0x00
    
    lcall LCD_4BIT

    ; Writing out my name - Hashaam
    MOV DPTR, #FirstName
    MOV R0, #0x80
    MOV R2, #7
    lcall print

	; Writing out student number - 10078020
	MOV DPTR, #StudentNumber
	MOV R0, #0xC0
	MOV R2, #8
	lcall print
	
	;Pacman code
;    MOV DPTR, #Pacman
;    mov A, #0x40
;    lcall WriteCommand
;    MOV R1, #0
;loop:;
;	MOV A, R1
;MOVC A, @A+DPTR
;lcall WriteData
;INC R1
;CJNE R1, #8, loop
	
;MOV A, #0x80
;lcall WriteCommand
;MOV A, #0x00
;lcall WriteData
 
	
    
forever:
	;Animation for Pacman
	MOV R0, #0 ;Counter for the path

MainLoop:
	MOV DPTR, #Path
	MOV A, R0 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R2, A 			;Saves R2 as pacman's position
    
    ;Ghost 1
    MOV A, R0
    INC A	 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R3, A 			;Saves R2 as pacman's position
    
    ;Ghost 2
    MOV A, R0
    INC A
    INC A	 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R4, A 			;Saves R2 as pacman's position
    
    ;Ghost 3
    MOV A, R0
    INC A
    INC A
    INC A	 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R5, A 			;Saves R2 as pacman's position
    
    ;Ghost 4
    MOV A, R0
    INC A
    INC A
    INC A
    INC A	 			;Updates counter
	MOVC A, @A+DPTR		;Retrieves character
    MOV R6, A 			;Saves R2 as pacman's position
    

    
    
    MOV A, #01H ; Load the immediate value into the accumulator
	ANL A, R2 ; Perform bitwise AND with the value in R2
	MOV R2, A ; Move the result back to register R2
	JZ EvenLabel
	;Odd number code
	MOV DPTR, #Pacman
	sjmp EvenOddEnd

EvenLabel: 
	MOV DPTR, #AltPacman
	;Basic if else to alternate between pacman and alt pacman
	
	;Prints out pacman
EvenOddEnd: 
	mov A, #0x40
    lcall WriteCommand
    MOV R1, #0
PacmanLoop:
	MOV A, R1
	MOVC A, @A+DPTR
	lcall WriteData
	INC R1
	CJNE R1, #8, PacmanLoop
 
 ;Ghost one
 
    MOV DPTR, #Ghost1
    mov A, #0x40
    lcall WriteCommand
    MOV R1, #0
Ghost1Loop:
	MOV A, R1
	MOVC A, @A+DPTR
	lcall WriteData
	INC R1
	CJNE R1, #8, Ghost1Loop
	
	MOV A, R3
	lcall WriteCommand
	MOV A, #0x00
	lcall WriteData
	
;Ghost two
    MOV DPTR, #Ghost2
    mov A, #0x40
    lcall WriteCommand
    MOV R1, #0
Ghost2Loop:
	MOV A, R1
	MOVC A, @A+DPTR
	lcall WriteData
	INC R1
	CJNE R1, #8, Ghost2Loop
	
	MOV A, #0x80
	lcall WriteCommand
	MOV A, #0x00
	lcall WriteData
	
;Ghost 3
    MOV DPTR, #Ghost3
    mov A, #0x40
    lcall WriteCommand
    MOV R1, #0
Ghost3Loop:
	MOV A, R1
	MOVC A, @A+DPTR
	lcall WriteData
	INC R1
	CJNE R1, #8, Ghost3Loop
	
	MOV A, #0x80
	lcall WriteCommand
	MOV A, #0x00
	lcall WriteData
	
;Ghost 4
    MOV DPTR, #Ghost4
    mov A, #0x40
    lcall WriteCommand
    MOV R1, #0
Ghost4Loop:
	MOV A, R1
	MOVC A, @A+DPTR
	lcall WriteData
	INC R1
	CJNE R1, #8, Ghost4Loop
	
	MOV A, R6
	lcall WriteCommand
	MOV A, #0x00
	lcall WriteData
	
	MOV R2, #0xFF		;Delay (250ms)
    lcall WaitmilliSec
    
    INC R0
    
    CJNE R0, #15, bigjump
    
	
    ljmp forever
bigjump:
	LJMP MainLoop
; Data declarations
FirstName: DB 'Hashaam ' , 0
StudentNumber: DB '10078020',0

; Custom Characters (8 allowed)
Pacman: DB  0x00, 0x0E, 0x1F, 0x1E, 0x1C, 0x1E, 0x1F, 0x0E
AltPacman: DB  0x00, 0x0E ,0x1F, 0x1B, 0x1F, 0x16, 0x19, 0x0E
Ghost1: DB 0x00, 0x00, 0x0E, 0x1F, 0x15, 0x1F, 0x1F, 0x0A
Ghost2: DB 0x00, 0x00, 0x0E, 0x1F, 0x15, 0x1F, 0x1F, 0x15
Ghost3: DB 0x0E, 0x1F, 0x15, 0x1F, 0x1F, 0x0A, 0x00, 0x00
Ghost4: DB 0x0E, 0x1F, 0x15, 0x1F, 0x1F, 0x15, 0x00, 0x00

Path: DB 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0xCF, 0xCE, 0xCD, 0xCC, 0xCB, 0xCA, 0xC9, 0xC8,0x08, 0x09, 0x0A, 0x0B, 0x0C  
END


