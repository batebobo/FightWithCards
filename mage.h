#ifndef MAGE_H
#define MAGE_H

#include "hero.h"

class Mage : public Hero
{
public:
	Mage(char* = "Mage" , int = 30 , int = 2 , bool = false);

	void print() const;
	void usePower(Player*);

	bool hasDifferentTargets() const{return true;}
};

#endif