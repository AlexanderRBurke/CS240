#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include <vector>
using namespace std;

int main(){
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
	return 0;
}
