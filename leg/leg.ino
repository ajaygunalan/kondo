#include <IcsHardSerialClass.h>
#include "stoch.h"

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 1000; 

IcsHardSerialClass krs(&Serial,EN_PIN,BAUDRATE,TIMEOUT); 

unsigned int start_pos[2]; 
unsigned int end_pos[2];


/**********write the pos to a particular servo & check if the value is within the joint limits**********/
void set_pos (byte id, unsigned int angle){
  switch(id){

    case 0:
    if (angle >= KNEE_MIN && angle <= KNEE_MAX) {
      Serial.println("Return Value of Knee");
      Serial.println(krs.setPos(KNEE_ID, angle));
    }
    else
      Serial.println("commanded angle exceeds  the joint limit of knee");
    break;

    case 1:
    int temp;  
    if (angle >= HIP_MIN && angle <= HIP_MAX){
      Serial.println("Return Value of Hip");
      Serial.println(krs.setPos(HIP_ID, angle));
    }
    else
      Serial.println("commanded angle exceeds the joint limit of hip");
      break;

    default:
        Serial.println("ID is wrong");
  }
}

/**********Given a start and end point this will give a bunch of intermediate points**********/
void single_traj_write (byte id, unsigned int  start_pos, unsigned int end_pos){
  for(unsigned int commanded_pos =  start_pos; commanded_pos <= end_pos; commanded_pos = commanded_pos + STEP_SIZE){
    set_pos(id, commanded_pos);
    delay(DELAY);
  }

  for(unsigned int commanded_pos =  end_pos; commanded_pos >= start_pos; commanded_pos = commanded_pos - STEP_SIZE){
    set_pos(id, commanded_pos);
    delay(DELAY);
  }
}

void setup() {
  krs.begin();
  
/**********Set the start and end position of the Knee**********/
//  start_pos[KNEE_ID] = 3400;
//  end_pos[KNEE_ID]= 8300;

/**********Set the start and end position of the Hip**********/
  start_pos[HIP_ID] = 6600;
  end_pos[HIP_ID]= 11000;
 }

void loop() {

//  single_traj_write(KNEE_ID, start_pos[KNEE_ID], end_pos[KNEE_ID]);
  single_traj_write (HIP_ID, start_pos[HIP_ID], end_pos[HIP_ID]);
}
