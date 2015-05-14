#include <iostream>
#include "hand.h"

using namespace std;

Hand::Hand(Card a , Card b , Card c) : number(3)
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
		hand[number++] = &deck.drawCard();
	}
}

void Hand::printHand() const
{
	for(int i = 0 ; i < number ; i++)
		hand[i]->print_card();
}

Card& Hand::useCard(Card& card)
{
	for(int i = 0 ; i < number ; i++)
		if(hand[i]->getNumber() == card.getNumber())
		{
			for(int k = i ; k < number - 1 ; k++)
				hand[k] = hand[k+1];
			number--;
			return card;
		}
}