#include <iostream>
#include "PlayingCard.h"
using namespace std;

PlayingCard::PlayingCard(){}

PlayingCard::PlayingCard(int value, Suit suit){
	this->value = value;
	this->suit = suit;
}

/*PlayingCard::~PlayingCard(){
	delete &suit;
	}
*/
ostream& operator<<(ostream& out, const PlayingCard& p){
	
	if(p.value!=1 && p.value<10){
		out<<p.value;
	}
	else{
		switch(p.value){
			case 1: out<<"A"; break;
			case 10: out<<"T"; break;
			case 11: out<<"J"; break;
			case 12: out<<"Q"; break;
			case 13: out<<"K"; break;
		}
	}
	
	switch(p.suit){
		case 0: out<<"H"; break;
		case 1: out<<"D"; break;
		case 2: out<<"S"; break;
		case 3: out<<"C"; break;
		}
	return out;
}

bool PlayingCard:: operator==(const PlayingCard &p2){
	if(this->value==p2.value)
		return true;
	return false;	
}

bool PlayingCard:: operator>(const PlayingCard &p2){
//	cout<<this->value<<" versus "<<p2.value<<endl;
	if(this->value==1 && p2.value!=1)
		return true;
	if(p2.value==1)
		return false;
	if(this->value>p2.value)
		return true;
	return false;
}	

int PlayingCard::getValue(){
	return value;
}
Suit PlayingCard::getSuit(){
	return suit;
}
