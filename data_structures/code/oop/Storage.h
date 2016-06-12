#include "IntCell.h"
#include <vector>

using namespace std;

// Composition is when one class contains another as a member
class Storage
{
public:
	Storage(int size) : cells(size) {}

	int get(int index) const;
	void put(int index, int value);

private:
	vector<IntCell> cells;
};