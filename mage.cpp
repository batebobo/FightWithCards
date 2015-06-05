#include <iostream>
#include "mage.h"

using namespace std;

Mage::Mage(char* _name , int hp , int powerMana , bool attacked) : Hero(_name , hp , powerMana , attacked)
{}

void Mage::print() const
{
	printHero();
	cout<<"Power : Deals 1 damage to selected hero or monster"<<endl;
}

void Mage::usePower(Player* p)
{
	print();
	cout<<endl;
	cout<<"Use hero power on hero or monster? ";
	enum Choice {MONSTER , HERO};
	map<string,Choice> m;
	m["monster"] = MONSTER;
	m["hero"] = HERO;
	string input;
	cin>>input;
	Choice choice = m[input];
	if(choice == HERO)
	{
		p->getHero()->setHealth(p->getHero()->getHealth() - 1);
		setHasAttacked(true);
	}
	else if(choice == MONSTER)
	{
		p->printField();
		cout<<"Enter the index of the monster you want to use the hero power on : ";
		int monsterIndex;
		cin>>monsterIndex;
		p->getField()[monsterIndex]->setHealth(p->getField()[monsterIndex]->getHealth() - 1);
		setHasAttacked(true);
	}
	else
		cout<<"Incorrect command input!"<<endl;
}