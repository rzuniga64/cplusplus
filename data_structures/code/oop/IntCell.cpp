#include <iostream>
#include "IntCell.h"

using namespace std;

int IntCell::read() const {
	return storedValue;
}

void IntCell::write(int x) {
	storedValue = x;
}
