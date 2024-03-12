#include <iostream>
#include <cstdlib>
#include <random> // Include the C++11 random library for random number generation
#include <cstring>

using namespace std;

int gridSize, xCoordinate, yCoordinate, count = 0; // Declare global variables to store grid size, coordinates, and tile count
int grid[128][128]; // Declare a 2D array to represent the grid

// Function to place a tile at given coordinates
void placeTile(int x1, int y1, int x2, int y2, int x3, int y3) {
    static random_device rd; // Create a random device object
    static mt19937 gen(rd()); // Create a random number generator engine
    uniform_int_distribution<> dis(1, RAND_MAX); // Create a uniform distribution for random numbers

    ::count = dis(gen); // Generate a random count value using the random number generator
    grid[x1][y1] = ::count % 3 + 1; // Mark the tile in the grid with a random number
    grid[x2][y2] = ::count % 3 + 1; // Mark the tile in the grid with a random number
    grid[x3][y3] = ::count % 3 + 1; // Mark the tile in the grid with a random number
}

// Function based on divide and conquer to fill the grid with tiles recursively
void tile(int size, int startX, int startY) {
    int holeRow, holeCol; // Variables to store the coordinates of the hole
    if (size == 2) { // Base case: if the grid size is 2x2
        static random_device rd; // Create a random device object
        static mt19937 gen(rd()); // Create a random number generator engine
        uniform_int_distribution<> dis(1, RAND_MAX); // Create a uniform distribution for random numbers

        ::count = dis(gen); // Generate a random count value using the random number generator
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[startX + i][startY + j] == 0) { // Check if the cell is empty
                    grid[startX + i][startY + j] = ::count % 3 + 1; // Place the tile in the grid with a random number
                }
            }
        }
        return; // Return from the function
    }
    // Finding hole location
    for (int i = startX; i < startX + size; i++) {
        for (int j = startY; j < startY + size; j++) {
            if (grid[i][j] != 0) // Check if the cell is not empty
                holeRow = i, holeCol = j; // Store the coordinates of the hole
        }
    }

    // Calculate half of the 'size' variable and store it in the 'half' variable
    int half = size / 2;

    // Placing tiles in the respective quadrants based on the location of the hole
    if (holeRow < startX + half && holeCol < startY + half) // If the hole is in the 1st quadrant
        placeTile(startX + half, startY + half - 1, startX + half, startY + half, startX + half - 1, startY + half);
    else if (holeRow >= startX + half && holeCol < startY + half) // If the hole is in the 3rd quadrant
        placeTile(startX + half - 1, startY + half, startX + half, startY + half, startX + half - 1, startY + half - 1);
    else if (holeRow < startX + half && holeCol >= startY + half) // If the hole is in the 2nd quadrant
        placeTile(startX + half, startY + half - 1, startX + half, startY + half, startX + half - 1, startY + half - 1);
    else if (holeRow >= startX + half && holeCol >= startY + half) // If the hole is in the 4th quadrant
        placeTile(startX + half - 1, startY + half, startX + half, startY + half - 1, startX + half - 1, startY + half - 1);

    // Recursively divide the grid into 4 quadrants and fill them with tiles
    tile(half, startX, startY + half); // Top right quadrant
    tile(half, startX, startY); // Top left quadrant
    tile(half, startX + half, startY); // Bottom left quadrant
    tile(half, startX + half, startY + half); // Bottom right quadrant
}

// Driver program to test above functions
int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <gridSize> <holeRow> <holeCol>" << endl;
        return 1;
    }

    // Parse command-line arguments
    gridSize = strtol(argv[1], nullptr, 10);
    xCoordinate = strtol(argv[2], nullptr, 10) - 1;
    yCoordinate = strtol(argv[3], nullptr, 10) - 1;

    // Define grid size and initialize grid with zeros
    memset(grid, 0, sizeof(grid)); // Initialize grid with zeros

    // Specify coordinates where a tile cannot be placed
    grid[xCoordinate][yCoordinate] = -1; // Mark the cell as unavailable for placing a tile

    // Fill the grid with tiles recursively using divide and conquer approach
    tile(gridSize, 0, 0); // Start with the entire grid

    // Print the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++)
            cout << grid[i][j] << " \t"; // Print each cell value separated by a tab
        cout << "\n"; // Move to the next line after printing each row
    }

    return 0; // Indicate successful completion of the program
}
