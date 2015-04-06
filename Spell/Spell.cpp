/* 
 * File:   Spell.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 2:41 AM
 */

#include "Spell.h"
#include <iostream>

using namespace std;

Spell::Spell(char* _name, int _damage, int _cost, bool _hasFreeze, bool _hasDestroy) {
    name = _name;
    damage = _damage;
    cost = _cost;
    hasFreeze = _hasFreeze;
    hasDestroy = _hasDestroy;
    cout << _name << " spell has been instantiated" << endl;
}

Spell::Spell(const Spell& orig) {
    name = orig.name;
    damage = orig.damage;
    cost = orig.cost;
    hasFreeze = orig.hasFreeze;
    hasDestroy = orig.hasDestroy;
}
Spell& Spell::operator=(const Spell& s){
    if(this == &s) { 
        cout << "Same thing!";
        return *this;
    }
    name = s.name;
    damage = s.damage;
    cost = s.cost;
    hasFreeze = s.hasFreeze;
    hasDestroy = s.hasDestroy;
}


Spell::~Spell() {
    cout << "Deletion of object" << endl;
}

void Spell::hit(Creature& creature) {
    creature.changeHP(-damage);
    if(creature.getHP() <= 0) {
        cout << "dead" << endl;
    }
} 

void Spell::freeze(Creature& creature){
    
    if(creature.getState() != true && hasFreeze == true) {
        creature.changeState(true);
    }
    else {
        cout << "The creature is already frozen or the spell you tried to pick was inappropriate! There's nothing more you can do.";
    }
}
void Spell::destroy(Creature& creature) {
    if(hasDestroy == true) {
        creature.changeHP(-creature.getHP());
        cout << "The creature has been destroyed" << endl;
    }
    else { 
        cout << "The card has no such property" << endl;
    }
}

