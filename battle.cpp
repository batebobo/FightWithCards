#include "battle.h"
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


Battle::Battle(Player& one , Player& two , int _turn)
				: turn(0) , P1(&one) , P2(&two)
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
	if(firstPlayer == 1)
	{
		Player* temp = P2;
		P2 = P1;
		P1 = temp;
	}

	while(P1->getHero().getHealth() > 0 && P2->getHero().getHealth() > 0) 
	{
		
		cout<<"Player "<<P1->getName()<<" turn."<<endl;
		play(*P1, *P2);
		cout<<"Player "<<P2->getName()<<" turn."<<endl;
		play(*P2, *P1);
		turn++;
		P1->setMana(1);
		P2->setMana(1);
	}
}

void Battle::play(Player& currentTurnPlayer, Player& inactivePlayer) // създаване на enum вместо цифров код
{
	//If Player.hand is empty, automatically end turn;
	//Optional - bool isMonster to check the card type
	bool endTurn = false;
	while(!endTurn)
	{
		int k;
		cout<<"Press 9 to end your turn."<<endl;
		cout<<"Press 0 to set monster on the battlefield."<<endl;
		cout<<"Press 1 to use spell card on hero." << endl;
		cout<<"Press 2 to use spell card on monster."<<endl;
		cout<<"Press 3 to attack enemy monster."<<endl;
		cout<<"Press 4 to attack enemy hero."<<endl;
		cout<<"Press 5 to use hero skill."<<endl;
		cout<<"Press 6 to see own hand , hero and field."<<endl;
		cout<<"Press 7 to see enemy hero and field."<<endl;
		cin >> k;
		switch(k) 
		{
			case 0 : // Monster use
				currentTurnPlayer.getHand().printHand();
				cout << "Enter the number of the monster you want to play!" << endl;
				int index; cin >> index;
				currentTurnPlayer.useCard(index); //if monster, and if valid index

			break;
			case 1: // SpellCard on hero
	
			break;
			case 2 : //SpellCard use
				currentTurnPlayer.getHand().printHand(); 
				cout << "Enter the index of the spell card you want to play!" << endl;
				int index2; cin >> index2;
				currentTurnPlayer.useCard(index2); //if spell and if valid index
			break;
			case 3 : 
				//If Player.field is empty, skip this step
				//first - with which monster to perform the attack - from attacking player field
				//second - which monster to be attacked by first - from defending player field

				cout << "Enter the index with which you want to attack the enemy!" << endl;
				int attackingIndex; cin >> attackingIndex;
				currentTurnPlayer.getField()[attackingIndex]->printCard();

				cout << "Enter the index of the monster you wish to attack!" << endl;
				int defendingIndex; cin >> defendingIndex;
				inactivePlayer.getField()[defendingIndex]->printCard(); 
				// attack inactivePlayer.field[defendingIndex]
				currentTurnPlayer.getField()[attackingIndex]->attack((Monster&)inactivePlayer.getField()[defendingIndex]); 
			break;
			case 4 : 
				cout << "Enter the index with which you want to attack the enemy!" << endl;
				int attackingIndex2; cin >> attackingIndex2;
				currentTurnPlayer.getField()[attackingIndex2]->printCard();
				currentTurnPlayer.getField()[attackingIndex2]->attack(inactivePlayer.getHero()); 
				break;
			case 5 : 
				currentTurnPlayer.getHero().usePower(inactivePlayer.getHero()); 
				break;
			case 6 : 
				cout<<"Hand : "<<endl;
				currentTurnPlayer.getHand().printHand();
				cout<<"Hero : "<<endl;
				currentTurnPlayer.getHero().print();
				cout<<"Field : "<<endl;
				for(int i = 0 ; i < currentTurnPlayer.getMonsterInField() ; i++)
					currentTurnPlayer.getField()[i]->print();
				break;
			case 7 :
				cout<<"Hero : "<<endl;
				inactivePlayer.getHero().print();
				cout<<"Field : "<<endl;
				for(int i = 0 ; i < inactivePlayer.getMonsterInField() ; i++)
					inactivePlayer.getField()[i]->print();
				break;
			case 9 : endTurn = true; break;
			default : cout<<"Incorrect command input!"<<endl; 

		}
	}
}