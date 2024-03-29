#include "MagicCard.h"

MagicCard::MagicCard() { 
    this->setName("Default");
    this->setEfect("Default");
    this->setType((Type)0);
}
MagicCard::MagicCard(const char* name, const char* efect, const Type type) { 
    this->setName(name);
    this->setEfect(efect);
    this->setType(type);
}

const char* const MagicCard::getName() const {
    return this->name;
}
void MagicCard::setName(const char* name) {
    strcpy(this->name, name);
}

const char* const MagicCard::getEfect() const {
    return this->efect;
}
void MagicCard::setEfect(const char* efect) {
    strcpy(this->efect, efect);
}

const Type const MagicCard::getType() const {
    return this->type;
}
void MagicCard::setType(const Type type) {
    this->type = type;
}