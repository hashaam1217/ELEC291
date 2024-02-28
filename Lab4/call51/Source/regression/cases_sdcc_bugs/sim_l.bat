@echo off
echo %1
c51 %1 --model-large --use-stdout >> reg_l.txt
s51 %~n1.hex -r10 -oreg_l.txt
del *.asm *.lkr *.lst *.map *.obj *.hex

