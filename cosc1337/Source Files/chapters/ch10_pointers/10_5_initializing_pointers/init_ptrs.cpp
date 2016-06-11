 // This program uses the address of each element in the array.
 #include <iostream>
 #include <iomanip>

 using namespace std;

 int main()
{
	 // The following definition of pint is legal because myValue is an integer.
	 int myValue1;
	 int * pint1 = &myValue1;

	 // The following definition of point is illegal because myFloag is not an int.
	 //float myFloat;
	 //int *pint = &mhFloat;	//illegal

	 //Pointers may be defined in the same statement as other variables of the same type.
	 int myValue2, *pint2 = &myValue2;

	 // the following definition defines an array, readings, and a pointer, marker,
	 // which is initialized with the address of the first element in the array:
	 double readings[50], *marker = readings;

	 // The following is illegal because pint is being initialized
	 // with the address ofan object that does not exist yet:
	 //int *pint = &myValue; // Illegal!
	 //int myValue;

	 // In most computers, memory at address 0 is inaccessible to user programs because it is
	 // occupied by operating system data structures. This fact allows programmers to signify that
	 // a pointer variable does not point to a memory location accessible to the program by
	 // initializing the pointer to 0. For example, if ptrToint is a pointer to int, and ptrTofloat
	 // is a pointer to float, we can indicate that neither of them points to a legitimate address by
	 // assigning 0 to both:
	 int *ptrToint1 = 0;
	 float *ptrTofloat1 = 0;

	 // Many header files, including iostream, fstream, and cstdlib, define a constant named
	 // NULL whose value is zero. Thus, assuming one of these header files has been included.
	 // A pointer whose value is the address 0 is often called a null pointer.
	 int *ptrToint2 = NULL;
	 float *ptrTofloat2 = NULL;

	 return 0;
 }
