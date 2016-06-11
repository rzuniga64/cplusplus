#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double area = 0.0;
    int  choice = 0;
    cout << "This program will calculate the area of a shape." << endl;
    cout << "Please choose from the following options." << endl;
    cout << "1. Calculate the area of a circle" << endl;
    cout << "2. Calculate the area of a rectangle" << endl;
    cout << "3. Calculate the area of a triangle" << endl;
    cin >> choice;
    
    // TODO: finish program!
    if (choice == 1)
    {
        double radius;
        cout << "Enter the radius: ";
        cin >> radius;
        area = M_PI * radius * radius;
    }
    else if (choice == 2)
    {
        double height, width;
        cout << "Enter the height and width of the rectangle: ";
        cin >> height >> width;
        area = height * width;
    }
    else if (choice == 3)
    {
        double height, base;
        cout << "Enter the height and base of the rectangle: ";
        cin >> height >> base;
        area = 0.5 * base * height;
    }
   
    cout << "Area: " << area << endl;
    
    system("PAUSE");
    return 0;
}
