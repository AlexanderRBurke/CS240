#include <iostream>
#include "PlayingCard.h"
#include "Player.h"
using namespace std;


Player::Player(string myName,int rand){
	name = myName;
	randomNum = rand;
}

Player::Player(LLC<PlayingCard>* myCards, string myName){
	cards = myCards;
	name = myName;
}

Player::~Player(){
	if(cards->len()!=0){
	//	cout<<*cards<<endl;
		delete cards;
	}
}

ostream& operator<<(ostream& out, const Player& l){
	return out<<l.name;
}
