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
        time.sleep(1)
        print("Send message to Arduino")
        ser.write("Hello from Raspberry Pi\n".encode('utf-8'))

except KeyboardInterrupt:
    print("Close Serial")
    ser.close()
