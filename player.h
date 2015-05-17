#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "hand.h"
#include "Hero.h"
#include "MyString.h"


class Player
{
public:
    Player(Mystring,Deck&,Hero& , int = 5);
	Player(Player const&);
    void print();
    void useCard(int);
	void removeCardFromField(int); // премахва карта от полето (използва се от бикта , когато карта бъде унищожена)

	void setMana(int); // добавяне или премахване на мана
	void drawCard();

	Hand& getHand(){return hand;}
	Deck& getDeck(){return deck;}
	Hero& getHero(){return hero;}
	Card** getField(){return field;}
	int getMonsterInField() const{return monstersInField;}
	Mystring getName() const{return name;}

private:
    Hand hand;
    Deck deck;
    Hero hero;
    Card* field[7];
    int fatigue;
    int mana;
    int monstersInField;
    Mystring name;
};
#endif // PLAYER_H
