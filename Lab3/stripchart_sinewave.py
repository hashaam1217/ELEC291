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

xsize=100

def data_gen():
    t = data_gen.t
    N = 20  # Number of samples to average over
    samples = []  # List to store the last N samples
    derivative_samples= []
    while True:
        strin = ser.readline()
        byte_string = strin
        string = byte_string.decode('utf-8')  # Decode the byte string into a regular string
        string = string.strip()  # Remove the newline character at the end
        number = int(string)
        print (number)
        t += 0.5
        samples.append(number)  # Add the new sample to the list

        # If we have more than N samples, remove the oldest one
        if len(samples) > N:
            samples.pop(0)

        # Calculate the average of the last N samples
        val = sum(samples) / len(samples)
        print(val)
        if len(samples) > 1:
            derivative = np.diff(samples)[-1]/0.5
            derivative_samples.append(derivative)
            if len(derivative_samples) > N:
                derivative_samples.pop(0)
                derivative = sum(derivative_samples) / len(derivative_samples)
        else:
            derivative = 0

        yield t, val, derivative

def run(data):
    # update the data
    t, y, dydt = data
    if t > -1:
        xdata.append(t)
        ydata.append(y)
        dydt_data.append(dydt)
        if t > xsize:  # Scroll to the left.
            ax.set_xlim(t - xsize, t)
        line.set_data(xdata, ydata)
        line2.set_data(xdata, dydt_data)

    return line, line2,

data_gen.t = -1
fig = plt.figure()
ax = fig.add_subplot(111)
line, = ax.plot([], [], lw=2)
line2, = ax.plot([], [], lw=2, color='r')  # New line for the derivative
ax.set_ylim(0, 50)
ax.set_xlim(0, xsize)
ax.grid()
xdata, ydata, dydt_data = [], [], []  # New list for the derivative data

ani = animation.FuncAnimation(fig, run, data_gen, blit=False, interval=100, repeat=False)

plt.show()

