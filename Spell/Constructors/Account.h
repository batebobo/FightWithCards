/* 
 * File:   Account.h
 * Author: boyan
 *
 * Created on April 6, 2015, 8:51 AM
 */

#ifndef ACCOUNT_H
#define	ACCOUNT_H

class Account {
private:
    char* owner;
    char* securityKey;
    int id;
    int amount;
public:
    Account(char*, char*, int, int);
    Account(const Account& orig);
    virtual ~Account();

};

#endif	/* ACCOUNT_H */

