#ifndef LIST_3358_LL_H_
#define LIST_3358_LL_H_

// File name: stack_3358_LL.h
//
// a Stack ADT
//
// This implementation uses a linked list
// This implementation is a template

#include <assert.h>

using namespace std;

template<class ItemType>
class Stack_3358 {
    
public:
    //***********************************************************
    // Stack_3358: default constructor
    // Preconditions: None.
    // Postconditions: stack is empty.
    
    Stack_3358();
    
    //***********************************************************
    // Stack_3358: copy constructor
    // Preconditions: None.
    // Postconditions: New stack is created, which is a deep copy of src stack.

    Stack_3358(const Stack_3358 & src);
    
    //****************************
    // makeEmpty: Removes all the items from the stack.
    // Preconditions: None.
    // Postconditions: All the items have been removed

     void makeEmpty();
    
    //****************************
    // isEmpty: Checks to see if there are any items on the stack.
    // Preconditions: None.
    // Postconditions: Returns true if there are no items on the stack,
    //   else false.

    bool isEmpty() const;
    
    //****************************
    // isFull: Determines if you have any more room to add items to the stack.
    // Preconditions: None.
    // Postconditions: Returns true if there is no more room to add items,
    //   else false.

    bool isFull() const;
    
    //****************************
    // push: Adds newItem to the top of the stack.
    // Preconditions: Stack is not full.
    // Postconditions: newItem is at the top of the stack.

    void push(const ItemType &);
 	
    //****************************
    // pop: Removes topItem from stack and returns it.
    // Preconditions: Stack is not empty.
    // Postconditions: Top element has been removed from stack and a copy of the
    //    removed element is returned.

    ItemType pop();
private:
    struct Node {         // node type for singly-linked-list
        ItemType data;
        Node *next;
    };  
    
    Node *head;           // points to top of stack
}; 

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ()
{
    head = NULL;  
}

template<class ItemType>
Stack_3358<ItemType>::Stack_3358(const Stack_3358 & src)
{
    Node *srcPtr;         //traverses source list
    Node *ptr;            //points to last elem of this list

    head = NULL;
    
    // traverse src list, append each item to this list
    for (srcPtr = src.head; srcPtr != NULL; srcPtr = srcPtr->next) {
        Node *newNode = new Node;       //set up the new node
        newNode->data = srcPtr->data;
        newNode->next = NULL;
        
        if (head == NULL)               //make previous node point to new node
            head = newNode;
        else 
            ptr->next = newNode;
        
        ptr = newNode;    //advance ptr to last node in this list
    }
} 

template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty()
{
    while (!isEmpty())
        pop();
}

template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty() const
{  
    return (head == NULL);     
}

template<class ItemType>
bool Stack_3358 <ItemType>::isFull() const
{
    return false;
}


template<class ItemType>
void Stack_3358 <ItemType>::push(const ItemType& newItem)
{
    assert(!isFull());
    
    Node *temp=new Node;
    temp->data = newItem;
    
    //insert at head of list
    temp->next = head;
    head = temp;
}

template<class ItemType>
ItemType Stack_3358 <ItemType>::pop()
{
    assert(!isEmpty());
    
    ItemType value = head->data;
    
    // remove the first node (top)
    Node *temp = head;
    head = head->next;
    delete temp;
    
    return value;
}

#endif