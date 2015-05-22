#ifndef MONSTER_H_
#define MONSTER_H_
#include "Card.h"
#include "Hero.h"

class Monster:public Card
{
private:
	int power;
	int health;
	bool has_attacked;
public:
	Monster (char* = "",int = 0,int = 0, int = 0, int = 0 , bool = true);
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
	void setHasAttacked(bool);
	void attack(Monster*);
	void attack(Hero&);
	void print ();

	bool hasAttacked() const{return has_attacked;}
	bool isMonster() {return true;}
};

#endif /* MONSTER_H_ */
