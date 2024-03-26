SHELL=cmd

OBJS=main.o print_format.o nrf24.o radioPinFunctions.o
PORTN=$(shell type COMPORT.inc)

DEVICE  = msp430g2553
CC      = msp430-elf-gcc
LD      = msp430-elf-ld
OBJCOPY = msp430-elf-objcopy
ODDJUMP = msp430-elf-objdump

GCCPATH=$(subst \bin\$(CC).exe,\,$(shell where $(CC)))
SUPPORT_DIR = $(GCCPATH)include

CCFLAGS = -I $(SUPPORT_DIR) -mmcu=$(DEVICE) -Os
LDFLAGS = -L $(SUPPORT_DIR) -Wl,-Map,SPI_nRF24L018.map

SPI_nRF24L018.elf: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LDFLAGS) -o SPI_nRF24L018.elf
	$(OBJCOPY) -O ihex SPI_nRF24L018.elf SPI_nRF24L018.hex
	@echo done!

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o

print_format.o: print_format.c
	$(CC) -c $(CCFLAGS) print_format.c -o print_format.o

nrf24.o: nrf24.c
	$(CC) -c $(CCFLAGS) nrf24.c -o nrf24.o
	
radioPinFunctions.o: radioPinFunctions.c
	$(CC) -c $(CCFLAGS) radioPinFunctions.c -o radioPinFunctions.o
	
clean:
	del $(OBJS) *.elf *.map SPI_nRF24L018.hex

Load_Flash: SPI_nRF24L018.hex
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	MSP430_prog -p -r SPI_nRF24L018.hex
	@cmd /c start c:\putty\putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N

Circuit_Picture_1:
	cmd /c start pictures\nRF24L01_Connection_1.jpg

Circuit_Picture_2:
	cmd /c start pictures\nRF24L01_Connection_2.jpg

putty:
	@taskkill /f /im putty.exe /t /fi "status eq running" > NUL
	@cmd /c start c:\putty\putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N
	
dummy: SPI_nRF24L018.map
	@echo :-)