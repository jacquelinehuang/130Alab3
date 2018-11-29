#ifndef _LEAF
#define _LEAF
#include "Entry.h"

//this class holds two entries
class Leaf{
	private:
		Entry** aLeaf;
		
	public:
		Leaf(){
			aLeaf = new Entry* [2];
			
			// need to make default Entries  
			aLeaf[0] = new Entry ();
			aLeaf[1] = new Entry ();
		}
		void set1stEntry( int index1, User u1){
			delete aLeaf[0];
			aLeaf[0] = new Entry (u1, index1);
		}
		void set2ndEntry( int index2, User u2){
			delete aLeaf[1];
			aLeaf[1] = new Entry (u2, index2);
		}
		
		Entry* get1stEntry () {
			return aLeaf[0]; 
		}
		Entry* get2ndEntry () {
			return aLeaf[2]; 
		}
}

#endif