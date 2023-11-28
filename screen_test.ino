#include <SoftwareSerial.h>
  
#define rxPin 10
#define txPin 11

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
int8_t Ran1[7] = {0,1,2,3,4,8,16};
float Ran3[7] = {0,0.1,0.2,0.3,0.4,0.8,0.16};

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if (mySerial.available())
  {
    uint8_t buffer[12];
    uint8_t crc=0;
  
    buffer[0] = 65;
    buffer[1] = Ran1[random(7)];
    buffer[2] = 48;
    buffer[3] = 0;
    buffer[4] = random(120,255);
    buffer[5] = 0;
    
    buffer[7] = 1;
    buffer[8] = random(1,255);
    buffer[9] = 0x34;
    buffer[10] = 0;
    buffer[11] = 0;
  
    for(int k=1;k<12;k++)
    {
        if (k!=6) crc^=buffer[k];
    };
    buffer[6]=crc;
  
    mySerial.write(buffer,12);
  }
  
  delay(500);


}
