#ifndef HEAL_HERO_SPELL
#define HEAL_HERO_SPELL

#include "SpellCard.h"

class HealHeroSpell : public SpellCard
{
public:
	HealHeroSpell(char* = "", int = 0, int = 0,  int = 0);

	void print();
	void useCard(Player* , Player*);
};

#endif