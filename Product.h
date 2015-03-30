#pragma once
class Product
{
private:
	int number;

	int quantity;
	int price;
	char* name;
public:
	//Constructors
	Product();
	Product(int, int, char*);

	//Getters
	int getPrice() const {
		return price;
	}
	char* getName() const {
		return name;
	}
	int getNumber() const {
		return number;
	}
	

	//Setters
	void changeQuantity(int);
	void changePrice(int);
	void changeNumber(int);

	void changeName(char*);
};

