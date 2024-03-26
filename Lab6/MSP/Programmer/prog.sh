#!/bin/bash

sudo rmmod ftdi_sio
sudo ./MSP430_prog -p -r $1
sudo modprobe ftdi_sio
