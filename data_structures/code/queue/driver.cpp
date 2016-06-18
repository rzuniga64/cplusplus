#include <iostream>
#include "queueArray.h"

using namespace std;

template < typename T > 
void showQueue(queue<T> & myQueue);

int main() {

	queue<int> myQueue;
	queue<char> s;

	if (myQueue.isEmpty())
		cout << "int queue is empty" << endl;
	else
		cout << "int queue is not empty" << endl;

	s.enqueue('Y');
	cout << "the char queue " << endl;
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

	queue<int> myQueue2 = myQueue; // copy constructor

	myQueue2.dequeue();
	myQueue2.dequeue();

	cout << "test dequeues from original int queue" << endl;
	showQueue(myQueue);

	cout << "show copied Queue, tests copy constructor" << endl;
	showQueue(myQueue2);

	return 0;
}

template <typename T>
void showQueue(queue<T> & myQueue) {
	// Note: this uses the copy constructor to initialize temp;
	queue<T> temp = myQueue;

	cout << "queue from front " << endl;
	while (!temp.isEmpty()) 
		cout << temp.dequeue() << endl;
	cout << endl;

}