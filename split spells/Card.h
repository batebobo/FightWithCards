#ifndef CARD_H_
#define CARD_H_

#include "MyString.h"

class Monster;
class Hero;
class Player;

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
	Mystring getName() const{ return name;}

	void setNumber(int); // changes card number

	virtual void print(){}
	void printCard();

	virtual void attack(Monster*){}
	virtual void attack(Hero*){}
	virtual bool isMonster(){return 0;}
	virtual int getHealth() const{ return 10;}
	virtual void setHasAttacked(bool){}
	virtual bool hasAttacked() const{return 1;} 
	virtual void useCard(Player* , Player*){};
};

#endif CARD_H_
