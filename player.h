#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "hand.h"
#include "Hero.h"
#include "MyString.h"


class Player
{
public:
    Player(Mystring,Deck,Hero);
    void turn();
private:
    Hand hand;
    Deck deck;
    Hero hero;
    int fatigue;
    Mystring name;
};
#endif // PLAYER_H
