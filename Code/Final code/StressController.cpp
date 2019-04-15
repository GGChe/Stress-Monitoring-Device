/**
 *
 * "Monitoring of stress level"
 * University of Glasgow
 * Supervised by: Bernd Porr
 * By Ahmed Elmogamer, Daewon Jung and Gabriel Galeote Checa
 *
 * Official project location:
 * https://github.com/GGChe/Stress_Controller_Device
 *
 * Open Readme for details about the project
 *
 * -----------------------------------------------------------------
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/

#include "VEML6030rpi.h"
#include <wiringPiI2C.h>
#include "Fir1.h"
#include "CppTimer.h"
#include <fstream>
#include <array>
#include <time.h>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <softTone.h>

//////// INITIALIZATION OF VARIABLES

#define PIN 7 // GPIO for the buzzer

double ctr = 0;
int tbpm, pbpm;
int stat = 0;
int ipulse = 0;
double pulse[300] = {0};
double mpulse = 0;
int statpulse = 0;
int pd = 0;
int tempbpm = 80;
VEML6030rpi veml6030;
double  runctr, restctr, runT, restT;
int iuserrest, iuserrun, iuserstress, isession, iconfig, beg, configstat;
int configstep = 1;
int configd = 0;
string status, username, myexit, session, config;
int sessionbpm[10] = {80};
Fir1 fir("coeffnoise.dat", 801);
bool userfound = false;
int play = 0;
int cnt = 1;

//new profile or existing profile
ifstream statustxt;
string statusfname = "/var/www/html/Project/status.txt";
//current user in use
ifstream usernametxt;
string usernamefname = "/var/www/html/Project/username.txt";
//Data of every user
fstream userstxt;
string usersfname = "/var/www/html/Project/userdata.txt";
//exit to main menu
ifstream exittxt;
string exitfname = "/var/www/html/Project/exit.txt";
//session of checking for stress
ifstream sessiontxt;
string sessionfname = "/var/www/html/Project/session.txt";
//configuration process
ifstream configtxt;
string configfname = "/var/www/html/Project/config.txt";
//output of sensor
//Maybe Remove
ofstream whitetxt;
string whitefname = "/var/www/html/Project/white.txt";
//log of events
ofstream eventlogtxt;
string eventlogfname = "/var/www/html/Project/eventlog.txt";

/**
 * alarm Function
 * This code is used for the alarm. To avoid the repetition of the same beep without stop, we include a
 * counter inside of the function to limit the beeping.
 *
 **/

void init(){
  // initialize buzer
  wiringPiSetup ();
  softToneCreate (PIN);

  //Sensor
  //initialize sensor
  veml6030.init(0x48);
  veml6030.powerSaving(0x0000);

  //Filter
  fir.reset ();

  configstat = 1;
  restctr = 0;
  runctr = 0;
  runT = 0;
  restT = 0;
  configstep = 1;

}

void alarm(){
  	int i=1;
	wiringPiSetup ();
	softToneCreate (PIN);
			softToneWrite (PIN, 700);
			delay(200);
			softToneWrite (PIN, 0);
				/*
	while (i<1000){
		if(i%500==0){
			softToneWrite (PIN, 700);
			softToneWrite (PIN, 0);
		}
		i++;
	}
	* */
  }

class ObtainData : public CppTimer {
  void timerEvent() {
    //add code to test for stress
    veml6030.white = veml6030.getWhite();

    if((session == "1") || (config == "1") || (config == "2")){
      //filter input
    double iw = fir.filter((double)veml6030.white) * 10000;


      if(ipulse > 280){
      ctr = 0;
      ipulse = 0;
    }

      if(iw >0){
      pulse[ipulse] = iw;     //assign detected peak to an array
      ipulse++;               //increase the counter of the detected peak array
      statpulse = 1;          //state in which we have detected a pulse
      ctr++;
    }

      if(iw < 0){
      ipulse = 0;
      if (statpulse == 1){
        mpulse = *max_element(pulse, pulse + 299) ;       //since pulse detection has detected a zero, we can now assign the maximum value of the array to a value
        statpulse = 0;          //reset stat value
        if(pd == 1){
          //second pulse detected
          //calculate BPM
          tbpm = 60.0*(200.0/ctr);

          if(tbpm >= 50 && tbpm <= 170){
            pbpm = tbpm;
                  cout << pbpm << endl;
                  
             if(session == "1"){
      //add the new bpm to the current bpm array
      for(int i = 0; i < 9; i++){
        sessionbpm[i] = sessionbpm[i + 1];
      }
      sessionbpm[9] = pbpm;
      int tempstress = 0;

      for(int j = 0; j < 9; j++){
        //finds an sum of the difference between bpms
        tempstress = abs(sessionbpm[j] - sessionbpm[j+1]) + tempstress;
      }

      tempstress = tempstress / 9;
      time_t my_time = time(NULL);
      if(tempstress <= iuserstress){
        //record the username, stress average and date of the event
        alarm();
	eventlogtxt << username << "-----" << tempstress << "-----" << ctime(&my_time) << endl;
	eventlogtxt.close();
      }
    }
    else if(configstep == 3){
      configstep = 1;
      configstat = 0;
    }
    else if((config == "1") && (configstep == 2)){
      //calculate run
            runctr++;
      runT = runT +  abs(tempbpm - pbpm); //get the total of the bpms during rest configuration period
      tempbpm = pbpm;
      configstep = 3;
    }
    else if((config == "1") && (configstep == 1)){
      restctr++;
      //calculate rest
      restT = restT + abs(tempbpm - pbpm); //get the total of the bpms during rest configuration period
      tempbpm = pbpm;
      configstep = 2;
      runctr = 0;
    }

          }

          //reseting variables
          mpulse = 0;
          ctr = 0;
        }
      }
      else
      {
        ctr++;    //increase the counter otherwise
      }
    }

      if(mpulse > 50000){
      ctr++; //incrementing pointer
      pd = 1; //comparison pulse detected mode
    }

      if(ipulse > 280){
        ctr = 0;
        ipulse = 0;
      }

      if(iw >0){
        pulse[ipulse] = iw;     //assign detected peak to an array
        ipulse++;               //increase the counter of the detected peak array
        statpulse = 1;          //state in which we have detected a pulse
        ctr++;
      }

      if(iw < 0){
        ipulse = 0;
        if (statpulse == 1){
          mpulse = *max_element(pulse, pulse + 299) ;       //since pulse detection has detected a zero, we can now assign the maximum value of the array to a value
          statpulse = 0;          //reset stat value
          if(pd == 1){
            //second pulse detected
            //calculate BPM
            tbpm = 60.0*(200.0/ctr);

            if(tbpm >= 50 && tbpm <= 170){
              pbpm = tbpm;
              cout<<pbpm<<endl;
            }

            //reseting variables
            mpulse = 0;
            ctr = 0;
          }
        }
        else
        {
          ctr++;    //increase the counter otherwise
        }
      }

      if(mpulse > 50000){
        ctr++; //incrementing pointer
        pd = 1; //comparison pulse detected mode
      }

    }

   
  }
};



int main(void){
  //Timer
  ObtainData Odata;
  init();
  Odata.start(5000000);

  //main function loop
  while(1){
    //cout << configstep << endl;
    if(cnt>1000000){ // we stablish a counter to manage until when are we are going to read the file

      // opening files
      statustxt.open(statusfname.c_str());
      usernametxt.open(usernamefname.c_str());
      exittxt.open(exitfname.c_str());
      sessiontxt.open(sessionfname.c_str());
      configtxt.open(configfname.c_str());

      // extracting data from the files
      statustxt >> status;
      usernametxt>>username;
      exittxt>>myexit;
      sessiontxt>>session;
      configtxt>>config;

      //close all the files after reading.
      statustxt.close();
      usernametxt.close();
      exittxt.close();
      sessiontxt.close();
      configtxt.close();
      
      /** Firstly, we need to check whether status is 0, 1 or 2.
       *  Then, if status is equals to 0, we are in the main webpage.
       *  if status is equals to 1, we are logged but the user already exists to we don't need to calibrate
       *  if status is equals to 2, we need to signup and calibrate. Another case must be considered for this condition.
       **/


      if(status == "0"){

         if(configstat == 0){
           //cout<<configstat<<endl;
           cout<<restctr<<"  "<<runctr<<"  "<<runT<<"  "<<restT<<endl;
            iuserrest = restT / (restctr - 1.0);
            iuserrun = runT / (runctr - 1.0);
         	  //calculate stress here
             // stress average level is approximated to be half of the user's average of stress and run
             iuserstress = (iuserrest + iuserrun)/4;
         	  //write to end of users.txt
         	  userstxt.open(usersfname.c_str());
             cout << username << "/" << iuserrest << "/" << iuserrun << "/" << iuserstress << endl;
         	  userstxt << username << "/" << iuserrest << "/" << iuserrun << "/" << iuserstress << endl;
         	  userstxt.close();
             configstat = 1;
             restctr = 0;
             runctr = 0;
             runT = 0;
             restT = 0;
         }


       }
      // Second Case
      if(status == "1"){//Existing Profile

	string content;
	while (getline(userstxt, content))
	  {
	    if(content.find(username) != std::string::npos){
	      userfound=true; 
	      int sizef = username.size();
	      iuserrest = stoi(content.substr((sizef+1), 2));
	      iuserrun = stoi(content.substr((sizef+4), 2));
	      iuserstress = stoi(content.substr((sizef+7), 2));
	      break;
	    }
	  }


	//reset to main menu

      }


      cnt=0;
    }
    else {
      cnt++;
    }
  }
}
