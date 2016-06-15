// file NumberList.cpp
#include "numberlist.h"
#include <iostream>

using namespace std;

// constructor sets up empty list
NumberList::NumberList() {
    head = NULL;
}

/*
 * Pointers + dynamic allocation => deep copy
 * Don't copy any pointers (allocate new memory)
 * Iterate over src list, append nodes to the new list
 * Initialize head to NULL
 * For each item in the src list (in order) append value to the list
 */
NumberList::NumberList(const NumberList &src) {
    head = NULL;
    ListNode *p = src.head;
    while (p) {
        appendNode(p->value);
        p = p->next;
    }
}

/*
 *  Destructor: must deallocate all mondes used in the list
 *  To do this, use list traversal to visit each node.
 *  For each node save the address of the next node in a pointer.
 *  Delete the node and advance the pointer.
 */
NumberList::~NumberList() {
    ListNode *p = head;
    ListNode *n;
    while (p) {
        n = p->next;
        delete p;
        p = n;
    }
}

/*
 *  Append add new node to end of list
 *  Algorithm:
 *  1. Create a new node and store the data in it
 *  2. If the list has no nodes
 *          Make head point to the new node
 *     Else
 *          Find teh last node in the list
 *          Make the lst node point to the new node
 */
void NumberList::appendNode(double num) {
    
    ListNode *newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    
    if (head==NULL) {
        head = newNode;
    } else {
        ListNode *p = head;
        while (p->next)
            p = p->next;
        p->next = newNode;
    }
}

/*
 * 	insert:  Inserts a new node into the middle of a list.
 * 	Uses two extra pointers:
 * 	one to point to node before the insertion point
 * 	one to point to the node after the insertion point [this one is optional]
 *
 * 	Insert node in a certain position
 *
 * 	Create the new node, store the data in it
 * 	Use pointer p to traverse the list,
 * 	    until it points to: node after insertion point or  NULL
 * 	    as p is advancing, make n point to the node  before
 *  if p points to first node (p is head, n was not set)
 *      make head point to new node
 *      make new node point to p’s node
 *  else
 *      make n’s node point to new node
 *      make new node point to p’s node
 */

void NumberList::insertNode(double num) {

    ListNode *newNode = new ListNode;
    newNode->value = num;

    ListNode *p = head;
    ListNode *n = NULL;
    while (p && p->value < num) {
        n = p;
        p = p->next;
    }
    
    if (p==head) {
        head = newNode;
        newNode->next = p;
    } else {
        n->next = newNode;
        newNode->next = p;
    }
}

/*
 *  deleteNode: removes node from list, and deletes (Deallocates) the removed node.
 *  Requires two pointers:
 *      one to point to the node to be deleted
 *      one to point to the node before the node to be deleted.
 *      Change the pointer of the previous node to point to the node after the one to be deleted.
 *      Now just “delete” the p node
 *      use p to traverse the list, until it points to num or NULL
 *      as p is advancing, make n point to the node before it
 *
 *      if (p is not NULL) //found!
 *      if (p==head) //it’s the first node, and n is garbage
 *          make head point to the second element
 *          delete p’s node (the first node)
 *      else
 *          make n’s node point to what p’s node points to
 *          delete p’s node
 *      else: . . . p is NULL, not found do nothing
 */

void NumberList::deleteNode(double num) {
    ListNode *p = head;
    ListNode *n = NULL;
    while (p && p->value!=num) {
        n = p;
        p = p->next;
    }
    
    if (p) {
        if (p==head) {
            head = p->next;
            delete p;
        } else {
            n->next = p->next;
            delete p;
        }
    }
}

void NumberList::displayList() {
    ListNode *p = head;
    while (p) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

/*
 *  display
 *  Visit each node in a linked list, to display contents, sum data, test data, etc.
 *  Basic process:
 *      set a pointer to point to what head points to
 *      while pointer is not NULL
 *      process data of current node
 *      go to the next node by setting the pointer to the pointer field of the current node
 *      end while
 */

void NumberList::operator= (const NumberList &rhs) {

}

