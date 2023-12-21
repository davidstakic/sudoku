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

	/**
	 * @brief Checks if the given number can be setted to the given position by checking if number is present in the row, column and 3x3 submatrix.
	 * @param number The number we want to put in the sudoku grid.
	 * @param row Index of the row where we want to put our number.
	 * @param column Index of the column where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidPosition(int number, int row, int column);
	/**
	 * @brief Checks if the given number can be setted to the given row by checking if number is present in the row.
	 * @param number The number we want to put in the sudoku grid.
	 * @param row Index of the row where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidRow(int number, int row);
	/**
	 * @brief Checks if the given number can be setted to the given column by checking if number is present in the column.
	 * @param number The number we want to put in the sudoku grid.
	 * @param column Index of the column where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidColumn(int number, int column);
	/**
	 * @brief Checks if the given number can be setted to the given position by checking if number is present in the 3x3 submatrix.
	 * @param number The number we want to put in the sudoku grid.
	 * @param row Index of the row where we want to put our number.
	 * @param column Index of the column where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidSubMatrix(int number, int row, int column);

	/**
	 * @brief Counts how many cells are filled in the submatrix.
	 * @param row Index of the row in which the submatrix is.
	 * @param column Index of the column in which the submatrix is.
	 * @return Returns number of filled cells in the submatrix.
	*/
	int countCellsInSubMatrix(int row, int column);
	/**
	 * @brief Checks if there is any submatrix in the grid that has more than 6 cells filled.
	 * This function is used while removing cells when generating sudoku grid, to ensure that no submatrix has more than 6 cells filled.
	 * @return Returns true if there is submatrix that has more than 6 cells filled, false if there isn't.
	*/
	bool anyGreaterThanSix();

	/**
	 * @brief Solves sudoku grid using backtrack algorithm.
	 * @param row Index of the row where solving starts.
	 * @param column Index of the column where solving starts.
	 * @return Returns true if solution is found, false if isn't.
	*/
	bool solveSudoku(int row, int column);

	/**
	 * @brief Generates random number between 1 and 9.
	 * This function is used while generating sudoku grid to fill the cells.
	 * @return Returns random generated number between 1 and 9.
	*/
	int getRandomNumber();
	/**
	 * @brief Generates random nubmer between 0 and 80.
	 * This functions is used for generating sudoku to determine which cell we should removed from solved sudoku grid.
	 * @return Returns random generated number between 0 and 80.
	*/
	int getRandomCell();
	/**
	 * @brief Generates random number between 43 and 60.
	 * This functions is used for generating sudoku to indicate how much cells should be removed from solved sudoku grid.
	 * @return Returns random generated number between 43 and 60.
	*/
	int howMuchToRemove();

	void fillSubMatrix(int row, int column);
	void fillDiagonal();
	void removeCells();
	void generateSudoku();

	/**
	 * @brief Sets all grid cells to 0.
	*/
	void resetGrid();
};