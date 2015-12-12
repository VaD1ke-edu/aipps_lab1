#include "VowelStrategy.h"
#include <iostream>

void VowelStrategy::execute(char letter) {
	attron(COLOR_PAIR(1));
	printw("This %c letter is vowel\n", letter);
	attroff(COLOR_PAIR(1));
}