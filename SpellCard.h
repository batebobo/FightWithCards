#pragma once

#include "Card.h"
#include "Hero.h"
#include "monster.h"

class SpellCard : public Card
{
	//разбиване на класове
public:
	enum Effects {DEAL_DAMAGE , INCREASE_HP};


	SpellCard(Effects, char* = "", int = 0, int = 0,  int = 0);
	SpellCard(const SpellCard&);
	SpellCard& operator=(SpellCard const&);

	SpellCard::Effects getEffect() const { return effect; }
	int getEffectValue() const { return effectValue; }
	char* getReadonlyEffectInformation() const { return readOnlyEffect; }

	void setProperties(Effects, int);

	bool isMonster(){return false;}
	
	void useSpellCard(Player* , Player*);

	void print();

	~SpellCard();
private:
	SpellCard::Effects effect;
	int effectValue;
	char* readOnlyEffect;
};

