#ifndef CHARACTER_HANDLER_CLASS
#define CHARACTER_HANDLER_CLASS

#include "Strategy.h"
#include "FlyweightFactory.h"

// Chatacter handler
class CharacterHandler {
public:
	CharacterHandler(FlyweightFactory*);
	CharacterHandler* execute();
	CharacterHandler* setLetter(char letter);
	char getLetter();
private:
	FlyweightFactory* _flyweightFactory;
	Strategy* _strategy;
	char _letter;
	CharacterHandler* changeStrategy();
};

#endif