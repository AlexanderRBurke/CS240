#include <iostream>
#include <stdlib.h>
#include <string>
#include "Voter.h"

using namespace std;

class VoterDB {

	public:
		VoterDB(int mymaxVoters);
		VoterDB(int mymaxVoters, string fileName);
		~VoterDB();
		bool login();
		bool newAcc();
		void report();
		bool save();
		bool load(string input);
		void menu();
		
	private:
		Voter* voterArr;
		int curNumOfVoters;
		int maxVoters;

};
