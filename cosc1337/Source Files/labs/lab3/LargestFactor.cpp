/*
 * 	Purpose: This program allows the user to enter integers repeatedly and
 * 	 		 informs the user where the integer is prime or not. The user
 * 	 		 will indicate that he or she is finished entering numbers by
 * 	 		 entering the number zero.
 * 	Input: 	 An integer entered in by the user until a 0 is entered.
 * 	Output:	 Display if the number is prime.  If not then display the largest
 * 			 factor of the number.
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

bool isPrime(int, int &);

int main()
{
	int largestFactor = 0;
	int num = 1;

	while (num != 0)
	{
		cout << "Enter a positive integer (0 to exit): ";
		cin >> num;

		if (num < 0)
		{
			cout << "You entered a negative number. ";
			continue;
		}

		if (num == 1 || isPrime(num, largestFactor))
			cout << "The number " << num << " is prime!" << endl;
		else
			cout << "The number " << num << " is not prime. It's largest factor is " << largestFactor << endl;
	}

	cout << "Exiting the program!" << endl;

	return 0;
}

/*
 *	Purpose: Calculates if a number is prime. If not prime it calculates
 *			 it calculates the largest factor of the number.
 *	Input: 	 A test score which is of type int.
 *	Output:  true if the number is prime or false if it isn't.
 *		     If it is not prime it returns the largest factor of the
 *		     number using a reference variable.
 */

bool isPrime(int num, int &largestFactor)
{
	bool isPrime = false;

	int i;
	for (i = num-1; num % i != 0; i--) {}
	if (i == 1)
		isPrime = true;
	else
		largestFactor = i;

	return isPrime;
}
