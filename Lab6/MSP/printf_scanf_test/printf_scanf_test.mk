SHELL=cmd

OBJS=main.o print_format.o scan_format.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os -g2 -DSCANF_FLOAT -DPRINTF_FLOAT 
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,printf_scanf_test.map,-nostdlib

printf_scanf_test.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o printf_scanf_test.elf
	$(OBJCOPY) -O ihex printf_scanf_test.elf printf_scanf_test.hex
	@echo done!

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o

print_format.o: print_format.c
	$(CC) -c $(CCFLAGS) print_format.c -o print_format.o

scan_format.o: scan_format.c
	$(CC) -c $(CCFLAGS) scan_format.c -o scan_format.o
	
clean:
	del $(OBJS) *.elf

Load_Flash: printf_scanf_test.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r printf_scanf_test.hex
	@cmd /c start putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N

putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N
	
dummy: printf_scanf_test.map
	@echo :-)