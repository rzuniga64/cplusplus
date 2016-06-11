#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double vectorLength, vectorDegrees;
    
    cout << "Enter the length of the vector: ";
    cin >> vectorLength;
    cout << "Enter the number of degrees from horizontal: ";
    cin >> vectorDegrees;
    
    // TODO: calculate and display the x,y coordinates of the tip of the vector
    double x = vectorLength * cos(vectorDegrees * M_PI / 180.0);
    double y = vectorLength * sin(vectorDegrees * M_PI / 180.0);
    
    cout << "Tip of vector is at " << x << ", " << y << endl;

    return 0;
}
