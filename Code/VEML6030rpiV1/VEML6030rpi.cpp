#include "VEML6030rpi.h"

#include <iostream>
using namespace std;

#define _ADR        0x48
#define ALS_CONF  	0x00
#define ALS_WH      0x01
#define ALS_WL      0x02
#define PWR_SVG     0x03
#define ALS_CMD     0x04
#define WHITE_CMD   0x05
#define ALS_INT     0x06

//Integration Times bit masks
#define IT25 0x300  //25ms
#define IT50 0x200  //50ms
#define IT100 0x000 //100ms
#define IT200 0x040 //200ms
#define IT400 0x080 //400ms
#define IT800 0x0C0 //800ms

#define GAIN_1 0x0000 //Gain x1
#define GAIN_2 0x0800 //Gain x2
#define GAIN_1_8 0x1000 //Gain x1/8
#define GAIN_1_4 0x1800 //Gain x1/4

//Persistance will define how man consecutive values required to trigger interrupt
#define PER_1 0x00 //Persistance of 1
#define PER_2 0x10 //Persistance of 2
#define PER_4 0x20 //Persistance of 4
#define PER_8 0x30 //Persistance of 8

void VEML6030rpi::VEML6030rpi(){

}
void VEML6030rpi::initVEML(uint8_t ADR){//initializes the sensor
  _ADR = ADR
  uint8_t dByte[3];
  dByte[0] = 0x00 ;
  dByte[1] = 0x00 ;
  dByte[2] = 0x00 ;
  writeVEML(dByte, 3);
}
void VEML6030rpi::setALS(uint16_t cmd){
  uint8_t dByte[3];
  dByte[0] = ALS_CONF ;
  dByte[1] = cmd & 0xFF ;
  dByte[2] = (cmd >> 8) & 0xFF ;
  writeVEML(dByte, 3) ;
}
void VEML6030rpi::setALS_WH(uint16_t wh){
  uint8_t dByte[3];
  dByte[0] = ALS_WH ;
  dByte[1] = wh & 0xFF ;
  dByte[2] = (wh >> 8) & 0xFF ;
  writeVEML(dByte, 3) ;
}
void VEML6030rpi::setALS_WL(uint16_t wl){
  uint8_t dByte[3];
  dByte[0] = ALS_WL ;
  dByte[1] = wl & 0xFF ;
  dByte[2] = (wl >> 8) & 0xFF ;
  writeVEML(dByte, 3) ;
}
void VEML6030rpi::powerSaving(uint16_t ps){
  uint8_t dByte[3];
  dByte[0] = PWR_SVG ;
  dByte[1] = ps & 0xFF ;
  dByte[2] = (ps >> 8) & 0xFF ;
  writeVEML(dByte, 3) ;
}
uint16_t VEML6030rpi::getALS(void){
  uint16_t als = 0 ;
  uint8_t cmd = ALS_CMD ;
  uint8_t dByte[2];
  dByte = readVEML(cmd, 2) ;
  als = (dByte[1] << 8) | dByte[0] ;
  return ( als ) ;
}
uint16_t VEML6030rpi::getWhite(void){
  uint16_t wh = 0 ;
  uint8_t cmd = WHITE_CMD ;
  uint8_t dByte[2];
  dByte = readVEML(cmd, 2) ;
  wh = (dByte[1] << 8) | dByte[0] ;
  return ( wh ) ;
}
uint16_t VEML6030rpi::getALS_INT(void){
  uint16_t als_int = 0 ;
  uint8_t cmd = ALS_INT ;
  uint8_t dByte[2];
  dByte = readVEML(cmd, 2) ;
  als_int = (dByte[1] << 8) | dByte[0] ;
  return ( als_int ) ;
}
uint8_t VEML6030::SetIntTime(unsigned int TimeBits){
	Conf = readVEML(ALS_CONF, 1); //Update global config value
	return writeVEML((Conf & 0xFC3F) | TimeBits , 1);
}
uint8_t VEML6030::SetGain(unsigned int GainVal){
	Conf = readVEML(ALS_CONF, 1); //Update global config value
	return writeVEML((Conf & 0xE7FF) | GainVal , 1);
}
unsigned int VEML6030::IntTime2Bits(unsigned int Time){
	uint8_t X2X1 = (int)(log(Time/100)/log(2));
	uint8_t X4X3 = (int)(((Time % 100) / 25) + 2*(Time % 50)/25);
	return ((X4X3 << 2) | (X2X1)) << 6;
}
unsigned int VEML6030::Gain2Bits(float GainVal){
	for(int i = 0; i < 4; i++) {  //Use linear search to avoid float math and increase speed
		if(GainVals[i] == GainVal) {
			return (i << 11); //if entries match, return bits
		}
	}
	return 0x1000; //Return gain of 1/8 if not a valid gain value
}
uint8_t VEML6030::Shutdown(void){ //Places device in shutdown low power mode
  Conf = readVEML(ALS_CONF, 1); //Update global config value
	return WriteConfig(Conf | 0x01 , 1); //Set shutdown bit
}
uint8_t VEML6030::PowerOn(void){ //Turns device on from shutdown mode
  Conf = readVEML(ALS_CONF, 1); //Update global config value
	return writeVEML(Conf & 0xFFFE , 1); //Clear shutdown bit
}
float VEML6030::GetResolution(float valALS, float Gain, float IntTime){//Add non-linear correction!
	float Resolution = (1.8432/((float)IntTime/25.0))*(0.125/Gain);
	return Resolution; //Return scaled Lux mesurment
}
uint8_t VEML6030rpi::AutoRange(void){
  // PowerSaveOff(); //Turn power save off for fastest reading
  float gainALS = GAIN_1_8 ;
  float intTime = IT25 ;
	SetIntTime(gainALS) ; //Set to minimum integration time
	SetGain(intTime) ; //Set to minmum gain
	PowerOn() ;

	delay(30); //Wait for new sample
	float TestALS = getALS(); //Get new lux value
  float TestLux = GetResolution(TestALS ,gainALS, intTime) * TestALS;
	unsigned long HighLux = 120796;  //Start at max value
	unsigned int NewIntTime = 25; //Default to min value
	float NewGainHigh = 0.125; //Default to min value
	float NewGainLow = 0.25; //Default to 2nd lowest value
	float NewGain = 0.125; //Default to min value

	if(TestLux < 236) {  //If Lux is too small to measure at max values (<1.8432) or in minimum range, simply set to highest gain and integration time
		NewIntTime = 800;
		NewGain = 2;
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
					NewGainLow = GetGain(GainValBits[g + 1]);
				}
			}
		}
	}

	unsigned int GainBits = Gain2Bits(NewGain); //Convert new gain value
	unsigned int IntBits = IntTime2Bits(NewIntTime); //Convert to new integration time

	SetGain(GainBits);
	SetIntTime(IntBits);

  return resolution ;
}
uint16_t VEML6030rpi::readVEML(uint8_t addr, int len){//Reads from bytes from device
  // open the I2C device (check with "ls -l/ dev/i2c*")
  int file = open("/dev/i2c-2",O_RDWR);
  // tell the kernel which I2C address it is
  ioctl(file, I2C_SLAVE, _ADR);
  uint8_t dByte[len];
  // write byte
  write(file, (char *)addr, 1) ;
  // read bytes
  read(file, (char *)dByte, len);
  return dByte;
}
void VEML6030rpi::writeVEML(uint8_t dByte , int len){//Writes bytes to device
  // open the I2C device (check with "ls -l/ dev/i2c*")
  int file = open("/dev/i2c-2",O_RDWR) ;
  // tell the kernel which I2C address it is
  ioctl(file, I2C_SLAVE, _ADR) ;

  // write byte
  write(file, (char *)dByte, len) ;

}
