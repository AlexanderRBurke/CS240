#include <iostream>
#include <stdlib.h>

using namespace std;



class LLC{

	public:
		
		LLC();
		LLC( const LLC &l);
		LLC operator =(const LLC &l); 
		~LLC();
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
		Node* getFirst();
		Node* getLast();

	private:
		Node* first;
		Node* last;

}

typedef struct Node{
	string data;
	Node *next = nullptr;
	} Node;
