#include <iostream>

using namespace std;

int wrap(int n, int maxn) {

	int hourHand;
	if (n >= 0)
		hourHand = n % maxn;
	else if (n < 0) {
		hourHand =  (maxn - ( -n -1) % maxn) -1;
	}

	return hourHand;
}

int main() {

	const int nrows = 4;
	const int ncols = 5;
	const int row = 2;
	const int col = 2;

	int grid[nrows][ncols] = {{35, 48, 20, 21, 34}, {19, 39, 6, 11, 48}, {26, 31, 13, 34, 36}, {31, 26, 31, 19, 22}};

	// the element  of an existing two-dimensional integer  array  called grid being set to the element  to the left of it in the grid.
	// grid[row][col] = grid[row][wrap(col-1,ncols)];

	// an element  of an existing two-dimensional integer  array  called grid being set to the element  above it in the grid.
	// grid[row][col] = grid[wrap(row-1,nrows)][col];

	int irow, icol;
	for (int i = 0; i < nrows-row; i++)
		for (int j = 0; j < ncols-col; j++) {
			if ((i != row) && (j != col))
				irow = wrap(i+row-1,nrows);
				icol = wrap(j+col-1,ncols);
				grid[wrap(i+row-1,nrows)][wrap(j+col-1,ncols)] = 1;
		}
	return 0;
}
