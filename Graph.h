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
    void addrelation(int u, int v) 
    {
        alist[u].pushback(v);
        alist[v].pushback(u);
    }

    //we shouldhave a check for this. See if u and v are already related 

    std::vector<int> getfriends(int index);

};

#endif