#include <iostream>
#include <stdlib.h>   
#include <iomanip>      // std::setprecision
#include <fstream>
#include "VoterDB.h"

using namespace std;

VoterDB::VoterDB(int mymaxVoters){
		voterArr = new Voter[mymaxVoters];
		curNumOfVoters = 0;
		maxVoters=mymaxVoters;
		//cout<<maxVoters;
	}
VoterDB::~VoterDB(){
	//cout<<"deocon";
	delete []voterArr;
}

VoterDB::VoterDB(int mymaxVoters, string fileName){
		voterArr = new Voter[mymaxVoters];
		curNumOfVoters = 0;
		voterArr[0] = Voter();
		maxVoters=mymaxVoters;
		//cout<<"max voters"<<maxVoters;
		//ifstream file(fileName); // declare file stream
		Voter temp;
		int index = 0;
		load(fileName);
		cout<<"Database has been loaded.";
		/*while ( file.good() )
		{
			if(index<maxVoters){
				voterArr[index] = load(fileName);			
			}		 
		}*/
		//TODO Load in file info from fileName
		//Use Voter's load and save methods
	}

bool VoterDB::login(){
	string userid;
	cout<< ": \nUserid: ";
	cin>>userid;
	//cout<<"here";
	string password;
	cout<< ": \nPassword: ";
	//cout<<"here";
	cin>>password;
	//cout<<voterArr[0].getUserid()<<endl;
	bool ret = false;
	int index = -1;
	//cout<<voterArr[3].getUserid();//testing
	//cout<<"here"<< endl;
	for (int i = 0; i<curNumOfVoters; i++){//loop through accs arr and if it matches turn ret to true
		//cout<<"looping"<<endl;
		//Voter temp = voterArr[i]; 
		//cout<<"looping2"<<endl;
		if(voterArr[i].getUserid() == userid && voterArr[i].getPassword() == password)
		{
			//cout<<"found it"<<endl;
			ret = true;
			index = i; 
		}
	
	}
	//cout<<"userid: "<<userid<< " password "<< password;
	if (ret)
		voterArr[index].menu();
	else{cout<<"Invalid login";}
		
	//Check if creds match a current voter account
	return ret;
}

bool VoterDB::newAcc(){
	
	string userid;
	cout<< ": \nUserid: ";
	cin>>userid;//contains at least 5 characters but no more than 10, 
			//containing only letters and digits
	bool valid = false;
	//cout<<maxVoters;
	if(curNumOfVoters==maxVoters){
		cout<<"At maximum amount of voters.";
		return false;
		}
	if (userid.length()>=5 && userid.length()<=10){
		bool temp = true;
		for(int i = 0; i<userid.length();i++){
			if(isalnum(userid[i])==0)
				temp = false;
		}
			bool temp2 = true;
			for (int i = 0; i<curNumOfVoters; i++){
				Voter temp = voterArr[i]; 
				if(temp.getUserid() == userid)
				{
					temp2 = false;
				}
	
			}
			if (temp && temp2){
				valid = true;
				//cout<<"valid";
			}
	}
	while(!valid){
		cout<< ": \nPlease enter a valid Userid: ";
		cin>>userid;
		
		if (userid.length()>=5 && userid.length()<=10){
			bool temp = true;
			for(int i = 0; i<userid.length();i++){
				if(isalnum(userid[i])==0)
					temp = false;
			}
			bool temp2 = true;
			for (int i = 0; i<curNumOfVoters; i++){
				Voter temp = voterArr[i]; 
				if(temp.getUserid() == userid)
				{
					temp2 = false;
				}
	
			}
			if (temp && temp2){
				valid = true;
				//cout<<"valid";
			}
		}
	}

	//TODO
	//Check that userid is not in use, is valid, and is not creating more than  
	//maximum allowable number of voters 	

	cout<< ": \nLast Name: ";
	string lName;
	cin>>lName;
	/*if(lName.length() == 0)
		lName = "[empty]";*/

	cout<< "First Name: ";
	string fName;
	cin>>fName;
	/*if(fName.length() == 0)
		fName = "[empty]";*/

	cout<< "Age: ";
	int age;
	cin>>age;

	cout<< "House Number: ";
	int streetNum;
	cin>>streetNum;

	cout<< "Street Name: ";
	string streetName;
	cin.ignore();	
	getline(cin,streetName);

	cout<< "Town: ";
	string town;
	//cin.ignore();	
	getline(cin,town);

	string zipCode;
	cout<< "Zip Code: ";	
	cin>>zipCode;

	valid = false;
	if(zipCode.length() == 5)
		valid = true;
	while(!valid){
		cout<< "Please enter a valid Zip Code: ";	
		cin>>zipCode;
		if(zipCode.length() == 5)
			valid = true;
	}
	//make sure it is valid	
	

	string password;
	cout<< "Password: ";
	cin>>password;
	
	valid = false;
	if(password.length()>=6){
		bool digit = false;
		bool nonAlNum = false;		
		for(int i = 0; i<password.length();i++){
				if(isalnum(password[i])==0)
					nonAlNum = true;
				if(isdigit(password[i]))
					digit = true;
			}
		valid = digit && nonAlNum;
	}
	while(!valid){

		cout<< "Please enter a valid Password: ";
		cin>>password;
		if(password.length()>=6){
		bool digit = false;
		bool nonAlNum = false;		
		for(int i = 0; i<password.length();i++){
				if(isalnum(password[i])==0)
					nonAlNum = true;
				if(isdigit(password[i]))
					digit = true;
			}
		valid = digit && nonAlNum;
		}

	}
	//make sure it is valid	

	float amtDonated;
	amtDonated = 0;
	voterArr[curNumOfVoters] = Voter(userid, password, lName,fName,age,streetNum,streetName,town,zipCode);
	// = tempVoter;
	curNumOfVoters++;
	//cout<<"userid: "<<userid<<endl;
	//cout<<"userid: "<<tempVoter.getUserid()<<endl;
	//cout<<"userid: "<<voterArr[0].getUserid()<<endl;
	return true;
}

	

void VoterDB::report(){
	float sum;
	for (int i = 0; i<curNumOfVoters; i++){
		Voter temp = voterArr[i];
		sum+= temp.getAmtDonated();
	} 
	cout << std::fixed;
	cout<< ": \n";
	cout<<setprecision(2)<<"There are "<<curNumOfVoters<< " voters in the database, contributing a total of"
	<< " " <<"$"<<sum<< "\n";
	
}

bool VoterDB::save(){
	cout<<"Where should the database be saved? \n";
	string output;
	cin>>output;

	ifstream f(output);
	if (f.good()){
		string overwrite;
		cout<<"Do you want to overwrite the file with the same name? [y/n]\n";
		cin>>overwrite;
		if(overwrite=="y"){
			ofstream file (output); // declare file stream
			for (int i = 0; i<curNumOfVoters; i++){
				Voter temp = voterArr[i];
				file<<temp.save();
				cout<<"saved "<<temp.getUserid()<<endl;
			} 
		}else{return false;}
	}
	else{
		ofstream file;
		file.open(output);
		for (int i = 0; i<curNumOfVoters; i++){
				Voter temp = voterArr[i];
				file<<temp.save();
		}
		file.close();	
	}
	return true;
}
/*  store all current voter database information, including voter account information and
amounts donated, into a file. After the user enters “Save”, your program should prompt her for the
name of the file to save the information to, and should open that file and write into it. If the file exists,
your program should warn the user that it exists and offer to overwrite its contents or allow the user to
select a different file. The file should be stored as comma separated values text file with a .csv
extension.
*/
		

bool VoterDB::load(string input){
	if (input == ""){	
		cout<<"Where should the database be loaded from? \n";
		cin>>input;
	}
	ifstream file(input);
	if(file.is_open()){
		string lName;
		string fName;
		string userid;//contains at least 5 characters but no more than 10, containing only letters and digits
		string password;//least 6 chars,at least one digit and one neither a letter nor a digit		
		int age;
		int streetNum;
		string streetName;//may include multiple words separated by spaces or tabs
		string town;//may also include multiple words separated by spaces or tabs
		string zipCode;//contains exactly 5 digits
		float amtDonated;//non-negative, total amount donate must not grow beyond $2,700
		string temp;
		stringstream stream;
		getline(file,temp);
		//cout<<"temp: "<<temp<<endl;
		while(curNumOfVoters<maxVoters && file.good()){
			//stream<<temp;
			voterArr[curNumOfVoters] = Voter(temp);
			//cout<<"please get here"<<endl;
			curNumOfVoters++;
			getline(file,temp);
		}
			
		/*string temp;
		temp = "\n";
		cout<<"problem?"<<endl;
		while(curNumOfVoters<maxVoters && temp =="\n"){
				  getline(file, lName, ',' );// read a string until next comma
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
				getline ( file, temp);
				amtDonated = stof(temp);
				Voter tempVoter;
				cout<<"problem!!? userid:"<<userid<<endl;
				voterArr[curNumOfVoters] = Voter(userid, password, lName,fName,age,streetNum,streetName,town,zipCode);
				//cout<<tempVoter.getLName()<<" problem!!? "<<curNumOfVoters<<endl;
				 //= tempVoter;
				cout<<"problem!!?"<<endl;
				curNumOfVoters++;
		}*/
	return true;	
	}else{return false;}
}
/*  
restore voter information from a .csv file, including voter information and amounts
donated. Again, the user should be prompted for the name of the file, and any existing voter
information “imemory” should simply be overwritten by the contents of the file.
*/

void VoterDB::menu(){
	bool quit = false;
	while(!quit){
		//cout<<"some thing"<<endl;
		string input;
		cout<<"\nEnter a command. \nChoose from [\"Login\" \"New\"   \"Report\" \"Save\" \"Load\" \"Quit\"]\n";//\"Update\" \"View\" \"Donate\"
		cin>>input;
		//cout<<input<<"\n";
		if (input == "New")
			newAcc();
		else if (input == "Login")
			login();
		else if (input == "Save")
			save();
		else if (input == "Load")
			load("");
		else if (input == "Report")
			report();
		else if (input == "Quit"){
			cout<< ": ";			
			quit = true;
			break;
		}
		else cout<<": Command not recognized. Please try again.\n";
	}
	
	//cout<<"some thing"<<endl;
}




















