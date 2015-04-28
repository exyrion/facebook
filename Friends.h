//Justin Liang
#ifndef FRIENDS_H
#define FRIENDS_H
#include "Friend.h"
#include "Node.h"
#include "LinkedList.h"

class Friends {
   private:
	// private member variables
	Node *root;
	int numFriends;
	LinkedList *queue;

	// helper functions!
	Friend *getFriend(Friend *, Node *);
	void addFriend(Friend *, Node *);
	void removeFriend(Friend *, Node *);
	void makeTraversalQueue(Node *);
	void printFriendsHelper(FILE *outfile, Node *);
	Friend *findSuccessor(Node *);

   public:
	Friends();  // constructor
	~Friends(); // destructor

	// accessors
	int getNumFriends();	// find out the number of friends in list
	Friend *getFriend(Friend *); // return the nth friend in the list

	// mutators
	void addFriend(Friend *); // add a friend to the list
	void removeFriend(Friend *); // remove friend from list

	// iterator
	void resetIterator();	// reset iterator
	Friend *getNextFriend(); // get next Friend in the in-order traversal

	// you may add more public methods here
	// prints - make sure you have a stub for both of these,
	// just implement one.  You can leave the other blank
	// print an in-order traversal
	void printFriends(FILE *outfile);
	void printFriends(ofstream *outstream);
};
#endif

