SHELL=cmd

OBJS=main.o print_format.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,SPI_MCP3008.map

SPI_MCP3008.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o SPI_MCP3008.elf
	$(OBJCOPY) -O ihex SPI_MCP3008.elf SPI_MCP3008.hex
	@echo done!

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o

print_format.o: print_format.c
	$(CC) -c $(CCFLAGS) print_format.c -o print_format.o
	
clean:
	del $(OBJS) *.elf *.map SPI_MCP3008.hex

Load_Flash: SPI_MCP3008.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r SPI_MCP3008.hex
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N

putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start putty -serial $(PORTN) -sercfg 115200,8,n,1,N
	
Circuit_Picture: SPI_MCP3008.map
	cmd /c start SPI_MCP3008.jpg
