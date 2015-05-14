#pragma once

class Monster;
class Player;
#include "Card.h"
class SpellCard : public Card
{
private:
	int effect;
	int damage;
	char* readOnlyEffect;

public:
	SpellCard(char* = "", int = 0, int = 0, int = 0, int = 0);
	SpellCard(const SpellCard&);

	int getEffectNumber() const { return effect; }
	int getDamageInformation() const { return damage; }
	char* getReadonlyEffectInformation() const { return readOnlyEffect; }

	void setProperties(int, int);
	
	void freezeMonster(Monster&);
	void dealDamageToMonster(Monster&);
	void dealDamageToPlayer(Player&);

	void healPlayer(Player&);


	~SpellCard();
};

