#pragma once
#include "Files.hpp"

class Sudoku9 {
private:
	int grid[9][9];
public:
	Files files;
	Sudoku9();

	const int(*getGrid() const)[9];
	void setGrid(const int newGrid[9][9]);

	bool isValidPosition(int number, int row, int column);
	bool isValidRow(int number, int row);
	bool isValidColumn(int number, int column);
	bool isValidSubMatrix(int number, int row, int column);

	int countNumbersInSubMatrix(int row, int column);
	bool anyGreaterThanSix();
	
	bool solveSudoku(int row, int column);

	int getRandomNumber();
	int getRandomCell();
	int howMuchToRemove();

	void fillSubMatrix(int row, int column);
	void fillDiagonal();
	void removeNumbers();
	void generateSudoku();

	void resetGrid();
};