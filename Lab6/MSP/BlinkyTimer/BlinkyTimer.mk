SHELL=cmd

OBJS=BlinkyTimer.o

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -O2 -g
LDFLAGS = -L $(SUPPORT_DIR)

BlinkyTimer.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o BlinkyTimer.elf
	$(OBJCOPY) -O ihex BlinkyTimer.elf BlinkyTimer.hex
	@echo done!

BlinkyTimer.o: BlinkyTimer.c
	$(CC) -c $(CCFLAGS) BlinkyTimer.c -oBlinkyTimer.o
	
clean:
	del $(OBJS) *.elf *.hex

Load_Flash: BlinkyTimer.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r BlinkyTimer.hex

Verify_Flash: BlinkyTimer.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -v -r BlinkyTimer.hex
