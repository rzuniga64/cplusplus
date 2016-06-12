#include "Storage.h"

int Storage::get(int index) const {
	return cells[index].read();
}

void Storage::put(int index, int value) {
	cells[index].write(value);
}
