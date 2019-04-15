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
int ipulse = 0; //index of detected length array
int statpulse = 0; //indicates that we are in a state of a detected pulse
int pd = 0; //indicates tha pulse is detected and ready for comparison to produce bpm
int tempbpm = 80; //temporary bpm to compare with next detected bpm
/* iuserrest: integer value of user rest
 * iuserrun: integer value of user run
 * iuserstress: integer value of user stress
 * tbpm: temporary bpm use to check if the detected bpm is within 50 and 170
 * pbpm: permanent bpm
 */
int iuserrest, iuserrun, iuserstress, tbpm, pbpm; 
int configstep = 1; //which step of the configuration process
int cnt = 1; //counter to regulate the main while loop
int scale [14] = {659, 659, 0, 659, 0, 523, 659, 0, 784, 0, 0, 0, 392, 0}; //notes for buzzer
int configstat = 1; //status if the calibration is done or not, 0 means done

double restctr = 0; //counter of how many bpms detected at rest
double runctr = 0; //counter of how many bpms detected at run
double runT = 0; //total of differences between bpms during run
double restT = 0; //total of differences between bpms during rest
double ctr = 0; //ctr to determine the difference between pulses
double pulse[300] = {0}; //array to store all the values of the detected pulse
double mpulse = 0; //maximum value in the pulse array
/* duserrest: double of user rest
 * duserrun: double of user run
 * duserstress: double of user stress
 */
double duserrest, duserrun, duserstress;

VEML6030rpi veml6030; //sensor constructor

//string for status, current username used, to exit to main page or not, which session maning main, login or signup, to run the filter during configuration or not
string status, username, myexit, session, config;
//filling up the session bpm array with random values to make the average bpm difference between high
int sessionbpm[20] = {0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
//filter coefficients at 801 taps
Fir1 fir("coeffnoise.dat", 801);
//check if the username in use is found
bool userfound = false;

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

void startalarm(){//Mario theme song at the start of the rpi
  int i;
  wiringPiSetup ();
  softToneCreate (PIN);
  for (i = 0; i < 14; ++i)
    {
      softToneWrite (PIN, scale [i]);
      delay(200);
    }

}

void alarm(){//Alarm Function: Makes a single beep
  int i=1;
	wiringPiSetup ();
	softToneCreate (PIN);
  softToneWrite (PIN, 700);
  delay(200);
  softToneWrite (PIN, 0);
  
  }

void init(){//initializers
  // initialize buzzer
  wiringPiSetup ();
  softToneCreate (PIN);
  startalarm();

  //Sensor
  //initialize sensor
  veml6030.init(0x48);
  veml6030.powerSaving(0x0000);

  //Filter
  fir.reset ();
}

class ObtainData : public CppTimer {
  void timerEvent() {
    //add code to test for stress
    veml6030.white = veml6030.getWhite();

    if((session == "1") || (config == "1") || (config == "2")){
      //filter input
      double iw = fir.filter((double)veml6030.white) * 10000;

      if(ipulse > 280){ // to make sure the counter doesnt exceed pulse maximum array index
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

              if(session == "1"){
                //add the new bpm to the current bpm array
                for(int i = 0; i < 19; i++){
                  sessionbpm[i] = sessionbpm[i + 1];
                }
             
                sessionbpm[19] = pbpm; //assign new bpm value
                int tempstress = 0; 

                for(int j = 0; j < 19; j++){
                  //finds an sum of the difference between bpms
                  tempstress = abs(sessionbpm[j] - sessionbpm[j+1]) + tempstress;
                }

                  tempstress = tempstress / 19;
                  time_t my_time = time(NULL);
                  if(tempstress <= iuserstress){
                    //record the username, stress average and date of the event
                    alarm();
                    eventlogtxt.open(eventlogfname.c_str(), ios::app);
                    eventlogtxt << username << "-----" << tempstress << "-----" << ctime(&my_time) << endl;
                    eventlogtxt.close();
                  }
              }
              else if(configstep == 3){
                configstep = 1;
                configstat = 0;
              }
              else if((config == "1") && (configstep == 2)){
                runctr++;
                //calculate run
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
              }

            }

            //reseting variables
            mpulse = 0;
            ctr = 0;
          }
        }
        else {
          ctr++;    //increase the counter otherwise
        }
      }

      if(mpulse > 50000){ //compare the pulse
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
       *  if status is equals to 2, we need to signup and calibrate. 
       **/


      if(status == "0"){

         if(configstat == 0){
            duserrest = restT / (restctr - 1.0);
            duserrun = runT / (runctr - 1.0);
         	  //calculate stress here
            // stress average level is approximated to be half of the user's average of stress and run
            duserstress = (duserrest + duserrun)/4;
            iuserrest = round(duserrest);
            iuserrun = round(duserrun);
            iuserstress = round(duserstress);
         	  //write to end of users.txt
         	  userstxt.open(usersfname.c_str(), ios::app);
         	  userstxt << username << "/" << iuserrest << "/" << iuserrun << "/" << iuserstress << endl;
         	  userstxt.close();
            //reseting values
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
              //retrieving user's data
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
