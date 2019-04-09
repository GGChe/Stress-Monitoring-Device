#include <iostream>
using namespace std;

class incidentRecord {

public:
  void logIncident();
private:
  void writeIncident();
};

void incidentRecord::logIncident(){

  cout<<"logIncident"<<endl;
  writeIncident();

}

void incidentRecord::writeIncident(){

  cout<<"writeIncident"<<endl;

}
