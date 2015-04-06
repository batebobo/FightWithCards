/* 
 * File:   main.cpp
 * Author: boyan
 *
 * Created on April 6, 2015, 2:41 AM
 */

#include <cstdlib>
#include "Spell.h"
#include "Creature.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Creature gollum = Creature(false,40);
    Spell incinerate = Spell("Incinerate", 30, 0, false, false);
    Spell frostbolt = Spell("Frost bolt", 0, 0, true, false);
    Spell obliterate = Spell("Obliterate", 0, 0, false, true);
    
    //incinerate = incinerate;
    
    incinerate.hit(gollum);
    cout << "Gollum's HP is now " << gollum.getHP() << endl;
    
    frostbolt.freeze(gollum);
    if(gollum.getState() == 0) {
        cout << "The creature remains fully functional" << endl;
    }
    else {
        cout << "The creature is now frozen" << endl;
    }
    obliterate.destroy(gollum);
    
    return 0;
}

