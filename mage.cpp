#include <iostream>
#include "mage.h"

using namespace std;

Mage::Mage(char* _name , int hp , int powerMana , bool attacked) : Hero(_name , hp , powerMana , attacked)
{}

void Mage::print() const
{
	printHero();
	cout<<"Power : Deals 1 damage to selected hero or monster"<<endl;
}

void Mage::usePower(Hero* h, Monster* m, int choice)
{
	if(choice == 0)
		h->setHealth(h->getHealth() - 1);
	else
		m->setHealth(m->getHealth() - 1);
	setHasAttacked(true);
}