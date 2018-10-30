
#include <iostream>
#include <stdlib.h>


using namespace std;

	enum Suit {HEARTS,DIAMONDS,SPADES,CLUBS};

class PlayingCard{
	public:
		PlayingCard(int value,Suit suit);
		friend ostream& operator<<(ostream& out, const PlayingCard& p);
		bool operator==(const PlayingCard &p2); 
		bool operator>(const PlayingCard &p2); 
	private:
		int value;
		Suit suit;
		
}; 
