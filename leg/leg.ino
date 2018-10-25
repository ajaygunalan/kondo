#include <IcsHardSerialClass.h>
#include "stoch.h"

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 1000; 

IcsHardSerialClass krs(&Serial,EN_PIN,BAUDRATE,TIMEOUT); 

unsigned int start_pos[1]; 
unsigned int end_pos[1];

void setup() {
  krs.begin();
  start_pos[1]= 7000;
  end_pos[1] = 10000;

 }

void loop() {
  single_traj_write (HIP_ID, start_pos[1], end_pos[1]);
}












    // set_angle(HIP_ID, 8000);

//     set_angle(HIP_ID, 11499);
//     set_angle(KNEE_ID, 3499);


//     Serial.println("Hip & Knee");
//     Serial.println(krs.getPos(HIP_ID));
//     Serial.println(krs.getPos(KNEE_ID));


// //   set_angle(HIP_ID, SIT_HIP);
// //   set_angle(KNEE_ID, SIT_KNEE);
// //
// //   delay(1000);
// //
// //   set_angle(HIP_ID, STAND_HIP);
// //   set_angle(KNEE_ID, STAND_KNEE);
