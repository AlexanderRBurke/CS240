#ifndef H_Tournament_H
#define H_Tournament_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Player.h"


using namespace std;

class Tournament{

	public:
		Player* winner;
		vector<Player*> players;
		vector<int>* battleCount;
		ofstream* outFile;
		Tournament* leftTournament;
		Tournament* rightTournament;
		Tournament(vector<Player*> myPlayers, ofstream* myOutFile, vector<int>* battleCount);
		~Tournament();
		void play();


	private:



};

#endif
