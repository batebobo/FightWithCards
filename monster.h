#ifndef MONSTER_H_
#define MONSTER_H_
#include "Card.h"
#include "Hero.h"

class Monster:public Card
{
private:
	int power;
	int health;
public:
	Monster (char* = "",int = 0,int = 0, int = 0, int = 0);
	int getAttack () const
	{
		return power;
	}

	int getHealth () const
	{
		return health;
	}

	void setAttack (int p) {power = p; }
	void setHealth (int h) {health = h;}
	void attack(Monster&);
	void attack(Hero&);
	void print ();
};

#endif /* MONSTER_H_ */
