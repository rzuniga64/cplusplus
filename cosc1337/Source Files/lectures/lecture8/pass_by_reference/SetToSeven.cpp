#include <iostream>

using namespace std;

void setToSeven(int &);

int main()
{
    int num = 16;
    
    setToSeven(num);
    
    cout << num << endl;
    
    system("PAUSE");
    return 0;
}

void setToSeven(int & i)
{
    i = 7;
}
