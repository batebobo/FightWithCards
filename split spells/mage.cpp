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

void Mage::usePower(Player* currentPlayer , Player* inactivePlayer)
{
	print();
	cout<<"Use hero power on enemy target? y/n ";
	string answer;
	cin>>answer;
	bool switched = false;
	if(answer == "n")
	{
		Player* temp = currentPlayer;
		currentPlayer = inactivePlayer;
		inactivePlayer = temp;
		switched = true;
	}
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
		inactivePlayer->getHero()->setHealth(inactivePlayer->getHero()->getHealth() - 1);
		setHasAttacked(true);
		if(switched)
			inactivePlayer->changeMana(-2);
		else
			currentPlayer->changeMana(-2);
	}
	else if(choice == MONSTER)
	{
		if(!(inactivePlayer->fieldIsEmpty()))
		{
			inactivePlayer->printField();
			cout<<"Enter the index of the monster you want to use the hero power on : ";
			int monsterIndex;
			cin>>monsterIndex;
			inactivePlayer->getField()[monsterIndex]->setHealth(inactivePlayer->getField()[monsterIndex]->getHealth() - 1);
			setHasAttacked(true);
			if(switched)
				inactivePlayer->changeMana(-2);
			else
				currentPlayer->changeMana(-2);
		}
		else
			cout<<"No monsters on "<<inactivePlayer->getName()<<"'s field!"<<endl;
	}
	else
		cout<<"Incorrect command input!"<<endl;
}