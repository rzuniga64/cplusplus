#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n = 6;
	int j;
	j=0;
	string stars = "";

	while (j < n )
	{
		j++;
		stars += "*";
	}
	cout << stars << endl;
}


