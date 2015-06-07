// hunter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "hunter.h"

using namespace std;

Hunter::Hunter(char* _name, int hp, int powerMana, bool attacked) : Hero(_name, hp, powerMana, attacked)
{}

void Hunter::print() const
{
	printHero();
	cout<<"Power: Deals 2 damage to the enemy hero."<<endl;
}

void Hunter::usePower(Hero* h, Monster* m, int choice)
{
	h.setHealth(getHealth()-2);
	setHasAttacked(true);
}

