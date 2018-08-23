#include "RL_FND.h" //import FND
#include "RL_LEDArray.h" //import LEDArray

FND fnd;
LED led;
const int buzz = 8;
const int trigPin = 5;
const int echoPin = 4;
int dist;
unsigned long warn_prev = 0;
unsigned long dan_prev = 0;
unsigned long current;

void setup() {
  Serial.begin(57600);
  fnd.begin();
  led.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);
  
}

void loop() {
  
  /* get dist from ultrasonic function */
  dist = pingUltra();
  showFND();

  /* Normal Mode */
  if(dist > 1000){
    for(int i=1; i<9; i++){
      led.Off(i);
    }
  }

  
  /* Warning Mode */
  if(dist > 100 && dist < 1000){
    /* reset LED */
    led.AllOff();
    
    /* buzzer beep */
    current = millis();
    if(current - warn_prev >= 1000){
      tone(buzz, 500, 100);
      warn_prev = current;
    }
    
    if(dist > 900 && dist < 1000){
      led.On(1);
    } else if(dist > 800 && dist < 900){
      for(int i=1; i<3; i++){
        led.On(i);
      }
    } else if(dist >700 && dist < 800){
      for(int i=1; i<4; i++){
        led.On(i);
      }
    } else if(dist >600 && dist < 700){
      for(int i=1; i<5; i++){
        led.On(i);
      }
    } else if(dist >500 && dist < 600){
      for(int i=1; i<6; i++){
        led.On(i);
      }
    } else if(dist >400 && dist < 500){
      for(int i=1; i<7; i++){
        led.On(i);
      }
    } else if(dist >300 && dist < 400){
      for(int i=1; i<8; i++){
        led.On(i);
      }
    } else if(dist >200 && dist < 300){
      for(int i=1; i<9; i++){
        led.On(i);
      }
    }
  }


  /* Danger Mode */
  if(dist < 100){
    current = millis();
    if(current - dan_prev >= 500){
      tone(buzz, 500, 100);
    }
    
    /* turn led on for 0.25s */  
    for(int i=1; i<9; i++){
      led.On(i);
    }
    delay(250);
    
    /* turn led off for 0.25s */
    for(int i=1; i<9; i++){
      led.Off(i);
    }
    delay(250);
    
    dan_prev = current;
  }
  
  Serial.println(dist);
  delay(100);
  
}

/* display on FND */
void showFND() {
  byte tmp;
  tmp = dist/1000;
  fnd.setNum(1, tmp);
  tmp = dist%1000/100;
  fnd.setNum(2, tmp);
  tmp = dist%1100/10;
  fnd.setNum(3, tmp);
  tmp = dist%1110;
  fnd.setNum(4, tmp);
}

// pingUltra: return the distance in mm from the ultrasonic sensor
int pingUltra(){
  // clear triiger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  // pull trigger high for 10 us (starts measurement)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // find pulse length and calc distance
  int distance = pulseIn(echoPin, HIGH, 30000) / 2 /2.91;
  
  return (distance);
}
