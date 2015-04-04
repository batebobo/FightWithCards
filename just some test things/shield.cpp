#include "shield.h"
#include<iostream>
#include<cstring>
Shield::Shield(char* _name  , int _armor ):name(NULL) , armor(_armor) , durability(10){
	setName(_name);
}
Shield::~Shield(){
	destroy();
}
Shield::Shield(const Shield& other):name(NULL){
	copy(other);
}
Shield& Shield::operator=(const Shield& other){
	copy(other);
	return *this;
}
void Shield::copy(const Shield& other){
	setName(other.name);
	armor = other.armor;
	durability = 10;
}
void Shield::destroy(){
	if(name !=NULL){
		delete[] name;
	}
}
void Shield::setName(char* _name){
	if(name != NULL){
		delete[] name;
	}
	name = new char[strlen(_name) + 1];
	srtcpy(name , _name);
}
void Shield::engrave(){
	int cost;
	std::cout<<"List of upgrade costs:\n10 for +10 armor\n20 for + 8 armor + 5 durability\n100 for 50 armor + 10 durability\n200 for 75 armor + 15 durability\n";
	std::cin>>cost;
	switch(cost){
		case 10:armor+=10;
		case 20:armor+=8;durability+=5;
		case 100:armor+=50;durability+=10;
		case 200:armor+=75;durability+=15;
		case 1000:armor+=1000;durability+=500;
		default:std::cout<<"wrong input therefore money lost!";
	}
} 