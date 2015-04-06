/* 
 * File:   Game.h
 * Author: boyan
 *
 * Created on April 6, 2015, 8:47 AM
 */

#ifndef GAME_H
#define	GAME_H

class Game {
private:
    char* name;
    double length;
    int maxPlayers;
    double cost;
public:
    Game(char* = "", double = 0, int = 0, double = 0);
    Game(const Game& orig);
    virtual ~Game();
    Game& operator=(const Game&);

};

#endif	/* GAME_H */

