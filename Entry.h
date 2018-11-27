#include "User.h"

//a small header file for the data structure entries,
//which holds users and their indexes 
class Entry {
private:
	User *u1;
	int index1, 
public: 
	Entry (User* u, index i)
	{
		u1 = u;
		index1=i;
	}
	int getuserindex1 () {return index1;}
	User * getuser1 () {return u1;}

};