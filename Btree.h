#include "User.h"
#include "BTreeNode.h"
#include "Entry.h"
// A BTree node

class Btree
{

    private:
      BTreeNode* current; //node currently on
      BTreeNode* root; //root of btree
      int height; // height of tree so far unnecessary so ?? we'll see
	  int numOfElms;

    public:
        Btree();
        //making a new tree, which gives a node that is a leaf 
        Btree(Entry *en1, Entry *en2);
        void insert(User u, int index);
        int split (BTreeNode *x, int i);
        BTreeNode* search(int perm); //returns leaf node or NULL of where this perm exists 
        void traverse(BTreeNode *p); //traverse from root 


};
