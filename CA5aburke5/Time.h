#ifndef H_Time_H
#define H_Time_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

class Time{
    public:
        int timeNum;
        //int hour;
        //int minute;
        //bool isAM;
        friend ostream& operator<<(ostream& out, const Time& t);
        Time(string time);
}

Time(string time){
    stringstream sstrm;
    sstrm<<time;
    int hour,min;
    sstrm>>hour;
    sstrm.get();
    sstrm>>min;
    string m;
    sstrm>>m;
    if(m=="pm" && hour !=12)
        timeNum+=1200+hour*100;
    else
        timeNum+= hour*100;
    timeNum+=min;
}

ostream& operator<<(ostream& out, const Time& t){
    
   
    /* if(hour<10)
        out<<"0"<<to_string(hour);
    else{
        out<<to_string(hour);
    }
    if(minute<10)
        out<<"0"<<to_string(minute);
    else{
        out<<to_string(minute);
    }
    if(isAM)
        out<<"am";
    else
        out<<"pm";*/

    return out;	
}

#endif
