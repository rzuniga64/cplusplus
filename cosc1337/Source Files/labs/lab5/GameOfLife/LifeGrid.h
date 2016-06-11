#ifndef LIFE_GRID_H
#define LIFE_GRID_H

#include <iostream>
#include <fstream>
#include "Graphics.h"

#define GRID_NUM_ROWS 100
#define GRID_NUM_COLS 100

class LifeGrid {
public:
	/* constructor:
	   inputs: size of window
	   Stores size of grid cells and then initializes grid
	*/
    LifeGrid(int windowWidth, int windowHeight);
	/* draw:
	   inputs/outputs: none
	   Draws the current state of the grid in the window, with 
	   black for living cells and white for dead ones. */
    void draw();
	/* drawColored:
	   inputs/outputs: none
	   Draws the current state of the grid with shades of blue
	   for living cells, and white for dead cells.  The longer a
	   cell has been alive, the darker it's color. */
    void drawColored();
	/* update:
	   inputs/outputs: none
	   Computes the new state of each cell based on the previous 
	   time step according to the rules of the game.
	   NEEDS TO BE COMPLETED! */
    void update();
private:
	/* getNumLivingNeighbors:
	   inputs: one pair of grid indices, indicating a particular grid cell
	   output: the number of living neighbors of the indicated cell
	   Computes how many of the 8 contiguous neighbors of the input 
	   cell are living, and returns that number.
	   NEEDS TO BE COMPLETED! */
    int getNumLivingNeighbors(int row, int col);
	/* readObjectFromFile:
	   inputs: file name and indices of top left corner
	   output: none
	   Fills the specified regions of the grid with the cells given in
	   the file.  The file format has one line with the x and y size of
	   the pattern, and then has a line for each line of the pattern where
	   a '-' character represents a dead cell and a 'X' character 
	   represents a living cell. */
    void readObjectFromFile(string filename, int topLeftRow, int topLeftCol);

	/* data members*/
    int grid[GRID_NUM_ROWS][GRID_NUM_COLS]; 	// grid of cells
    int tempGrid[GRID_NUM_ROWS][GRID_NUM_COLS];	// temp grid for update
    int cellHeight;							    // size of cells (pixels)
    int cellWidth;
};

#endif
