//Justin Liang


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "Friend.h"
#include "Friends.h"
#include "Node.h"
#include "Link.h"
#include "LinkedList.h"

Friends::Friends()
{
	root = NULL;
	numFriends = 0;
}

Friends::~Friends()
{
}

int Friends::getNumFriends()
{
	return numFriends;
}

/* getFriend
 *
 * recursively code this to return the Friend that matches f
 *
 * In linked lists and the array, we found the friend by index.
 * This doesn't make sense in a binary search tree - how do we
 * number the nodes?  Instead, we need to use the binary search
 * tree to find the friend based on the compare method.  Rewrite
 * the getFriend method to work for the binary tree, looking for
 * the item that matches f rather than the index i.1
 */

Friend *Friends::getFriend(Friend *f, Node *r)
{
	if(r == NULL)
	{
		return NULL;
	}
	else
	{
		if(f->compare(r->getValue()) == 0)
		{
			return r->getValue();
		}
		else if(f->compare(r->getValue()) > 0)
		{
			return getFriend(f, r->getRight());
		}
		else if(f->compare(r->getValue()) < 0)
		{
			return getFriend(f, r->getLeft());
		}
	}
}

Friend *Friends::getFriend(Friend *f)
{
	return getFriend(f,root);
}

/* addFriend
 *
 * finds where the new Friend should go in the BST
 * and then creates the Node and inserts it into the BST
 *
 * This must be implemented recursively
 * This is called by the public method addFrirend implemented below
 * (I already implemented it for you)
 */

void Friends::addFriend(Friend *f, Node *r)
{
	if(f->compare(r->getValue()) < 0)
	{
		if(r->getLeft() == NULL)
		{
			r->setLeft(new Node(f));
		}
		else
		{
			addFriend(f, r->getLeft());
		}
	}
	else
	{
		if(r->getRight() == NULL)
		{
			r->setRight(new Node(f));
		}
		else
		{
			addFriend(f, r->getRight());
		}
	}
}

/*  addFriend
 *
 *  This is the public method call to addFriend.  This
 *  begins the recursion, too, if the item is not being added
 *  to the root node (to be the root node or to be the child of
 *  the root node).  Your job is to implement the recursive method.
 *  No change to this method is necessary, but it would be useful for
 *  you to go through it and make sure you understand all of it, because
 *  components of it will be the same as in the recursive method.
 */

void Friends::addFriend(Friend *f)
{
	numFriends++;
	// if the tree is empty, make root and return
	if (root == NULL)
	{
		root = new Node(f);
		return;
	}

	// compare to this node's friend
	int comp = f->compare(root->getValue());
	// if it is smaller
	if (comp < 0)
	{
		if (root->getLeft() != NULL)
			addFriend(f, root->getLeft());
		else
			root->setLeft(new Node(f));
	}
	// if it is larger
	else
	{
		if (root->getRight() != NULL)
			addFriend(f, root->getRight());
		else
			root->setRight(new Node(f));
	}
}

/* findSuccessor
 *
 * this method finds the Friend that is the value in the node
 * that is the next larger than rt.  This is used by the
 * removeFriend method, so you can test it by removing friends.
 *
 * Note that rt is a Node *, but it is returning a Friend *
 */
Friend *Friends::findSuccessor(Node *rt)
{
	if(rt->getRight() == NULL)
		return NULL;
	else
		return (rt->getRight())->getValue();
}

/* removeFriend
 *
 * This is a *really* complicated method, so I am not requiring
 * you to write it.  You are only writing one useful method -
 * getSuccessor.
 */

void Friends::removeFriend(Friend *f, Node *parent)
{
	// check if parent's child is the one to be removed
	int comp = f->compare(parent->getValue());
	if (comp < 0)
	{
		Node *left = parent->getLeft();
		if (left == NULL)
			return;

		if (f->compare(left->getValue()) == 0)
		{
			printf("Remove this one\n");
			// check to see if left has 0 or 1 child
			if (left->getLeft() == NULL)
				parent->setLeft(left->getRight());
			else if (left->getRight() == NULL)
				parent->setLeft(left->getLeft());
			// if successor is left->getRight()
			else if (left->getRight()->getLeft() == NULL)
			{
				// move succ up to left
				Node *succ = left->getRight();
				succ->setLeft(left->getLeft());
				parent->setLeft(succ);
			}
			// otherwise, find successor, trade, remove it
			else
			{
				Friend *swap = findSuccessor(left);
				left->setValue(swap);
				removeFriend(swap,left->getRight());
			}
			delete left;
		}
		else
			removeFriend(f,left);
	}
	else
	{
		Node *right = parent->getRight();
		if (right == NULL)
			return;
		if (f->compare(right->getValue()) == 0)
		{
			// check to see if right has 0 or 1 child
			if (right->getLeft() == NULL)
				parent->setRight(right->getRight());
			else if (right->getRight() == NULL)
				parent->setRight(right->getLeft());
			// if successor is right->getRight()
			else if (right->getRight()->getLeft() == NULL)
			{
				// move succ up to right
				Node *succ = right->getRight();
				succ->setLeft(right->getLeft());
				parent->setRight(succ);
			}
			// otherwise, find successor, trade, remove it
			else
			{
				Friend *swap = findSuccessor(right);
				right->setValue(swap);
				removeFriend(swap,right->getRight());
				return;
			}
			delete right;
		}
		else
			removeFriend(f,right);
	}
}

void Friends::removeFriend(Friend *f)
{
	numFriends--;
	// if there is no tree, do nothing
	if (root == NULL)
		return;
	printf("Compare ");
	f->printFriend(stdout);
	printf(" and ");
	root->getValue()->printFriend(stdout);
	int comp = f->compare(root->getValue());
	printf(": %d\n",comp);
	// if the root matches, remove root
	if (comp == 0)
	{
		Node *n = root;
		// if root has 0 or 1 children, simple
		if ((root->getLeft() == NULL) && (root->getRight() == NULL))
			root = NULL;
		else if (root->getLeft() == NULL)
			root = root->getRight();
		else if (root->getRight() == NULL)
			root = root->getLeft();
		// replace root with successor
		else
		{
			// go one to the right, all the way to the left
			n = root->getRight();
			// if right child has no left child, swap with
			// right child
			if (n->getLeft() == NULL)
			{
				n->setLeft(root->getLeft());
				delete root;
				root = n;
			}
			else
			{
				// stop right above successor
				while(n->getLeft()->getLeft() != NULL)
					n = n->getLeft();
				// put succ into root
				Node *succ = n->getLeft();
				root->setValue(succ->getValue());
				removeFriend(succ->getValue(),n);
			}
			return;
		}
		delete n;
	}
	else
		removeFriend(f, root);
}

/* makeTraversalQueue
 *
 * This method is called by the reset method for the iterator.
 * This is a recursive function that does an in-order traversal of
 * the BST.  Instead of printing out the node, like in your printFriends
 * method, you insert each FRIEND (not the node) into the queue
 * (the queue created in the resetIterator).  Then,
 * the getNextFriend, removes the items in that order.
 * Note that the queue is of type LinkedList - so you can't use dequeue
 * and enqueue.  You need to use LinkedList methods (i.e. addFront, addBack)
 */

void Friends::makeTraversalQueue(Node *r)
{
	if(r!=NULL)
	{
		makeTraversalQueue(r->getRight());
		queue->addFront(r->getValue());
		makeTraversalQueue(r->getLeft());
	}
}

void Friends::resetIterator()
{
	queue = new LinkedList();
	makeTraversalQueue(root);
}

/* getNextFriend
 *
 * In the resetIterator, a queue was created that holds all the friends in
 * the proper order.  Each time getNextFriend is called, remove the next item
 * in the queue and return it.
 */
Friend *Friends::getNextFriend()
{
	queue->removeFront();
}

/* printFriends
 *
 * this is an in-order traversal of the BST.
 * You MUST do this recursively
 */
void Friends::printFriendsHelper(FILE *outfile, Node *r)
{
	if(r != NULL)
	{
		printFriendsHelper(outfile, r->getLeft());
		r->printNode(outfile);
		fprintf(outfile, "\n");
		printFriendsHelper(outfile, r->getRight());
	}
}

void Friends::printFriends(FILE *outfile)
{
	printFriendsHelper(outfile, root);
}

void Friends::printFriends(ofstream *outstream)
{
	// do not fill this in - fill in the one above
}

