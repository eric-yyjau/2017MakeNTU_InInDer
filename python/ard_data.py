#!/usr/bin/python

import serial
import re
import numpy as np
#from serial import serial

def initialization():
    data_cali = []
    # ser = serial.Serial('/dev/cu.usbmodem1411', 38400) 
    for i in range(10):
        line = ser.readline()
    for i in range(10):
        line = ser.readline()
        num = np.array( re.findall('\d+', str(line)) )
        if len(num) == 6:
            data_cali.append( num )
    data_cali = np.array(data_cali)
    data_cali = data_cali.astype(int)
    # return data_cali
    # print(data_cali[-1])
    return data_cali.mean(axis=0)

def checkAcc(raw_data):
    return True

def checkRot(raw_data):
    return True

def readData(ser, data_cali, data_all):
    line = ser.readline()
    numList = re.findall('\d+', str(line))
    raw_data = np.array(numList)
    raw_data = raw_data.astype(int)
    print(raw_data)
    # print(data)
    return raw_data

def accTest(data):
    thd = 10000
    if data[0] > thd or data[1] > thd:
        return True
    else: 
        return False

def gyroTest(data):
    thd = 1000
    if data[3] > thd or data[4] > thd or data[5] > thd:
        return True
    else: 
        return False


def isFall(data):
    thd = 14000
    if data[2] < -1*thd:
        return True
    else:
        return False

def reset():
    return True


def saveMe():
    return True


switchNum = int(1000000)

#ser.write("<ID01><PA> \r\n") 
ser = serial.Serial('/dev/cu.usbmodem1411', 38400) 
data_cali = initialization()
data_cali = data_cali.astype(int)
print(data_cali)
data_all = []
measure = False
mode = 0
accCount = 0
gyroCount = 0
accResult = False
gyroResult = False
fall = False

for i in range(10000):
    data = readData(ser, data_cali, data_all)
    if len(data) == 6:
        data = data - data_cali
        data_all.append(data)
    elif len(data) == 1:
        if data[0] == switchNum:
            print("switch!")
            if measure == 1:
                reset()
                measure = 0
                print("Off")
            else:
                measure = 1
                print("On")

            

    data = data_all[-1]
    accResult = accTest(data)
    print("acc", accResult)
    gyroResult = accTest(data)
    print("gyro", gyroResult)
    fall = isFall(data)

    if fall:
        saveMe()

    if measure:
        print("measure")
        if accResult:
            accCount = accCount + 1
        if gyroResult:
            gyroCount = gyroCount + 1
        if accResult or gyroResult:
            ser.write('a'.encode())
        else:
            ser.write('c'.encode())
    else:
        ser.write('g'.encode())
    # ser.write('g'.encode())

    '''
    ser.write('c'.encode())
    ser.write('e'.encode())
    '''

#read_chars = ser.read(20)
#print(read_chars)

ser.close()


