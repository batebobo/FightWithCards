#include <iostream>
#include "priest.h"

using namespace std;

Priest::Priest(char* _name , int hp , int powerMana , bool attacked) : Hero(_name , hp , powerMana , attacked)
{}

void Priest::print() const
{
	printHero();
	cout<<"Power : heals 2 health to selected hero or monster"<<endl;
}

void Priest::usePower(Hero* h, Monster* m , int choice)
{
	if(choice == 0)
		h->setHealth(h->getHealth() + 2);
	else
		m->setHealth(m->getHealth() + 2);
	setHasAttacked(true);
}