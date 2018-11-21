#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "VoterDB.h"


using namespace std;

int main(int argc, char **argv){
	string progName(argv[0]);
	int maxVoters;
	istringstream buf(argv[1]); 
	buf >> maxVoters;
	//cout<<maxVoters;
	if(argc>2){
		string fileName;
		istringstream buf2(argv[2]); 
		buf2 >> fileName;
		VoterDB database = VoterDB(maxVoters,fileName);
		database.menu();
		//cout<<"some dfsa"<<endl;	
	}
	else{ 
		VoterDB database = VoterDB(maxVoters);
		database.menu();
	}
	
		
	
	

}
