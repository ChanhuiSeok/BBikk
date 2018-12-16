#include <stdio.h>
#include <termio.h>
#include <string.h>
#include <stdlib.h>

main(){
	long long int bar;
	char bar2[20];
	char txt[5] = ".txt";

	bar = getch();
	printf("%ld", bar);
	sprintf(bar2, "%ld", bar);

	strcat(bar2, txt);
	printf("%s", bar2);
}

long int getch(void){
	long int ch;

	struct termios buf;
	struct termios save;

	tcgetatt(0, &save);
	buf = save;

	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[V

