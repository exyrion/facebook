
#include <iostream>
using namespace std;
#include "Link.h"

Link::Link()
{
	value = NULL;
	next = NULL;
}

Link::Link(Friend *f)
{
	value = f;
	next = NULL;
}

void Link::setValue(Friend *f)
{
	value = f;
}

void Link::setNext(Link *l)
{
	next = l;
}

Friend *Link::getValue()
{
	return value;
}

Link *Link::getNext()
{
	return next;
}

void Link::printLink(FILE *fp)
{
	value->printFriend(fp);
}
