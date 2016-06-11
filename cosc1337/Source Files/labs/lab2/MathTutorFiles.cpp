/*
 * 	Purpose: A program that can be used as a math tutor for a
 * 			 young student.  It generates two random numbers,
 * 			 adds them and provides the answer.
 * 	Input: 	 The students name.
 * 	Output:	 The problem is written to student_name + "_problems.txt".
 * 	         The problem and answer is written to student_name + "solutions.txt".
 */

#include <iostream>
#include <string>
#include <iomanip>	// needed to use setw, setfill
#include <cstdlib> 	// needed to use srand and rand
#include <ctime> 	// needed to use time
#include <cmath>	// needed to use log10
#include <fstream>	// needed to use ofstream, ifstream

using namespace std;

int main() {

	int num1;
	int num2;
	string name, fname;
	string text1, text2;
	unsigned seed; // Random generator seed

	cout << "Please enter your first name: ";
	cin >> fname;

	name = fname;
	text1 = "_problems.txt";
	text2 = "_solutions.txt";
	const char* probFileName = fname.append(text1).c_str();
	const char* solnFileName = name.append(text2).c_str();

	ofstream outfile1;
	ofstream outfile2;
	outfile1.open(probFileName, ios::out | ios::app);
	outfile2.open(solnFileName, ios::out | ios::app);

	// Use the time function to get a "seed" value for srand
	seed = time(0);
	srand(seed);

	// Create two random integers between 1 and 1000
	num1 = rand() % 1001;
	num2 = rand() % 1001;

	int numDigits = log10(num1+num2) + 1;

	outfile1 << setw(numDigits+2) << setfill(' ') << num1 << endl;
	outfile1 << "+ " << setw(numDigits) << num2 << endl;
	outfile1 << string(numDigits+2, '-') << endl;
	outfile1 << "  " << endl;

	outfile2 << setw(numDigits+2) << setfill(' ') << num1 << endl;
	outfile2 << "+ " << setw(numDigits) << num2 << endl;
	outfile2 << string(numDigits+2, '-') << endl;
	outfile2 <<  setw(numDigits+2) << num1 + num2 << endl << endl;
    //system("PAUSE"); */

	outfile1.close();
	outfile2.close();
	return 0;
}
