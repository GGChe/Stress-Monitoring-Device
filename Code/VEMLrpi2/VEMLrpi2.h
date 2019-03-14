#ifndef VEMLrpi2_h
#define VEMLrpi2_h

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include <stdio.h>
#include <iostream>
using namespace std;


/**
 * Vishay VEMLrpi2
 * High Accuracy Ambient Light Sensor with I2C Interface
 */
 /*
 * @code
* @endcode
*/
class VEMLrpi2
{
public:
  /**
  * VEMLrpi2 constructor
  *
  * @param sda SDA pin
  * @param sdl SCL pin
  * @param addr addr of the I2C peripheral
  */
VEMLrpi2();

void setALSConf(uint16_t conf) ;
void setALS_WH(uint16_t wh) ;
void setALS_WL(uint16_t wl) ;
void setPowerSaving(uint16_t ps) ;
uint16_t getALS(void) ;
uint16_t getWHITE(void) ;
uint16_t getALS_INT(void) ;

private:
  void readRegs(int addr, uint8_t * data, int len);
  void writeRegs(uint8_t * data, int len);

};
#endif /* _VEMLrpi2_H_ */
