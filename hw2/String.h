/******************************************************************************
 * Programmer: Hau Tao
 * File: String.h
 * Date: 02/08/2016
 * Descrition: This program was implemented exactly as same as in lab 3
 			   However, it was added some functions
               (multiplication, substraction, concatenation
 *Algorithm: Multiplication: Make  n copy of original string 
 			 Subtraction: remove the string contained in the original string
 			 Try to find out the first occurence index of sub-string in 
 			 original string, and then concatenate 2 strings from
 			 beginning to first occurence index and from the 
 			 first occurence + substring.size to the end of orginal string.
 			 Concatenation: Add 2 string together similarly 
 			 implementation of operator +=
 *******************************************************************************/

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
    //***************************************************************************Hau 02/08/2016
    // Multiplication String: "abc"*3--> abcabcabc
    String operator*(unsigned );
    // Substraction String : "collision" -"lisi"--> colon
    String operator-(const String& );
    //Concatenation Operator +
    String operator+(const String &);
    //***************************************************************************Hau 02/08/2016
    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);

};

#endif

