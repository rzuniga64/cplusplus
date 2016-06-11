/*
 *	Purpose: Print a message that will greet the writer
 *			 by name.
 *	Input:	 None
 *	Output:  The word "Hello" followed by the name on
 *			 seperate lines, and displays a little box made
 *			 of * symbols around the message.
 */

#include <iostream>

using namespace std;

int main()
{
	string stars = "*********";

	cout << stars << endl;
    cout << "* Hello *" << endl;
    cout << "* Raul! *" << endl;
    cout << stars << endl;
    system("PAUSE");
    return 0;
}
