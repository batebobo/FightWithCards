/* 
 * File:   Song.h
 * Author: boyan
 *
 * Created on April 6, 2015, 8:35 AM
 */
#include "Movie.h"

#ifndef SONG_H
#define	SONG_H

class Song {
private:
    char* name;
    double length;
    Movie* from;
public:
    Song(Movie, char* = "", double = 0);
    Song(const Song& orig);
    virtual ~Song();
    Song& operator=(const Song&);


};

#endif	/* SONG_H */

