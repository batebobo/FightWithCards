/* 
 * File:   Movie.h
 * Author: boyan
 *
 * Created on April 6, 2015, 8:27 AM
 */
#include "Book.h"

#ifndef MOVIE_H
#define	MOVIE_H

class Movie {
private:
    char* name;
    double length;
    Book* basedOn;
public:
    Movie(char*, int, Book);
    Movie(const Movie& orig);
    virtual ~Movie();
    Movie& operator=(const Movie&);


};

#endif	/* MOVIE_H */

