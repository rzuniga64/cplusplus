#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	while ((num > 0) && (num <= 10)) 
	{
		num = num + 1;
		cout << num << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
