#include <iostream>
#include "PlayingCard.h"
#include "Game.h"
#include "Player.h"
using namespace std;

Game::Game(Player* p1, Player* p2){
	player1 = p1;
	player2 = p2;
}

Player* Game::play(){
	shuffleDeck();
	
	cout<<*(player1->cards)<<endl;
	cout<<*(player2->cards)<<endl;

	while(!(player1->cards->getFirst()==nullptr || player2->cards->getFirst()==nullptr)){
		battle();
	} 
	cout<<*(player1->cards)<<endl;
	cout<<*(player2->cards)<<endl;
	if(player1->cards->getFirst()==nullptr)
		return player2;
	return player1;
}

Player* Game:: battle(){
	hands++;

	if(hands>1000){
		int len1 = player1->cards->len();
		int len2 = player2->cards->len();
		Node<PlayingCard>* tempNode= player1->cards->pop();
		PlayingCard* card1 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
		delete tempNode;//might need to copy data from node
		tempNode= player2->cards->pop();
		PlayingCard* card2 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
		delete tempNode;

		middle->insert(*card1);
		middle->insert(*card2);

		Player* winner;
		if(len1>=len2)
			winner= player1;
		else
			winner= player2;
		while(!(middle->getFirst()==nullptr)){
			winner->cards->insert((middle->pop()->data));
		}
		cout<<"Player1 cards: " <<len1<< " Player2 cards: "<<len2<<endl;
		return winner;
	}
	Node<PlayingCard>* tempNode= player1->cards->pop();
	PlayingCard* card1 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
	delete tempNode;//might need to copy data from node
	tempNode= player2->cards->pop();
	PlayingCard* card2 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
	delete tempNode;

	middle->insert(*card1);
	middle->insert(*card2);

	cout<<card1->getValue()<<endl;
	cout<<card2->getValue()<<endl;

	Player* winner;
	if(*card1==*card2)
		winner = war();
	else if(*card1>*card2){
		winner = player1;
	}
	else
		winner = player2;


	while(!(middle->getFirst()==nullptr)){
		winner->cards->insert((middle->pop()->data));
	}

	cout<<"Battle inner is "<<winner->name<<endl;
	//cout<<*(player1->cards)<<endl;
	cout<<*(player2->cards)<<endl;
	return winner;	
}

Player* Game::war(){
	cout<<"WAR"<<endl;
	if(player1->cards->getFirst()==nullptr)
		return player2;
	if(player2->cards->getFirst()==nullptr)
		return player1;

	PlayingCard* card1;
	PlayingCard* card2;
	for(int i = 0; i<4; i++){

		Node<PlayingCard>* tempNode= player1->cards->pop();
		if(!(tempNode==nullptr)){
			card1 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
			middle->insert(*card1);
			cout<<"Card1 "<<*card1<<endl;
		}
		delete tempNode;//might need to copy data from node
		tempNode= player2->cards->pop();
		if(!(tempNode==nullptr)){
			card2 = new PlayingCard(tempNode->data.getValue(),tempNode->data.getSuit());
			middle->insert(*card2);
			cout<<"Card2 "<<*card2<<endl;

		}
		delete tempNode;

		//Node<PlayingCard>* node2 = player2->cards->pop();
		//	PlayingCard card1 = player1->cards->pop()->data;
		//	PlayingCard card2 = player2->cards->pop()->data;

		//	if(!(&card2==nullptr))
		//		middle->insert(card2);
	}
	Player* winner;
	if(*card1==*card2)
		winner = war();
	else if(*card1>*card2){
		winner = player1;
	}
	else
		winner = player2;

	cout<<"War winner is "<<winner->name<<endl;

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

	deck->shuffle();


	for(int i =0; i<26;i++){
		player1->cards->insert(deck->pop()->data);}
	for(int i =0; i<26;i++){
		player2->cards->insert(deck->pop()->data);}
}


