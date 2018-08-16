# Arduino
Simple experiments on arduino

### Libraries
* RL_RGBLED.h
* RL_LEDArray.h
* RL_FND.h

##### LDR_LEDArray
* Detect room light
* Turn on LEDArray bulbs from 1-8 under dim environment
* Turn off LEDArray bulbs from 8-1 under bright environment

##### LDR_RGB
* Detect room light
* Turn RGB to purple under bright envrionment
* Turn RGB to torquoise under dim envrionment

##### PIR_FND_RGB
* Detect heat change (incoming object) using PIR sensor + interruption
* Count the number of interruption
* Turn RGB from red (idle) to blue (interrupted) for 0.5s
