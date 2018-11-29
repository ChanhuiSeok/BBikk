#include<stdio.h>
#include<string.h>
#include<curses.h>

void show_counsel(char name[], char pname[], int count, char date[])
{
	initscr();

	clear();
	
	move(10,20);
	addstr("***********Counsel Content************");
	move(13,20);
	printw("Student Name: %s", name);
	move(15,20);
	printw("Professor Name: %s", pname);
	move(17,20);
	printw("Counsel count: %d",count);
	move(19,20);
	printw("Counsel date: %s",date);
	move(21,0);

	refresh();
	getch();

	endwin();
}
		

