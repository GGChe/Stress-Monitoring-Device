#ifndef VEML6030rpi_h
#define VEML6030rpi_h

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include <stdio.h>
#include <iostream>
using namespace std;




class VEML6030rpi {
  public:
    VEML6030rpi();
    uint8_t initVEML(uint8_t _ADR);
    void setALS(uint16_t cmd);
    void setALS_WH(uint16_t wh);
    void setALS_WL(uint16_t wl);
    void powerSaving(uint16_t ps);
    uint16_t getALS(void);
    uint16_t getWhite(void);
    uint16_t getALS_INT(void);
    uint8_t SetIntTime(unsigned int TimeBits);
    uint8_t SetGain(unsigned int GainVal);
    unsigned int IntTime2Bits(unsigned int Time);
    unsigned int Gain2Bits(float GainVal);
    uint8_t Shutdown(void);
    uint8_t PowerOn(void);
    float GetResolution(float valALS, float Gain, float IntTime);
    uint8_t AutoRange(void);
  private:
    uint16_t readVEML(uint8_t addr, int len);
    void writeVEML(uint8_t dByte , int len;

};
#endif
