
#include <iostream>
#include "funcs.h"
#include "time.h"
#include "timeslot.h"
#include "movie.h"

int main(){
    //task A
    Time time1 = {10, 32};
    int result1 = minutesSinceMidnight(time1);
    std::cout << "==============TASK A==============" << std::endl;
    std::cout << "Number of minutes from midnight to " << time1.h << ":" << time1.m << " is " << result1 << " MINUTES\n" << std::endl;

    Time timea = {10, 30};
    Time timeb = {13, 40};
    int result2 = minutesUntil(timea, timeb);
    std::cout << "Number of minutes in between " << timea.h << ":" << timea.m << " and " << timeb.h << ":" << timeb.m << " is " << result2 << " MINUTES\n" << std::endl;

    //task B
    Time time0B = {8,10};
    int min1 = 75;
    Time result1B = addMinutes(time0B, min1);
    std::cout << "==============TASK B==============" << std::endl;
    std::cout << "Old Time: " << time0B.h << ":" << time0B.m << " Shift: " << min1 << " minutes" << " New Time: " << result1B.h << ":" << result1B.m << std::endl;
    std::cout << "\n";
    Time time0B2 = {13, 25};
    int min2 = 45;
    Time result2B = addMinutes(time0B2, min2);
    std::cout << "Old Time: " <<time0B2.h << ":" << time0B2.m << " Shift: " << min2 << " minutes" << " New Time: " << result2B.h << ":" << result2B.m << std::endl;
    std::cout << "\n"; 

    //task C

    Movie movie1 = {"Call Me By Your Name", ROMANCE, 132};
    Movie movie2 = {"The Batman", ACTION, 176};
    Movie movie3 = {"Anchorman", COMEDY, 105};
    Movie movie4 = {"House of Gucci", DRAMA, 157};
    Movie movie5 = {"A Star is Born", ROMANCE, 135};
    TimeSlot morning1 = {movie1, {9, 15}};  
    TimeSlot daytime1 = {movie2, {11, 15}}; 
    TimeSlot evening1 = {movie2, {16, 45}};
    TimeSlot morning2 = {movie3, {10, 30}};


    std::cout << "==============TASK C==============" << std::endl;
    std::string result1c = getTimeSlot(morning1);
    std::cout << result1c << std::endl;
    std::cout << "\n";
    std::string result2c = getTimeSlot(daytime1);
    std::cout << result2c << std::endl;
    std::cout << "\n";
    std::string result3c = getTimeSlot(morning2);
    std::cout << result3c << std::endl;
    std::cout << "\n";


    //task D
    std::cout << "==============TASK D==============" << std::endl;
    TimeSlot result1D = scheduleAfter(morning1, movie1);
    std::cout << "The next showing for " << movie1.title << " is at " << result1D.startTime.h << ":" << result1D.startTime.m << std::endl;
    std::cout << "\n";
    TimeSlot result2D = scheduleAfter(daytime1, movie2);
    std::cout << "The next showing for " << movie2.title << " is at " << result2D.startTime.h << ":" << result2D.startTime.m << std::endl;
    std::cout << "\n";


    //task E
    
    std::cout << "==============TASK E==============" << std::endl;
    std::cout << getTimeSlot(morning2) << std::endl;
    std::cout << getTimeSlot(daytime1) << std::endl;
    std::cout << "\nNo Overlap\n";
    std::cout << "----------------------------------" << std::endl;

    std::cout << getTimeSlot(morning1) << std::endl;
    std::cout << getTimeSlot(daytime1) << std::endl;
    std::cout << "\nOverlap\n";


    return 0;
}


