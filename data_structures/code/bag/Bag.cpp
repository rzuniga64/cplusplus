#include "Bag.h"

Bag::Bag() {
	count = 0;
	capacity = INCREMENT;
	data = new int[capacity];
}

Bag::Bag(const Bag &rhs) {
	data = new int[rhs.capacity];
	capacity = rhs.capacity;
	count = rhs.count;
	for (int i = 0; i < count; i++) {
		data[i] = rhs.data[i];
	}
}

Bag::~Bag() {
	delete[] data;
}

void Bag::add(int element) {
	// if count is at the capacity, resize
	if (count == capacity) {
		capacity += INCREMENT;
		int *newData = new int[capacity];	// new array
		for (int i = 0; i < count; i++) {	// copy values
			newData[i] = data[i];		
		}
		delete[] data;						// delete old array
		data = newData;
	}

	data[count] = element;					//add new element
	count++;
}

void Bag::remove(int element) {
	int index = -1; // change to position if found
	for (int i = 0; i < count && index == -1; i++) {
		if (data[i] == element)
			index = i;
	}

	if (index != -1) { // found, replace w/ last elem
		data[index] = data[count - 1];
		count--;
	}
}

int Bag::occurrences(int element) const {
	int occurrences = 0;
	for (int i = 0; i < count; i++) {
		if (data[i] == element) {
			occurrences++;
		}
	}
	return occurrences;
}

bool Bag::isEmpty() const {
	return (count == 0);
}

int Bag::size() const {
	return count;
}

void Bag::operator=(int element) {

}