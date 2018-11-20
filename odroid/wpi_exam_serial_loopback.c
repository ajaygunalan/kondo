#include <wiringSerial.h>
#include <wiringPi.h>
#include <stdio.h>
 
int main(int argc, char ** argv)
{
        int fd = serialOpen("/dev/ttySAC0", 115200);
        char buf[255];
 
        while (1) {
                printf("Serial Input> ");
                fgets(buf, 255, stdin);
                serialPuts(fd, buf);
                delay(10);
                printf("Serial Output> ");
                while (serialDataAvail(fd))
                        putchar(serialGetchar(fd));
        }
}
