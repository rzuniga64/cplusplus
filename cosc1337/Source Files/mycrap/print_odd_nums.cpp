#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	for (int i=11; i <= 121; i++)
	{
		if (i % 2 != 0)
			cout << i << " ";
	}
	return 0;
}
