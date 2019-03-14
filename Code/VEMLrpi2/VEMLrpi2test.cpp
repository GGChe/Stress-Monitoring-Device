#include "VEMLrpi2.h"



int main(void)
{
    uint16_t als, white ;

    veml6030 = new VEMLrpi2() ;
    veml6030->setALSConf(0x0000) ;
    veml6030->setPowerSaving(0x0000) ;


    printf("=== VEML6030 test for %s (%s)===\n", BOARD_NAME, __DATE__) ;
    printf("Ambient, White\n") ;

    while(1) {
        als = veml6030->getALS() ;
        white = veml6030->getWHITE() ;
        printf("%6d, %6d\n", als, white) ;
        wait(1) ;
    }
}
