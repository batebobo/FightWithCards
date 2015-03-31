#ifndef DECK _H
#define DECK _H
class Deck
{
   private:
       void copy(const Deck&);
       void destroy();
       char* name;
       Card* cards;
   public:
       //THE BIG 4
        Deck(char* = "" , Card* = new Card());
        ~Deck();
        Deck& operator=(const Deck&);
        Deck(const Deck&);

        void shuffle();
        void printDeck()const;
        void setName(char*);
        void setCards(Card*);
};
#endif // DECK
