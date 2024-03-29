#include <iostream>

#include "MonsterCard.h"

MonsterCard::MonsterCard() { }
MonsterCard::MonsterCard(const char* name, const unsigned int attackPoints, const unsigned int defencePoints) {
	setName(name);
	setAttackPoints(attackPoints);
	setDefencePoints(defencePoints);
}
MonsterCard::MonsterCard(const MonsterCard& other) { 
	copyFrom(other);
}

const char* const MonsterCard::getName() const {
	return this->name;
}
void MonsterCard::setName(const char* name) {
	strcpy(this->name, name);
}

const unsigned int const MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}
void MonsterCard::setAttackPoints(const unsigned int attackPoints) {
	this->attackPoints = attackPoints;
}

const unsigned int const MonsterCard::getDefencePoints() const {
	return this->defencePoints;
}
void MonsterCard::setDefencePoints(const unsigned int defencePoints) {
	this->defencePoints = defencePoints;
}