#include<stdio.h>
#include<string.h>
#include<curses.h>

void show_attend(char name[], int late, int absent)
{
        initscr();

        clear();

        move(10,20);
        addstr("***********Attend Content************");
        move(13,20);
        printw("Student Name: %s", name);
        move(15,20);
        printw("Late count: %d", late);
        move(17,20);
        printw("Absent count: %d", absent);
        move(19,0);

        refresh();
        getch();

        endwin();
}


