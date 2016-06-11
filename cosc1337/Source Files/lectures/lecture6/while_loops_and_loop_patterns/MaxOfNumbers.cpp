// Reads in positive values and reports the largest 
// when all are read.  User indicates the end of the 
// input by entering a negative number.
#include <iostream>

using namespace std;

int main()
{
    double num, biggest = 0;
    cout << "Enter a number: ";
    cin >> num;
    while (num >= 0)
    {
        //biggest = (num > biggest ? num : biggest);
        if (num > biggest)
            biggest = num;
        cout << "Enter a number: ";
        cin >> num;
    }
    cout << "Biggest number: " << biggest << endl;
    system("PAUSE");
    return 0;
}
