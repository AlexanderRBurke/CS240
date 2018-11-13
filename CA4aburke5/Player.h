#ifndef H_Player_H
#define H_Player_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

class Player{

	public:
		LLC<PlayingCard>* cards = new LLC<PlayingCard>;
		string name;
		int gamesWon=0;
		int randomNum;
		Player(string myName,int rand);
		Player(LLC<PlayingCard>* myCards, string myName);
		~Player();
		friend ostream& operator<<(ostream& out, const Player& l);
		
};
#endif
