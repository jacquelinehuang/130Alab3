#include "Btree.h"
#include <iostream>

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

	//if we search and cannot find the item, then we can insert it. 
	//in int case search returns anegative number. otherwise it would be anullptr
	if (search(item, root)<0)
	{
		//the pointer, <current> is pointing at the parent where the entry should be inserted.
		//if current has less than 3 keys, a.k.a. we don't need to worry about splitting nodes, only leaves
	if(current ->countkeys < 3)  
	     {
		//if leaf is  not full, aka has 1 or 2 entries, insert properly
	        if(current->leafIsNotFull(0)){
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
		for (int i=0;i<4;i++)
		{
			//see if we have one open spot left in any leaf. 
			BTreeNode* kid = current ->children[i];
			if (kid->leafisfull == false)
			{
				allleavesarefull=false;
				break;
			}

		}

		if (allleavesarefull)
		{
			//call split nodes and make a new node STUB
			splitnode(0, item);

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

void Btree:: splitnode(int keyindex, int item)
{}


//search for user given an int.
//return the node where we found user.
//if false ie, cannot find,return nullptr,
//will always update the node pointer "current" to hold the last internal node before the area we want
int Btree::search(int perm, BTreeNode* x)
{
	//x keeps track of current node  we're on. Start with root

	if (x!=NULL){
		//if x is not a leaf...
		if (!x->leaf){
			if(perm < x->keys[0]){ //perm less then keys[0] 
				search(perm, x->children[0]);
			}else if (x->countkeys==1 | (x->keys[1]!=-1 && perm < x->keys[1])){ //perm between keys[0] and keys[1] or when only one key
				search(perm, x->children[1]);
			}else if (x->countkeys==2 | (x->keys[2]!=-1 && perm < x->keys[2])){ //perm between keys[1] and keys[2] or when only two keys
				search(perm, x->children[2]);
			}else { // countkeys==3 and perm is greater then keys[3]
				search(perm, x->children[3]);
			}	
		}
		//basecase 
		if (x->leaf==true)
		{
			//x is now a leaf node where the int shoul be.
			current = x->parent; //the variable current now points to the node that is parent to where we want to find/insert the leaf
			if (x->e1== perm)
				return x->e1;
			else if (x->e2 == perm)
				return x->e2;
			else
				return -999;
				//any negative number means search is false 
		}

	}		

}

//for sanitycheck's sake but im not even sure this works
void Btree:: traverse(BTreeNode *p)  {}

int main ()
{
  std::cout<<"we have a main folks";
  return 0;
}
