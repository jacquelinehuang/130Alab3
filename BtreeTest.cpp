#include "Btree.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
#include <vector>

//tester class to make sure btree works properly. not quite sure how to write this test class yet either
int main ()
{

	std::ifstream ifs;
	
	std::string userInfo;
	std::string semicolon = ";";
	size_t pos = 0;

	std::string name, genre1, genre2;
	int userPerm;
	std::vector<Entry*> entrymaker;
	
	
	ifs.open("textFile.txt");
	if (ifs.fail()){
		std::cout<< "Couldn't find text file" << std::endl;
	}
	
	//read whileloops
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

		//make entries from data read with default position 1. 
		//cout<<"perm name are:"<<userPerm<<" "<<name<<endl;
		entrymaker.push_back(new Entry (new User(userPerm, name, genre1, genre2), 1) );
		
	}

	//node making test
	//Btree *temp = new Btree (new Entry (new User (123, "aa","aa","aa"),1) );
	//cout<<"make test tree with  perm: 123"<<endl;


	
	Btree *aBTree=new Btree(entrymaker[0]);	
	cout<<"make tree with  perm: "<<entrymaker[0]->getkey()<<endl;
	//inserts
	for (unsigned int i=1; i < entrymaker.size(); i++)
	 {
		//inserting in a graph and a tree
		aBTree->insert(entrymaker[i]);
		//cout<<"TESTCLASS MESSAGE inserted perm: "<<entrymaker[i]->getkey()<<endl;	

	}
	//insert to see if it picksup somethiing is wrong 
	cout<<"make duplicate perm. what does it say?"<<endl;
	aBTree->insert(new Entry (new User (1, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (3, "aa","aa","aa"),1) );

	//please work
	cout<< "\nsearching for, 1 returns: " <<aBTree->search(1)->getkey()<<endl;
	cout<< "searching for 8, returns: " <<aBTree->search(8)->getkey()<<endl;
	cout<< "searching for, 5 returns: "<< aBTree->search(5)->getkey()<<endl;
	cout<< "searching for, 6 returns: " <<aBTree->search(6)->getkey()<<endl;
	cout<< "searching for, 71 returns: " <<aBTree->search(71)->getkey()<<endl;
	cout<< "searching for, 12 returns: " <<aBTree->search(12)->getkey()<<endl;
	cout<< "searching for, 57 returns: " <<aBTree->search(57)->getkey()<<endl;
	
	return 0;
}