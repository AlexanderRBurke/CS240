#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"
#include "Player.h"
#include "Game.h"
//#define _GLIBCXX_USE_CXX11_ABI 0
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include "Tournament.h"
using namespace std;

int main(int argc, char **argv){
	string progName(argv[0]);

	string player_file;
	string log_file;
	//cout<<argc<<endl;
	istringstream buf(argv[1]); 
	buf >> player_file;
	//cout<<player_file;

	istringstream buf2(argv[argc-1]); 
	buf2 >> log_file;

	ifstream inFile(player_file);
	ofstream outFile(log_file);

	string tempName;
	vector<string> vect;

	getline(inFile,tempName);
	while(inFile.good()){
		vect.push_back(tempName);
		getline(inFile,tempName);
	}

	bool validPlayerNum =false;

	for(int i =1; i<=6; i++){
		if(vect.size()%static_cast<unsigned int>(pow(2,i))==0)
			validPlayerNum=true;
	}

	vector<Player*> playerVect;

	if(validPlayerNum){
		vector<int>* numOfBattles=new vector<int>();
		double avgNumOfBattles;
		int largestNumOfBattles=0;
		for(unsigned int i =0; i<vect.size();i++){
			srand((int)time(0));
			//	cout<<rand()<<endl;
			playerVect.push_back(new Player(vect[i],rand()*(i+1)));
		}	
		Tournament* tournament = new Tournament(playerVect,&outFile,numOfBattles);
		tournament->play();
		int sum =0;
		for(unsigned int i =0; i<numOfBattles->size();i++){
			int temp = (*numOfBattles)[i];
			//cout<<temp<<endl;
			if(temp>largestNumOfBattles)
				largestNumOfBattles=temp;
			sum+=temp;
		}
		//cout<<"here?"<<numOfBattles->size()<<endl;
		avgNumOfBattles= sum/(numOfBattles->size());

		cout<<"The winner is "<<*(tournament->winner)<<endl;
		cout<<"The average number of battles per matchup is "<<avgNumOfBattles<<endl;
		cout<<"The largest number of battles in any one matchup is "<<largestNumOfBattles<<endl;
		delete tournament;
		delete numOfBattles;
	}
	else{
		cout<<"Incorrect number of participants"<<endl;
		return -1;
	}


	//delete &vect;
	for(unsigned int i=0;i<playerVect.size();i++)
		delete playerVect[i];
	//delete &playerVect;











	/*
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
	*/
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
