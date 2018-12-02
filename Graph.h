#ifndef _GRAPH
#define _GRAPH
#include <vector>
#include <stack> 
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