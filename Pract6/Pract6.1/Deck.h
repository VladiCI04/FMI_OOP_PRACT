#pragma once

#include "GlobalConstants.h"
#include "MonsterCard.h"
#include "MagicCard.h"

class Deck {
private: 
	MagicCard magicCards[GlobalConstants::MAX_CARDS_SIZE];
	MonsterCard monsterCards[GlobalConstants::MAX_CARDS_SIZE];

public:
	magicCardsCount();
	monsterCardsCount();
	addMagicCard(const MagicCard& magicCard);
	addMonsterCard(const MonsterCard& monsterCard);
	modifyMagicCard(const unsigned short index, const MagicCard& magicCard);
	modifyMonsterCard(const unsigned short index, const MonsterCard& monsterCard);
	removeMagicCard(const unsigned short index);
	removeMonsterCard(const unsigned short index);
};