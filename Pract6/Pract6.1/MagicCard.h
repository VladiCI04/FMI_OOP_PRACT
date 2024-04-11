#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include "GlobalConstants.h"

enum Type {
    trap,
    buff,
    spell
};

class MagicCard {
private:
    char name[GlobalConstants::MAGICCARD_MAX_SIZE + 1] = "Default";
    char efect[GlobalConstants::EFFECT_MAX_SIZE + 1] = "Default";
    Type type = (Type)0;

public:
    MagicCard();
    MagicCard(const char* name, const char* efect, const Type type);

    const char* getName() const;
    void setName(const char* name);

    const char* getEfect() const;
    void setEfect(const char* efect);

    const Type getType() const;
    void setType(const Type type);
};