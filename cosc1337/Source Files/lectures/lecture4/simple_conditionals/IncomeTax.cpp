#include <iostream>

using namespace std;

int main()
{
    double income;
    double taxRate, tax;
    
    cout << "Enter your annual income: ";
    cin >> income;
    
    if (income < 8375)
        taxRate = 0.1;
    else if (income < 34000)
        taxRate = 0.20;
    else if (income < 82400)
        taxRate = 0.25;
    else if (income < 171850)
        taxRate = 0.3;
    else if (income < 373650)
        taxRate = 0.33;
    else
        taxRate = 0.35;
    tax = taxRate * income;
    cout << "Tax due: $" << tax << endl;
    
    system("PAUSE");
    return 0;
}
