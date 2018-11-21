#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Voter {

	public:
		Voter();//More constructors?
		Voter(string myuserid, string mypassword, string mylName,string myfName,int myage,int mystreetNum,string mystreetName,string mytown,string myzipCode);
		Voter(const Voter &v); // copy constructor
		Voter(string str);
		//Voter operator =(const Voter &v);
		void update();
		void view();
		void donate();
		void report();
		string getUserid() const;
		string getPassword() const;
		string getLName() const;
		string getFName() const;
		int getAge() const;
		int getStreetNum() const;
		string getStreetName() const;
		string getTown() const;
		string getZipCode() const;
		float getAmtDonated() const;
		bool changePassword();
		//Voter load(string fileName);
		string save();
		void menu();
	private:
		string lName = "[empty]";
		string fName = "[empty]";
		string userid;//contains at least 5 characters but no more than 10, containing only letters and digits
		string password;//least 6 chars,at least one digit and one neither a letter nor a digit		
		int age = -1;
		int streetNum = 0;
		string streetName = "[empty]";//may include multiple words separated by spaces or tabs
		string town = "[empty]";//may also include multiple words separated by spaces or tabs
		string zipCode= "-----";//contains exactly 5 digits
		float amtDonated;//non-negative, total amount donate must not grow beyond $2,700
		


};
