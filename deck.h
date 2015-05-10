#ifndef DECK _H
#define DECK _H
#include "card.h"
class Card;

class Deck
{
   private:
       void copy(const Deck&);
       void destroy();
       char* name;
	   Card deck[30];
	   int position;
	   bool empty;

   public:
       //THE BIG 4
        Deck(char* = "" , Card* = NULL);
        ~Deck();
        Deck& operator=(const Deck&);
        Deck(const Deck&);

        void shuffle();
        void printDeck()const;
        void setName(char*);
        void setCards(const Card*);
        bool isEmpty()const {return empty ;}
		Card drawCard();

};
#endif // DECK
