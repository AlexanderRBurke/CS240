#include <iostream>
#include <stdlib.h>
#include "LLC.h"

using namespace std;

LLC::LLC(){
	first = nullptr;
	last = nullptr;
}
		
LLC::LLC( const LLC &l){	
	Node *oldNode = l.getFirst();
	if(oldNode!=nullptr){
		Node *newNode = new Node;
		first= newNode;
		last= newNode;
		newNode->data=oldNode->data;
		while(oldNode->next!=nullptr){
			newNode->next = oldNode->next;
			oldNode = oldNode->next;
			newNode = new Node;
			last= newNode;
			newNode->data=oldNode->data;
		}
	}
}

LLC::LLC operator =(const LLC &l){
	LLC(l);
	l.~LLC();
} 

LLC::~LLC(){
	if(first!=nullptr){
		Node *tempNext = first->next
	}
}
		bool contains(const string &str);
		bool insert(const string &str);
		void remove(const string &str);
		void shuffle();
		LLC operator +(const LLC &l1,const LLC &l2);
		void head(int n);
		string tail();
		friend ostream& operator<<(ostream& out, const LLC& l);
		//friend istream& operator>>(istream& in, const LLC& l);//extra
		LLC operator +=(int n);
		int len();
		void join(LLC other);


