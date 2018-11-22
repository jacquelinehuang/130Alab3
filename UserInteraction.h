#ifndef _USERINTERACTION
#define _USERINTERACTION
#include "User.h"

class UserInteraction
{
    private:
    void addUsertoBTree (User u);

    public:
	void inputFile();
    void add (User u);
    //search and say true or false
    bool findUser(int perm);
    //search and print if found
    void findUserDetail (int perm);
    void reccomendfriends (int perm);
};
#endif