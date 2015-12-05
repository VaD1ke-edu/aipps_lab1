#ifndef VOWEL_STRATEGY_CLASS
#define VOWEL_STRATEGY_CLASS

#include "Strategy.h"

// Strategy for vowel letter
class VowelStrategy : public Strategy {
public:
	void execute(char letter);
};

#endif