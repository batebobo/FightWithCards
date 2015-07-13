#include <iostream>
#include "heal_monster_spell.h"

using namespace std;

HealMonster::HealMonster(char* _name, int _number, int _manacost,  int _damage) : SpellCard(INCREASE_HP , _name , _number , _manacost , _damage)
{}

void HealMonster::useCard(Player* currentPlayer, Player* inactivePlayer)
{
	cout<<"Use spell card on enemy or own monster? ";
	string choice;
	cin>>choice;
	bool swapped = false;
	if(choice == "own")
	{
		Player* temp = currentPlayer;
		currentPlayer = inactivePlayer;
		inactivePlayer = temp;
		swapped = true;
	}
	if(!(inactivePlayer->fieldIsEmpty()))
		{
			int monsterIndex;
			inactivePlayer->printField();
			cout<<endl;
			cout<<"Enter the number of the monster you want to use your spell card on : ";
			cin>>monsterIndex;
			inactivePlayer->getField()[monsterIndex]->setHealth(inactivePlayer->getField()[monsterIndex]->getHealth() + effectValue);

			cout<<inactivePlayer->getName()<<"'s "<<inactivePlayer->getField()[monsterIndex]->getName()<<" got "<<getEffectValue()<<" health healed!"<<endl;

			if(!swapped)
			{
				currentPlayer->changeMana(-getManacost());
				currentPlayer->getHand().useCard(getNumber());
			}
			else
			{
				inactivePlayer->changeMana(-getManacost());
				inactivePlayer->getHand().useCard(getNumber());
			}
		}
		else if(inactivePlayer->fieldIsEmpty())
			cout<<"Player "<<inactivePlayer->getName()<<" has no monsters on his field!"<<endl;
}

void HealMonster::print()
{
	printSpell();
	cout<<"Effect : Heals selected monster"<<endl;
	cout<<endl;
}