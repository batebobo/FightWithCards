#include "Product.h"
#include <iostream>

using namespace std;

int productNumber = 0;

Product::Product(int price, int quantity, char* name){
	this->price = price;
	this->quantity = quantity;
	this->name = name;
	
	cout<< "Successfully created: " << this->quantity << " " << this->name << " with the price of " << this->price << endl;
}

void Product::changeName(char* newName){
	this->name = newName;
}

void Product::changePrice(int newPrice){
	this->price = newPrice;
}

void Product::changeQuantity(int k){
	this->quantity += k;
}

