#include <iostream>

using namespace std;

int main()
{
    char makeEntry = ' ';
    double sales = 0.0;
    
    cout << "Enter a sales amount? (y/n) ";
    cin >> makeEntry;
    do
    {
        cout << "Enter the sales: ";
        cin >> sales;
        cout << "You entered " << sales << endl << endl;
        cout << "Enter a sales amount? (y/n) ";
        cin >> makeEntry;
    } while(makeEntry == 'Y' || makeEntry == 'y');
    
    system("PAUSE");
    return 0;
}
