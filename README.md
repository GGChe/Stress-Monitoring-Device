# RealTimeProject
This is the group for the project of Real Time Programming.

Some ideas:

1. Stress control for driving behaviour controller system.

Use a smartwatch or any Heart-Rate monitoring device capable of sending the data via wireless from a driver and, consequently, decide if he is stressed or not (control model). Then, the system can decide how to warn the driver (think about different ways of warning or reduce the stress of the user). 

We can not just measure stress but anxiety from novice drivers or drivers that are not in conditions for driving. That could be a good preventive innitiative to stop the driver BEFORE driving with and initial analysis that can determine whether the driver can turn on the car or not.  

https://ac.els-cdn.com/S0001457518300873/1-s2.0-S0001457518300873-main.pdf?_tid=39d63053-775a-4267-843c-c975b55c2b55&acdnat=1547224018_da29ac5d60597879add915341faf702d

PROS: Easy control system (just a threshold), easy warning (maybe a light).

CONS: connection between devide and raspberry PI.

## System Configuration
  
- SODIAL(R) Pulse Sensor can measure ECG by touching finger. 
 
  ![123234](https://user-images.githubusercontent.com/46483800/51086736-2c4c7780-1742-11e9-94d0-ce5760728c73.JPG)
  
-  The sensor is built in steering wheel like below.

![asdfsadfds](https://user-images.githubusercontent.com/46483800/51086779-b1379100-1742-11e9-9c3c-06a60248d4dc.JPG)

- Another sensor Example:
https://www.sunrom.com/p/heart-beat-sensor-digital-pulse-out

- When driver grabs the part of wheel, the sensor measures ECG. 

- SODIAL(R) Pulse Sensor is connected with A/D converter and this converter sends digital data to Raspberry Pi. 

Useful link : https://tutorials-raspberrypi.com/raspberry-pi-heartbeat-pulse-measuring/

------------------------------------------------

---------16/01/2019----------------------

Possible other applications >> Use the stress controller for videogames.

ADC CONVERTER 16 BITS I2C
https://uk.farnell.com/texas-instruments/ads1110a0idbvt/adc-16bit-240sps-i2c-sot23/dp/1206859?st=16%20bits%20acdc%20conversor

IMPORTANT TIPS:
  We need to find an I2C connection
  The PCB must include robust pluggers (sb9, vga, usb... )
  

-----------------------------------
SOME EXTRA INFO


https://www.instructables.com/id/Streaming-Data-Visualization-Plotly-Raspberry-Pi/

