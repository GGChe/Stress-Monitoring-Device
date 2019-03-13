#include <iostream>
#include <lightSensor_h>

void lightSensor::initSensor() {
	lightSensor mySensor;
	mySensor.PowerOn();
	cout << "initSensor" << endl;
	int lux = 0;
}

void lightSensor::requestData() {
	lux = mySensor.GetLux();
	cout << "requestData/t"<< lux << endl;

}

void lightSensor::filterData() {

	cout << "filterData" << endl;

}