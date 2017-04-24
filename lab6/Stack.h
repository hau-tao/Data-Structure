/*****************************************************************************************************
 * Hau Tao
 * Stack.h
 * 02/24/2016
 * This program implements the Stack class
 * I use all containers like vector, list, string from STL  to make sure they work correctly
 *****************************************************************************************************/
#ifndef STACK_H
#define STACK_H

// Stack.h  -- a stack implemented as an adapter (of vector or list or ...)

#include "list"

using namespace std;

//Use the following line for STL containers.
template <class T, template <class T, class = allocator<T> > class Container = list>

class Stack
{
public:
   //We don't need a constructor or destructor because the Container has/should have one
   //Stack(): container() { }
   //~Stack() { ~container(); }
   bool empty() const{ return container.empty();}
   unsigned int size() const{container.size();}
   void push(const T & x){container.push_back(x);}
   void pop(){container.pop_back();}
   T & top(){return container.back();}
private:
   Container<T> container;
};

#endif

