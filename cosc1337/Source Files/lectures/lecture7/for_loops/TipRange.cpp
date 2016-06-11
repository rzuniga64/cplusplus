// Write a for loop to fill in the program below.
// The program should read in a restaurant bill
// amount, and then calculate and display the 
// total bill with tip for various tip rates:
// 10%, 12.5%, 15%, 17.5%, .... 25%
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double billAmount = 0.0;
    
    cout << "Enter the bill amount: ";
    cin >> billAmount;
    
    // write for loop here
    for (double tipRate=0.1; tipRate <= 0.25; tipRate += 0.025) {
        cout << fixed << setprecision(2)<< 100*tipRate << "%: $";
        cout << billAmount * (1 + tipRate) << endl;
    }
    
    system("PAUSE");
    return 0;
}
