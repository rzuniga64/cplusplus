// File Name: list_test.cpp
//
// Tests the cursor-based list ADT

#include <iostream>
using namespace std;

#include "list_3358.h"

void showList(List_3358<int> myList);
bool search(List_3358<int> & myList, int target);

int main() {

	List_3358<int> myList;

	myList.insert(42);
	myList.insert(52);
	myList.insert(12);

	myList.resetFront();
	myList.diagnose();
	myList.insert(-42);
	myList.resetBack();
	myList.diagnose();
	myList.insert(2);

	cout << "test inserts" << endl;
	showList(myList);  // -42 42 52 2 12

	cout << endl;
	myList.resetFront();
	cout << "ResetFront, current is " << myList.getCurrent() << endl;

	cout << endl;
	myList.resetBack();
	cout << "ResetBack, current is " << myList.getCurrent() << endl;

	myList.advance();
	myList.insert(88);

	cout << "test insert at end" << endl;
	showList(myList);

	cout << "test getCurrent at EOL" << endl<< endl;
	while (!myList.atEOL()) {
		myList.advance();
	}

	myList.diagnose();

	//remove the comment marker, calling next function should fail
	//  cout << myList.getCurrent() << endl;


	myList.resetFront();
	myList.advance();
	myList.advance();

	int value = myList.getCurrent();
	cout << "mylist current value is: " << value << endl;

	List_3358<int> myList2 = myList; //copy constructor
	cout << "show mylist2 (copy constr)" << endl << endl;
	showList(myList2);

	value = myList2.getCurrent();
	cout << "mylist2 current value is: " << value << endl;

	myList.resetBack();
	myList.diagnose();

	cout << " test search" << endl;
	int target = 42;
	if (search(myList, target))
		cout << myList.getCurrent() << endl;
	else
		cout << target << " not found" << endl;

	myList.remove();

	cout << " test remove after search" << endl;
	showList(myList);

	cout << "show other list (test copy constructor) still has 42" << endl;
	showList(myList2);

	return 0;
}

//***********************************************************
// showList: displays the list, first to last element
// myList the list to display
// note that the list is passed by value, so the cursor remains unchanged
//  in the argument passed to this function.
//***********************************************************

void showList(List_3358<int> myList) {
	myList.resetFront();

	while (!myList.atEOL()) {
		cout << myList.getCurrent() << " ";
		myList.advance();
	}
	cout << endl;
}

//***********************************************************
// search: finds target in list and moves the cursor to that element
// myList the list to search
// target: the value to find
// returns true if found, false if not.
// list is passed by reference so that it can change the cursor
//  (if not found, cursor will be EOL)
//***********************************************************

bool search(List_3358<int> & myList, int target) {
	myList.resetFront();

	while (!myList.atEOL() && (target != myList.getCurrent()))
		myList.advance();

	if (!myList.atEOL())
		return true; //found it and cursor is placed on it
	else
		return false; //not found and cursor at end
}
