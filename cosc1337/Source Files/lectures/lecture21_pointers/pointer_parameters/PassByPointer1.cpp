// PointerParam.cpp
#include <iostream>

using namespace std;

void setToSeven(int * param)
{
    *param = 7;
}

/*
void setToSeven(int & param)
{
    param = 7;
}
*/

int main() {
    int num = 14;
    
    // make function call here
    setToSeven(&num);
    //setToSeven(num);
    
    cout << num << endl;
    
    system("PAUSE");
    return 0;
}
