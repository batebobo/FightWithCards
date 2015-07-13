#include <iostream>
#include "heal_hero_spell.h"

using namespace std;

HealHeroSpell::HealHeroSpell(char* _name, int _number, int _manacost,  int _damage) : SpellCard(INCREASE_HP , _name , _number , _manacost , _damage)
{}

void HealHeroSpell::print()
{
	printSpell();
	cout<<"Effect : Heals selected hero"<<endl;
	cout<<endl;
}

void HealHeroSpell::useCard(Player* currentPlayer, Player* inactivePlayer)
{
	cout<<"Use spell card on enemy or own hero? ";
	string choice;
	cin>>choice;
	bool switched = false;
	if(choice == "own")
	{
		Player* temp = currentPlayer;
		currentPlayer = inactivePlayer;
		inactivePlayer = temp;
		switched = true;
	}
	inactivePlayer->getHero()->setHealth(inactivePlayer->getHero()->getHealth() + effectValue);
	cout<<"Hero "<<inactivePlayer->getHero()->getName()<<" got "<<effectValue<<" health restored!\n"<<endl;
	if(switched)
	{
		inactivePlayer->changeMana(-getManacost());
		inactivePlayer->getHand().useCard(getNumber());
	}
	else
	{
		currentPlayer->changeMana(-getManacost());
		currentPlayer->getHand().useCard(getNumber());
	}
}