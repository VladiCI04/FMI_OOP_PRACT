#include <iostream>

#include "Deck.h"
#include "Duelist.h"
#include "MagicCard.h"
#include "MonsterCard.h"

int main()
{
    //40 cards = 20 MonsterCards/20 MagicCards
    Deck d;

    // 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
    //ATK: 3000 DEF: 2500
    MonsterCard monsterCard("Blue-eyes white dragon", 3000, 2500);
    d.addMonsterCard(monsterCard);

    // 5-th card in the Magic deck is added/changed to "Monster reborn"
    MagicCard magicCard("Monster reborn", "revive", spell);
    d.addMagicCard(magicCard);

    //Returns the amount of MagicCards in the deck
    std::cout << d.magicCardsCount() << std::endl; //1

    //Returns the amount of MonsterCards in the deck
    std::cout << d.monsterCardsCount() << std::endl; //13

    Duelist player1("Seto Kaiba");

    ///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
    MonsterCard DarkMagician("Dark Magician", 2500, 2100);
    player1.modifyCardDromDeck(2, DarkMagician);

    Duelist player2("Yugi Muto");

    //Changes the 2-nd magic card in the Magic deck to “Reflection”
    MagicCard Reflection("Reflection", "Reflects the last played spell", trap);
    player2.modifyCardFromDeck(2, Reflection);
}