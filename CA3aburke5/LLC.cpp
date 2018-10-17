#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include <vector>
using namespace std;

LLC::LLC(){
	//cout<<"constructor"<<endl;
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
		Node *prevNode = newNode;
		while(oldNode->next!=nullptr){
			prevNode=newNode;
			oldNode = oldNode->next;
			newNode = new Node;
			last= newNode;
			newNode->data=oldNode->data;
			prevNode->next=newNode;
		}
	}
}

LLC LLC::operator =(const LLC &l){
	//cout<<"here"<<endl;
        delete this;	
	//cout<<"after delete"<<endl;
	first=nullptr;
	last=nullptr;
	Node *oldFirst = l.getFirst();
	//cout<<oldFirst->data<<endl;
	Node *oldNext = oldFirst->next;
	while(oldNext!=nullptr){	
		//cout<<first<<endl;
		insert(oldFirst->data);
		//cout<<oldFirst->data<<endl;
		oldFirst=oldNext;
		oldNext=oldFirst->next;	
		//cout<<oldFirst->data<<endl;
	}
	//cout<<"after loop"<<endl;
	insert(oldFirst->data);
	return *this;
} 

LLC::~LLC(){
	if(first!=nullptr){
		//cout<<"deconstructing"<<endl;
		Node *tempNext = first->next;
		while(tempNext!=nullptr){
			delete first;
			first = tempNext;
			tempNext = first->next;
		}
		delete first;
		first=nullptr;
		last=nullptr;
	}

		//cout<<"first: "<<first<<endl;
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
		//cout<<"inserting "<<endl;
	if(first==nullptr){
		//cout<<"inserting "<<endl;
		Node *tempNode = new Node;
		tempNode->data= str;
		first=tempNode;
		last=tempNode;
		return true;
	}else{
		Node *tempNode = new Node;
		tempNode->data = str;
		last->next = tempNode;
		last=tempNode;
		return true;
	}
	return false;
}

void LLC::remove(const string &str){
	Node *tempFirst = first;
	//cout<<tempFirst->next->data<<endl;
	if(tempFirst!=nullptr){
		while(tempFirst->data==str){
			first = tempFirst->next;
			delete tempFirst;
			tempFirst = first;
		}
		Node *tempPrev = tempFirst;
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			//cout<<tempFirst->data<<endl;
			if(tempFirst->data==str){	
			//	cout<<"here2"<<endl;
				tempPrev->next=tempNext;
				delete tempFirst;
			}
			tempPrev = tempFirst;
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		//	cout<<tempFirst->data<<endl;
		}
		//cout<<"here"<<endl;
		if(tempFirst->data==str){
			last=tempPrev;
			tempPrev->next=nullptr;
			delete tempFirst;
		}
		//cout<<tempFirst<<endl;
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
	//cout<<"vect size "<<vect.size()<<endl;
	Node *tempPrev = tempFirst;
	Node *tempNext = tempFirst->next;
	unsigned int size = vect.size();
	for(unsigned int i =0; i<size;i++){
		srand(time(NULL));
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
		//cout<<"i "<<i<<endl;
	}
	//cout<<"vect size "<<vect.size()<<endl;
	last=tempPrev;
	last->next=nullptr;
}

LLC& LLC::operator +(const LLC &l){
	LLC* copy = new LLC();
	Node* tempFirst = getFirst();
	while(tempFirst->next!=nullptr){
		//cout<<tempFirst->data<<endl;
		copy->insert(tempFirst->data);
		tempFirst=tempFirst->next;	
	}
	copy->insert(tempFirst->data);
	tempFirst = l.getFirst();
	while(tempFirst!=nullptr){
		copy->insert(tempFirst->data);
		tempFirst=tempFirst->next;	
	}
	return *copy;
}
void LLC::head(int n){
	//cout<<"in head method"<<endl;
	if(n!=0){
		Node *tempFirst = first;
		if(tempFirst!=nullptr){
			Node *tempNext =first->next;
			//cout<<tempNext->data<<" next data \n";
			cout<<"["<<tempFirst->data<<", ";
			for(int i =0;i<n-1;i++){
				if(tempNext!=nullptr&&i!=n-2){
					tempFirst = tempNext;
					tempNext = tempFirst->next;
					cout<<tempFirst->data<<", ";
				}else{
					tempFirst = tempNext;
					tempNext = tempFirst->next;
					cout<<tempFirst->data;
				}
			}
			cout<<"]"<<endl;
		}

	}
}

string LLC::tail(){
	if(last!=nullptr){
	cout<<last->data<<endl;
	return last->data;
	}
	return "nullptr";
}

ostream& operator<<(ostream& out, const LLC& l){
	//cout<<"print"<<endl;
	LLC::Node *tempFirst = l.getFirst();
	if(tempFirst!=nullptr){
		LLC::Node *tempNext = tempFirst->next;
		out<<"[";

		while(tempNext!=nullptr){
			out<<tempFirst->data<<", ";
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		out<<tempFirst->data<<"]";

	}
	return out;
}

//friend istream& operator>>(istream& in, const LLC& l);//extra
void LLC::operator +=(int n){
	Node *tempFirst = first;
	for(int i =0;i<n;i++){
		Node *tempNode=tempFirst;
		first = tempNode->next;
	//	cout<<*this<<endl;
		while(tempNode->next!=nullptr){
			tempNode=tempNode->next;
		}
		tempNode->next = tempFirst;
		last=tempFirst;
		last->next=nullptr;
		tempFirst = first;
		//cout<<"here3\n";
	}
	//cout<<"here3\n";
}
int LLC::len(){
	int retLen = 0;
	Node *tempFirst = first;
	if(tempFirst!=nullptr){
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			retLen++;
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		retLen++;
	}
	return retLen;
}

void LLC::join(LLC other){
	Node *tempFirst = other.getFirst();
	if(tempFirst!=nullptr){
		Node *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			insert(tempFirst->data);
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		insert(tempFirst->data);
	}
}
LLC::Node* LLC::getFirst() const{
	return first;
}
LLC::Node* LLC::getLast() const{
	return last;
}

