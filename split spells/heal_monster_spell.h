#ifndef HEAL_MONSTER_SPELL_H
#define HEAL_MONSTER_SPELL_H

#include "SpellCard.h"

class HealMonster : public SpellCard
{
public:
	HealMonster(char* = "", int = 0, int = 0,  int = 0);
	void useCard(Player* , Player*);
	void print();
};

#endif