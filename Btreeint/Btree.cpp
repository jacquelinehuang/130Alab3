#include "Btree.h"
Btree::Btree(){
	numOfElms =0;
	height = 0;
	root = new BTreeNode(); //root is some blank node, which we will replace once we insert more data
	current =root;
}



//method that checks if we can insert without issue. Calls the actual insert and split functions
bool Btree:: abletoadd(int item)
{
	  //when Btrees are created, we initialize an empty root. We start adding entries from there

	//if we search and cannot find the item, then we can insert it
	if (search(item)==nullptr)
	{
		//the pointer, <current> is pointing at the parent where the entry should be inserted.
		//if current has less than 3 keys, a.k.a. we don't need to worry about splitting nodes, only leaves
		if(current ->countkeys < 3){
	      if(item<current->keys[0])
	      {
					//if not full, aka has 1 or 2 entries, insert properly
	        if(current->leafIsNotFull(0)){
	          current ->insertInLeaf(0, item);
	          return true;
	        }else{ //leaf where we want to insert is full but node is not
	            current->splitleaf(0, item);
	        }
	      } else if(keys[1]!=-1 && item>=keys[0] && item<keys[1]) {

	      }
	      else // (item>=key[1] )
	      {}
	    }
	    return false;
	  }
	}

  /*
  if (parent == NULL){ // add in empty root node
    keys[0] = item;
    BTreeNode * child = new BTreeNode(item); //initializing a new node puts entrycount to 1
    children[1]=child;
    child->parent = this;////SOURCE FOR ERRORS
    countkeys++;
    return true;
  }else{
  */


}

voidi Btree:: split (int keyindex, int item)
{}


//search for user given an int.
//return the node where we found user.
//if false ie, cannot find,return nullptr,
//will always update the node pointer "current" to hold the last internal node before the area we want
BTreeNode* Btree::search(int perm)
{
	BTreeNode * x; //keeps track of current node  we're on. Start with root
	x=root;

	//move until currrent becomes a leaf,
	// move current to left, lmid, rmid or r child
	while (x->leaf == false)
	{
		int i =1;

		//3 cases.
		//current has 1 key, aka has M/2 =2 children
		if (x->count ==2)
		{
			if (perm < x->keys[0])
				x = x->children [0]; //move to l child
			if (perm >= x->keys [0])
				x = x->children [1]; //move to r child
		}

		//current has 2 keys, aka 3 children
		if (x->count ==3)
		{
			if (perm < x-> keys[0])
				x = x->children [0]; //move to l child
			if	(perm >x-> keys[0] && perm < x-> keys [1])
				x = x->children [1]; //move to mid
			if (perm >=  x-> keys [1])
				x = x->children [2]; //move to r child
		}
		//Current has 3 keys aka has M =4 children
		if (current->count ==4)
		{
			if (perm < x-> keys[0])
				x = x->children [0]; //move to l child
			if	(perm > x->keys[0] && perm < x-> keys [1])
				x = x->children [1]; //move to lmid
			if	(perm >x-> keys[1] && perm < x-> keys [2])
				x = x-> children [2]; //move to lmid
			if (perm >=x-> keys [2])
				x = x->children [3]; //move to r child
		}

	}

	//x is now a leaf node where the int shoul be.
	current = x->parent; //the variable current now points to the node that is parent to where we want to find/insert the leaf
	if (x->e1->getuser() ->getPerm()==perm || x ->e2->getuser()->getPerm()==perm )
		return x; //return node where the perm exists
	else
		return nullptr; //the leaf node at the correct spot doesn't have what we want.
}

//for sanitycheck's sake but im not even sure this works
void Btree:: traverse(BTreeNode *p)  {}

int main ()
{
  std::cout<<"we have a main folks";
  return 0;
}
