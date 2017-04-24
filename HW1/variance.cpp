/************************************************************************************************
 * Hau Tao
 * variance.cpp
 * 01/31/2016
 * Description: This program calculates the variance and average, and the number of user input
 * Algorithm : user input the value to the array, and calculate the average and variance value
 * based on the formula given below:
 * Average = total value of each elemnt in array divided by size of array
 * Variance = sum of the squares of the differences of each element divided by size of array


 ************************************************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
float average(float*, int );
float variance (float *, int );

main()
{
    int in,b[101];
	float a[100];
	int count = 0; // count the number of input
	cin >> in ;
	while(!cin.eof()){	
		a[count] = in;
		++count;

		cin >> in;	
	}
	// handle the error when input = 0, 1 , or >100
	try{
	    cout <<"The number of input is: "<< count<< endl;
		cout <<"The average value is: "<< average(a,count)<< endl;
		cout <<"The variance value is: " <<variance(a,count)<< endl;

	}catch(const char* msg){
		cerr << msg << endl;

	}
	

}

// Calculate the average value of input
float average(float *a, int n){
	float total = 0.0;
	if (n==0 || n==1||n>100)
			throw "Try again\n";
	for(int i = 0; i < n ; i++)
		total +=a[i];
	return total/n;


}
// Calculate the variance value of input
float variance (float *a, int n){
	float sum_of_squares_differences = 0.0;
	if (n==0 || n==1||n>100)
			throw "Try again\n";
	for(int i =0; i < n ; i++)
		sum_of_squares_differences += pow((a[i]-average(a,n)),2);
	return sum_of_squares_differences/(n-1);

}

