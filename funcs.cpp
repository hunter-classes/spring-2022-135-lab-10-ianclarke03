#include <iostream>
#include "funcs.h"
#include "time.h"
#include "timeslot.h"
#include "movie.h"


//Task A
int minutesSinceMidnight(Time time){
  return ((time.h * 60) + (time.m));
}



int minutesUntil(Time earlier, Time later){
  return (((later.h - earlier.h) * 60) + (later.m - earlier.m));
}

//Task B
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


//task C

std::string printMovie(Movie mv){
    std::string g;
    std::string output = "";
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    output = mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";

    return output;
}

std::string getTimeSlot(TimeSlot ts){
    std::string result = "";
    result += printMovie(ts.movie);
    result += " [starts at ";
    result += std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m);
    result += ",";
    result += " ends by "; //ending time is the startime + duration

    Time t1 = {ts.startTime.h, ts.startTime.m};
    Time endTime = addMinutes(t1, ts.movie.duration);
    result += std::to_string(endTime.h) + ":" + std::to_string(endTime.m);
    result += "]";

    return result;


}


//Task D


TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time t1 = {ts.startTime.h, ts.startTime.m};
    TimeSlot newT = {nextMovie, addMinutes(t1, nextMovie.duration)};

    return newT;
}



//Task E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int ts1Start = minutesSinceMidnight(ts1.startTime);
    int ts2Start = minutesSinceMidnight(ts2.startTime);
    int ts1End = ts1Start + ts1.movie.duration;
    int ts2End = ts2Start + ts2.movie.duration;

    if ((ts1Start < ts2Start && ts1End <= ts2Start) || (ts2Start < ts1Start && ts2End <= ts1Start))
    {
        return false;
    }
    return true;
}