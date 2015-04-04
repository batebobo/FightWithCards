#include<iostream>
#include"teardrop.h"
Teardrop::Teardrop(int _howMany , float _saltiness ,bool _fromHappines):howMany(_howMany) , saltiness(_saltiness) , fromHappines(_fromHappines){
}
Teardrop::~Teardrop(){
}
Teardrop::Teardrop(const Teardrop& other){
	howMany = other.howMany;
	saltiness = other.saltiness;
	fromHappines = other.fromHappines;
}
Teardrop& Teardrop::operator=(const Teardrop& other){
	howMany = other.howMany;
	saltiness = other.saltiness;
	fromHappines = other.fromHappines;
	return *this;
}
void Teardrop::drop(){
	howMany++;
}
void Teardrop::setSaltiness(float salt){
	saltiness+=salt/1000;
}
void Teardrop::checkHappines(){
	if(saltiness >=10){
		fromHappines = false;
	}
}
float Teardrop::makeSalt(){
	return (float)howMany/1000;
}