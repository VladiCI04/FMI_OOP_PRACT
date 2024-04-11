#pragma once
#pragma warning(disable: 4996)

#include "GlobalConstants.h"
#include "Deck.h"
#include "MonsterCard.h"
#include "MagicCard.h"

class Duelist {
private: 
	char* name;
	Deck* deck[GlobalConstants::MAX_CARDS_IN_DECK] = { 0 };
	unsigned short deckIndex = 0;
	void free();
	void copyFrom(const Duelist& other);

public:
	Duelist();
	Duelist(const char* name);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();

	unsigned short cardsCountInDeck() const;
	void addCardInDeck(const MagicCard& magicCard);
	void addCardInDeck(const MonsterCard& monsterCard);
	void modifyCardFromDeck(const unsigned short index, const MagicCard& magicCard);
	void modifyCardDromDeck(const unsigned short index, const MonsterCard& monsterCard);
	void removeCardFromDeck(const unsigned short index);
};
