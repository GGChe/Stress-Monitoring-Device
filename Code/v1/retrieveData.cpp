#include <iostream>
using namespace std;
#include "retrieveData.h"
#include "VEML6030.h"



int main() {
VEML6030 mySensor;
	int lux = 0;
	lux = mySensor.GetLux();
	cout << "requestData/t"<< lux << endl;
	return 0;
}

void retrieveData::initSensor() {
	
	
}

void retrieveData::requestData() {
	

}

void retrieveData::filterData() {

	cout << "filterData" << endl;

}