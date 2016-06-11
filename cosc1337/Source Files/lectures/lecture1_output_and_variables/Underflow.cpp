#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float num = pow(10.0, -45);
    
    cout << "num: " << num << endl;
    
    cout << "dividing num by 10..." << endl;
    num /= 10.0;
    cout << "num: " << num << endl;
    
    return 0;
}
