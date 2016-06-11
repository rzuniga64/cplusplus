// This program demonstrates the ability of a pointer to
// point to different variables
#include <iostream>

using namespace std;

int main() {
    int x = 25;
    int y = 30;
    int * ptr;
    
    cout << "Original values: " << x << " ";
    cout << y << endl;
    
    ptr = &x;
    *ptr *= 4;
    
    ptr = &y;
    *ptr *= 2;
    
    cout << "Modified value: " << x << " ";
    cout << y << endl;
    
    system("PAUSE");
    return 0;
}
