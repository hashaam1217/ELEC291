@echo off
echo %1
c51 %1 --model-medium --use-stdout >> reg_m.txt
s51 %~n1.hex -r10 -oreg_m.txt
del *.asm *.lkr *.lst *.map *.obj *.hex

