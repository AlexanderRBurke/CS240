#ifndef H_LLC_H
#define H_LLC_H
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

//class Node{
//	private:
//		Node* next;
//		string data;
//	public:
//		Node(string s);
//		Node* getNode(){return this.data;};
//		void setNext(Node* n){this->next=n;};
//		Node* getNext(){return this->next};
//		~Node(){this->next = nullptr;};
//};
template <class T>
class Node{
	public:
		T data;
		Node<T> *next= nullptr;
		Node<T>();
};
template <class T>
Node<T>::Node(){}
template <class T>
class LLC{

	private:
		Node<T>* first;
		Node<T>* last;

	public:

		LLC();
		LLC( const LLC<T> &l);
		LLC<T> operator =(const LLC<T> &l); 
		~LLC();
		bool contains(const T &str);
		bool insert(const T &str);
		void remove(const T &str);
		void shuffle();
		LLC& operator +(const LLC &l);
		void head(int n);
		T tail();
		template<class U>
			friend ostream& operator<<(ostream& out, const LLC<U>& l);
		//friend istream& operator>>(istream& in, const LLC& l);//extra
		void operator +=(int n);
		int len();
		void join(LLC<T> other);
		Node<T>* getFirst() const;
		Node<T>* getLast() const;
		Node<T>* pop();
};

template <class T>
LLC<T>::LLC(){
	//cout<<"constructor"<<endl;
	first = nullptr;
	last = nullptr;
}

template <class T>
LLC<T>::LLC( const LLC<T> &l){	
	Node<T> *oldNode = l.getFirst();
	if(oldNode!=nullptr){
		Node<T> *newNode = new Node<T>;
		first= newNode;
		last= newNode;
		newNode->data=oldNode->data;
		Node<T> *prevNode = newNode;
		while(oldNode->next!=nullptr){
			prevNode=newNode;
			oldNode = oldNode->next;
			newNode = new Node<T>;
			last= newNode;
			newNode->data=oldNode->data;
			prevNode->next=newNode;
		}
	}
}

template <class T>
LLC<T> LLC<T>::operator =(const LLC<T> &l){
	//cout<<"here"<<endl;
	this->~LLC<T>();	
	//cout<<"after delete"<<endl;
	first=nullptr;
	last=nullptr;
	Node<T> *oldFirst = l.getFirst();
	//cout<<oldFirst->data<<endl;
	Node<T> *oldNext = oldFirst->next;
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

template <class T>
LLC<T>::~LLC(){
	if(first!=nullptr){
		//cout<<"deconstructing"<<endl;
		Node<T> *tempNext = first->next;
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

template <class T>
bool LLC<T>::contains(const T &str){
	Node<T> *tempFirst = first;
	if(tempFirst!=nullptr){
		Node<T> *tempNext = tempFirst->next;
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

template <class T>
bool LLC<T>::insert(const T &str){
	//cout<<"inserting "<<endl;
	if(first==nullptr){
		//cout<<"inserting "<<endl;
		Node<T> *tempNode = new Node<T>;
		tempNode->data= str;
		first=tempNode;
		last=tempNode;
		return true;
	}else{
		Node<T> *tempNode = new Node<T>;
		tempNode->data = str;
		last->next = tempNode;
		last=tempNode;
		return true;
	}
	return false;
}

template <class T>
void LLC<T>::remove(const T &str){
	Node<T> *tempFirst = first;
	//cout<<tempFirst->next->data<<endl;
	if(tempFirst!=nullptr){
		while(tempFirst->data==str){
			first = tempFirst->next;
			delete tempFirst;
			tempFirst = first;
		}
		Node<T> *tempPrev = tempFirst;
		Node<T> *tempNext = tempFirst->next;
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
template <class T>
void LLC<T>::shuffle(){
	vector<Node<T>*> vect;

	Node<T> *tempFirst = first;
	if(tempFirst!=nullptr){
		Node<T> *tempNext = tempFirst->next;
		while(tempNext!=nullptr)
		{
			vect.push_back(tempFirst);
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}

		vect.push_back(tempFirst);
	}
	//cout<<"vect size "<<vect.size()<<endl;
	Node<T> *tempPrev = tempFirst;
	Node<T> *tempNext = tempFirst->next;
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

template <class T>
LLC<T>& LLC<T>::operator +(const LLC<T> &l){
	LLC<T>* copy = new LLC<T>();
	Node<T>* tempFirst = getFirst();
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
template <class T>
void LLC<T>::head(int n){
	//cout<<"in head method"<<endl;
	if(n!=0){
		Node<T> *tempFirst = first;
		if(tempFirst!=nullptr){
			Node<T> *tempNext =first->next;
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

template <class T>
T LLC<T>::tail(){
	if(last!=nullptr){
		cout<<last->data<<endl;
		return last->data;
	}
	return "nullptr";
}

template <class T>
ostream& operator<<(ostream& out, const LLC<T>& l){
	//cout<<"print"<<endl;
	Node<T> *tempFirst = l.getFirst();
	if(tempFirst!=nullptr){
		Node<T> *tempNext = tempFirst->next;
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

//friend istream& operator>>(istream& in, const LLC<T>& l);//extra
template <class T>
void LLC<T>::operator +=(int n){
	Node<T> *tempFirst = first;
	for(int i =0;i<n;i++){
		Node<T> *tempNode=tempFirst;
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
template <class T>
int LLC<T>::len(){
	int retLen = 0;
	Node<T> *tempFirst = first;
	if(tempFirst!=nullptr){
		Node<T> *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			retLen++;
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		retLen++;
	}
	return retLen;
}

template <class T>
void LLC<T>::join(LLC<T> other){
	Node<T> *tempFirst = other.getFirst();
	if(tempFirst!=nullptr){
		Node<T> *tempNext = tempFirst->next;
		while(tempNext!=nullptr){
			insert(tempFirst->data);
			tempFirst = tempNext;
			tempNext = tempFirst->next;
		}
		insert(tempFirst->data);
	}
}
template <class T>
Node<T>* LLC<T>::getFirst() const{
	return first;
}
template <class T>
Node<T>* LLC<T>::getLast() const{
	return last;
}

template <class T>
Node<T>* LLC<T>:: pop(){
	if(getFirst()!=nullptr){
		Node<T>* temp = getFirst();
		first = first->next;
		return temp;}
	return nullptr;
}
#endif
