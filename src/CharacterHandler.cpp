#include "CharacterHandler.h"

CharacterHandler::CharacterHandler(FlyweightFactory* flyweightFactory) {
	this->_flyweightFactory = flyweightFactory;
}

CharacterHandler* CharacterHandler::execute() {
	this->changeStrategy();
	this->_strategy->execute(this->getLetter());
	return this;
}

CharacterHandler* CharacterHandler::changeStrategy() {
	this->_strategy = this->_flyweightFactory->setLetter(this->getLetter())->getObject();
	return this;
}

CharacterHandler* CharacterHandler::setLetter(char letter) {
	this->_letter = letter;
	return this;
}

char CharacterHandler::getLetter() {
	return this->_letter;
}