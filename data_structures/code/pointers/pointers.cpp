#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "pointers.h"

using namespace std;

int main() {
	pointers_and_address_operator();
	pointer_variables();
	indirection_operator();
	dynamic_memory_allocation();
	reference_variables();
	structures();
	indigenous_vs_exogenous_data();
	shallow_copy_vs_deep_copy();

	return 0;
}

void pointers_and_address_operator() {

	char letter;
	short number;
	float amount;
	double profit;
	char ch;

	// Print address of each variable
	// The cast to long makes addresses print in decimal
	// rather than in hexadecimal
	cout << "Address of letter is: "
		<< long(&letter) << endl;
	cout << "Address of number is: "
		<< long(&number) << endl;
	cout << "Address of amount is: "
		<< long(&amount) << endl;
	cout << "Address of profit is: "
		<< long(&profit) << endl;
	cout << "Address of ch is: "
		<< long(&ch) << endl;
}

void pointer_variables(){

	// A pointer is a variable that stores the address of another variable, 
	// providing indirect access to it. An asterisk is used to define a pointer.
	int x = 25; 
	int *ptr; 

	// The address operator(&) returns the address of a variable 
	ptr = &x; // Store the address of x in ptr
	cout << "The value in x is " << x << endl;
	cout << "The address of x is " << ptr << endl;

	// The unary operator * is the dereferencing operator. 
	// *ptr is an alias for the variable that the pointer points to.
	cout << "The value in x is " << *ptr << endl;

	// Initialization
	int y = 10;
	int *ptr2 = &y;	//declaration, NOT dereferencing
	cout << "The value in y is " << *ptr2 << endl;

	// What is wrong with each of the following?
	//int *ptr2 = &z;	// z is not declared yet
	//int z = 10;

	//int a = 10;
	//int *ptr = a; // a is not an address

	int b = 10, c = 99;
	int *ptr3 = &c;
	*ptr3 = b;
	ptr3 = &b; // c gets 10 (changes c), ptr3 points to x(changes ptr3)

	// What is happening in each of the following?
	int *ptr4 = NULL;  // initializing a pointer to NULL or 0 (null pointer)

	int int1 = 10;
	int *ptr5 = &int1;
	*ptr5 += 5;			// int1 is now 15
	*ptr5++;			// changes ptr5 to point to location after int1 (returns it's value)

	int int2 = 10, int3 = 99;
	int *ptr6 = &int2, *ptr7 = &int3;

	ptr6 = ptr7;		// makes ptr6 point to what ptr7 is pointing to
	*ptr6 = *ptr7;		// copies what ptr7 points to into the locati0n ptr6 points to
	if (ptr6 == ptr7) {	// do the pointers point to the same location?
		cout << "pointers point to the same location" << endl;
	}

	if (*ptr6 == *ptr7){// do the pointers point to the same values?
		cout << "pointers point to the same value" << endl;
	}
}

void indirection_operator(){

	// This  demonstrates the use of the indirection operator.
	int x = 25;		// int variable
	int *ptr = &x;	// Store the address of x in ptr

	// Use both x and ptr to display the value in x
	cout << "Here is the value in x, printed twice:\n";
	cout << x << " " << *ptr << endl;

	// Assign 100 to the location pointed to by ptr
	// This will actually assign 100 to x.
	*ptr = 100;

	// Use both x and ptr to display the value in x
	cout << "Once again, here is the value in x:\n";
	cout << x << " " << *ptr << endl;
}

void dynamic_memory_allocation() {
	// Automatic variables are created when declared
	// and destroyed at the end of their scope.
	// Dynamic memory allocation allows you to create
	// and destroy anonymous variables on demand, 
	// during runtime.
	//
	// 'new' operator requests dynamically allocated
	// memory and returns address of newly created 
	// anonymous vairable

	string *ptr;
	ptr = new string("hello");
	cout << *ptr << endl;
	cout << "Length: " << (*ptr).size() << endl;

	// When you are finished using a variable created with
	// new, use the delete operator to destroy it.  Do not
	// forget to delete dynamically allocated variables
	// (memory leaks: allocated but inaccessible memory).

	delete ptr;
}

void reference_variables() {
	// Reference Type: an alias to another variable
	// It's like a constant pointer variable that is always
	// implicitly dereferenced.  

	int x = 25;
	int &y = x;	// int & is the reference type
	y += 3;		// this changes x to 3

	// Reference variables MUST be initialed when they are 
	// declared. No way to change their address value later
	// (assignment dereferences them)
	// C++ call by reference parameters are really reference 
	// variables used as parameters.
}

void structures() {
	// A structure stores a collection of objects of various types
	// Each object in the structure is a member, and is
	// accessed using the dot member operator.

	struct Student {
		int idNumber;	// defines a new data type
		string name;
		int age;
		string major;
	};

	Student student1, student2;
	student1.name = "John Smith";

	// Valid operations over entire structs
	// assignment
	student2 = student1;
	// function call myFunc(gradStudent, x);

	// Invalid operations over structs:
	// Comparison student1 == student2
	// output cout << student1
	// input cin>> student2
	// Must do these member by member

	// pointers to structs
	Student s1 = { 12345, "Jane Doe", 18, "Math" };
	Student *ptr = &s1;

	// To access the members via the pointer:
	cout << (*ptr).name << endl; 

	// or equivalently use ->
	cout << ptr->name << endl;
}

void indigenous_vs_exogenous_data() {

	//indigenous data completely contained within the structure
	struct Student{
		int idNumber;
		string name;
		int age;
		string major;
	};

	// exogenous data reside outside the structure, and are pointed to from the structure-> Teacher's name
	struct Teacher {
		int idNumber;
		string *name;
	};
}

void shallow_copy_vs_deep_copy() {
	struct Student{
		int idNumber;
		string name;
		int age;
		string major;
	};

	// exogenous data reside outside the structure,
	// and are pointed to from the structure-> Teacher's name
	struct Teacher {
		int idNumber;
		string *name;
	};

	Student s1, s2;
	s1 = s2;

	//Teacher t1, t2;
	Student t1, t2;
	t1 = t2;

	// By default, it is a member by member copy.
	// this is fine for Student buy not the Teachers
	// t1.name and t2.name share the same memory, 
	// point to the same place
	// changing t1-> name will also change t2->name
	// delete t1.name, will make t2.name invalid.

	//	Shallow copy : copies top level data only.F or
	//	pointers, the address is copied, not the values
	//	pointed to.This is the default for = .

	//	Deep copy : copies the pointed at values instead
	//	of their addresses. May require allocating new
	//	memory for the new value.
}

// Call by value is the default
// Problem: lots of copying if vector is large
int findMax(vector<int> vect) {
	assert(vect.size() > 0);
	int max = 0;
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] > max)
			max = vect[i];
	}
	return max;
}



