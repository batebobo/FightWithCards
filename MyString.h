#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>
using namespace std;

class Mystring
{
private:
    char* mystring;
    int sizea;
public:
    Mystring()
    {
        mystring=NULL;
        sizea=0;
    }
    Mystring (char* newstring)
    {
        mystring= new char[strlen(newstring)];
        for (int i=0; i<strlen(newstring); i++)
		{
			mystring[i]=newstring[i];
		}
        this->sizea=strlen(newstring);
    }

    Mystring ( const Mystring &other)
    {
        this->sizea=other.sizea;
        mystring= new char[sizea];
        for(int i=0; i<sizea; i++)
        {
            mystring[i]=other.mystring[i];
        }
    }

    Mystring operator=(const Mystring &other)
    {
        if(this!=&other)
        {
            delete [] mystring;
            mystring= new char[other.sizea];
            this->sizea=other.sizea;
            for(int i=0; i<sizea; i++)
        {
            mystring[i]=other.mystring[i];
        }
        }
        return *this;
    }

    ~Mystring()
    {
        delete [] mystring;
    }

	int getSize()
	{
		return sizea;
	}

    friend ostream& operator<<(ostream &, Mystring &);

};

 ostream& operator<<(ostream & os, Mystring & other)
    {
		for(int i=0; i<other.getSize();i++) 
			os<<other.mystring[i];
        return os;
    }
#endif // MYSTRING_H
