#include <iostream>
#include <cstring>
#include "monster.h"

using namespace std;

Monster::Monster (char* _nameMonster, int _number, int _manaCost, int _attack, int _health , bool _hasAttacked):
					Card(_nameMonster,_number,_manaCost)
{
	power = _attack;
	health = _health;
	hasAttacked = _hasAttacked;
}

void Monster::print ()
{
	Card::printCard();
	cout<<"Attack: "<<getAttack() <<endl;
	cout<<"Health: "<<getHealth() <<endl;
}

void Monster::attack(Monster& m)
{
	m.setHealth(m.getHealth() - getAttack());
	setHealth(getHealth() - m.getAttack());
}

void Monster::attack(Hero& h)
{
	h.setHealth(h.getHealth() - getAttack());
}