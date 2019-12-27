#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    10
#define LED_COUNT 8

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  pinMode(MISO,OUTPUT);
  pinMode(MOSI,INPUT);
  pinMode(SCK,INPUT);
  pinMode(SS,INPUT);

  SPCR |= _BV(SPE);   // SPI 활성화, 0x40
  SPCR &= ~_BV(MSTR); // Slave 모드 선택, 
  SPCR |= _BV(SPIE);  // 인터럽트 허용

  SPI.setClockDivider(SPI_CLOCK_DIV16);

  Serial.begin(9600);
}

ISR (SPI_STC_vect)
{
  SPDR = count;  // 카운터 값을 ASCII 값으로 전달
}

void loop() {
  // put your main code here, to run repeatedly:

}
