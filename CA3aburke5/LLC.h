#include <iostream>
#include <stdlib.h>

using namespace std;



class LLC{

	private:
		struct Node{
			string data;
			Node *next = nullptr;
		};
		Node* first;
		Node* last;

	public:

		LLC();
		LLC( const LLC &l);
		LLC operator =(const LLC &l); 
		~LLC();
		bool contains(const string &str);
		bool insert(const string &str);
		void remove(const string &str);
		void shuffle();
		LLC operator +(const LLC &l);
		void head(int n);
		string tail();
		friend ostream& operator<<(ostream& out, const LLC& l);
		//friend istream& operator>>(istream& in, const LLC& l);//extra
		LLC operator +=(int n);
		int len();
		void join(LLC other);
		Node* getFirst() const;
		Node* getLast() const;
		
};

