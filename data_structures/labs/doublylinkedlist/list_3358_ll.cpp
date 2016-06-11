// File Name: list_3358_ll.h
//
// Author: Raul Zuniga
// This class implements the list_3358 interface using a doubly-linked list

#include <iostream>
#include <cassert>
#include "list_3358_ll.h"

using namespace std;

List_3358::List_3358() {
	cursor = NULL;
	head = NULL;
	tail = NULL;
}

List_3358::List_3358(const List_3358 & src) {
	cursor = NULL;
	head = NULL;
	tail = NULL;
	// to contruct a copy of the list
	for (Node *p = src.head; p != NULL; p = p->next) {
		insert(p->value);
	}
	// to put this->cursor in the right position
	if (src.cursor) {//then the list isn't empty and cursor isn't null
		cursor = head;
		for (Node *p = src.head; p != src.cursor; p = p->next) {
			advance();
		}
	}
}

List_3358::~List_3358() {
	Node *n;			// node pointing ahead of p into the list
	Node *p = head;		// node traveersing the list	
	while (p != NULL) {
		n = p->next;
		delete p;
		p = n;
	}
}

void List_3358::insert(const int & item) {
	assert(!isFull());

	// make a new node, set value
	Node *p = new Node;
	p->value = item;

	if (cursor == NULL) {
		// new node  is th enew tail (append)
		if (tail == NULL) {		// adding to empty list
			p->previous = NULL;
			head = p;
		}
		else {				// make old tail point to new
			p->previous = tail;
			tail->next = p;
		}
		p->next = NULL;
		tail = p;				// update tail to point to new node
	}
	else {
		// new node takes place of current/cursor
		if (head == cursor) {	// add to front of list
			p->previous = NULL;
			head = p;	
		} else {				// add to middle of list
			Node* before = cursor->previous;
			p->previous = before;
			before->next = p;
		}
		cursor->previous = p;
		p->next = cursor;
	}
}

void List_3358::remove() {
	assert(!atEOL() && !isEmpty());

	Node* before = cursor->previous;	// points to node before cursor
	Node* after = cursor->next;			// points to node after cursor

	// reset boefore's next pointer
	if (before == NULL) {				// cursor is on first item
		head = after;
	}
	else {
		before->next = after;
	}
	// reset after's previous pointer
	if (after == NULL) {				// cursor is on last item
		tail = before;
	} else {
		after->previous = before;
	}
	Node* p = cursor;					// save for delete
	cursor = after;

	// deallocate the node we removed
	delete p;
}

void List_3358::diagnose() {
	Node *h;
	Node *t;

	cout << "forwards: ";
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

void List_3358::resetFront(){
	cursor = head;
}

void List_3358::resetBack() {
	cursor = tail;
}

void List_3358::advance() {
	if (cursor)							// not EOL
		cursor = cursor->next;
}

void List_3358::backup() {
	if (cursor)							// not EOL
		cursor = cursor->previous;
}

bool List_3358::isEmpty() const {
	return (head == NULL);
}

bool List_3358::atEOL() const {
	return cursor == NULL;
}

bool List_3358::isFull() const {
	return false;
}

int List_3358::getCurrent() const {
	assert(cursor != NULL);

	return cursor->value;
}