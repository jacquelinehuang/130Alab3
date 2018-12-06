#ifndef _ENTRY
#define _ENTRY

#include "User.h"

//a small header file for the data structure entries,
//which holds users and their indexes

class Entry {
private:
	User *user;
	int index1;

public:
	Entry ()
	{
		user = new User(); //default user with perm =-1
		index1=-1;
	}

	Entry (User *u, int i)
	{
		user = u;
		index1=i;
	}
	
	int getuserindex() {return index1;}
	User* getuser() {return user;}
	void setuserindex(int graphpos) {index1=graphpos;}
//for sanity's sake
	int getkey() {return user->getPerm();}

};
#endif