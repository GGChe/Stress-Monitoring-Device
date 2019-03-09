#include "VEML6030.h"
#include "wiringPi.h"
#include "wiringPiI2c.h"
#include "wiringPi.c"
#include "wiringPiI2c.c"
#include <cmath>
#include <iostream>
using namespace std;

VEML6030::VEML6030()
// Base library type I2C
{
}


uint8_t VEML6030::begin(uint8_t _ADR) // Initialize library for subsequent pressure measurements
{
	ADR = _ADR;
	int dID = _ADR;// i2c Channel the device is on
  int fd, e, status;
  status = 1;

  //int wiringPiI2CSetup (int devId) ;
  if((fd=wiringPiI2CSetup(dID))<0){
  cout<<"error opening i2c channel"<<endl;
  status = 0;
  }

  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, 0x00))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }

return status;
}

uint8_t VEML6030::Shutdown() //Places device in shutdown low power mode
{
	Config = ReadWord(CONF_CMD); //Update global config value
	return WriteConfig(Config | 0x01); //Set shutdown bit
}

uint8_t VEML6030::PowerOn() //Turns device on from shutdown mode
{
	Config = ReadWord(CONF_CMD); //Update global config value
	return WriteConfig(Config & 0xFFFE); //Clear shutdown bit
}
uint8_t VEML6030::SetIntTime(unsigned int TimeBits)
{
	Config = ReadWord(CONF_CMD); //Update global config value
	return WriteConfig((Config & 0xFC3F) | TimeBits);
}

unsigned int VEML6030::GetIntTime()
{
	Config = ReadWord(CONF_CMD); //Update global config value
	int X2X1 = (Config >> 6) & 0x03;
	int X3 = ReadBit(Config, 8);
	int X4 = ReadBit(Config, 9);
	IntTime = 100*pow(2, X2X1)/pow(2, X3 + X4);  //Do some ugly math to go from bit pattern to value
	return IntTime;
}
float VEML6030::GetGain()
{
	Config = ReadWord(CONF_CMD); //Update global config value
	// Serial.println(Config); //DEBUG!
	int X0 = ReadBit(Config, 11);
	int X1 = ReadBit(Config, 12);
	Gain = pow(2, X0 - 3*X1);
	return Gain;
}
float VEML6030::GetLux()
{	//Add non-linear correction!
	GetGain(); //Update global values
	GetIntTime();
	float Resolution = (1.8432/((float)IntTime/25.0))*(0.125/Gain);
	// Serial.print("TEST = "); //DEBUG!
	// Serial.print(Resolution); //DEBUG!
	// Serial.print(" "); //DEBUG!
	// Serial.print(IntTime); //DEBUG!
	// Serial.print(" "); //DEBUG!
	// Serial.println(Gain); //DEBUG!
	return GetALS()*Resolution; //Return scaled Lux mesurment
}

unsigned int VEML6030::GetALS()
{
	return ReadWord(ALS_CMD);
}

unsigned int VEML6030::GetWhite()
{
	return ReadWord(WHITE_CMD);
}
uint8_t VEML6030::WriteWord(uint8_t Command, unsigned int Data)  //Writes value to 16 bit register
{
  int fd, e, status;
  status = 1;

  if((fd=wiringPiI2CSetup(ADR))<0){
  cout<<"error opening i2c channel"<<endl;
  status = 0;
  }

  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, Command))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }
  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, Data & 0xFF))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }
  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, (Data >> 8) & 0xFF))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }
	return status;
  }

uint8_t VEML6030::WriteConfig(unsigned int NewConfig)
{
  int fd, e, status;
  status = 1;

  if((fd=wiringPiI2CSetup(ADR))<0){
  cout<<"error opening i2c channel"<<endl;
  status = 0;
  }

  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, CONF_CMD))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }
  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, NewConfig & 0xFF))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }
  //int wiringPiI2CWrite (int fd, int data) ;
  if((e=wiringPiI2CWrite(fd, (NewConfig >> 8) & 0xFF))<0){
  cout<<"error writing to slave"<<endl;
  status = 0;
  }

	if(status == 1) {
		Config = NewConfig; //Set global config if write was sucessful
		return 1;
	}
	else return 0; //If write failed, return failure condition
}
int VEML6030::ReadWord(uint8_t Command)  //Send command value, returns entire 16 bit word
{
  int fd, e, status;
  status = 1;
	uint8_t Error = SendCommand(Command);
  if((fd=wiringPiI2CSetup(ADR))<0){
  cout<<"error opening i2c channel"<<endl;
  status = 0;
  }
  uint16_t Bytes = wiringPiI2CRead(ADR);

	if(status == 1) return (Bytes); //If read succeeded, return concatonated value
	else return 0; //Return error if read failed
}
uint8_t VEML6030::ReadBit(unsigned int Data, uint8_t Pos)
{
	return (Data >> Pos) & 0x01;
}
