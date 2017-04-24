/**************************************************************************************************
 * Hau Tao
 * select.cpp
 * 01/26/2016
 * This program implement the selection sort
 *The algorithm divides the input list into two parts: the sublist of items already sorted,
 *which is built up from left to right at the front (left) of the list, and the sublist of
 *items remaining to be sorted that occupy the rest of the list. Initially, the sorted
 *sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds
 * by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist,
 * exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order)
 *and moving the sublist boundaries one element to the right.
 **************************************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
void print_out(vector<int>&v);
void selection_sort(vector<int>&v,int n );
void random_vector( vector<int>& v, int n);

main()
{
	int n;
	cout << "Enter your size (n): \n";
	cin >> n;
	vector<int> v(n);
	srand(time(0));
	random_vector(v,n);
	selection_sort(v, n);
	print_out(v);

	
}
// selection sort algorithm
void selection_sort(vector<int>&v, int n )
{
	for ( int i = 0; i< n-1; i++){
		for( int j =i+1; j< n; ++j){
			if(v.at(i)>v.at(j))
				swap(v.at(i), v.at(j));

		}
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
