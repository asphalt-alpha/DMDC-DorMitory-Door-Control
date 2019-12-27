#include <SoftwareSerial.h>

SoftwareSerial rf(3, 2); // TX, RX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  rf.begin(9600);

  Serial.println("Goodnight moon!");

  delay(1000);
  rf.write("Please...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (rf.available())
    Serial.write(rf.read());
 
  // Receive from PC and send it to bluetooth
  if (Serial.available())
    rf.write(Serial.read());
}
