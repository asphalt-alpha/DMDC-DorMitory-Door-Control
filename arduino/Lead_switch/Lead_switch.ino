#include <SoftwareSerial.h>

#define ADDR 0x10

SoftwareSerial BT(2, 3); // TX, RX
SoftwareSerial RF(4, 5); // TX, RX

int leadSW = 6;
unsigned char RF_rx[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  RF.begin(9600);

  pinMode(leadSW,INPUT_PULLUP);
}

void loop() {
  if(RF.available()){
    Serial.print("MJ447RTX : ");
    int idx=0;
    int len = RF.readBytes(RF_rx,4);
    /*
    while(RF.available()){
      RF_rx[idx++] = RF.read();
      Serial.write(RF_rx[idx-1]);
    }*/
    Serial.println(" ");
    for(int i=0; i<4; i++){
      Serial.write(RF_rx[i]);  
    }
    Serial.println(" ");  
  }
   
  if(BT.available()){
    
  }

}
