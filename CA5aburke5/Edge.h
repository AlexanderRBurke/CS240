#ifndef H_Edge_H
#define H_Edge_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Edge{
        public:
                string depCity;
                string destCity;
                int depTime;
                int arrTime;
                float cost;
                int timeNum (string time) const;
                string timeString (int time) const;
                friend ostream& operator<<(ostream& out, const Edge& e);
                bool operator < (const Edge& e) const;

                Edge(string depCity, string destCity,string depTime, string arrTime, string cost);

};

Edge::Edge(string depCity, string destCity,string depTime, string arrTime, string cost){
        this->depCity = depCity;
        this->destCity = destCity;
        this->depTime = timeNum(depTime);
        this->arrTime = timeNum(arrTime);
        this->cost= stof(cost.substr(1)); 
}
ostream& operator<<(ostream& out, const Edge& e){
        cout << fixed << showpoint;
        cout << setprecision(2);
        out<<e.depCity<<" "<<e.destCity<<" "<<e.timeString(e.depTime)<<" "
                <<e.timeString(e.arrTime)<<" $"<< e.cost;

        return out;
}

int Edge::timeNum(string time)const{
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

string Edge::timeString(int time) const{
        //cout<<"\ntime: "<<time<<endl;
        string retStr= "";
        int tempInt = time%100;
        string tempStr = to_string(tempInt);
        time/=100;
        string m ="";
        if(time>12){
                retStr +="0"+to_string(time-12)+":";
                m+="pm";
        }else if(time<10){
                retStr+="0"+to_string(time)+":";
        }
        else{
                retStr+=to_string(time)+":";
        }
        if(tempInt<10){
                retStr+="0"+tempStr;
        }else{retStr+=tempStr;}

        if(time==12){
                retStr+="pm";
        }else if(m=="pm"){
                retStr+=m;
        }else{ retStr+="am";}

        return retStr;
}

bool Edge::operator < (const Edge& e) const{
  return (arrTime<e.arrTime);
}
#endif
