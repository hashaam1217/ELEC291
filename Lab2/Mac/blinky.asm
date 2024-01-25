$MODN76E003

;  N76E003AT20 pinout:
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

org 0000H
    ljmp myprogram

; When using a 16.6MHz oscillator one cycle takes 1.0/16.6MHz = 60.24 ns
WaitHalfSec:
    mov R2, #100
L3: mov R1, #200
L2: mov R0, #104
L1: djnz R0, L1 ; 4 cycles->4*60.24ns*104=25us
    djnz R1, L2 ; 25us*200=5.0ms
    djnz R2, L3 ; 5.0ms*100=0.5s (approximately)
    ret
	
myprogram:
    mov SP, #7FH
    mov P1M1, #0 ; Configure P1 in bidirectional mode
    mov P1M2, #0 ; Configure P1 in bidirectional mode
M0:
    cpl P1.7
    lcall WaitHalfSec
    sjmp M0
END