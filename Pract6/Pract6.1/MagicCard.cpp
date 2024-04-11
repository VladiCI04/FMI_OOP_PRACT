#include "MagicCard.h"
#include <iostream>

MagicCard::MagicCard() = default;
MagicCard::MagicCard(const char* name, const char* efect, const Type type) { 
    this->setName(name);
    this->setEfect(efect);
    this->setType(type);
}

const char* MagicCard::getName() const {
    return this->name;
}
void MagicCard::setName(const char* name) {
    strcpy(this->name, name);
}

const char* MagicCard::getEfect() const {
    return this->efect;
}
void MagicCard::setEfect(const char* efect) {
    strcpy(this->efect, efect);
}

const Type MagicCard::getType() const {
    return this->type;
}
void MagicCard::setType(const Type type) {
    if (type < 0 || type > 2) {
        return;
    }

    this->type = type;
}