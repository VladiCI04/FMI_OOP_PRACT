#pragma once
#pragma warning(disable: 4996)

class MonsterCard {
private:
    char* name = nullptr;
    unsigned int attackPoints = 0;
    unsigned int defencePoints = 0;
    void free();
    void copyFrom(const MonsterCard& other);

public:
    MonsterCard();
    MonsterCard(const char* name, const unsigned int attackPoints, const unsigned int defencePoints);
    MonsterCard(const MonsterCard& other);
    MonsterCard& operator=(const MonsterCard& other);
    ~MonsterCard();

    char* getName() const;
    void setName(char* name);

    unsigned int getAttackPoints() const;
    void setAttackPoints(const unsigned int attackPoints);

    unsigned int getDefencePoints() const;
    void setDefencePoints(const unsigned int defencePoints);
};