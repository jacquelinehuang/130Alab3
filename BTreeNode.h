
//we need template because the node can points to a next node or to a leaf
template<class T>
class BTreeNode{
	protected:
		int perms [] = {-1,-1,-1};
		
		T* lassThan1st;
		BTreeNode* greaterThan1stAndLessThan2nd;
		BTreeNode* greaterThan2ndAndLessThan3rd;
		BTreeNode* greaterThan3rd;
		
		BTreeNode() 
		{ 	lassThan1st = NULL;
			greaterThan1stAndLessThan2nd = NULL;
			greaterThan2ndAndLessThan3rd = NULL;
			greaterThan3rd = NULL;
		}
		void setLassThan1st(BTreeNode* lt1) { lassThan1st = lt1; }
		void setGreaterThan1stAndLessThan2nd(BTreeNode* gt1lt2) { greaterThan1stAndLessThan2nd = gt1lt2; }
		void setGreaterThan2ndAndLessThan3rd(BTreeNode* gt2lt3) { greaterThan2ndAndLessThan3rd = gt2lt3; }
		void setGreaterThan3rd(BTreeNode* gt3) { greaterThan3rd = gt3; }
		
		void set1stNum (int num1) { perms[0] = num1; }
		void set2ndNum (int num2) { perms[1] = num2; }
		void set3rdNum (int num3) { perms[2] = num3; }
		//BTreeNode* getPrev(){ return prev; }
		//BTreeNode* getNext(){ return next; }
};