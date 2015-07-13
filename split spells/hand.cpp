#include <iostream>
#include "hand.h"
#include "Card.h"
#include "deck.h"

using namespace std;

Hand::Hand():number(0){}

Hand::Hand(Card& a , Card& b , Card& c) : number(3)
{
	hand[0] = &a;
	hand[1] = &b;
	hand[2] = &c;
}

void Hand::drawCard(Deck& deck)
{
	if(cardCounter() == 10)
		cout<<"Maximum card capacity in hand reached! Cannot draw more cards!"<<endl;
	else
	{
		hand[number++] = deck.drawCard();
	}
}

void Hand::printHand()
{
	for(int i = 0 ; i < number ; i++)
		hand[i]->print();
}

Card* Hand::useCard(int _number)
{
	for(int i = 0 ; i < number ; i++)
		if(hand[i]->getNumber() == _number)
		{
			for(int k = i ; k < number - 1 ; k++)
			{
				Card* temp = hand[k];
				hand[k] = hand[k+1];
				hand[k+1] = temp;
			}
			return hand[--number];
		}
	return NULL;
}