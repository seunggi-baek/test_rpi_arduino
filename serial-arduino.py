#!/usr/bin/python3
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=5)

input_str = ser.readline()
print("Read input " + input_str.decode('utf-8').strip() + " from Arduino")

while True:
    ser.write(b'status\n')
    input_str = ser.readline().decode('utf-8').strip()
    if input_str == "":
        print(".")
    else:
        print("Read input back: " + input_str)

    time.sleep(5)

    ser.write(b'set on\n')
    input_str = ser.readline().decode('utf-8').strip()
    if input_str == "":
        print(".")
    else:
        print("Read input back(on): " + input_str)

    time.sleep(5)

    ser.write(b'set off\n')
    input_str = ser.readline().decode('utf-8').strip()
    if input_str == "":
        print(".")
    else:
        print("Read input back(off): " + input_str)

    time.sleep(5)


