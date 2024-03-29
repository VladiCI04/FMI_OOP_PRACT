#pragma once

class MonsterCard {
private:
    char* name = nullptr;
    unsigned int attackPoints = 0;
    unsigned int defencePoints = 0;

public:
    MonsterCard();
    MonsterCard(const char* name, const unsigned int attackPoints, const unsigned int defencePoints);

    const char* const getName() const;
    void setName(const char* name);

    const unsigned int const getAttackPoints() const;
    void setAttackPoints(const unsigned int attackPoints);

    const unsigned int const getDefencePoints() const;
    void setDefencePoints(const unsigned int defencePoints);
};