#ifndef CARD_H_
#define CARD_H_

#include "MyString.h"

class Monster;
class Hero;

class Card {
private:
	Mystring name;
	int manacost;
	int number;
	void copy( const Card&);
public:
	Card();
	Card(Mystring, int, int);
	Card(char*, int, int);
	Card(const Card&);
	Card operator=(const Card&);
	
	int getNumber() const;
	int getManacost() const{ return manacost;}

	virtual void print(){}
	void printCard();

	virtual void attack(Monster&){}
	virtual void attack(Hero&){}
	virtual void useSpellCard(Monster&){}
	virtual void useSpellCard(Hero&){}
	virtual bool isMonster(){return 0;}
};

#endif CARD_H_
