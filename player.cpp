#include<iostream>
#include "player.h"
using namespace std;

Player::Player(Mystring _name,Deck &myDeck,Hero& myHero , int _mana_crystals):name(_name),deck(myDeck),hero(myHero)
						,fatigue(0),monstersInField(0) , mana_crystals(_mana_crystals) , mana(_mana_crystals)
{
	for(int i = 0 ; i < 3 ; i++)
		drawCard();
}

Player::Player(Player const& other):name(other.name),hero(other.hero),fatigue(other.fatigue),monstersInField(other.monstersInField) 
													, mana(other.mana) , hand(other.hand) , deck(other.deck)
{}

Player& Player::operator=(Player const& other)
{
	if(this != &other)
	{
		name = other.name;
		deck = other.deck;
		hero = other.hero;
		hand = other.hand;
		mana = other. mana;
	}
	return *this;
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
	Hand newHand = hand;
	Card* toUse = newHand.useCard(number);
	if(toUse->isMonster())
	{
		if(toUse->getManacost() <= mana)
		{
			field[monstersInField++] = hand.useCard(number);
			field[monstersInField - 1]->setNumber(monstersInField - 1);
			field[monstersInField - 1]->setHasAttacked(true);
			mana -= toUse->getManacost();
		}
		else
			cout<<"Not enough mana to summon that monster!"<<endl;
	}
	else
		cout<<"Selected card is not a monster!"<<endl;
}

Card* Player::useSpellCard(int number)
{
	Hand newHand = hand;
	Card* toUse = newHand.useCard(number);
	if(!(toUse->isMonster()))
	{
		if(toUse->getManacost() <= mana)
		{
			mana -= toUse->getManacost();
			return hand.useCard(number);
		}
		else
			cout<<"Not enough mana to use that spell card!"<<endl;
	}
	else
		cout<<"Selected card is not a spell card!"<<endl;
	return new Card();
}

void Player::removeCardFromField(int number)
{
	for(int i = 0 ; i < monstersInField ; i++)
		if(field[i]->getNumber() == number)
		{
			for(int k = i ; k < monstersInField - 1 ; k++)
			{
				field[i] = field[i+1];
				field[i]->setNumber(i);
			}
			monstersInField--;
			break;
		}
}

void Player::increaseManaCrystals()
{
	if(mana_crystals < 10)
		mana_crystals++;
	mana = mana_crystals;
}

void Player::drawCard()
{
	getHand().drawCard(getDeck());
}

void Player::printField() 
{
	for(int i = 0 ; i < monstersInField ; i++)
		field[i]->print();
	cout<<endl;
}

Monster& Player::getMonster(int number)
{
	for(int i = 0 ; i < monstersInField ; i++)
		if(field[i]->getNumber() == number)
			return (Monster&)field[i];
	cout<<"Incorrect number input!"<<endl;
	return Monster();
}

void Player::setMonsterHasAttacked(bool attacked)
{
	for(int i = 0 ; i < monstersInField ; i++)
		field[i]->setHasAttacked(attacked);
}

void Player::changeMana(int value)
{
	mana += value;
}