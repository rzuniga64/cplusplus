#include "String.h"

int main()
{
	String s1 = "banana";
	String s2 = "apple";

	s2 = s1;

	cout << s1 << s2 << endl;

	s2.assign(10, '*');

	cout << "s2: " << s2 << endl;

	String s3 = "apple";
	s3.erase(1,500);
	cout << "s3: " << s3 << endl;

    return 0;
}
