/**
 * @file Sudoku9.hpp
 * @brief Defines the Sudoku9 class, representing a 9x9 Sudoku grid with functionalities for generating, solving, and manipulating Sudoku puzzles.
 * @author David Stakic
 * @date 2023-12-22
 */

#pragma once
#include "Files.hpp"

/**
* @class Sudoku9
* @brief Represents a 9x9 Sudoku grid and provides functionality for generating, solving, and manipulating Sudoku puzzles.
*/
class Sudoku9 {
private:
	int grid[9][9];
	int numberOfValid;
	int numberOfFaults;
	int gameCounter;
public:
	Files files;
	/**
	 * @brief Constructs a Sudoku9 object, setting all 9x9 sudoku grid cells to 0.
	 * The default constructor sets up the initial state of the Sudoku puzzle.
	 */
	Sudoku9();

	const int(*getGrid() const)[9];
	void setGrid(const int newGrid[9][9]);

	/**
	 * @brief Checks if the given number can be setted to the given position by checking if number is present in the row, column and 3x3 submatrix.
	 * @param number The number we want to put in the 9x9 sudoku grid.
	 * @param row Index of the row where we want to put our number.
	 * @param column Index of the column where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidPosition(int number, int row, int column);
	/**
	 * @brief Checks if the given number can be setted to the given row by checking if number is present in the row.
	 * @param number The number we want to put in the 9x9 sudoku grid.
	 * @param row Index of the row where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidRow(int number, int row);
	/**
	 * @brief Checks if the given number can be setted to the given column by checking if number is present in the column.
	 * @param number The number we want to put in the 9x9 sudoku grid.
	 * @param column Index of the column where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidColumn(int number, int column);
	/**
	 * @brief Checks if the given number can be setted to the given position by checking if number is present in the 3x3 submatrix.
	 * @param number The number we want to put in the 9x9 sudoku grid.
	 * @param row Index of the row where we want to put our number.
	 * @param column Index of the column where we want to put our number.
	 * @return Returns true if the position is valid, false if isn't valid.
	*/
	bool isValidSubMatrix(int number, int row, int column);

	/**
	 * @brief Counts how many cells are filled in the 3x3 submatrix.
	 * @param row Index of the row in which the 3x3 submatrix is.
	 * @param column Index of the column in which the 3x3 submatrix is.
	 * @return Returns number of filled cells in the 3x3 submatrix.
	*/
	int countCellsInSubMatrix(int row, int column);
	/**
	 * @brief Checks if there is any 3x3 submatrix in the 9x9 sudoku grid that has more than 6 cells filled.
	 * This function is used while removing cells when generating 9x9 sudoku grid, to ensure that no 3x3 submatrix has more than 6 cells filled.
	 * @return Returns true if there is 3x3 submatrix that has more than 6 cells filled, false if there isn't.
	*/
	bool anyGreaterThanSix();

	/**
	 * @brief Solves 9x9 sudoku grid using backtrack algorithm.
	 * @param row Index of the row where solving starts.
	 * @param column Index of the column where solving starts.
	 * @return Returns true if solution is found, false if isn't.
	*/
	bool solveSudoku(int row, int column);

	/**
	 * @brief Generates random number between 1 and 9.
	 * This function is used while generating 9x9 sudoku grid to fill the cells.
	 * @return Returns random generated number between 1 and 9.
	*/
	int getRandomNumber();
	/**
	 * @brief Generates random nubmer between 0 and 80.
	 * This functions is used for generating 9x9 sudoku grid to determine which cell we should removed from solved 9x9 sudoku grid.
	 * @return Returns random generated number between 0 and 80.
	*/
	int getRandomCell();
	/**
	 * @brief Generates random number between 43 and 60.
	 * This functions is used for generating 9x9 sudoku grid to indicate how much cells should be removed from solved 9x9 sudoku grid.
	 * @return Returns random generated number between 43 and 60.
	*/
	int howMuchToRemove();

	/**
	 * @brief Fills 3x3 submatrix with randomly generated numbers from 1 to 9 and ensures that no numbers are repeated.
	 * @param row Index of the row where generating starts.
	 * @param column Index of the column where generating starts.
	*/
	void fillSubMatrix(int row, int column);
	/**
	 * @brief Fills 3x3 submatrices on the main diagonal with random numbers from 1 to 9 and ensures that no numbers are repeated.
	*/
	void fillDiagonal();
	/**
	 * @brief Removes a random cell number from the 9x9 sudoku grid solution.
	 * The number of cells that will be deleted is between 43 and 60.
	 * The cells that will be deleted are randomly determined.
	*/
	void removeCells();
	/**
	 * @brief Generates a 9x9 sudoku grid by first filling the 3x3 submatrices on the main diagonal,
	 * then solves the 9x9 sudoku grid and removes a randomly generated number of cell from the solved sudoku 9x9 grid.
	*/
	void generateSudoku();

	/**
	 * @brief Checks if 9x9 sudoku grid is solved by checking whether there is a valid number in each cell.
	 * @return Returns true if 9x9 sudoku grid is solved, false if isn't
	*/
	bool isSolved();
	/**
	 * @brief Calculates the number of valid numbers in cells, number of invalid numbers in cells and game count.
	*/
	void calculateStatistics();

	/**
	 * @brief Sets all 9x9 sudoku grid cells to 0.
	*/
	void resetGrid();
};