#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <vector>
#include <algorithm>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
	public:
	typedef DequeIterator<T> iterator;
	
	Deque(): vecOne(), vecTwo() { }
	Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
	Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
    ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                     // never call a destructor explicitly
    Deque & operator=(const Deque<T> & d);

	T & operator[](unsigned int);
	T & front();
	T & back();
	bool empty();
	iterator begin();
	iterator end();
	void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
	int size();
	void push_front(const T & value);
	void push_back(const T & value);
	void pop_front();
	void pop_back();
protected:
	vector<T> vecOne;
	vector<T> vecTwo;
};
// Your code goes here ...
template <class T>
Deque<T> & Deque<T>:: operator=(const Deque<T> & d){
	vecOne = d.vecOne;
	vecTwo = d.vecTwo;
}
template <class T>
T & Deque<T>:: operator[](unsigned int x){
	int n = vecOne.size();
	if(x< n)
		return vecOne[(n-1)-x];
	else
		return vecTwo[x - n];

}

template <class T>
T& Deque<T> ::front (){
	if(vecOne.empty())
		return vecTwo.front();
	
	return vecOne.back();
}
template <class T>
T & Deque<T>:: back(){
	if(vecTwo.empty())
		return vecOne.front();
	
	return vecTwo.back();

}
template <class T>
bool  Deque<T>::empty(){
	return (vecOne.empty() and vecTwo.empty());
		
}
template <class T>
typename Deque<T>::iterator Deque<T>::begin() 
{
    return iterator(this, 0);
}
template <class T>
typename Deque<T>::iterator Deque<T>::end() 
{
    return iterator(this, size());
}
template <class T>
void Deque<T>:: erase(const iterator & it){
	int index = it.index;
	int n = vecOne.size();
	if(index < n)
		vecOne.erase(vecOne.begin() + ((n-1) - index));
	else
		vecTwo.erase(vecTwo.begin() + (index-n));
}
template <class T>
void Deque<T>:: erase(const iterator & start, const iterator & end){
	int start_index = start.index;
	int end_index = end.index;
	int size_1 = vecOne.size();
	if( end_index < size_1  )
		vecOne.erase(vecOne.begin()+start_index,vecOne.begin()+end_index);
	else if( start_index >= size_1)
		vecTwo.erase(vecTwo.begin()+start_index,vecTwo.begin()+end_index);
	else if (start_index < size_1 and end_index >= size_1){
		vecOne.erase(vecOne.begin()+start_index, vecOne.end());
		vecTwo.erase(vecTwo.begin(), vecTwo.begin()+(end_index-size_1));
	}

}


template <class T>
void Deque<T>::insert(const iterator & itr, const T & x){
	int index = itr.index;
	int size_1 = vecOne.size();
	if(index < size_1)
		vecOne.insert(vecOne.begin()+(size_1-index), x);
	else
		vecTwo.insert(vecTwo.begin()+(index-size_1), x);
}

template <class T>
int Deque<T>:: size(){
	return vecOne.size()+vecTwo.size();
}
template <class T>
void Deque<T>::push_front(const T & value){
	vecOne.push_back(value);
}
template <class T>
void Deque<T>::push_back(const T & value){
	vecTwo.push_back(value);
}
template <class T>
void Deque<T>:: pop_front(){
	if(vecOne.empty())
		vecTwo.erase(vecTwo.begin());
	else
		vecOne.pop_back;
	
}
template <class T>
void  Deque<T>::pop_back(){
	if(vecTwo.empty())
		vecOne.erase(vecOne.begin());
	else
		vecTwo.pop_back();
}




template <class T>
class DequeIterator {
	friend class Deque<T>;
	typedef DequeIterator<T> iterator;
public:
	DequeIterator(): theDeque(0), index(0) { }
	DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
	DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

	T & operator*();
	iterator & operator++();
	iterator operator++(int);
	iterator & operator--();
	iterator operator--(int);
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	iterator operator=(const iterator & r);
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	Deque<T> * theDeque;
	int index;
};
template <class T>
T & DequeIterator<T>:: operator*(){
	return (*theDeque)[index];
}
template <class T>
DequeIterator<T>& DequeIterator<T>:: operator++(){
	++index;
	return *this;
}
template <class T>
DequeIterator<T> DequeIterator<T>:: operator++(int){
	DequeIterator<T> clone(*this);
	index++;
	return clone;
}
template <class T>
DequeIterator<T>& DequeIterator<T>:: operator--(){
	--index;
	return *this;
}
template <class T>
DequeIterator<T> DequeIterator<T>:: operator--(int){
	DequeIterator<T> clone(*this);
	index--;
	return clone;
}
template <class T>
bool DequeIterator<T>::operator==(const iterator & r){
	return theDeque == r.theDeque && index == r.index;
}
template <class T>
bool DequeIterator<T>::operator!=(const iterator & r){
	return theDeque == r.theDeque && index != r.index;

}
template <class T>
bool DequeIterator<T>::operator<(const iterator & r){
	return theDeque == r.theDeque && index < r.index;

}
template <class T>
T & DequeIterator<T>:: operator[](unsigned int i){
	return (*theDeque) [index + i];
}
template <class T>
DequeIterator<T> DequeIterator<T>:: operator=(const iterator & r){
	theDeque = r.theDeque; 
	index = r.index;
	return *this;
}
template <class T>
DequeIterator<T> DequeIterator<T>:: operator+(int i){
	return  iterator(theDeque, index+i);
}
template <class T>
DequeIterator<T> DequeIterator<T>:: operator-(int i){
	return  iterator(theDeque, index-i);
}


#endif

