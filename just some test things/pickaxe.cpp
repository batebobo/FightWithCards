#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include"pickaxe.h"
Pickaxe::Pickaxe(char* onlyToNeedConstructor , int _durability , int _digGoldChance , float _moneyColected):onlyToNeedConstructor(NULL) , durability(_durability) , digGoldChance(_digGoldChance) , moneycolected(_moneyColected){
	setName(_onlyToNeedConstructor);
}
Pickaxe::~Pickaxe(){
	destroy();
}
Pickaxe::Pickaxe(const Pickaxe& other):onlyToNeedConstructor(NULL){
	copy(other);
}
Pickaxe& Pickaxe::operator=(const Pickaxe& other){
	copy(other);
	return *this;
}
void Pickaxe::destroy(){
	if(onlyToNeedConstructor != NULL){
		delete[] onlyToNeedConstructor;
	}
}
void Pickaxe::copy(const Pickaxe& other){
	setName(other.onlyToNeedConstructor);
	durability = other.durability;
	digGoldChance = other.digGoldChance;
	moneyColected = other.moneyColected;
}
void Pickaxe::setName(char* _name){
	if(onlyToNeedConstructor != NULL){
		delete[] onlyToNeedConstructor;
	}
	onlyToNeedConstructor = new char[strlen(_name) + 1];
	strcpy(onlyToNeedConstructor , _name);
}
void Pickaxe::repair(){
	std::cout<<"It will cost 5$ for 1 durability proceed y/n ?\n";
	do{
		char c;
		getch(c);
	}while(c!='y' && c!='n');
	if(c == 'y'){
		if(moneyColected < (10 - durability)*5){
			int tempMoney = moneyColected/5;
			moneyColected = moneyColected%5;
			durability +=tempMoney;
		}
		else{
			moneyColected-=(10 - durability)*5;
			durability = 10;
		}
	}
	else{
		return;
	}
}
void Picaxe::digGold(){
	srand(time(0));
	int chance = rand()%30+1;
	durability--;
	for(int i = 0 ; i < digGoldChance ; i++){
		if(chance == i){
			moneyColected+=5;
			return;
		}
	}
}
float Pickaxe::upgrade(float moneyPaid){
	if(digGoldChance == 20){
		std::cout<<"you can only upgrade to level 20 sorry :(\n";
		return;
	}
	std::cout<<"For those money we can upgrade it "<<moneyPaid/20<<" times /n";
	digGoldChance+=moneyPaid/10;
	return moneyPaid%10;
}
void Pickaxe::print()const{
	std::cout<<"Money: "<<moneyCollected<<"\nPickaxe level: "<<digGoldChance<<"\nDurability: "<<durability;	
}