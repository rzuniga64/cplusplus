/*
 * 	File Name: hashtable_test.cpp
 * 	Author: Raul Zuniga
*/

#include <iostream>			// needed for cout
#include <fstream>			// needed for ifstream
#include <string>			// needed for string
#include <deque>			// needed for deque
#include <vector>			// needed for vector
#include <assert.h>			// needed for assert
#include <chrono>			// needed for sleep_for
#include <thread>
#include "hashtable_3358.h"

using namespace std::chrono;

vector<string> & getWordSequences(string file, vector<string> & wordSequences, unsigned int numberOfWords);

int main() {
	string file1 = "";								
	string file2 = "";
	unsigned int numberOfWords;
	unsigned int sequencesInCommon = 0;
	
	vector<string> wordSequences1, wordSequences2;	// holds the word sequences for file1 and file2
	HashTable_3358 hashTable1, hashTable2;			// hash tables for word sequences 

	cout << "Please enter name of the first file to analyze: ";
	getline(cin, file1);
	assert(file1.length() != 0);

	cout << "Please enter name of the second file to analyze: ";
	getline(cin, file2);
	assert(file2.length() != 0 );

	cout << "Please enter the number of words per sequence: ";
	cin >> numberOfWords;

	// parse files and generate a list of word sequences which are stored in vectors.
	getWordSequences(file1, wordSequences1, numberOfWords);	
	getWordSequences(file2, wordSequences2, numberOfWords);

	// insert word squences for file 1 into hash table 1
	for (size_t i = 0; i < wordSequences1.size(); i++) 
		hashTable1.insert(wordSequences1[i]);

	// insert word sequences  for file 2 into hash table
	// and count how many file 2 word sequences are in hash table 1
	for (size_t j = 0; j < wordSequences2.size(); j++) {
		if (!hashTable2.find(wordSequences2[j]))
			hashTable2.insert(wordSequences2[j]);
		if (hashTable1.find(wordSequences2[j])) 
			sequencesInCommon++;
	}

	cout << "***" << file1 << endl;
	cout << "***" << file2 << endl;

	cout << "word count file1 = " << hashTable1.size() << endl;
	cout << "word count file2 = " << hashTable2.size() << endl;
	cout << "sequences in common: " << sequencesInCommon;

	return 0;
}

/**********************************************
getWordSequences: Produces a list of all the 
				  numberOfWords-word sequences
				  that occur in file and 
				  returns them in a vector
***********************************************/
vector<string> & getWordSequences(string file, vector<string> & wordSequences, unsigned int numberOfWords) {
	string word, words, str;
	deque<string> sequence;
	ifstream infile;
	int count = 0;

	try
	{
		infile.open(file);
		if (infile.good()) {
			while (infile >> word) {
				sequence.push_back(word);
				count++;
				if (count == numberOfWords) {
					for (size_t i = 0; i < numberOfWords; i++) {
						if (i < numberOfWords - 1)
							words.append(sequence[i] + " ");
						else
							words.append(sequence[i]);
					}
					wordSequences.push_back(words);
					words.erase(words.begin(), words.end());
					sequence.pop_front();
					count = numberOfWords - 1;
				}
			}
			infile.close();
		} else {
			cout << "Error: " << file << " not found" << endl;
			//std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			exit(EXIT_FAILURE);
		}

	} catch (ifstream::failure e) {
		cerr << "Exception opening/reading/closing/file\n";
		//std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		exit(EXIT_FAILURE);
	}

	return wordSequences;
}

