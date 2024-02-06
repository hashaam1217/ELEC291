import time
import serial
# configure the serial port
ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.EIGHTBITS
)
ser.isOpen()
while 1 :
    strin = ser.readline()
    byte_string = strin
    string = byte_string.decode('utf-8')  # Decode the byte string into a regular string
    string = string.strip()  # Remove the newline character at the end
    number = int(string)
    print (number)
