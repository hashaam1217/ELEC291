SHELL=cmd

OBJS=main.o uart.o
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

main.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o main.elf
	$(OBJCOPY) -O ihex main.elf main.hex
	@echo done!

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o

uart.o: uart.c
	$(CC) -c $(CCFLAGS) uart.c -o uart.o
	
clean:
	del $(OBJS) *.elf *.hex

Load_Flash: main.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r main.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N

dummy: main.lst
	@echo Hello!
	
dissasembly:
	$(ODDJUMP) -d main.elf > main.lst
