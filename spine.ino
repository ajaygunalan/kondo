#include <IcsHardSerialClass.h>

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 1000;		

IcsHardSerialClass krs(&Serial,EN_PIN,BAUDRATE,TIMEOUT);  //インスタンス＋ENピン(2番ピン)およびUARTの指定


void setup() {
  // put your setup code here, to run once:
  krs.begin();  
}


void loop() {
  // put your main code here, to run repeatedly:
   
  
    krs.setPos(0,6000);
    delay(1000); 
                 
    krs.setPos(0,6500);
    delay(1000); 
                 
    krs.setPos(0,7000); 
    delay(1000); 

    krs.setPos(0,7500); 
    delay(1000); 

    krs.setPos(0,7000); 
    delay(1000);

    krs.setPos(0,6500);
    delay(1000);

    krs.setPos(0,6000);
    delay(1000); 
}
