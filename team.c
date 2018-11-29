#include<stdio.h>
#include<string.h>
#include<curses.h>

void show_counsel(char name[], int late, int absent, char rent[], char delay[], char fname[], int count, char date[])
{
	initscr();

	clear();
	
	move(10,20);
	addstr("***********Counsel Content************");
	move(13,20);
	printw("Student Name: %s\n", name);

	
	
	refresh();
	getch();

	endwin();
}
		

