#ifndef _USERINTERACTION
#define _USERINTERACTION
#include "User.h"
#include "Graph.h"

class UserInteraction 
{
    private:
		void addUsertoBTree (User u);
		Graph aGraph;
		//BTree* aBTree;
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