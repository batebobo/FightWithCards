/* 
 * File:   Song.cpp
 * Author: boyan
 * 
 * Created on April 6, 2015, 8:35 AM
 */

#include "Song.h"
#include "Movie.h"
#include <iostream>

using namespace std;

Song::Song(Movie _from, char* _name, double _length):name(_name), length(_length) {
    from = new Movie;
    *from = _from;
}

Song::Song(const Song& orig) {
    from = new Movie;
    *from = *orig.from;
    name = orig.name;
    length = orig.length;
}

Song& Song::operator=(const Song& other) {
    if(this == &other){
        cout << "Same thing" << endl;
        return *this;
    }
    from = new Movie;
    *from = *other.from;
    name = other.name;
    length = other.length;
}

Song::~Song() {
    delete[] from;
}

