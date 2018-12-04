#include <algorithm>
#include "Entry.h"
#include <iostream>
using std::cout;
using std::endl;

class BTreeNode
{
private:

    int keys [3];  // An array of keys- Max number m-1 =3
    BTreeNode * children[4]; //array of pointers to its children. default to max size 4
    Entry * entries[2]; //array of entries
    BTreeNode * parent; //parent pointer,
    int countkeys;     // counts number of keys
    int  countEntries; //counts how many entries in a leaf
    int countchildren; //counts how many children this node has
    bool leaf; // Is true when node is leaf. Otherwise false

public:
	//node constructor, assuming for insert at leaf.

  //make a new leaf constructor
  BTreeNode (bool isleaf){
    for (int i=0; i<3; i++) {keys [i]=-1;} //no valid keys because is leaf
    leaf= isleaf;
    
    //make nonnull entries that are dummy entries
    entries[0] =new Entry();
    entries[1] =new Entry();
    countEntries=0;
  }

  //make root 
  BTreeNode (Entry* start)
  {
    leaf = false;
    countEntries = 0;
    //default -1 keys 
    for (int i=0; i<3; i++) {keys [i]=-1;}
    //attatch empty leaves.
    for (int i=0; i<4; i++)
    {
      //make all children leaves since it is a root
        children[i] = new BTreeNode(true);
    }
    parent=nullptr;
    cout<<"in constructor for root node."<<endl;

    //adjust to turn to root with one entry and one leaf.
    children[0]->entries[0]=start;
    children[0]->countEntries=1;
    keys[0]=1+start->getkey();

  }

  //other constructor for  internal nodes
  BTreeNode ()
  {
    leaf = false;
    countEntries = 0;
    //default -1 keys 
    for (int i=0; i<3; i++) {keys [i]=-1;}

  }


// Friend so we can acess data as if it were a struct
friend class Btree;
};
