import serial

# Configure the serial port
ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.EIGHTBITS
)

# Check if the serial port is open
if ser.isOpen():
    print("Serial port is open.")
else:
    print("Error: Serial port is not open.")
    sys.exit(1)  # Exit the program if the port is not open

try:
    while True:
        # Read a line from the serial port
        raw_data = ser.readline()
        print(f"Raw data received: {raw_data}")

        # Decode the byte string into a regular string
        decoded_string = raw_data.decode('utf-8').strip()
        print(f"Decoded string: {decoded_string}")

        # Attempt to convert the numeric part to a float
        numeric_part = decoded_string[:-1]
        try:
            number = float(numeric_part)
            print(f"Converted float: {number}")
        except ValueError:
            print("Invalid format for float.")
except KeyboardInterrupt:
    print("\nExiting due to user interruption.")
finally:
    ser.close()  # Close the serial port when done

