#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int NROWS = 10;
    const int NCOLS = 15;
    int data[NROWS][NCOLS];
    
    // initialize elements of array randomly
    // from 1-10
    for (int row=0; row<NROWS; row++) 
    {
        for (int col=0; col<NCOLS; col++)
            data[row][col] = rand()%10 + 1;
    }
    
    // display contents of array
    for (int row=0; row<NROWS; row++) 
    {
        for (int col=0; col<NCOLS; col++)
            cout << setw(2) << data[row][col] << " ";
        cout << endl;
    }
    
    //// prompt use to enter column index (loop until valid)
//    int col;
//    cout << "Enter a column index: ";
//    cin >> col;
//    while (col < 0 || col >= NCOLS) 
//    {
//        cout << "That index is invalid.  Try again: ";
//        cin >> col;
//    }
//    // display the sum of the elements in the column
//    int sum = 0;
//    for (int row=0; row<NROWS; row++) 
//    {
//        sum += data[row][col];
//    }
//    cout << "Sum of column: " << sum << endl;
    
    // display the sum of all the columns
    int sum;
    for (int col=0; col<NCOLS; col++)
    {
        sum = 0;
        for (int row=0; row<NROWS; row++)
            sum += data[row][col];
        cout << setw(2) << sum << " ";
    }
    cout << endl;
    
    system("PAUSE");
    return 0;
}
