#ifndef CARD_H_
#define CARD_H_

#include "MyString.h"

class Card {
private:
	Mystring name;
	int manacost;
	int number;
	void copy( const Card&);
public:
	Card();
	Card(Mystring, int, int);
	Card(char*, int, int);
	Card(const Card&);
	Card operator=(const Card&);
	int getNumber() const;
	//virtual void use();
	void print();
};

#endif CARD_H_