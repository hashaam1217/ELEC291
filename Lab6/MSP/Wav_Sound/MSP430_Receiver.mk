SHELL=cmd

OBJS=MSP430_Receiver.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,MSP430_Receiver.map

MSP430_Receiver.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o MSP430_Receiver.elf
	$(OBJCOPY) -O ihex MSP430_Receiver.elf MSP430_Receiver.hex
	@echo done!

MSP430_Receiver.o: MSP430_Receiver.c
	$(CC) -c $(CCFLAGS) MSP430_Receiver.c -o MSP430_Receiver.o

clean:
	del $(OBJS) *.elf *.map MSP430_Receiver.hex

Load_Flash: MSP430_Receiver.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r MSP430_Receiver.hex

putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	cmd /c start c:\putty\putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N
	
dummy: MSP430_Receiver.map
	@echo :-)