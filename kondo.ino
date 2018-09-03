void setup(){
  Serial.begin(115200, SERIAL_8E1);
  delay(500);
}
byte buf[3];
int target_angle = 3500;
int k = 100, incomingByte[6];

void loop(){
  
  buf[0] = 0b10000000; //servo ID
  buf[1] = (target_angle>>7)&0x7f;
  buf[2] = target_angle&0x7f;
  Serial.write(buf, 3);
  Serial.flush();
  if(Serial.available() > 0) {
    for (int n=0; n<6; n++){
      incomingByte[n] = Serial.read();
      }
    }

  if(target_angle < 11500) {
    target_angle += k;
  }

  
}
