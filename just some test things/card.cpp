#include "card.h"
#include<iostream>
#include<cstring>
Card::Card(int _attack ,int _health , char* _name , int _mana_cost):attack(_attack) , health(_health) , name(NULL) , mana_cost(_mana_cost) {
    setName(_name);
    isActive = true;
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
void Card::changeState(){
    if(isActive){
        isActive = false;
    }else{
        isActive = true;
    }
}
