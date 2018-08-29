#!/usr/bin/env/python
import rospy
from geometry_msg.msg import PointStamped
import serial
import time
import struct
import array
import numpy

com = serial.Serial()
com.port = 'dev/ttyUSB0'
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

def callback(data):
	global target angle
	global angle 
	angle = data.point.x
	target_angle = (int)((angle-b_)/a_)

	if (target_angle > 11500):
		target_angle = 11500
	elif (target_angle < 3500):
		target_angle =3500

def data_pub():
	pub = rospy.Publisher('servo_angle', PointStamped, queue_size = 100)
	rospy.Subscriber("master_angle", PointStamped, callback)
	rospy.init_node('servo_node', anonymmous = True)
	r = rospy.Rate(100)
	global target_angle
	global angle
	data_msg = PointStamped();
	while not rospy.is_shutdown():
		data_msg.header.stamp = rospy.get_rostime()
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
			data_msg.point.x =  angle
			data_msg.point.y = (float)(val)*a_ + b_
			pub.publish(data_msg)

			r.sleep()
if __name__ == '__main__':
	try:
		data_pub()
	except rospy.ROSInterruptException: pass