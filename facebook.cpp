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



Friend me;
Friends friends;
Circles circles;

void listFriendsCircle();
void addFriend();
void addFriendCircle();
void removeFriend();

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
	s = strtok(buf," ");
	s2 = new char[strlen(s)+1];
	strcpy(s2,s);
	me.setFirstName(s2);
	s = strtok(NULL," ");
	s2 = new char[strlen(s)+1];
	strcpy(s2,s);
	me.setLastName(s2);
	s = strtok(NULL," \n");
	s2 = new char[strlen(s)+1];
	strcpy(s2,s);
	me.setBirthDate(s2);
	printf("strlen of %s is %d\n",s,strlen(s));

	//printf("Name: %s %s %s\n",me.lastname,me.firstname,me.birthdate);

	// y circles
	fgets(buf,256,fp);
	size = atoi(buf);
	int num_circles = size;
	//printf("%d circles\n",size);

	// read in the circle names
	for (i=0;i<size;i++)
	{
		char *s;
		Circle *c = new Circle();
		fgets(buf,80,fp);
		buf[strlen(buf)-1] = '\0';
		s = new char[strlen(buf)+1];
		strcpy(s,buf);
		c->setCirclename(s);
		//printf("Circle name %d: %s\n",i,s);
		// make a new, empty circle for each one
		circles.addCircle(c);

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

		friends.addFriend(fr);

		// now add this friend to the proper circles
		// insert into the proper circle
		s = strtok(NULL," \n");
		while (s != NULL)
		{
			// find the right circle
			int j=0;
			Circle *circle = circles.getCircle(0);
			char *circlename = circle->getCirclename();
			//printf("find circle %s\n",s);
			while(circlename != NULL)
			{
				//printf("%s vs %s\n",circlename,s);
				if (strcmp(circlename,s) == 0)
				{
					circle->addFriend(fr);
					//printf("inserted into circle %s\n", s);
					break;
				}
				j++;
				circle = circles.getCircle(j);
				circlename = circle->getCirclename();
			}
			s = strtok(NULL," \n");
		}
	}

	fclose(fp);

	do{
		// the top-level menu
		printf("What would you like to do?\n");
		printf("0) Exit\n");
		printf("1) List Friends\n");
		printf("2) List Friends in a particular Circle\n");
		printf("3) Add a Friend\n");
		printf("4) Add a Friend to a Circle\n");
		printf("5) Remove a Friend\n");

		// read the response
		fgets(buf,80,stdin);
		option = atoi(buf);
		switch (option) {
			case(0): break;
			case(1):
				friends.printFriends(stdout);break;
			case(2): listFriendsCircle();break;
			case(3): addFriend();break;
			case(4): addFriendCircle();break;
			case(5): removeFriend();break;
			default: printf("Incorrect option.  Choose from 0-4\n");
		}
	}while (option != 0);

	if ((fp = fopen(filename,"w")) == NULL)
	{
		printf("Could not open file %s for writing\n",filename);
		exit(1);
	}
	me.printFriend(fp);
	num_circles = circles.getNumCircles();
	fprintf(fp,"\n%d circles\n",num_circles);
	for(i=0;i<num_circles;i++)
		fprintf(fp,"%s\n",circles.getCircle(i)->getCirclename());
	num_friends = friends.getNumFriends();
	fprintf(fp,"%d friends\n",num_friends);
	friends.resetIterator();
	for(i=0;i<num_friends;i++)
	{
		int j;
		Friend *f = friends.getNextFriend();
		f->printFriend(fp);
		// now see what circles it's in!!!
		for (j=0;j<num_circles;j++)
		{
			Circle *circle = circles.getCircle(j);
			int size = circle->getNumFriends();
			int k;
			for(k=0;k<size;k++)
			{
				Friend *f2 = circle->getFriend(k);
				if (f2 == f)
				{
					fprintf(fp," %s",circle->getCirclename());
					break;
				}
			}
		}
		fprintf(fp,"\n");
	}

	fclose(fp);
}


void listFriendsCircle()
{
	char buf[80];
	circles.printCircles(stdout);
	printf("Which circle? ");
	fgets(buf,80,stdin);
	int i = atoi(buf);
	Circle *circle = circles.getCircle(i);
	if (circle == NULL)
	{
		printf("No circle found\n");
		return;
	}
	circle->printCircle(stdout);
}

void addFriend()
{
	char *buf = new char[64];
	Friend *f = new Friend();
	printf("Friend's first name: ");
	fgets(buf,64,stdin);
	buf[strlen(buf)-1] = '\0';
	f->setFirstName(buf);
	buf = new char[64];
	printf("Friend's last name: ");
	fgets(buf,64,stdin);
	buf[strlen(buf)-1] = '\0';
	f->setLastName(buf);
	printf("Friend's birthdate (MMDDYYYY): ");
	buf = new char[20];
	fgets(buf,20,stdin);
	buf[strlen(buf)-1] = '\0';
	f->setBirthDate(buf);

	friends.addFriend(f);

}

void removeFriend()
{
	char first[80], last[80];
	int fnum, cnum, csize;
	Circle *circle;
	Friend *f;
	friends.printFriends(stdout);
	printf("Which friend (first name): ");
	fgets(first,80,stdin);
	first[strlen(first)-1] = '\0';
	printf("Which friend (last name): ");
	fgets(last,80,stdin);
	last[strlen(last)-1] = '\0';
	friends.removeFriend(new Friend(first, last, "00000000"));
}

void addFriendCircle()
{
	char first[80], last[80], buf[80];
	int fnum, cnum, csize;
	Circle *circle;
	Friend *f;
	friends.printFriends(stdout);
	printf("Which friend (first name): ");
	fgets(first,80,stdin);
	first[strlen(first)-1] = '\0';
	printf("Which friend (last name): ");
	fgets(last,80,stdin);
	last[strlen(last)-1] = '\0';
	f = friends.getFriend(new Friend(first, last, "00000000"));
	if (f == NULL)
	{
		printf("No friend found\n");
		return;
	}
	circles.printCircles(stdout);
	printf("Which circle? ");
	fgets(buf,80,stdin);
	cnum = atoi(buf);
	circle = circles.getCircle(cnum);
	if (circle == NULL)
	{
		printf("No circle found\n");
		return;
	}
	circle->addFriend(f);
}

