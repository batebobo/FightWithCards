#ifndef INVOICE_H
#define INVOICE_H
#include "client.h"

class Invoice
{
private:
	Client c;
	Shop s;

public:
	Invoice(Client , Shop);
	void print() const;
};

#endif