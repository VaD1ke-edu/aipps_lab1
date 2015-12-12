#include "CharacterHandler.h"
#include "FlyweightFactory.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>

int main()
{
	initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_BLUE);

	char inputChar;
	CharacterHandler* handler = new CharacterHandler(new FlyweightFactory());

	try {
		 do {
			printf("\nInput a letter\n");
			inputChar = getchar();
			//fflush(stdin);
			handler->setLetter(inputChar)->execute();
			refresh();
		 } while (isalpha(inputChar));
	} catch (char const* e) {
    	init_pair(3, COLOR_BLACK, COLOR_RED);
		attron(COLOR_PAIR(3)); 
		printf(e, "%s");
	}

	getchar();
    endwin();

	return 0;
}
