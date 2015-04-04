#include<iostream>
#include<cstring>
#include"player.h"
#include "sword.h"
#include "shield.h"
Player::Player(char* _name , int _health , int _armor , int _money):name(NULL) , health(_health) , armor(_armor) , money(_money){
	sword = new Sword("Starting sword" , 5);
	shield = new Shield("Starting shield" , 10);
	armor+=shield->armor;
}
Player::~Player(){
	destroy();
}
Player::Player(const Player& other):name(NULL){
	copy(other);
	std::cout<<"Player cloned! \n";
}
Player& Player::operator=(const Player& other){
	copy(other);
	return *this;
}
void Player::destroy()[
	if(name != NULL){
		delete[] name;	
	}
	delete sword;
	delete shield;
}
void Player::setName(char* _name){
	if(name != NULL){
		delete[] name;
	}
	name = new char[strlen(_name) + 
	strcpy(name , _name);
}
void Player::copy(const Player& other){
	setName(other.name);
	delete sword;
	delete shield;
	sword = new Sword();
	sword = other.sword;
	shield = new Shield();
	shield = other.shield;
	health = other.health;
	armor = other.armor;
	money = other.money;
}
void Player::attack(Player& other){
	if(sword->durability > 0){
		other.health = other.armor/2 - sword->attack;
		sword->durability-=1;
	}
	else{
		std::cout<<"You cant attack rigth now!\n";
	}
}
void Player::defend(Player& other){
	if(shield->durability > 0){
		health = armor/2 - other.sword->attack;
		shield->durability--;
	}
	else{
		health -= other.sword->attack;
	}
	if(health <= 0){
		std::cout<<"You died!\n";
	}
}
void Player::equipSword(Sword& other){
	delete sword;
	sword = new Sword();
	sword = other;
}
void Player::equipShield(Shield& other){
	delete shield;
	shield = new Shield();
	shield = other;
}