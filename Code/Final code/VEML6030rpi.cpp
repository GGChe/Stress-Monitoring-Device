/**
 *
 * "Library to use VEML6030 light sensor with RPI"
 * University of Glasgow
 * Supervised by: Bernd Porr
 * By Ahmed Elmogamer, Daewon Jung and Gabriel Galeote Checa
 *
 *
 * Has been further developed from and inspired by:
 *  for mbed microcontroller: https://os.mbed.com/teams/MSS/code/VEML6030/
 *  for Arduino, Bobby Schulz @ Northern Widget LLC: https://github.com/NorthernWidget/VEML6030
 *
 *
 * Official project location:
 * https://github.com/GGChe/Stress_Controller_Device
 *
 * Open Readme for details about the project
 *
 * -----------------------------------------------------------------
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/

#include "VEML6030rpi.h"
#include <wiringPiI2C.h>
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

//Registers
#define _ADR        0x48
#define ALS_CONF  	0x00
#define ALS_WH      0x01
#define ALS_WL      0x02
#define PWR_SVG     0x03
#define ALS_CMD     0x04
#define WHITE_CMD   0x05
#define ALS_INT     0x06

//Integration Times bit masks
#define IT25  0x300  //25ms
#define IT50  0x200  //50ms
#define IT100 0x000 //100ms
#define IT200 0x040 //200ms
#define IT400 0x080 //400ms
#define IT800 0x0C0 //800ms

//Gains
#define GAIN_1 0x0000 //Gain x1
#define GAIN_2 0x0800 //Gain x2
#define GAIN_1_8 0x1000 //Gain x1/8
#define GAIN_1_4 0x1800 //Gain x1/4

VEML6030rpi::VEML6030rpi(){

}
VEML6030rpi::~VEML6030rpi(){
}
void VEML6030rpi::init(uint8_t ADR){
  //Setting up I2C
  I2CRW = wiringPiI2CSetup(0x48);
  if(I2CRW <0){
  cout<<"set up failed"<<endl;}

  //Writing to Register 00 0x0000
  uint8_t dByteW[3] = {0x00, 0x00, 0x00};
  writeVEML(dByteW, 3);
}
void VEML6030rpi::setALS(uint16_t cmd){
  //Data Byte Write
  uint8_t dByteW[3];
  //Register
  dByteW[0] = ALS_CONF ;
  //command to be written to the register
  dByteW[1] = cmd & 0xFF ;
  dByteW[2] = (cmd >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
void VEML6030rpi::setALS_WH(uint16_t wh){
  //Data Byte Write
  uint8_t dByteW[3];
  //Register
  dByteW[0] = ALS_WH ;
  //command to be written to the register
  dByteW[1] = wh & 0xFF ;
  dByteW[2] = (wh >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
void VEML6030rpi::setALS_WL(uint16_t wl){
  //Data Byte Write
  uint8_t dByteW[3];
  //Register
  dByteW[0] = ALS_WL ;
  //command to be written to the register
  dByteW[1] = wl & 0xFF ;
  dByteW[2] = (wl >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
uint8_t VEML6030rpi::SetIntTime(uint16_t TimeBits){
  //Register
  uint8_t cmd = ALS_CONF;
  //Data Byte Read
  uint8_t dByteR[2];
  //Update global config value
  readVEML(cmd, dByteR, 2) ;
  //Data Byte Write
  uint8_t dByteW[3];
  //cout<<(int)TimeBits<<endl;
  dByteW[0] = ALS_CONF;
  //command to be written to the register
  dByteW[1] = (TimeBits & 0xFF) | dByteR[0];
  dByteW[2] = ((TimeBits >> 8) & 0xFF) | dByteR[1];
	writeVEML(dByteW , 3);
}
uint8_t VEML6030rpi::SetGain(uint16_t GainVal){
  //Register
  uint8_t cmd = ALS_CONF;
  //Data Byte Read
  uint8_t dByteR[2];
  //Update global config value
  readVEML(cmd, dByteR, 2) ;
  //Data Byte Write
  uint8_t dByteW[3];
  dByteW[0] = ALS_CONF;
  //command to be written to the register
  dByteW[1] = (GainVal & 0xFF) | dByteR[0];
  dByteW[2] = ((GainVal >> 8) & 0xFF) | dByteR[1];
	writeVEML(dByteW , 3);
}
uint16_t VEML6030rpi::getALS(void){
  uint16_t als = 0 ;
  //Register
  uint8_t cmd = ALS_CMD ;
  //Data Byte Read
  uint8_t dByteR[2];
  readVEML(cmd, dByteR, 2) ;
  als = (dByteR[1] << 8) | dByteR[0] ;
  return ( als ) ;
}
uint16_t VEML6030rpi::getWhite(void){
  uint16_t wh = 0 ;
  //Register
  uint8_t cmd = WHITE_CMD ;
  //Data Byte Read
  uint8_t dByteR[2];
  readVEML(cmd, dByteR, 2) ;
  wh = (dByteR[1] << 8) | dByteR[0] ;
  return ( wh ) ;
}
uint16_t VEML6030rpi::getALS_INT(void){
  uint16_t als_int = 0 ;
  //Register
  uint8_t cmd = ALS_INT ;
  //Data Byte Read
  uint8_t dByteR[2];
  readVEML(cmd, dByteR, 2) ;
  als_int = (dByteR[1] << 8) | dByteR[0] ;
  return ( als_int ) ;
}
unsigned int VEML6030rpi::IntTime2Bits(unsigned int Time){
  //Calculations of bits to change from int to bits
	uint8_t X2X1 = (int)(log(Time/100)/log(2));
	uint8_t X4X3 = (int)(((Time % 100) / 25) + 2*(Time % 50)/25);
	return ((X4X3 << 2) | (X2X1)) << 6;
}
uint16_t VEML6030rpi::Gain2Bits(float GainVal){
  //Changing of float gain values to bits
  float Gains[4] = {0.125, 0.25, 1, 2};
  unsigned int GainsInBits[4] = {0x1000, 0x1800, 0x0000, 0x0800};
	for(int i = 0; i < 4; i++){  //Use linear search to avoid float math and increase speed
		if(Gains[i] == GainVal){
			return (GainsInBits[i]); //if entries match, return bits
			break;
		}
	}
	return 0x1000; //Return gain of 1/8 if not a valid gain value
}
void VEML6030rpi::powerSaving(uint16_t ps){
  //Data Byte Write
  uint8_t dByteW[3];
  //Register
  dByteW[0] = PWR_SVG ;
  //command to be written to the register
  dByteW[1] = ps & 0xFF ;
  dByteW[2] = (ps >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
uint8_t VEML6030rpi::Shutdown(void){ //Places device in shutdown low power mode
  //Data Byte Read
  uint8_t dByteR[2];
  //Register
  uint8_t cmd = ALS_CONF;
  readVEML(cmd, dByteR, 2) ;
  //Data Byte Write
  uint8_t dByteW[3];
  dByteW[0] = cmd;
  //command to be written to the register
  dByteW[1] = dByteR[0] | 0x01;
  dByteW[2] = dByteR[1] | 0x00;
  writeVEML(dByteW , 3);
}
uint8_t VEML6030rpi::PowerOn(void){ //Turns device on from shutdown mode
  //Data Byte Read
  uint8_t dByteR[2];
  //Register
  uint8_t cmd = ALS_CONF;
  readVEML(cmd, dByteR, 2) ;
  //Data Byte Write
  uint8_t dByteW[3];
  dByteW[0] = cmd;
    //command to be written to the register
  dByteW[1] = dByteR[0] & 0xFE;
  dByteW[2] = dByteR[1] & 0xFF;
  writeVEML(dByteW , 3);
}
void VEML6030rpi::SetResolution(float Gain, float IntTime){//Add non-linear correction!
  resolution = (1.8432/((float)IntTime/25.0))*(0.125/Gain);
}
void VEML6030rpi::AutoSet(void){
  // PowerSaveOff(); //Turn power save off for fastest reading
  unsigned int gainALS = GAIN_1_8 ;
  float Gains[4] = {0.125, 0.25, 1, 2};
  unsigned int intTime = IT25 ;
  float Ints[6] = {25,50, 100, 200, 400, 800};

	SetIntTime(intTime) ; //Set to minimum integration time
	SetGain(gainALS) ; //Set to minmum gain
	PowerOn() ;
  int g = 0;
  int inT = 0;
  uint16_t TestALSB = getALS(); //Get new lux value
  float TestALS = (int)TestALSB;


  SetResolution(Gains[g], Ints[inT]);
  float TestLux = resolution * TestALS;
	unsigned long HighLux = 120796;  //Start at max value
	unsigned int NewIntTime = 25; //Default to min value
	float NewGainHigh = 0.125; //Default to min value
	float NewGainLow = 0.25; //Default to 2nd lowest value
	float NewGain = 0.125; //Default to min value
  int j = 1;

	if(TestLux < 236) {  //If Lux is too small to measure at max values (<1.8432) or in minimum range, simply set to highest gain and integration time
		NewIntTime = 800;
    inT = 5;
		NewGain = 2;
    g = 5;
	}
	else {  //If lux is not outside low range, search for a value
		for(int i = 0; i < 6; i++) {
			if(TestLux < HighLux && TestLux >= HighLux/2.0) {
				NewIntTime = NewIntTime * ceil(pow(2, i));
				break; //breakout of for loop since result is found
			}
			else HighLux = ceil(HighLux/2.0); //If not found, go to next lux range
		}

		if(TestLux < HighLux * 0.0625) NewGain = 2; //If below the lowest max for integration range, set to max gain
		else {  //Otherwise search for a new value
			for(int g = 1; g < 3; g++) {
				if(TestLux < HighLux * (0.125/NewGainHigh) && TestLux >= HighLux * (0.125/NewGainLow)) {
					NewGain = NewGainHigh;
					break; //Break loop once gain is found
				}
				else {
					NewGainHigh = NewGainLow;
					NewGainLow = Gains[j + 1];
				}
			}
		}
	}

	uint16_t GainBits = Gain2Bits(NewGain); //Convert new gain value
	uint16_t IntBits = IntTime2Bits(NewIntTime); //Convert to new integration time
	SetResolution(NewGain, NewIntTime);

	SetGain(GainBits);
	SetIntTime(IntBits);
}
void VEML6030rpi::readVEML(uint8_t addr, uint8_t* dByteR, int len){//Reads from device
    //write byte
    uint16_t dword=0;
    dword = wiringPiI2CReadReg16(I2CRW, addr);
    //Error Checking
    if(dword<0)
    {cout<<"error writing"<<endl;}
    //Upating the pointer
    dByteR[0] = dword & 0xFF ;
    dByteR[1] = (dword >> 8) & 0xFF ;

}
void VEML6030rpi::writeVEML(uint8_t* dByteW, int len){//Writes to device
    //write byte
    uint16_t dword = (dByteW[2] << 8) | dByteW[1] ;
    //Error Checking and Writing
    if(wiringPiI2CWriteReg16(I2CRW, dByteW[0], dword)<0)
    {cout<<"error writing"<<endl;}
    //Updating the pointer
    dByteW[1] = dword & 0xFF ;
    dByteW[2] = (dword >> 8) & 0xFF ;
}
