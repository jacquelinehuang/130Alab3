##ifndef _BTREENODEWITHLEAVES
#define  _BTREENODEWITHLEAVES

#include "Leaf.h"

class BTreeNodeWithLeaves{
	private:
		int perms [] = {-1,-1,-1};
		
		Leaf* lassThan1st;
		Leaf* greaterThan1stAndLessThan2nd;
		Leaf* greaterThan2ndAndLessThan3rd;
		Leaf* greaterThan3rd;
	
	public:	
		BTreeNodeWithLeaves(){
			lassThan1st = NULL;
			greaterThan1stAndLessThan2nd =NULL;
			greaterThan2ndAndLessThan3rd = NULL;
			greaterThan3rd = NULL;
		}
		void setLassThan1st(Leaf* lt1) { lassThan1st = lt1; }
		void setGreaterThan1stAndLessThan2nd(Leaf* gt1lt2) { greaterThan1stAndLessThan2nd = gt1lt2; }
		void setGreaterThan2ndAndLessThan3rd(Leaf* gt2lt3) { greaterThan2ndAndLessThan3rd = gt2lt3; }
		void setGreaterThan3rd(Leaf* gt3) { greaterThan3rd = gt3; }
		
		void set1stNum (int num1) { perms[0] = num1; }
		void set2ndNum (int num2) { perms[1] = num2; }
		void set3rdNum (int num3) { perms[2] = num3; }
		
		
};

#endif