#ifndef NUMBERLIST_H
#define NUMBERLIST_H

/**
 * A data structure representing a series of dynamically allocated nodes chained together in a sequence.
 * Each node points to another node.
 * Each nodes contains a data field (structure, object, etc) and a pointer that can point to another node.
 * A separate pointer (the head) points to the first item in the list.
 * The last element (the tail) points to nothing (NULL).
 * An empty list contains no nodes. The list head points to NULL
 *
 *  Operations:
 *  constructor:        creates an empty linked list
 *  append:             add a link to the end of the list
 *  insert:             add a node within the list
 *  delete:             delete a link
 *  display():          display the linked list
 *  copy constructor (and operator=)
 *
 * Advantages of linked lists over arrays
 * 1. A linked list can grow or shrink in size.
 * 2. The programmer doesn't need to predict how many values could be in teh list.
 * 3. The programmer doesn't need to resize and copy the list when it reaches a certain capacity.
 * 4. When a value is inserted into or deleted from a linked list, none of the other nodes have to be moved.
 */

#include <cstddef>   // for NULL

class   NumberList
{
private:
    struct ListNode    // a data type
    {
        double value;           // data
        struct ListNode *next;  // ptr to next node
    };
    ListNode *head;          // the list head
    
public:
    NumberList();
    NumberList(const NumberList &);
    
    ~NumberList();
    
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList();

    void operator= (const NumberList &);
};
#endif
