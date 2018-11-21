#include <iostream>
#include "PlayingCard.h"
#include "Player.h"
#include "Game.h"
#include "Tournament.h"
#include <fstream>
using namespace std;

Tournament::Tournament(vector<Player*> myPlayers, ofstream* myOutFile, vector<int>* battleCount){
	players = myPlayers;
	outFile = myOutFile;
	this->battleCount=battleCount;
}

Tournament::~Tournament(){
		//cout<<players.size()<<endl;
		if(players.size()>2){
			//delete winner;
			delete leftTournament;
			delete rightTournament;
		}
		//for(unsigned int i=2;i<players.size();i++)
		//			delete players[i];
	//	delete &players;
	//	
	//	delete outFile;
}

void Tournament::play(){
	srand((int)time(0));
	int size = players.size();
	//	cout<<size<<endl;
	if(size==1)
		return;

	vector<Player*> leftPlayers;
	for(int i=0; i<size/2;i++){
		leftPlayers.push_back(players[i]);
	}
	vector<Player*> rightPlayers;
	for(int i=size/2; i<size;i++){
		rightPlayers.push_back(players[i]);
	}


	Game* game;
	if(size!=2){
		leftTournament = new Tournament(leftPlayers,outFile,battleCount);
		rightTournament = new Tournament(rightPlayers,outFile,battleCount);
		leftTournament->play();
		rightTournament->play();
		game = new Game(leftTournament->winner, rightTournament->winner,outFile);
	}
	else{
		Player* leftPlayer = leftPlayers[0];
		Player* rightPlayer = rightPlayers[0];
		game = new Game(leftPlayer, rightPlayer,outFile);
	}

	winner = game->play(); 
	battleCount->push_back(game->hands);

	delete game;


	//	delete rightTournament;
	//cout<<battleCount->size()<<endl;	
}
