#ifndef _GRAPH
#define _GRAPH
#include <vector>
#include <stack> 
#include "Btree.h"
#include <iostream>

class Graph
{
 private:
    std::vector<std::vector <int>> alist;
	bool isFriend(int userIndex, int potentialFriendPerm);
	int  find (int perm);
   public:
    int insertInGraph(std::vector<int> userAndFriends);
	void print();
    std::vector<int> getfriends(int index);
    //searches for new friends with same favorite genre and prints out perms of new friends
    void DFS (int perm, Btree* aBTree);
    void updateGraph(int indexInGraph, int friendPerm);
};

#endif