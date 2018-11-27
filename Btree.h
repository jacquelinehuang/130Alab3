#include "User.h"
#include "Entry.h"
// A BTree node
class BTreeNode
{

public:
	const int M =4 ;;   // max number of children in a node
	const int MINM = 2;    // min number of children in a node
	const int MAXKEYS = 3; //max no of keys per node
	const int L = 2;  // max no of elements per leaf


	//node constructor, assuming for insert at leaf. 
	BTreeNode (Entry *en1, Entry *en2)
	{
		//initialize as leaf with data
		leaf= true;
		e1= en1;
		e2= en2;
		//keys used and children it has default to 0
		count = 0;
	}

	//Will use setters to fix for nodes created by splitting. 
	//default constructor for internal nodes  
	BTreeNode ()
	{
		leaf = false;
	}

private:

    int keys [MAXKEYS];  // An array of keys- Max number m-1 =3
    BTreeNode * children[M]; //array of pointers to its children. default to max size 4
    BTreeNode * parent; //parent pointer, not sure if this complicates things
    int count;     // counts number of children
    bool leaf; // Is true when node is leaf. Otherwise false
    

    Entry *e1;	//data if it is a leaf. 2 entries can be in a leaf max	
    Entry *e2;

// Friend so we can acess data as if it were a struct 
friend class Btree;
};


class Btree
{

    private:
      BTreeNode* current; //node currently on
      BTreeNode* root; //root of btree
      int height; // height of tree so far unnecessary so ?? we'll see

    public:
        
        //making a new tree, which gives a node that is a leaf 
        Btree(Entry *en1, Entry *en2);
        void insert(User* u);
        int split (BTreeNode *x, int i);
        BTreeNode* search(int perm); //returns leaf node or NULL of where this perm exists 
        void traverse(BTreeNode *p); //traverse from root 


};
