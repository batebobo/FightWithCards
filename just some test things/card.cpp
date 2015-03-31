#include "card.h"
#include "deck.h"
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
Card::Card(int _attack ,int _health , char* _name , int _mana_cost ):attack(_attack) , health(_health) , name(NULL) , mana_cost(_mana_cost){
    setName(_name);
}
Card::Card(const Card& c):name(NULL){
    copy(c);
    std::cout<<"Card "<<name<<" cloned \n";
}
Card::~Card(){
    std::cout<<"Card "<<name<<" destroyed! \n";
    destroy();
}
Card& Card::operator=(const Card& c){
    std::cout<<"Card "<<name<<" turned into card "<<c.name;
    copy(c);
}
void Card::copy(const Card& other){
    setName(other.name);
    attack = other.attack;
    health = other.health;
    mana_cost = other.mana_cost;
}
void Card::setName(char* _name){
    if(name != NULL){
        delete[] name;
    }
    name = new char[strlen(_name) + 1];
    strcpy(name , _name);
}
void Card::destroy(){
    if(name != NULL){
        delete[] name;
    }
}
void Card::print_card() const {
    std::cout<<"Card: "<<name<<"\nAttack: "<<attack<<"\nHealth: "<<health<<"\nMana cost: "<<mana_cost<<std::endl;
}
Deck::Deck(char* _name , Card* _cards):name(NULL) , cards(NULL){
    setName(_name);
    setCards(_cards);
}
Deck::Deck(const Deck& other):name(NULL),cards(NULL){
    copy(other);
    std::cout<<"Deck copied! \n";
}
Deck& Deck::operator=(const Deck& other){
    std::cout<<"Deck: "<<name<<" set to deck: "<<other.name<<std::endl;
    copy(other);

}
Deck::~Deck(){
    destroy();
}
void Deck::destroy(){
    if(name != NULL){
        delete[] name;
    }
    if(cards != NULL){
        delete[] cards;
    }
}
void Deck::copy(const Deck& other){
    setName(other.name);
    setCards(other.cards);
}
void Deck::setName(char* _name){
    if(name != NULL){
        delete[] name;
    }
    name = new char[strlen(_name) + 1];
    strcpy(name , _name);
}
void Deck::setCards(Card* _cards){
    if(cards != NULL){
        delete[] cards;
    }
    cards = new Card[30];
    for(int i = 0 ; i < 30 ; i++){
        cards[i] = _cards[i];
    }
}
void Deck::printDeck() const {
    for(int i = 0 ; i < 30 ; i++){
        std::cout<<"Card "<<i+1<<" name: "<<cards[i].getName()<<std::endl;
    }
}
void Deck::shuffle(){
    srand(time(0));
    int from;
    int to;
    Card swap;
    for(int i = 0 ; i < 1000 ; i++){
        from = rand()%30;
        to = rand()%30;
        std::cout<<"swapping "<<from<<" with "<<to<<std::endl;
        swap = cards[from];
        cards[from] = cards[to];
        cards[to] = swap;
    }
}
int main(){
    Card c1(15,150 ,"The walking horror",5);
    Card c2(20 , 500 , "The wrestler" , 2);
    Card c3(10 , 200 , "Dingo" , 1);
    Card c4(50 , 1 , "Explosive" , 4);
    Card c5(12 , 250 , "The Batka" , 3);
    Card* cards = new Card[30];
    for(int i = 0 ; i < 30 ; i++){
        if(i %5 ==0){
            cards[i] = c1;
        }
        if(i%5 == 1){
            cards[i] = c2;
        }
        if(i%5 == 2){
            cards[i] = c3;
        }
        if(i%5 == 3){
            cards[i] = c4;
        }
        if(i%5 == 4){
           cards[i] = c5;
        }
    }
    c1.print_card();
    Deck myDeck("Best deck EU" , cards);
    myDeck.shuffle();
    myDeck.printDeck();
    return 0;
}
