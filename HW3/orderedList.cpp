/***************************************************************************************************
 * Programmer: Hau Tao
 * File: orderedlist.cpp
 * Date: 02/22/2016
 * Descrition: This program was implemented union an intersection of 2 ordered lists
 * Algorithm: Union ordered list: Get all elements from both lists and push them to the new list
             Intersection ordered list: push all common elemnt from both lists to the new list
             Union unorder list: selction sort 2 lists and call Union ordered list
             Intersection unorderd list: selection sort 2 lists and call intersection ordered list
 ***************************************************************************************************/

#include <iostream>
#include <list>
#include <cassert>
using namespace std;
// Ordered union list
template <class T>
list<T> ordered_union(const list<T> & a, const list<T> & b){
	list<T> temp ;
	typename list<T>::iterator it = temp.begin()  ; 
	typename list<T>::const_iterator i  = a.begin();
	typename list<T>::const_iterator j = b.begin();
	while(i!= a.end() && j != b.end()){
		if(*i < *j){
			temp.push_back(*i);
			i++;	
		}else if( *i > *j){
			temp.push_back(*j);
			j++;	
		}
	    else {
	        temp.push_back(*i);
	    	i++;
	    	j++;
	    }
	    it++;
	}
	while(i!= a.end()){
		temp.push_back(*i);
		i++;
	}
	while(j != b.end()){
		temp.push_back(*j);
	    j++;

	}		
	return temp;
    
}

// Ordered intersection list
template <class T>
list<T> ordered_intersect(const list<T> & a, const list<T> & b){
	list<T> temp ;
	typename list<T>::iterator it = temp.begin()  ; 
	typename list<T>::const_iterator i  = a.begin();
	typename list<T>::const_iterator j = b.begin();
	while(i!= a.end() && j != b.end()){
		if(*i < *j)
			i++;	
		else if( *i > *j)
			j++;	
		
	    else{
	        temp.push_back(*i);
	    	i++;
	    	j++;
	    	it++;
	    }
	   
	}
	return temp;

}
// Selection sorted list
template <class T>
void selection_sort(list<T>& a)
{
    //from the first until the pre-last element
    typename list<T>::iterator itr   ; 
	
    for( itr = a.begin(); itr != (--a.end()); ++itr)
    {
        T* smallest = &(*itr);
        typename list<T>::iterator itr2  = itr;
        for(++itr2; itr2 != a.end(); ++itr2)
            if (*smallest > *itr2)
                smallest = &(*itr2);    
        T tmp = *itr;
        *itr = *smallest;
        *smallest = tmp;
    }
}
// Unorderd union list
template <class T>
list<T> unordered_union(const list<T> & a, const list<T> & b){

	return ordered_union(a,b);

}
// Unordred Intersection list 
template <class T>
list<T> unordered_intersect(const list<T> & a, const list<T> & b){

	return ordered_intersect(a,b);

}

int main()
{
	list<int> a ;
	a.push_back(5);
	a.push_back(10);
	a.push_back(12);
	a.push_back(14);
	a.push_back(15);

	list<int> b ;
	b.push_back(6);
	b.push_back(12);
	b.push_back(13);
	b.push_back(15);

	list<int> temp = ordered_union(a,b);
	list<int>::iterator it=temp.begin();
	assert(*it == 5); it++;
	assert(*it == 6); it++;
	assert(*it == 10); it++;
	assert(*it == 12); it++;
	assert(*it == 13); it++;
	assert(*it == 14); it++;
	assert(*it == 15); it++;

	list<int> temp2 = ordered_intersect(a,b);
	list<int>::iterator it2=temp2.begin();
	assert(*it2 == 12); it2++;
	assert(*it2 == 15);

    //Test selection sort algorithm
	list<int> c ;
	c.push_back(1);
	c.push_back(10);
	c.push_back(2);
	c.push_back(8);
	c.push_back(5);
	c.push_back(4);
	selection_sort(c);
	cout << "selection sort of list c " << endl;
	for(list<int> :: iterator itr = c.begin(); itr != c.end(); ++itr)
        cout << *itr << endl;
    list<int> d;
    d.push_back(1);
	d.push_back(3);
	d.push_back(2);
	d.push_back(9);
	d.push_back(5);
	d.push_back(4);
	selection_sort(d);
	cout << "selection sort of list d " << endl;
	for(list<int> :: iterator itr = d.begin(); itr != d.end(); ++itr)
        cout << *itr << endl;
    

    // Test unordered union list
    list<int> temp3 = unordered_union(c, d);
    list<int>::iterator it3=temp3.begin();
    assert(*it3==1); it3++;
    assert(*it3==2); it3++;
    assert(*it3==3); it3++;
    assert(*it3==4); it3++;
    assert(*it3==5); it3++;
    assert(*it3==8); it3++;
    assert(*it3==9); it3++;
    assert(*it3==10); it3++;

    cout << "Union list " << endl;
    for(list<int> :: iterator itr = temp3.begin(); itr != temp3.end(); ++itr)    
        cout << *itr << endl;
    

    list<int> temp4 = unordered_intersect(c, d);
    list<int>::iterator it4=temp4.begin();
    assert(*it4==1); it4++;
    assert(*it4==2); it4++;
    assert(*it4==4); it4++;
    assert(*it4==5); it4++;
   

    cout << "Intersect list" << endl;
    for(list<int> :: iterator itr = temp4.begin(); itr != temp4.end(); ++itr)
        cout << *itr << endl;
    

    cout << "SUCCESS" << endl;  
	return 0;
}


