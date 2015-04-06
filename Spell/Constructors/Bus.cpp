/* 
 * File:   Bus.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 9:25 AM
 */

#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus(int _number, int _peopleCount, char* _model, int _pointer) {
    number = _number;
    peopleCount = _peopleCount;
    model = _model;
    pointer = new int;
    *pointer = _pointer;
}

Bus::Bus(const Bus& orig) {
    number = orig.number;
    peopleCount = orig.peopleCount;
    model = orig.model;
    pointer = new int;
    *pointer = *orig.pointer;
}
Bus& Bus::operator=(const Bus& other) {
    if(this = &other) {
        cout << "Same thing" << endl;
        return *this;
    }
    pointer = new int;
    *pointer = *other.pointer;
    number = other.number;
    peopleCount = other.peopleCount;
    model = other.model;
    
}

Bus::~Bus() {
    delete pointer;
}

