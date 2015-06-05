#include "battle.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
#include "monster.h"
#include <string>
#include <map>
#include <assert.h>

using namespace std;

// observer pattern , * factory pattern
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
	P1->getDeck().shuffle();
	P2->getDeck().shuffle();
	while(P1->getHero()->getHealth() > 0 && P2->getHero()->getHealth() > 0) 
	{
		if(P1->getDeck().isEmpty())
		{
			cout<<P1->getHero()->getName()<<" loses 1 health due to fatigue!"<<endl;
			P1->getHero()->setHealth(P1->getHero()->getHealth() - 1);
		}
		if(P2->getDeck().isEmpty())
		{
			cout<<P2->getHero()->getName()<<" loses 1 health due to fatigue!"<<endl;
			P2->getHero()->setHealth(P2->getHero()->getHealth() - 1);
		}
		if(P2->getHero()->getHealth() > 0)
		{
			cout<<"Player "<<P1->getName()<<" turn."<<endl;
			play(*P1, *P2);
		}
		else
			break;
		if(P2->getHero()->getHealth() > 0)
		{
			cout<<"Player "<<P2->getName()<<" turn."<<endl;
			play(*P2, *P1);
		}
		else
			break;
		turn++;
		P1->increaseManaCrystals();
		P2->increaseManaCrystals();
		P1->drawCard();
		P2->drawCard();
	}
	if(P1->getHero()->getHealth() <= 0)
		cout<<"Player "<<P2->getName()<<" has won the duel!"<<endl;
	else
		cout<<"Player "<<P1->getName()<<" has won the duel!"<<endl;
}

void Battle::play(Player& currentTurnPlayer, Player& inactivePlayer) 
{
	enum Commands{DEF , PLAY_CARD , END_TURN ,  ATTACK_MONSTER , ATTACK_HERO , USE_HERO_POWER , SEE_OWN_STATS , SEE_ENEMY_STATS};//all caps
	map<string,Commands> m;
	m["play card"] = PLAY_CARD;
	m["end turn"] = END_TURN;
	m["attack monster"] = ATTACK_MONSTER;
	m["attack hero"] = ATTACK_HERO;
	m["use hero power"] = USE_HERO_POWER;
	m["show own stats"] = SEE_OWN_STATS;
	m["show enemy stats"] = SEE_ENEMY_STATS;
	bool end = false;
	Card* playedCard = NULL;
	while(!end)
	{
		string input;
		cout<<"Type \"end turn\" to end your turn."<<endl;
		cout<<"Type \"play card\" to play a card from your hand."<<endl;
		cout<<"Type \"attack monster\" to attack enemy monster."<<endl;
		cout<<"Type \"attack hero\" to attack enemy hero."<<endl;
		cout<<"Type \"use hero power\" to use hero power."<<endl;
		cout<<"Type \"show own stats\" to see own mana , hand , hero and field."<<endl;
		cout<<"Type \"show enemy stats\" to see enemy mana , hero and field."<<endl;
		getline(cin , input);
		Commands command = m[input];
		switch(command) 
		{ 
			case DEF : cout<<"Incorrect command input!"<<endl; break;
			case PLAY_CARD : // set monster on field
				currentTurnPlayer.getHand().printHand();
				cout << "Enter the number of the card you want to play!" << endl;
				int index; cin >> index;
				playedCard = currentTurnPlayer.playCard(index);
				if(playedCard != NULL)
				{
					playedCard->useCard(&currentTurnPlayer , &inactivePlayer);
				}
				else
					cout<<"Incorrect card number input!"<<endl;

			break;
			case ATTACK_MONSTER : // attack enemy monster with your monster
				if(currentTurnPlayer.fieldIsEmpty())
				{
					cout<<"You dont have monsters on the field with which to attack!"<<endl;
					break;
				}
				if(inactivePlayer.fieldIsEmpty())
				{
					cout<<"Enemy player do not have any monsters on his field!"<<endl;
					break;
				}
				currentTurnPlayer.printField();
				cout << "Enter the index of the monster with which you want to attack the enemy!" << endl;
				int attackingIndex; cin >> attackingIndex;
				if(currentTurnPlayer.getField()[attackingIndex]->hasAttacked())
				{
					cout<<"This monster was set on the field this turn or has already attacked!"<<endl;
					break;
				}
				cout<<endl;
				inactivePlayer.printField();
				cout << "Enter the index of the monster you wish to attack!" << endl;
				int defendingIndex; cin >> defendingIndex;
				currentTurnPlayer.getField()[attackingIndex]->attack((Monster*)inactivePlayer.getField()[defendingIndex]);
				if(currentTurnPlayer.getField()[attackingIndex]->getHealth() <= 0)
				{
					cout<<currentTurnPlayer.getField()[attackingIndex]->getName()<<" was destroyed!"<<endl;
					currentTurnPlayer.removeCardFromField(attackingIndex);
				}
				if(inactivePlayer.getField()[defendingIndex]->getHealth() <= 0)
				{
					cout<<inactivePlayer.getField()[defendingIndex]->getName()<<" was destroyed!"<<endl;
					inactivePlayer.removeCardFromField(defendingIndex);
				}
			break;
			case ATTACK_HERO : // attack enemy hero with your monster
				if(currentTurnPlayer.fieldIsEmpty())
				{
					cout<<"You dont have monsters on the field with which to attack!"<<endl;
					break;
				}
				currentTurnPlayer.printField();
				cout << "Enter the index with of the monster which you want to attack the enemy!" << endl;
				attackingIndex; cin >> attackingIndex;
				if(currentTurnPlayer.getField()[attackingIndex]->hasAttacked())
				{
					cout<<"This monster was set on the field this turn or has already attacked!"<<endl;
					break;
				}
				currentTurnPlayer.getField()[attackingIndex]->attack(inactivePlayer.getHero()); 
				if(inactivePlayer.getHero()->getHealth() <= 0)
				{
					cout<<inactivePlayer.getHero()->getName()<<" has died!"<<endl;
					end = true;
				}
				break;
			case USE_HERO_POWER : // use hero skill
				if(!(currentTurnPlayer.getHero()->hasAttacked()))
				{
					if(currentTurnPlayer.getMana() >= currentTurnPlayer.getHero()->getSkillManacost())
					{
						cout<<"Do you want to use hero power on enemy target? y/n";
						char answer;
						cin>>answer;
						if(answer == 'y')
							currentTurnPlayer.getHero()->usePower(&inactivePlayer);
						else if(answer == 'n')
							currentTurnPlayer.getHero()->usePower(&currentTurnPlayer);
						else
							cout<<"Incorrect answer input!"<<endl;
					}
					else
					{
						cout<<"Not enough mana!"<<endl; break;
					}
				}
				else
					cout<<"Hero has already used his power this turn!"<<endl;
				break;
			case SEE_OWN_STATS : // see own cards
				cout<<endl;
				cout<<"your mana : "<<currentTurnPlayer.getMana()<<endl;
				cout<<"\t\t==== Hand ===="<<endl;
				currentTurnPlayer.getHand().printHand();
				cout<<"\t\t==== Hero ===="<<endl;
				currentTurnPlayer.getHero()->print();
				cout<<"\t\t==== Field ===="<<endl;
				for(int i = 0 ; i < currentTurnPlayer.getMonsterInField() ; i++)
					currentTurnPlayer.getField()[i]->print();
				break;
			case SEE_ENEMY_STATS : // see enemy field and hero
				cout<<"enemy mana : "<<inactivePlayer.getMana()<<endl;
				cout<<"\t\t==== Hero ===="<<endl;
				inactivePlayer.getHero()->print();
				cout<<"\t\t==== Field ===="<<endl;
				for(int i = 0 ; i < inactivePlayer.getMonsterInField() ; i++)
					inactivePlayer.getField()[i]->print();
				break;
			case END_TURN : 
				end = true;
				currentTurnPlayer.setMonsterHasAttacked(false);
				currentTurnPlayer.getHero()->setHasAttacked(false);
				break; 
		}
		cin.ignore();
	}
}