/* 
 * File:   Book.cpp
 * Author: boyan
 * 
 * Created on April 5, 2015, 5:34 PM
 */

#include "Book.h"
#include <cstring>
#include <iostream>

using namespace std;



Book::Book(char* _name ,int _pages):name(NULL), pages(_pages), isInteresting(false), pageAt(0) {
    name = _name;
    cout << _name << " has been bought" << endl;
}

Book::Book(const Book& orig):name(NULL) {
    name = orig.name;
    pages = orig.pages;
    pageAt = orig.pageAt;
    isInteresting = orig.isInteresting;
}
Book& Book::operator=(const Book& other){
	name = other.name;
	pages = other.pages;
	pageAt = other.pageAt;
	return *this;
}

Book::~Book() {
    
}
int Book::read(int speed){
    pageAt += speed;
    if(pageAt >= pages/2) {
        isInteresting = true;
    }
    return pageAt;
}


