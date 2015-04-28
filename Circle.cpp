#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "Friend.h"
#include "Circle.h"

Circle::Circle()
{
	allocatedSize = 10;
	numFriends = 0;
	name = NULL;
	array = new Friend *[allocatedSize];
	int i;
	for(i=0;i<allocatedSize;i++)
		array[i] = NULL;
}

Circle::~Circle()
{
	delete[] array;
}

int Circle::getNumFriends()
{
	return numFriends;
}

Friend *Circle::getFriend(int index)
{
	if (index >= numFriends)
		return NULL;
	else
		return array[index];

}

char *Circle::getCirclename()
{
	return name;
}

void Circle::addFriend(Friend *f)
{
	numFriends++;
	if (numFriends >= allocatedSize)
		expand();
	array[numFriends-1] = f;
}

void Circle::setCirclename(char *n)
{
	name = n;
}

void Circle::printCircle(FILE *outfile)
{
	int i;
	for (i=0;i<numFriends;i++)
	{
		array[i]->printFriend(outfile);
		fprintf(outfile,"\n");
	}

}

void Circle::printCircle(ofstream *outstream)
{
	int i;
	for (i=0;i<numFriends;i++)
	{
		array[i]->printFriend(outstream);
		*outstream << endl;
	}


}

void Circle::expand()
{
	int newSize = allocatedSize * 2;
	Friend **new_array = new Friend *[newSize];
	int i;
	for(i=0;i<allocatedSize;i++)
		new_array[i] = array[i];
	for(i;i<newSize;i++)
		new_array[i] = NULL;
	delete[] array;
	array = new_array;
	allocatedSize = newSize;
}
