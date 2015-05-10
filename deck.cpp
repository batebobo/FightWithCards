#include<iostream>
#include<cstring>
#include "deck.h"
#include "card.h"
#include<ctime>
#include<cstdlib>

Deck::Deck(char* _name , Card* _cards):name(NULL), position(0), empty(false){
    setName(_name);
    setCards(_cards);
}

Deck::Deck(const Deck& other):name(NULL){
    copy(other);
    std::cout<<"Deck copied! \n";
}

Deck& Deck::operator=(const Deck& other){
	if (this != &other)
	{
		std::cout << "Deck: " << name << " set to deck: " << other.name << std::endl;
		copy(other);
	}
	return *this;
}

Deck::~Deck(){
    destroy();
}
void Deck::destroy(){
    if(name != NULL){
        delete[] name;
    }
}


void Deck::copy(const Deck& other){
    setName(other.name);
    setCards(other.deck);
	position = other.position;
}


void Deck::setName(char* _name){
    if(name != NULL){
        delete[] name;
    }
    name = new char[strlen(_name) + 1];
    strcpy(name , _name);
}

void Deck::setCards(const Card _cards[30]){
    for(int i = 0 ; i < 30 ; i++){
        deck[i] = _cards[i];
    }
}

void Deck::printDeck() const {
    for(int i = position ; i < 30 ; i++){
		deck[i].print_card();
		std::cout<<std::endl;
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
        swap = deck[from];
        deck[from] = deck[to];
        deck[to] = swap;
    }
}


Card Deck::drawCard(){
		position++;
		if(position == 30)
        {
            empty = true;
        }
		return deck[position -1];
}
