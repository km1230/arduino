# Arduino
Simple experiments on arduino

### Libraries
* RL_RGBLED.h
* RL_LEDArray.h
* RL_FND.h

#

##### LDR_LEDArray (ATMega2560)
* Detect room light
* Turn on LEDArray bulbs from 1-8 under dim environment
* Turn off LEDArray bulbs from 8-1 under bright environment

##### LDR_RGB (ATMega2560)
* Detect room light
* Turn RGB to purple under bright envrionment
* Turn RGB to torquoise under dim envrionment

##### PIR_FND_RGB (ATMega2560)
* Detect heat change (incoming object) using PIR sensor + interruption
* Count the number of interruption
* Turn RGB from red (idle) to blue (interrupted) for 0.5s

##### UltrasonicAlarm (ATMega2560)
* Detect incoming objects using Ultrasonic sensor
* within 100-1000mm: buzzer beeps every second & turns LEDArray on (1 for every 100mm)
* closer than 100mm: buzzer beeps and LEDArray blinks every 0.5seconds

##### LightAlarm (ATMega2560)
* Detect light using LDR sensor
* Brightness < 400: RGBLED blinks on red
* Brightness > 400: RGBLED on green
