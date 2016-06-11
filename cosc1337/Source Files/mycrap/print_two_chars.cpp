#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int i;
	for (i = 97; i < 102 ; i++ )
		for (int j = 97; j <= 101; j++)
			cout << static_cast<char>(i) << static_cast<char>(j) <<  endl;

	return 0;
}
