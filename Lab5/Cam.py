 
import time
import serial
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys, time, math
import re

xsize = 1000


def data_gen():
    t = data_gen.t
    while True:
        # read data from serial port
        #data = ser.readline()
        #data = data.strip()
        #data = data.decode('utf-8')
        #data_num = (float(data)/100)
        # print temp to terminal
        #print(data_num)
        t += 1
        val1 = 2 * math.sin(t * 2.0 * 3.1415 / 100.0)  # Sine wave 1 with amplitude 100
        val2 = 1 * math.sin(t * 2.0 * 3.1415 / 100.0)  # Sine wave 2 with amplitude 50
        yield t, val1, val2

def run(data):
    # update the data
    t, y1, y2 = data
    if t > -1:
        xdata.append(t)
        ydata.append(y1)
        ydata2.append(y2)
        if t > xsize:  # Scroll to the left.
            ax.set_xlim(t-xsize, t)
        line.set_data(xdata, ydata)
        line2.set_data(xdata, ydata2)

    return line, line2,

def on_close_figure(event):
    sys.exit(0)

data_gen.t = -1
fig = plt.figure()
fig.canvas.mpl_connect('close_event', on_close_figure)
ax = fig.add_subplot(111)
line, = ax.plot([], [], lw=2, label='Ref signal')
line2, = ax.plot([], [], lw=2, color='r', label='Input signal')  # Second sine wave
ax.set_ylim(-5, 5)  # Adjusted ylim to accommodate both waves
ax.set_xlim(0, xsize)
ax.grid()
xdata, ydata, ydata2 = [], [], []

ani = animation.FuncAnimation(fig, run, data_gen, blit=False, interval=100, repeat=False, cache_frame_data=False)
plt.legend()
plt.show()
