#ifndef _USER
#define _USER
#include <string>

class User{
	
	private:
		int perm;
		std::string name, genre1, genre2;
		
	public:
		User (int p, std::string n, std::string g1, std::string g2){
			perm=p;
			name = n;
			genre1=g1;
			genre2=g2;
		}
		
		// getters
		int getPerm (){return perm;}
		std::string getName (){return name;}
		std::string getGenre1 (){return genre1;}
		std::string getGenre2 () {return genre2;}
	
		//setters
		void setPerm (int p) { perm = p;}
		void setName (std::string n)  { name = n; }
		void setGenre1 (std::string g1)  { genre1 = g1; }
		void setGenre2 (std::string g2)  { genre2 = g2; }
};
#endif