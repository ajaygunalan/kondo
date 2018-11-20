#include <wiringPi.h>
#define PIN_NUMBER 0  

int main(void)
{
    wiringPiSetup();
    pinMode(PIN_NUMBER, OUTPUT);
 
    for (;;)
    {
        digitalWrite(PIN_NUMBER, HIGH); 
        delay(1000);
        digitalWrite(PIN_NUMBER, LOW); 
        delay(1000);
    }
    return 0;
}
