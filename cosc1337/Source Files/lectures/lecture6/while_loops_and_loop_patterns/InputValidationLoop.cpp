#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double area = 0.0;
    char  choice;
    cout << "This program will calculate the area of a shape." << endl;
    cout << "Please choose from the following options." << endl;
    cout << "c: Calculate the area of a circle" << endl;
    cout << "r: Calculate the area of a rectangle" << endl;
    cout << "t: Calculate the area of a triangle" << endl;
    cin >> choice;
    // TODO: fill in condition (choice is invalid)
    //while (choice != 'c' && choice != 'r' && choice != 't')  
    while (!(choice == 'c' || choice == 'r' || choice == 't'))
    {
        cout << "I'm sorry, that choice is invalid. ";
        cout << "Please enter c, r, or t: ";
        cin >> choice;
    }
    
    
    switch(choice)
    {
        case 'c':
        {
            double radius;
            cout << "Enter the radius: ";
            cin >> radius;
            area = M_PI * radius * radius;
            break;
        }
        case 'r':
        {
            double height, width;
            cout << "Enter the height and width of the rectangle: ";
            cin >> height >> width;
            area = height * width;
            break;
        }
        case 't':
        {
            double height, base;
            cout << "Enter the height and base of the rectangle: ";
            cin >> height >> base;
            area = 0.5 * base * height;
            break;
        }
    }
   
    cout << "Area: " << area << endl;
    
    system("PAUSE");
    return 0;
}
