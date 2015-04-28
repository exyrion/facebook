#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include "Friend.h"

class Node {
	Friend *value;
	Node *left;
	Node *right;

   public:
	Node();
	Node(Friend *);

	void setValue(Friend *);
	void setLeft(Node *);
	void setRight(Node *);
	Friend *getValue();
	Node *getLeft();
	Node *getRight();

	void printNode(FILE *);
};

#endif

