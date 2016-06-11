#include <iostream>
#include <cmath>

using namespace std;

void calcCircleInfo(double , double & , double & );

int main()
{
    double r, a, c;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    
    calcCircleInfo(r, a, c);
    
    system("PAUSE");
    return 0;
}

void calcCircleInfo(double radius, double & area, double & circum)
{
    area = radius * radius * M_PI;
    circum = 2 * M_PI * radius;
}
