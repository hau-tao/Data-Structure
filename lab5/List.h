#ifndef LIST_H
#define LIST_H

// List.h - a doubly-linked list
#include <algorithm>


// forward declaration of classes defined in this header
template <class T> class Link;
template <class T> class List_iterator;

template <class T> 
class List
{
public:
    typedef List_iterator<T> iterator;
    List();
    List(const List<T> & l);
    ~List();
    bool empty() const;
    unsigned int size() const; 
    T & back() const;
    T & front() const;
    void push_front(const T & x);
    void push_back(const T & x);
    void pop_front();
    void pop_back();
    iterator begin() const;
    iterator end() const;
    void insert(iterator pos, const T & x); // insert x before pos
    void erase(iterator & pos);             // pos must be valid after erase() returns
    List<T> & operator=(const List<T> & l);
protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;
};

template <class T>
List<T>::List()
{
    first_link = 0;
    last_link = 0;
     my_size = 0;
}

template <class T>
List<T>::List(const List & l)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for (Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);
}

template <class T>
typename List<T>::iterator List<T>::end() const
{
    return iterator(last_link->next_link);
}
template <class T>
typename List<T>::iterator List<T>::begin() const
{
    return iterator(first_link);
}
template <class T>
bool List<T>::empty() const{
    if(my_size!= 0)
	      return false;
    return true;
}
template <class T>
unsigned int List<T>::size() const{
    return my_size;
} 
template <class T>
T & List<T>:: back() const{
    return *iterator(last_link);
}
template <class T>
T & List<T>:: front() const{
    return *iterator(first_link);
}
template <class T>
void List<T>::push_front(const T & x){
    Link<T> *new_link = new Link<T>(x);
    if(first_link==0)
	      first_link = last_link = new_link;
    else{
	      new_link->next_link = first_link;
	      first_link->prev_link = new_link;
	      first_link = new_link;
    }
    my_size++;
}
template <class T>
void List<T>::push_back(const T & x){
    Link<T> *new_link = new Link<T>(x);
    if(first_link==0)
	      first_link = last_link = new_link;
    else{
	     last_link->next_link = new_link;
	     new_link->prev_link = last_link;
	     last_link = new_link;
    }
    my_size++;
}
template <class T>
void List<T>:: pop_front(){
	
    if(first_link ==0)
	    first_link = last_link = 0 ;
    else{
	    Link<T> *temp ;
	    temp = first_link-> next_link; 
        delete first_link;
        first_link = temp;
        first_link->prev_link = 0;
        my_size--; 
    }	 
     
       
}
template <class T>
void List<T>:: pop_back(){
	
    if(first_link == 0)
        first_link = last_link = 0;
    else if (my_size ==1)
        pop_front();
    else{
        Link<T> *temp = last_link->prev_link;
        delete last_link;
        last_link = temp;
        last_link->next_link =0;
        my_size--;     

    }
       

}
template <class T>
void List<T>:: insert(iterator pos, const T & x){
    Link<T>*new_link = new Link<T>(x);
    Link<T>*current = pos.current_link;
    Link<T>*prev = current->prev_link;
    if(current == first_link)
        push_front(x);
    else{
    	  new_link->next_link = current;
    	  new_link->prev_link = prev;
        current->prev_link = new_link;
       // current = new_link ->prev_link;
        prev->next_link = new_link;
        //if(current !=0)
            //current->next_link = new_link;
        my_size++;  
    }
}
template <class T>
void List<T> ::erase (iterator &pos){
    Link<T> *next = pos.current_link->next_link;
	  Link<T> *prev = pos.current_link->prev_link;
	  if(next==0)
		    last_link = prev;
	  else
		    next->prev_link = prev;
	  if(prev==0)
		    first_link = next;
	  else
		    prev->next_link = next;
	  delete pos.current_link;
	  my_size--;
	  pos.current_link = next;
}
template<class T>
List<T>::~List(){
    while(!empty())
		    pop_back();
}
template <class T>
List<T>& List<T> :: operator=(const List<T> & l){
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for (Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);

      
          
    return *this;
 }


// Your code goes here ...

template <class T> 
class Link 
{
private:
    Link(const T & x): value(x), next_link(0), prev_link(0) {}             
    T value;     
    Link<T> * next_link;
    Link<T> * prev_link;
    friend class List<T>;
    friend class List_iterator<T>;
};

template <class T> class List_iterator
{
public:
    typedef List_iterator<T> iterator;

    List_iterator(Link<T> * source_link): current_link(source_link) { }
    List_iterator(): current_link(0) { }
    List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }
    T & operator*();  // dereferencing operator
    iterator & operator=(const iterator & rhs);
    bool operator==(const iterator & rhs) const;
    bool operator!=(const iterator & rhs) const;
    iterator & operator++();  // pre-increment, ex. ++it
    iterator operator++(int); // post-increment, ex. it++
    iterator & operator--();  // pre-decrement
    iterator operator--(int); // post-decrement

protected:
    Link<T> * current_link;
    friend class List<T>;
};

template <class T>
T & List_iterator<T>::operator*()
{
    return current_link -> value;
}

template <class T>
List_iterator<T> & List_iterator<T>::operator++() // pre-increment
{
    current_link = current_link -> next_link;
    return *this;
}
template<class T>
List_iterator<T> & List_iterator<T>::operator--() // pre-idecrement
{
    current_link = current_link -> prev_link;
    return *this;
}
template<class T>
List_iterator<T>& List_iterator<T>:: operator=(const iterator & rhs){
    current_link = rhs.current_link;
    return *this;
}
template<class T>
bool List_iterator<T>::  operator==(const iterator & rhs) const{
    return current_link == rhs.current_link;
}
template<class T>
bool List_iterator<T>::  operator!=(const iterator & rhs) const{
	  return current_link != rhs.current_link;
}
template<class T>
List_iterator<T>  List_iterator<T>::operator++(int) // post-increment
{
    List_iterator<T> copy(current_link);
	  current_link = current_link -> next_link;
    return copy;
}
template<class T>
List_iterator<T>  List_iterator<T>::operator--(int) // post-decrement
{
    List_iterator<T> copy(current_link);
	  current_link = current_link -> prev_link;
    return copy;
}
// more code goes here
#endif



