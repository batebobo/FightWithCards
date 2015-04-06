/* 
 * File:   Movie.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 8:27 AM
 */

#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(char* _name, double _length, Book _basedOn): name(_name), length(_length){
    basedOn = new Book;
    *basedOn = _basedOn;
}

Movie::Movie(const Movie& orig) {
    basedOn = new Book;
    *basedOn = *orig.basedOn;
}
Movie& Movie::operator=(const Movie& other){
    if(this == &other){
        cout << "Same thing" << endl;
        return *this;
    }
    basedOn = new Book;
    *basedOn = *other.basedOn;
    name = other.name;
    length = other.length;
    
}

Movie::~Movie() {
    delete[] basedOn;
}

