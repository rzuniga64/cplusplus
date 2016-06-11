
// File Name: heap_3358.h
//
// Author: Jill Seaman and ...
// Date: 4/21/15
// Assignment Number: 6
// CS 3358 Spring 2015
// Instructor: Jill Seaman
//
// A binary heap

#include <algorithm>

using namespace std;

template<class ItemType>
class Heap_3358 {
public:
    
    //Constructor
    Heap_3358();
    
    /****************************
     makeEmpty
     
     Function: Removes all the items from the heap.
     Postconditions: All the items have been removed/deallocated
     *****************************/
    void makeEmpty();
    
    /****************************
     insertItem
     
     Function: Adds newItem to the heap.
     Postconditions: newItem is in the proper position for a heap.
     *****************************/
    void insertItem(const ItemType &);
    
    /****************************
     findMin
     
     Function: Finds minimum element in heap.
     Preconditions: heap has at least one node.
     Postconditions: Returns the smallest element in the heap.
     *****************************/
    ItemType findMin();
    
    /****************************
     deleteMin
     
     Function: Removes minimum element from heap.
     Preconditions: heap has at least one node.
     Postconditions: Smallest element has been removed from heap, and it's
                     still a heap.
     *****************************/
    void deleteMin();
    
    /****************************
     display
     
     Function: for diagnostic purposes, displays the tree like this 
     (positions in array are shown):
     1
     2 3
     4 5 6 7
     8 9 10 11 12 13 14 15
     etc.
     *****************************/

    void display();
    
private:
    int size;
    ItemType array[100];
    
    // Given a position in the array, percolate that element up into place
    void percolateUp(int);
    // Given a position in the array, percolate that element down into place
    void percolateDown(int);
    
};

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Heap_3358<ItemType>::Heap_3358() : size(0)
{
}

template<class ItemType>
void Heap_3358 <ItemType>::makeEmpty()
{
	size = 0;
}

template<class ItemType>
ItemType Heap_3358 <ItemType>::findMin()
{
	if (size == 0) {
		try {
			throw _MM_EXCEPT_UNDERFLOW;
		} catch (int e) {
			cerr << "findMin exception: tree is empty, error: " << e << endl;
			return 0;
		}
	} else
		return array[1];
}

template<class ItemType>
void Heap_3358 <ItemType>::insertItem(const ItemType& newItem)
{
    // place newItem at end of tree
	array[++size] = newItem;

	// use percolate up to move to proper place
	percolateUp(loc);
}

template<class ItemType>
void Heap_3358 <ItemType>::percolateUp(int loc) {

	// if array[loc] is greater than its parent: done
	if (array[loc] >= array[loc / 2])
		return;
	// else swap array[loc] with parent, repeat on the parent
	else if (array[loc] < array[loc / 2]) {
		swap(array[loc], array[loc / 2]);
		percolateUp(loc/2);
	}
}

template<class ItemType>
void Heap_3358 <ItemType>::deleteMin()
{
	if (size == 0)
		return;

	// move last item to top, use percolate down to move it to proper place
	if (size > 1)
		array[1] = array[size--];
	percolateDown(1);
}

template<class ItemType>
void Heap_3358 <ItemType>::percolateDown(int loc) {
    
	int left  = 2 * loc;		//calculate index of left child
	int right = 2 * loc + 1;	//calculate index of right child
    
	if (left > size) 			// no children
		return;

    if (left == size) {			// one child
		// compare array[loc] to array[left], swap if needed
		if (array[loc] > array[left]) 
			swap(array[loc], array[left]);
		return;
    }
    
	if (left < size) { //two children:
		// if both children are greater than the parent: done
		if (array[left] > array[loc] && array[right] > array[loc])
			return; 
		// otherwise, swap the smaller of the two children with the parent
		if (array[left] < array[right] && array[left] < array[loc]) {
			swap(array[left], array[loc]);
			percolateDown(left);
		}
		else if (array[right] < array[left] && array[right] < array[loc]) {
			swap(array[right], array[loc]);
			percolateDown(right);
		}
	}
}

// Provided:
template<class ItemType>
void Heap_3358 <ItemType>::display () {
    for (int i=1; i<=size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " " ;
    }
    cout << endl;
}

    
