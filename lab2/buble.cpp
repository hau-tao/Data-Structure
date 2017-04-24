/**************************************************************************************************
 * Hau Tao
 * buble.cpp
 * 01/26/2016
 * This program implement the bubble sort
 * The bubble sort makes multiple passes through a list. It compares adjacent items and exchanges 
 * those that are out of order. Each pass through the list places the next largest value in its proper
 * place. In essence, each item “bubbles” up to the location where it belongs.
 **************************************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
void print_out(vector<int>&v);

void buble_sort (vector<int>&v, int n);

void random_vector( vector<int>& v, int n);

main()
{
	int n;
	cout << "Enter your size (n): \n";
	cin >> n;
	vector<int> v(n);
	srand(time(0));
	random_vector(v,n);
	buble_sort(v,n);
	print_out(v);
	


	
}

// buble sort algorithm
void buble_sort (vector<int>&v, int n)
{
	for (int i = n-1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (v.at(j)> v.at(j+1))
            	swap(v.at(j), v.at(j+1));

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
