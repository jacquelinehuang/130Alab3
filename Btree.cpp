#include "Btree.h"
#include <iostream>
#include <algorithm>    // std::max
using std::max;
using std::cout;

Btree::Btree(Entry* e){
	root = new BTreeNode(e); //root is some node made with the first user data
	//make the leaves point to parent here
	for (int i=0; i<4;i++)
	{
		root->children[i]->parent=root;
	}
	current =root;
}


//insert
//method that tries to insert an entry. Calls the actual insert and split functions
bool Btree:: insert(Entry* item)
{

	//current is a leafnode, found as a byproduct of using search. 
	Entry *foundentry =search(item->getkey());

	//if we search and cannot find the item, aka we returned amock entry with a negative perm, then we can proceed to inserting
	if (foundentry->getkey()<0)
	{
		
		//then check if current, which points to a leaf is full or not.1) If not, then add item to leaf
		if (current->entries[0]->getkey()==-1 || current->entries[1]->getkey()==-1)
		{
			//add item to leaf. 
			for (int n=0; n<2; n++)
			{
				//this takes care of if it will be in spot 1 or spot 2. Entries with -1 are considered empty
				// insert at first open spot
				if (current->entries[n]->getkey()==-1)
				{
					current->entries[n]=item;
					break;
				}
			}
			current->countEntries++;
			//swap to keep largest entry at entries[1] for simplicity's sake
			if (!(current->countEntries<2))
			{
				//we dont want to do this swap when theres an "empty" dummy entry
				if (current->entries[0]->getkey()>current->entries[1]->getkey()) //comparison with getperm which calls users getperm
				{
				Entry *temp = current->entries[0];
				current->entries[0]=current->entries[1];
				current->entries[1]=temp;
  				}
			}

		}
		//2) If leaves are full, 
		else{

cout<<"leaves are full"<<endl;

			/*Leaf splits into two parts.
			1) If parent had 3 or less children initially, it can take a new leaf so it adds the split on. */
			/*2)If not, then parent node will split. If parent node splits, it must check it’s parent as well and this will happen recursively until root.
			step 1 except you have to split the node itself too*/ 

			//split leaf. make a new leaf //new leaf y will be the maximum of the three elements that can live in our current leaf. 
			BTreeNode *y= new BTreeNode (true);
			//since child2 is max in node, find max of item and child[1]
			int maxentry = max(item->getkey(),current->entries[1]->getkey());

			//case item is largest
			if (maxentry==item->getkey()) 
			{ y->entries[1]=item; cout<<"item is largest"<<endl;}
			//case child2 is largest
			else
			{
				//take out largest child2 to y. put item in a new leaf
				y->entries[0]=current->entries[1];
				current->entries[1]=item;
				current->countEntries=1;
				
				if (current->entries[0]->getkey()>current->entries[1]->getkey()) //adjust the entries that live in current so child2 is still larger
				{
					Entry* temp = current->entries[0];
					current->entries[0]=current->entries[1];
					current->entries[1]=temp;
				}
			}

			//so now y is like some new leaf we want to insert. find location of current, place y in next spot
			//go through parent's children[] to find location of current in pparents rray
			BTreeNode *currentparent=current->parent;

			//currentloc is the location where current lives in the parents child array
			int currentloc;
			for (int i = 0; i <4; i++)
			{
				if (currentparent->children[i]==current)
				{
					currentloc=i;
					break;
				}
			}

			BTreeNode* leftovernode; //there will be one leaf that doesn't fit. if it's a dummy node, we don't care 

			//first move everything down a slot, so our leftover node from the split always holds the largest elements for sanity's sake			
			//to make sure not to get a segfault if x is in slot 3. If x is in slot 3, y immediately is the leftovernode 
			if (currentloc== 3)	{ leftovernode=y;}
			//if x isn't the last node move everything down one space in the array until we hit location of current. put y in that slot
			else{
				leftovernode= currentparent->children[3];
				for (int n=3; n<currentloc;n++)
					{
						currentparent-> children[n] = currentparent->children [n-1];
					}
				currentparent->children[currentloc+1]=y;
				//have y's parent point toxparent for future use
				y->parent = currentparent;

				//increment as normal if leftover was a dummy node. this means the num of entries is 0 and its a dummy node we dont care about
				if ( leftovernode->entries[0]->getkey()==-1 && leftovernode->entries[1]->getkey()==-1)
					currentparent->countchildren++;
			}
			//if the leafsplit requires no node split, update =parents keys here
			for (int k=0; k<3;k++)
			{
				current->parent->keys[k]=fixkeys(current->parent, k);
			}


			//since we're dealing with leaves here, the pushed out leaf node will have a non dummy entry if the node was previously full
			//this means parent of current is full, call split
			if (leftovernode->entries[0]->getkey()>0)
			{
				splitnode(current->parent, leftovernode);
			}
		}
		
	}

	//else number exists, we don't insert
	return false;
}


int Btree::fixkeys (BTreeNode *x, int index)
{
	//index is index of key we're trying to adjust, will only be 0-2
	int keycorrection;

	BTreeNode* temp = x->children[index+1]; //traverse r left left left. find r child of key	
	//traverse left left left until leaf, return smallest.
	while (!(temp->leaf))
	{
		temp=temp->children[0];
	}
	if (temp->entries[0]->getkey()==-1)
		keycorrection=temp->entries[1]->getkey();
	else
		keycorrection=temp->entries[0]->getkey();

	return keycorrection;
}

void Btree:: splitnode(BTreeNode* x, BTreeNode* leftovernode)
{
	//Split, which is called each time
	BTreeNode *xparent= new BTreeNode(); //for easier ref of parent of original node we split

	///splitting function
	//x is a full node with full leaves. X becomes Xminus data in Y will take some of the data, + the new leftover node
	BTreeNode *y= new BTreeNode ();
	//a bad split hard coded for 4 nodes and a 2/3 split.
	//copy the second half of children in x to y plus the third floating node
	y->children[0]=x->children[2];
	y->children[1]=x->children[3];
	y->children[2]=leftovernode;
	leftovernode->parent=y;
	y->countchildren=3;
	//adjust x to only hold 2 children, reset the keys
	x->children[2]=nullptr;
	x->children[3]=nullptr;
	x->keys[1]=-1;
	x->keys[2]=-1;
	x->countchildren=2;

	//fix keys for x. it has 2 elements so 1 key
	x->keys[0]=fixkeys(x, 0);

	//fix keys for y. y has 3 elements and 2keys
	y->keys[0]=fixkeys(y, 0);
	y->keys[1]=fixkeys(y, 1);

	//now onto 3 cases
	//base case to handle root, do special things aka make new root with 2 children
	if (xparent ==nullptr||x==root)
	{
		xparent=new BTreeNode();
		xparent->children[0]=x;
		xparent->children[1]=y;
		y->parent=xparent;
		x->parent=xparent;

		//fix keys for new root
		xparent->keys[0]=fixkeys (x,0);

		return;
	}

	//now that we have a new y, insert it as a child to xparent next to x
	//find location of x, place y in next spot
	//go through parent's children[] to find location of x in array
	int xloc;
	for (int i = 0; i < x->countchildren; i++)
	{
		if (xparent->children[i]==x)
				xloc=i;
	}
	//first move everything down a slot, so our leftover node always holds the largest elem
	//make sure not to get a segfault if x is in slot 3. If x is in slot 3, y immediately is the leftovernode 
	if (xloc== 3)	{ leftovernode=y;}
	//where children[pos of curent] = stopping point 
	//move everything down one space in the array
	else{
		leftovernode= xparent->children[3];
		for (int n=3; n<xloc;n++)
			{
				xparent-> children[n] = xparent->children [n-1];
			}
		xparent->children[xloc]=y;
		//have y's parent point toxparent for future use
		y->parent = xparent;
		
		//increment only if numofchildren is not 4 yet 
		if (xparent->countchildren<4)
				xparent->countchildren++;
	}
	
	//basecase, parent is not full. Fix keys and stop 
	if ( xparent->countchildren<=4 && leftovernode != nullptr)
	{
		//
		for (int i=0; i<3;i++)
		{
			xparent->keys[i]=fixkeys(xparent, i);
		}
		return;
	}

	//check if leftovernode has real entries or the dummy ones we implemented 
	if ( xparent->countchildren>=4 && leftovernode != nullptr)
	{
		splitnode(xparent,leftovernode);
	}

}



Entry* Btree::searchHelper(int perm, BTreeNode* x)
{
	//x keeps track of current node  we're on. Start with root
	if (x!=NULL)
	{
		//base case
		if (x->leaf==true)
		{
			//x is now a leaf node where the int shoul be.
			current = x; //the variable current now points to the node that we should insert at
			if (x->entries[0]->getkey()== perm)
			{
				cout<<"in entry 1 search found this perm: "<<x->entries[0]->getkey();
				return x->entries[0];
			}	
			else if (x->entries[1]->getkey() == perm)
			{
				
				cout<<"apparently in entry 2 search found this perm: "<<x->entries[1]->getkey();
				return x->entries[1];
			}		
			else
			{
					Entry *pointer2 = new Entry();
					cout<<"not found. dummy perm: "<<pointer2->getkey();
					return pointer2;
			}		
		}
		//if x is not a leaf...
		else
		{
			if(perm <x->keys[0]){ //perm less then keys[0]
				searchHelper(perm, x->children[0]);
			}else if ( (perm >= x->keys[0] && x->keys[1]==-1) ||(perm >= x->keys[0] && perm < x->keys[1])){ //perm between keys[0] and keys[1] or when only one key
				searchHelper(perm, x->children[1]);
			}else if ( (perm >= x->keys[0] && x->keys[1]==-1) || (perm >= x->keys[2]  && perm < x->keys[2])){ //perm between keys[1] and keys[2] or when only two keys
				searchHelper(perm, x->children[2]);
			}else { // countkeys==3 and perm is greater then keys[3]
				searchHelper(perm, x->children[3]);
			}
		}
	}
}
//search for user given an int and return the entry that holds it. else return a mock entry with perm =-1
Entry* Btree::search(int perm){

	return searchHelper(perm, root);
}


//for sanitycheck's sake but im not even sure this works
void Btree:: traverse(BTreeNode *p)  {}
