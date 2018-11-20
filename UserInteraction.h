#include "User.h";

Class UserInteraction
{
    private:
    void addUsertoBTree (User u);

    public:
    void add (User u);
    //search and say true or false
    bool findUser(int perm);
    //search and print if found
    void findUserDetail (int perm);
    void reccomendfriends (int perm);
};