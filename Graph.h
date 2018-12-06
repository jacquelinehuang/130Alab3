#ifndef _GRAPH
#define _GRAPH
#include <vector>
#include <stack> 
#include "Graph.h"
#include "Btree.h"
#include <iostream>
#include <algorithm>  
#include "User.h"
#include "Entry.h"

class Graph
{
 private:
    std::vector<std::vector <int>> alist;
	bool isFriend(int userIndex, int potentialFriendPerm);
	int  find (int perm);
   public:
    int insertInGraph(std::vector<int> userAndFriends);
	void print();
    void DFS (int perm, BTree* aBTree);

};

#endif