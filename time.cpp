#include <iostream>
#include "time.h"
#include <math.h>
#include <stdio.h>

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




int main(){

  std::cout << minutesSinceMidnight ({1, 30}) << "\n";
  std::cout << minutesUntil( {10, 30}, {13, 40} ) << "\n";
// ==> should return 190 minutes


return 0;
}