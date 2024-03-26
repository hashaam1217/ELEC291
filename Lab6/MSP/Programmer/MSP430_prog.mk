SHELL=cmd
PORTN=$(shell type COMPORT.inc)

# Compile using Microsoft Visual C.  Check docl.bat.
MSP430_prog.exe: MSP430_prog.c
	@docl MSP430_prog.c
	
clean:
	del MSP430_prog.obj MSP430_prog.exe

dummy: docl.bat
	@echo hello from dummy target!
	
program_blinky: ..\Blinky\blinky.hex
	MSP430_prog -p -r ..\Blinky\blinky.hex

program_uart: ..\Uart\main.hex
	MSP430_prog -p -r ..\Uart\main.hex

Calibration_IC_1: Calibration_IC_1.hex
	MSP430_prog -p -q Calibration_IC_1.hex

run:
	MSP430_prog -r
	
CBUS_default:
	MSP430_prog -cbus
	
explorer:
	explorer .
