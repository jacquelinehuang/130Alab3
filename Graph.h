#include <vector>
using std::vector

Class Graph 
{
 private:
   vector< vector<int> > v;
    int currentsize;

   public:
    Graph ();
    void addinGraph(int perm);
    void DFS ();

};