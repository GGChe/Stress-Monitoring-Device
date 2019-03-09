#include "retrieveData.h"
#include "Buzzer.h"
#include "incidentRecording.h"
#include <iostream>
using namespace std;

int main()
{
  lightSensor Ls;
  Buzzer Bz;
  incidentRecord Ir;

  Ls.initSensor();
  Ls.requestData();

  Bz.stressAlarm();

  Ir.logIncident();

  return 0;
}
