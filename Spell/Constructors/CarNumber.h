/* 
 * File:   CarNumber.h
 * Author: boyan
 *
 * Created on April 6, 2015, 9:32 AM
 */

#ifndef CARNUMBER_H
#define	CARNUMBER_H

class CarNumber {
private:
    char* firstTwo;
    int middle;
    char* lastTwo;
    
    
public:
    CarNumber(char* = "", int = 0, char* = "");
    CarNumber(const CarNumber& orig);
    CarNumber& operator=(const CarNumber&);
    virtual ~CarNumber();

};

#endif	/* CARNUMBER_H */

