// File Name: list_3358_ll.h
//
// Author: Raul Zuniga
// Date: 3/19/2014
// Assignment Number: 2
// CS3358 Sprint 2015
// Instructor: Jill Seaman
//
// A cursor based List ADT
//
// The elements in the collection are all of the same type.
// -It has a finite length (the number of elements).
// -The elements are arranged sequentially:
// o There is a first element and a last element
// o Every element except the last has a unique successor
// o Every element except the first has a unique predecessor
// It has a current position, called the cursor, which points to either
// -one of the elements in the collection OR
// -none of the elements.  This is called EOL (End Of List).
//
// This class implements the list_3358 interface using a doubly-linked list

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class List_3358 {
private:

	// Node type for doubly linked list.
	struct Node {
		T value;
		Node* next;
		Node* previous;
	};

	Node* head;       // first element
	Node* tail;       // last element
	Node* cursor;     // current element

public:
	//***********************************************************
	// List_3358: default constructor
	// Preconditions: None.
	// Postconditions: list is empty, cursor at EOL.
	List_3358();

	//***********************************************************
	// List_3358: copy constructor
	// Preconditions: None
	// Postconditions: New list is created, which is a deep copy of src List.
	//   Cursor position is preserved.
	List_3358(const List_3358 & src);

	//***********************************************************
	// ~List_3358: destructor
	// Preconditions: None.
	// Postconditions: List is destroyed, if dynamically allocated.
	~List_3358();

	//************************************
	// insert:
	// Preconditions: List is not full.
	// Postconditions: The item has been inserted into the list, the cursor
	//   points to the same element it did before the insert.
	//   The new item is the predecessor of the element at the cursor.
	//   If the cursor is at EOL, the new item is the last element.
	void insert(const int & item);

	//************************************
	// remove:
	// Preconditions: Cursor is not at EOL and list is not empty.
	// Postconditions: The item at the original cursor is removed from the list.
	//   The cursor points to that item's successor,
	//   or EOL if the removed item was the last element in the list.
	void remove();

	//************************************
	// diagnose:
	// Preconditions: none
	// Postconditions: Determines if all the links and member variable 
	// pointers correctly after performing a given operation.  It is 
	// called from the driver on the list after a call to a member function
	// on the list (like insert).  It prints -11 for NULL
	void diagnose();

	//************************************
	// resetFront:
	// Preconditions: None.
	// Postconditions: Cursor points to the first element in the list,
	//   or EOL if the list is empty.
	void resetFront();

	//************************************
	// resetBack:
	// Preconditions: None.
	// Postconditions: Cursor points to the last element in the list.
	//   or EOL if the list is empty.
	void resetBack();

	//************************************
	// advance:
	// Preconditions: None.
	// Postconditions: Cursor points to the successor of the element it was
	//   previously pointing to.  If it was the last element, it is now EOL.
	//   If it was EOL, it remains EOL.
	void advance();

	//************************************
	// backup:
	// Preconditions: None.
	// Postconditions: Cursor points to the predecessor of the element it was
	//   previously pointing to.  If it was the first element, it is now EOL.
	//   If it was EOL, it remains EOL.
	void backup();

	//*******************
	// isEmpty:
	// Preconditions: None.
	// Postconditions: Returns true if the list contains no elements,
	//   and false otherwise.
	bool isEmpty() const;

	//*******************
	// atEOL:
	// Preconditions: None.
	// Postconditions: Returns true if the cursor is at EOL,
	//   and false otherwise.
	bool atEOL() const;

	//*******************
	// isFull:
	// Preconditions: None.
	// Postconditions: Return value is true if the list contains its capacity
	//  of elements, and false otherwise.
	bool isFull() const;

	//*******************
	// getCurrent:
	// Preconditions: Cursor is not at EOL.
	// Postconditions: Returns a copy of the element at the cursor.
	int getCurrent() const;
};

template <typename T>
List_3358<T>::List_3358() :head(NULL), tail(NULL), cursor(NULL){}

template <typename T>
List_3358<T>::List_3358(const List_3358 & src) {
	cursor = head = tail = NULL;

	// to contruct a copy of the list
	for (Node *p = src.head; p != NULL; p = p->next) {
		insert(p->value);
	}

	// to put this->cursor in the right position
	if (src.cursor) {	// then the list isn't empty and cursor isn't null
		cursor = head;
		for (Node *p = src.head; p != src.cursor; p = p->next) {
			advance();
		}
	}
}

template <typename T>
List_3358<T>::~List_3358() {
	Node* n;
	resetFront();
	while (cursor) {
		n = cursor->next;
		delete cursor;
		cursor = n;
	}
}

template <typename T>
void List_3358<T>::insert(const int & item) {
	assert(!isFull());

	// Create a new node and set the value of item 
	Node *newNode = new Node;
	newNode->value = item;
	newNode->next = NULL;
	newNode->previous = NULL;

	//resetFront();
	// Find the node where new node will be inserted
	//while (cursor && cursor->value < item) {
	//	cursor = cursor->next;
	//}

	if (cursor == NULL) {
		// new node  is the new tail (append)
		if (tail == NULL) {				// list is empty
			head = newNode;
		}
		else {							// cursor points to EOL
			tail->next = newNode;		// make old tail point to new
			newNode->previous = tail;
		}
		tail = newNode;					// update tail to point to new node
		tail->next = NULL;
	}
	else {
		// new node takes place of current/cursor
		if (cursor == head) {			// add to front of list
			head = newNode;
			head->previous = NULL;
			// Insert when cursor points to a node between head and tail
		}
		else {							// add to middle of list
			Node *before = cursor->previous;
			newNode->previous = before;
			before->next = newNode;
		}
		cursor->previous = newNode;
		newNode->next = cursor;
	}
}

template <typename T>
void List_3358<T>::remove() {
	assert(!atEOL() && !isEmpty());

	Node* before = cursor->previous;	// points to node before cursor
	Node* after = cursor->next;			// points to node after cursor

	// reset before's next pointer
	if (cursor == head)
		head = after;
	else
		before->next = after;

	// reset after's previous pointer
	if (cursor->next == NULL)			// cursor is on the last item
		tail = before;
	else
		after->previous = before;

	Node *p = cursor;					// save for delete
	cursor = after;

	// deallocate the node we removed
	delete p;
}

template <typename T>
void List_3358<T>::diagnose() {
	Node *h;
	Node *t;

	cout << endl << "forwards: ";
	for (h = head; h != NULL; h = h->next) {
		cout << h->value << "  ";
	}
	cout << endl;
	cout << "backwards: ";
	for (t = tail; t != NULL; t = t->previous) {
		cout << t->value << "  ";
	}
	cout << endl << endl;
	cout << "head: " << (head ? head->value : -11) << endl;
	cout << "tail: " << (tail ? tail->value : -11) << endl;
	cout << "cursor: " << (cursor ? cursor->value : -11) << endl << endl;
}

template <typename T>
void List_3358<T>::resetFront(){
	cursor = head;
}

template <typename T>
void List_3358<T>::resetBack() {
	cursor = tail;
}

template <typename T>
void List_3358<T>::advance() {
	if (cursor)							// not EOL
		cursor = cursor->next;
}

template <typename T>
void List_3358<T>::backup() {
	if (cursor)							// not EOL
		cursor = cursor->previous;
}

template <typename T>
bool List_3358<T>::isEmpty() const {
	return head == NULL;
}

template <typename T>
bool List_3358<T>::atEOL() const {
	return cursor == NULL;
}

template <typename T>
bool List_3358<T>::isFull() const {
	return false;
}

template <typename T>
int List_3358<T>::getCurrent() const {
	assert(cursor != NULL);
	return cursor->value;
}