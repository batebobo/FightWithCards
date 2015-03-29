#ifndef ORDER_H_
#define ORDER_H_

class Order
{
private:
	int quantity;
	int item_number;
	int order_number;
	int item_price;
	int order_price;
public:
	Order();
	Order(int, int, int, int);
	int getQuantity();
	int getItem_Number();
	int getOrder_Number();
	int getItem_Price();
	int getOrder_Price();
	void print();
	void read();
};

#endif