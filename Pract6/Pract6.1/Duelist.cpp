#include "Duelist.h"
#include <iostream>

void Duelist::free() {
	delete[] this->name;
	for (unsigned int index = 0; index < deckIndex; index++) {
		delete[] this->deck[index];
	}
	delete[] this->deck;
	this->deckIndex = 0;
}
void Duelist::copyFrom(const Duelist& other) {
	strcpy(this->name, other.name); 
	unsigned int index = 0;
	while (other.deck[index]) {
		this->deck[index] = other.deck[index];
		index++;
	}
	this->deckIndex = other.deckIndex;
}
Duelist::Duelist() = default;
Duelist::Duelist(const char* name) {
	if (name) {
		strcpy(this->name, name);
	}
}
Duelist::Duelist(const Duelist& other) {
	copyFrom(other);
}
Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
Duelist::~Duelist() {
	free();
}

unsigned short Duelist::cardsCountInDeck() const {
	return this->deckIndex;
}

void Duelist::addCardInDeck(const MagicCard& magicCard) {
	this->deck[this->deckIndex]->addMagicCard(magicCard);
	this->deckIndex++;
}

void Duelist::addCardInDeck(const MonsterCard& monsterCard) {
	this->deck[this->deckIndex]->addMonsterCard(monsterCard);
	this->deckIndex++;
}

void Duelist::modifyCardFromDeck(const unsigned short index, const MagicCard& magicCard) {
	if (index >= this->deckIndex) {
		return;
	}

	this->deck[index]->addMagicCard(magicCard);
}

void Duelist::modifyCardDromDeck(const unsigned short index, const MonsterCard& monsterCard) {
	if (index >= this->deckIndex) {
		return;
	}

	this->deck[index]->addMonsterCard(monsterCard);
}

void Duelist::removeCardFromDeck(const unsigned short index) {
	if (index >= this->deckIndex) {
		return;
	}

	for (unsigned short i = index; i < this->deckIndex - 1; i++) {
		this->deck[i] = this->deck[i + 1];
	}

	this->deckIndex--;
}