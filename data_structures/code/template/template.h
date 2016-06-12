#include <iostream>
#include <string>

using namespace std;
/***********************************************
TYPE INDEPENDENCE 

Many algorithms like search, sort, or swap do
not depend on the type of the elements/items.
We would like to re - use the same code
regardless of the item type.

GENERIC PROGRAMMING

-	Writing functions and classes that are 
	type-independent is called generic programming. 
-	These functions and classes will have an extra
-	parameter to represent the specific type of the
-	components.
-	When the stand-alone function is called, or 
	class is instantiated, the programmer provides 
	the specific type:

	vector<string> students(20);
	vector<double> dailySales(365);

	Note: vector is a templated class.

TEMPLATES

-	C++ provides template to implement generic
	functions and classes.
-	A function template is not a function, it is a
	design or pattern for a function.
-	The function template makes a function when
	the compiler encounters a call to the function.
-	Like a macro, it substitutes the appropriate type for
	the type variable.

*************************************************/

template <class Object>
void swap(Object &lhs, Object &rhs) {
	Object tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int main() {
	int x = 5;
	int y = 7;
	string a = �hello�;
	string b = �there�;
	swap <int>(x, y); //int replaces Object
	swap <string>(a, b); //string replaces Object
	cout << x << � � << y << endl;
	cout << a << � � << b << endl;
}