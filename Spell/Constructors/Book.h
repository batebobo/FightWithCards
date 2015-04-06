/* 
 * File:   Book.h
 * Author: boyan
 *
 * Created on April 5, 2015, 5:34 PM
 */

#ifndef BOOK_H
#define	BOOK_H

class Book {
private:
    int pages;
    bool isInteresting;
    int pageAt;
    char* name;
    
    int *reader;
    
public:
    Book(char*, int = 0);
    Book(const Book& orig);
    virtual ~Book();
    Book& operator=(const Book&);
    int read(int);
    
    int getPages()const {return pages;}
    char* getName() const{return name;}
    
    
};

#endif	/* BOOK_H */

