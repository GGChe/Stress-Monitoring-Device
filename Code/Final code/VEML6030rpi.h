#ifndef VEML6030rpi_h
#define VEML6030rpi_h

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <fstream>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class VEML6030rpi {
  public:
    VEML6030rpi();
    virtual ~VEML6030rpi();
    void init(uint8_t _ADR );
    void setALS(uint16_t cmd);
    void setALS_WH(uint16_t wh);
    void setALS_WL(uint16_t wl);
    uint8_t SetIntTime(uint16_t TimeBits);
    uint8_t SetGain(uint16_t GainVal);
    uint16_t getALS(void);
    uint16_t getWhite(void);
    uint16_t getALS_INT(void);
    unsigned int IntTime2Bits(unsigned int Time);
    uint16_t Gain2Bits(float GainVal);
    void powerSaving(uint16_t ps);
    uint8_t Shutdown(void);
    uint8_t PowerOn(void);
    void SetResolution(float Gain, float IntTime);
    void AutoSet(void);
    //variables
    uint16_t als,white;
    float resolution, lux, whitelux;
  private:
    void readVEML(uint8_t addr, uint8_t* dByteR, int len);
    void writeVEML(uint8_t* dByteW , int len);
    //variables
    int I2CRW;
};
#endif
