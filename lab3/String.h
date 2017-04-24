/*****************************************************************************************************
 * Hau Tao
 * String.h
 * 02/02/2016
 * This program implements String class declaration
 * Including one default constructor, and 2 String constructors, the destructor, and the length function
 * and overloading operators ([];= ;+=;==;<=;<<)
 *****************************************************************************************************/

#ifndef STRING_H
#define STRING_H

// String.h

#include <iostream>

using namespace std;

class String {
        int size;
        char * buffer;
public:
        String();
        String(const String &);
        String(const char *);
        ~String();

	// other methods
        int length();
        char &operator[](const unsigned );
        String operator=(const String&);
        String &operator+= (const String&);


        friend bool operator==(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
};

#endif

