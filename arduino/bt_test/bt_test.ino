#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

int blueTx = 2; //Tx (보내는핀 설정)
int blueRx = 3; //Rx (받는핀 설정)
SoftwareSerial Bt(2, 3);  //시리얼 통신을 위한 객체선언

int a=4, b=5, c=6, d=7;

void setup()
{
  Serial.begin(9600);   //시리얼모니터
  Bt.begin(9600); //블루투스 시리얼
  Serial.println("Hello");

  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
}
void loop()
{
  if (Bt.available()) {
    Serial.write(Bt.read());  //블루투스측 내용을 시리얼모니터에 출력
  }
  if (Serial.available()) {
    Bt.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
  }

  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  delay(3000);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  delay(1000);
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  delay(3000);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  delay(1000);
}
