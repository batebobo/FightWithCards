#include <iostream>
#include <cstring>
#include "monster.h"

using namespace std;

Monster::Monster (char* _nameMonster, int _number, int _manaCost,
	int _attack, int _health , bool _hasAttacked):Card(_nameMonster,_number,_manaCost)
{
	power = _attack;
	health = _health;
	has_attacked = _hasAttacked;
}

void Monster::print ()
{
	Card::printCard();
	cout<<"Attack: "<<getAttack() <<endl;
	cout<<"Health: "<<getHealth() <<endl;
	cout<<endl;
}

void Monster::attack(Monster* m)
{
	m->setHealth(m->getHealth() - getAttack());
	setHealth(getHealth() - m->getAttack());
	cout<<m->getName()<<" received "<<power<<" damage!"<<endl;
	cout<<getName()<<" received "<<m->getAttack()<<" damage!"<<endl;
	setHasAttacked(true);
}

void Monster::attack(Hero* h)
{
	h->setHealth(h->getHealth() - getAttack());
	cout<<h->getName()<<" received "<<power<<" damage!"<<endl;
	setHasAttacked(true);
}

void Monster::setHasAttacked(bool attacked)
{
	has_attacked = attacked;
}

void Monster::useCard(Player* currentPlayer , Player* inactivePlayer)
{
	if(getManacost() <= currentPlayer->getMana())
	{
		int monsters = currentPlayer->getMonsterInField();
		currentPlayer->getField()[monsters] = (Monster*)currentPlayer->getHand().useCard(getNumber());
		currentPlayer->getField()[monsters]->setNumber(monsters);
		currentPlayer->getField()[monsters]->setHasAttacked(true);
		cout<<currentPlayer->getName()<<" set "<<currentPlayer->getField()[monsters]->getName()<<" on his field!\n";
		currentPlayer->changeMana(-getManacost());
		currentPlayer->getHand().useCard(getNumber());
		currentPlayer->increaseMonstersInField(1);
	}
	else
		cout<<"Not enough mana to summon that monster!"<<endl;
}