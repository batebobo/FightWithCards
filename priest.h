#ifndef PRIEST_H
#define PRIEST_H

#include "hero.h"

class Priest : public Hero
{
public:
	Priest(char* = "Priest" , int = 30 , int = 2 , bool = false);

	void print() const;
	void usePower(Player*, Player*);

	bool hasDifferentTargets() const{return true;}
};

#endif
