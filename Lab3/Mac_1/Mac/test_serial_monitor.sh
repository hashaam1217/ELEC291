#!/bin/bash
# Doesn't run the serial monitor for some reason after bootloader
./a51 -l Hello.asm
./ISPN76E003 -r -p/dev/ttyUSB0 Hello.hex
wait
echo "finished"
stty -F /dev/ttyUSB0 115200 cs8 -cstopb -parenb
cat < /dev/ttyUSB0
