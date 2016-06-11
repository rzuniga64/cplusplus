#include <iostream>

using namespace std;

int main()
{
    int age = 0;
    
    cout << "Enter an age greater than 0: ";
    cin >> age;
    
    do
    {
        cout << "You entered " << age << endl << endl;
        cout << "Enter an age greater than 0: ";
        cin >> age;
    } while (age > 0);
    
    system("PAUSE");
    return 0;
}
