#include <iostream>

using namespace std;

int wrap(int n, int maxn) {

	int hourHand = 0;
	if (n >= 0)
		hourHand = n % maxn;
	else if (n < 0) {
		hourHand = (maxn-(-n-1)%maxn)-1;
	}
	return hourHand;
}

int main() {

	const int ROWS = 3;
	const int COLS = 3;

	int grid[ROWS][COLS] = {{34, 56, 78}, {56, 78, 90}, {34, 56, 77}};

	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < COLS; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	int row = 1;
	int col = 1;

	for (int i = row-1; i <= row+1; i++)
		for (int j = col-1; j <= col + 1; j++){
			if (!((i == row) && (j == col)))
				grid[wrap(i,ROWS)][wrap(j,COLS)] = 1;
		}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
