 // This program uses the address of each element in the array.
 #include <iostream>
 #include <iomanip>
 using namespace std;

 int main()
	 {
	 int * p = new int[5];
	 for (int i = 0; i < 5; i++) {
		 p[i] = i;
	 }

	 delete [] p;
	 return 0;
 }
