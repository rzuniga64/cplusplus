#include <iostream>
#include <vector>
#include <string> 
#include "list_3358_ll.h"

using namespace std;

/*************************************************************************************
* WHY USE RECURSION?
*
* It is true that recursion is never required to solve a problem
* - Any problem that can be solved with recursion can also be solved using iteration.
* Recursion requires extra overhead: function call
* + return mechanism uses extra resources
* However some repetitive problems are more easily and naturally solved with recursion
* - Iterative solution may be unreadable to humans
*
* Recursion is the primary method of performing repetition in most functional languages.
*
* Once programmers adapt to solving problems using recursion, the code produced is
* generally shorter, more elegant, easier to read and debug.
*
* HOW TO WRITE RECURSIVE FUNCTIONS
* Branching is required!! (If or switch)
* Find a base case
* - one (or more) values for which the result of the
* function is known (no repetition required to solve it)
* - no recursive call is allowed here
* Develop the recursive case
* - For a given argument (say n), assume the function works for a smaller value (n-1).
* - Use the result of calling the function on n-1 to form a solution for n
*
* Many recursive functions (over integers) look
* like this:
* type f(int n) {
*	if (n==0)
*		// do the base case
*	else
*		// ... f(n-1) ...
* ! Note these functions are undefined for n < 0.
**************************************************************************************/

void message(int n) {
	if (n > 0) {
		cout << "This is a recursive function.\n";
		message(n - 1);
	}
}

/******************************************************************
* Recursive function example
* Mathematical definition of n! (factorial of n)
* if n=0 then n! = 1
* if n>0 then n! = 1 x 2 x 3 x ... x (n-1) x n
*
* base case: n=0 (result is 1)
* recursive case:
* If we assume (n-1)! can be computed, how can we get n! from that?
* n! = n * (n-1)!
*******************************************************************/
int factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

/******************************************************************
* Recursive function over lists: recursive function to compute sum
*								 of a list of numbers
* You can write recursive functions over lists using the length
* of the list instead of n
*
* base case: length = 0 ==> empty list
* recursive case: if we assume we can sum the first n-1 items in
* the list, how can we get the sum of the whole list from that?
*
* sum(list = sum(list[0...n-2]) + list[n-1]
* Assume you given the answer to sum(list[0...n-2]), the sume
* of the first n-1) items.
*******************************************************************/
int sumList(int a[], int size) { //size is number of elems
	if (size == 0)
		return 0;
	else
		// call sum on first n-1 elements: sum(a,size-1)
		// the last element: a[size-1] 
		return sumList(a, size - 1) + a[size - 1];
}

/*
*	Aren't we removing all the elements from the vector?  No. We are passing by value
*   But something else is happening each time. We are copying the entire vector.
*/
int sumVec1(vector<int> v) { // using pass by value: lots of copying
	if (v.size() == 0)
		return 0;
	else {
		int x = v.back();
		v.pop_back();
		return x + sumVec1(v);
	}
}

int sumRec(vector<int> & v) { // using pass by reference
	if (v.size() == 0)
		return 0;
	else {
		int x = v.back();
		// v.pop_back creates the shorter vector
		v.pop_back();
		return x + sumRec(v);
	}
}

// auxilary function is needed to set things up before starting recursion
int sumVec2(vector<int> x) {
	// pass by value -> x is a copy of the argument
	return sumRec(x);
}

/*
* C++ string member function: substr string substr (int pos, int len) const;
* pos position of the first character to be copied as a substring. Note: The 
* first character is denoted by a value of 0 (not 1). 
* - len Number of characters to include in the substring.
* If pos+len is greater than the number of characters in the string, the whole 
* value of the string beginning at start is returned. 
*
* Recursive function to count the number of times a specific character appears 
* in a string
*/

int numChars(char target, string str) {
	if (str.empty()) {
		return 0;
	}
	else {
		int result = numChars(target, str.substr(1, str.size()));
		if (str[0] == target)
			return 1 + result;
		else
			return result;
	}
}

/*
* Three required properties of recursive functions
*
* A Base case
* -a non-recursive branch of the function body.
* -must return the correct result for the base case
*
* Smaller caller
* - each recursive call must pass a smaller version of the current argument.
*
* Recursive case
* -assuming the recursive call works correctly, the code must produce the
* correct answer for the current argument.
*
* Recursive function example
* greatest common divisor
* Greatest common divisor of two non-zero ints is the largest positive integer 
* that divides the numbers without a remainder
* This is a variant of Euclid�s algorithm:
*
* gcd(x,y) = y if y divides x evenly, otherwise:
* gcd(x,y) = gcd(y,remainder of x/y) //gcd(y,x%y) in c++
*
* It�s a recursive mathematical definition
* If x < y, then x%y is x (so gcd(x,y) = gcd(y,x))
* This moves the larger number to the first position.
*/

int gcd(int x, int y) {
	cout << "gcd called with " << x << " and " << y << endl;
	if (x % y == 0) {
		return y;
	}
	else {
		return gcd(y, x % y);
	}
}

/* 
* Recursive function example
* Fibonacci numbers
* Series of Fibonacci numbers : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
* Starts with 0, 1. Then each number is the sum
* of the two previous numbers
* F0 = 0
* F1 = 1
* Fi = Fi-1 + Fi-2 (for i > 1)
* It�s a recursive definition
*/

int fib(int x) {
	if (x <= 1)
		return x;
	else
		return fib(x - 1) + fib(x - 2);
}

/*
* Recursive function example
* Fibonacci numbers
* Modified code to count the number of calls to fib
* Why are there so many calls to fib?
* Say it computes fib(n-2) first.
* When it computes fib(n-1), it computes fib(n-2) again
* It�s not just double the work. It�s double the work for
* each recursive call.
* Each recursive call does more and more redundant work
*
* The number of recursive calls is
* - larger than the Fibonacci number we are trying to compute
* - exponential, in terms of n
* Never solve the same instance of a problem in
* separate recursive calls.
* - make sure f(m) is called only once for a given m
*/
int fibWithCount(int x, int &count) {
	count++;
	if (x <= 1)
		return x;
	else
		return fibWithCount(x - 1, count) + fibWithCount(x - 2, count);
}

int main() {

	const int SIZE = 10;
	//message(5);

	// factorial of a number
	int number = 10;
	cout << "The factorial of " << number << " is " << factorial(number) << endl;

	// recursion over a list
	int list[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11 };
	cout << "Sum of list is " << sumList(list, SIZE) << endl;

	// recursion over a vector, sum uses pass by value
	vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);

	cout << "sumVec1 " << sumVec1(a) << endl;
	cout << "size " << a.size() << endl;

	// recursion over a vector, sum uses pass by reference
	vector<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	b.push_back(40);

	cout << "sumVec2 " << sumVec2(b) << endl;
	cout << "size " << b.size() << endl;

	//List_3358 myList;

	//myList.insert(42);
	//myList.insert(52);
	//myList.insert(12);

	//cout << "linked list sum " << myList.sum() << endl;

	string mystring = "Mississippi";
	cout << mystring << " number of chars: " << numChars('s', mystring) << endl;

	cout << endl << "GCD(9,1): " << gcd(9, 1) << endl;
	cout << "GCD(1,9): " << gcd(1, 9) << endl;
	cout << "GCD(9,2): " << gcd(9, 2) << endl;
	cout << "GCD(70,25): " << gcd(70, 25) << endl;
	cout << "GCD(25,70): " << gcd(25, 70) << endl;

	cout << "The first 13 fibonacci numbers: " << endl;
	for (int i = 0; i<13; i++)
		cout << fib(i) << " ";
	cout << endl;

	cout << "The first 40 fibonacci numbers: " << endl;
	for (int i = 0; i<= 40; i++) {
		int count = 0;
		int x = fibWithCount(i, count);
		cout << "fib (" << i << ")= " << x
			<< " # of recursive calls to fib = " << count << endl;
	}

	return 0;
}