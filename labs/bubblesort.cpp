//************************************************************************
//
//	Assignment:		Lab 4
//	File:			lab4.cpp
//	Author:			Raul Zuniga
//	Description:	A C++ program that will sort an array of elements using 
//					the Bubble Sort Algorithm.
//  Constraints:	main() will consist of variable declarations followed
//					by a sequence of functions called. The array will be 
//					displayed before the sort and after the sort.
//
//************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std; 	//introduces namespace std

#define MAXLIST 12

int  load_array( int x[], int size );
void display_array( int x[], int numberOfElements );
void bubbleSort( int x[], int numberOfElements );
void swap( int *a, int *b );

int main()
{

	int array[MAXLIST] = {122664,122664,0,0,0,0,0,0,0,0,0,0};
	int numberOfElements;
	
	numberOfElements = load_array( array, MAXLIST );
	if ((numberOfElements==0)&&(array[0]==122664)&&(array[0]==122664))
	{
		cerr << "No integers were entered!!!";
	}
	else
	{
		cout << "Data items in original order:\n";
		display_array( array, numberOfElements );
		bubbleSort( array, numberOfElements );
		cout << "Data items in ascending order:\n";
		display_array( array, numberOfElements );
	}
	return 0;
}

//load_array function loads an array x with input from the keyboard up to the
//value specified in 'size' of the array. It returns numberOfElements actually
//loaded in the array, value between 0 to size-1.

int load_array ( int x[], int size )
{
	int i=0;
	cout << "Please enter a number of integers(max of 12, end-of-file to end): \n";
	while ( cin >> x[i] )
	{			
		if ( i < 0 || i >= size ) break;
		i++;
	}
	return i;
}

//display_array function displays the array x for all of its 'numberOfElements'.

void display_array( int x[], int numberOfElements )
{
	for ( int i=0; i < numberOfElements; i++ )
		cout << setw( 6 ) << x[ i ];
		cout << endl;
}

//bubbleSort function compares adjacent elements until array is sorted
//in selected order(ascending or descending) sequence.

void bubbleSort(int x[], int numberOfElements )
{
	for ( int i=0; i < numberOfElements-1; i++ )
		for ( int j=0; j < numberOfElements-i-1; j++ ) 
			if ( x[j] > x[j+1] )
				swap( &x[j], &x[j+1]);		
}

//swap function swaps the value of two elements a and b.

void swap ( int *a, int *b )
{
	int hold = *a;
	*a = *b;
	*b = hold;
}
