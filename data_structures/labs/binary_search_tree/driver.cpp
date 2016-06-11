/* File Name: driver.cpp
 * Author: Raul Zuniga
*/

#include <iostream>
#include <string>
#include "bst_3358.h"
#include "heap_3358.h"

using namespace std;

void test_bst();
void test_heap();

int main() {
	test_bst();
	// test_heap();
	return 0;
}

void test_bst() {
	// test constructor: root is NULL
	BST_3358<int> bst;
	bst.inOrderTraversal();

	// test insertItem;
	bst.insertItem(4);
	bst.insertItem(2);
	bst.insertItem(1);
	bst.insertItem(3);
	bst.insertItem(6);
	bst.insertItem(5);
	bst.insertItem(7);
	bst.insertItem(NULL);
	// test for a duplicate
	bst.insertItem(2);

	// test inOrderTraversal: 0 1 2 3 5 4 6 7
	// should be no duplicates
	bst.inOrderTraversal();

	// test preOrderTraversal: 4 3 2 1 0 5 6 7
	bst.preOrderTraversal();

	// test findItem
	// test for item that is in the tree
	unsigned int item = 3;
	if (bst.findItem(item))
		cout << "Item " << item << " found!" << endl;
	else
		cout << "Item " << item << " not found!" << endl;

	// test for item that is not in the tree
	item = 8;
	if (bst.findItem(item))
		cout << "Item " << item << " found!" << endl;
	else
		cout << "Item " << item << " not found!" << endl;

	// test an empty tree
	item = 1;
	BST_3358<int> bst2;
	if (bst2.findItem(item))
		cout << "Item " << item << " found!" << endl;
	else
		cout << "Item " << item << " not found!" << endl;

	// test countNodes: 8
	cout << "Number of nodes: " << bst.countNodes() << endl;

	// test findMin: 0
	cout << "Min: " << bst.findMin() << endl;

	// test findMax: 7
	cout << "Min: " << bst.findMax() << endl;

	// test makeEmpty
	bst.makeEmpty();

	// tree should be empty
	bst.inOrderTraversal();

	BST_3358<int> bst3;

	// test destructor
	// should call makeEmpty & handle empty bst, bst2 trees
	// should deallocate bst3 tree
	bst3.insertItem(12);
	bst3.insertItem(11);
	bst3.insertItem(10);
	bst3.insertItem(9);
	bst3.insertItem(13);
	bst3.insertItem(14);
	bst3.insertItem(15);
}

void test_heap() {
	// test constructor
	Heap_3358<int> heap;
	Heap_3358<int> heap2;
	Heap_3358<int> heap3;
	Heap_3358<int> heap4;
	Heap_3358<int> heap5;

	heap.insertItem(13);
	heap.insertItem(21);
	heap.insertItem(16);
	heap.insertItem(24);
	heap.insertItem(31);
	heap.insertItem(19);
	heap.insertItem(68);
	heap.insertItem(65);
	heap.insertItem(26);
	heap.insertItem(32);

	heap.display();

	// test insertItem & percolateUp
	heap.insertItem(14);
	heap.display();

	// test findMin
	// test empty tree
	heap2.findMin();

	// test non-empty tree: 13
	cout << "Min = " << heap.findMin() << endl;

	// test deleteMin & percolateDown
	// delete from an empty tree
	heap2.deleteMin();

	// delete from non-empty tree
	heap3.insertItem(13);
	heap3.insertItem(14);
	heap3.insertItem(16);
	heap3.insertItem(19);
	heap3.insertItem(21);
	heap3.insertItem(19);
	heap3.insertItem(68);
	heap3.insertItem(65);
	heap3.insertItem(26);
	heap3.insertItem(32);
	heap3.insertItem(31);
	heap3.display();

	heap3.deleteMin();
	heap3.display();

	// test findMin
	cout << "Min = " << heap3.findMin() << endl;

	heap4.insertItem(13);
	heap4.deleteMin();
	heap4.display();

	heap5.insertItem(13);
	heap5.insertItem(14);
	heap5.display();

	heap5.deleteMin();
	heap5.display();

	// test makeEmpty
	heap3.makeEmpty();
	heap3.display();
}