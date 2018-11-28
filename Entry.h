#include "User.h"

//a small header file for the data structure entries,
//which holds users and their indexes 
class Entry {
private:
	User *u;
	int index1; 
public: 
	Entry (User* u, int i)
	{
		this->u = u;
		index1=i;
	}
	int getuserindex() {return index1;}
	User * getuser() {return u;}

};
