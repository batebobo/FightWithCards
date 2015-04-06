/* 
 * File:   Creature.h
 * Author: boyan
 *
 * Created on April 6, 2015, 2:45 AM
 */

#ifndef CREATURE_H
#define	CREATURE_H

class Creature {
private:
    bool isFrozen;
    int HP;
    
public:
    Creature(bool = false, int = 0);
    Creature(const Creature& orig);
    virtual ~Creature();
    
    int getHP() const {
        return HP;
    }
    void changeHP(int);
    
    bool getState() const {
        return isFrozen;
    }
    
    void changeState(bool);

};

#endif	/* CREATURE_H */

