@echo off
echo %1
echo %1 >> reg.txt
c51 %1 --use-stdout >> reg.txt
s51 %~n1.hex -r10 -oreg.txt
del *.asm *.lkr *.lst *.map *.obj *.hex

