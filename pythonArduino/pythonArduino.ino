
unsigned int data, integerValue = 0; // Max value is 65535
char incomingByte, outgoingByte[5];



int read_from_python(){
    if (Serial.available() > 0) {              // something came across serial
    integerValue = 0;                          // throw away previous integerValue
      while (1) {                                // force into a loop until 'n' is received
        incomingByte = Serial.read();
        if (incomingByte == '\n') break;         // exit the while(1), we're done receiving
        if (incomingByte == -1) continue;        // if no characters are in the buffer read() returns -1
        integerValue *= 10;                      // shift left 1 decimal place
      
        // convert ASCII to integer, add, and shift left 1 decimal place
        integerValue = ((incomingByte - 48) + integerValue);
      }
      return integerValue;
      Serial.flush();
    }
  }

void write_to_python(int a){
  int myVal = a;
  byte payload[2];
  payload[0] = highByte(myVal);
  payload[1] = lowByte(myVal);

  Serial.write(payload[0]);
  Serial.write(payload[1]); 
}

void setup()
{
  Serial.begin(9600);
}

