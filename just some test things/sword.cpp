#include<iostream>
#include<cstring>
#include "sword.h"
void Sword::setName(char* _name){
	if(name != NULL){
		delete[] name;
	}
	name = new char[strlen(_name) + 1];
	strcpy(name , _name);
}
void Sword::copy(const Sword& other){
	setName(other.name);
	attack = other.attack;
	durability = other.durability;
}
void Sword::destroy(){
	if(name != NULL){
		delete[] name;
	}	
}
Sword::Sword(char* _name , int _attack ):name(NULL),attack(_attack),durability(10){
	setName(_name);
}
Sword::~Sword(){
	destroy();
}
Sword::Sword(const Sword& other):name(NULL){
	copy(other.name);
	std::cout<<"Instance created! \n";	
}
Sword& Sword::operator=(const Sword& other){
	copy(other);
	std::cout<<"Sword replicated! \n";
	return *this;	
}
void Sword::forge(int upgradeCost){
	if(upgradeCost <= 10){
		attack+=5;
	}
	else if(upgradeCost <= 100){
		attack+=upgradeCost/2;
	}
	else if(upgradeCost == 200){
		attack+=100;	
	}
	else{
		std::cout<<"invalid upgrade cost \n pay: \n10 for +5\n11-100 for +upgradecost/2\n200 for +100\n";
	}
}