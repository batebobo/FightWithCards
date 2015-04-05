// Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Hero.h"

using namespace std;

Hero::Hero() 
{
	this->health=40;
	this->name="";
	this->power="";
}

Hero::Hero(int health, string name, string power)
{
	if (health==0) health=40;
	else this->health=health;
	this->name=name;
	this->power=power;
}

Hero::Hero(const Hero& other)
{
	this->health=other.health;
	this->name=other.name;
	this->power=other.power;
}

Hero& Hero::operator=(const Hero& other)
{
	if(this != &other)
	{
		this->health=other.health;
		this->name=other.name;
		this->power=other.power;
	}
	return *this;
}

Hero::~Hero()
{
}

int Hero::getHealth() const { return health;}
string Hero::getName() const {return name;}
string Hero::getPower() const { return power;}


void Hero::print() const
{
	cout<<"Health: "<<health <<endl;
	cout<<"Name: "<<name <<endl;
	cout<<"Power: "<<power <<endl;
}

void Hero::set()
{
	cin>>health>>name>>power;
	this->health=health;
	this->name=name;
	this->power=power;
}

int main(int argc, _TCHAR* argv[])
{
	Hero Mage(40, "Mage", "Fireblast");
	Mage.print();
	Hero Hunter(40, "Hunter", "Steady Shot");
	Hunter.print();
	Hero Warrior(40, "Warrior", "Shield Up");
	Warrior=Hunter;
	Warrior.print();
	Hunter.set();
	Hunter.print();
	Warrior.print();
	return 0;
}


