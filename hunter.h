#ifndef HUNTER_H_
#define HUNTER_H_

#include "Hero.h"

class Hunter : public Hero
{
public:
	Hunter(char* = "Hunter", int=30, int =2, bool=false);

	void print() const;
	void usePower(Hero*, Monster*, int);
};

#endif