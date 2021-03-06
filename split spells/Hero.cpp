// Hero.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Hero.h"

using namespace std;

Hero::Hero(char* _name , int _health , int manacost , bool attacked) : health(_health) , name(NULL) , skill_manacost(manacost) , has_attacked(attacked)
{
	setName(_name);
}

Hero::Hero(const Hero& other) : health(other.health) , name(NULL) , skill_manacost(other.skill_manacost) , has_attacked(other.has_attacked)
{
	setName(other.name);
}

Hero& Hero::operator=(const Hero& other)
{
	if(this != &other)
	{
		skill_manacost = other.getSkillManacost();
		has_attacked = other.hasAttacked();
		health = other.getHealth();
		setName(other.getName());
	}
	return *this;
}

Hero::~Hero()
{
	if(name != NULL)
		delete[] name;
}


void Hero::printHero() const
{
	cout<<"Health : "<<getHealth()<<endl;
	cout<<"Name : "<<getName()<<endl;
	cout<<"Skill manacost : "<<getSkillManacost()<<endl;
}

void Hero::setName(char* _name)
{
	if(name != NULL)
		delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name , _name);
}

void Hero::setHealth(int hp)
{
	health = hp;
}

void Hero::setHasAttacked(bool attacked)
{
	has_attacked = attacked;
}