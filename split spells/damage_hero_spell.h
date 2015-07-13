#ifndef DAMAGE_HERO_SPELL
#define DAMAGE_HERO_SPELL

#include "SpellCard.h"

class DamageHeroSpell : public SpellCard
{
public:
	DamageHeroSpell(char* = "", int = 0, int = 0,  int = 0);
	void print();
	void useCard(Player* , Player*);
};

#endif