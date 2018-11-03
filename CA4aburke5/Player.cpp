#include <iostream>
#include "PlayingCard.h"
#include "Player.h"
using namespace std;


Player::Player(string myName){
	name = myName;
}

Player::Player(LLC<PlayingCard>* myCards, string myName){
	cards = myCards;
	name = myName;
}

ostream& operator<<(ostream& out, const Player& l){
	return out<<l.name;
		}
