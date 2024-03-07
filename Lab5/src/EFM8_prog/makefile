EFM8_prog: EFM8_prog.o
	gcc -o EFM8_prog EFM8_prog.c

ADC:
	wine c51.exe EFM8_ADC.c 2>&1 | grep -v preloader | grep -v fixme
F:
	./c
	./EFM8_prog -r -p/dev/ttyUSB0 EFM8_ADC.hex

clean:
	rm -f *.o *.asm *.hex *.lkr *.lst *.map *.obj
