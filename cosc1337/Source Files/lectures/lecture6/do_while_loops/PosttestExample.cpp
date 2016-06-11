#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	do
	{
		num = num + 1;
		cout << num << " ";
	} while ((num > 0) && (num <= 10));
	cout << endl;
	system("PAUSE");
	return 0;
}
