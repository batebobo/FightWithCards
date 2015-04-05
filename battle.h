#ifndef BATTLE_H
#define BATTLE_H

#include "card.h"
#include "player.h"

class Battle
{
private:
	int turn;
	Player P1 , P2;
	Card P1Field[5] ,  P2Field[5];
	void copy(Battle const&);

public:
	Battle(Player , Player ,Card* , Card*, int = 0 );
	Battle(Battle const&);
	Battle& operator=(Battle const&);

	void endTurn();

};

#endif