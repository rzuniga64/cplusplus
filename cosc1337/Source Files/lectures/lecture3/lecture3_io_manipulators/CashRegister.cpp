#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double TAX_RATE = 0.0825;
    double purchaseAmt = 0.0;
    double priceWithTax = 0.0;
    
    cout << "Enter the purchase amount: $";
    cin >> purchaseAmt;
    
    priceWithTax = purchaseAmt + purchaseAmt * TAX_RATE;
    
    cout << "Price with tax: $" << fixed << setprecision(2) << priceWithTax << endl;
    
    return 0;
}
