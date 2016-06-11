#include <iostream>

using namespace std;

int main() {
    int n = 7;
    int m = 8;
    int * ptr1 = &n;
    int * ptr2 = &m;
    
    ptr1 = ptr2;
    
    system("PAUSE");
    return 0;
}
