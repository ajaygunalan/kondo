#include <IcsHardSerialClass.h>

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 1000; 


#define HIP_ID 1
#define HIP_MIN 6500
#define HIP_MAX 11500

#define KNEE_ID 0
#define KNEE_MIN 3500
#define KNEE_MAX 8400

#define SIT_HIP 9800
#define SIT_KNEE 5600 

#define STAND_HIP 8100
#define STAND_KNEE 5600 

int temp;
IcsHardSerialClass krs(&Serial,EN_PIN,BAUDRATE,TIMEOUT); 

//int set_angle (int id, int set_angle){
//
//  switch(id){
//
//    case 0:
//    
//    if (set_angle >= KNEE_MIN && set_angle <= KNEE_MAX )
//          temp=krs.setPos(0, set_angle);
//    else
//        Serial.println("commanded angle exceeds  the joint limit of knee");
//
//    case 1:
//      
//      if (set_angle >= HIP_MIN && set_angle <= HIP_MAX )
//        temp= krs.setPos(1, set_angle);
//    else
//        Serial.println("commanded angle exceeds the joint limit of hip");
//  }
// return temp;
//}


void setup() {
  krs.begin();

 }

//int hip_set_angle, knee_set_angle, hip_get_angle, knee_get_angle;

void loop() {

  while(1){
    int set_angle;
    
    krs.setPos(1, 8000);

    for(set_angle = 7000;set_angle <= 10000; set_angle = set_angle + 10 ){
      krs.setPos(HIP_ID, set_angle);
//      delay(1);
    }

    for(set_angle = 10000;set_angle >= 7000; set_angle = set_angle - 10 ){
      krs.setPos(HIP_ID, set_angle);
//      delay(1);
    }
   
    Serial.println("Hip & Knee");
    Serial.println(krs.getPos(HIP_ID));
    Serial.println(krs.getPos(KNEE_ID));
  }
}
    

//    set_angle(HIP_ID, 10000);

//
//    Serial.println("Hip & Knee");
//    Serial.println(krs.getPos(HIP_ID));
//    Serial.println(krs.getPos(KNEE_ID));


//    set_angle(HIP_ID, SIT_HIP);
//    set_angle(KNEE_ID, SIT_KNEE);
//
//    delay(1000);
//
//    set_angle(HIP_ID, STAND_HIP);
//    set_angle(KNEE_ID, STAND_KNEE);
  
