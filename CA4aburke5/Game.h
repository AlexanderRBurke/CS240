#ifndef H_Game_H
#define H_Game_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "LLC.h"
#include "PlayingCard.h"
#include "Player.h"

using namespace std;

//class Player;

class Game{

	public:
		Player* player1;
		Player* player2;
		LLC<PlayingCard>* middle=new LLC<PlayingCard>;
		int hands=0;
		Game(Player* p1, Player* p2);
		Player* play();
		Player* battle();
		Player* war();
		
	private:	
		void shuffleDeck();


};
#endif
