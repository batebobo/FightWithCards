// Card.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Card.h"
using namespace std;

void Card::copy(const Card &other)
{
	name=other.name;
	manacost=other.manacost;
	number=other.number;
}

Card::Card() {
	manacost = 1;
	Mystring n;
	name=n;
	number=1;
}

Card::Card(Mystring name, int number, int manacost)
{
	name=name;
	number=number;
	manacost=manacost;
}

Card::Card(char* name, int number, int manacost)
{
	Mystring newname(name);
	this->name=newname;
	this->number=number;
	this->manacost=manacost;
}

Card::Card(const Card &other) {
	copy(other);
}

Card Card::operator=(const Card &other)
{
	if (this!=&other) 
		copy(other);
	return *this;
}

int Card::getNumber() const
{
	return number;
}

void Card::printCard()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Number: "<<number<<endl;
	cout<<"Manacost: "<<manacost<<endl;
}

