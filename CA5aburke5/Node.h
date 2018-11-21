#ifndef H_Node_H
#define H_Node_H
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Node{
	public:
		string depCity;
		string destCity;
		Time depTime;
		Time arrTime;
		float cost;
		vector<Edge> edges;


		//Node *next= nullptr;
		Node();
};



#endif
