#ifndef MONSTER_H_
#define MONSTER_H_
#include "Card.h"

class Monster:public Card
{
private:
	int attack;
	int health;
public:
	Monster (char* = "",int = 0,int = 0, int = 0, int = 0);
	int getAttack () const
	{
		return attack;
	}

	int getHealth () const
	{
		return health;
	}

	void setAttack (int a) {attack = a; }
	void setHealth (int h) {health = h;}
	void print ();
};

#endif /* MONSTER_H_ */
