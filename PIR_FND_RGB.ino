/*Import libraries*/
#include "RL_RGBLED.h" //RGBLED library
#include "RL_FND.h" //FND library

/*create objects*/
FND fnd; //fnd object
RGBLED rgbLed; //rgbLed object

int fndValue; //declare variable for FND value
volatile int detect = 0; //declare volatile flag for interruption

void setup() {
  /*instantiate objects*/
  fnd.begin();
  rgbLed.begin();
  
  fndValue = 0; //set FND value as 0
  fnd.setAllNum(0); //set FND display all 0

  attachInterrupt(0, detection, RISING); //Attach Intteruption
}

void loop() {
  rgbLed.OnRgb(0, 0, 255); //turn on blue light only on RGBLed
  
  /* Response to the interruption from PIR Sensor */
  if(detect == 1){
    rgbLed.OnRgb(255, 0 ,0); //turn on red light only on RGBLed
    
    /* Reset FND value once reach higher than 9999 */
    if(fndValue == 9999){
      fndValue = 0;
    }
    
    fndValue += 1; //Increase FND Value by 1
    detect = 0; //Reset interruption flag  
    delay(500);
  }
  
  displayFND(); //Call displayFND function
}

void detection(){
  detect = 1;
}

void displayFND(){
  /* display on FND */
  byte tmp;
  tmp = fndValue / 1000;
  fnd.setNum(1, tmp); //set the 1st digit
  tmp = fndValue % 1000 / 100;
  fnd.setNum(2, tmp); //set the 2nd digit
  tmp = ((fndValue % 1000) % 100) / 10;
  fnd.setNum(3, tmp); //set the 3rd digit
  tmp = ((fndValue % 1000) % 100) % 10;
  fnd.setNum(4, tmp); //set the last digit
}

