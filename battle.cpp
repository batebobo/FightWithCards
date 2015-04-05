#include "battle.h"

void Battle::copy(Battle const& b)
{
	turn = b.turn;
	P1 = b.P1;
	P2 = b.P2;
	for(int i = 0 ; i < 5 ; i++)
	{
		P1Field[i] = b.P1Field[i];
		P2Field[i] = b.P2Field[i];
	}
}

Battle::Battle(Player one , Player two , Card* field1 , Card* field2 , int _turn) : turn(0) 
{
	P1 = one;
	P2 = two;
}

Battle::Battle(Battle const& b)
{
	copy(b);
}

void Battle::endTurn()
{
	turn++;
	P1.nextTurn();
	P2.nextTurn();
}