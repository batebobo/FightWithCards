#include "battle.h"


Battle::Battle(Player& one , Player& two , int _turn)
				: turn(0) , P1(one) , P2(two)
{}

Battle::Battle(Battle const& b) : P1(b.P1) , P2(b.P2)
{
	turn = b.turn;
}


void Battle::beginBattle()
{
	int firstPlayer;
	bool coinToss = false;
	if(!coinToss)
	{
		srand(time(NULL));
		firstPlayer = rand()%2;
		coinToss = true;
	}
	while(P1.getHero().getHP() > 0 && P2.getHero().getHP() > 0)
	{
		if(firstPlayer == 0)
		{
			cout<<"Player "<<P1.getName()<<" turn."<<endl;
			play(P1);
			cout<<"Player "<<P2.getName()<<" turn."<<endl;
			play(P2);
		}
		else
		{
			cout<<"Player "<<P2.getName()<<" turn."<<endl;
			play(P2);
			cout<<"Player "<<P1.getName()<<" turn."<<endl;
			play(P1);
		}
		turn++;
	}
}

void Battle::play(Player& p)
{
	bool endTurn = false;
	while(!endTurn)
	{
		bool summonedMonster = false;
		if(!summonedMonster)
		{
			int k;
			cout<<"Press 9 to end your turn."<<endl;
			cout<<"Press 1 to set monster on the battlefield."<<endl;
			cout<<"Press 2 to use spell card."<<endl;
			cout<<"Press 3 to attack enemy monster."<<endl;
			cout<<"Press 4 to attack enemy hero."<<endl;
			cout<<"Press 5 to use hero skill."<<endl;
			switch(k) 
			{
				case 1 : ;
				case 2 : ;
				case 3 : ;
				case 4 : ;
				case 5 : ;
				case 9 : endTurn = true; break;
				default : cout<<"Incorrect command input!"<<endl; 

			}
		}
		else
		{
			int k;
			cout<<"Press 9 to end your turn."<<endl;
			cout<<"Press 1 to use spell card."<<endl;
			cout<<"Press 2 to attack enemy monster."<<endl;
			cout<<"Press 3 to attack enemy hero."<<endl;
			cout<<"Press 4 to use hero skill."<<endl;
			switch(k) 
			{
				case 1 : ;
				case 2 : ;
				case 3 : ;
				case 4 : ;
				case 9 : endTurn = true; break;
				default : cout<<"Incorrect command input!"<<endl;

			}

		}
	}
}