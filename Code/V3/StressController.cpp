#include "VEML6030rpi.h"
#include <wiringPiI2C.h>
#include "Fir1.h"
#include "CppTimer.h"
#include <fstream>
#include <array>
#include <time.h>
#include <string>

  VEML6030rpi veml6030;
  string username;
  int iuserrest, iuserrun, iuserstress, isession, iconfig, beg;
  Fir1 fir("coeffnoise.dat");
  //new profile or existing profile
  ifstream statustxt ("status.txt");
  //current user in use
  ifstream usernametxt ("username.txt");
  //Data of every user
  fstream userstxt ("users.txt");
  //exit to main menu
  ifstream exittxt ("exit.txt");
  //session of checking for stress
  ifstream sessiontxt ("session.txt");
  //configuration process
  ifstream configtxt ("config.txt");
  //output of sensor
  //Maybe Remove
  ofstream whitetxt ("white.txt");
  //log of events
  ofstream eventlogtxt ("eventlog.txt", ios::app);


class ObtainData : public CppTimer {

  void timerEvent() {
    if(beg == 0){
     beg++;
     sleep(3);}
    //add code to test for stress
    veml6030.als = veml6030.getALS();
    veml6030.white = veml6030.getWhite();
    //cout<<veml6030.als<<"   "<<veml6030.white<<endl;

    if(isession == 1){
      //Detect stress
      veml6030.als = fir.filter(veml6030.als);
      veml6030.white = fir.filter(veml6030.white);

      cout<<veml6030.als<<"   "<<veml6030.white<<endl;

      int tempstress = 10;

      time_t my_time = time(NULL);
      if(tempstress <= iuserstress){
      eventlogtxt << username << "-----" << tempstress << "-----" << ctime(&my_time) << endl;
      eventlogtxt.close();
    }}
    else if(iconfig == 1){
      //calculate rest
      veml6030.als = fir.filter(veml6030.als);
      veml6030.white = fir.filter(veml6030.white);

      cout<<veml6030.als<<"   "<<veml6030.white<<endl;
      iuserrest = 99;
    }
    else if(iconfig == 2){
      //calculate run
      veml6030.als = fir.filter(veml6030.als);
      veml6030.white = fir.filter(veml6030.white);

      cout<<veml6030.als<<"   "<<veml6030.white<<endl;
      iuserrun = 99;
    }


  }

};

int main(void){
  //Sensor
  //initialize sensor
  veml6030.init(0x48);
  veml6030.powerSaving(0x0000);
  cout << "Initialized Sensor" << endl;

  //Filter
  fir.reset ();
  int taps;
  taps = fir.getTaps();

  //text files
  string login ,userfull, userrest, userrun, userstress, status, exit, session, config;
  int statusint, iexit;
  //Deciding the process
  statustxt.is_open();

  //session
  sessiontxt.is_open();

  //exit to main menu
  exittxt.is_open();

  //current username used
  usernametxt.is_open();

  //Folder to output readings
  whitetxt.is_open();

  //user's Data
  userstxt.is_open();

  //config
  configtxt.is_open();

  //Event Log
  eventlogtxt.is_open();
    cout << "loop entered" << endl;

  //Timer
  ObtainData Odata;
    beg = 0;
    Odata.start(5000000);
  
    cout << "Timer started" << endl;

  
  //main function loop
  while(1){

  

  statusint = 0;

  while(statusint == 0){
    //Read for statusint
      statustxt.is_open();
    getline(statustxt, status);
    statusint = stoi(status);
    //cout << statusint<<endl;
        statustxt.close();
            sleep(1);
   // Exit Loop when statusint is not 0
  }
cout <<"left loop" <<endl;
  if(statusint == 1){//Existing Profile
    //getting username
  getline(usernametxt, username);
    //assigning variables
  while (getline (userstxt, userfull)){
      int sizef = username.size();
      if(username == (userfull.substr(0,sizef))){
        userrest = username.substr((sizef+1), 2);
        iuserrest = stoi(userrest);
        userrun = username.substr((sizef+4), 2);
        iuserrun = stoi(userrun);
        userstress = username.substr((sizef+7), 2);
        iuserstress = stoi(userstress);
        break;
      }
      else{
        cout << "Username not Found"<<endl;
      }
    }

  getline(exittxt, exit);
  iexit = stoi(exit);

  while(iexit == 0){
  getline(sessiontxt, session);
  getline(exittxt, exit);
  isession = stoi(session);
  iexit = stoi(exit);

  if((isession == 1) && (iexit == 0)){
    //start session timer function


  //keeping session alive
  while(isession == 1){
    getline(sessiontxt, session);
    isession = stoi(session);
  }
  }
  }

  //reset to main menu
  statusint = 0;

  }
  else if(statusint == 2){//New Profile
    //getting username
    getline(usernametxt, username);

    getline(configtxt, config);
    iconfig = stoi(config);
    //maybe add exit here?
    //read until iconfig becomes 1
    while(iconfig == 0){
      getline(configtxt, config);
      iconfig = stoi(config);
    }

    getline(configtxt, config);
    iconfig = stoi(config);
    //maybe add exit here?
    //read until iconfig becomes 1
    while(iconfig == 0){
      getline(configtxt, config);
      iconfig = stoi(config);
    }

    //calculate stress here
    iuserstress = 99;

    //write to end of users.txt
    userstxt << username << "/" << iuserrest << "/" << iuserrun << "/" << iuserstress << endl;
    userstxt.close();

    //reset to main menu
    statusint = 0;

  }
  else{//error occured
    cout<<"Error Reading the configuration mode"<<endl;
  }


  }

  userstxt.close();
  sessiontxt.close();
  configtxt.close();
  exittxt.close();
  statustxt.close();
  whitetxt.close();
  usernametxt.close();
}
