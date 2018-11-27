#ifndef H_Edge_H
#define H_Edge_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

class Edge{
	public:
		//string depCity;
		string destCity;
		int depTime;
	        int arrTime;
		float cost;
                int timeNum(string time);

                Edge(string destCity,string depTime, string arrTime, string cost);

};

Edge::Edge(string destCity,string depTime, string arrTime, string cost){
    this->destCity = destCity;
    this->depTime = timeNum(depTime);
    this->arrTime = timeNum(arrTime);
    cost>>this->cost; 
}

int Edge::timeNum(string time){
    int timeNum=0;
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
    return timeNum;
}

#endif
