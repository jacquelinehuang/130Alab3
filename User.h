//I'm lazy so everything's in the h file.

Class User{
public:
//constructor and getters 

  User (int p, string n, string g1, string g2)
  {
    perm=p;
    name = n;
    genre1=g1;
    genre2=g2;
  }
  int getPerm (){return perm;}
  string getName (){return name;}
  string getGenre1 (){return genre1;}
  string getGenre2 () {return genre2;}
private:
  int perm;
  string name, genre1, genre2;
}
