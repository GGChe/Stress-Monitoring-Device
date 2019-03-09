#include <iostream>
using namespace std;

class lightSensor {

public:
  void initSensor();
  void requestData();
private:
  void filterData();
};

void lightSensor::initSensor(){

  cout<<"initSensor"<<endl;

}

void lightSensor::requestData(){

  cout<<"requestData"<<endl;
  filterData();

}

void lightSensor::filterData(){

  cout<<"filterData"<<endl;

}
