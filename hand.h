#ifndef HAND_H
#define HAND_H

class Card;
class Deck;

class Hand
{
private:
	Card* hand[10];
	int number;

public:
	Hand(Card& , Card& , Card&);
	Hand();
	void drawCard(Deck&);
	void printHand();
	Card& useCard(Card&);
	int cardCounter(){return number;}
};

#endif
