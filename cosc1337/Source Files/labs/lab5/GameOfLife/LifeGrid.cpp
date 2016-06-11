#include "LifeGrid.h"
#include <cstdlib>
#include <ctime>
#include <string>

/* Utility function for wrapping the array indices around to the
   other side of the grid */
int wrap(int n, int m) {
    return (n<0 ? (m-(-n-1)%m)-1 : n%m);
}

LifeGrid::LifeGrid(int windowWidth, int windowHeight) {
    cellWidth = windowWidth / GRID_NUM_COLS;
    cellHeight = windowHeight / GRID_NUM_ROWS;
    if (cellHeight == 0 || cellWidth == 0) {
        cout << "Error! Window is not big enough for ";
		cout << GRID_NUM_ROWS << " by " << GRID_NUM_COLS << " grid." << endl;
	}
	// this nested loop randomly initializes the grid
    srand(time(0));
 //   for (int row=30; row<GRID_NUM_ROWS; row++) {
 //      for (int col=30; col<GRID_NUM_COLS; col++) {
 //           grid[row][col] = 0;
            // ten percent of the time, make the cell start as living
//            if (rand()%10 == 0)
//                grid[row][col] = 1;
//        }
//    }
	// this line creates a particular pattern from a file, but it
	// probably won't last long if it is on top of the random cells.
	readObjectFromFile("block.txt", 10, 10);
	readObjectFromFile("blinker.txt", 30, 30);
	readObjectFromFile("downRightGlider.txt", 50, 50);
    readObjectFromFile("gosperGliderGun.txt", 0, 50);
	readObjectFromFile("pulsar.txt",75, 75);
}

void LifeGrid::readObjectFromFile(string filename, 
								  int topLeftRow, int topLeftCol) {
    ifstream inFile;
    inFile.open(filename.data());
    if (inFile.is_open()) {
        int patternRows, patternCols;
        char ch;
        inFile >> patternCols >> patternRows;
        if (topLeftRow+patternRows <= GRID_NUM_ROWS && 
			topLeftCol+patternCols <= GRID_NUM_COLS) {
            for (int row=0; row<patternRows; row++) {
                for (int col=0; col<patternCols; col++) {            
                    inFile >> ch;
                    if (toupper(ch) == 'X')
                        grid[topLeftRow+row][topLeftCol+col] = 1;
                }
            }
        }
        else {
            cout << "Pattern is too big to fit in specified area." << endl;
        }
    }
    else {
        cout << "Error. Couldn't open " << filename;
		cout << " for reading." << endl;
	}
}

#define CLIP(n, min, max) (((n)<(min))?(min):(((n)>(max))?(max):(n)))

/* For drawing black and white cells */
void LifeGrid::draw() {
    for (int row=0; row<GRID_NUM_ROWS; row++) {
        for (int col=0; col<GRID_NUM_COLS; col++) {    
            if (grid[row][col] > 0)
                setColor(BLACK);
            else
                setColor(WHITE);
            drawFilledBox(col*cellWidth, 
						  (GRID_NUM_ROWS-row-1)*cellHeight, 
						  (col+1)*cellWidth, 
						  (GRID_NUM_ROWS-row)*cellHeight);
        }
    }
}

/* For drawing blue cells where darker = longer lived */
void LifeGrid::drawColored() {
    for (int row=0; row<GRID_NUM_ROWS; row++) {
        for (int col=0; col<GRID_NUM_COLS; col++) {    
            if (grid[row][col] > 0)
                setColor(CLIP(0.1*grid[row][col], 0.0, 1.0), 0, 
                         CLIP(1.0-0.1*grid[row][col], 0.0, 1.0));
            else
                setColor(WHITE);
            drawFilledBox(col*cellWidth, 
						  (GRID_NUM_ROWS-row-1)*cellHeight, 
						  (col+1)*cellWidth, 
						  (GRID_NUM_ROWS-row)*cellHeight);
        }
    }
}

int LifeGrid::getNumLivingNeighbors(int row, int col) {
	int num = 0;

	for (int i = row - 1; i <= row + 1; i++)
		for (int j = col - 1; j <= col + 1; j++) {
			if (!((i == row) && (j == col))) {
				if (grid[wrap(i, GRID_NUM_ROWS)][wrap(j, GRID_NUM_COLS)] >= 1)
					num += 1;
			}
		}

    return num;
}

void LifeGrid::update() {
	// compute new cells in tempGrid
	for (int row = 0; row<GRID_NUM_ROWS; row++) 
		for (int col = 0; col < GRID_NUM_COLS; col++) {
			//cout << "Number of live neighbors is: " << getNumLivingNeighbors(row, col) << " for row[" << row << "][" << col << "]" << endl;
			if (grid[row][col] == 1 && getNumLivingNeighbors(row, col) < 2)
				tempGrid[row][col] = 0;
			else if (grid[row][col] == 1 && getNumLivingNeighbors(row, col) > 3)
				tempGrid[row][col] = 0;
			else if (grid[row][col] == 1 && getNumLivingNeighbors(row, col) == 2)
				tempGrid[row][col] = 1;
			else if (grid[row][col] == 1 && getNumLivingNeighbors(row, col) == 3)
				tempGrid[row][col] = 1;
			else if (grid[row][col] == 0 && getNumLivingNeighbors(row, col) == 3)
				tempGrid[row][col] = 1;
		}

	// copy tempGrid back into grid
		for (int row = 0; row<GRID_NUM_ROWS; row++) 
			for (int col = 0; col < GRID_NUM_COLS; col++) 
				grid[row][col] = tempGrid[row][col];

    // sleep to slow down animate so it can be seen
#if defined(_WIN32)
    // on Windows: in milliseconds, 
    // so 500 = 0.5 seconds between updates
    Sleep((DWORD)500);
#else
	// on Macs and Linux: in microseconds, 
    // so 500000 = 0.5 seconds between updates
    usleep(500000);
#endif
}
