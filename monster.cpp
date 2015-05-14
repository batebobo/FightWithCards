#include <iostream>
#include <cstring>
#include "monster.h"

using namespace std;

Monster::Monster (char* _nameMonster, int _number, int _manaCost, int _attack, int _health):Card(_nameMonster,_number,_manaCost)
{
	attack = _attack;
	health = _health;
}

void Monster::print ()
{
	Card::print();
	cout<<"Attack: "<<getAttack() <<endl;
	cout<<"Health: "<<getHealth() <<endl;
}


