#include "battle.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
#include "monster.h"

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
		cout<<"Press 6 to see own mana , hand , hero and field."<<endl;
		cout<<"Press 7 to see enemy mana , hero and field."<<endl;
		cin >> k;
		switch(k) 
		{
			case 0 : // set monster on field
				currentTurnPlayer.getHand().printHand();
				cout << "Enter the number of the monster you want to play!" << endl;
				int index; cin >> index;
				currentTurnPlayer.useCard(index); //if monster, and if valid index

			break;
			case 1: // use spell card on hero
				currentTurnPlayer.getHand().printHand();
				cout << "Enter the number of the spell you want to use!" << endl;
				cin >> index;
				int heroIndex;
				cout<<"Press 1 to use the spell on your hero or 2 to use it on the enemy hero."<<endl;
				cin>>heroIndex;
				if(heroIndex == 1)
					currentTurnPlayer.useSpellCard(index)->useSpellCard(currentTurnPlayer.getHero());
				if(heroIndex == 2)
					currentTurnPlayer.useSpellCard(index)->useSpellCard(inactivePlayer.getHero());
			break;
			case 2 : //use spell card on monster
				currentTurnPlayer.getHand().printHand();
				cout << "Enter the number of the spell you want to use!" << endl;
				cin >> index;
				int monsterIndex;
				cout<<"Monsters on your field : "<<endl;
				currentTurnPlayer.printField();
				cout<<"Monsters on enemy field : "<<endl;
				inactivePlayer.printField();
				cout<<"Will you use the spell on enemy monster? y/n ";
				char answer;
				cin>>answer; cout<<endl;
				cout<<"Enter the number of the monster on which you want to use the spell card"<<endl;
				cin>>monsterIndex;
				if(answer == 'y')
					currentTurnPlayer.useSpellCard(index)->useSpellCard((Monster&)inactivePlayer.getField()[monsterIndex]);
				else
					currentTurnPlayer.useSpellCard(index)->useSpellCard((Monster&)currentTurnPlayer.getField()[monsterIndex]);
			break;
			case 3 : // attack enemy monster with your monster
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
				currentTurnPlayer.getField()[attackingIndex]->print();
				cout<<endl;
				inactivePlayer.printField();
				cout << "Enter the index of the monster you wish to attack!" << endl;
				int defendingIndex; cin >> defendingIndex;
				inactivePlayer.getField()[defendingIndex]->print(); 
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
			case 4 : // attack enemy hero with your monster
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
				currentTurnPlayer.getField()[attackingIndex]->printCard();
				currentTurnPlayer.getField()[attackingIndex]->attack(inactivePlayer.getHero()); 
				if(inactivePlayer.getHero()->getHealth() <= 0)
				{
					cout<<inactivePlayer.getHero()->getName()<<" has died!"<<endl;
					endTurn = true;
				}
				break;
			case 5 : // use hero skill
				if(!(currentTurnPlayer.getHero()->hasAttacked()))
				{
					if(currentTurnPlayer.getMana() >= currentTurnPlayer.getHero()->getSkillManacost())
					{
						if(currentTurnPlayer.getHero()->hasDifferentTargets())
						{
							currentTurnPlayer.getHero()->print();
							int choice;
							cout<<"Press 0 to use hero power on a hero or 1 to use hero power on monster : ";
							cin>>choice;
							if(choice == 0)
							{
								int target;
								cout<<"Press 1 to use power on your hero or 2 to use power on enemy hero : ";
								cin>>target;
								cout<<endl;
								if(target == 1)
									currentTurnPlayer.getHero()->usePower(currentTurnPlayer.getHero() , (Monster*)&Card() , choice);
								else
									currentTurnPlayer.getHero()->usePower(inactivePlayer.getHero() , (Monster*)&Card() , choice);
								currentTurnPlayer.changeMana(-currentTurnPlayer.getHero()->getSkillManacost());
								if(inactivePlayer.getHero()->getHealth() <= 0)
								{
									cout<<inactivePlayer.getHero()->getName()<<" has died!"<<endl;
									endTurn = true;
								}
							}
							else
							{
								int targetField , target;
								cout<<"Press 1 to use skill on your monster or 2 to use skill on enemy monster : ";
								cin>>targetField;
								if(targetField == 1)
								{
									if(currentTurnPlayer.fieldIsEmpty())
										cout<<"You don't have any monsters on the field!"<<endl;
									else
									{
										currentTurnPlayer.printField();
										cout<<"Enter number of the monster to use hero power on that monster! ";
										cin>>target;
										currentTurnPlayer.getHero()->usePower(inactivePlayer.getHero() , (Monster*)currentTurnPlayer.getField()[target] , choice);
									}
								}
								else
								{
									if(inactivePlayer.fieldIsEmpty())
										cout<<"No monsters on enemy field!"<<endl;
									else
									{
										inactivePlayer.printField();
										cout<<"Enter number of the monster to use hero power on that monster! ";
										cin>>target;
										currentTurnPlayer.getHero()->usePower(inactivePlayer.getHero() , (Monster*)inactivePlayer.getField()[target] , choice);
									}
								}
							}
						}
						else // change might be needed here , maybe some more cases for warlock and paladin cuz they must have access to players..
							currentTurnPlayer.getHero()->usePower(inactivePlayer.getHero() , new Monster("Silver Hand Recruit" , 0 , 0 , 1 , 1 , true) , 0);
					}
					else
					{
						cout<<"Not enough mana!"<<endl; break;
					}
				}
				else
					cout<<"Hero has already used his power this turn!"<<endl;
				break;
			case 6 : // see own cards
				cout<<"your mana : "<<currentTurnPlayer.getMana()<<endl;
				cout<<"Hand : "<<endl;
				currentTurnPlayer.getHand().printHand();
				cout<<"Hero : "<<endl;
				currentTurnPlayer.getHero()->print();
				cout<<"Field : "<<endl;
				for(int i = 0 ; i < currentTurnPlayer.getMonsterInField() ; i++)
					currentTurnPlayer.getField()[i]->print();
				break;
			case 7 : // see enemy field and hero
				cout<<"enemy mana : "<<inactivePlayer.getMana()<<endl;
				cout<<"Hero : "<<endl;
				inactivePlayer.getHero()->print();
				cout<<"Field : "<<endl;
				for(int i = 0 ; i < inactivePlayer.getMonsterInField() ; i++)
					inactivePlayer.getField()[i]->print();
				break;
			case 9 : 
				endTurn = true;
				currentTurnPlayer.setMonsterHasAttacked(false);
				currentTurnPlayer.getHero()->setHasAttacked(false);
				break;
			default : cout<<"Incorrect command input!"<<endl; 

		}
	}
}