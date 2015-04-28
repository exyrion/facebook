/*
//Justin Liang

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "string.h"
#include "Friend.h"
#include "Friends.h"
#include "Circle.h"
#include "Circles.h"



Friends friends;
Friend *backup[10];

int main(int argc, char **argv)
{
	FILE *fp = stdin;
	char buf[256];
	char *s, *s2;
	Friend *fr;
	int i;
	int size;
	int option;
	char *filename;
	// if there is a command-line argument (the filename)
	if (argc == 2)
		filename = argv[1];
	else
		filename = "friends.txt";
	// open the file and see if it opened properly
	if ((fp = fopen(filename,"r")) == NULL)
	{
		printf("Could not open file %s\n",filename);
		exit(1);
	}

	// read user information
	fgets(buf,256,fp);
	s = strtok(NULL," ");
	s = strtok(NULL," \n");

	// y circles
	fgets(buf,256,fp);
	size = atoi(buf);
	int num_circles = size;
	// read in the circle names
	for (i=0;i<size;i++)
	{
		fgets(buf,80,fp);
		buf[strlen(buf)-1] = '\0';
	}

	// read in the number of friends
	fgets(buf,256,fp);
	size = atoi(buf);

	//printf("%d friends\n",size);
	int num_friends = size;
	for(i=0;i<size;i++)
	{
		fr = new Friend();
		fgets(buf,80,fp);
		printf("Add friend %s",buf);
		s = strtok(buf," ");
		s2 = new char[strlen(s)+1];
		strcpy(s2,s);
		fr->setFirstName(s2);
		s = strtok(NULL," ");
		s2 = new char[strlen(s)+1];
		strcpy(s2,s);
		fr->setLastName(s2);
		s = strtok(NULL," \n");
		s2 = new char[strlen(s)+1];
		strcpy(s2,s);
		fr->setBirthDate(s2);

		backup[i] = fr;
		friends.addFriend(fr);
		printf("printFriends:\n");
		friends.printFriends(stdout);
	}
	fclose(fp);

	printf("Testing getFriend\n");
	for(i=0;i<num_friends;i++)
		if (backup[i] != friends.getFriend(backup[i]))
			printf("getFriend %d did not work\n",i);

	printf("Testing numFriends\n");
	if (num_friends != friends.getNumFriends())
		printf("numFriends is not updated properly\n");


	printf("Testing removeFriend\n");
	if (num_friends > 5)
	{
		printf("Remove ");
		backup[5]->printFriend(stdout);
		printf("\n");
		friends.removeFriend(backup[5]);
		friends.printFriends(stdout);
		backup[5] = NULL;
		num_friends--;
	}
	if (num_friends > 2)
	{
		printf("Remove ");
		backup[2]->printFriend(stdout);
		printf("\n");
		friends.removeFriend(backup[2]);
		friends.printFriends(stdout);
		backup[2] = NULL;
		num_friends--;
	}
	if (num_friends > 0)
	{
		printf("Remove ");
		backup[0]->printFriend(stdout);
		printf("\n");
		friends.removeFriend(backup[0]);
		friends.printFriends(stdout);
		backup[0] = NULL;
		num_friends--;
	}
	printf("Testing numFriends\n");
	if (num_friends != friends.getNumFriends())
		printf("numFriends is not updated properly\n");

	// now test if the iterator prints out in sorted order
	int j;
        for(i=0;i<size;i++)
	{
                for(j=1;j<size-i;j++)
		{
			if (backup[j] == NULL)
				continue;
			if ((backup[j-1] == NULL) ||
                         (backup[j]->compare(backup[j-1]) < 0))
                        {
                                Friend *tmp = backup[j];
                                backup[j] = backup[j-1];
                                backup[j-1] = tmp;
                        }
		}
	}
	friends.resetIterator();
	fr = friends.getNextFriend();
	i = 0;
	while(fr != NULL)
	{
		printf("%d: ",i);
		fr->printFriend(stdout);
		printf("\n");
		if (backup[i++] != fr)
			printf("Iterator not in the right order\n");
		fr = friends.getNextFriend();
	}
	if (i != num_friends)
		printf("Iterator did not return enough friends\n");
}
*/

