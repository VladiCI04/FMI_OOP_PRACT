#pragma once

#include <iostream>
#include "GlobalConstants.h"

enum Type {
    trap,
    buff,
    spell
};

class MagicCard {
private:
    char name[GlobalConstants::MAGICCARD_MAX_SIZE + 1];
    char efect[GlobalConstants::EFFECT_MAX_SIZE + 1];
    Type type;

public:
    MagicCard();
    MagicCard(const char* name, const char* efect, const Type type);

    const char* const getName() const;
    void setName(const char* name);

    const char* const getEfect() const;
    void setEfect(const char* efect);

    const Type const getType() const;
    void setType(const Type type);
};