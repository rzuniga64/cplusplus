//File name: queue_test.cpp
//
//tests the  Queue ADT
//

#include <iostream>
#include "queue_3358_ll.h"

using namespace std;

template <typename itemType>
void showQueue(Queue_3358 <itemType> & myQueue);

int main () {
    
    Queue_3358 <int> myQueue;
    
    Queue_3358 <char> s;
    
    if (myQueue.isEmpty())
        cout << "int queue is empty" << endl;
    else
        cout << "int queue is not empty" << endl;   
    
    s.enqueue('Y');
    cout << "The char queue: " << endl;
    showQueue(s);
    
    myQueue.enqueue(42);
    
    
    if (myQueue.isEmpty())
        cout << "int queue is empty" << endl;
    else
        cout << "int queue is not empty" << endl;   
    
    myQueue.enqueue(52);
    
    myQueue.enqueue(12);
    
    cout << "test enqueues to int queue" << endl;  
    showQueue(myQueue);
    
    Queue_3358 <int> myQueue2 = myQueue; //copy constructor
    
    myQueue.dequeue();
    
    myQueue.dequeue();
    
    cout << "test dequeues from original int queue" << endl;  
    showQueue(myQueue);
    
    cout << "show copied Queue, tests copy constructor" << endl;
    showQueue(myQueue2);
    
}   


//prints Queue.

template <typename itemType>
void showQueue(Queue_3358 <itemType> & myQueue) {
    
    //Note: this uses the copy constructor to initialize temp
    Queue_3358 <itemType> temp = myQueue;
    
    cout << "queue from front " << endl;
    while (!temp.isEmpty()) {
        cout << temp.dequeue() << endl;
        
    }
    cout << endl;
    
}


