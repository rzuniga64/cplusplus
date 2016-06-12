#include <iostream>
#include <assert.h> 
#include <algorithm>	// needed for template <class T> void swap(T & a, T & b)

using namespace std;

/*
*	Searching in a sorted list is much easier thansearching in an unsorted list.
*	Most of the data displayed by computers is sorted.
*
*	Sorting is one of the most intensively studied operations in computer science
*	There are many different sorting algorithms. The run-time analyses of each algorithm are
*	well-known.
*	
*	Selection sort
*	Insertion sort
*	Bubble sort
*	Merge sort
*	Quicksort
*	Heap sort
*/

/*
*	Selection Sort
*	There is a pass for each position (0..size-1)
*	On each pass, the smallest (minimum) element
*	in the rest of the list is exchanged (swapped)
*	with element at the current position.
*
*	The first part of the list (already processed) is always sorted
*	Each pass increases the size of the sorted portion
*		Start		Pass 1		Pass 2		Pass 3		Pass 4
*	#	Data	#	Data	#	Data	#	Data	#	Data
*		   _					
*	0	36	|	0	6 _		0	6		0	6		0	6
*	1	24	|	1	24 |	1	10_		1	10		1	10
*	2	10	|	2	10 |	2	24 |	2	12_		2	12		
*	3	6  _|	3	36 |	3	36 |	3	36 |	3	24	
*	4	12		4	12_|	4	12_|	4	24_|	4	36
*						
*	N is the number of elements in the list
*	Outer loop (in selectionSort) executes N-1 times
*	Inner loop (in minIndex) executes N-1, then N-2, then N-3, ... then once.
*	Total number of comparisons (in inner loop)
*	(N+1) + (N+2) + ... + 2 + 1 = the sum of 1 to N-1
*	The sum from n=1 to n for k is n(n + 1) /2
*	(N+1) + (N+2) + ... + 2 + 1 = (n-1)(n-1+1)/2
*                               = (n2 - n)/2
*							    = n2/2 - n/2
*	efficiency of algorith is O(N2)
*/

	template<class ItemType>
int minIndex(ItemType values[], int size, int start) {
		int minIndex = start;
	for (int i = start+1; i < size; i++)
		if (values[i] < values[minIndex])
			minIndex = i;
	return minIndex;
}

	template<class ItemType>
void selectionSort (ItemType values[], ItemType size) {
	int min;
	for (int index = 0; index < (size -1); index++) {
		min = minIndex(values, size, index);
		swap(values[min],values[index]);
	}
}

/*
*	Insertion Sort
*	The front of the list remains sorted.
*	On each pass, the next element is placed in its
*	proper place among the already sorted elements.
*	Like playing a card game, if you keep your hand
*	sorted, when you draw a new card, you put it in
*	the proper place in your hand.
*	Each pass increases the size of the sorted portion
*
*		Start		Pass 1		Pass 2		Pass 3		Pass 4		Pass 5
*	#	Data	#	Data	#	Data	#	Data	#	Data	#	Date
*		   					
*	0	36		0	36_		0	24		0	10		0	6		0	 6
*	1	24		1	24 |	1	36_		1	24		1	10		1	10
*	2	10		2	10 |	2	10 |	2	36_		2	24		2	12
*	3	 6   	3	 6 |	3	 6 |	3	 6 |	3	36_		3	24
*	4	12		4	12_|	4	12_|	4	12_|	4	12_|	4	36
*														  	
*	Very similar to Selection sort
*	Total number of comparisons (in inner loop):
*	At most 1, then 2, then 3 ... up to N-1 for the last element
*	So it's (N+1) + (N+2) + ... + 2 + 1 = N2/2 - N/2
*	efficiency of algorith is O(N2)
*/

	template<class ItemType>
void insertionSort (ItemType a[], int size) {
	for (int index = 1; index < size; index++) {
		ItemType tmp = a[index]; // next element
		int j = index; // start from the end of sorted part
	
		// find tmp's place, AND shift bigger elements up
		while (j > 0 && tmp < a[j-1]) {
			a[j] = a[j-1]; // shift bigger element up
			j--;
		}
		a[j] = tmp; // put tmp in its place
	}
}

/*
*	Bubble Sort
*	On each pass:
*	Compare first two elements. If the first is bigger, they
*	exchange places (swap).
*
*	Compare second and third elements. If second is
*	bigger, exchange them. Repeat until last two elements of 
*	the list are compared.
*
*	Repeat this process until a pass completes with no exchanges
*	At the end of the first pass, the largest element is
*	moved to the end (it’s bigger than all its neighbors)
*
*	At the end of the second pass, the second largest
*	element is moved to just before the last element.
*	The back end (tail) of the list remains sorted.
*	Each pass increases the size of the sorted portion.
*	No exchanges implies each element is smaller
*	than its next neighbor (so the list is sorted)
*	
*	7 2 3 8 9 1  7 > 2, swap
*   - - 
*	2 7 3 8 9 1  7 > 3, swap
*     - - 
*	2 3 7 8 9 1  !(7 > 8), no swap
*       - - 
*	2 3 7 8 9 1  !(8 > 9), no swap
*		  - - 
*	2 3 7 8 9 1  9 > 1, swap
*           - -
*	2 3 7 8 1 9  finished pass 1, did 3 swaps 
*
*	2 3 7 8 1 9  2<3<7<8, no swap, !(8<1), swap
*         - - 
*	2 3 7 1 8 9  (8<9) no swap finished pass 2, did one swap
*
*	2 3 7 1 8 9  2<3<7, no swap, !(7<1), swap
*       - -
*	2 3 1 7 8 9  7<8<9, no swap finished pass 3, did one swap
*	2 3 1 7 8 9  2<3, !(3<1) swap, 3<7<8<9
*     - - 
*	2 1 3 7 8 9  finished pass 4, did one swap
*	2 1 3 7 8 9  !(2<1) swap, 2<3<7<8<9
*   - - 
*	1 2 3 7 8 9  finished pass 5, did one swap
*	1 2 3 7 8 9	 1<2<3<7<8<9, no swaps finished pass 6, no swaps, list is sorted!
*
*	Buble sort: runtime analysis
*	Each pass makes N-1 comparisons
*	There will be at most N passes
*	- one to move the right element into each position
*	So worst case it’s:(N-1)* N	O(N2)
*	If you change the algorithm to look at only the unsorted
*	part of the array in each pass, it’s exactly like the selection sort
*	What is the best case for Bubble sort?
*	(N+1) + (N+2) + ... + 2 + 1 = N2/2 - N/2
*	efficiency is still O(N2)
*	Are there any sorting algorithms better than O(N2)?
*/
template<class ItemType>
void bubbleSort (ItemType a[], int size) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < (size-1); i++) {
			if (a[i] > a[i+1]) {
			swap(a[i],a[i+1]);
			swapped = true;
			}
		}
	} while (swapped);
}


int main() {
	const int SIZE = 5;
	int array1[SIZE] = {24, 36, 10, 6, 12};
	selectionSort(array1, SIZE);
	cout << "Selection Sort:" << endl;
	for (int i=0; i < 5; i++) 
		cout << "i " << array1[i] << endl;
	cout << endl;

	int array2[SIZE] = {24, 36, 10, 6, 12};
	insertionSort(array2, SIZE);
	cout << "Insertion Sort:" << endl;
	for (int i=0; i < 5; i++) 
		cout << "i " << array2[i] << endl;
	cout << endl;

	int array3[SIZE] = {7,2,3,8,9};
	bubbleSort(array3, SIZE);
	cout << "Bubble Sort:" << endl;
	for (int i=0; i < 5; i++) 
		cout << "i " << array3[i] << endl;
	cout << endl;

	return 0;
}