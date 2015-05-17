#ifndef BATTLE_H
#define BATTLE_H

#include "Card.h"
#include "player.h"

class Battle
{
private:
	int turn;
	Player P1 , P2;

public:
	Battle(Player& , Player& , int = 0);
	Battle(Battle const&);
	
	void play(Player&);
	void beginBattle();

};

#endif