#include "battle.h"
#include <iostream>

using namespace std;


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
	srand(time(NULL));
	firstPlayer = rand()%2;

	while(P1.getHero().getHP() > 0 && P2.getHero().getHP() > 0)
	{
		if(firstPlayer == 0)
		{
			cout<<"Player "<<P1.getName()<<" turn."<<endl;
			play(P1, P2);
			cout<<"Player "<<P2.getName()<<" turn."<<endl;
			play(P2, P1);
		}
		else
		{
			cout<<"Player "<<P2.getName()<<" turn."<<endl;
			play(P2, P1);
			cout<<"Player "<<P1.getName()<<" turn."<<endl;
			play(P1, P2);
		}
		turn++;
	}
}

void Battle::play(Player& currentTurnPlayer, Player& inactivePlayer)
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
			cin >> k;
			switch(k) 
			{
				case 1 : 
					currentTurnPlayer.hand.printHand();
					cout << "Enter the name of the monster you want to play!" << endl;
					int index; cin >> index;
					currentTurnPlayer.useCard(index); //if monster, and if valid index // Error - private access
				break;
				case 2 :
					currentTurnPlayer.hand.printHand(); //Error - private access
					cout << "Enter the index of the spell card you want to play!" << endl;
					int index; cin >> index;
					currentTurnPlayer.useCard(index); //if spell and if valid index // Error - private access
				break;
				case 3 : 
					//first - with which monster to attack - attacking player field
					//second - which monster to be attacked by first - defending player field

					cout << "Enter the index with which you want to attack the enemy!" << endl;
					int attackingIndex; cin >> attackingIndex;
					currentTurnPlayer.field[attackingIndex].printCard(); //Error - private access

					cout << "Enter the index of the monster you wish to attack!" << endl;
					int defendingIndex; cin >> defendingIndex;
					// attack inactivePlayer.field[defendingIndex]
					currentTurnPlayer.field[attackingIndex].attack(inactivePlayer.field[defendingIndex]); //Error - Card has no function "Attack", Private access


				break;
				case 4 : ; break;
				case 5 : ; break;
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