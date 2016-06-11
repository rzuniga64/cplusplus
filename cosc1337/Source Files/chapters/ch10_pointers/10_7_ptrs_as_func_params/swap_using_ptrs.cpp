#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void swap(int * a, int *  b)
{
	int  * temp = new int;
	*temp = *a;
	*a = *b;
	*b = *temp;

	delete temp;
}

int main()
{
	int a = 9;
	int b = 17;
	int * aptr = &a;
	int * bptr = &b;

	swap(aptr, bptr);
	cout << " a: " << a << ", b: " << b << endl;
	return 0;
}
