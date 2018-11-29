#include<stdio.h>
#include<string.h>
#include<curses.h>

void show_counsel(long long int  barcode)
{
	initscr();

	clear();
	
	move(10,20);
	addstr("***********Counsel Content************");
	move(13,20);
	
	if (barcode == 20171131511) {
		addstr("[Student Information]");
		move(15,20);
		addstr("Song Min Ju  2017113151");
		move(17,20);
		addstr("Professor : Han Gi Jun");
		move(19,20);
		addstr("Counsel count : 1");
		move(21,20);
		addstr("Counsel date : 2018.05.01");
		move(23,0);
	}
	else if (barcode == 20171131351) {
                addstr("[Student Information]");
                move(15,20);
                addstr("Jung Ji U  2017113135");
                move(17,20);
                addstr("Professor : Lee Eun Ju");
                move(19,20);
                addstr("Counsel count : 2");
                move(21,20);
                addstr("Counsel date : 2017.04.22");
                move(23,20);
		addstr("         : 2018.11.22");
		move(25,0);
	      }
	 else if (barcode == 20171132311) {
                addstr("[Student Information]");
                move(15,20);
                addstr("Kim Hyun Woo  2015113231");
                move(17,20);
                addstr("Professor : Tak Byeong Cheol");
                move(19,20);
                addstr("Counsel count : 1");
                move(21,20);
                addstr("Counsel date : 2018.10.13");
                move(23,0);
              }
	 else {
                addstr("[Student Information]");
                move(15,20);
                addstr("Soek Chan hui  2015111523");
                move(17,20);
                addstr("Professor : Hong Seok in");
                move(19,20);
                addstr("Counsel count : 2");
                move(21,20);
                addstr("Counsel date : 2016.10.01  2018.09.27");
		move(23,0);

              }
	
	refresh();
	getch();

	endwin();
}
		

