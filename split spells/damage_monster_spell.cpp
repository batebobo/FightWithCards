#include <iostream>
#include "damage_monster_spell.h"

using namespace std;

DamageMonster::DamageMonster(char* _name, int _number, int _manacost,  int _damage) : SpellCard(DEAL_DAMAGE , _name , _number , _manacost , _damage)
{}

void DamageMonster::useCard(Player* currentPlayer, Player* inactivePlayer)
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
			inactivePlayer->getField()[monsterIndex]->setHealth(inactivePlayer->getField()[monsterIndex]->getHealth() - effectValue);
			if(inactivePlayer->getField()[monsterIndex] != NULL)
			{
				cout<<inactivePlayer->getName()<<"'s "<<inactivePlayer->getField()[monsterIndex]->getName()<<" received "<<getEffectValue()<<" damage!"<<endl;
				if(inactivePlayer->getField()[monsterIndex]->getHealth() <= 0)
				{
					cout<<inactivePlayer->getField()[monsterIndex]->getName()<<" has died!"<<endl;
					inactivePlayer->removeCardFromField(monsterIndex);
				}

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
			else
				cout<<"Incorrect index input!\n";
		}
		else if(inactivePlayer->fieldIsEmpty())
			cout<<"Player "<<inactivePlayer->getName()<<" has no monsters on his field!"<<endl;
}

void DamageMonster::print()
{
	printSpell();
	cout<<"Effect : Deals damage to selected monster"<<endl;
	cout<<endl;
}