#include "BTreeNode.h"
//#include "Entry.h"

class Btree
{

    private:
      BTreeNode* current; //node currently on
      BTreeNode* root; //root of btree
      int height; // height of tree so far unnecessary so ?? we'll see
	  int numOfElms;

    public:
      Btree();
      //making a new tree, which gives a root that is a default node with keys set to -1
      //  void insert(User u, int index);

      bool abletoadd(int item);
      void splitnode(int keyindex, int item);

      int search(int perm, BTreeNode* x); //returns leaf node or NULL of where this perm exists
      void traverse(BTreeNode *p); //traverse from root


};