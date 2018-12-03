#include "Btree.h"
#include "Entree.h"
#include <iostream>

Btree::Btree(){
	root = new BTreeNode(); //root is some blank node, which we will replace once we insert more data
	current =root;
}


//insert
/*
 search to determine what bucket the new record should go into.
    If the bucket is not full (at most b − 1 {\displaystyle b-1} b-1 entries after the insertion), add the record.
    Otherwise, before inserting the new record
        split the bucket.
            original node has ⎡(L+1)/2⎤ items
            new node has ⎣(L+1)/2⎦ items
        Move ⎡(L+1)/2⎤-th key to the parent, and insert the new node to the parent.

Repeat until a parent is found that need not split.
If the root splits, treat it as if it has an empty parent and split as outline above.
*/
//method that tries to insert an entry. Calls the actual insert and split functions
bool Btree:: abletoadd(int item)
{
	//when Btrees are created, we initialize an empty root. We start adding entries from there

	//if we search and cannot find the item, then we can insert it.
	//in int case search returns anegative number. otherwise it would be anullptr
	if (search(item, root)<0)
	{
		//the pointer, <current> is pointing at the leaf node where we should insert.
		//if current's parent has less than 3 keys, a.k.a. we don't need to worry about splitting nodes, only leaves
		if(current ->-parent->countkeys < 3)
	     {
		//if leaf is  not full, aka has 1 or 2 entries, insert properly
	        if(current->countEntries<0){


//FML IT"S WRONG FROM HERE
	          current ->insertInLeaf(0, item);
	          return true;
	        }else{ //leaf where we want to insert is full but node is not, we must create a new leaf or adjust keys and place the number in the next leaf with a spot
	            current->splitleaf(0, item);
	        }
	      }
	//case that node is full. We have 2 cases, leaves are full, in which case we split node or leaves or not full in which we just rearrange leaves
	else
	{
		bool allleavesarefull = true;
		//check if all leaves are full
		for (int i=0;i<4;i++)
		{
			//see if we have one open spot left fpr entries in any leaf.
			BTreeNode* kid = current ->children[i];
			if (kid->countEntries < 2)
			{
				allleavesarefull=false;
				break;
			}

		}

		if (allleavesarefull)
		{
			//call split node on current node and make a new node STUB
			current->splitleaf(0)
			splitnode(current, item);

		}
		//not all leaves are full, proceed as usual
		else{
			if(current->leafIsNotFull(0)){
	          current ->insertInLeaf(0, item);
	          return true;
	        }else{ //leaf where we want to insert is full but node is not, we must create a new leaf or adjust keys and place the number in the next leaf with a spot
	            current->splitleaf(0, item);
	        }
		}

	}

	return true;
	}

	//else number exists, we cannot insert
	else
		return false;





}


void Btree:: splitnode(BTreeNode* x, int i)
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


//search for user given an int.
//return the node where we found user.
//if false ie, cannot find,return nullptr,
//will always update the node pointer "current" to hold the last internal node before the area we want
Entry Btree::search(int perm){
	return searchHelper(int perm,root);
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
			if (x->e1->user.getPerm()== perm)
				return x->e1;
			else if (x->e2->user.getPerm() == perm)
				return x->e2;
			else
				return nullptr;
				//any negative number means search is false
		}
		//if x is not a leaf...
		else{
			if(perm <=x->keys[0]){ //perm less then keys[0]
				search(perm, x->children[0]);
			}else if (x->countkeys==1 | (x->keys[1]!=-1 && perm <= x->keys[1])){ //perm between keys[0] and keys[1] or when only one key
				search(perm, x->children[1]);
			}else if (x->countkeys==2 | (x->keys[2]!=-1 && perm <=x->keys[2])){ //perm between keys[1] and keys[2] or when only two keys
				search(perm, x->children[2]);
			}else { // countkeys==3 and perm is greater then keys[3]
				search(perm, x->children[3]);
			}
		}
	}
}

//for sanitycheck's sake but im not even sure this works
void Btree:: traverse(BTreeNode *p)  {}
