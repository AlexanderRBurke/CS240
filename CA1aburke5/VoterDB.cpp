#include <iostream>
#include <stdlib.h>   
#include <iomanip>      // std::setprecision

using namespace std;

void newAcc(string &lName,string &fName,int &age,int &streetNum,string &streetName,string &town,string &zipCode,float &amtDonated){

	cout<< ": \nLast Name: ";
	cin>>lName;
	/*if(lName.length() == 0)
		lName = "[empty]";*/

	cout<< "First Name: ";
	cin>>fName;
	/*if(fName.length() == 0)
		fName = "[empty]";*/

	cout<< "Age: ";
	cin>>age;

	cout<< "House Number: ";
	cin>>streetNum;

	cout<< "Street Name: ";
	cin.ignore();	
	getline(cin,streetName);

	cout<< "Town: ";
	cin>>town;

	cout<< "Zip Code: ";
	cin>>zipCode;
	
	amtDonated = 0;
}

void update(string &lName,string &fName,int &age,int &streetNum,string &streetName,string &town,string &zipCode){

	cout<< ": \nLast Name:";
	cin>>lName;

	cout<< "First Name: ";
	cin>>fName;

	cout<< "Age: ";
	cin>>age;

	cout<< "House Number: ";
	cin>>streetNum;

	cout<< "Street Name: ";
	cin.ignore();	
	getline(cin,streetName);

	cout<< "Town: ";
	cin>>town;

	cout<< "Zip Code: ";
	cin>>zipCode;
}
	
void view(string lName,string fName,int age,int streetNum,string streetName,string town,string zipCode,float amtDonated){
	
	cout<< ": \nDonor Info:\n" << fName <<" " <<lName<<": age "
		<< age<< "\n" << streetNum <<" " << streetName << "\n" << town
		<< " " << zipCode << "\nCurrent Amount Donated: $"
		<< amtDonated<< "\n\n";
}

void donate(float &amtDonated){
	float donation;
	cout<<": \nEnter Amount to Donate: ";
	cin>>donation;
	amtDonated+=donation;
	cout << fixed << setprecision(2);
	cout<<"$"<<donation<< " donated.\n";
}

void report(string lName, float amtDonated){

	cout << std::fixed;
	cout<< ": \n";
	cout<<setprecision(2)<<lName<< " " <<"$"<<amtDonated<< "\n";

}



















