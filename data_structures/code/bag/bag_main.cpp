#include <iostream>
#include "Bag.h"

using namespace std;

int main() {

	Bag b;
	b.add(4);
	b.add(8);
	b.add(4);

	cout << "size " << b.size() << endl;
	cout << "how many 4's: " << b.occurrences(4) << endl << endl;
	b.remove(4);
	cout << "removed a 4" << endl;
	cout << "size " << b.size() << endl;
	cout << "how many 4's: " << b.occurrences(4) << endl << endl;

	Bag c(b);
	cout << "copied to c" << endl;
	cout << "size " << c.size() << endl;
	cout << "how many 4's: " << c.occurrences(4) << endl << endl;
	b.add(10);
	cout << "added 10 to b" << endl;
	cout << "b.size " << b.size() << endl;
	cout << "c.size " << c.size() << endl << endl;
	cout << "starting to add 20 items" << endl;
	for (int i = 0; i<20; i++)
		b.add(33);
	cout << "added 20 more items to b" << endl;
	return 0;
}