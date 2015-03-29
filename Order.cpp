// Order.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Order.h"

using namespace std;

Order::Order()
{
	quantity=0;
	item_number=0;
	order_number=0;
	item_price=0;
	order_price=0;
}
Order::Order(int q, int n, int o, int p)
{
	quantity=q;
	item_number=n;
	order_number=o;
	item_price=p;
	order_price=q*p;
}
int Order::getQuantity()
{
	return quantity;
}
int Order::getItem_Number()
{
	return item_number;
}
int Order::getOrder_Number()
{
	return order_number;
}
int Order::getItem_Price()
{
	return item_price;
}
int Order::getOrder_Price()
{
	return quantity*item_price;
}
void Order::print()
{
	cout<<endl<<"Order number "<<order_number<<endl;
	cout<<quantity<<" copies of item with code "<<item_number<<endl;
	cout<<"Price for 1 copy of given item "<<item_price<<endl;
	cout<<"Total "<<order_price;
}
void Order::read()
{
	cout<<endl<<"What's the order's number? ";
	cin>>order_number;
	cout<<endl<<"What's the ordered item's number? ";
	cin>>item_number;
	cout<<endl<<"How much does the item cost? ";
	cin>>item_price;
	cout<<endl<<"How many copies of the item? ";
	cin>>quantity;
	order_price=quantity*item_price;
}
