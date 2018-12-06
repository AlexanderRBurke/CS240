#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map> 
#include <sstream>
#include <fstream>
#include "Node.h"
#include "Edge.h"
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>
//#include "Time.h"


using namespace std;

int timeNum(string time){
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

void anyPath(string depCity, string destCity,map<string,Node> graph){
        Node source=graph[depCity];
        // for(int i=0; i<map.size();i++){
        // if(graph[i]
        //}

        queue <Node*> que;
        //map<string,Node>::iter
        for(unsigned int i=0; i<source.edges.size();i++){ //unsigned??
                // cout<<"i: "<<i<<endl;
                // if(source.edges[i].depTime>depTimeInt){
                Node* nextNode = &graph[source.edges[i].destCity];
                nextNode->pi = &source;
                nextNode->piFlight = &source.edges[i];
                nextNode->visited = 1;
                // cout<<*nextNode<<endl;
                que.push(nextNode);
                //}
        }
        // cout<<source.pi<<endl;
        source.visited=2;
        Node* tempNode = que.front();
        que.pop();
        //       cout<<tempNode->pi<<endl;

        // cout<<graph["LAX"].edges[0]<<endl;
        //cout<<"ATL: "<<graph["ATL"]<<endl;

        // cout<<"before pi loop"<<endl;

        while(tempNode->name!=destCity){
                //while(que.size()!=0 || tempNode->pi==&source){//TODO Fix this
                //   cout<<"Queue size: "<<que.size()<<endl;
                // cout<<"tempNode: "<<*tempNode<<endl;
                for(unsigned int i=0; i<tempNode->edges.size();i++){ //unsigned??
                        Node* nextNode = &graph[tempNode->edges[i].destCity];
                        //       cout<<"nextNode: "<<*nextNode<<endl;
                        if(nextNode->visited==0 && nextNode->pi ==nullptr){
                                nextNode->pi = tempNode;
                                nextNode->piFlight = &tempNode->edges[i];
                                nextNode->visited = 1;
                                que.push(nextNode);
                        }
                }
                tempNode->visited =2;
                if(que.size()!=0){
                        tempNode = que.front();
                        que.pop();
                }
                //cout<<"during pi loop "<<endl;
                //cout<<tempNode.name<<" "<<destCity<<endl;
                // cout<<*tempNode->pi<<endl;
        }

        // cout<<"after pi loop"<<endl;
        //  cout<<*tempNode->pi<<endl;

        tempNode = &graph[destCity];

        vector<Edge> flights;
        if(tempNode->pi!= nullptr){
                while(tempNode->pi!=nullptr){
                        flights.push_back(*tempNode->piFlight);
                        // cout<<tempNode<<endl;
                        tempNode =tempNode->pi;
                        //cout<<"here"<<endl;
                }

                float sum=0;
                for(unsigned int i=flights.size(); i>0;i--){
                        cout<<flights[i-1].depCity<<" "<<flights[i-1].destCity<<endl;
                        sum+=flights[i-1].cost;
                }

        }else{
                cout<<"I'm sorry this trip is impossible."<<endl;
        } 

        map<string,Node>::iterator it = graph.begin();
        while(it != graph.end()){
                Node node =it->second;
                node.visited = 0;
                node.pi = nullptr;
                node.piFlight = nullptr;
                it++;
        }//TODO Test this

        //cout<<"Total cost: "<<sum<<endl;
        //TODO Add return trip     
        }

        void earliestArrival(string depCity, string destCity, map<string,Node> graph, int depTimeInt){
                Node source=graph[depCity];
                source.dist = 0;

                map<string,Node>::iterator it = graph.begin();
                while(it != graph.end()){
                        //               cout<<"ifinite?"<<endl;
                        Node node =it->second;
                        //cout<<node<<endl;
                        vector<Edge> flights = node.edges;
                        sort(flights.begin(), flights.end()); 
                        it++;
                }//TODO Test this

                queue <Node*> que;
                //priority_queue <Node*, vector<Node*>, less<Node*>> que;
                for(unsigned int i=0; i<source.edges.size();i++){ //unsigned??
                        if(source.edges[i].depTime>depTimeInt){
                                Node* nextNode = &graph[source.edges[i].destCity];
                                nextNode->pi = &source;
                                nextNode->piFlight = &source.edges[i];
                                nextNode->visited = 1;
                                nextNode->dist=source.edges[i].arrTime;
                                // cout<<nextNode->pi<<endl;
                                que.push(nextNode);
                        }
                }
                /// cout<<source.pi<<endl;
                source.visited=2;
                // cout<<que.size()<<endl;

                Node* tempNode;
                if(que.size()!=0){
                        tempNode = que.front();
                        //que.pop();
                }
                //while(que.size()>0){
                //while(que.size()!=0 || tempNode->pi==&source){//TODO Fix this
                while(que.size()!=0){//TODO Fix this
                        que.pop();
//                        cout<<"Queue size: "<<que.size()<<endl;
                        //       cout<<"que front: "<<*que.front()<<endl;
                        for(unsigned int i=0; i<tempNode->edges.size();i++){ //unsigned??
                                // cout<<"i: "<<i<<endl;
                                Node* nextNode = &graph[tempNode->edges[i].destCity];
  //                              cout<<(tempNode->edges[i].arrTime)<<endl;
                                if(nextNode->visited==0 && tempNode->piFlight->arrTime<tempNode->edges[i].depTime){
                                        nextNode->pi = tempNode;
                                        nextNode->piFlight = &tempNode->edges[i];
                                        nextNode->visited = 1;
                                        nextNode->dist=tempNode->edges[i].arrTime;
                                        // cout<<"New node: "<<*nextNode<<endl;
                                        que.push(nextNode);
                                }
                                else if(nextNode->visited==1 && tempNode->piFlight->arrTime<tempNode->edges[i].depTime){
    //                                    cout<<(tempNode->edges[i].arrTime)<<endl;
                                        if(tempNode->edges[i].arrTime<nextNode->dist){
                                                nextNode->pi = tempNode;
                                                nextNode->piFlight = &tempNode->edges[i];
                                                nextNode->visited = 1;
                                                nextNode->dist=tempNode->edges[i].arrTime;
                                                //cout<<"New node: "<<*nextNode<<endl;
                                                que.push(nextNode);

                                        } 
                                }
                        }
                        tempNode->visited = 2;
                        if(que.size()!=0){
                                tempNode = que.front();
                                //que.pop();
                        }
                }

      //          cout<<"Destcity: "<<graph[destCity].dist<<endl;
        //        cout<<"Mission: "<<graph["Mission_Viejo"].dist<<endl;
                tempNode = &graph[destCity];
                vector<Edge> flights;
                if(tempNode->pi!= nullptr){
                        while(tempNode->pi!=nullptr){
                                flights.push_back(*tempNode->piFlight);
                                // cout<<tempNode<<endl;
                                tempNode =tempNode->pi;
                                //cout<<"here"<<endl;
                        }

                        float sum=0;
                        for(unsigned int i=flights.size(); i>0;i--){
                                cout<<flights[i-1]<<endl;
                                sum+=flights[i-1].cost;
                        }
                        cout<<"Total cost: $"<<sum<<endl;
                        //TODO Add return trip    
                }else{
                        cout<<"I'm sorry this trip is impossible."<<endl;
                } 
                it = graph.begin();
                while(it != graph.end()){
                        //        cout<<"Infinite?"<<endl;
                        Node node =it->second;
                        node.visited = 0;
                        node.pi = nullptr;
                        node.piFlight = nullptr;
                        node.dist = 0;
                        it++;
                }

        }
        void cheapestPath(string depCity, string destCity, map<string,Node> graph, int depTimeInt){
                Node source=graph[depCity];
                source.dist = 0;

                map<string,Node>::iterator it = graph.begin();
                while(it != graph.end()){
                        //               cout<<"ifinite?"<<endl;
                        Node node =it->second;
                        //cout<<node<<endl;
                        vector<Edge> flights = node.edges;
                        sort(flights.begin(), flights.end()); 
                        it++;
                }

                queue <Node*> que;
                //priority_queue <Node*, vector<Node*>, less<Node*>> que;
                for(unsigned int i=0; i<source.edges.size();i++){ //unsigned??
                        if(source.edges[i].depTime>depTimeInt){
                                Node* nextNode = &graph[source.edges[i].destCity];
                                nextNode->pi = &source;
                                nextNode->piFlight = &source.edges[i];
                                nextNode->visited = 1;
                                nextNode->dist=source.edges[i].arrTime;
                                // cout<<nextNode->pi<<endl;
                                que.push(nextNode);
                        }
                }
                /// cout<<source.pi<<endl;
                source.visited=2;
                // cout<<que.size()<<endl;

                Node* tempNode;
                if(que.size()!=0){
                        tempNode = que.front();
                        //que.pop();
                }
                //while(que.size()>0){
                //while(que.size()!=0 || tempNode->pi==&source){//TODO Fix this
                while(que.size()!=0){//TODO Fix this
                        que.pop();
//                        cout<<"Queue size: "<<que.size()<<endl;
                        //       cout<<"que front: "<<*que.front()<<endl;
                        for(unsigned int i=0; i<tempNode->edges.size();i++){ //unsigned??
                                // cout<<"i: "<<i<<endl;
                                Node* nextNode = &graph[tempNode->edges[i].destCity];
  //                              cout<<(tempNode->edges[i].arrTime)<<endl;
                                if(nextNode->visited==0 && tempNode->piFlight->arrTime<tempNode->edges[i].depTime){
                                        nextNode->pi = tempNode;
                                        nextNode->piFlight = &tempNode->edges[i];
                                        nextNode->visited = 1;
                                        nextNode->dist=tempNode->dist+tempNode->edges[i].cost;
                                        // cout<<"New node: "<<*nextNode<<endl;
                                        que.push(nextNode);
                                }
                                else if(nextNode->visited==1 && tempNode->piFlight->arrTime<tempNode->edges[i].depTime){
    //                                    cout<<(tempNode->edges[i].arrTime)<<endl;
                                        //if(tempNode->edges[i].arrTime<nextNode->dist){
                                        if((nextNode->dist)>(tempNode->dist+tempNode->edges[i].cost)){
                                                nextNode->pi = tempNode;
                                                nextNode->piFlight = &tempNode->edges[i];
                                                nextNode->visited = 1;
                                                nextNode->dist=tempNode->dist+tempNode->edges[i].cost;
                                                //cout<<"New node: "<<*nextNode<<endl;
                                                que.push(nextNode);

                                        } 
                                }
                        }
                        tempNode->visited = 2;
                        if(que.size()!=0){
                                tempNode = que.front();
                                //que.pop();
                        }
                }

                //          cout<<"Destcity: "<<graph[destCity].dist<<endl;
                //        cout<<"Mission: "<<graph["Mission_Viejo"].dist<<endl;
                tempNode = &graph[destCity];
                vector<Edge> flights;
                if(tempNode->pi!= nullptr){
                        while(tempNode->pi!=nullptr){
                                flights.push_back(*tempNode->piFlight);
                                // cout<<tempNode<<endl;
                                tempNode =tempNode->pi;
                                //cout<<"here"<<endl;
                        }

                        float sum=0;
                        for(unsigned int i=flights.size(); i>0;i--){
                                cout<<flights[i-1]<<endl;
                                sum+=flights[i-1].cost;
                        }
                        cout<<"Total cost: $"<<sum<<endl;
                        //TODO Add return trip    
                }else{
                        cout<<"I'm sorry this trip is impossible."<<endl;
                } 
                it = graph.begin();
                while(it != graph.end()){
                        //        cout<<"Infinite?"<<endl;
                        Node node =it->second;
                        node.visited = 0;
                        node.pi = nullptr;
                        node.piFlight = nullptr;
                        node.dist = 0;
                        it++;
                }
        }
        int main(int argc, char **argv){
                argc+=0;
                string progName(argv[0]);

                string file_name;
                //cout<<argc<<endl;
                istringstream buf(argv[1]); 
                buf >> file_name;
                //cout<<player_file;

                ifstream inFile(file_name);

                map<string,Node> graph;
                //vector<Node> vect;

                unordered_set<string> cities; 

                string tempLine;
                //getline(inFile,tempLine);

                string mydepCity;
                string mydestCity;
                string mydepTime;
                string myarrTime;
                string mycost;
                while(inFile>>mydepCity>>mydestCity>>mydepTime>>myarrTime>>mycost){            
                        // string depCity;
                        //   //tempLine>>depCity;
                        // inFile>>depCity;
                        // string destCity;
                        // inFile>>destCity;
                        // string depTime;
                        //inFile>>depTime;
                        //string arrTime;
                        //inFile>>arrTime;
                        //string cost;
                        //inFile>>cost;
                        //cout<<cost<<endl;
                        if(cities.find(mydepCity)==cities.end()){
                                graph.insert(pair<string,Node>(mydepCity,*(new Node(mydepCity))));
                                cities.insert(mydepCity);
                        }
                        if(cities.find(mydestCity)==cities.end()){
                                graph.insert(pair<string,Node>(mydestCity,*(new Node(mydestCity))));
                                cities.insert(mydestCity);
                        }
                        graph[mydepCity].insertEdge(*(new Edge(mydepCity,mydestCity,mydepTime,
                                                        myarrTime,mycost)));      

                        //   getline(inFile,tempName);
                }




                //cout<<"here"<<endl;
                string depCity;
                cout<<"Please input your departure city: ";
                cin>>depCity;
                string destCity;
                cout<<"\nPlease input your destination city: ";
                cin>>destCity;
                string depTime;
                cout<<"\nPlease input your earliest departure time: ";
                cin>>depTime;

                int depTimeInt = timeNum(depTime);

                string objectiveStr;
                int objective =0;
                while(objective!=-1){

                        cout<<"\nAny itinerary (0), earliest arrival (1), least expensive (2), or quit (-1): ";
                        cin>>objectiveStr;
                        objective = stoi(objectiveStr);

                        if(objective==0){
                                cout<<"Trip to destination: "<<endl;
                                anyPath(depCity,destCity, graph);
                                cout<<"\nReturn trip: "<<endl;
                                anyPath(destCity,depCity, graph);
                        }
                        else if(objective == 1){
                                cout<<"Trip to destination: "<<endl;
                                earliestArrival(depCity,destCity, graph, depTimeInt);
                                cout<<"\nPlease input your earliest return departure time: ";
                                cin>>depTime;
                                depTimeInt = timeNum(depTime);
                                cout<<"\nReturn trip: "<<endl;
                                earliestArrival(destCity,depCity, graph, depTimeInt);
                        }
                        else if(objective == 2){
                                cout<<"Trip to destination: "<<endl;
                                cheapestPath(depCity,destCity, graph, depTimeInt);
                                cout<<"\nPlease input your earliest return departure time: ";
                                cin>>depTime;
                                depTimeInt = timeNum(depTime);
                                cout<<"\nReturn trip: "<<endl;
                                cheapestPath(destCity,depCity, graph, depTimeInt);
                        }


                }


        }

