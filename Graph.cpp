#include "Graph.h"
#include <iostream>

int Graph::insertInGraph(std::vector<int> userAndFriends){
	// first elm of userAndFriends is userPerm and nextElms are friends' perms
	alist.push_back(userAndFriends);
	
	//returns graph's index where it was inserted
	// we need it for BTree 
	return alist.size()-1;
}
void Graph::print(){
	std::cout  <<std::endl;
	
	for (int i=0; i<alist.size(); i++){
		std::cout<< "User's Perm: "<< alist[i][0] << "; friends: " ;
		for (int j=1; j<alist[i].size(); j++){
			std::cout<< " "<< alist[i][j]  ;
		}
		std::cout  <<std::endl;
	}
}