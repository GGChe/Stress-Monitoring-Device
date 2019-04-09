## Welcome to FreeStressGame's open source Project!

Our tream provides an open-source real time embedded project based on the development of a real time biomedical device which aim is to monitor the stress level of a videogame player. This project is open source and anyone is invited to contribute freely sharing all your tips and modifications

## Table of Contents

* [Introduction](#introduction)
* [Required Components](#required-components)
* [System Manual](#system-manual)
* [Found a Bug](#found-a-bug)
* [Contributing](#contributing)
* [License](#license)


### Introduction


According to the World Health Organisation, mental disorders are a main topic in global health, specially because one in four people in the world will be affected by mental or neurological disorders at some point in their lives. It is estimated that more that 450 million people are currently suffering from such disorders, placing this risk to the top of all the ill-health's causes and disability worldwide. The main mental disorder is depression, and in many situations it is caused by stress. Nowadays, stress is a risk that every person need to face in some point of the day, like work, house, friends, etc. 

There is evidence available that supports the fact that the stress is one of the main triggers of depression. More in detail , such evidence shows that depression can stem from chronic overstimulation of the body's hypothalamic-pituitary-adrenal axis, which produces cortisol in humans. However, while adults can face the stress with therapy and different skills, children are a very enthreaten sector of the population that does not own skills against that. 

With the mentioned before, we can imagine that one of the most risky situations for a child are videogames where we set an unprepared person against a stressfull and addictive situation, causing severe damage on the child. 

Then, this project constitutes a reliable and attractive solution for parents, therapists and adults that want to monitor and control the stress status of the player.

### Required Components 
The device consists of the next components:
- Raspberry Pi 3 B+
- PCB adaptor: 
  * 2 X 2Kohm SMD resistors
- Wrist sensor:
  * VEML6030 Light sensor 
  * LED
  * 1 X 1 Kohm SMD resistor 
  * 1 X 10 Kohm SMD resistor
  * 1 X 1000 nF SMD capasitor 
- Piezo Buzzer
- RJ45 Cable
- Band type case for Wrist sensor
- Raspberry Pi case 

All circuit schematics / PCB Eagle files/ 3D Solidworks files are included in UPLOADED DOCUMENTS. 

### System Manual 
#### 1. Installation

To deploy and starts working with this device, we need to follow some steps. 

#### [Hardware setting] 

![OUTLINE](https://user-images.githubusercontent.com/46483800/55642991-ea275500-57c9-11e9-9a85-fb307a86195a.JPG)<img width="3" height="3"></img>
![pin outline](https://user-images.githubusercontent.com/46483800/55650311-3b8d0f80-57dd-11e9-888e-57d0e911ed39.JPG)
* Connect PCB adaptor with Wrist sensor by RJ45 cable
* Connect PCB adaptor pins with Raspberry Pi pins as shown in below table 

|PCB adaptor | Raspberry Pi| 
------------|-------------
|    1      |     1 (3.3V)|
|    3      |     3 (SDA) |
|    5      |     5 (SCL) |
|    39     |     39 (GND)|

* Connect Piezo Buzzer pins with Raspberry Pi pins as shown in below table 

|Piezo Buzzer | Raspberry Pi| 
------------|-------------
| Positive (+) |     11 (GPIO 17)|
| Negative (-) |     14 (GND) |

#### [Software setting] 



#### 2. Make a Profile 
<p align="center">
  <img width="550" height="350" src="https://user-images.githubusercontent.com/46483800/55652907-cb828780-57e4-11e9-9571-8c4e7ec287e8.JPG">
</p>

#### 3. Use Case 




### Found a bug?

If you think you've found a bug and  you're confident it's a new bug, and have confirmed that someone else is facing the same issue, go ahead and create a new GitHub issue. Be sure to include as much information as possible so we can reproduce the sbug.


### Contributing



### License


