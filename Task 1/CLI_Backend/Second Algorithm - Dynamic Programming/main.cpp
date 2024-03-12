#include <bits/stdc++.h>
using namespace std;

// Structure to hold information about a tile
struct TileInfo {
    int size;     // Size of the tile
    int startX;   // Starting X-coordinate of the tile
    int startY;   // Starting Y-coordinate of the tile
};

// Function to place a tile at given coordinates
void placeTile(int x1, int y1, int x2, int y2, int x3, int y3, int grid[][128]) {
    static int count = 0;  // Counter for the tile colors
    count++;  // Increment the color counter
    int color = count % 3 + 1;  // Calculate the color (1, 2, or 3)
    grid[x1][y1] = color;  // Set color in grid
    grid[x2][y2] = color;  // Set color in grid
    grid[x3][y3] = color;  // Set color in grid
}

// Function to fill the grid with L-trominoes iteratively
void tile(int size, int startX, int startY, int grid[][128]) {
    stack<TileInfo> tiles;  // Stack to hold tile information

    // Push initial tile onto the stack
    tiles.push({size, startX, startY});

    // Iterate until all tiles are processed
    while (!tiles.empty()) {
        // Get the current tile from the stack
        TileInfo current = tiles.top();
        tiles.pop();

        // Variables to store hole coordinates
        int holeRow, holeCol;

        // Find the hole location in the current tile
        for (int i = current.startX; i < current.startX + current.size; i++) {
            for (int j = current.startY; j < current.startY + current.size; j++) {
                if (grid[i][j] != 0) {
                    holeRow = i;
                    holeCol = j;
                }
            }
        }

        // Base case: if the tile size is 2x2
        if (current.size == 2) {

            cout << "hole is at "<< holeRow << holeCol <<endl;
            if ( holeRow == current.startX && holeCol == current.startY)
                placeTile(current.startX , current.startY + 1,
                          current.startX + 1, current.startY + 1,
                          current.startX + 1, current.startY, grid);
            if ( holeRow == current.startX && holeCol == current.startY + 1)
                placeTile(current.startX , current.startY,
                          current.startX + 1, current.startY + 1,
                          current.startX + 1, current.startY, grid);
            if ( holeRow == current.startX +1 && holeCol == current.startY)
                placeTile(current.startX , current.startY,
                          current.startX , current.startY + 1,
                          current.startX + 1, current.startY + 1, grid);
            if ( holeRow == current.startX +1 && holeCol == current.startY + 1)
                placeTile(current.startX , current.startY,
                          current.startX , current.startY + 1,
                          current.startX + 1, current.startY, grid);

            continue;  // Skip to next iteration
        }

        // Calculate half of the tile size
        int half = current.size / 2;

        // Place L-trominoes in the respective quadrants based on the location of the hole

        //hole in the first quadrant
        if (holeRow < current.startX + half && holeCol < current.startY + half)
            //put a hole in the first second and third quadrants
            placeTile(current.startX + half, current.startY + half - 1,
                      current.startX + half, current.startY + half,
                      current.startX + half - 1, current.startY + half, grid);

            //hole in the second quadrant
        else if (holeRow >= current.startX + half && holeCol < current.startY + half)
            placeTile(current.startX + half - 1, current.startY + half,
                      current.startX + half, current.startY + half,
                      current.startX + half - 1, current.startY + half - 1, grid);

            //hole in the third quadrant
        else if (holeRow < current.startX + half && holeCol >= current.startY + half)
            placeTile(current.startX + half, current.startY + half - 1,
                      current.startX + half, current.startY + half,
                      current.startX + half - 1, current.startY + half - 1, grid);

            //hole in the fourth quadrant
        else if (holeRow >= current.startX + half && holeCol >= current.startY + half)
            placeTile(current.startX + half - 1, current.startY + half,
                      current.startX + half, current.startY + half - 1,
                      current.startX + half - 1, current.startY + half - 1, grid);

        // Push smaller tiles into the stack for further processing
        tiles.push({half, current.startX, current.startY + half});
        tiles.push({half, current.startX, current.startY});
        tiles.push({half, current.startX + half, current.startY});
        tiles.push({half, current.startX + half, current.startY + half});
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if command-line arguments are provided
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <gridSize> <holeRow> <holeCol>" << endl;
        return 1;  // Exit with error status
    }

    // Parse command-line arguments to get grid size and hole position
    int gridSize = strtol(argv[1], nullptr, 10);
    int xCoordinate = strtol(argv[2], nullptr, 10);
    int yCoordinate = strtol(argv[3], nullptr, 10);

    // Define grid size and initialize grid with zeros
    int grid[128][128] = {0};

    // Specify coordinates where a tile cannot be placed
    grid[xCoordinate][yCoordinate] = -1;

    // Fill the grid with L-trominoes using iterative approach
    tile(gridSize, 0, 0, grid);

    // Print the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cout << grid[i][j] << " \t";  // Print each cell value separated by a tab
        }
        cout << endl;  // Move to the next line after printing each row
    }

    return 0;  // Indicate successful completion of the program
}
