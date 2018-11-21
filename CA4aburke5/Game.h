#ifndef H_Game_H
#define H_Game_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "LLC.h"
#include "PlayingCard.h"
#include "Player.h"
#include <fstream>

using namespace std;

//class Player;

class Game{

	public:
		Player* player1;
		Player* player2;
		LLC<PlayingCard>* middle;
		int hands=0;
		int wars=0;
		ofstream* outFile;
		Game(Player* p1, Player* p2,ofstream* myOutFile);
		~Game();
		Player* play();
		Player* battle();
		Player* war();
		
	private:	
		void shuffleDeck();


};
#endif
