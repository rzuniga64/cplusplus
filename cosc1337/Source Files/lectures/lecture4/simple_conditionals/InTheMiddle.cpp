#include <iostream>

using namespace std;

int main()
{
    double d1, d2, d3;
    
    cout << "Enter three different numbers, separated by spaces: ";
    cin >> d1 >> d2 >> d3;
    
    // TODO: find and display the median 
    // (that is, the one in the middle)
    if ((d2 < d1 && d1 < d3) || (d3 < d1 && d1 < d2))
        cout << d1;
    else if ((d1 < d2 && d2 < d3) || (d3 < d2 && d2 < d1))
        cout << d2;
    else
        cout << d3;
    cout << " is in the middle. " << endl;
    
    system("PAUSE");
    return 0;
}
