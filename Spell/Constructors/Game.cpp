/* 
 * File:   Game.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 8:47 AM
 */

#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(char* _name, double _length, int _maxPlayers, double _cost):
name(_name), length(_length), maxPlayers(_maxPlayers), cost(_cost) {
}

Game::Game(const Game& orig) {
    name = orig.name;
    length = orig.length;
    cost = orig.cost;
    maxPlayers = orig.maxPlayers;
}

Game::~Game() {
    cout << "Deletion of object" << endl;
}

