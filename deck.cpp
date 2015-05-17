#include<iostream>
#include<cstring>
#include "deck.h"
#include "Card.h"
#include<ctime>
#include<cstdlib>
#include "MyString.h"
const Mystring def("default");

Deck::Deck(char* _name ,Card** _cards):name(NULL), position(0), empty(false){
    setName(_name);
    setCards(_cards);
}

Deck::Deck(Deck& other):name(NULL){
    copy(other);
    std::cout<<"Deck copied! \n";
}

Deck& Deck::operator=(Deck& other){
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


void Deck::copy(Deck& other){
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

void Deck::setCards(Card* _cards[30]){
    for(int i = 0 ; i < 30 ; i++){
			deck[i] = _cards[i];
    }
}

void Deck::printDeck(){
    for(int i = position ; i < 30 ; i++){
		deck[i]->print();
		std::cout<<std::endl;
    }
}

void Deck::shuffle(){
    srand(time(0));
    int from;
    int to;
    Card* swap;
    for(int i = 0 ; i < 1000 ; i++){
        from = rand()%30;
        to = rand()%30;
        swap = deck[from];
        deck[from] = deck[to];
        deck[to] = swap;
    }
}


Card* Deck::drawCard(){
	position++;
	if(position < 30)
        {
        	return deck[position -1];
        }
	empty = true;
	return NULL;
}
