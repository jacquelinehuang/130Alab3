#include "Btree.h"
#include <iostream>
#include <algorithm>    // std::max

Btree::Btree(){
	root = new BTreeNode(); //root is some blank node, which we will replace once we insert more data
	current =root;
}


//insert
//method that tries to insert an entry. Calls the actual insert and split functions
bool Btree:: insert(Entry item)
{
	//current is a leafnode, found as a byproduct of using search. 
	Entry foundentry =search(item.getperm());
	//if we search and cannot find the item, aka negative perm, then we can proceed to inserting
	if (foundentry.getperm()<0)
	{
		
		//then check if leaf is full or not. 
		//.1) If not, then add item to leaf. 
		if (current->countEntries<2)
		{
			//add item to leaf. 
			for (int n=0; n<2; n++)
			{
				//this takes care of if it will be in spot 1 or spot 2. Entries with -1 are considered empty
				// insert at first open spot
				if (current->entries[n].getperm()==-1)
				{
					current->entries[n]=item;
					break;
				}
			}
			current->countEntries++;
			//swap to keep largest entry at entries[1] for simplicity's sake
 			if (current->entries[0].getperm()>current->entries[1].getperm()) //comparison with getperm which calls users getperm
			{
				Entry temp = current->entries[0];
				current->entries[0]=current->entries[1];
				current->entries[1]=temp;
  			}
		}

		//2) If full, then you must split the leaf. 
		else{
			//splitleaf code. basically copy out some of the code into leaf2
			BTreeNode leaf2;
			leaf2= new BTreeNode(current->parent); //leaf2 is a new node that we want to point to current's parent. we'll check if parent node is full later





			/*Leaf splits into two parts. Now you must check if parents can take in another part. 
			1) If parent had 3 or less children initially, it can take a new leaf so it adds it. 
			procedures: split, adjust parents keys and numofchildren, attatch the two new leaves as children. do another search 
			
			2)If not, then parent node will split. If parent node splits, it must check it’s parent as well and this will happen recursively until root.
			step 1 except you have to split the node itself too*/

			//separate func for splitnode - a recursive function
		}
	}

	//else number exists, we don't insert
	return false;
}

/*
  //if we need to put more entries into current's leaf nodes
  void insertInLeaf(Entry i)
  {
    //if current's is empty, aka create a new node
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
      leafisfull=true;
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
*/

void Btree:: splitnode(BTreeNode* x, Entry item)
{
	/*
	//x is a full node with full leaves.
	BTreeNode *node1, *node2;
	//new internal nodes
	node1 = new BTreeNode ();
	node2 = new BTreeNode ();

	//copy data to internal nodes
	for (int j=0, j<2, j++)
	{
		//copy keys 0, 1 to node 1
		node1->keys [i] = x->keys [i];
		// copy children 0, 1 to node 1
		node1->children[i]=x-keys[i];
	}

	//copy data after the mid split
	node->keys[0]=x->keys [3]
	for (int j=2, j<4, j++)
	{
		// copy children 0, 1 to node 1
		node1->children[i]=x-keys[i];
	}

	//replace x with the two new nodes, node1 and node 2.
	//have x's parent have 1 and 2 as children and 1-2's parent point to x->parent

	//increase how manychildren parent has
	x->parent->countchildren++;


	//if x's parent is also full, call again
	if (x->parent->countchildren)

	*/
}



Entry Btree::searchHelper(int perm, BTreeNode* x)
{
	//x keeps track of current node  we're on. Start with root
	if (x!=NULL){
				//base case
		if (x->leaf==true)
		{
			//x is now a leaf node where the int shoul be.
			current = x; //the variable current now points to the node that we should insert at
			if (x->entries[0].getperm()== perm)
				return x->entries[0];
			else if (x->entries[1].getperm() == perm)
				return x->entries[1];
			else
				return Entry();
		}
		//if x is not a leaf...
		else{
			if(perm <=x->keys[0]){ //perm less then keys[0]
				searchHelper(perm, x->children[0]);
			}else if ((x->keys[1]!=-1 && perm <= x->keys[1])){ //perm between keys[0] and keys[1] or when only one key
				searchHelper(perm, x->children[1]);
			}else if ((x->keys[2]!=-1 && perm <=x->keys[2])){ //perm between keys[1] and keys[2] or when only two keys
				searchHelper(perm, x->children[2]);
			}else { // countkeys==3 and perm is greater then keys[3]
				searchHelper(perm, x->children[3]);
			}
		}
	}
}
//search for user given an int and return the entry that holds it. else return a mock entry with perm =-1
Entry Btree::search(int perm){
	return searchHelper(perm, root);
}


//for sanitycheck's sake but im not even sure this works
void Btree:: traverse(BTreeNode *p)  {}
