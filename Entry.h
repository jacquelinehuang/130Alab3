#include "User.h"

//a small header file for the data structure entries,
//which holds users and their indexes
class Entry {
private:
	User user;
	int index1;

public:
	Entry ()
	{
		user = new User();
		index1=-1;
	}
	Entry (User u, int i)
	{
		user = u;
		index1=i;
	}
	int getuserindex() {return index1;}
	User getuser() {return user;}
	void setuserindex(int graphpos) {index1=graphpos;}

	//overload ops <, >, <= and >= and ==

	Entry operator<(const Entry& b) {
	return (this->user.getPerm() < b->user.getPerm();)
}

	Entry operator>(const Entry& b) {
	return (this->user.getPerm() > b->user.getPerm();)
}

Entry operator<=(const Entry& b) {
return (this->user.getPerm() <= b->user.getPerm();)
}

Entry operator=>(const Entry& b) {
return (this->user.getPerm() => b->user.getPerm();)
}

};
