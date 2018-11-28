#include "Btree.h"

Btree::Btree(Entry *en1, Entry *en2)
{
	//tree constructor, make one new leaf/root node combo
	root = new BTreeNode(en1, en2);
	current = root;
	height =1;
}

void Btree::insert(User *u) //insert a new user. there are 3 cases to consider
{
	int p= u->getPerm();//easier way to search with userperm
	
	if (search (p)==nullptr )
	{

	}

	//2 children or 3 children, find spot and insert
	if (current ->leaf == true && current->count <4 )
	{

	}
	//4 children- split case
}


int Btree::split (BTreeNode *x, int i) 
{
	//split, we have x is the floating node without a parent

	//split current, the parent of would be x

	return 1;
//stub
}

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
	while (x->leaf == false && x!=NULL)
	{
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

