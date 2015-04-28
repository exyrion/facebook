#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include "Friend.h"

class Link {
	Friend *value;
	Link *next;

   public:
	Link();
	Link(Friend *);

	void setValue(Friend *);
	void setNext(Link *);
	Friend *getValue();
	Link *getNext();

	void printLink(FILE *);

};

#endif

