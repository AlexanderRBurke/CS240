#include <iostream>
#include <stdlib.h>


using namespace std;

void newAcc(string &lName,string &fName,int &age,int &streetNum,string &streetName,string &town,string &zipCode,float &amtDonated);
void update(string &lName,string &fName,int &age,int &streetNum,string &streetName,string &town,string &zipCode);
void view(string lName,string fName,int age,int streetNum,string streetName,string town,string zipCode,float amtDonated);
void donate(float &amtDonated);
void report(string lName, float amtDonated);

int main() {

	string lName = "[empty]";
	string fName = "[empty]";
	int age = -1;
	int streetNum = 0;
	string streetName = "[empty]";
	string town = "[empty]";
	string zipCode= "-----";
	float amtDonated;
	
	bool quit = false;
	//newAcc(lName,fName,age,streetNum,streetName,town,zipCode,amtDonated);

	while(!quit){
		string input;
		cout<<"\nEnter a command. \nChoose from [\"New\" \"Update\" \"View\" \"Donate\" \"Report\" \"Quit\"]\n";
		cin>>input;
		//cout<<input<<"\n";
		if (input == "New")
			newAcc(lName,fName,age,streetNum,streetName,town,zipCode,amtDonated);
		else if (input == "Update")
			update(lName,fName,age,streetNum,streetName,town,zipCode);
		else if (input == "View")
			view(lName,fName,age,streetNum,streetName,town,zipCode,amtDonated);
		else if (input == "Donate")
			donate(amtDonated);
		else if (input == "Report")
			report(lName,amtDonated);
		else if (input == "Quit"){
			cout<< ": ";			
			quit = true;
		}
		else cout<<": Command not recognized. Please try again.\n";

	}

	

}
