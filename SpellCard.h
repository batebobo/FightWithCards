#pragma once
#include "c:\users\boyan\desktop\cardgame\trunk\Card.h"

class Creature;
class Player;
class SpellCard :
	Card
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
	
	void freezeCreature(Creature&);
	void dealDamageToCreature(Creature&);
	void dealDamageToPlayer(Player&);

	void healPlayer(Player&);


	~SpellCard();
};

