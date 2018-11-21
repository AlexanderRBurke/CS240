#include <iostream>
#include <stdlib.h>
#include <iomanip>      // std::setprecision
#include <fstream>
#include "Voter.h"

using namespace std;


	Voter::Voter(){
		lName = "[empty]";
		fName = "[empty]";
		age = -1;
		streetNum = 0;
		streetName = "[empty]";//may include multiple words separated by spaces or tabs
		town = "[empty]";//may also include multiple words separated by spaces or tabs
		zipCode= "-----";//contains exactly 5 digits
		amtDonated=0;//non-negative, total amount donate must not grow beyond $2,700
	}

	Voter::Voter(string myuserid, string mypassword, string mylName,string myfName,int myage,int mystreetNum,string mystreetName,string mytown,string myzipCode){
		lName = mylName;
		fName = myfName;
		age = myage;
		streetNum = mystreetNum;
		streetName = mystreetName;//may include multiple words separated by spaces or tabs
		town = mytown;//may also include multiple words separated by spaces or tabs
		zipCode= myzipCode;//contains exactly 5 digits
		amtDonated = 0;//non-negative, total amount donate must not grow beyond $2,700
		userid= myuserid;//at least 5 characters but no more than 10, only letters and digits
		password = mypassword;//at least 6 characters, one digit and one character neither a letter nor a digit)
	}


	Voter::Voter(const Voter &v){ //TODO
		lName = v.getLName();
		fName = v.getFName();
		age = v.getAge();
		streetNum = v.getStreetNum();
		streetName = v.getStreetName();//may include multiple words separated by spaces or tabs
		town = v.getTown();//may also include multiple words separated by spaces or tabs
		zipCode= v.getZipCode();//contains exactly 5 digits
		amtDonated = v.getAmtDonated();//non-negative, total amount donate must not grow beyond $2,700
		userid= v.getUserid();//at least 5 characters but no more than 10, only letters and digits
		password = v.getPassword();//at least 6 characters, one digit and one character neither a letter nor a digit)
	}

	//void Voter::operator =(const Voter &v){	}
	Voter::Voter(string str){
				string temp;
				//cout<<str<<"here"<<endl;
				stringstream stream;
				stream<<str;
				getline(stream, lName, ',' );// read a string until next comma

				getline ( stream, fName, ',' );
				getline ( stream, userid, ',' );   
				getline ( stream, password, ',' );
				getline ( stream, temp, ',' );
				age = stoi(temp);
				getline ( stream, temp, ',' );
				streetNum = stoi(temp);
				getline ( stream, streetName, ',' );
				getline ( stream, town, ',' );
				getline ( stream, zipCode, ',' );
				getline ( stream, temp);
				amtDonated = stof(temp);
				//cout<<"please get here"<<endl;
	}

	/*Voter Voter::operator =(const Voter &v){		
		cout<<lName<<" assignment"<<endl;
		 lName = v.getLName();
		cout<<"assignment22"<<endl;
		 fName = v.getFName();
		 age = v.getAge();
		 streetNum = v.getStreetNum();
		 streetName = v.getStreetName();//may include multiple words separated by spaces or tabs
		 town = v.getTown();//may also include multiple words separated by spaces or tabs
		 zipCode= v.getZipCode();//contains exactly 5 digits
		 amtDonated = v.getAmtDonated();//non-negative, total amount donate must not grow beyond $2,700
		 userid= v.getUserid();//at least 5 characters but no more than 10, only letters and digits
		 password = v.getPassword();//at least 6 characters, one digit and one character neither a letter nor a digit)
		cout<<"assignment2"<<endl;
	}*/

void Voter::update(){
	string temp;
	char ctemp;
	bool valid;	
	
	cout<< ": \nLast Name is currently: " << lName<<"\n";
	cin.ignore();		
	ctemp = cin.get();
	if(ctemp != '\n'){
		getline(cin,temp);
		lName = ctemp+temp;}
		
	cout<< "First Name is currently: " << fName<<"\n";
	ctemp = cin.get();
	if(ctemp != '\n'){
		getline(cin,temp);
		fName = ctemp+temp;}

	cout<< "Age is currently: " << age<<"\n";
	//cin.ignore();	
	ctemp = cin.get();
	if(ctemp != '\n'){
		getline(cin,temp);
		
		age = stoi(ctemp+temp);}
	cout<<age;
	//if (temp!="\n")
		//age = stoi(temp); //TODO Recognize line breaks

	cout<< "House Number is currently: " << streetNum<<"\n";
	ctemp = cin.get();
	if(ctemp != '\n'){
		getline(cin,temp);
		streetNum = stoi(ctemp+temp);}
	cout<<streetNum;

	cout<< "Street Name is currently: " << streetName<<"\n";
	ctemp = cin.get();
	if(ctemp != '\n'){
		getline(cin,temp);
		streetName = ctemp+temp;}

	cout<< "Town is currently: " << town<<"\n";
	ctemp = cin.get();
	if(ctemp != '\n'){
		getline(cin,temp);
		town = ctemp+temp;}
	//cout<<town;

	cout<< "Zip Code is currently: " << zipCode<<"\n";
	ctemp = cin.get();
	string temp2;
	if(ctemp != '\n'){
		getline(cin,temp2);
		temp+= ctemp+temp2;
		valid = false;
		if(temp.length() == 5)
			valid = true;
		while(!valid){
			cout<< "Please enter a valid Zip Code: ";	
			cin>>temp;
			if(temp.length() == 5)
				valid = true;
			}
		if(valid)
			zipCode = temp;
	}
}
	

void Voter::view(){
	
	cout<< ": \nDonor Info:\n" << fName <<" " <<lName<<": age "
		<< age<< "\n" << streetNum <<" " << streetName << "\n" << town
		<< " " << zipCode << "\nCurrent Amount Donated: $"
		<< amtDonated<< "\n\n";
}

void Voter::donate(){
		float donation;
		cout<<": \nEnter Amount to Donate: ";
		cin>>donation;
		if(donation>=0 && amtDonated+donation<=2700.0){
			amtDonated+=donation;
			cout << fixed << setprecision(2);
			cout<<"$"<<donation<< " donated.\n";}
		else{ cout<<"Invalid donation.\n";}
}
	
	string Voter::getUserid() const{return userid;} //getters
	string Voter::getPassword() const{return password;}
	string Voter::getLName()const{return lName;	}
	string Voter::getFName()const{return fName;	}
	int Voter::getAge()const{return age;}
	int Voter::getStreetNum()const{return streetNum;}
	string Voter::getStreetName()const{return streetName;}
	string Voter::getTown()const{return town;}
	string Voter::getZipCode()const{return zipCode;}
	float Voter::getAmtDonated()const{return amtDonated;}

	bool Voter::changePassword(){
		string oldPassword;
		string newPassword1;
		string newPassword2;

		cout<< ": \nCurrent password: ";
		cin>>oldPassword;
		
		if(oldPassword==password){
			cout<< ": \nNew password: ";
			cin>>newPassword1;
			bool valid = false;
			if(newPassword1.length()>=6){
				bool digit = false;
				bool nonAlNum = false;		
				for(unsigned int i = 0; i<newPassword1.length();i++){
						if(isalnum(newPassword1[i])==0)
							nonAlNum = true;
						if(isdigit(newPassword1[i]))
								digit = true;
					}
				valid = digit && nonAlNum;
				//cout<<valid;
				}
			while(!valid){
				cout<< "\nPlease enter a valid Password: ";
				cin>>newPassword1;
				if(newPassword1.length()>=6){
					bool digit = false;
					bool nonAlNum = false;		
					for(unsigned int i = 0; i<newPassword1.length();i++){
						if(isalnum(newPassword1[i])==0)
							nonAlNum = true;
						if(isdigit(newPassword1[i]))
							digit = true;
						}
					valid = digit && nonAlNum;
				}
			}
			cout<< ": \nEnter new password again: ";
			cin>>newPassword2;
			if (newPassword1 == newPassword2){
				password = newPassword1;
				return true;
			}
		
	}
	return false;
}

	void Voter::report(){
		cout << std::fixed;
		cout<< ": \n";
		cout<<setprecision(2)<<lName<< " " <<"$"<<amtDonated<< "\n";
	}

	/*Voter Voter::load(string fileName){
		string temp;
		ifstream file (fileName); // declare file stream
		getline ( file, lName, ',' );// read a string until next comma
		getline ( file, fName, ',' );
		getline ( file, userid, ',' );   
		getline ( file, password, ',' );
		getline ( file, temp, ',' );
		age = stoi(temp);
		getline ( file, temp, ',' );
		streetNum = stoi(temp);
		getline ( file, streetName, ',' );
		getline ( file, town, ',' );
		getline ( file, zipCode, ',' );
		getline ( file, temp, ',' );
		amtDonated = stof(temp);
		file.close()
		return *this;
	}*/

	string Voter::save(){
		string ret;
		//ofstream file (fileName, ios::app); // declare file stream
		stringstream stream;
		stream << fixed << setprecision(2) << amtDonated;
		ret=lName+","+fName+","+userid+","+password+","+to_string(age)+","+to_string(streetNum)+","+
			streetName+","+town+","+zipCode+","+stream.str()+"\n";//+
		return ret;
		/*file << lName <<",";
		file << fName <<",";
		file << userid <<",";		
		file << password <<",";
		file << age <<",";
		file << streetNum <<",";
		file << streetName <<",";
		file << town <<",";
		file << zipCode <<",";
		file << amtDonated <<"\n";
  		file.close();
		*/
	}

	void Voter::menu(){
		bool quit = false;
	while(!quit){
		string input;
		cout<<"\nEnter a command. \nChoose from [\"Update\" \"Passwd\"   \"Report\" \"View\" \"Donate\" \"Logout\"]\n";//\"Update\" \"View\" \"Donate\"
		cin>>input;
		//cout<<input<<"\n";
		if (input == "Update")
			update();//lName,fName,age,streetNum,streetName,town,zipCode,amtDonated
		else if (input == "Passwd"){
			if(changePassword()){
				cout<<"\nPassword change successful! ";
			}
			else{cout<<"\nPassword change unsuccessful. ";}
			}
		else if (input == "Report")
			report();
		else if (input == "View")
			view();
		else if (input == "Donate")
			donate();
		else if (input == "Logout"){
			cout<< ": ";			
			quit = true;
		}
		else cout<<": Command not recognized. Please try again.\n";
	}
	}
	





