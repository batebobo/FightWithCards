#ifndef CLIENT_H
#define CLIENT_H
#include <cstring>


class Client
{
private:
	char* firstName; // име на клиента
	char* lastName; // фамилия на клиента
	double money; // пари на клиента
	double * product , * quantity , * price; // количка на клиента
	int number; // количка на клиента
public:
	Client(char* name, char* last_name , double _money) 
	{
		firstName = name;
		lastName = last_name;
	    money = _money;
		product = quantity = price = NULL;
		number = 0;
	}
	char* getFirstName() const{return firstName;}
	char* getLastName() const{return lastName;}
	double getClientMoney() const {return money;}
	double* getProduct() const {return product;} // достъп до продуктите от количката
	double* getQuantity() const {return quantity;}
	double* getPrice() const {return price;}
	int getNumber() const {return number;} 

	void remove() // клиентът напуска магазина
	{
		delete[] firstName;
		delete[] lastName;
	}

	void addToCart(Product& ); // добавяне на продукт в количката на клиента
	void pay(); // плащане на продуктите 

};

Client newClient(); // създаване на нов клиент т.е. клиент влиза в магазина


#endif