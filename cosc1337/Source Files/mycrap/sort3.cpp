#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void swapdoubles(double &x, double &y)
{
	double temp = x;
	x = y;
	y = temp;
}

void sort3(double &a, double &b, double &c)
{
	if (a > b)
		swapdoubles(a,b);
	if ( b > c)
		swapdoubles(b,c);
	if ( a > b )
		swapdoubles(b,a);
}

/*
	x		y		z
	3.5		1.6		2.7
	1.1		2.2		3.3
	2.3		1.4		3.5
	1.2		3.4		2.3
	2.4		3.5		1.6
	10.1	9.2		8.3
	3.14	2.71	3.04
	3.6		2.7		1.8
	1.1		2.2		3.3
*/
int main()
{
	double a = 1.2;
	double b = 3.4;
	double c = 2.3;

	sort3(a, b, c);
	cout << a << " " << b << " " << c << endl;

}
