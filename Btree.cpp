#include "Btree.h"
Btree::Btree(){
	numOfElms =0;
	height = 0;
}
Btree::Btree(Entry *en1, Entry *en2)
{
	//tree constructor, make one new leaf/root node combo
	root = new BTreeNode(en1, en2);
	current = root;
	height =1;
}

void Btree::insert(User u, int index) //insert a new user. there are 3 cases to consider
{	Entry* e = new Entry (u, index);
	int p= u.getPerm();//easier way to search with userperm
	
	if (numOfElms == 0){
		BTreeNode* newNode;
		BTreeNode* newLeaf(e);
		root = newNode;
		newNode->keys[0] = p;
		newNode->children[1] = newLeaf;
		numOfElms++;
	}
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
Entry Btree::searchInBtree(int perm){
	return search(int perm,root);
}
bool Btree::isFound(int perm){
	Entry anEntry = searchHelper(perm);
	if (anEntry.getuserindex().getPerm() == -1 | anEntry.getuserindex().getPerm() == -2)
		return false;
	else
		return true;
}
//search for user given an int. 
//return the node where we found user. 
//if false ie, cannot find,return nullptr, 
//will always update the node pointer "current" to hold the last internal node before the area we want 
Entry Btree::searchHelper(int perm, BTreeNode* root)
{ 
	if (root!=NULL){
		if (!root->leaf){
			if(perm < root->keys[0]){ //perm less then keys[0] 
				searchHelper(perm, children[0]);
			}else if (countkeys==1 | (keys[1]!=-1 && perm < keys[1])){ //perm between keys[0] and keys[1] or when only one key
				searchHelper(perm, children[1]);
			}else if (countkeys==2 | (keys[2]!=-1 && perm < keys[2])){ //perm between keys[1] and keys[2] or when only two keys
				searchHelper(perm, children[2]);
			}else { // countkeys==3 and perm is greater then keys[3]
				searchHelper(perm, children[3]);
			}	
		}else{
			if (root->e1.getuserindex().getPerm() == perm)
				return e1;
			else if (root->e2.getuserindex().getPerm() == perm)
				return e2;
			else{
				Enrtry defEntry;
				return defEntry;//INFO for debugging: getPerm will returm -1, so it means the search is unsuccessful
			}		
		}
	}else{
		Enrtry defEntry;
		defEntry.setPerm(-2);//INFO for debugging: getPerm will returm -2
		return defEntry;
	}	
}
