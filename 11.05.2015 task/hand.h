#ifndef HAND_H
#define HAND_H

class Card;
class Deck;

class Hand
{
private:
	Card* hand;
	int number;

public:
	Hand(Card , Card , Card);
	void drawCard(Deck&);
	void printHand() const;
	Card& useCard(Card&);
	int cardCounter(){return number;}
};

#endif