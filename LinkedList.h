#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Friend.h"
#include "Link.h"

class LinkedList {
	Link *head;
	Link *tail;
  public:
	LinkedList();

	void addFront(Friend *);
	void addBack(Friend *);
	Friend *removeFront();

	void printList(FILE *);

};

#endif

