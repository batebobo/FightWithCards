#ifndef HAND_H
#define HAND_H

class Card;
class Deck;
class Monster;
class SpellCard;

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
	Card* useCard(int);
	int cardCounter(){return number;}
	Card& getCard(int);
};

#endif
