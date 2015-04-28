#ifndef CIRCLE_H
#define CIRCLE_H
#include "Friend.h"

class Circle {
   private:
	// private member variables
	Friend **array;
	int allocatedSize;
	int numFriends;
	char *name;

	// private methods
	void expand();


   public:
	Circle();  // constructor
	~Circle(); // destructor - optional

	// accessors
	int getNumFriends();	// find out the number of friends in list
	Friend *getFriend(int); // return the nth friend in the list
	char *getCirclename(); // get the name of the circle

	// mutators
	void addFriend(Friend *); // add a friend to the list
	void setCirclename(char *); // set the name of the circle

	// you may add more public methods here
	// prints - make sure you have a stub for both of these,
	// just implement one.  You can leave the other blank
	void printCircle(FILE *outfile);
	void printCircle(ofstream *outstream);
};
#endif

