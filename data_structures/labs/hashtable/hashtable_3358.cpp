/* File Name: hashtable_3358.cpp

	Author: Raul Zuniga
	Date: 4/14/2015
	Assignment Number: 5
	CS3358 Spring 2015
	Instructor: Jill Seaman
*/

#include <string>
#include "hashtable_3358.h"

HashTable_3358::HashTable_3358() : hashTable(101){
	makeEmpty();
}

void HashTable_3358::makeEmpty() {
	occupied = 0;
	for (size_t i = 0; i < hashTable.size(); i++) 
		hashTable[i] = " ";
}


unsigned int HashTable_3358::hash(string key) const {
	unsigned int hashVal = 0;

	for (size_t i = 0; i < key.length(); i++)
		hashVal = 37 * hashVal + key[i];

	return hashVal % hashTable.size();
}

unsigned int HashTable_3358::findPos(string key) const {
	int i = 0;
	unsigned int currentPos = hash(key);

	while (hashTable[currentPos] != " " &&
		   hashTable[currentPos] != key) {
		currentPos += 2 * ++i - 1;	// Compute ith probe
		if (currentPos >= hashTable.size())
			currentPos -= hashTable.size();
	}
	return currentPos;
}

bool HashTable_3358::find(string key) const {
	int currentPos= findPos(key);

	if (hashTable[currentPos] != " ")
		return true;
	else
		return false;
}

void HashTable_3358::rehash() {
	vector<string> oldHashTable = hashTable;

	// Create new empty hash table
	hashTable.resize(nextPrime(2 * oldHashTable.size()));
	makeEmpty();

	// Copy table over
	for (size_t i = 0; i < oldHashTable.size(); i++)
		if (oldHashTable[i] != " ")
			insert(oldHashTable[i]);
}

void HashTable_3358::insert(string key) {
	// Insert key 
	int currentPos = findPos(key);
	if (hashTable[currentPos] != key)
		hashTable[currentPos] = key;

	if (++occupied > hashTable.size() / 2)
		rehash();
}

bool HashTable_3358::isPrime(unsigned int number){
	for (int i = 2; i < number/2; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

unsigned int HashTable_3358::nextPrime(unsigned int number){
	unsigned int x = number + 1;
	while (!isPrime(x))
		x++;
	return x;
}

unsigned int HashTable_3358::size(){
	return occupied;
}