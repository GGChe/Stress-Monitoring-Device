#include "VEML6030rpi.h"
#include <wiringPiI2C.h>
#include <math.h>
#include <fstream>
#include <string>
#include "Iir.h"
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


VEML6030rpi::VEML6030rpi(){

}
void VEML6030rpi::initFilter(void){
  const float samplingrate = 100000; // Hz
  const float center = 5; // Hz
  const float width = 4.5;
  const float cutoff = 1;
  f.setup(samplingrate, center, width);
  //f.setup (samplingrate, cutoff);
  f.reset();
}
void VEML6030rpi::initbpm(void){
  thd = 0;

}
void VEML6030rpi::initVEML(uint8_t ADR){
  myfile.open ("white.txt");
  initFilter();
  initbpm();
  fd = wiringPiI2CSetup(0x48);
  if(fd <0){
  cout<<"set up failed"<<endl;}
  uint8_t dByteW[3] = {0x00, 0x00, 0x00};
  writeVEML(dByteW, 3);
}
void VEML6030rpi::bpm(void){
  if(lux > thd){
    tbpm = 60*((ctr)/100000);
    //cout<<lux <<endl;
    if(tbpm >= 50 && tbpm <= 170){
      pbpm = tbpm;
      ctr = 0;
      cout<<"BPM: "<<pbpm<<endl;
    }
    else
    {
      ctr++;
    }
  }
  else{
    ctr++;
  }
}
void VEML6030rpi::avgBpm(void){

}
void VEML6030rpi::timerEvent(void){
    als = getALS();
    white = getWhite();

    als = f.filter(als);
    lux = (float)als*resolution;
    white = f.filter(white);
    whitelux = (float)white*resolution;

    bpm();

    cout<<als<<"   "<<white<<"   "<<whitelux<<endl;
    myfile<<white<<" "<<endl;
}
void VEML6030rpi::setALS(uint16_t cmd){
  uint8_t dByteW[3];
  dByteW[0] = ALS_CONF ;
  dByteW[1] = cmd & 0xFF ;
  dByteW[2] = (cmd >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
void VEML6030rpi::setALS_WH(uint16_t wh){
  uint8_t dByteW[3];
  dByteW[0] = ALS_WH ;
  dByteW[1] = wh & 0xFF ;
  dByteW[2] = (wh >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
void VEML6030rpi::setALS_WL(uint16_t wl){
  uint8_t dByteW[3];
  dByteW[0] = ALS_WL ;
  dByteW[1] = wl & 0xFF ;
  dByteW[2] = (wl >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
void VEML6030rpi::powerSaving(uint16_t ps){
  uint8_t dByteW[3];
  dByteW[0] = PWR_SVG ;
  dByteW[1] = ps & 0xFF ;
  dByteW[2] = (ps >> 8) & 0xFF ;
  writeVEML(dByteW, 3) ;
}
uint16_t VEML6030rpi::getALS(void){
  uint16_t als = 0 ;
  uint8_t cmd = ALS_CMD ;
  uint8_t dByteRA[2];
  readVEML(cmd, dByteRA, 2) ;
  //cout<<"dbyter"<<(int)dByteR[0]<<"     "<<(int)cmd<<"     "<<endl;
  als = (dByteRA[1] << 8) | dByteRA[0] ;
  return ( als ) ;
}
uint16_t VEML6030rpi::getWhite(void){
  uint16_t wh = 0 ;
  uint8_t cmd = WHITE_CMD ;
  uint8_t dByteR[2];
  readVEML(cmd, dByteR, 2) ;
  wh = (dByteR[1] << 8) | dByteR[0] ;
  return ( wh ) ;
}
uint16_t VEML6030rpi::getALS_INT(void){
  uint16_t als_int = 0 ;
  uint8_t cmd = ALS_INT ;
  uint8_t dByteR[2];
  readVEML(cmd, dByteR, 2) ;
  als_int = (dByteR[1] << 8) | dByteR[0] ;
  return ( als_int ) ;
}
uint8_t VEML6030rpi::SetIntTime(uint16_t TimeBits){
  uint8_t cmd = ALS_CONF;
  uint8_t dByteR[2];
  dByteR[0] = 0x00;
  dByteR[1] = 0x00;
  readVEML(cmd, dByteR, 2) ; //Update global config value
  uint8_t dByteW[3];
  //cout<<(int)TimeBits<<endl;
  dByteW[0] = ALS_CONF;
  dByteW[1] = (TimeBits & 0xFF) | dByteR[0];
  dByteW[2] = ((TimeBits >> 8) & 0xFF) | dByteR[1];
	writeVEML(dByteW , 3);
}
uint8_t VEML6030rpi::SetGain(uint16_t GainVal){
  uint8_t cmd = ALS_CONF;
  uint8_t dByteR[2];
  readVEML(cmd, dByteR, 2) ; //Update global config value
  uint8_t dByteW[3];
  dByteW[0] = ALS_CONF;
  dByteW[1] = (GainVal & 0xFF) | dByteR[0];
  dByteW[2] = ((GainVal >> 8) & 0xFF) | dByteR[1];
	writeVEML(dByteW , 3);
}
unsigned int VEML6030rpi::IntTime2Bits(unsigned int Time){
	uint8_t X2X1 = (int)(log(Time/100)/log(2));
	uint8_t X4X3 = (int)(((Time % 100) / 25) + 2*(Time % 50)/25);
	return ((X4X3 << 2) | (X2X1)) << 6;
}
uint16_t VEML6030rpi::Gain2Bits(float GainVal){
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
uint8_t VEML6030rpi::Shutdown(void){ //Places device in shutdown low power mode
  uint8_t dByteR[2];
  uint8_t cmd = ALS_CONF;
  readVEML(cmd, dByteR, 2) ;
  uint8_t dByteW[3];
  dByteW[0] = cmd;
  dByteW[1] = dByteR[0] | 0x01;
  dByteW[2] = dByteR[1] | 0x00;
  writeVEML(dByteW , 3);  //Update global config value
}
uint8_t VEML6030rpi::PowerOn(void){ //Turns device on from shutdown mode
  uint8_t dByteR[2];
  uint8_t cmd = ALS_CONF;
  readVEML(cmd, dByteR, 2) ;
  uint8_t dByteW[3];
  dByteW[0] = cmd;
  dByteW[1] = dByteR[0] & 0xFE;
  dByteW[2] = dByteR[1] & 0xFF;
  writeVEML(dByteW , 3);  //Update global config value
}
float VEML6030rpi::GetResolution(float Gain, float IntTime){//Add non-linear correction!
  float Resolution = (1.8432/((float)IntTime/25.0))*(0.125/Gain);
  //cout<<Gain<<"          "<<IntTime<<endl;
	return Resolution; //Return scaled Lux mesurment
}
float VEML6030rpi::AutoRange(void){
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


  resolution =  GetResolution(Gains[g], Ints[inT]);
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
	resolution = GetResolution(NewGain, NewIntTime);
	//cout<<(int)GainBits<<"             "<<(int)IntBits<<endl;
	//cout<<NewGain<<"             "<<NewIntTime<<endl;
	SetGain(GainBits);
	SetIntTime(IntBits);
  return resolution ;
}
void VEML6030rpi::readVEML(uint8_t addr, uint8_t* dByteR, int len){//Reads from bytes from device
  // open the I2C device (check with "ls -l/ dev/i2c*")
  /*int file = open("/dev/i2c-1",O_RDWR);
  if(file < 0)
  {cout<<"failed to open i2c"<<endl;}
  // tell the kernel which I2C address it is
  if(ioctl(file, I2C_SLAVE, _ADR)<0)
  {cout<<"problem establishing buss access"<<endl;}
  // write byte
  char t[2] = {0x48, addr};
  char taddr[1] = {0x48};
  if(write(file, t, 2) != 2)
    {cout<<"error writing"<<endl;}
  // read bytes
  if(write(file, taddr,1) != 1)
  {cout<<"error writing addr" <<endl;}
  if(read(file, (char *)dByteR, len) != len)
  {cout <<"failed to read"<< endl;}
  else*/

  // write byte
    uint16_t dword=0;
dword = wiringPiI2CReadReg16(fd, addr);
if(dword<0)
{cout<<"error writing"<<endl;}
    dByteR[0] = dword & 0xFF ;
    dByteR[1] = (dword >> 8) & 0xFF ;


  //cout<<"R       "<<(int)addr<<"       "<<(int)dword<<endl;
}
void VEML6030rpi::writeVEML(uint8_t* dByteW, int len){//Writes bytes to device
  // open the I2C device (check with "ls -l/ dev/i2c*")

  //cout<<(int)dByteW[0]<<"     "<<(int)dByteW[1]<<"     "<<(int)dByteW[2]<<endl;
  /*char taddr[1] = {0x48};
  int file = open("/dev/i2c-1",O_RDWR) ;
    if(file < 0)
  {cout<<"failed to open i2c"<<endl;}
  // tell the kernel which I2C address it is
  if(ioctl(file, I2C_SLAVE, _ADR)<0)
    {cout<<"problem establishing buss access"<<endl;}*/
  // write byte
    uint16_t dword = (dByteW[2] << 8) | dByteW[1] ;
    cout<<"W       "<<(int)dByteW[0]<<"           "<<(int)dword<<endl;
  if(wiringPiI2CWriteReg16(fd, dByteW[0], dword)<0)
    {cout<<"error writing"<<endl;}
    dByteW[1] = dword & 0xFF ;
    dByteW[2] = (dword >> 8) & 0xFF ;
}
