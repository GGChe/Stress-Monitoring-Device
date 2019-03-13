#include <iostream>
using namespace std;
#include "retrieveData.h"
#include "VEML6030.h"


void retrieveData::initSensor() {
	VEML6030 mySensor;
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