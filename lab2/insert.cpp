/**************************************************************************************************
 * Hau Tao
 * buble.cpp
 * 01/26/2016
 * This program implement the insertionsort
 *Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
 * Each iteration, insertion sort removes one element from the input data, finds the location it belongs 
 *within the sorted list, and inserts it there. It repeats until no input elements remain.
 **************************************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
void print_out(vector<int>&v);
void insertion_sort( vector<int>&v, int n);
void random_vector( vector<int>& v, int n);

main()
{
	int n;
	cout << "Enter your size (n): \n";
	cin >> n;
	vector<int> v(n);
	srand(time(0));
	random_vector(v,n);
	insertion_sort(v,n);
	print_out(v);
	


	
}


// insertion sort algorithm
void insertion_sort( vector<int>&v, int n)
{
	int elem, j;
	for (int i = 1; i < n; i++){
		for (  elem = v.at(i),  j = i-1; j >= 0 && elem < v.at(j); j--)
        	v.at(j+1) = v.at(j);
        v.at(j+1) = elem;
		
   			

	}
}

// print out the sorted vector
void print_out(vector<int>&v)
{
	for( int i =0; i< v.size(); i++)
		cout << v.at(i)<<endl;
}
// create the random number vector
void random_vector( vector<int> &v, int n)
{
	for( int i =0; i< n; i++)
		v.at(i) = rand()/1000000;
}
