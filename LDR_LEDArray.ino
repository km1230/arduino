#include "RL_LEDArray.h"

const unsigned int ldrPin = A0;
LED led;

void setup() {
  pinMode(ldrPin, INPUT);
  led.AllOff();
}

void loop() {
  int lightValue = 1024 - analogRead(ldrPin);
  
  if(lightValue > 500){
    for(int i=0; i<9; i++){
      led.Off(8-i);
      delay(200);
    }
  } else {
    for(int i=0; i<9; i++){
      led.On(i);
      delay(200);
    }
  }  
}
