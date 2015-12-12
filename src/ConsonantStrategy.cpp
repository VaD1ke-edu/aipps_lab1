#include "ConsonantStrategy.h"
#include <iostream>

void ConsonantStrategy::execute(char letter) {
	attron(COLOR_PAIR(2));
	printw("This %c letter is consonant\n", letter);
	attroff(COLOR_PAIR(2));
}