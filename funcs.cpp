#include <iostream>
#include "funcs.h"
#include <string>
//#include "funcs.h"
#include "time.h"


class Time { 
public:
    int h;
    int m;
};

void printTime(Time time) {
    std::cout << time.h << ":" << time.m;
}


int minutesSinceMidnight(Time time){
  return ((time.h * 60) + (time.m));
}



int minutesUntil(Time earlier, Time later){
  return (((later.h - earlier.h) * 60) + (later.m - earlier.m));
}


Time addMinutes(Time time0, int min){
  int hours = min / 60;
  int mins = min % 60;
  time0.h += hours;
  time0.m += mins;

  if (time0.m > 60){
    time0.m -= 60;
    time0.h += 1;
    }

  Time result = {time0.h, time0.m};
  return result;
    
}





/*
int main(){

  std::cout << minutesSinceMidnight ({1, 30}) << "\n";
  std::cout << minutesUntil( {10, 30}, {13, 40} ) << "\n";
// ==> should return 190 minutes

  addMinutes({8, 10}, 75);
  std::cout << "\n";
// ==> should return {9, 25}

return 0;
}
*/
