#include <iostream>
using namespace std;

class Buzzer {

public:
  void stressAlarm();
  void emergencyAlarm();
  void Beep();
private:
};

void Buzzer::stressAlarm(){

  cout<<"StressAlarm"<<endl;

}

void Buzzer::emergencyAlarm(){

  cout<<"emergencyAlarm"<<endl;

}

void Buzzer::Beep(){

  cout<<"Beep"<<endl;

}
