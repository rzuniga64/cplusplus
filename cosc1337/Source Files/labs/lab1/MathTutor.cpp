/*
 * 	Purpose: A program that can be used as a math tutor for a
 * 			 young student. The program will prompt the student to solve
 * 			 an addition problem, prompting them by name, and then
 * 			 reading in the student's answer.
 * 	Input: 	 The student's name and answer.
 * 	Output:	 A message giving the correct answer along with the
 * 	         the student's answer.
 */

#include <iostream>
#include <string>
#include <iomanip>	// Header file need to use setw
#include <cstdlib> 	// Header file needed to use srand and rand
#include <ctime> 	// Header file needed to use time

using namespace std;

int main() {

	int num1;
	int num2;
	int answer;
	string fname;
	unsigned seed; // Random generator seed

	cout << "Please enter your first name: ";
	cin >> fname;

	// Use the time function to get a "seed" value for srand
	seed = time(0);
	srand(seed);
	num1 = rand() % 10;
	num2 = rand() % 10;

	cout << fname << " can you solve this addition problem? " << endl;
	cout << setw(3) << num1 << endl;
	cout << "+ " << setw(1) << num2 << endl;
	cout << "---" << endl << "  ";
	cin >> answer;
	cout << endl << "The correct answer is " << num1 + num2 << " and " << fname
		 << "'s answer was " << answer << "." << endl;
    system("PAUSE");
	return 0;
}
