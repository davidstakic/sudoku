#include <iostream>
#include "Sudoku9.hpp"

int main() {
    Sudoku9 sudoku;

    sudoku.generateSudoku();

    sudoku.files.writeIntoFile(sudoku.getGrid());

	return 0;
}