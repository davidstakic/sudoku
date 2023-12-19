#pragma once

class Sudoku9 {
private:
	int grid[9][9];
public:
	Sudoku9();

	void generateSudoku();
	void solveSudoku();
};