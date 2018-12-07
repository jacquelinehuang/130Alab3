#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
using namespace std;

Graph aGraph;
Btree *aBTree;
std::vector<Entry*> entrymaker;

//Takes reference to a file consisting of user info and makes Btree and friendship graph CHECK!
void inputFile(){
	string filename;
	std::ifstream ifs;
	
	std::string userInfo;
	std::string semicolon = ";";
	size_t pos = 0;
	std::string name, genre1, genre2;
	int userPerm;
	std::vector<int> userAndFriends;

	cout<<"\n1) Reading basefile: "; 
	cin>>filename;
	//filename="textFile.txt"; //use this for testing sake

	ifs.open(filename);
	if (ifs.fail()){
		std::cout<< "Couldn't find text file" << std::endl;
		return;
	}
	
	while (!ifs.eof()) { 
		std::getline(ifs, userInfo);

		pos = userInfo.find(semicolon);
		userPerm = std::stoi(userInfo.substr(0, pos));
		userInfo.erase(0, pos + semicolon.length());
			
		pos = userInfo.find(semicolon);
		name = userInfo.substr(0, pos);
		userInfo.erase(0, pos + semicolon.length());
		
		pos = userInfo.find(semicolon);
		genre1 = userInfo.substr(0, pos);
		userInfo.erase(0, pos + semicolon.length());
		
		pos = userInfo.find(semicolon);
		genre2 = userInfo.substr(0, pos);
		userInfo.erase(0, pos + semicolon.length());
		
		User newUser (userPerm, name, genre1, genre2);		
		//makes entries for graph

		int count=1;
		userAndFriends.push_back(userPerm);	
		while ((pos = userInfo.find(semicolon)) != std::string::npos) {
			userAndFriends.push_back( std::stoi(userInfo.substr(0, pos)));
			userInfo.erase(0, pos + semicolon.length());
			count++;
		}
		userAndFriends.push_back( std::stoi(userInfo));
		
		//inserting in a graph and a tree		
		int index = aGraph.insertInGraph(userAndFriends);

		//inserting
		entrymaker.push_back(new Entry (new User(userPerm, name, genre1, genre2), index) );
		// will need to clean vector after each user!!!!
		userAndFriends.clear();


	}

	//make tree 
	aBTree=new Btree(entrymaker[0]);	
	//inserts
	for (unsigned int i=1; i < entrymaker.size(); i++)
	{
		aBTree->insert(entrymaker[i]);
		//cout<<"TESTCLASS MESSAGE inserted perm: "<<entrymaker[i]->getkey()<<endl;	
	}
	
	ifs.close();
	cout<<"Done reading."<<endl;

	//aGraph.print();
}

//Add a new user to system. Params are a perm, name, 2 favorite genres, and a list of perms
//user info will be added to btree and graph
//friendship graph may have to be updated as well

void add ()
{
	vector <int> userandfriendperms;
	User *u;
	string name, genre1, genre2, friendstring;
	std::string semicolon = ",";
	int perm;

	cout<<"Enter user's name: ";
	cin>>name;
	cout<<"Enter user's perm: ";
	cin>>perm;
	while(std::cin.fail()) {
		std::cout << "Error, not a perm. Type an (integer)" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> perm;
		}
	cout<<"Enter user's favorite genre1: ";
	cin>>genre1;
	cout<<"Enter user's favorite genre2: ";
	cin>>genre2;	
	u= new User (perm, name, genre1, genre2);

	cout<<"Enter perm number of their friends separated by commas: ";
	cin>>friendstring;

	userandfriendperms.push_back(perm);	
	int count =1;
	size_t pos = 0;

	while ((pos = friendstring.find(semicolon)) != std::string::npos) {
		userandfriendperms.push_back( std::stoi(friendstring.substr(0, pos)));
		friendstring.erase(0, pos + semicolon.length());
		count++;
	}
	userandfriendperms.push_back( std::stoi(friendstring));
		
	//inserting in a graph and a tree		
	int index = aGraph.insertInGraph(userandfriendperms);
	//if btree is empty and we add first go here
	if (aBTree==NULL){
		aBTree=new Btree(new Entry(u,index));
	}
	else{//add new user to existing btree
		aBTree->insert(new Entry(u,index));
	}
	//update friend relations 
	int indexInGraph;
	for (int i=1; i<userandfriendperms.size(); i++){
		indexInGraph = (aBTree->search(userandfriendperms[i]))->getuserindex();
		aGraph.updateGraph(indexInGraph, perm);
	}
	
}
//find a user and print if you can find in Btree
bool findUser(int perm)
{
	Entry *result=aBTree->search(perm);

	if (result->getkey()>0)
	{
		std::cout << "We found them!\n";
		return true;
	}
	else
	{
		std::cout << "Cannot find user" << std::endl;
		return false;
	}
}
//search user
//print user details. Using index, it will also print friends
void findUserDetail (int perm)
{
	if (findUser(perm))
	{
		Entry *result=aBTree->search(perm);
		result->getuser()->print();

		int tableindex= result->getuserindex();

		std::vector<int> friendsvector = aGraph.getfriends(tableindex);
		cout<< " has friends: ";
		for (int j=1; j<friendsvector.size(); j++){
			std::cout<< friendsvector[j] << " ";
		}
		//INCOMPLETE GRAPH PORTION HERE
	}
}

//takes perm as input, extracts users favorite genres and friends
//traverse entire adjacency list using dfs and ID all users with at least one genre in common to current user
//filter out users that are already friends with current user.
//print list <permnumber, name, 2genres of each reccomended friend.>
void reccomendfriends (int perm)
{
	aGraph.DFS(perm, aBTree);
}

int main(){

	int oper;
	char answer;
	
	string inputfile;
	cout << endl<< "Welcome to the transaction-chain application. \n"<<endl;
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
			inputFile();
		}	
		if (oper == 2){
			cout<< "\n2) Add a new user\n";
			add();
		}	
		if (oper == 3){
			cout<< "\n3) Find a user.\nInput their perm: ";
			int x;
			std::cin >> x;
			while(std::cin.fail()) {
				std::cout << "Error, not a perm. Type an (integer)" << std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin >> x;
			}
			findUser(x);
		}	
		if (oper == 4){
			cout<< "\n4) Find a user's details.\nEnter their perm: ";
			int x;
			std::cin >> x;
			while(std::cin.fail()) {
				std::cout << "Error, not a perm. Type an (integer)" << std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin >> x;
			}
			findUserDetail (x);			
		}	
		if (oper == 5){
			cout << "\n5) Recommend friends.\nEnter a perm: ";
			int x;
			std::cin >> x;
			while(std::cin.fail()) {
				std::cout << "Error, not a perm. Type an (integer)" << std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin >> x;
			}
			reccomendfriends(x);
		}	
		cout << endl << "Do you want to continue again? (y/n): ";
		cin.clear();
		std::cin.ignore(256,'\n');
		cin >> answer;
	}while (answer == 'y');
	
	return 0;
}