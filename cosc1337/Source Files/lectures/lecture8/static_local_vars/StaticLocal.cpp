#include <iostream>

using namespace std;

double runningAverage(double d);

int main()
{
    double num;
    cout << "Enter a number (negative to quit): ";
    cin >> num;
    
    while (num >= 0)
    {
        cout << "Average so far: " << runningAverage(num) << endl;
        cout << "Enter a number (negative to quit): ";
        cin >> num;
    }
    system("PAUSE");
    return 0;
}

double runningAverage(double d) 
{
    static int num = 0;
    static double sum = 0.0;
    num++;
    sum += d;
    return sum / num;
}
