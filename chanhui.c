#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>
// create
int menu();
int diary();

int main(){
	WINDOW * first;
	WINDOW * first_in;
	WINDOW * stick;
	WINDOW * stick2;
	initscr();

	char barcode[50];
	
// First Page

	move(5,10);
	first = newwin(25,80,5,15);
	wborder(first,'|','|','=','=','*','*','*','*');
	refresh();
	wrefresh(first);
	
	move(10, 30);
	attron(A_BOLD);
	addstr("--------- WELCOME Our Barcode System !!! ---------");
	attroff(A_BOLD);
	move(12,30);
	addstr("    Program Made by _ Team BBikk / Ver 1.0.0.1    ");
	move(13,30);
	addstr("  SongMinJu / JeonJiU / KimHyeonWoo / SeokChanHui ");
	move(15,30);
	addstr("--------------------------------------------------");
	refresh();

	move(20,20);
	first_in = newwin(5,60,20,25);
	wborder(first_in,'|','|','=','=','*','*','*','*');
	refresh();
	wrefresh(first_in);

	stick = newwin(20,29,28,40);
	wborder(stick,'|','|','-','-','+','+','+','+');
	refresh();
	wrefresh(stick);
	
	stick2 = newwin(3,29,48,40);
	wborder(stick2,'|','|','-','-','*','*','*','*');
	refresh();
	wrefresh(stick2);

	start_color();
	init_pair(1,COLOR_YELLOW,COLOR_YELLOW);
	attron(COLOR_PAIR(1));

	move(31,61);addstr("**");
	move(32,53);addstr("**");
	move(32,61);addstr("**");
	
	move(33,52);addstr("****");
	move(33,58);addstr("********");

	move(34,51);addstr("**");
	move(34,55);addstr("**");
	move(34,61);addstr("**");
	
	move(35,50);addstr("**");
	move(35,56);addstr("**");
	move(35,61);addstr("**");
	
	move(36,49);addstr("**********");
    
	move(37,48);addstr("**");
	move(37,58);addstr("**");

	move(38,47);addstr("**");
	move(38,59);addstr("**");

	move(39,46);addstr("**");
	move(39,60);addstr("**");

	attroff(COLOR_PAIR(1));

	refresh();

	move(22, 35);
	
	attron(A_BOLD);
	addstr("BARCODE IN >> ");
	move(22, 55);
	mvgetstr(22,60,barcode);
	attroff(A_BOLD);

	//(1) 20151115231-SeokChanHui
	if(!strcmp(barcode,"20151115231")){
		sleep(1);
		menu(barcode);
	}

//	scanw("%d",&ch);

//if(ch==1){
//		diary();
//	}
}

int menu(char* barcode){

	initscr();
	clear();

	printw("%s",barcode);

	refresh();
	getch();
	endwin();

}


int diary(){
	
	WINDOW *my_win;
	WINDOW *real_win;
	WINDOW *home;
	int ch;
	char txt[50];
	char title[50];

	int fd;
	int wr;
	clear();
	initscr();
	start_color;
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	my_win = newwin(10,70,7,10);
	real_win = newwin(9,68,6,9);
	
	box(my_win,ACS_VLINE,ACS_HLINE);
	box(real_win,ACS_VLINE,ACS_HLINE);
	refresh();
	wprintw(my_win, "*** MY DIARY :) ***");
	wprintw(real_win, "**********< MY DIARY :) >**********");
	wrefresh(my_win);
	wrefresh(real_win);

	move(8, 11);
	attron(A_BOLD);
	addstr("Diary Title : ");
	attroff(A_BOLD);
	move(8, 25);
	mvgetstr(8,25,title);

	move(11,11);
	mvgetstr(11,11, txt);

	strcat(title,".txt");

	if ( (fd=creat(title,0644)) == -1){
		perror("creat");
	}

	if ( wr = write(fd, txt, strlen(txt)) == -1){
		perror("write");
	}
	move(15,15);
	printw("Save Successfully!!");
	attroff(COLOR_PAIR(2));

	close(fd);
	move(13,13);
//	printw("%s\n",txt);
	

	ch=getch();
	endwin();


}
