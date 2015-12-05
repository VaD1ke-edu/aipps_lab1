#include "CharacterHandler.h"
#include "FlyweightFactory.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>

int main()
{
	initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
	attron(COLOR_PAIR(1)); 

	char inputChar;
	try {
		 do {
			printf("\nInput a letter\n");
			inputChar = getchar();
			CharacterHandler* handler = new CharacterHandler(new FlyweightFactory());
			handler->setLetter(inputChar)->execute();
			refresh();
		 } while (isalpha(inputChar));
	} catch (char const* e) {
    	init_pair(2, COLOR_BLACK, COLOR_RED);
		attron(COLOR_PAIR(2)); 
		printf(e);
	}

	getchar();
    endwin();

	return 0;
}
