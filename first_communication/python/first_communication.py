#/usr/bin env python3
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)
time.sleep(3)

if(ser.isOpen() == False):
    ser.open()

ser.reset_input_buffer()
print("Serial OK")

try:
    while True:
        time.sleep(0.01)
        line = ser.readline().decode('utf-8')
        print(f"rpi3 : {line}")
except KeyboardInterrupt:
    print("Close Serial")
    ser.close()
