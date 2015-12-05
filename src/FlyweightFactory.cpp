#include "FlyweightFactory.h"
#include "ConsonantStrategy.h"
#include "VowelStrategy.h"
#include <array>
#include <string>

FlyweightFactory::FlyweightFactory() {
	this->_letterTypes.resize(2);
	this->_letterTypes[VOWEL_KEY] = std::vector<char> {
		'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'
	};


	this->_letterTypes[CONSONANT_KEY] = std::vector<char> {
		'b', 'B', 'c', 'C', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 
		'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'p', 'P', 'q', 'Q', 'r', 'R', 
		's', 'S', 't', 'T', 'v', 'V', 'w', 'W', 'x', 'X', 'z', 'Z'
	};
}

Strategy* FlyweightFactory::getObject() {
	char key = this->_getLetterType();;
	std::map<char, Strategy*>::iterator strategyIterator = this->_strategies.find(key);

	if (strategyIterator != this->_strategies.end()) {
		return strategyIterator->second;
	}
	Strategy* strategy = NULL;
	switch (key) {
		case CONSONANT_KEY:
			strategy = new ConsonantStrategy();
			break;
		case VOWEL_KEY:
			strategy = new VowelStrategy();
			break;
		default:
			throw "Not an english letter";
	}
	this->_strategies.insert(std::pair<char, Strategy*>(key, strategy));
	return strategy;
}

FlyweightFactory* FlyweightFactory::setLetter(char letter) {
	this->_letter = letter;
	return this;
}

char FlyweightFactory::getLetter() {
	return this->_letter;
}


char FlyweightFactory::_getLetterType() {
	char letter = this->getLetter();
	if (!letter) return -1;

	for (int letterType = 0; letterType < LETTER_TYPES_QTY; letterType++) {
		for (vector<char>::iterator it = this->_letterTypes[letterType].begin(); it != this->_letterTypes[letterType].end(); ++it) {
			if (letter == *it) return letterType;
		}
	}

	return -1;
}
