#include <assert.h>

/*
* 	Create vector using a dynamically allocated array.
* 	It must be able to resize when the array is full.
* 	The following methods should be utilitized:
* 	- push_back
* 	- pop_back
* 	- operator[](int k);
*/

template <typename T>
class vector {
public:
	vector(int init_length = 8);
	int size();
	void push_back(T value);
	T pop_back();
	T operator[](int k);
private:
	T* data;
	int length;
	int capacity;
	void resize();
};

template <typename T>
vector<T>::vector(int init_length){
	length = init_length;
	data = new T[length];
	capacity = 0;
}

template <typename T>
int vector<T>::size() {
	return capacity;
}

template <typename T>
void vector<T>::push_back(T value) {
	if (capacity == length) 
		resize();
	data[capacity] = value;
	capacity++;
}

template <typename T>
T vector<T>::pop_back() {
	assert(capacity > 0);
	capacity--;
	return data[capacity];
}

template <typename T>
T vector<T>::operator[](int k) {
	assert(k >= 0 && k < length);
	return data[k];
}

template <typename T>
void vector<T>::resize() {
	length *= 2;
	T* temp = new T[length];
	for (int i = 0; i < capacity; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
}