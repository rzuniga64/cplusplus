 // This program demonstrates the order in which base and
 // derived class constructors and destructors are called.
 // For the sake of simplicity, all the class declarations
 // are in this file.
 #include <iostream>
 using namespace std;

 // Base class
 class BaseDemo
 {
 public:
	 BaseDemo() // Constructor
 	 { cout << "This is the BaseDemo constructor.\n"; }
	 ~BaseDemo() // Destructor
	 { cout << "This is the BaseDemo destructor.\n"; }
	 };

 // Derived class
 class DeriDemo : public BaseDemo
 {
 public:
	 DeriDemo() // Constructor
 	 { cout << "This is the DeriDemo constructor.\n"; }
	 ~DeriDemo() // Destructor
	 { cout << "This is the DeriDemo destructor.\n"; }
 };

 int main()
 {
	 cout << "We will now create a DeriDemo object.\n";
	 DeriDemo object;
	 cout << "The program is now going to end.\n";
	 return 0;
 }
