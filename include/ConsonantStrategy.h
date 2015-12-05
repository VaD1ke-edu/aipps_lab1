#ifndef CONSONANT_STRATEGY_CLASS
#define CONSONANT_STRATEGY_CLASS

#include "Strategy.h"

// Strategy for consonant letter
class ConsonantStrategy : public Strategy {
public:
	void execute(char letter);
};

#endif