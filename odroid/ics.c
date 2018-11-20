#include <wiringSerial.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>

#define PIN_NUMBER 0
#define enHigh  digitalWrite(PIN_NUMBER, HIGH);
#define enLow   digitalWrite(PIN_NUMBER, LOW);

uint8_t buf[3];
unsigned int target_angle = 3500;
unsigned int incomingByte[6];
uint8_t id = 0;

int main(int argc, char ** argv) {
        int fd = serialOpen("/dev/ttySAC0", 115200);

        while (1) {
         
                buf[0] = 0x80 + id;                         //command + servoID
                buf[1] = ((target_angle >> 7) & 0x007F);    //POS_H
                buf[2] = (target_angle& 0x007F);            //POS_L

                enHigh
                serialPuts(fd, buf);
             

                while (serialDataAvail(fd)) {
                        for (int n=0; n<6; n++){
                            incomingByte[n] = serialGetchar(fd);
                        } 
                }
                enLow 
                delay(1);
        }
}



    


