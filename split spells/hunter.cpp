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

void Hunter::usePower(Player* currentPlayer, Player* inactivePlayer)
{
	print();
	inactivePlayer->getHero()->setHealth(inactivePlayer->getHero()->getHealth() - 1);
	setHasAttacked(true);
	currentPlayer->changeMana(-2);
}

