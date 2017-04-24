
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void adjust_heap(vector<T>&v1, unsigned heapSize, unsigned position){
	typename vector<T> ::iterator start  =v1.begin();
	while(position < heapSize){
		unsigned int childpos = position *2+1;
		if(childpos < heapSize){
			if(childpos +1 < heapSize && start[childpos+1] > start[childpos])
				childpos++;
			if(start[position]>start[childpos] )
				return;
			else
				swap(start[position], start[childpos]);

		}
		position = childpos;
			
	}
}
template <class T>
void make_heap(vector<T>&v1){
	typename vector<T>::iterator start  = v1.begin(), stop= v1.end();
	unsigned int heapSize = stop-start;
	for(int i =heapSize/2;i>=0;i--)
		adjust_heap(v1,heapSize,i);
}
template <class T>
void sort_heap(vector<T>&v1){
	typename vector<T>::iterator start  = v1.begin(), stop= v1.end();
	unsigned int lastPosition = stop - start -1;
	while(lastPosition > 0){
		swap(start[0], start[lastPosition]);
		adjust_heap(v1, lastPosition, 0);
		lastPosition--;
	}
}
template <class T>
void heap_sort(vector<T>&v1){
	make_heap(v1);
	sort_heap(v1);
}
int main()
{   // integer input
	vector<int> v1;
	
	int input;

	while(cin >> input ){
		v1.push_back(input);
	}
	heap_sort(v1);
	cout << "Heap sort (integer input):"<< endl;
	for (vector<int>::iterator it = v1.begin() ; it != v1.end(); ++it)
    	cout << ' ' << *it;
    cout << endl;

    // string input
    cin.clear();
    vector<string> v2;
	
	string s;

	while(cin >> s ){
		v2.push_back(s);
	}
	heap_sort(v2);
	cout << "Heap sort (string input):";
	for (vector<string>::iterator it = v2.begin() ; it != v2.end(); ++it)
    	cout << ' ' << *it;
    cout << endl;
}