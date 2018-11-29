#include "User.h"

//a small header file for the data structure entries,
//which holds users and their indexes 
class Entry {
private:
	User* newUser;
	int index1; 
public: 
	Entry ()
	{
		newUser = new User();
		index1=-1;
	}
	Entry (User u, int i)
	{
		newUser = u;
		index1=i;
	}
	int getuserindex() {return index1;}
	User getuser() {return newUser;}

};
