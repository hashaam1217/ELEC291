SHELL=cmd

OBJS=main.o
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

ShowCalibration.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o ShowCalibration.elf
	$(OBJCOPY) -O ihex ShowCalibration.elf ShowCalibration.hex
	@echo done!

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o
	
clean:
	del $(OBJS) *.elf

Load_Flash: ShowCalibration.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r ShowCalibration.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N

dummy: main.lst
	@echo Hello!

