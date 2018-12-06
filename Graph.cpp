
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
//neended for debugging dfs
int Graph::find (int perm){
	for (int i=0; i<alist.size();i++){
		if (perm == alist[i][0])
			return i;
	}
}
// checks if two users are friends
bool Graph::isFriend(int userIndex, int potentialFriendPerm){
	for (int i=0; i<alist[userIndex].size();i++){
		if (alist[userIndex][i] == potentialFriendPerm)
			return true;
	}
	return false;
}
void Graph::DFS (int perm, BTree* aBTree){
	std::vector<bool> alistIsVisited(alist.size(), false);
	std::stack <int> aStack; 
	std::vector<User> recommendations;
	std::string genre1, genre2;
	User nonFriend, user;
	int indexOfUserInTable, index, j;
	Entry anEntry;
	
	anEntry = aBTree->search(perm);
	index = anEntry.getuserindex();
	user = anEntry.getuser();
	indexOfUserInTable = index;
	genre1 = anEntry.getuser.getGenre1();
	genre2 = anEntry.getuser.getGenre2();
	alistIsVisited[index] = true;
	aStack.push(index);
	
	while (!aStack.empty()){
		for(int i=1; i<alist[index].size(); i++){
			j=find(alist[index][i]);
			if (alistIsVisited[j]==false){
				aStack.push(j);
				alistIsVisited[j] =true;
			}
		}
		index =aStack.top();	
		aStack.pop();
		
		if (!isFriend(indexOfUserInTable, alist[index][0])){
			nonFriend = aBTree->search(alist[index][0]).getuser();
			if (genre1 == nonFriend.getGenre1() | genre1 == nonFriend.getGenre2() | genre2 == nonFriend.getGenre1() | genre2 == nonFriend.getGenre2())
				recommendations.push_back(nonFriend);
		}		
	}
	/*sort(perms.begin(), recommendations.end()); 
  
    std::cout << "Sorted \n"; 
    for (auto x : perms) 
        std::cout << x << ", "; */
}






