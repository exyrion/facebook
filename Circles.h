#ifndef CIRCLES_H
#define CIRCLES_H
#include "Friend.h"
#include "Circle.h"

 class Circles {
   private:
	// private member variables
	Circle **array;
	int numCircles;
	int allocatedSize;

	// private methods
	void expand();


   public:
	Circles();  // constructor
	~Circles(); // destructor

	// accessors
	int getNumCircles();	// find out the number of circles
	Circle *getCircle(int); // return the nth circle in the list

	// mutators
	void addCircle(Circle *); // add a circle to the list

	// you may add more public methods here
	// prints - make sure you have a stub for both of these,
	// just implement one.  You can leave the other blank
	void printCircles(FILE *outfile);
	void printCircles(ofstream *outstream);
};
#endif

