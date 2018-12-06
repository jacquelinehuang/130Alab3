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
	std::vector<Entry*> entrymaker, entrymaker2;
	
	
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


	ifs.close();
	
	Btree *aBTree=new Btree(entrymaker[0]);	
	cout<<"make tree with  perm: "<<entrymaker[0]->getkey()<<endl;
	//inserts
	for (unsigned int i=1; i < entrymaker.size(); i++)
	 {
		//inserting in a graph and a tree
		aBTree->insert(entrymaker[i]);
		//cout<<"TESTCLASS MESSAGE inserted perm: "<<entrymaker[i]->getkey()<<endl;	

	}

	cout<<"insert new perms"<<endl;
	ifs.open("weirdtextfile.txt");
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
		entrymaker2.push_back(new Entry (new User(userPerm, name, genre1, genre2), 1) );
		
	}

	for (unsigned int i=0; i < entrymaker2.size(); i++)
	 {
		//inserting in a graph and a tree
		aBTree->insert(entrymaker2[i]);
		//cout<<"TESTCLASS MESSAGE inserted perm: "<<entrymaker[i]->getkey()<<endl;	

	}

	cout<<"out of loop2"<<endl;

//rando order  test

	aBTree->insert(new Entry (new User (999, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (607, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (110, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (1482, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (108, "aa","aa","aa"),1) );	
	aBTree->insert(new Entry (new User (994, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (244, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (0, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (153, "aa","aa","aa"),1) );
	//problemarises here 
	aBTree->insert(new Entry (new User (125, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (199, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (110, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (1092, "aa","aa","aa"),1) );
	aBTree->insert(new Entry (new User (385, "aa","aa","aa"),1) );


	cout<<aBTree->search(1231)->getkey()<<aBTree->search(1231)->getuser()->getName()<<endl;
	cout<<aBTree->search(142)->getkey()<<aBTree->search(142)->getuser()->getName()<<endl;
	cout<<aBTree->search(993)->getkey()<<aBTree->search(993)->getuser()->getName()<<endl;
	cout<<aBTree->search(108)->getkey()<<aBTree->search(108)->getuser()->getName()<<endl;
	cout<<aBTree->search(109)->getkey()<<aBTree->search(109)->getuser()->getName()<<endl;
	cout<<aBTree->search(116)->getkey()<<aBTree->search(116)->getuser()->getName()<<endl;
	cout<<aBTree->search(1117)->getkey()<<aBTree->search(1117)->getuser()->getName()<<endl;
	cout<<aBTree->search(900)->getkey()<<aBTree->search(900)->getuser()->getName()<<endl;
	cout<<aBTree->search(607)->getkey()<<aBTree->search(607)->getuser()->getName()<<endl;
	cout<<aBTree->search(153)->getkey()<<aBTree->search(153)->getuser()->getName()<<endl;

		//please work
	cout<< "\nsearching for, 1 returns: " <<aBTree->search(1)->getkey()<<endl;
	cout<< "searching for 8, returns: " <<aBTree->search(8)->getkey()<<endl;
	cout<< "searching for, 5 returns: "<< aBTree->search(5)->getkey()<<endl;
	cout<< "searching for, 6 returns: " <<aBTree->search(6)->getkey()<<endl;
	cout<< "searching for, 17 returns: " <<aBTree->search(17)->getkey()<<endl;
	cout<< "searching for, 12 returns: " <<aBTree->search(12)->getkey()<<endl;
	cout<< "searching for, 25 returns: " <<aBTree->search(25)->getkey()<<endl;
	cout<< "searching for, 29 returns: " <<aBTree->search(29)->getkey()<<endl;
	cout<< "searching for, 57 returns: " <<aBTree->search(57)->getkey()<<endl;
	cout<< "searching for, 107 returns: " <<aBTree->search(107)->getkey()<<endl;
	cout<< "searching for, 89 returns: " <<aBTree->search(89)->getkey()<<endl;
	cout<< "searching for, 154 returns: " <<aBTree->search(999)->getkey()<<endl;
	cout<< "searching for, 244 returns: " <<aBTree->search(607)->getkey()<<endl;
	cout<< "searching for, 0 returns: " <<aBTree->search(110)->getkey()<<endl;
	cout<< "searching for, 173 returns: " <<aBTree->search(1482)->getkey()<<endl;
	cout<< "searching for, 108 returns: " <<aBTree->search(108)->getkey()<<endl;
	cout<< "searching for, 125 returns: " <<aBTree->search(994)->getkey()<<endl;
	cout<< "searching for, 109 returns: " <<aBTree->search(244)->getkey()<<endl;
	cout<< "searching for, 110 returns: " <<aBTree->search(0)->getkey()<<endl;
	cout<< "searching for, 111 returns: " <<aBTree->search(153)->getkey()<<endl;	
	cout<< "searching for, 305 returns: " <<aBTree->search(125)->getkey()<<endl;
	cout<< "searching for, 125 returns: " <<aBTree->search(199)->getkey()<<endl;
	cout<< "searching for, 110 returns: " <<aBTree->search(110)->getkey()<<endl;
	cout<< "searching for, 111 returns: " <<aBTree->search(1092)->getkey()<<endl;	
	cout<< "searching for, 305 returns: " <<aBTree->search(385)->getkey()<<endl;

	return 0;
}