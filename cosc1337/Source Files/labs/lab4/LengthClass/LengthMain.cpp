#include "Length.h"

void zeroLength(Length &len)
{
	len.setValue(0.0);
}

int main()
{
	//a.Fill in the main function with statements that do each of the following, in the order given.I
	//	recommend that you stop, compile, run, and debug each one before you do the next one.

	// i. Declare a Length instance named len1 that has initial value 1 foot, 
	// and display it using the class's display function. Before you display 
	// it, print a string with the variable's name, and after displaying print 
	// out a newline, so you get output that looks like this :
	// len1 : 1 ft
	
	Length len1(1, "ft");
	cout << "len1 : ";
	len1.display();
	cout << endl;

	// ii.Declare another Length instance named len2 that has initial value 
	// 10 inches, use the convertTo function to convert it to centimeters, 
	// and display it.

	Length len2(10, "in");
	len2.convertTo("cm");
	cout << "len2 : ";
	len2.display();
	cout << endl;

	// iii. Declare another Length instance named len3 using the default constructor.
	// Then use the read function to read in the length from the user, and display it.
	// Before you call the read function, print a prompt so the user will know what to do, like this:
	// Enter a length, followed by the units(ft / in / cm) :

	Length len3;
	cout << "Enter a length, followed by the units (ft/in/cm): ";
	len3.read();
	cout << "len3 : ";
	len3.display();
	cout << endl;
	
	// iv. Use the lessThan function to determine whether len1 is less than len3, and
	//	display whichever length is shorter.The output should look like this (though 
	// perhaps with different numbers) :
	//	3 inches is shorter than 1 feet.

	if (len1.lessThan(len3)){
		len1.display();
		cout << " is less than ";
		len3.display();
		cout << endl;
	} 
	else {
		len3.display();
		cout << " is less than ";
		len1.display();
		cout << endl;
	}

	// b. Add the global function called zeroLength to the LengthClassMain.cpp file.It
	//	  should appear after the #include "Length.h'' statement. The function should receive a Length
	//	  object by reference, and set it to zero using the Length class setValue member function.The
	//	  function should return void.Test that your function works by calling it on len1 and displaying
	//	  the result after the function call.

	zeroLength(len1);
	cout << "len1 after zeroLength function call: ";
	len1.display();
	cout << endl;

	return 0;
}

