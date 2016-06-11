#include "stats.h"
#include <iostream>

using namespace std;

Stats::Stats() 
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		statsArr[i] = 0;
	capacity = 0;
}

void Stats::display() {

	cout << "capacity of array is " << capacity << endl;
	cout << "array values are: ";
	for (int i = 0; i < capacity; i++)
		cout << statsArr[i] << " ";
	cout << endl;
}

double Stats::getCapacity() {
	return capacity;
}

bool Stats::storeValue(double value) {
	bool isStored = false;

	if (capacity < ARRAY_SIZE) {
		statsArr[capacity] = value;
		isStored = true;
		capacity++;
	}
	else if (capacity >= ARRAY_SIZE)
		isStored = false;

	return isStored;
}

double Stats::total() {
	double total = 0.0;
	for (int i = 0; i <= capacity && capacity != 0; i++)
		total += statsArr[i];
	return total;
}

double Stats::average(){
	double average = 0.0;
	average = this->total() / this->getCapacity();
	return average;
}

double Stats::lowest() {
	double min = statsArr[0];
	for (int i = 0; i < capacity; i++) {
		if (statsArr[i] < min)
			min = statsArr[i];
	}
	return min;
}

double Stats::highest() {
	double max = statsArr[0];
	for (int i = 0; i < capacity; i++) {
		if (statsArr[i] > max)
			max = statsArr[i];
	}
	return max;
}