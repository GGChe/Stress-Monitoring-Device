#include <iostream>
using namespace std;
#include "retrieveData.h"
#include "VEML6030.h"
VEML6030 mySensor;

void retrieveData::initSensor() {
	
	mySensor.PowerOn();
	cout << "initSensor" << endl;
	int lux = 0;
}

void retrieveData::requestData() {
	lux = mySensor.GetLux();
	cout << "requestData/t"<< lux << endl;

}

void retrieveData::filterData() {

	cout << "filterData" << endl;

}