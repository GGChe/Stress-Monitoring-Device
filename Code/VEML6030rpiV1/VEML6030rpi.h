#ifndef VEML6030rpi_h
#define VEML6030rpi_h

#include "Iir.h"
#include <unistd.h>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include "CppTimer.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class VEML6030rpi : public CppTimer{
  public:
    VEML6030rpi();
    void initbpm(void);
    void initFilter(void);
    uint16_t als,white;
    void bpm(void);
    void avgBpm(void);
    void initVEML(uint8_t _ADR );
    void setALS(uint16_t cmd);
    void setALS_WH(uint16_t wh);
    void setALS_WL(uint16_t wl);
    void powerSaving(uint16_t ps);
    uint16_t getALS(void);
    uint16_t getWhite(void);
    uint16_t getALS_INT(void);
    uint8_t SetIntTime(uint16_t TimeBits);
    uint8_t SetGain(uint16_t GainVal);
    unsigned int IntTime2Bits(unsigned int Time);
    uint16_t Gain2Bits(float GainVal);
    uint8_t Shutdown(void);
    uint8_t PowerOn(void);
    float GetResolution(float Gain, float IntTime);
    float AutoRange(void);
    virtual void timerEvent(void);
    ofstream myfile;
  private:
    Iir::Butterworth::HighPass<4> f;
    float resolution, lux, thd, whitelux;
    float ctr = 0;
    int fd, tbpm, pbpm;
    void readVEML(uint8_t addr, uint8_t* dByteR, int len);
    void writeVEML(uint8_t* dByteW , int len);

};
#endif
