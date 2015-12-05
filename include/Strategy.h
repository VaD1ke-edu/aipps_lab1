#ifndef STRATEGY_CLASS
#define STRATEGY_CLASS

#include <ncurses.h>

// Abstraction
class Strategy {
public:
	virtual void execute(char) = 0;
	virtual ~Strategy() {}
};

#endif