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
#include <cstring>
#include "String.h"

String:: String(){
	size = 0;
	buffer = 0;

}
int String::length(){
	return size;
} 
char &String::operator[](const unsigned i){
	return buffer[i];
}

String String::operator=(const String &s){
	delete[] buffer;
	size = s.size;
	buffer = new char[size];
	for( int i =0; i<size; i++)
		buffer[i] = s.buffer[i];
	return *this;

}

String &String:: operator+=(const String &s){
	size +=s.size; // new size = old size + size of new string
	char *newbuffer = new char[size ];
	for ( int i =0; i < size; i++)
		newbuffer[i] = buffer[i];
	int j = 0;
	delete[] buffer;
	buffer = new char[size];
	for(int i = strlen(newbuffer); i< size ; i++){
		newbuffer[i] = s.buffer[j++];
	}
	// move back to buffer
	buffer = newbuffer;
	
	return *this;
}

String:: String (const String &source){
	size = source.size;
	buffer = new char[size];
	for( int i =0; i< size;++i){
		buffer[i] = source.buffer[i];
	}
}
String:: String(const char *p){
	size = strlen(p);
	buffer = new char[size];
	for( int i = 0 ; i< size; i++)
		buffer[i] = p[i];

}
String:: ~ String(){
	delete[] buffer;
	size = 0;
}
bool operator==(const String &left, const String &right ){
	int i, j;
	for(i=0, j=0; i<left.size && j<right.size; i++,j++)
		if(left.buffer[i] != right.buffer[i])
			return false;
	if (i == left.size && j == right.size)
		return true;
	 
	return false;

}
bool operator <= (const String &left, const String &right){
	int i ,j ;
	for(i=0, j=0; i<left.size && j<right.size; i++,j++)
		if(left.buffer[i] > right.buffer[i])
			return false;
	return true;
}
bool operator < (const String &left, const String &right){
	int i ,j ;
	for(i=0, j=0; i<left.size && j<right.size; i++,j++)
		if(left.buffer[i] >= right.buffer[i])
			return false;
	return true;
}
ostream & operator<< (ostream &out , const String &s){
	for (int i =0; i< s.size; i++)
		out << s.buffer[i];
	return out;

}
//*****************************************************************************************Hau 02/08/2016
// Operator multiplication
String String::operator*(unsigned  n){
	int temp = size; //keep the original size 
	size = n*size;
    char* new_buffer = new char[size];
    int i, j;
    for(int i=0, j=0; j< size; i++,j++){
    	// if i is equal to original size, reset i to make another copy of original string
    	if( i == temp)
    		i =0;
    	new_buffer[j]= buffer[i];
    }
    
    buffer = new_buffer;
    return *this;

}
// Substraction
String String:: operator-(const String& s){
	int temp = size ;// keep the original size
	size -= s.size;
	char* new_buffer = new char[size];
	/* Find the first occurence  of Sring s*/
	int i,j,found_index;
	for( i =0, j=0; i< temp && j< s.size; i++){
		if(buffer[i] == s.buffer[j])
			j++;
		else {
			if(j > 0){
			    j=0;
				i--;	
			}
		}
	}
	if(j == s.size )
		found_index = i-j; // return the first occurence

	int k,l;
	for(k =0; k< found_index; k++)
		new_buffer[k] = buffer[k];
	for(l= found_index +s.size ; l< temp; l++,k++)
		new_buffer[k] = buffer[l];
	buffer = new_buffer;
	return *this;


}

// Concatenation operator +
String String::operator+( const String &s){
	size +=s.size; // new size = old size + size of new string
	char *newbuffer = new char[size ];
	for ( int i =0; i < size; i++)
		newbuffer[i] = buffer[i];
	int j = 0;
	delete[] buffer;
	buffer = new char[size];
	for(int i = strlen(newbuffer); i< size ; i++){
		newbuffer[i] = s.buffer[j++];
	}
	return newbuffer;
}
//*****************************************************************************************Hau 02/08/2016