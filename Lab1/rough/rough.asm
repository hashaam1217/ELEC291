MOV DPTR, #myString ; DPTR points to the start of the string
MOV A, #00 ; Clear the accumulator

NEXT_CHAR:
MOVC A, @A+DPTR ; Load the character into the accumulator
JZ END_OF_STRING ; If the character is null, end the string

INC DPTR ; Move to the next character
SJMP NEXT_CHAR ; Repeat the process

END_OF_STRING:
; Code to end the program goes here

myString: DB 'Hello, World!', 0 ; The string to display

