#include "RL_RGBLED.h"

RGBLED rgbled;
const byte ldr=A0;
unsigned long current;
unsigned long prev = 0;

void setup() {
  rgbled.begin();
  pinMode(ldr, INPUT);
  Serial.begin(57600);
}

void loop() {
  int lightValue = 1024 - analogRead(ldr);
  
  /* Normal */
  if(lightValue > 500 && lightValue < 950){
    rgbled.OnRgb(0, 127, 0);
  }
  
  /* Alert */
  if(lightValue < 400){
    current = millis();
    if(current - prev >= 2000){
      rgbled.OnRgb(127, 0, 0);
      delay(750);
      rgbled.off();
      delay(750);
      prev = current;
    }
  }
  
  Serial.println(lightValue);

}
