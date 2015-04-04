#include"batka.h"
#include<iostream>
#include<cstring>
void Batka::copy(const Batka& other){
	setName(other.name);
	years = other.years;
	swagLevel = other.swagLevel;
	muscleMass = other.muscleMass;
}
void Batka::destroy(){
	if(name != NULL){
		delete[] name;
	}
}
void Batka::setName(char* _name){
	if(name != NULL){
		delete[] name;
	}
	name = new char[strlen(_name) +1];
	strcpy(name , _name);
}
Batka::Batka(char* _name , int _years , float _swagLevel ,int _muscleMass):name(NULL) , years(_years) , swagLevel(_swagLevel) , muscleMass(_muscleMass){
	setName(_name);
}
Batka::~Batka(){
	destroy();
}
Batka::Batka(const Batka& other):name(NULL){
	copy(other);
}
Batka& Batka::operator=(const Batka& other){
	copy(other);
	return *this;
}
void Batka::train(int hours){
	muscleMass++;
	swagLevel+=hours;
}