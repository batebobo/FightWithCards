#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck
{
   private:
       void copy(const Deck&);
       void destroy();
       char* name;
	   Card* deck[30];
	   int position;
	   bool empty;

   public:
       //THE BIG 4
        Deck(char* = "" , Card** = NULL);
        ~Deck();
        Deck& operator=(const Deck&);
        Deck(const Deck&);

        void shuffle();
        void printDeck();
        void setName(char*);
        void setCards(Card**);
        bool isEmpty()const {return empty ;}
		Card** getCards() const{
			return (Card**)deck;
		}
		Card* drawCard();

};
#endif // DECK
