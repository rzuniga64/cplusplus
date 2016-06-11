#include <string>
#include <iostream>

using namespace std;

void printStars( int n)
{
	string stars = "";

	for (int i=1; i <=n; i++)
		stars += "*";

	cout << stars << endl;
}

int main()
{
	printStars(35);

}
