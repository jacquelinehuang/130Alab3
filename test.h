
void Graph::DFS (int perm){
	std::vector<bool> alistIsVisited(alist.size(), false);
	std::stack <int> aStack; 
	std::vector<int> perms;
	int j;

	
	int index = find(perm);
	int indexOfUser = index;
	
	
	alistIsVisited[index] =true;
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
		
		if (!isFriend(indexOfUser, alist[index][0]))
			perms.push_back(alist[index][0]);
				
	}
	sort(perms.begin(), perms.end()); 
  
    std::cout << "Sorted \n"; 
    for (auto x : perms) 
        std::cout << x << ", "; 
}