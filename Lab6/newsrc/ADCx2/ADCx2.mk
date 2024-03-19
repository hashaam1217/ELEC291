SHELL=cmd

OBJS=adc.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,adc_test.map

adc_test.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o adc_test.elf
	$(OBJCOPY) -O ihex adc_test.elf adc_test.hex
	@echo done!

adc.o: adc.c
	$(CC) -c $(CCFLAGS) adc.c -o adc.o
	
clean:
	del $(OBJS) *.elf *.hex *.map

Load_Flash: adc_test.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r adc_test.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
dummy: adc_test.map
	@echo :-)