#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

int blueTx = 2; //Tx (보내는핀 설정)
int blueRx = 3; //Rx (받는핀 설정)
SoftwareSerial Bt(2, 3);  //시리얼 통신을 위한 객체선언
int a = 0;
void setup()
{
  Serial.begin(9600);   //시리얼모니터
  Bt.begin(9600); //블루투스 시리얼
  Serial.println("Hello");
}
void loop()
{
  Bt.write(a++);
  delay(1000);
}
