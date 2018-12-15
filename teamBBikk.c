//
// [System Programming Team Project]
// 
// 
// Created by team BBikk
// Kim Hyeonwoo, Song Minju, Jeong Jiu, Seok Chanhui
// Last ver. date 20181206
// 

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>

#define BUFFERSIZE 4096

/* Global Varable & Func declaration */
char * info[8];
char barcode[50];
int menu();
int diary();
int start();

/* Main Function */
int main() {
	start();
}

/* start() - Program Start Page */
int start() {
	WINDOW * first;
	WINDOW * first_in;
	WINDOW * stick;
	WINDOW * stick2;

	initscr();

	// create upper window
	move(5, 10);
	first = newwin(15, 80, 0, 15);
	wborder(first, '|', '|', '=', '=', '*', '*', '*', '*');
	refresh();
	wrefresh(first);

	move(2, 30);
	attron(A_BOLD);
	addstr("--------- WELCOME Our Barcode System !!! ---------");
	attroff(A_BOLD);
	move(4, 30);
	addstr("    Program Made by _ Team BBikk / Ver 1.0.0.1    ");
	move(6, 30);
	addstr("  SongMinJu / JeonJiU / KimHyeonWoo / SeokChanHui ");
	move(8, 30);
	addstr("--------------------------------------------------");
	refresh();

	move(5, 20);
	first_in = newwin(5, 60, 8, 25);
	wborder(first_in, '|', '|', '=', '=', '*', '*', '*', '*');
	refresh();
	wrefresh(first_in);

	stick = newwin(11, 29, 15, 40);
	wborder(stick, '|', '|', '-', '-', '+', '+', '+', '+');
	refresh();
	wrefresh(stick);


	// Color Palette Setting
	if (has_colors()) {
		start_color();
		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		init_pair(2, COLOR_WHITE, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	}
	start_color();
	attron(COLOR_PAIR(3));


	// Drawing "A+"
	move(16, 61); addstr("**");
	move(17, 53); addstr("**");
	move(17, 61); addstr("**");
	move(18, 52); addstr("****");
	move(18, 58); addstr("********");
	move(19, 51); addstr("**");
	move(19, 55); addstr("**");
	move(19, 61); addstr("**");
	move(20, 50); addstr("**");
	move(20, 56); addstr("**");
	move(20, 61); addstr("**");
	move(21, 49); addstr("**********");
	move(22, 48); addstr("**");
	move(22, 58); addstr("**");
	move(23, 47); addstr("**");
	move(23, 59); addstr("**");
	move(24, 46); addstr("**");
	move(24, 60); addstr("**");

	attroff(COLOR_PAIR(3));

	attron(COLOR_PAIR(1));
	refresh();
	move(10, 35);

	attron(A_BOLD);
	addstr("BARCODE IN >> ");
	move(10, 55);
	mvgetstr(10, 60, barcode);
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));

	// Applying user list
	if (!strcmp(barcode, "20171131351")) {
		sleep(1);
		menu(barcode);
	}
	else if (!strcmp(barcode, "20151132331")) {
		sleep(1);
		menu(barcode);
	}
}

/* menu() - Menu Selection Page */
int menu(char* barcode) {

	WINDOW * menuBar;
	WINDOW * menuBar2;
	WINDOW * menuList;
	int fd, n_chars;
	int i = 0, j = 0;
	int dir = 5, pos = 0, count = 0;
	int choice;
	int highlight = 0;
	char bar[50] = { 0, };
	char Buf[BUFFERSIZE];
	char *hello[8];
	strcat(bar, barcode);
	strcat(bar, ".txt");

	//  Read user info file
	if ((fd = open(bar, O_RDONLY)) == -1) {
		printw("cannot open");
		refresh();
		exit(1);
	}
	while ((n_chars = read(fd, Buf, BUFFERSIZE) > 0)) {
		hello[i] = Buf;
		i++;
	}
	i = 0;
	char * ptr = strtok(hello[0], "\n");
	while (ptr != NULL) {
		info[i] = ptr;
		ptr = strtok(NULL, "\n");
		i++;
	}

	initscr();
	clear();
	start_color();
	attron(COLOR_PAIR(2));
	menuBar = newwin(3, 80, 1, 1);
	wborder(menuBar, '|', '|', '=', '=', '+', '+', '+', '+');
	menuBar2 = newwin(3, 80, 3, 1);
	wborder(menuBar2, '|', '|', '=', '=', '+', '+', '+', '+');
	refresh();
	wrefresh(menuBar);
	wrefresh(menuBar2);
	attroff(COLOR_PAIR(2));

	move(2, 2);
	printw("[CONNECT]");
	attron(COLOR_PAIR(1));
	move(2, 12);
	printw("%s", info[0]);
	attroff(COLOR_PAIR(1));
	move(2, 60);
	printw("");
	move(4, 25);
	attron(A_BOLD);
	printw(" S E L E C T   T H E   M E N U ");
	attroff(A_BOLD);

	menuList = newwin(7, 40, 8, 20);
	wborder(menuList, '*', '*', '*', '*', '*', '*', '*', '*');
	refresh();
	wrefresh(menuList);
	keypad(menuList, true);

	char *choices[5] = { "         [1] Show Attendence         ", "         [2] Show Using Library      ","         [3] Show Professor Counsel   ", "         [4] Writing A Diary         ","         [5] Return Home       " };
	while (1) {
		for (j = 0; j < 5; j++) {
			if (j == highlight)
				wattron(menuList, A_REVERSE);
			mvwprintw(menuList, j + 1, 1, choices[j]);
			wattroff(menuList, A_REVERSE);
		}
		choice = wgetch(menuList);

		switch (choice) {
		case KEY_UP:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;
		case KEY_DOWN:
			highlight++;
			if (highlight == 5)
				highlight = 4;
			break;
		default:
			break;
		}
		if (choice == 10)
			break;
	}
	move(15, 10);

	// Select menu (1~4, Selected is highlighted)
	if (highlight == 0)
		attend();
	else if (highlight == 1)
		library();
	else if (highlight == 2)
		counsel();
	else if (highlight == 3)
		diary();
	else if (highlight == 4) {
		clear();
		start();
	}

	refresh();
	getch();
	endwin();

}

/* [MENU 1] Attendence Info */
int attend() {

	WINDOW *my_win;
	WINDOW *real_win;
	WINDOW *home;
	WINDOW *menuBar;
	WINDOW *menuBar2;
	int ch;
	char txt[50];
	char title[50];

	int fd;
	int wr;
	clear();
	initscr();

	// create top common menu
	start_color();
	attron(COLOR_PAIR(2));
	menuBar = newwin(3, 80, 1, 1);
	wborder(menuBar, '|', '|', '=', '=', '+', '+', '+', '+');
	menuBar2 = newwin(3, 80, 3, 1);
	wborder(menuBar2, '|', '|', '=', '=', '+', '+', '+', '+');
	refresh();
	wrefresh(menuBar);
	wrefresh(menuBar2);
	attroff(COLOR_PAIR(2));

	move(2, 2);
	printw("[CONNECT]");
	attron(COLOR_PAIR(1));
	move(2, 12);
	printw("%s", info[0]);
	attroff(COLOR_PAIR(1));
	move(2, 60);
	printw("[Go home | press 0]");
	move(4, 24);
	attron(A_BOLD);
	printw(" A T T E N D E N C E   I N F O ");
	attroff(A_BOLD);

	my_win = newwin(10, 65, 7, 10);
	box(my_win, ACS_VLINE, ACS_HLINE);
	refresh();
	wprintw(my_win, "MY ATTENDENCE INFO");


	// create window for content ouput
	wrefresh(my_win);
	move(9, 16);
	printw("<Late Count> : %s", info[1]);
	move(11, 16);
	printw("<Absent Count> : %s", info[2]);

	move(13, 17);
	if (atoi(info[2]) < 7 && atoi(info[2]) >= 5)
		printw("* * * OOPS! BE CAREFUL F!!!! * * *");
	else if (atoi(info[2]) < 5 && atoi(info[2]) >= 3)
		printw("* * * SMART GUY~~~!! * * *");
	else if (atoi(info[2]) < 3)
		printw("* * * YOU ARE 'A'!! LET'S GET IT!! * * *");

	move(18, 5);

	// press 0 -> back to the menu
	if ((ch = getch()) == '0') {

		clear();
		menu(barcode);
	}

}


/* [MENU 2] Professor Counsel Info */
int counsel() {

	WINDOW *my_win;
	WINDOW *real_win;
	WINDOW *home;
	WINDOW *menuBar;
	WINDOW *menuBar2;
	int ch;
	char txt[50];
	char title[50];
	int back;
	int fd;
	int wr;

	clear();
	initscr();

	// create top common menu
	start_color();
	attron(COLOR_PAIR(2));
	menuBar = newwin(3, 80, 1, 1);
	wborder(menuBar, '|', '|', '=', '=', '+', '+', '+', '+');
	menuBar2 = newwin(3, 80, 3, 1);
	wborder(menuBar2, '|', '|', '=', '=', '+', '+', '+', '+');
	refresh();
	wrefresh(menuBar);
	wrefresh(menuBar2);
	attroff(COLOR_PAIR(2));

	move(2, 2);
	printw("[CONNECT]");
	attron(COLOR_PAIR(1));
	move(2, 12);
	printw("%s", info[0]);
	attroff(COLOR_PAIR(1));
	move(2, 60);
	printw("[Go home | press 0]");
	move(4, 24);
	attron(A_BOLD);
	printw(" M Y   C O U N S E L  I N F O ");
	attroff(A_BOLD);

	my_win = newwin(10, 70, 7, 10);
	box(my_win, ACS_VLINE, ACS_HLINE);
	refresh();
	wprintw(my_win, "MY COUNSEL INFO");


	// create window for content ouput
	wrefresh(my_win);
	move(9, 16);
	printw("<Professor Name> : %s", info[8]);
	move(11, 16);
	printw("<Counsel Count> : %s", info[9]);

	move(13, 17);
	if (atoi(info[6]) < 7 && atoi(info[6]) >= 5)
		printw("* * * MANY Counsel Counts! AWESOME!! * * *");
	else if (atoi(info[6]) < 5 && atoi(info[6]) >= 4)
		printw("* * * It's OKAY~! * * *");
	else if (atoi(info[6]) <= 3)
		printw("* * * Please VISIT YOUR PROFESSOR..! * * *");

	move(18, 3);

	// press 0 -> back to the menu
	if ((ch = getch()) == '0') {

		clear();
		menu(barcode);
	}

}


/* [MENU 3] Using Library Info */
int library() {

	WINDOW *bor_win;
	WINDOW *late_win;
	WINDOW *home;
	WINDOW *menuBar;
	WINDOW *menuBar2;
	int ch;
	char txt[50];
	char title[50];

	int fd;
	int wr;
	clear();
	initscr();

	// create top common menu
	start_color();
	attron(COLOR_PAIR(2));
	menuBar = newwin(3, 80, 1, 1);
	wborder(menuBar, '|', '|', '=', '=', '+', '+', '+', '+');
	menuBar2 = newwin(3, 80, 3, 1);
	wborder(menuBar2, '|', '|', '=', '=', '+', '+', '+', '+');
	refresh();
	wrefresh(menuBar);
	wrefresh(menuBar2);
	attroff(COLOR_PAIR(2));

	move(2, 2);
	printw("[CONNECT]");
	attron(COLOR_PAIR(1));
	move(2, 12);
	printw("%s", info[0]);
	attroff(COLOR_PAIR(1));
	move(2, 60);
	printw("[Go home | press 0]");
	move(4, 24);
	attron(A_BOLD);
	printw(" M Y  L I B R A R Y  I N F O  ");
	attroff(A_BOLD);


	// create window for content ouput
	bor_win = newwin(14, 30, 7, 10);
	late_win = newwin(14, 30, 7, 40);
	box(bor_win, ACS_VLINE, ACS_HLINE);
	box(late_win, ACS_VLINE, ACS_HLINE);
	refresh();
	wprintw(bor_win, "*** BORROWED ***");
	wprintw(late_win, "*** OVERDUE ***");

	wrefresh(bor_win);
	wrefresh(late_win);

	// borrow list
	move(9, 13);
	printw("%s", info[3]);
	move(11, 13);
	printw("%s", info[4]);
	move(13, 13);
	printw("%s", info[5]);
	move(15, 13);
	printw("%s", info[6]);

	// overdue list
	move(9, 44);
	printw("%s", info[7]);
	move(23, 5);

	// press 0 -> back to the menu
	if ((ch = getch()) == '0') {

		clear();
		menu(barcode);
	}

}

int diary() {

	WINDOW *my_win;
	WINDOW *real_win;
	WINDOW *home;
	WINDOW *menuBar;
	WINDOW *menuBar2;
	int ch;
	char txt[50];
	char title[50];

	int fd;
	int wr;
	clear();
	initscr();

	// create top common menu
	start_color();
	attron(COLOR_PAIR(2));
	menuBar = newwin(3, 80, 1, 1);
	wborder(menuBar, '|', '|', '=', '=', '+', '+', '+', '+');
	menuBar2 = newwin(3, 80, 3, 1);
	wborder(menuBar2, '|', '|', '=', '=', '+', '+', '+', '+');
	refresh();
	wrefresh(menuBar);
	wrefresh(menuBar2);
	attroff(COLOR_PAIR(2));

	move(2, 2);
	printw("[CONNECT]");
	attron(COLOR_PAIR(1));
	move(2, 12);
	printw("%s", info[0]);
	attroff(COLOR_PAIR(1));
	move(2, 60);
	printw("[Go home | press 0]");
	move(4, 24);
	attron(A_BOLD);
	printw(" W R I T I N G   M Y   D I A R Y ");
	attroff(A_BOLD);


	// create window for content ouput
	my_win = newwin(10, 70, 10, 10);
	real_win = newwin(9, 68, 9, 9);

	box(my_win, ACS_VLINE, ACS_HLINE);
	box(real_win, ACS_VLINE, ACS_HLINE);
	refresh();
	wprintw(my_win, "*** MY DIARY :) ***");
	wprintw(real_win, "**********< MY DIARY :) >**********");
	wrefresh(my_win);
	wrefresh(real_win);

	move(11, 11);
	attron(A_BOLD);
	attron(COLOR_PAIR(1));
	addstr("Diary Title : ");
	attroff(A_BOLD);
	move(11, 25);
	mvgetstr(11, 25, title);
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvgetstr(13, 11, txt);
	attroff(COLOR_PAIR(2));
	strcat(title, ".txt");

	if ((fd = creat(title, 0644)) == -1) {
		perror("creat");
	}

	if (wr = write(fd, txt, strlen(txt)) == -1) {
		perror("write");
	}
	move(18, 15);
	printw("Save Successfully!!");
	attroff(COLOR_PAIR(1));

	close(fd);
	move(13, 13);
	move(18, 5);

	// press 0 -> back to the menu
	if ((ch = getch()) == '0') {

		clear();
		menu(barcode);
	}

}
