#ifndef FLYWEIGHT_FACTORY_CLASS
#define FLYWEIGHT_FACTORY_CLASS

#define CONSONANT_KEY 1
#define VOWEL_KEY 0
#define LETTER_TYPES_QTY 2

#include "Strategy.h"
#include <map>
#include <vector>

using namespace std;

// Flyweight factory
class FlyweightFactory {

public:
	FlyweightFactory();
	~FlyweightFactory();
	Strategy* getObject();
	FlyweightFactory* setLetter(char letter);
	char getLetter();

private:
	char _letter;
	vector< vector<char>> _letterTypes;
	std::map <const char, Strategy*> _strategies;
	char _getLetterType();
};

#endif