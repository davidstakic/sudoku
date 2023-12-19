#include <iostream>
#include "Files.hpp"

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    Files test("test.txt");

    test.writeIntoFile(grid);
    int** readGrid = test.readFromFile();

    // Display the read grid (for verification)
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << readGrid[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    // Deallocate memory for the read grid
    for (int i = 0; i < 9; ++i) {
        delete[] readGrid[i];
    }
    delete[] readGrid;

	return 0;
}