#!/usr/bin/python

import serial
import re
#from serial import serial

ser = serial.Serial('/dev/cu.usbmodem1411', 38400) 

#ser.write("<ID01><PA> \r\n") 
while 1:    
    line = ser.readline()
    print(line)
    numList = re.findall('\d+', str(line))
    if len(numList) > 0:
        number = numList[0]
        print(int(number))
        if(int(number) == 500):
            print("equal")

    # ser.write('a'.encode())
    ser.write('c'.encode())
    ser.write('e'.encode())

#read_chars = ser.read(20)
#print(read_chars)

ser.close()

