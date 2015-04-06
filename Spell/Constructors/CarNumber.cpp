/* 
 * File:   CarNumber.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 9:32 AM
 */

#include "CarNumber.h"

CarNumber::CarNumber(char* _first, int _middle, char* _last):
firstTwo(_first), middle(_middle), lastTwo(_last){
}

CarNumber::CarNumber(const CarNumber& orig) {
    firstTwo = orig.firstTwo;
    middle = orig.middle;
    lastTwo = orig.lastTwo;
}
CarNumber& CarNumber::operator=(const CarNumber& other) {
    if(this == &other) {
        return *this;
    }
    firstTwo = other.firstTwo;
    middle = other.middle;
    lastTwo = other.lastTwo;
}

CarNumber::~CarNumber() {
}

