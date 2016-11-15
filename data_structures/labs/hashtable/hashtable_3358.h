/*	File Name: hashtable_3358.h

	Author: Raul Zuniga
	Date: 4/14/2015
	Assignment Number: 5

This class implements the hashtable_3358 interface using a vector
*/

#ifndef HASHTABLE_3358_H
#define	HASHTABLE_3358_H

#include <string>
#include <vector>

using namespace std;

class HashTable_3358 {
public:
	/*********************************************************************
	constructor: Initializes hash table to a predetermined size.
	**********************************************************************/
	HashTable_3358();
	/*********************************************************************
	makeEmpty: Removes all the items from the hash table.
	**********************************************************************/
	void makeEmpty();
	/*********************************************************************
	hash: A hash routine for string objects.
	key is the string to hash.
	tableSize is the size of the hash table.
	**********************************************************************/
	unsigned int hash(string key) const;
	/*********************************************************************
	findPos: Return the position where the seach for string x terminates
	**********************************************************************/
	unsigned int findPos(string key) const;
	/*********************************************************************
	find: Returns true if is in the hash table, else false.
	**********************************************************************/
	bool find(string key) const;
	/*********************************************************************
	rehash: Expand the hash table
	**********************************************************************/
	void rehash();
	/*********************************************************************
	insert: Adds the string to the hash table, if it is not already there.
	(If the hash table becomes 50% full, it rehashes.)
	**********************************************************************/
	void insert(string key);
	/*********************************************************************
	isPrime: Given a integer > 1
			 returns true if number
			 is prime, else false.
	**********************************************************************/
	bool isPrime(unsigned int number);
	/*********************************************************************
	nextPrime: return a prime number at least as large as number.
	**********************************************************************/
	unsigned int nextPrime(unsigned int number);
	/*********************************************************************
	size: return the number of strings stored in the hash table.
	**********************************************************************/
	unsigned int size();

private:
	vector<string> hashTable;
	unsigned int occupied;
};
#endif	/* HASHTABLE_3358_H */