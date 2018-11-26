#include <IcsHardSerialClass.h>

#define END_POS_1 11300
#define END_POS_2 6900

#define START_POS_1  8800
#define START_POS_2  5900

#define RANGE_1 2500
#define RANGE_2 1000

#define DELTA_1 25
#define DELTA_2 10

#define DELAY 10 //ms

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 1000;    
IcsHardSerialClass krs(&Serial,EN_PIN,BAUDRATE,TIMEOUT);  

void setup() {
  // put your setup code here, to run once:
  krs.begin(); 
}

void read_encoder(){
  int a, b;
  Serial.println("value of 1");
  a = krs.getPos(1);
  Serial.println(a);

  Serial.println("value of 2");
  b = krs.getPos(2);
  Serial.println(b);
}


unsigned int set_one, set_two;

void loop() {
  
  for(int i = 0; i < 1000; i++){

        //Start to End
        for (set_one = START_POS_1, set_two = START_POS_2; set_one <= END_POS_1 && set_two <= END_POS_2; set_one = set_one + DELTA_1, set_two = set_two + DELTA_2) {
          krs.setPos(1, set_one);
          krs.setPos(2, set_two);
          delay(DELAY); 
        }
    
        //End to Start
        for (set_one = END_POS_1, set_two = END_POS_2; set_one >= START_POS_1 && set_two >= START_POS_2; set_one = set_one - DELTA_1, set_two = set_two - DELTA_2) {
           krs.setPos(1, set_one);
           krs.setPos(2, set_two);
          delay(DELAY); 
        }
  }
}
