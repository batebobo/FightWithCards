#include "stdafx.h"
#include <iostream>
#include "warrior.h"
using namespace std;

Warrior::Warrior(char* _name, int hp, int powerMana, bool attacked) : Hero(_name, hp, powerMana, attacked)
{}

void Warrior::print () const
{
	printHero();
	cout<<"Power: Increases his health by 2."<<endl;
}

void Warrior::usePower(Player* currentPlayer, Player* inactivePlayer)
{
	print();
    	currentPlayer->getHero()->setHealth(currentPlayer->getHero()->getHealth() +2);
	setHasAttacked(true);
	currentPlayer->changeMana(-2);
}
