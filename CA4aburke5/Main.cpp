#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"
#include "Player.h"
#include "Game.h"
//#define _GLIBCXX_USE_CXX11_ABI 0
#include <vector>
using namespace std;

int main(){

	PlayingCard* ace = new PlayingCard(1,SPADES);
	PlayingCard* ten = new PlayingCard(10,CLUBS);

	LLC<PlayingCard>* deck = new LLC<PlayingCard>();
	deck->insert(*ace);
	deck->insert(*ten);

	string name1= "Alex";
	string name2 = "Henry";
	Player* alex = new Player("Alex");
	Player* henry = new Player("Henry");

	Game* game = new Game(alex,henry);
	//game->shuffleDeck();
	Player* winner = game->play();
	
	//cout<<*ace<<endl;
	//cout<<*deck<<endl;
	cout<<winner->name<<endl;
	/*
	LLC* list1 = new LLC();
	for(int i = 0; i<5;i++){
		list1->insert(to_string(i));
		//cout<<to_string(i)<<endl;
	}
	cout<<*list1<<endl;
	list1->head(3);
	//cout<<"test"<<endl;
	//list1->shuffle();
	cout<<*list1<<endl;
	cout<<list1->len()<<endl;
	//cout<<*list1<<endl;
	LLC* list2 = new LLC(*list1);
	//cout<<*list1<<endl;
	list2->shuffle();
	list1->remove("4");
	cout<<"list1: "<<*list1<<endl;
	cout<<"list2: "<<*list2<<endl;
	LLC* list3 =&(*list1+(*list2));
	cout<<*list3<<endl;
	cout<<list1->contains("4")<<endl;
	cout<<list2->contains("4")<<endl;
	*list3+=2;
	cout<<*list3<<endl;
	list2->join(*list1);
	cout<<*list2<<endl;
	list2->tail();
	*list1=*list2;
	cout<<*list1<<endl;
	cout<<"test"<<endl;

	delete list1;
	delete list2;
	delete list3;
	*/
	return 0;
}
/*
int tournament(int numOfPlayers){
	
}*/
