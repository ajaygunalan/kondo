void setup(){
  Serial.begin(115200);
  delay(500);
}
byte buf[3];
unsigned int target_angle = 3500;
int k = 100, incomingByte[6];
byte id = 0;;
const byte enPin = 2;

inline void enHigh(){digitalWrite(enPin, HIGH);}
inline void enLow(){digitalWrite(enPin, LOW);}



void loop(){
    
  buf[0] = 0x80 + id;                       //command + servoID
  buf[1] = ((target_angle >> 7) & 0x007F); //POS_H
  buf[2] = (target_angle& 0x007F);
  //POS_L
  
  Serial.flush();
  enHigh(); 
  Serial.write(buf, 3);
  Serial.flush();
  
  if(Serial.available() > 0) {
    for (int n=0; n<6; n++){
      incomingByte[n] = Serial.read();
      }
    }

  enLow();  //受信切替

  delay(1);
    
  int angle = (incomingByte[4]<<7)|incomingByte[5];
  Serial.print("\n");
  Serial.print(angle);

  Serial.print("\n");
  Serial.print(target_angle);
  
  if(target_angle < 11500) {
    target_angle += k;
  }
  
  else {
    target_angle = 3500; 
  }
  
  
  delay(10);

  
}
