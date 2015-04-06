/* 
 * File:   Spell.h
 * Author: boyan
 *
 * Created on April 6, 2015, 2:41 AM
 */
#include "Creature.h"
#include "Player.h"
#ifndef SPELL_H
#define	SPELL_H

class Spell {
private:
    char* name;
    int damage;
    int cost;
    bool hasFreeze;
    bool hasDestroy;
    
public:
    Spell(char* = "", int = 0, int = 0, bool = false, bool = false);
    Spell(const Spell& orig);
    virtual ~Spell();
    Spell& operator=(const Spell&);
    
    
    void hit(Creature&);
    void freeze(Creature&);
    void destroy(Creature&);
    
    int getCost() const {
        return cost;
    }
    int getDamage() const {
        return damage;
    }
    char* getName() const { 
        return name;
    }
    bool getFreeze() const { 
        return hasFreeze;
    }
    bool getDestroy() const {
        return hasDestroy;
    }
    
};

#endif	/* SPELL_H */

