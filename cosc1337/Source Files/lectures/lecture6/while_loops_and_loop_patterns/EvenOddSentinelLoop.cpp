#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter a number (negative to quit): ";
    cin >> num;
    
    while (num > 0)
    {
        if (num%2 == 0)
            cout << num << " is even." << endl;
        else
            cout << num << " is odd." << endl;
        cout << "Enter a number (negative to quit): ";
        cin >> num;
    }
    
    system("PAUSE");
    return 0;
}
