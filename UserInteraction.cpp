#include "UserInteraction.h"
#include <fstream>
#include <iostream>
#include <vector>

void UserInteraction::inputFile(){
	std::ifstream ifs;
	
	std::string userInfo;
	std::string semicolon = ";";
	size_t pos = 0;
	std::string name, genre1, genre2;
	int userPerm;
	std::vector<int> userAndFriends;
	
	
	ifs.open("textFile.txt");
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
		/*std::cout << "newUser perm: "<< newUser.getPerm() << std::endl
				<< "newUser name: "<< newUser.getName() << std::endl
				<< "newUser g1: "<< newUser.getGenre1() << std::endl
				<< "newUser g2: "<< newUser.getGenre2() << std::endl;
		*/	
		userAndFriends.push_back(userPerm);	
		int count =1;
		while ((pos = userInfo.find(semicolon)) != std::string::npos) {
			userAndFriends.push_back( std::stoi(userInfo.substr(0, pos)));
			userInfo.erase(0, pos + semicolon.length());
			count++;
		}
		userAndFriends.push_back( std::stoi(userInfo));
		
		//inserting in a graph and a tree		
		int index = aGraph.insertInGraph(userAndFriends);
		//aBTree.insertInBTree(newUser, index);
		
		
		// will need to clean vector after each user!!!!
		userAndFriends.clear();
	}
	aGraph.print();
}
void UserInteraction::reccomendfriends (int perm){
	//aGraph.DFS(perm, aBTree);
}
