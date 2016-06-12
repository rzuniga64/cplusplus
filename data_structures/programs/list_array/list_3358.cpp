// File Name: list_3358.h
//
// Implementation of a cursor-based List ADT
// This is a simple array implementation

#include <iostream>
#include <cassert>
using namespace std;

#include "list_3358.h"


List_3358::List_3358 ( ) {
    currentSize = 0;
    cursor = EOL;
}

//List_3358::List_3358 ( const List_3358 & src ) {
//  This is exactly what the default copy constructor does.
//    
//    cursor = src.cursor;
//    currentSize = src.currentSize;
//    
//    for (int i = 0; i < currentSize; i++)
//        values[i] = src.values[i];
//    
//}

//List_3358::~List_3358 ( ) {
//    //Do nothing, no dynamically allocated memory here
//}


void List_3358::insert (const int & item) {
    assert(!isFull());
    
    if (cursor == EOL)
        values[currentSize] = item;
    else {
        //shift elements after the cursor up by one
        for (int i = currentSize; i > cursor; i--)
            values[i] = values[i-1];
        //insert at cursor
        values[cursor] = item;
        //advance to successor
        cursor++;
    }
    
    // count is increased by one
    currentSize++;
}



void List_3358::remove() {
    assert(!atEOL() && !isEmpty());
    
    //shift elements after the cursor down by one
    for (int i=cursor; i < currentSize-1; i++)
        values[i] = values[i+1];
    
    //decrease number of elements
    currentSize--;
    
    //if the last item was removed, set cursor to EOL
    if (cursor==currentSize)
        cursor = EOL;
    
}


void List_3358::resetFront ( ) {
    if (!isEmpty())
        cursor = 0;
}

void List_3358::resetBack ( ) {
    if (!isEmpty())
        cursor = currentSize-1;
}



void List_3358::advance ( ) {
    if (cursor == EOL)
        return;
    
    if (cursor < currentSize-1)
        cursor++;
    else
        cursor = EOL;
    
}

void List_3358::backup ( ) {
    if (cursor == EOL)
        return;
    
    if (cursor > 0)
        cursor--;
    else
        cursor = EOL;
    
}



bool List_3358::isEmpty ( ) const {
    return currentSize == 0;
}



bool List_3358::atEOL ( ) const {
    return cursor == EOL;
}



bool List_3358::isFull ( ) const {
    return currentSize == MAX_ITEMS;
}



int List_3358::getCurrent ( ) const {
    assert(cursor != EOL);

    return values[cursor];    
}




