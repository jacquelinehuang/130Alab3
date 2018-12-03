#include "BTreeNode.h"

class Btree
{

    private:
      BTreeNode* current; //node currently on
      BTreeNode* root; //root of btree

    public:
      Btree();
      //making a new tree, which gives a root that is a default node with keys set to -1
      //  void insert(User u, int index);

      bool insert(Entry item);
      void splitnode(BTreeNode* x, Entry item);


      Entry search(int perm);//returns leaf node or NULL of where this perm exists
      Entry searchHelper(int perm, BTreeNode* x);
      void traverse(BTreeNode *p); //traverse from root


};
