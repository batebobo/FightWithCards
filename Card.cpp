// Card.cpp : Defines the entry point for the console application.
//

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

Card::Card(Mystring _name, int _number, int _manacost)
{
	name = _name;
	number = _number;
	manacost = _manacost;
}

Card::Card(char* _name, int _number, int _manacost)
{
	Mystring newname(_name);
	name = newname;
	number = _number;
	manacost = _manacost;
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

void Card::setNumber(int newNumber)
{
	number = newNumber;
}