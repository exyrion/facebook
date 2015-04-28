#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "Circle.h"
#include "Circles.h"

Circles::Circles()
{
	allocatedSize = 10;
	numCircles = 0;
	array = new Circle *[allocatedSize];
	int i;
	for(i=0;i<allocatedSize;i++)
		array[i] = NULL;
}

Circles::~Circles()
{
	delete[] array;
}

int Circles::getNumCircles()
{
	return numCircles;
}

Circle *Circles::getCircle(int index)
{
	if (index >= numCircles)
		return NULL;
	else
		return array[index];

}


void Circles::addCircle(Circle *f)
{
	numCircles++;
	if (numCircles >= allocatedSize)
		expand();
	array[numCircles-1] = f;
}


void Circles::printCircles(FILE *outfile)
{
	int i;
	for (i=0;i<numCircles;i++)
	{
		fprintf(outfile,"%d: %s\n",i,array[i]->getCirclename());
	}

}

void Circles::printCircles(ofstream *outstream)
{
	int i;
	for (i=0;i<numCircles;i++)
	{
		*outstream << i << ": " << array[i]->getCirclename()<<endl;
	}


}

void Circles::expand()
{
	int newSize = allocatedSize * 2;
	Circle **new_array = new Circle *[newSize];
	int i;
	for(i=0;i<allocatedSize;i++)
		new_array[i] = array[i];
	for(i;i<newSize;i++)
		new_array[i] = NULL;
	delete[] array;
	array = new_array;
	allocatedSize = newSize;
}
