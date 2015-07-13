#include <iostream>
#include "damage_hero_spell.h"

using namespace std;

DamageHeroSpell::DamageHeroSpell(char* _name, int _number, int _manacost,  int _damage) : SpellCard(DEAL_DAMAGE , _name , _number , _manacost , _damage)
{}

void DamageHeroSpell::print()
{
	printSpell();
	cout<<"Effect : Deals damage to selected hero"<<endl;
	cout<<endl;
}

void DamageHeroSpell::useCard(Player* currentPlayer, Player* inactivePlayer)
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
	inactivePlayer->getHero()->setHealth(inactivePlayer->getHero()->getHealth() - effectValue);
	cout<<"Hero "<<inactivePlayer->getHero()->getName()<<" received "<<effectValue<<" damage!\n"<<endl;
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