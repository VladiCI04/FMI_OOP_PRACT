#pragma once

#include "GlobalConstants.h"
#include "MonsterCard.h"
#include "MagicCard.h"

class Deck {
private: 
	MagicCard magicCards[GlobalConstants::MAX_CARDS_SIZE];
	MonsterCard monsterCards[GlobalConstants::MAX_CARDS_SIZE];
	unsigned short magicCardsIndex = 0;
	unsigned short monsterCardsIndex = 0;

public:
	Deck();
	Deck(const MagicCard* magicCards, const MonsterCard* monsterCards);

	unsigned short magicCardsCount() const;
	unsigned short monsterCardsCount() const;
	void addMagicCard(const MagicCard& magicCard);
	void addMonsterCard(const MonsterCard& monsterCard);
	void modifyMagicCard(const unsigned short index, const MagicCard& magicCard);
	void modifyMonsterCard(const unsigned short index, const MonsterCard& monsterCard);
	void removeMagicCard(const unsigned short index);
	void removeMonsterCard(const unsigned short index);
};