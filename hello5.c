#include <stdio.h>
#include <curses.h>
#define LEFTEDGE 0
#define RIGHTEDGE 60
#define ROW 40

main()
{
	char name[] = "name";
	char student[] = "s2017...";
	char messagehi[] = "hello everyone!";
	char messagepl[] = "please. take a bar code";
	char message[] = "bbic and next ya";
	char blank[] = "                                       ";
	char barcode[] = "  ";
	int dir = +5;
	int pos = 0;
	int flag = 0;

	initscr();
	clear();
	while(1)
	{
		move(ROW,pos);
		addstr(message);
		move(10,40);
		addstr(messagehi);
		move(15,35);
		attron(A_BLINK);
		addstr(messagepl);
		attroff(A_BLINK);
		move(LINES-1,COLS-1);
		refresh();
		sleep(1);
		move(ROW,pos);
		addstr(blank);
		pos += dir;
		if(pos >= COLS -1)
			dir = -5;
		if(pos <= COLS)
			dir = +5;
		flag++;
		if(flag == 5)
			break;//if barcode input
	}
	move(LINES,COLS);
	clear();
	refresh();

	char star = '*';
	char messagecho[] = "*****************CHOICE!******************";
	char message1[] = "  1. Show Attendence.";
	char message2[] = "  2. Show Library Using.";
	char message3[] = "  3. Show Professor Counsel.";
	char messageend[] = "******************************************";

	move(10,20);
	addstr(messagecho);
	move(15,20);
	addstr(message1);
	move(20,20);
	addstr(message2);
	move(25,20);
	addstr(message3);
	move(30,20);
	addstr(messageend);
	int i=10;
	while(i<=30){
		move(i,20);
		addch(star);
		move(i,61);
		addch(star);
		i++;
	}



	refresh();

	char choice;
	choice = getch();

	clear();

	switch(choice)
	{
		case '1':
			move(10,10);
			addstr("fffffffddffffffffff");
			move(15,10);
			addstr("eeeeeeeeeeeeeeeeeeeeeee\n");
			break;
		case '2':
			break;
		case '3':
			break;

	}

	getch();



//	endwin();

}
