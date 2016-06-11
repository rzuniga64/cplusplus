#include <iostream>

using namespace std;

int main() {
    int * o1 = new int;
    int * o2 = new int;
    *o1 = 8;
    *o2 = 9;
    
    o2 = new int;
    *o2 = *o1;
    
    return 0;
}
