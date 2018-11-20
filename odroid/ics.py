#!/usr/bin/env/python
import serial
import time
import struct
import array
import numpy

com = serial.Serial()
com.port = '/dev/ttySAC0'
com.baudrate = 115200
com.bytesize = 8
com.parity =serial.PARITY_EVEN
com.stopbits =1
com.timeout = 0.1
com.open()
buf  = bytearray(3)
temp_ = bytearray(2)
target_angle = 7500
angle = 0.0 

a_ = 270.0/8000.0
b_ = -135.0 - a_*3500.0



while 1:
    
	buff[0] = 0x80
	buff[1] = (target_angle >> 7) & 0x7f
	buff[2] = target_angle & 0x7f
	come.write(buf)
	buf_read = com.read(6)
	if(len(buf_read)==6):
		temp_[0] = ord(buf_read[4])
		temp_[1] = ord(buf_read[5])
		val = temp_[1](temp_[0] << 7)
		print "%d" %(val)


