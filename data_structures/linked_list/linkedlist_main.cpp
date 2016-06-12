//ListDriver.cpp: using NumberList

#include <iostream>
#include "numberlist.h"

using namespace std;

int main() {
    
    // set up the list
    NumberList list;
    
    //Append Some values to the list
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    
    //  copy constructor:
    NumberList list2 (list);
    
    // insert:
    list.insertNode(1.5);
    
    // Display the values in the list
    list.displayList();
    
//    // Demo delete:
    cout << endl << "remove 7.9:" << endl;
    list.deleteNode(7.9);
    list.displayList();
    
    cout << endl << "remove 8.9: " << endl;
    list.deleteNode(8.9);
    list.displayList();
    
    cout << endl << "remove 2.5: " << endl;
    list.deleteNode(2.5);
    list.displayList();
//
//    
//    // copy constructor (after deletes)
    cout << endl << "copy of original list (before insert): " << endl;
    list2.displayList();
    
    return 0;
}