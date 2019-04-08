#include "VEML6030rpi.h"
#include <wiringPiI2C.h>

int main(void)
{
    uint16_t lux;
    float resolution ;

    VEML6030rpi veml6030;
    //initialize sensor
    veml6030.initVEML(0x48);
    veml6030.powerSaving(0x0000);
    resolution = veml6030.AutoRange();

    printf("=== VEML6030 RPI test ===\n") ;
    printf("Lux, White\n") ;
    veml6030.start(1000000);
    while(1){
      sleep(100);
    }


}
