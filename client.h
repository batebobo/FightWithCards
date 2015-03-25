#ifndef CLIENT_H
#define CLIENT_H
#include <cstring>

class Client
{
private:
	char* firstName;
	char* lastName;
	double money;

public:
	Client(char* name, char* last_name , double _money) 
	{
		firstName = name;
		lastName = last_name;
	    money = _money;
	}
	char* getFirstName() const{return firstName;}
	char* getLastName() const{return lastName;}
	double getClientMoney() const {return money;}
	void remove()
	{
		delete[] firstName;
		delete[] lastName;
	}

};

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


#endif