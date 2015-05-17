#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "hand.h"
#include "Card.h"
#include "Hero.h"
#include "MyString.h"


class Player
{
public:
    Player(Mystring,Deck&,Hero);
    void print();
    void useCard(int);
private:
    Hand hand;
    Deck deck;
    Hero hero;
    Monster field[7];
    int fatigue;
    int mana;
    int monstersInField;
    Mystring name;
};
#endif // PLAYER_H
