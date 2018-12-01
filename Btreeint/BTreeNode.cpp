#include <algorithm>
#include "BTreeNode.h"
#include <iostream>

//leaf constructor
BTreeNode:: BTreeNode (int i){
  leaf= true;
  e1= i;
  countEntries=1;
  parent =NULL;
}

//other constructor for  internal nodes
BTreeNode:: BTreeNode ()
{
  leaf = false;
  countkeys = 0;
  countEntries = 0;
  parent =NULL;
  for (int i=0; i<3; i++) {keys [i]=-1;}
  for (int i=0; i<4; i++)
    children[i] = NULL;
}

void BTreeNode::insertInLeaf(int childIndex, int i)
{
  if(children[childIndex] == NULL)
  {
    BTreeNode * child = new BTreeNode(i); //initializing a new node puts entrycount to 1
    children[childIndex]=child;
    child->parent = this;////SOURCE FOR ERRORS
  }
  else
  {
    if (children[childIndex]->countEntries ==1)
    {  if(i > children [childIndex]->e1)
          children [childIndex]->e2=i;
      else{
        children [childIndex]->e2 = children [childIndex]->e1;
        children [childIndex]->e1 = i;
      }
      children[childIndex]->countEntries ++;}
  }
}
bool BTreeNode::leafIsNotFull(int childIndex){
  return ((children[childIndex] == NULL) | (children[childIndex]->countEntries ==1));
}

void BTreeNode:: swapEntries(){
  int temp = e1;
  e1=e2;
  e2=temp;
}
void BTreeNode:: split(int keyIndex, int item){
  int maxNum = std::max(children[keyIndex]->e2, item);
  keys[keyIndex] = maxNum;
  if(maxNum == children[keyIndex]->e2) {
    //int minNum = std::min()
    children[keyIndex]->e2 = item;
    if (item <children[keyIndex]->e2)
      swapEntries();
  }//

  split(keyIndex+1, maxNum);
}

bool BTreeNode:: abletoadd(int item)
{
  if (parent == NULL){ // add in empty root node
    keys[0] = item;
    BTreeNode * child = new BTreeNode(item); //initializing a new node puts entrycount to 1
    children[1]=child;
    child->parent = this;////SOURCE FOR ERRORS
    countkeys++;
    return true;
  }else{
    if(countkeys < 3){
      if(item<keys[0])
      {
        if(leafIsNotFull(0)){
          insertInLeaf(0, item);
          return true;
        }else{ //leaf where we want to insert is full but node is not
            split(0, item);
        }
      } else if(keys[1]!=-1 && item>=keys[0] && item<keys[1]) {

      }
      else // (item>=key[1] )
      {}
    }
    return false;
  }
}

int main ()
{
  std::cout<<"we have a main folks";
  return 0;
}
