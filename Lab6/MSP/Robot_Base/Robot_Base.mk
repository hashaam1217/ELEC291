SHELL=cmd

OBJS=Robot_Base.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,Robot_Base.map

Robot_Base.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o Robot_Base.elf
	$(OBJCOPY) -O ihex Robot_Base.elf Robot_Base.hex
	@echo done!

Robot_Base.o: Robot_Base.c
	$(CC) -c $(CCFLAGS) Robot_Base.c -o Robot_Base.o
	
clean:
	del $(OBJS) *.elf *.hex *.map

Load_Flash: Robot_Base.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r Robot_Base.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
dummy: Robot_Base.map
	@echo :-)