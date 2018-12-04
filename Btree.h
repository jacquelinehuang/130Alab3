#include "BTreeNode.h"

class Btree
{

    private:
      BTreeNode* current; //node currently on
      BTreeNode* root; //root of btree

      //helper funcs for insert
      void splitnode(BTreeNode* x, BTreeNode* leftover);
      int fixkeys (BTreeNode *x, int index); //traverse and find key to be at this index
      Entry* searchHelper(int perm, BTreeNode* x); //helps w recursion search

    public:
      Btree(Entry *e);//making a new tree, which must start with some entry so we dont have all -1s
      bool insert(Entry *item); //attempts to insert. tells us if it is possible unless it already exists

      Entry* search(int perm);//returns leaf node or NULL of where this perm exists

      void traverse(BTreeNode *p); //traverse from root


};
