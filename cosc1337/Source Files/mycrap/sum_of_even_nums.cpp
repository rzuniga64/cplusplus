#include <string>
#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int num;

	cin >> num;
	while (num > 0)
	{
		if (num % 2 == 0) {
			sum += num;
		}
	cin >> num;
	}
	cout << "sum is: " << sum << endl;
}
