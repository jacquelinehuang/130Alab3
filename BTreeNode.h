
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
    int e2;
 public:
	//node constructor, assuming for insert at leaf.
	BTreeNode (int i);
	//Will use setters to fix for nodes created by splitting.
	//default constructor for internal nodes
	BTreeNode ();
	bool leafIsNotFull(int childIndex);
	bool abletoadd(int item);
	void insertInLeaf(int childIndex, int i);
	void swapEntries();
	void split (int keyindex, int item);
	
	// Friend so we can acess data as if it were a struct
	friend class Btree;
};
