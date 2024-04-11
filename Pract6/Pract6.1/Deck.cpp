#include "Deck.h"

Deck::Deck() = default;

Deck::Deck(const MagicCard* magicCards, const MonsterCard* monsterCards) {
	while (magicCards) {
		this->addMagicCard(*magicCards);
		magicCards++;
	}

	while (monsterCards) {
		this->addMonsterCard(*monsterCards);
		monsterCards++;
	}
}

unsigned short Deck::magicCardsCount() const {
	return this->magicCardsIndex;
}

unsigned short Deck::monsterCardsCount() const {
	return this->monsterCardsIndex;
}

void Deck::addMagicCard(const MagicCard& magicCard) {
	this->magicCards[this->magicCardsIndex] = magicCard;
	this->magicCardsIndex++;
}

void Deck::addMonsterCard(const MonsterCard& monsterCard) {
	this->monsterCards[this->magicCardsIndex] = monsterCard;
	this->monsterCardsIndex++;
}

void Deck::modifyMagicCard(const unsigned short index, const MagicCard& magicCard) {
	this->magicCards[index] = magicCard;
}

void Deck::modifyMonsterCard(const unsigned short index, const MonsterCard& monsterCard) {
	this->monsterCards[index] = monsterCard;
}

void Deck::removeMagicCard(const unsigned short index) {
	if (index >= this->magicCardsIndex) {
		return;
	}

	for (unsigned short i = index; i < this->magicCardsIndex - 1; i++) {
		this->magicCards[i] = this->magicCards[i + 1];
	}
}

void Deck::removeMonsterCard(const unsigned short index) {
	if (index >= this->monsterCardsIndex) {
		return;
	}

	for (unsigned short i = index; i < this->monsterCardsIndex - 1; i++) {
		this->monsterCards[i] = this->monsterCards[i + 1];
	}
}