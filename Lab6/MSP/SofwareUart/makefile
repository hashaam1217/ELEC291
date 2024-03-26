SHELL=cmd

OBJS=SoftwareUart.o
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

SoftwareUart.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o SoftwareUart.elf
	$(OBJCOPY) -O ihex SoftwareUart.elf SoftwareUart.hex
	@echo done!

SoftwareUart.o: SoftwareUart.c
	$(CC) -c $(CCFLAGS) SoftwareUart.c -oSoftwareUart.o
	
clean:
	del $(OBJS) *.elf *.hex

Load_Flash: SoftwareUart.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r SoftwareUart.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 9600,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 9600,8,n,1,N
