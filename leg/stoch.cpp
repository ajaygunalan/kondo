#include "stoch.h"
#include <IcsHardSerialClass.h>



//extern const byte EN_PIN = 2;
//extern const long BAUDRATE = 115200;
//extern const int TIMEOUT = 1000; 
//
//unsigned int start_pos[1], end_pos[1]; // Hip => 1 & Knee => 0
//extern IcsHardSerialClass krs(&Serial,EN_PIN,BAUDRATE,TIMEOUT); 

void set_pos (int id, unsigned int angle){

  switch(id){

    case 0:
    if (angle >= KNEE_MIN && angle <= KNEE_MAX)
        Serial.println(krs.setPos(0, angle));
    else
        Serial.println("commanded angle exceeds  the joint limit of knee");
    break;

    case 1:
      
      if (angle >= HIP_MIN && angle <= HIP_MAX)
        Serial.println(krs.setPos(1, angle));
    else
        Serial.println("commanded angle exceeds the joint limit of hip");
      break;

      default:
        Serial.println("ID is wrong");
  }
}

void single_traj_write (int id, unsigned int  start_pos, unsigned int end_pos){
  
  for(int commanded_pos =  start_pos; commanded_pos <= end_pos; commanded_pos + STEP_SIZE){
    set_pos(id, commanded_pos);
    delay(DELAY);
  }

  for(int commanded_pos =  end_pos; commanded_pos <= start_pos; commanded_pos - STEP_SIZE){
    set_pos(id, commanded_pos);
    delay(DELAY);
  }
}
