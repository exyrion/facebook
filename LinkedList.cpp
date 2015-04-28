#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

void LinkedList::addFront(Friend *f)
{

	Link *l = new Link(f);
	// if the list is empty
	if (head == NULL)
	{
		// this link is the entire list
		head = l;
		tail = l;
	}
	// if the list is not empty
	else
	{
		// make the new link's next pointer point to
		// the first link in the list
		l->setNext(head);
		//  make the head pointer point to the new link
		head = l;
		if (tail == NULL)
			tail = head;
	}
}

void LinkedList::addBack(Friend *f)
{

	Link *l = new Link(f);
	// if the list is empty
	if (head == NULL)
	{
		// this link i sthe entire list
		head = l;
		tail = l;
	}
	// if the list has many items in it
	else
	{
		// make that last element point to the new link
		tail->setNext(l);
		tail = l;
	}
}

Friend *LinkedList::removeFront()
{
	if (head == NULL)
	{
		return NULL;
	}
	else if (head == tail)
	{
		Friend *f = head->getValue();
		delete head;
		head = NULL;
		tail = NULL;
		return f;
	}
	else
	{
		Friend *f = head->getValue();
		Link *l = head;
		head = head->getNext();
		delete l;
		return f;
	}
}

void LinkedList::printList(FILE *fp)
{

	Link *l = head;
	// for each Link, call the printLink method
	for(l = head;l != NULL; l = l->getNext())
	{
		// call l's printLink method
		l->printLink(fp);
	}
}

