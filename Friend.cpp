#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#include "Friend.h"
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
/* Friend constructor
 *  inputs: none
 *   return value: none
 *   This initializes / allocates memory for the Friend
 */
Friend::Friend()
{
	// put your constructor code here
	firstname = NULL;
	lastname = NULL;
	birthdate = NULL;
}
/* Friend constructor
 * inputs: fn - character array holding the first name
 * 	ln - character array holding the last name
 * 	bd - character array holding the birthdate
 * You may assume for this that the space for fn, ln, and bd was
 * allocated outside of this method.
 */
Friend::Friend(char *fn, char *ln, char *bd)
{
	// put your constructor code here
	firstname = fn;
	lastname = ln;
	birthdate = bd;
}
/* destructor
 * This is optional - if the constructor allocated memory, then this needs
 * to deallocate the memory.
 */
/*
Friend::~Friend()
{
	// put your destructor code here
	delete[] firstname;
	delete[] lastname;
	delete[] birthdate;
}
*/

/*
 * getFirstName
 * inputs: none
 * outputs: character array (string) containing the first name
 * 	This does not allocate separate memory for that first name -
 * 	it just returns the pointer to the first name
 */
char *Friend::getFirstName()
{
	// put code here
	return firstname;
}
/*
 * getLastName
 * inputs: none
 * outputs: character array (string) containing the last name
 * 	This does not allocate separate memory for that last name -
 * 	it just returns the pointer to the last name
 */
char *Friend::getLastName()
{
	// put code here
	return lastname;
}
/*
 * getBirthDate
 * inputs: none
 * outputs: character array (string) containing the birthdate
 * 	This does not allocate separate memory for that birthdate -
 * 	it just returns the pointer to the birthdate
 */
char *Friend::getBirthDate()
{
	// put code here
	return birthdate;
}

/* setFirstName
 * inputs: char * (string) containing the first name
 * outputs: none
 * This sets the first name.  The memory is allocated outside, so it
 * just sets the pointer
 */
void Friend::setFirstName(char *fn)
{
	firstname = fn;
}
/* setLastName
 * inputs: char * (string) containing the last name
 * outputs: none
 * This sets the last name.  The memory is allocated outside, so it
 * just sets the pointer
 */
void Friend::setLastName(char *ln)
{
	lastname = ln;
}
/* setBirthDate
 * inputs: char * (string) containing the birthdate
 * outputs: none
 * This sets the birthdate.  The memory is allocated outside, so it
 * just sets the pointer
 */
void Friend::setBirthDate(char *bd)
{
	birthdate = bd;
}

/* printFriend
 * inputs: FILE *output file - the place where this should print
 * This method prints a single friend.  It prints tou whatever file
 * is passed in.  You may choose to implement this OR the other printFriend
 * you need not implement both.  Even if you do not implement it, this
 * empty method needs to stay in this file.
 */
void Friend::printFriend(FILE *outfile)
{
	fprintf(outfile,"%s %s %s",firstname,lastname,birthdate);
}
/* printFriend
 * inputs: ostream *stream - the place where this should print
 * This method prints a single friend.  It prints tou whatever stream
 * is passed in.  You may choose to implement this OR the other printFriend
 * you need not implement both.  Even if you do not implement it, this
 * empty method needs to stay in this file.
 */
void Friend::printFriend(ofstream *outstream)
{
	*outstream << firstname << " " << lastname << " " << birthdate;

}

int Friend::compare(Friend *f)
{
	int comp = strcmp(firstname,f->firstname);
	if (comp != 0)
		return comp;
	else
		return strcmp(lastname,f->lastname);
}

