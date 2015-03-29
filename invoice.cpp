#include <iostream>
#include "invoice.h"
#include "client.h"

using namespace std;

Invoice::Invoice(Client _c, Shop _s)
{
	c = _c;
	s = _s;
}
void Invoice::print() const
{
	cout<<"Shop : "<<s.getName()<<endl;
	cout<<"Client : "<<c.getFirstName()<<' '<<c.getLastName()<<endl;
	cout<<"¹ | product code | units | price per unit | price"<<endl;
	int count = c.getNumber();
	double sum = 0;
	double* product = c.getProduct() , * price = c.getPrice() , * quant = c.getQuantity();
	for(int i = 0 ; i < count ; i++)
	{
		cout<<i+1<<" | "<<product[i]<<" | "<<quant[i]<<" | "<<price[i]<<" | "<<quant[i] * price[i]<<endl;
		sum += (quant[i] * price [i]);
	}
	cout<<"Total price : "<<sum<<endl;
}