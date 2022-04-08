#include <iostream>
#include "funcs.h"
#include <math.h>
#include <stdio.h>

class Time { 
public:
    int h;
    int m;
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}