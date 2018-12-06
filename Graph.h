#ifndef _GRAPH
#define _GRAPH
#include <vector>

class Graph
{
 private:
    std::vector<std::vector <int>> alist;

   public:
    //Graph ();
    int insertInGraph(std::vector<int> userAndFriends);
	void print();
    void DFS ();

    //more necessary functions
    void adjustfriends();
    vector<int> getfriends(int index);

};

#endif