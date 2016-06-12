#ifndef QUEUE_3358_H
#define QUEUE_3358_H

// File name: queue_3358_LL.h
//
// a Queue ADT
// This implentation uses a linked list
// This implementation is a template


#include <assert.h>

using namespace std;

template<class ItemType>
class Queue_3358 {
public:
    
    //***********************************************************
    // Queue_3358: default constructor
    // Preconditions: None.
    // Postconditions: stack is empty.
    
    Queue_3358();
    
    //***********************************************************
    // Queue_3358: copy constructor
    // Preconditions: None.
    // Postconditions: New queue is created, which is a deep copy of src queue.

    Queue_3358(const Queue_3358 & src);
    
    //***********************************************************
    // makeEmpty: Removes all the items from the queue.
    // Preconditions: Queue has been initialized
    // Postconditions: All the items have been removed

    void makeEmpty();
    
    //***********************************************************
    // isEmpty: Function: Checks to see if there are any items in the queue.
    // Preconditions: Queue has been initialized
    // Postconditions: Returns true if there are no items in the queue, else false
    
    bool isEmpty() const;
    
    //***********************************************************
    // isFull: Determines if you have any more room to add items to the queue
    // Preconditions: Queue has been initialized
    // Postconditions: Returns true if there is no more room to add items, else false

    bool isFull() const;
    
    //***********************************************************
    // enqueue: Adds newItem to the end (rear) of the queue.
    // Preconditions: Queue has been initialized and is not full.
    // Postconditions: newItem is at the rear of the queue.

    void enqueue(const ItemType &);
 	
    //***********************************************************
    // dequeue: Removes item from front of queue and returns it.
    // Preconditions: Queue has been initialized and is not empty.
    // Postconditions: front element has been removed from queue and item is a
    //   copy of the removed element.

    ItemType dequeue();
    
    
private:
    struct Node {         // node type for singly-linked-list
        ItemType data;
        Node *next;
    };  
    
    Node *front;           // points to front of queue
    Node *rear;            // points to rear of queue
    
}; 

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Queue_3358<ItemType>::Queue_3358 ()
{
    front = rear = NULL;  
}

template<class ItemType>
Queue_3358<ItemType>::Queue_3358(const Queue_3358 & src)
{

    front = rear = NULL;
    
    // iterate over source list and enqueue each item to this
    Node *sptr;
    for (sptr = src.front; sptr != NULL; sptr = sptr->next)
        enqueue (sptr->data);
} 


template<class ItemType>
void Queue_3358 <ItemType>::makeEmpty()
{
    while (!isEmpty())
        dequeue();
}

template<class ItemType>
bool Queue_3358 <ItemType>::isEmpty() const
{  
    return (front == NULL);     
}

template<class ItemType>
bool Queue_3358 <ItemType>::isFull() const
{
    return false;
}

template<class ItemType>
void Queue_3358 <ItemType>::enqueue(const ItemType& newItem)
{
    assert(!isFull());
    
    Node *temp=new Node;
    temp->data = newItem;
    temp->next = NULL;
    
    //empty queue is a special case
    if (isEmpty()) 
        rear = front = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}


template<class ItemType>
ItemType Queue_3358 <ItemType>::dequeue()
{
    assert(!isEmpty());
    
    ItemType value = front->data;
    
    // remove the first node (top)
    Node *temp = front;
    front = front->next;
    delete temp;
    
    // if we just removed the last node, set rear to null
    if (front==NULL)
        rear=NULL;
    
    return value;
}

#endif
