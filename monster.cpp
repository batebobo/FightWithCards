#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "monster.h"

using namespace std;

Monster::Monster	 (char* _nameMonster, int _attack, int _health)
{
	nameMonster = _nameMonster;
	attack = _attack;
	health = _health;
}

Monster::Monster (Monster const& m)
{
	nameMonster = m.nameMonster;
	attack = m.attack;
	health = m.health;
}

void Monster::print () const 
{
	cout<<"Monster "<<getNameMonster() <<endl;
	cout<<"Attack: "<<getAttack() <<endl;
	cout<<"Health: "<<getHealth() <<endl;
}

void Monster::setNameMonster (const char* _nameMonster)
{
	nameMonster = new char;
	strcpy (nameMonster, _nameMonster);
}

Monster::~Monster ()
{
	delete [] nameMonster;
}

