
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator> 
#include <map> 
#include "Node.h"
#include "Edge.h"
//#include "Time.h"


using namespace std;

int main(int argc, char **argv){
	string progName(argv[0]);

	string file_name;
	//cout<<argc<<endl;
	istringstream buf(argv[1]); 
	buf >> file_name;
	//cout<<player_file;

	ifstream inFile(file_name);

        map<string,Node> graph;

        unordered_set<string> cities; 

        string tempLine;
	//getline(inFile,tempLine);
	while(inFile.good()){            
            string depCity;
            //tempLine>>depCity;
            inFile>>depCity;
            string destCity;
            inFile>>destCity;
            string depTime;
            inFile>>depTime;
            string arrTime;
            inFile>>arrTime;
            string cost;
            inFile>>cost;
            if(cities.find(depCity)==container.end()){
                graph.insert(pair<string,Node>(depCity,new Node(depCity)));
                cities.insert(depCity);
            }
            graph[depCity].insertEdge(new Edge(destCity,depTime,arrTime,cost);      

                 //   getline(inFile,tempName);
                    }
                    }

