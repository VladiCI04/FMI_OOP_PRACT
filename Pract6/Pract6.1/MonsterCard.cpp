#include <iostream>

#include "MonsterCard.h"

void MonsterCard::free() {
	delete[] this->name;
	this->attackPoints = 0;
	this->defencePoints = 0;
}
void MonsterCard::copyFrom(const MonsterCard& other) {
	this->name = other.name;
	this->attackPoints = other.attackPoints;
	this->defencePoints = other.defencePoints;
}

MonsterCard::MonsterCard() = default;
MonsterCard::MonsterCard(const char* name, const unsigned int attackPoints, const unsigned int defencePoints) {
	this->setName((char*) name);
	this->setAttackPoints(attackPoints);
	this->setDefencePoints(defencePoints);
}
MonsterCard::MonsterCard(const MonsterCard& other) { 
	copyFrom(other);
}
MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
MonsterCard::~MonsterCard() {
	free();
}

char* MonsterCard::getName() const {
	return this->name;
}
void MonsterCard::setName(char* name) {
	this->name = name;
}

unsigned int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}
void MonsterCard::setAttackPoints(const unsigned int attackPoints) {
	this->attackPoints = attackPoints;
}

unsigned int MonsterCard::getDefencePoints() const {
	return this->defencePoints;
}
void MonsterCard::setDefencePoints(const unsigned int defencePoints) {
	this->defencePoints = defencePoints;
}