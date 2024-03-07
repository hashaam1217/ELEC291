import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys, time, math
import serial

ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.EIGHTBITS
)

ser.isOpen()

while True:
    print("Started")
    strin = ser.readline()
    print(strin)
    byte_string = strin
    print(byte_string)
    string = byte_string.decode('utf-8').strip  # Decode the byte string into a regular string
    print(string)
    numeric_part = string[:-1]
    try:
        number = float(numeric_part)
        print(f"Converted float: {number}")
    except ValueError:
        print("Invalid format for float.")


print (number)
