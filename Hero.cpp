// Hero.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Hero.h"

using namespace std;

Hero::Hero(char* _name , int _health ) : health(_health) , name(NULL)
{
	setName(_name);
}

Hero::Hero(const Hero& other) : health(other.health) , name(NULL)
{
	setName(other.name);
}

Hero& Hero::operator=(const Hero& other)
{
	if(this != &other)
	{
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


void Hero::print() const
{
	cout<<"Health : "<<health <<endl;
	cout<<"Name : "<<name <<endl;
}

void Hero::setName(char* _name)
{
	if(name != NULL)
		delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name , _name);
}

void Hero::usePower(Hero& other)
{
	if(strcmp(name , "Priest") == 0 || strcmp(name , "priest") == 0)
		heal();
	else if(strcmp(name , "Hunter") == 0 || strcmp(name , "hunter") == 0)
		attack(other);
}

void Hero::attack(Hero& other)
{
	other.setHealth(other.getHealth() - 2);
}

void Hero::heal()
{
	health += 2;
}

void Hero::setHealth(int hp)
{
	health = hp;
}
