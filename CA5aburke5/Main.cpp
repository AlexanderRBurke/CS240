#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator> 
#include <map> 
#include <sstream>
#include <fstream>
#include "Node.h"
#include "Edge.h"
#include <bits/stdc++.h>
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
        cout<<endl;

        int depTimeInt = timeNum(depTime);

        string objectiveStr;
        cout<<"Any itinerary (0), earliest arrival (1), or least expensive (2): ";
        cin>>objectiveStr;
        int objective = stoi(objectiveStr);

        if(objective==0){
                Node source=graph[depCity];
                // for(int i=0; i<map.size();i++){
                // if(graph[i]
                //}

                queue <Node*> que;
                //map<string,Node>::iter
                for(unsigned int i=0; i<source.edges.size();i++){ //unsigned??
                        if(source.edges[i].depTime>depTimeInt){
                                Node* nextNode = &graph[source.edges[i].destCity];
                                nextNode->pi = &source;
                                nextNode->piFlight = &source.edges[i];
                                nextNode->visited = 1;
                                // cout<<nextNode->pi<<endl;
                                que.push(nextNode);
                        }
                }
                /// cout<<source.pi<<endl;
                source.visited=2;
                Node* tempNode = que.front();
                que.pop();
                //       cout<<tempNode->pi<<endl;
                // cout<<"before pi loop"<<endl;

                while(tempNode->name!=destCity){
                        for(unsigned int i=0; i<tempNode->edges.size();i++){ //unsigned??
                                Node* nextNode = &graph[tempNode->edges[i].destCity];
                                if(nextNode->visited==0 && nextNode->pi ==nullptr){
                                        nextNode->pi = tempNode;
                                        nextNode->piFlight = &tempNode->edges[i];
                                        nextNode->visited = 1;
                                        que.push(nextNode);
                                }
                        }
                        tempNode->visited =2;
                        tempNode = que.front();
                        que.pop();
                        //cout<<"during pi loop "<<endl;
                        //cout<<tempNode.name<<" "<<destCity<<endl;
                        // cout<<*tempNode->pi<<endl;
                }

                // cout<<"after pi loop"<<endl;
                //  cout<<*tempNode->pi<<endl;

                vector<Edge> flights;
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
                cout<<"Total cost: "<<sum<<endl;
                //TODO Add return trip     
        }
        else if(objective == 1){

                Node source=graph[depCity];
                source.dist = 0;

                queue <Node*> que;
                for(unsigned int i=0; i<source.edges.size();i++){ //unsigned??
                        if(source.edges[i].depTime>depTimeInt){
                                Node* nextNode = &graph[source.edges[i].destCity];
                                nextNode->pi = &source;
                                nextNode->piFlight = &source.edges[i];
                                nextNode->visited = 1;
                                nextNode->dist=source.edges[i].arrTime-source.edges[i].depTime;
                                // cout<<nextNode->pi<<endl;
                                que.push(nextNode);
                        }
                }
                /// cout<<source.pi<<endl;
                source.visited=2;
                cout<<que.size()<<endl;
                Node* tempNode;
                while(que.size()>0){
                        cout<<que.size()<<endl;
                        tempNode = que.front();
                        que.pop();
                        for(unsigned int i=0; i<tempNode->edges.size();i++){ //unsigned??
                                Node* nextNode = &graph[tempNode->edges[i].destCity];
                                if(nextNode->visited==0 && tempNode->piFlight->arrTime<tempNode->edges[i].depTime){
                                        nextNode->pi = tempNode;
                                        nextNode->piFlight = &tempNode->edges[i];
                                        nextNode->visited = 1;
                                        nextNode->dist=tempNode->dist+(tempNode->edges[i].arrTime-tempNode->edges[i].depTime);
                                        que.push(nextNode);
                                }
                                else if(nextNode->visited==1 && tempNode->piFlight->arrTime<tempNode->edges[i].depTime){
                                        if(tempNode->dist+(tempNode->edges[i].arrTime-tempNode->edges[i].depTime)<nextNode->dist){
                                                nextNode->pi = tempNode;
                                                nextNode->piFlight = &tempNode->edges[i];
                                                nextNode->visited = 1;
                                                nextNode->dist=tempNode->dist+(tempNode->edges[i].arrTime-tempNode->edges[i].depTime);
                                                que.push(nextNode);

                                        } 
                                }
                        }
                        tempNode->visited =2;
                        tempNode = que.front();
                        que.pop();
                }

                vector<Edge> flights;
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
                cout<<"Total cost: "<<sum<<endl;
                //TODO Add return trip     





        }







}

