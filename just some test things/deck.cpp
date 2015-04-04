#include<iostream>
#include<cstring>
#include"deck.h"
#include<ctime>
#include<cstdlib>
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
