#include <iostream>
#include ¨retrieveData.h¨
#include <VEML6030_h>


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