#ifndef H_PlayingCard_H
#define H_PlayingCard_H
#include <iostream>
#include <stdlib.h>


using namespace std;

enum Suit {HEARTS,DIAMONDS,SPADES,CLUBS};

class PlayingCard{
	public:
		PlayingCard();
		PlayingCard(int value,Suit suit);
		friend ostream& operator<<(ostream& out, const PlayingCard& p);
		bool operator==(const PlayingCard &p2); 
		bool operator>(const PlayingCard &p2); 
		int getValue();
		Suit getSuit();
	private:
		int value;
		Suit suit;

};
#endif
