#pragma once

#include "Card.h"
#include "Hero.h"
#include "monster.h"

class SpellCard : public Card
{

public:
	enum Effects {dealDamageToCreature, damageHero, buffCreature, healYourself};


	SpellCard(Effects, char* = "", int = 0, int = 0,  int = 0);
	SpellCard(const SpellCard&);
	SpellCard& operator=(SpellCard const&);

	SpellCard::Effects getEffect() const { return effect; }
	int getEffectValue() const { return effectValue; }
	char* getReadonlyEffectInformation() const { return readOnlyEffect; }

	void setProperties(Effects, int);

	bool isMonster(){return false;}
	
	void dealDamageToMonster(Monster&);
	void dealDamageToHero(Hero&);
	void buffMonster(Monster&);
	void healHero(Hero&);
	void useSpellCard(Hero&);
	void useSpellCard(Monster&);
	void print();

	~SpellCard();
private:
	SpellCard::Effects effect;
	int effectValue;
	char* readOnlyEffect;
};

