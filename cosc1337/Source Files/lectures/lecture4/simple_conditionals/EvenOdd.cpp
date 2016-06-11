#include <iostream>

using namespace std;

int main()
{
    int num;
    
    cout << "Enter an integer: ";
    cin >> num;
    
    // TODO: tell user if number is even or odd
    if (num%2 == 0) 
    {
        cout << num << " is even." << endl;
    }
    else 
    {
        cout << num << " is odd." << endl;
    }
    
    system("PAUSE");
    return 0;
}
