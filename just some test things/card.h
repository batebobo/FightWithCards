#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card(int = 0 , int = 0 , char* = "" , int = 0 );
        Card(const Card&);
        Card& operator=(const Card&);
       ~Card();
        void setName(char*);
        void print_card()const;
        char* getName(){return name;}
        void changeState();

    private:
        int attack;
        int health;
        char* name;
        int mana_cost;
        bool isActive;
        void destroy();
        void copy(const Card&);
};

#endif // CARD_H
