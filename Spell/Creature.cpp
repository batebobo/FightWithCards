/* 
 * File:   Creature.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 2:45 AM
 */

#include "Creature.h"
#include <iostream>

using namespace std;

Creature::Creature(bool _isFrozen, int _HP) {
    isFrozen = _isFrozen;
    HP = _HP;
    cout << "A creature has been instantiated" << endl;
}

Creature::Creature(const Creature& orig) {
}

Creature::~Creature() {
}

void Creature::changeHP(int by){
    HP += by;
}
void Creature::changeState(bool to) {
    isFrozen = to;
}

