#include "stdafx.h"
#include <iostream>
#include "warlock.h"

using namespace std;

Warlock::Warloc(char* _name, int hp, int powerMana, bool attacked) : Hero(_name, hp, powerMana, attacked)
{}

void Warlock::print() const
{
	printHero();
	cout<<"Power: Draw a card and lose 2 health."<<endl;
}

void Warlock::usePower(Hero* h, Monster* m, int choice)
{
	Hero::setHealth(getHealth()-2);
	Hero::getHand().drawCard(Hero::getDeck());
}