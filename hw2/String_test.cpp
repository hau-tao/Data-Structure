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
#include <iostream>
#include <cassert>
#include "String.h"
using namespace std;
int main()
{
    // Test String multiplication
    String s4 ="abc";
    s4 = s4 *3;
    String s5 ="hello cse330 ";
    s5 = s5*2;
    assert(s5 =="hello cse330 hello cse330 ");
    assert(s4 == "abcabcabc");
    cout <<"s4: "<< s4<<endl;
    cout <<"s5: "<< s5<<endl;
    // Test String Substraction
    String s6 = "collision";
    String s7 = s6 -"lisi";
    assert (s7 =="colon");
    cout <<"s7: "<< s7<<endl;
    String s8 = s7- "lon";
    assert (s8 == "co");
    cout <<"s8: "<< s8<<endl;
    // Test String concatenation
    String s9 = "cse";
    String s10 = " is great";
    String s11 =s9+s10; 
    assert(s11 =="cse is great");
    cout <<"s11: "<< s11<<endl;
    String s12 =s11 + ", love it";
    assert(s12 == "cse is great, love it");
   
   
    cout <<"s12: "<< s12<<endl;

    cout << "SUCCESS" << endl;  
}