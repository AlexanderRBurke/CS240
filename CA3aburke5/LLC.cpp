#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include <vector>
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

LLC LLC::operator =(const LLC &l){
	LLC temp =  LLC(l);
	l.~LLC();
	return temp;
} 

LLC::~LLC(){
	if(first!=nullptr){
		Node *tempNext = first->next;
		while(tempNext!=nullptr){
			delete first;
			first = tempNext;
			tempNext = first->next;
		}
		delete first;
	}

}

bool LLC::contains(const string &str){
	Node *tempFirst = first;
	if(tempFirst!=nullptr){
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			if(tempFirst->data==str)
				return true;
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		if(tempFirst->data==str)
			return true;
	}
	return false;
}

bool LLC::insert(const string &str){
	Node *tempFirst = first;
	if(tempFirst!=nullptr){
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		tempNext = new Node();
		tempNext->data = str;
		last = tempNext;
		return true;
	}else{return false;}
}

void LLC::remove(const string &str){
	Node *tempFirst = first;
	if(tempFirst!=nullptr){
		while(tempFirst->data==str){
			first = tempFirst->next;
			delete tempFirst;
			tempFirst = first;
		}
		Node *tempPrev = tempFirst;
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			if(tempFirst->data==str){	
				tempPrev = tempNext;
				delete tempFirst;
			}
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		if(tempFirst->data==str){
			tempPrev = tempNext;
			delete tempFirst;
		}
	}
}
void LLC::shuffle(){
	vector<Node*> vect;

	Node *tempFirst = first;
	if(tempFirst!=nullptr){
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr)
		{
			vect.push_back(tempFirst);
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}

		vect.push_back(tempFirst);
	}
	Node *tempPrev = tempFirst;
	Node *tempNext = tempFirst->next;
	for(int i =0; i<vect.size();i++){
		int r = (rand() % vect.size());
		if(i==0){
			first = vect.at(r);
				//tempNext = first->next;
				tempPrev = first;
			vect.erase(vect.begin() + r);
		}
		else{
			tempNext = vect.at(r);
			tempPrev->next = tempNext;
			tempPrev = tempNext;
			vect.erase(vect.begin() + r);
		}
	}
}

LLC LLC::operator +(const LLC &l){
	LLC copy = *this;
	LLC copy2 = l;
	copy.getLast()->next = copy2.getFirst();
	return copy;
}
void LLC::head(int n){
	if(n!=0){
			Node *tempFirst = first;
			if(tempFirst!=nullptr){
				Node *tempNext = next;
				for(int i =0;i<n;i++){
					if(tempNext!=nullptr){
						cout<<tempFirst->data;
					}

				}
			}
		}
	}
	string LLC::tail();
	//friend ostream& operator<<(ostream& out, const LLC& l);
	//friend istream& operator>>(istream& in, const LLC& l);//extra
	//LLC LLC::operator +=(int n);
	int LLC::len();
	void LLC::join(LLC other);
	Node* LLC::getFirst() const;
	Node* LLC::getLast() const;

