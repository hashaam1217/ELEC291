# Since we are compiling in windows, select 'cmd' as the default shell.  This
# is important because make will search the path for a linux/unix like shell
# and if it finds it will use it instead.  This is the case when cygwin is
# installed.  That results in commands like 'del' and echo that don't work.
SHELL=cmd

OBJS=blinky.o

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -O2 -g
LDFLAGS = -L $(SUPPORT_DIR)

# The default 'target' (output) is blinky.elf and 'depends' on
# the object files listed in the 'OBJS' assignment above.
# These object files are linked together to create blinky.elf.
# The linked file is converted to hex using program objcopy.
blinky.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o blinky.elf
	$(OBJCOPY) -O ihex blinky.elf blinky.hex
	@echo done!

# The object file blinky.o depends on blinky.c. blinky.c is compiled
# to create blinky.o.
blinky.o: blinky.c
	$(CC) -c $(CCFLAGS) blinky.c -o blinky.o
	
clean:
	del $(OBJS) *.elf *.hex

Load_Flash: blinky.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r blinky.hex

Verify_Flash: blinky.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -v -r blinky.hex
