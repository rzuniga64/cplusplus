/* 
* File Name: assing4_rz1005.cpp
* Author: Raul Zuniga
* Date: 4/1/2014
* Assignment Number: 4
* CS3358 Spring 2015
* Instructor: Jill Seaman
*/

#include <iostream>
#include <vector>
#include <string> 

using namespace std;

/***********************************************************
* struct ListNode
* Preconditions:  None.
* Postconditions: Creates a linked list node.
*				  Allows creation of a linked list without a
*			      class. The Node data type and head pointer 
*                 are defined in main.
************************************************************/
struct ListNode {
	double value;
	ListNode *next;
};

/***********************************************************
* appendNode(ListNode *& head, int num)
* Preconditions:  None.
* Postconditions: appends a node to a linked list
************************************************************/
void appendNode(ListNode *& head, int num) {
	ListNode *newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	if (head == NULL)
		head = newNode;
	else
		head->next = newNode;
}

/***********************************************************
* void displayList(ListNode *& head)
* Preconditions:  None.
* Postconditions: displays the values in a linked list
************************************************************/
void displayList(ListNode *& head) {
	ListNode *cursor = head;
	while (cursor) {
		cout << cursor->value << " ";
		cursor = cursor->next;
	}
}

/***********************************************************
* void emptyList(ListNode *& head)
* Preconditions:  None.
* Postconditions: deletes all the nodes of a linked list
************************************************************/
void emptyList(ListNode *& head) {
	ListNode *cursor = head;
	ListNode *n;
	while (cursor) {
		n = cursor->next;
		delete cursor;
		cursor = n;
	}
}

/***********************************************************
* tableOfSquares(int n)
* Preconditions:  None.
* Postconditions: returns a table of squares from 1 to n
************************************************************/
void tableOfSquares(int n) {
	if (n > 0) {
		tableOfSquares(n - 1);
		printf("%2d %3d \n", n, n*n);
	}
}

/***********************************************************
* power(double num, int pow)
* Preconditions:  the function takes two arguments, the 
*			      number raised to the power and the power.
* Postconditions: returns a number raised to a power using
*				  recursion
************************************************************/
double power(double num, unsigned int pow) {
	if (pow == 0)
		return 1;
	else
		return num * power(num, pow - 1);
}

/***********************************************************
* isMember(int array[], int size, int value)
* Preconditions:  the function takes three arguments, an 
*			      array of ints, its size(number of elements)
*				  and a target value.
* Postconditions: returns true if the target value is found
*				  in the array, or false if the value is not
*		          in the array.
************************************************************/
bool isMember(int array[], int size, int value) {
	if (size == 0)
		return (array[size] == value);
	else if (array[size] == value)
		return true;
	else return isMember(array, size - 1, value);
}

/************************************************************
* double maxNode(ListNode *cursor, double maxValue)
* Preconditions:  the function takes two arguments, an
*			      Listnode pointer, and the value to 
*				  compare against.
* Postconditions: returns the maximum value in a linked list.
*************************************************************/
double maxNode(ListNode *cursor, double maxValue) {
	if (cursor == NULL)
		return maxValue;
	if (cursor->value > maxValue)
		return maxNode(cursor->next, cursor->value);
	else 
		return maxNode(cursor->next, maxValue);
}

/************************************************************
* string trim(string const & str)
* Preconditions:  The function takes as a parameter a string.
* Postconditions: Returns a string with whitespace trimmed
*				  off the ends of the string.
*************************************************************/
string trim(string const & str) {
	if (str.empty())
		return str;

	int first = str.find_first_not_of(' ');
	int last = str.find_last_not_of(' ');
	return str.substr(first, last - first + 1);
}

/************************************************************
* bool isPalindrome(string n) 
* Preconditions:  The function takes as a parameter a string.
* Postconditions: Returns true if string argument is a 
*                 palindrome, false otherwise.
*************************************************************/
bool isPalindrome(string str) {

	bool ret= true;

	if (str.empty()) {
		return ret;
	} else {
		char first = tolower(str[0]);
		char last = tolower(str[str.size()-1]);
		if (first != last)
			ret = false;
		else if (str.size() > 2) {
			str = trim(str);
			ret = isPalindrome(str.substr(1, (str.length() - 1) - 1));
		}
	}
	return ret;
}

int main() {

	// test tableOfSquares
	tableOfSquares(10);

	// test power function
	cout << "\nPower function:" << endl;
	cout << 2 << " to the power of " << 5 << ": " << power(2, 5) << endl;

	// test isMember function
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11 };
	int value1 = 10;

	cout << "\nMember function" << endl;
	for (int i = 0; i < 10; i++)
		cout << i << " ";

	cout << "has " << value1 << "?: " << boolalpha << isMember(list, 10, value1) << endl;

	int value2 = 12;
	for (int i = 0; i < 10; i++)
		cout << i << " ";

	cout << "has " << value2 << "?: " << boolalpha << isMember(list, 10, value2) << endl;

	// test maxNode function
	ListNode *head = NULL;

	appendNode(head, 10);
	appendNode(head, 11);
	appendNode(head, 12);
	appendNode(head, 13);
	cout << "\nMaxNode of {";
	displayList(head);
	cout << "}: " << maxNode(head, -1);
	emptyList(head);

	string str1 = "A man A plan A canal Panama";
	string str2 = "No one";
	string str3 = "level";
	string str4 = "Pot top";
	string str5 = "Palindrome";
	string str6 = "";

	cout << "Is " << "\"" << str1 << "\"" << " a palindrome? " << isPalindrome(str1) << endl;
	cout << "Is " << "\"" << str2 << "\"" << " a palindrome? " << isPalindrome(str2) << endl;
	cout << "Is " << "\"" << str3 << "\"" << " a palindrome? " << isPalindrome(str3) << endl;
	cout << "Is " << "\"" << str4 << "\"" << " a palindrome? " << isPalindrome(str4) << endl;
	cout << "Is " << "\"" << str5 << "\"" << " a palindrome? " << isPalindrome(str5) << endl;
	cout << "Is " << "\"" << str6 << "\"" << " a palindrome? " << isPalindrome(str6) << endl;
	return 0;
}