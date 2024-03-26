SHELL=cmd

OBJS=Blinky_isr.o

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -O2 -g
LDFLAGS = -L $(SUPPORT_DIR)

Blinky_isr.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o Blinky_isr.elf
	$(OBJCOPY) -O ihex Blinky_isr.elf Blinky_isr.hex
	@echo done!

Blinky_isr.o: Blinky_isr.c
	$(CC) -c $(CCFLAGS) Blinky_isr.c -oBlinky_isr.o
	
clean:
	del $(OBJS) *.elf *.hex

Load_Flash: Blinky_isr.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r Blinky_isr.hex

Verify_Flash: Blinky_isr.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -v -r Blinky_isr.hex
