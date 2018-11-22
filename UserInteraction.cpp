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
	std::vector<int> friends;
	
	
	ifs.open("textFile.txt");
	if (ifs.fail()){
		std::cout<< "Couldn't find text file" << std::endl;
		return;
	}
	//while (!ifs.eof()) { 
		ifs >> userInfo;
		//word[0] = tolower(word[0]);
		//dataObject.insert(word);
		//std::cout<<"userInfo: " <<userInfo<< std::endl;
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
		int count =0;
		
		User newUser (userPerm, name, genre1, genre2);
		std::cout << "newUser perm: "<< newUser.getPerm() << std::endl
				<< "newUser name: "<< newUser.getName() << std::endl
				<< "newUser g1: "<< newUser.getGenre1() << std::endl
				<< "newUser g2: "<< newUser.getGenre2() << std::endl;
				
		while ((pos = userInfo.find(semicolon)) != std::string::npos) {
			friends.push_back( std::stoi(userInfo.substr(0, pos)));
			std::cout << "friends: " << friends[count] << std::endl;
			userInfo.erase(0, pos + semicolon.length());
			count++;
		}
		
		friends.push_back( std::stoi(userInfo));
		std::cout << "friends: " << friends[count] << std::endl;
	//}
}
