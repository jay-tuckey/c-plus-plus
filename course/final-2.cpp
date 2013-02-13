/* Final project 2 */

#include <iostream>
#include <stdexcept>
using namespace std;


class AlarmClock {
public:
  // Only included one constructor, since it does both the jobs that were required in the question
  AlarmClock(int h = 12, int m = 0, int s = 0, bool am = true) {
    setAm(am);
    setHours(h);
    setMins(m);
    setSecs(s);
    
  }

  // Make an operator to allow incrementing the time by one second.
  void operator++(int s) {
    if(secs != 59)
      ++secs;
    else {
      secs = 0;
      if(mins != 59)
	++mins;
      else {
	mins = 0;
	setHours(hours + 1);
      }
    }

    checkAlarm();
  }

  // Check if it is time to set off the alarm
  void checkAlarm() {
    if(!aon)
      return;
    if(hours == ahours && mins == amins && secs == asecs)
      cout << "WAKE UP!!!" << endl;
  }

  void setHours(int h) {
    if(h < 0)
      throw invalid_argument("Can't set the hours to less than 0");
    if(0 == h) {
      hours = 12;
      alternateAm();
    } else if(h < 12) {
      hours = h; 
    } else if(12 == h) {
      hours = h;
      alternateAm();
    } else if(h < 24) {
      hours = h-12;
      alternateAm();
    } else
      throw invalid_argument("Can't set the hour to greater than 24");
    
  }
  
  int getHours() {
    return hours;
  }
  
  void setMins(int m) {
    if(m < 0)
      throw invalid_argument("Can't set the minute to less than 0");
    else if(m < 60) {
      mins = m;
    } else
      throw invalid_argument("Can't set the minute to greater than 59");
  }

  int getMins() {
    return mins;
  }
  
  void setSecs(int s) {
    if(s < 0)
      throw invalid_argument("Can't set the second to less than 0");
    else if(s < 60) {
      secs = s;
    } else
      throw invalid_argument("Can't set the second to greater than 59");
  }

  int getSecs() {
    return secs;
  }

  void setAm(bool am) {
    isam = am;
  }

  bool getAm() {
    return isam;
  }
  
  void alternateAm() {
    if(isam)
      isam = false;
    else
      isam = true;
  }

  void setAlarm(int h, int m, int s, bool am) {
    asetAm(am);
    asetHours(h);
    asetMins(m);
    asetSecs(s);
    aon = true;
  }

  // Now a set of functions for setting up the alarm's time

  void asetHours(int h) {
    if(h < 0)
      throw invalid_argument("Can't set the hours to less than 0");
    if(0 == h) {
      ahours = 12;
      aalternateAm();
    } else if(h < 12) {
      ahours = h;
    } else if(h < 24) {
      ahours = h-12;
      aalternateAm();
    } else
      throw invalid_argument("Can't set the hour to greater than 24");
  }

  void aalternateAm() {
    if(aisam)
      aisam = false;
    else
      aisam = true;
  }

  int agetHours() {
    return ahours;
  }
  
  void asetMins(int m) {
    if(m < 0)
      throw invalid_argument("Can't set the minute to less than 0");
    else if(m < 60) {
      amins = m;
    } else
      throw invalid_argument("Can't set the minute to greater than 59");
  }

  int agetMins() {
    return amins;
  }
  
  void asetSecs(int s) {
    if(s < 0)
      throw invalid_argument("Can't set the second to less than 0");
    else if(s < 60) {
      asecs = s;
    } else
      throw invalid_argument("Can't set the second to greater than 59");
  }

  int agetSecs() {
    return asecs;
  }

  void asetAm(bool am) {
    aisam = am;
  }

  bool agetAm() {
    return aisam;
  }

  void printTime() {
    cout << "Hours:" << hours 
	 << " Mins:" << mins
	 << " Secs:" << secs
	 << " AM:" << isam << endl;
  }
private:
  int hours; // Current time - hours
  int mins; // Current time - minutes
  int secs; // Current time - seconds
  bool isam; // Current time - AM/PM
  bool aon; // Alarm - On/Off
  int ahours; // Alarm - hours
  int amins; // Alarm - minutes
  int asecs; // Alarm - seconds
  bool aisam; // Alarm - AM/PM
}; // End class AlarmClock

int main() {
  AlarmClock a(11, 59, 57, true), b(4, 15, 50, true), c(15) ;
  int counter;

  a.setAlarm(12,1,30,false);
  cout << "Time is: ";
  while(counter != 0) {
    a.printTime();
    cout << "Enter 0 to quit. How much do you want to increment the time by, in seconds? ";
    cin >> counter;
    
    for(int i = 0; i < counter; i++) {
      a++;
    }
  }
  
}
