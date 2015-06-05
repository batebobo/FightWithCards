#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "hand.h"
#include "Hero.h"
#include "MyString.h"
#include "monster.h"


class Player
{
public:
    Player(Mystring,Deck&,Hero* , int = 1);
	Player(Player const&);
	Player& operator=(Player const&);
    void print();
    Card* playCard(int);
	void removeCardFromField(int); 
	void printField();

	bool fieldIsEmpty() const{ return monstersInField == 0;}

	void increaseManaCrystals(); // increases mana_crystals with 1 and fills up mana to mana_crystals
	void changeMana(int);
	void drawCard();
	void setMonsterHasAttacked(bool);
	void increaseMonstersInField(int value) {monstersInField += value;}

	Hand& getHand(){return hand;}
	Deck& getDeck(){return deck;}
	Hero* getHero(){return hero;}
	Monster** getField(){return field;}

	int getMonsterInField() const{return monstersInField;}
	int getMana() const{return mana;}
	Mystring getName() const{return name;}

private:
    Hand hand;
    Deck deck;
    Hero* hero;
    Monster* field[7];
    int fatigue;
    int mana , mana_crystals;
    int monstersInField;
    Mystring name;
};
#endif // PLAYER_H
