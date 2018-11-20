include "User.h"

// A BTree node 
class BTreeNode 
{ 
    int *keys;  // An array of keys 
    int t;      // Minimum degree (defines the range for number of keys) 
    BTreeNode **C; // An array of child pointers 
    int n;     // Current number of keys 
    User u; //holds user if leaf condition is true
    bool leaf; // Is true when node is leaf. Otherwise false 
public: 
    BTreeNode(int _t, bool _leaf);   // Constructor 
    // A function to traverse all nodes in a subtree rooted with this node 
    void traverse(); 
    // A function to search a key in the subtree rooted with this node.     
    BTreeNode *search(int k);   // returns NULL if k is not present. 
  
// Make the BTree friend of this so that we can access private members of this 
// class in BTree functions 
friend class BTree; 
}; 


Class Btree
{
    private:
        const int minM = 2;
        const int maxM = 4;
        const int minL = 1;
        const int maxL = 2;
    public:
        bTree()
        void addinBtree(user u);
        bool finduser(int perm);

};