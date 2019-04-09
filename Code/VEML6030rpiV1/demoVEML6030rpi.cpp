#include "VEML6030rpi.h"

int main(void)
{
    uint16_t als, white ,lux;
    float resolution ;

    VEML6030rpi.VEML6030rpi veml6030;
    //initialize sensor
    veml6030.initVEML(0x48);
    veml6030.setALS(0x0000) ;
    veml6030.PowerSaving(0x0000) ;
    resolution = veml6030.AutoRange();

    printf("=== VEML6030 RPI test ===\n") ;
    printf("Lux, White\n") ;

    while(1) {
        als = veml6030.getALS() ;
        lux = als*resolution;
        white = veml6030.getWhite() ;
        printf("%6d, %6d\n", lux, white) ;
        wait(1) ;
    }
}
