#include "UserInteraction.h"
#include <iostream>
#include <string> 

using namespace std;

int main(){
	UserInteraction userInter;
	int oper;
	char answer;
	
	cout << endl<< "\tWelcome to the transaction-chain application"<< endl; 
	do{
		cout << endl<< "Please choose which operation do you want to make (1,2,3):" << endl;
		cout << "1) Input File " << endl
			 << "2) Add a user " << endl
			 << "3) Find a user " << endl
			 << "4) Find a user's details " << endl
			 << "5) Recommend friends " << endl
			 << "Please enter the number: ";
			 
		while(!(cin>>oper)) {
				cin.clear();
				cin.ignore(999,'\n');
				cout <<endl <<"Invalid data type! Enter 1,2,3,4 or 5. Try again"<< endl;
				cout << "Please enter the number: ";
			}
		if (oper == 1){
			userInter.inputFile();
		}	
		cout << endl << "Do you want to continue again? (y/n): ";
		cin >> answer;
	}while (answer == 'y');
	
	return 0;
}