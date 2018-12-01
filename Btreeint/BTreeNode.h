#include <algorithm>

class BTreeNode
{
private:

    int keys [3];  // An array of keys- Max number m-1 =3
    BTreeNode * children[4]; //array of pointers to its children. default to max size 4
    BTreeNode * parent; //parent pointer,
    int countkeys;     // counts number of keys
    int  countEntries; //counts how many entries in a leaf
    bool leaf; // Is true when node is leaf. Otherwise false

    int e1;//  always smaller number
    int e2; //entry 2, larger number

public:
	//node constructor, assuming for insert at leaf.

  //leaf constructor
  BTreeNode (int i){
    leaf= true;
    e1= i;
    countEntries=1;
    parent =NULL;
  }
  //other constructor for  internal nodes
  BTreeNode ()
  {
    leaf = false;
    countkeys = 0;
    countEntries = 0;
    parent =NULL;
    for (int i=0; i<3; i++) {keys [i]=-1;}
    for (int i=0; i<4; i++)
      children[i] = NULL;
  }

  //check that the leaf at this index child index can still hold more entries
  bool leafIsNotFull(int childIndex){
    return ((children[childIndex] == NULL) | (children[childIndex]->countEntries ==1));
  }
  //swap to keep largest entry at e2
  void swapEntries(){
    int temp = e1;
    e1=e2;
    e2=temp;
  }

  //if we need to put more entries into current's leaf nodes
  void insertInLeaf(int childIndex, int i)
  {
    //if current's pointer to child at children[childIndex] is empty
    if(children[childIndex] == NULL)
    {
      //make a totally new node that has e1=i
      BTreeNode * child = new BTreeNode(i); //initializing a new node puts entrycount to 1
      children[childIndex]=child;
      child->parent = this;////SOURCE FOR ERRORS MAYBE??
    }
    //if there is already a leaf node at this child
    else
    {
      //if there is only 1 entry
      if (children[childIndex]->countEntries ==1)       //that means only e1 is pointing to an entry. e2 is open so it will hold the new entry i
      {
      e2 =i;
      //check to make sure e2 still holds largest element
      if (e1>e2) {swapEntries();}
      children[childIndex]->countEntries ++;}
    }
  }

  void splitleaf(int keyIndex, int item){
    //the leaf has overflowed. Lets split it.
    //First lets adjust the keys. Find max btwn the newly inserted element and e2, the current largest elem in the leaf
    int maxNum = std::max(children[keyIndex]->e2, item);
    //replace keyindex with the new key
    keys[keyIndex] = maxNum;
    //if the largest number is e2, then we'll take out e2. Item is now e2, and e2 will move to another leaf
    if(maxNum == children[keyIndex]->e2) {
      insertInLeaf(keyIndex,item);
    }
    //else the largest element is the item we want to inserted
    //either way we have a floating data entry, maxnum. We want to insert maxNum to the next leaf spot

    //try to insert maxnum into the next spot. If it can fit
    if (children [keyIndex+1]->countEntries==0|| children [keyIndex+1]->countEntries==1)
      insertInLeaf(keyIndex+1, maxNum);
    else
      splitleaf(keyIndex+1, maxNum);
  }
// Friend so we can acess data as if it were a struct
friend class Btree;
};
