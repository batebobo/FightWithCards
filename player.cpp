#include<iostream>
#include "player.h"
using namespace std;

Player::Player(Mystring _name,Deck &myDeck,Hero& myHero , int _mana):name(_name),deck(myDeck),hero(myHero),fatigue(0),monstersInField(0) , mana(_mana)
{
	for(int i = 0 ; i < 3 ; i++)
		drawCard();
}

Player::Player(Player const& other):name(other.name),hero(other.hero),fatigue(other.fatigue),monstersInField(other.monstersInField) 
													, mana(other.mana) , hand(other.hand) , deck(other.deck)
{	
}

void Player::print(){
    cout<<"Player name: "<<name<<endl;
    cout<<"Player field:\n";
    for(int i = 1 ;i<=monstersInField;i++){
        cout<<"card "<<i<<endl;
        field[i]->print();
    }
    cout<<"player deck:\n";
    deck.printDeck();
}

void Player::useCard(int number){
	Card* toUse = hand.useCard(number);
	if(toUse->isMonster())
	{
		if(toUse->getManacost() <= mana)
		{
			field[monstersInField++] = toUse;
			mana -= toUse->getManacost();
		}
		else
			cout<<"Not enough mana to summon that monster!"<<endl;
	}
	else
		cout<<"Selected card is not a monster!"<<endl;
}

void Player::removeCardFromField(int number)
{
	for(int i = 0 ; i < monstersInField ; i++)
		if(field[i]->getNumber() == number)
		{
			for(int k = i ; k < monstersInField - 1 ; k++)
				field[i] = field[i+1];
			monstersInField--;
			break;
		}
}

void Player::setMana(int _mana)
{
	mana += _mana;
}

void Player::drawCard()
{
	getHand().drawCard(getDeck());
}