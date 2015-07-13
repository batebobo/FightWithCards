#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "hero.h"

class Warrior : public Hero
{
public:
	Warrior(char* = "Warrior", int = 30, int = 2, bool=false);

	void print() const;
	void usePower(Player*, Player*);
};

#endif
