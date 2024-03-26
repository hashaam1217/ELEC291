SHELL=cmd

OBJS=Servo.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -O2 -g
LDFLAGS = -L $(SUPPORT_DIR)

Servo.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o Servo.elf
	$(OBJCOPY) -O ihex Servo.elf Servo.hex
	@echo done!

Servo.o: Servo.c
	$(CC) -c $(CCFLAGS) Servo.c -oServo.o
	
clean:
	del $(OBJS) *.elf *.hex

Load_Flash: Servo.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r Servo.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
