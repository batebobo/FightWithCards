#ifndef WARLOCK_H_
#define WARLOCK_H_
#include "Hero.h"

class Warlock : public Hero
{
public:
	Warlock(char* = "Warlock", int = 30, int = 2, bool = false);

	void print() const;
	void usePower(Player*, Player*);
};

#endif
