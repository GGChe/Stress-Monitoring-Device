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
