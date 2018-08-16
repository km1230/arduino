#include "RL_RGBLED.h" //import RGB library

RGBLED rgbled; //create RGB object
const byte ldr = A0; //A0 pin for LDR

void setup(){
  rgbled.begin();
  pinMode(ldr, INPUT);
}

void loop(){
  int lightValue = 1024 - analogRead(ldr);
  if(lightValue > 500){
    rgbled.OnRgb(50,0,50);
  } else {
    rgbled.OnRgb(127,127,127);
  }
}

