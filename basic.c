#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
  int serial_port ;
  char dat;
  if ((serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0)  /* open serial port */
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }

  if (wiringPiSetup () == -1)         /* initializes wiringPi setup */
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }

  // while(1){
    
  // if(serialDataAvail (serial_port) )
  // { 
  //   dat = serialGetchar (serial_port);    /* receive character serially*/ 
  //   printf ("%c", dat) ;
  //   fflush (stdout) ;
  //   serialPutchar(serial_port, dat);    /* transmit character serially on port */
  //     }
  // }

  // pos value ranges from 3500 to 11500. 
  // It becomes special operation only when 0 is put in the position data, and the servo motor weakens. 
  // 7500 is the so-called neutral position.

  int set_pos (unsigned char id, int pos)
    {
    unsigned char tx[3]; 
    unsigned char rx[3];
    int i;

    tx[0] = 0x80 | id;
    tx[1] = (unsigned char)(pos >> 7 & 0x7F);
    tx[2] = (unsgined char)(pos & 0x7F);

  for (i = 0; i < 3; i++)
    {
    serialPutchar (tx[i]); 
    }
  
  for (i = 0; i < 3; i++)
    {
    rx[i] = serialGetchar (); 
    }

  }

}
