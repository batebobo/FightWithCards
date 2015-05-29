#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "hand.h"
#include "Hero.h"
#include "MyString.h"


class Player
{
public:
    Player(Mystring,Deck&,Hero& , int = 1);
	Player(Player const&);
	Player& operator=(Player const&);
    void print();
    void useCard(int);
	void removeCardFromField(int); 
	void printField();

	bool fieldIsEmpty() const{ return monstersInField == 0;}

	void increaseManaCrystals(); // increases mana_crystals with 1 and fills up mana to mana_crystals
	void changeMana(int);
	void drawCard();
	void setMonsterHasAttacked(bool);

	Hand& getHand(){return hand;}
	Deck& getDeck(){return deck;}
	Hero& getHero(){return hero;}
	Card** getField(){return field;}
	int getMonsterInField() const{return monstersInField;}
	int getMana() const{return mana;}
	Monster& getMonster(int);
	Mystring getName() const{return name;}
	Card* useSpellCard(int);

private:
    Hand hand;
    Deck deck;
    Hero hero;
    Card* field[7];
    int fatigue;
    int mana , mana_crystals;
    int monstersInField;
    Mystring name;
};
#endif // PLAYER_H
