#include <iostream>
#include "client.h"

using namespace std;

int size = 10;

Client newClient()
	{
		double _money;
		char* first_name = new char[30] , *last_name = new char[30];
		cout<<"Enter client's first name : ";
		cin>>first_name;
		cout<<"Enter client's last name : ";
		cin>>last_name;
		cout<<"Enter client's money : ";
		cin>>_money;
		return Client(first_name , last_name , _money);
	}

double* resize(double* arr , int old , int next) // увеличаване капацитета на количката
{
	double* newarr = new double[next];
	for(int i = 0 ; i < old ; i++)
		newarr[i] = arr[i];
	delete[] arr;
	return newarr;
}

void Client::addToCart(Product& p)
{
	product = new double[size];
	quantity = new double[size];
	price = new double[size];
	if(number == (size - 1))
		{
			int oldSize = size;
			size *= 2;
			product = resize(product , oldSize , size);
			quantity = resize(quantity , oldSize , size);
			price = resize(product , oldSize , size);
		}
	product[number] = p.getNumber(); // записване на номера на продукта
	int k;
	cout<<"How many "<<p.getName()<<" would you like?"<<endl;
	cin>>k;
	quantity[number] = k; //записване на количеството продукти
	price[number] = p.getPrice(); // записване на единичната цена на продукта
	p.changeQuantity(-k); // премахване на взетите продукти от магазина
	number++;

}

void Client::pay()
{
	double summary = 0;
	for(int i = 0 ; i < number ; i++)
	{
		summary += price[number]; //Обща цена на продуктите в количката
	}
	if(summary > money)
		cout<<"You dont have enough money to buy the products! Better return some of them."<<endl;
	else
	{ // Плащане на продуктите 
		money -= summary;
		delete[] price;
		delete[] quantity;
		delete[] product;
		number = 0;
	}
}