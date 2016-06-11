#include <iostream>

using namespace std;

char smaller(char c1, char c2);
int smaller(int i1, int i2);
double smaller(double d1, double d2);

int main()
{
    int choice;
    do 
    {
        cout << "Choose from the following options: " << endl;
        cout << "1. Enter characters" << endl;
        cout << "2. Enter integers" << endl;
        cout << "3. Enter real numbers" << endl;
        cout << "4. Quit" << endl;
        cout << "Your choice? ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                char c1, c2;
                cout << "Enter characters: ";
                cin >> c1 >> c2;
                cout << "Smaller of " << c1 << " and " << c2;
                cout << ": " << smaller(c1, c2) << endl;
                break;
            }
            case 2:
            {
                int i1, i2;
                cout << "Enter integer: ";
                cin >> i1 >> i2;
                cout << "Smaller of " << i1 << " and " << i2;
                cout << ": " << smaller(i1, i2) << endl;
                break;
            }
            case 3:
            {
                int d1, d2;
                cout << "Enter real numbers: ";
                cin >> d1 >> d2;
                cout << "Smaller of " << d1 << " and " << d2;
                cout << ": " << smaller(d1, d2) << endl;
                break;
            }
            case 4:
                break;
            default:
                cout << "Not a valid choice." << endl;
        }
    } while(choice != 4);
    system("PAUSE");
    return 0;
}

char smaller(char c1, char c2)
{
    return (c1 < c2 ? c1 : c2);
}

int smaller(int i1, int i2)
{
    return (i1 < i2 ? i1 : i2);
}

double smaller(double d1, double d2){
    return (d1 < d2 ? d1 : d2);
}
