#pragma once

#include "Card.h"
#include "Hero.h"
#include "monster.h"

class SpellCard : public Card
{

public:
	enum effects {dealDamageToCreature, damageHero, buffCreature, healYourself};


	SpellCard(effects, char* = "", int = 0, int = 0,  int = 0);
	SpellCard(const SpellCard&);
	SpellCard& operator=(SpellCard const&);

	SpellCard::effects getEffect() const { return effect; }
	int getEffectValue() const { return effectValue; }
	char* getReadonlyEffectInformation() const { return readOnlyEffect; }

	void setProperties(effects, int);
	
	void freezeMonster(Monster&);
	void dealDamageToMonster(Monster&);
	void dealDamageToHero(Hero&);

	void healHero(Hero&);

	void print();

	~SpellCard();
private:
	SpellCard::effects effect;
	int effectValue;
	char* readOnlyEffect;
};

