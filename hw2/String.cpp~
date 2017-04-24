/*****************************************************************************************************
 * Hau Tao
 * String.cpp
 * 02/02/2016
 * This program implements String class declaration
 * Including one default constructor, and 2 String constructors, the destructor, and the length function
 * and overloading operators ([];= ;+=;==;<=;<<)
 *****************************************************************************************************/
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
	strcpy(newbuffer, buffer); // copy buffer to another one
	int j = 0;
	delete[] buffer;
	buffer = new char[size];
	for(int i = strlen(newbuffer); i< size ; i++){
		newbuffer[i] = s.buffer[j++];
	}
	// move back to buffer
	for ( int i =0; i< size; ++i)
		buffer[i] = newbuffer[i];
	delete[] newbuffer;
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
			return false
;	return true;
}
ostream & operator<< (ostream &out , const String &s){
	for (int i =0; i< s.size; i++)
		out << s.buffer[i];
	return out;

}
