/* 
 * File:   Bus.h
 * Author: boyan
 *
 * Created on April 6, 2015, 9:25 AM
 */

#ifndef BUS_H
#define	BUS_H

class Bus {
private:
    int number;
    int peopleCount;
    char* model;
    int* pointer;
public:
    Bus(int, int, char*, int);
    Bus(const Bus& orig);
    virtual ~Bus();
    Bus& operator=(const Bus&);

};

#endif	/* BUS_H */

