mov SP, #0AH
mov 0AH, #08H
pop SP
mov a, #0AH
mov psw, #01110000B
subb a, #01H
