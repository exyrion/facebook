#ifndef FRIEND_H
#define FRIEND_H
#include <iostream>
using namespace std;
/*
 * Friend
 *
 * This class holds the information necessary for a single friend in
 * our Google+ / Facebook application for CS 24.
 *
 * Your project *must* compile with this file, though you will need to
 * add to this file.  Just don't make changes to what is already here -
 * you may add private variables, private methods, and public methods.
 */
class Friend
{
	private:
	// fill in your private variables
	char *firstname;
	char *lastname;
	char *birthdate;

	// fill in your private methods here

	public:
	// fill in your public methods here
	Friend(); // constructor
	// constructor - it is assumed that the memory for fn, ln, and bd
	// has been allocated outside of this method.
	Friend(char *fn, char *ln, char *bd);
	//~Friend(); // destructor

	// accessors or "getters"
	char *getFirstName();
	char *getLastName();
	char *getBirthDate();

	// mutators or "setters"
	void setFirstName(char *fn);
	void setLastName(char *ln);
	void setBirthDate(char *bd);

	int compare(Friend *f);

	// prints - make sure you have a stub for both of these,
	// just implement one.  You can leave the other blank
	void printFriend(FILE *outfile);
	void printFriend(ofstream *outstream);
};
#endif

