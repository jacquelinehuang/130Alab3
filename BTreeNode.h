

class BTreeNode
{
protected:

    int keys [MAXKEYS];  // An array of keys- Max number m-1 =3
    BTreeNode * children[M]; //array of pointers to its children. default to max size 4
    BTreeNode * parent; //parent pointer, not sure if this complicates things
    int countPtr;     // counts number of children
	int  countEntries;
    bool leaf; // Is true when node is leaf. Otherwise false
    

    Entry *e1;	//data if it is a leaf. 2 entries can be in a leaf max	
    Entry *e2;

	
public:
	const static int M =4 ;;   // max number of children in a node
	const static int MINM = 2;    // min number of children in a node
	const static int MAXKEYS = 3; //max no of keys per node
	const static int L = 2;  // max no of elements per leaf

	int numOfEntriesInLeaf(){
		return countEntries;
	}
	BTreeNode (Entry *en1){
		leaf= true;
		e1= en1;
		countEntries++;
	}
	//node constructor, assuming for insert at leaf. 
	BTreeNode (Entry *en1, Entry *en2)
	{
		//initialize as leaf with data
		leaf= true;
		e1= en1;
		e2= en2;
		//keys used and children it has default to 0
		countPtr = 0;
	}

	//Will use setters to fix for nodes created by splitting. 
	//default constructor for internal nodes  
	BTreeNode ()
	{
		leaf = false;
		countPtr = 0;
		countEntries = 0;
		
		keys[MAXKEYS] = {-1,-1,-1}
		
		for (int i=0; i<M; i++)
			children[i] = NULL;
		
	}

// Friend so we can acess data as if it were a struct 
friend class Btree;
};
#endif