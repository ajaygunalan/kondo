import serial #for Serial communication
import time   #for delay functions
import struct

servo_value_int = [5600, 7500, 8000, 11000]
write_value = []
alist = []

arduino = serial.Serial('/dev/ttyACM0',9600, timeout=1) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 secounds for the communication to get established


def int_into_byte_array (alist):
	convert_as_string = [str(item) for item in alist]
	append_endline_charac = [item+'\n' for item in convert_as_string]
	temp =[]
	for item in append_endline_charac:            
		temp.append(bytes(item, 'utf-8') )
	return temp


def read_from_arduino ()
	a = arduino.read()
	a += arduino.read()
	return int.from_bytes(a, byteorder='little')



write_value = int_into_byte_array(servo_value_int)


while 1:
	for item in write_value:
		arduino.write(item)
		time.sleep(1) 	