#include <iostream>
using namespace std;
#include "Node.h"

Node::Node()
{
	value = NULL;
	left = NULL;
	right = NULL;
}

Node::Node(Friend *f)
{
	value = f;
	left = NULL;
	right = NULL;
}

void Node::setValue(Friend *f)
{
	value = f;
}

void Node::setLeft(Node *l)
{
	left = l;
}

void Node::setRight(Node *l)
{
	right = l;
}

Friend *Node::getValue()
{
	return value;
}

Node *Node::getLeft()
{
	return left;
}

Node *Node::getRight()
{
	return right;
}

void Node::printNode(FILE *fp)
{
	value->printFriend(fp);
}
