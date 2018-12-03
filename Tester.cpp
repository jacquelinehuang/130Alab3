#include "Btree.h"
#include "Entry.h"
#include "BTreeNode.h"
#include <iostream>
using std::cout;

int main ()
{
  std::cout<<"we have a main folks. manual btree";
  Btree b= new Btree();

BTreeNode * leaf1, * leaf2, * leaf3, * leaf4, * leaf5, * leaf6, *node1, *node2;
Entry e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12;
//make entries
e1=(User (1, "a","a","a"), 1)
e2=(User (3, "a","a","a"), 1)
e3=(User (5, "a","a","a"), 1)
e4=(User (6, "a","a","a"), 1)
e5=(User (7, "a","a","a"), 1)
e6=(User (8, "a","a","a"), 1)
e7=(User (9, "a","a","a"), 1)
e8=(User (12, "a","a","a"), 1)
e9=(User (324, "a","a","a"), 1)
e10=(User (999, "a","a","a"), 1)
//make leaves
leaf1 = new BTreeNode(e1,e2)
leaf2 = new BTreeNode(e3,NULL)
leaf3 = new BTreeNode(e4,e5)
leaf4 = new BTreeNode(e6, NULL)
leaf5 = new BTreeNode(e7,e8)
leaf6 = new BTreeNode(e9,e10)

//new BTreeNode (int key1, int key2, int key3,
//BTreeNode * c1, BTreeNode * c2, BTreeNode * c3, BTreeNode * c4, BTreeNode * par, bool isleaf, Entry e1, Entry e2)
node1= (3, -1, -1, leaf1, leaf2, NULL,NULL, )
node2= (7, 8, 12,  )
root= new BTreeNode (5, -1,-1, node1, node2, NULL, NULL, NULL, false, NULL,NULL)
current = root;



if (b.search(324)==nullptr)
 cout<<"not found\n";
else{
  cout<<"found\n";
}
if (b.search(5)==nullptr)
 cout<<"not found\n";
else{
  cout<<"found\n";
}
if (b.search(12)==nullptr)
 cout<<"not found\n";
else{
  cout<<"found\n";
}
if (b.search(0)==nullptr)
 cout<<"not found\n";
else{
  cout<<"found\n";
}





return 0;}
