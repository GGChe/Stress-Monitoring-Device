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

--------------------------------------------------------------------------------------------------------------------------
2. Diabetes and Driving

Some hypoglucaemia patients have limitations with driving license. They often are forced to give it up because of a dangerous health state. A possible solution for this problem could be a NON-INVASIVE & REUSABLE system with wireless connection that is able to send the data of blood glucose level (also called blood sugar). It should usually be below 4mmol/l. However, we can implement some restrictions to make the system safer.

some info:
https://www.diabetes.org.uk/guide-to-diabetes/life-with-diabetes/driving
http://www.gluco-wise.com/
https://www.semanticscholar.org/paper/Non-Invasive-Glucose-Monitoring-%3A-A-Review-of-and-Lin-Gal/92a479dae8a0aaf97b4a28ad4bf5df5f935c0039

PROS: Realistic project, Easy control system.

CONS: Glucose sensor (how to find the correct one, how to supply energy, how to implement a communication between the raspberry and the system), Only can measure transient blood sugar in blood-gathering method, blood-gathering method is uncomfortable, Expesive sensor price

--------------------------------------------------------------------------------------------------------------------------
3. Driver Attention Lose Control

Honda developed a driver attention monitor that, by using the data of how the driver controls the car on the road, deterine if the driver should take a rest or not. Something similar could be done because in the Honda system, the driver could not be tired but the system insists on taking a rest. A more accurate system could be using electrooculography.

PROS: Very realistic and marketable system, Possibility of connecting the system with wireless connection.

CONS: Difficult connection, difficult settings (2 cameras and we have to calibrate and test the system (big problem with testing, this technique is not very accurate). 

http://www.hiltonheadhonda.com/blog/how-does-the-honda-driver-attention-monitor-work/
https://www.sciencedirect.com/topics/neuroscience/electrooculography

 link: https://www.youtube.com/watch?v=oVxRCUhbAMI
 link: https://www.youtube.com/watch?v=bZnJxowfPF8
       



THIS is what I told you about Zodial Bands https://www.amazon.co.uk/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=sodial+ECG+

-----------------------------------
SOME EXTRA INFO


https://www.instructables.com/id/Streaming-Data-Visualization-Plotly-Raspberry-Pi/

