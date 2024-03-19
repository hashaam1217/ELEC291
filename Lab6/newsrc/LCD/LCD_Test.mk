SHELL=cmd

OBJS=main.o lcd.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,main.map

main.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o main.elf
	$(OBJCOPY) -O ihex main.elf main.hex
	@echo done!

main.o: main.c lcd.h
	$(CC) -c $(CCFLAGS) main.c -o main.o

lcd.o: lcd.c lcd.h
	$(CC) -c $(CCFLAGS) lcd.c -o lcd.o
	
clean:
	del $(OBJS) *.elf *.hex *.map

Load_Flash: main.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r main.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N

Picture:
	@cmd /c start Pictures\MSP430_LCD.jpg
	
dummy: main.map
	@echo :-)