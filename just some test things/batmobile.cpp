#include<cstring>
#include<iostream>
#include"batmobile.h"
Batmobile::Batmobile(char* _name ,int _maxSpeed):noNeedOfName(NULL) , maxSpeed(_maxSpeed){
	setName(_name);
}
Batmobile::~Batmobile(){
	blastItWithRocketLauncher();
}
Batmobile::Batmobile(const Batmobile& other):name(NULL){
	copy(other);
}
Batmobile& Batmobile::operator=(const Batmobile& other){
	copy(other);
	return *this;
}
void Batmobile::copy(const Batmobile& other){
	setName(other.name);
	maxSpeed = other.maxSpeed;
}
void Batmobile::destory(){
	if(noNeedOfName != NULL){
		delete[] noNeedOfName;
	}
}
void Batmobile::setName(char* _name){
	if(noNeedOfName != NULL){
		delete[] noNeedOfName;
	}
	noNeedOfName = new char[strle(_name) +1 ];
	strcpy(noNeedOfName ,_name);
}
void Batmobile::speedUp(){
	if(maxSpeed > 2000){
		maxSpeed*=2;
	}
}
void Batmobile::tryToSlowDown(){
	if(maxSpeed < 2000){
		maxSpeed/=2;
	}
}