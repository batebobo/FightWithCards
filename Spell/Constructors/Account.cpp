/* 
 * File:   Account.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 8:51 AM
 */

#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(char* _owner, char* _securityKey, int _id, int _amount):
owner(_owner), securityKey(_securityKey), id(_id), amount(_amount) {
}

Account::Account(const Account& orig) {
    owner = orig.owner;
    securityKey = orig.securityKey;
    id = orig.id;
    amount = orig.amount;
}

Account::~Account() {
    cout << "Delete object" << endl;
}

