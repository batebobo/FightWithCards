// Card.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Card.h"
#include "MyString.h"
using namespace std;

void Card::copy(const Card &other)
{
	this->name=other.name;
	this->manacost=other.manacost;
	this->number=other.number;
}

Card::Card() {
	manacost = 1;
	Mystring n;
	name=n;
	number=1;
}

Card::Card(Mystring name, int number, int manacost)
{
	this->name=name;
	this->number=number;
	this->manacost=manacost;
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
	if (this!=&other) copy(other);
	return *this;
}

int Card::getNumber() const
{
	return number;
}

void Card::print()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Number: "<<number<<endl;
	cout<<"Manacost: "<<manacost<<endl;
}

int main(int argc, _TCHAR* argv[])
{
	Card p;
	p.print();

	return 0;
}

