#ifndef DAMAGE_MONSTER_SPELL_H
#define DAMAGE_MONSTER_SPELL_H

#include "SpellCard.h"

class DamageMonster : public SpellCard
{
public:
	DamageMonster(char* = "", int = 0, int = 0,  int = 0);
	void useCard(Player* , Player*);
	void print();
};

#endif