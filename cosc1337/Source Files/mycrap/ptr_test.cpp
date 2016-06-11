 #include <iostream>
 using namespace std;

 void zeroIt(int * p) {
	 *p = 0;
 }

 void doubleIt(int * p) {

	 *p *=2;
 }

 int main()
{
	 int x = 25, y = 50;
	 int * xp = NULL, * yp = NULL;
	 xp = &x;
	 yp = &y;
	 cout << *xp << " " << *yp << endl;

	 int * temp = xp;
	 xp = yp;
	 yp = temp;
	 cout << *xp << " " << *yp << endl;

	 int temp2 = *xp;
	 *xp = *yp;
	 *yp = temp2;
	 cout << *xp << " " << *yp << endl;

	 int * ptr = NULL;
	 int enrollment[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	 ptr = &enrollment[19];

	 int anumber = 5;
	 cout << anumber << endl;
	 doubleIt(&anumber);
	 cout << anumber << endl;
	 zeroIt(&anumber);
	 cout << anumber << endl;

	 int a[5] = {0,10,20,30,40};
	 int k=3;
	 int * p = a + 1;

	 cout << a[k] << endl;		//30
	 cout << *(a+k) << endl;	//30
	 cout << p[k] << endl;		//40
	 cout << p[*a] << endl;		//10
	 return 0;
 }
