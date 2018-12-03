#include <algorithm>
#include "Entry.h"

class BTreeNode
{
private:

    int keys [3];  // An array of keys- Max number m-1 =3
    BTreeNode * children[4]; //array of pointers to its children. default to max size 4
    Entry entries[2]; //array of entries
    BTreeNode * parent; //parent pointer,
    int countkeys;     // counts number of keys
    int  countEntries; //counts how many entries in a leaf
    int countchildren; //counts how many children this node has
    bool leaf; // Is true when node is leaf. Otherwise false

public:
	//node constructor, assuming for insert at leaf.

  //make a new leaf constructor
  BTreeNode (BTreeNode * p){
    leaf= true;
    parent =p;
  }

  //other constructor for  internal nodes
  BTreeNode ()
  {
    leaf = false;
    countEntries = 0;
    //default -1 keys 
    for (int i=0; i<3; i++) {keys [i]=-1;}
    //attatch empty leaves.
    for (int i=0; i<4; i++)
      children[i] = new BTreeNode (this);

  }


// Friend so we can acess data as if it were a struct
friend class Btree;
};
