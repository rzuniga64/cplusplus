#include <iostream>
#include <cmath>

using namespace std;

struct Test {
 	int n;
 	int maxn;
 };

int wrap(int n, int maxn) {

	int hourHand = 0;
	if (n >= 0)
		hourHand = n % maxn;
	else if (n < 0) {;
		hourHand = (maxn - ( -n -1) % maxn) -1;
//		hourHand = maxn -( -n + COLS) % COLS;
	}

	cout << "Hour hand is at: " << hourHand << endl;

	return hourHand;
}


 bool doTest(int n, int maxn) {
 	int student = wrap(n, maxn);
 	int correct = wrap(n, maxn);
 	if (student != correct) {
 		cerr << "When your function was passed  " << n << " for n and " << maxn << " for m";
 		cerr << ", your function returned " << student << " rather than the expected " << correct << endl;
 		return false;
 	}
 	return true;
 }

#define ROWS 3
#define COLS 3

 int main() {

 	const int SIZE = 8;
 	Test tests[SIZE] = {{17,15}, {35,17}, {0,15}, {26, 13}, {-1,13}, {-14, 13}, {-16, 15}, {-27, 13}};
 	bool success = true;
 	for (int i=0; i < SIZE; i++) {
	if (!doTest(tests[i].n, tests[i].maxn))
 			success = false;
 	}

 	if (!success) {
 		cout << 1;
 		return 1;
 	}
 	cout << 0;

 	int count = 10;
 	int grid[ROWS][COLS];

 	for (int i=0; i < ROWS; i++)
 		for (int j=0; j < COLS; j++)
 			grid[i][j] = ++count;


 	int row = 0;
 	int col = 0;
 	int leftoffset = wrap(-1, row*COLS+col);
 	grid[row][col] = grid[leftoffset/COLS][leftoffset%COLS];

 	return 0;
}
