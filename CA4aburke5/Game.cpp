#include <iostream>
#include "PlayingCard.h"
#include "Game.h"
#include "Player.h"
#include "LLC.h"
#include <fstream>
using namespace std;

Game::Game(Player* p1, Player* p2,ofstream* myOutFile){
	player1 = p1;
	player2 = p2;
	middle=new LLC<PlayingCard>;
	outFile = myOutFile;
	*outFile<<"=== \n"<<*player1<<" VS. "<<*player2<<endl;
}

Game::~Game(){
		//delete player1;

		//delete player2;
		delete middle;
//	delete outFile;

	}

Player* Game::play(){
	shuffleDeck();

	//*outFile<<*(player1->cards)<<endl;
	//*outFile<<*(player2->cards)<<endl;

	while(!(player1->cards->getFirst()==nullptr || player2->cards->getFirst()==nullptr)){
		battle();
	} 
	//*outFile<<*(player1->cards)<<endl;
	//*outFile<<*(player2->cards)<<endl;
	if(player1->cards->getFirst()==nullptr){
		player2->gamesWon++;
		*outFile<<*player2<<" ("<<player2->gamesWon<<") DEFEATED "<<*player1<<" in "
			<<hands<<" Battles and "<<wars<<" Wars"<<endl;
		return player2;
	}
	player1->gamesWon++;
	*outFile<<*player1<<" ("<<player1->gamesWon<<") DEFEATED "<<*player2<<" in "
		<<hands<<" Battles and "<<wars<<" Wars"<<endl;
	return player1;
}

Player* Game:: battle(){
	int len1 = player1->cards->len();
	int len2 = player2->cards->len();
	bool warFlag=false;
	if(hands>=1000){
		Node<PlayingCard>* tempNode= player1->cards->pop();
		PlayingCard* card1 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
		delete tempNode;//might need to copy data from node
		tempNode= player2->cards->pop();
		PlayingCard* card2 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
		delete tempNode;

		middle->insert(*card1);
		middle->insert(*card2);

		Player* winner;
		if(len1>=len2){
			winner= player1;
		}else{
			winner= player2;
		}
		while(!(middle->getFirst()==nullptr)){
			winner->cards->insert((middle->pop()->data));
		}
		//*outFile<<"Player1 cards: " <<len1<< " Player2 cards: "<<len2<<endl;
		return winner;
	}
	hands++;
	Node<PlayingCard>* tempNode= player1->cards->pop();
	PlayingCard* card1 = &(tempNode->data);
	//PlayingCard* card1 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
	//delete tempNode;//might need to copy data from node
	tempNode= player2->cards->pop();
	PlayingCard* card2 = &(tempNode->data);
	//PlayingCard* card2 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
	//delete tempNode;

	middle->insert(*card1);
	middle->insert(*card2);

	//*outFile<<card1->getValue()<<endl;
	//*outFile<<card2->getValue()<<endl;

	Player* winner;
	Player* loser;
	if(*card1==*card2){
		*outFile<<"\tBattle "<<hands<<": "<<*player2
			<<" ("<<*card1<<") tied "<<*player1<<" ("
			<<*card2<<")"<<endl;
		warFlag=true;
		winner = war();
	}else if(*card1>*card2){
		winner = player1;
		loser= player2;
	}
	else{
		winner = player2;
		loser= player1;
	}

	while(!(middle->getFirst()==nullptr)){
		winner->cards->insert((middle->pop()->data));
	}


	if(!warFlag){
		len1 = player1->cards->len();
		len2 = player2->cards->len();
		if(winner->name==player1->name){
			*outFile<<"\tBattle "<<hands<<": "<<*winner
				<<" ("<<*card1<<") defeated "<<*loser<<" ("
				<<*card2<<"): "<<*player1<<" "<<len1<<", "<<*player2
				<<" "<<len2<<endl;

		}
		else{
			loser=player1;			
			*outFile<<"\tBattle "<<hands<<": "<<*winner
				<<" ("<<*card2<<") defeated "<<*loser<<" ("
				<<*card1<<"): "<<*player1<<" "<<len1<<", "<<*player2
				<<" "<<len2<<endl;
		}
	}
	//*outFile<<*(player1->cards)<<endl;
	//*outFile<<*(player2->cards)<<endl;
	delete card1;
	delete card2;
	return winner;	
}

Player* Game::war(){
	Player* winner;
	wars++;
	//*outFile<<"WAR"<<endl;
	if(player1->cards->getFirst()==nullptr){
		winner = player2;
		//*outFile<<"War winner is "<<winner->name<<endl;
		while(!(middle->getFirst()==nullptr)){
			winner->cards->insert((middle->pop()->data));
		}
		return winner;
	}
	if(player2->cards->getFirst()==nullptr){
		winner = player1;
		//*outFile<<"War winner is "<<winner->name<<endl;
		while(!(middle->getFirst()==nullptr)){
			winner->cards->insert((middle->pop()->data));
		}
		return winner;
	}

	PlayingCard* card1;
	PlayingCard* card2;
	for(int i = 0; i<4; i++){

		Node<PlayingCard>* tempNode= player1->cards->pop();
		if(!(tempNode==nullptr)){
			//card1 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
			card1 = &(tempNode->data);
			middle->insert(*card1);
			//*outFile<<"Card1 "<<*card1<<endl;
		}
		//delete tempNode;//might need to copy data from node
		tempNode= player2->cards->pop();
		if(!(tempNode==nullptr)){
			//card2 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
			card2 = &(tempNode->data);
			middle->insert(*card2);
			//*outFile<<"Card2 "<<*card2<<endl;

		}
		//delete tempNode;

		//Node<PlayingCard>* node2 = player2->cards->pop();
		//	PlayingCard card1 = player1->cards->pop()->data;
		//	PlayingCard card2 = player2->cards->pop()->data;

		//	if(!(&card2==nullptr))
		//		middle->insert(card2);
	}
	if(*card1==*card2)
		winner = war();
	else if(*card1>*card2){
		winner = player1;
	}
	else
		winner = player2;

	//*outFile<<"War winner is "<<winner->name<<endl;
	while(!(middle->getFirst()==nullptr)){
		PlayingCard tempCard = middle->pop()->data;
		//	*outFile<<tempCard<<endl;
		winner->cards->insert((tempCard));
	}
	int len1 = player1->cards->len();
	int len2 = player2->cards->len();
	if(winner->name==player1->name){
		Player* loser= player2;
		*outFile<<"\tWar "<<wars<<": "<<*winner
			<<" ("<<*card1<<") defeated "<<*loser<<" ("
			<<*card2<<"): "<<*player1<<" "<<len1<<", "<<*player2
			<<" "<<len2<<endl;

	}
	else{
		Player* loser=player1;			
		*outFile<<"\tWar "<<wars<<": "<<*winner
			<<" ("<<*card2<<") defeated "<<*loser<<" ("
			<<*card1<<"): "<<*player1<<" "<<len1<<", "<<*player2
			<<" "<<len2<<endl;
	}

	return winner;	
}

void Game::shuffleDeck(){
	LLC<PlayingCard>* deck = new LLC<PlayingCard>;
	Suit suit = DIAMONDS;
	for(int i =1; i<=13;i++){
		deck->insert(*(new PlayingCard(i,suit)));
	}
	suit = HEARTS;
	for(int i =1; i<=13;i++){
		deck->insert(*(new PlayingCard(i,suit)));
	}
	suit = CLUBS;
	for(int i =1; i<=13;i++){
		deck->insert(*(new PlayingCard(i,suit)));
	}
	suit = SPADES;
	for(int i =1; i<=13;i++){
		deck->insert(*(new PlayingCard(i,suit)));
	}

	srand((player1->randomNum)+(player2->randomNum));
	for(int i=0;i<4;i++)
		//cout<<i<<" rand(): "<<rand()<<endl;
	deck->shuffle(rand());

	//*outFile<<*deck<<endl;

	player1->cards = new LLC<PlayingCard>;
	player2->cards = new LLC<PlayingCard>;

	for(int i =0; i<26;i++){
		PlayingCard tempCard = deck->pop()->data;
		//*outFile<<*(player1)<<endl;
		//*outFile<<tempCard<<endl;
		player1->cards->insert(tempCard);
		//*outFile<<tempCard<<endl;
	}
	for(int i =0; i<26;i++){
		player2->cards->insert(deck->pop()->data);}
	//*outFile<<*deck<<endl;
	delete deck;
}


