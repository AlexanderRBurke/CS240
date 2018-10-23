#include <iostream>
#include <stdlib.h>

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
		Node<T> *next = nullptr;
};
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
		template<T>
		friend ostream& operator<<(ostream& out, const LLC<T>& l);
		//friend istream& operator>>(istream& in, const LLC& l);//extra
		void operator +=(int n);
		int len();
		void join(LLC<T> other);
		Node<T>* getFirst() const;
		Node<T>* getLast() const;

};

