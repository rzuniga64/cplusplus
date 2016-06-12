// file NumberList.cpp
#include "numberlist.h"
#include <iostream>

using namespace std;

NumberList::NumberList() {
    head = NULL;
}

NumberList::NumberList(const NumberList &src) {
    head = NULL;
    ListNode *p = src.head;
    while (p) {
        appendNode(p->value);
        p = p->next;
    }
}

NumberList::~NumberList() {
    ListNode *p = head;
    ListNode *n;
    while (p) {
        n = p->next;
        delete p;
        p = n;
    }
}

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

void NumberList::operator= (const NumberList &rhs) { }

