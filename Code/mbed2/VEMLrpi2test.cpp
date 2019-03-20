#include "VEMLrpi2.h"
#include "wiringPi.h"
#include <iostream>
using namespace std;


int main(void)
{
    uint16_t als, white ;
    
    VEMLrpi2 veml6030;
    veml6030.setALSConf(0x0000) ;
    veml6030.setPowerSaving(0x0000) ;



    printf("Ambient, White\n") ;

    for (int i=0;i<10;i++) {
        als = veml6030.getALS() ;
        white = veml6030.getWHITE() ;
        printf("%6d, %6d\n", als, white) ;
    }
    return 0;+
}
