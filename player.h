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
    Player(Mystring,Deck,Hero);
    void turn();
    void print();
private:
    Hand hand;
    Deck deck;
    Hero hero;
    Card field[7];
    int fatigue;
    int mana;
    Mystring name;
};
#endif // PLAYER_H
