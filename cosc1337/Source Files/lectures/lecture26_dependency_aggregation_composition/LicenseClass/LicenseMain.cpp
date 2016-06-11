#include <iostream>
#include "License.h"

using namespace std;

void printDate(Date d) {
	d.display();
}

Date getToday() {
	Date today;
	return today;
}

int main()
{
	/*
	Date d1;
	d1.display();
	Date d2(3,3,2013);
	d2.display();
	Date d3(d1); //copy constructor
	Date d4 = d1; //copy constructor

	printDate(d1);
	*/

    License autry("Gene Autry", "horse riding", 9, 29, 1947);
    License astaire("Fred Astaire", "dancing", 5, 10, 1939);
    License stewart("Jon Stewart", "comedy", 11, 28, 2014);
    
    autry.display();
    astaire.display();
    stewart.display();
    
    return 0;
}
