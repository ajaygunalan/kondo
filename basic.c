#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<wiringPi.h>
#include<wiringSerial.h>

int main ()
{
	int serial_port ;
	char dat;

	if ((serial_port = serialOpen ("/dev/ttyS0", 115200)) < 0){  /* open serial port */
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
		return 1 ;
	}

	if (wiringPiSetup () == -1){    /* initializes wiringPi setup */
		fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
		return 1 ;
	}

  

	int set_pos (unsigned char id, int pos){
		unsigned char tx[3]; 
		unsigned char rx[3];
		int i, a, b, c, tem;
		unsigned char d;
		unsigned char data;

		tx[0] = 0x80 | id;
	
		tem = pos;
		a = tem>>7;
		b = a&0X7F;
		d = (unsigned char)(b);
		tx[1] = d;  // tx[1] = (unsigned char)(((pos>>7)&0x7F));

    	
		tx[2] = (unsigned char)((pos&0x7F));


		for (i = 0; i < 3; i++){
			if(serialDataAvail(serial_port)){
				serialPutchar(serial_port, tx[i]);
			}
		}
    	}	

	// 3500 < i << 11500 and 7500 is default neutral postion
        
	
 	for(int a = 3500; a < 11500; a++){
		set_pos(a,7500);
  		dat = serialGetchar (serial_port);
		}

}
