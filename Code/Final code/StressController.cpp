#include "VEML6030rpi.h"
#include <wiringPiI2C.h>
#include "Fir1.h"
#include "CppTimer.h"
#include <fstream>
#include <time.h>
#include <string>

  VEML6030rpi veml6030;
  string username;
  int iuserrest, iuserrun, iuserstress;
  Fir1 fir("coeffnoise.dat");
  //new profile or existing profile
  ifstream statustxt ("/var/www/html/Project/status.txt");
  //current user in use
  ifstream usernametxt ("/var/www/html/Project/username.txt");
  //Data of every user
  ifstream userstxt ("/var/www/html/Project/users.txt");
  //exit to main menu
  ifstream exittxt ("/var/www/html/Project/exit.txt");
  //session of checking for stress
  ifstream sessiontxt ("/var/www/html/Project/session.txt");
  //configuration process
  ofstream configtxt ("/var/www/html/Project/config.txt", ios::app);
  //output of sensor
  ofstream whitetxt ("white.txt");
  //log of events
  ofstream eventlogtxt ("eventlog.txt", ios::app);

class ConfigRunObtainData : public CppTimer {

    void timerEvent() {
      //add code to calculate run
      veml6030.als = veml6030.getALS();
      veml6030.white = veml6030.getWhite();

      veml6030.als = fir.filter(veml6030.als);
      veml6030.white = fir.filter(veml6030.white);

      iuserrun = 99;

    }

  };

class ConfigRestObtainData : public CppTimer {

    void timerEvent() {
      //add code to calculate rest
      veml6030.als = veml6030.getALS();
      veml6030.white = veml6030.getWhite();

      veml6030.als = fir.filter(veml6030.als);
      veml6030.white = fir.filter(veml6030.white);

      iuserrest = 99;

    }

  };

class SessionObtainData : public CppTimer {

  void timerEvent() {
    //add code to test for stress
    veml6030.als = veml6030.getALS();
    veml6030.white = veml6030.getWhite();

    veml6030.als = fir.filter(veml6030.als);
    veml6030.white = fir.filter(veml6030.white);

    cout<<veml6030.als<<"   "<<veml6030.white<<endl;
    whitetxt<<veml6030.white<<" "<<endl;

    int tempstress = 10;

    time_t my_time = time(NULL);
    if(tempstress <= iuserstress){
      configtxt << username << "-----" << tempstress << "-----" << ctime(&my_time) << endl;
      configtxt.close();
    }

  }

};

int main(void){
  //Sensor
  //initialize sensor
  veml6030.init(0x48);
  veml6030.powerSaving(0x0000);

  //Filter
  fir.reset ();
  int taps;
  taps = fir.getTaps();

  //text files
  string login ,userfull, userrest, userrun, userstress, status, exit, session, config;
  int statusint, iexit, isession, iconfig;
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

  //Timer
  SessionObtainData SessionOdata;
  ConfigRunObtainData ConfigRunOdata;
  ConfigRestObtainData ConfigRestOdata;

  //main function loop
  while(1){

  statusint = 0;

  While(statusint == 0){
    //Read for statusint
    getline(statustxt, status);
    statusint = stoi(status);
   // Exit Loop when statusint is not 0
  }

  if(statusint == 1){//Existing Profile
    //getting username
  if(getline(usernametxt, username) == 0){
    cout<<"Reading Failed" <<endl;}
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
  SessionOdata.start(500000);

  //code keeping thread alive
  while(isession == 1){
    sleep(1);
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
    if(getline(usernametxt, username) == 0){
    cout<<"Reading Failed" <<endl;}

    getline(configtxt, config);
    iconfig = stoi(config);
    //maybe add exit here?
    //read until iconfig becomes 1
    while(iconfig == 0){
      getline(configtxt, config);
      iconfig = stoi(config);
    }
    //timer
    ConfigRestOdata.start(500000);
    //sleep for 60 seconds
    sleep(60);

    getline(configtxt, config);
    iconfig = stoi(config);
    //maybe add exit here?
    //read until iconfig becomes 1
    while(iconfig == 0){
      getline(configtxt, config);
      iconfig = stoi(config);
    }
    //timer
    ConfigRunOdata.start(500000);
    //sleep for 60 seconds
    sleep(60);

    //calculate stress here
    iuserstress = 99;

    //write to end of users.txt
    configtxt << username << "/" << iuserrest << "/" << iuserrun << "/" << iuserstress << endl;
    configtxt.close();

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
