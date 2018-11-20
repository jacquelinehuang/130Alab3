include "User.h"

const int MAXM = 4;   // max number of keys in a node
const int MINM = 2;    // min number of keys in a node
const int MAXL = 2  // max no of elements per leaf

// A BTree node
class BTreeNode
{
    int keys [M];  // An array of keys
    int count;     // Current number of keys
    User u1;    //if leaf u1 and u2 can be not null
    User u2;
    bool leaf; // Is true when node is leaf. Otherwise false

// Make the BTree friend of this so that we can access private members of this
// class in BTree functions
friend class Btree;
};


Class Btree
{
    private:
      BTreeNode* currentnode;
      BTreeNode* root;

    public:
        bTree()
        void insert(user u);
        bool finduser(int perm);
        void traverse ()


};
