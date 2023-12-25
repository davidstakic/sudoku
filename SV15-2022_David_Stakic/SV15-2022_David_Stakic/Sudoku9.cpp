#include "Sudoku9.hpp"

Sudoku9::Sudoku9() : numberOfValid(0), numberOfFaults(0), gameCounter(0)
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			this->grid[i][j] = 0; // initially all cells are zero

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed for random numbers
}

const int(*Sudoku9::getGrid() const)[9]{
    return this->grid;
}

int(*Sudoku9::getGrid())[9]{
    return this->grid;
}

int Sudoku9::getNumberOfValid() const
{
    return this->numberOfValid;
}

int Sudoku9::getNumberOfFaults() const
{
    return this->numberOfFaults;
}

int Sudoku9::getGameCounter() const
{
    return this->gameCounter;
}

bool Sudoku9::isValidPosition(const int& number, const int& row, const int& column)
{
	return isValidRow(number, row) && isValidColumn(number, column) && isValidSubMatrix(number, row, column);
}

bool Sudoku9::isValidRow(const int& number, const int& row)
{
	for (int i = 0; i < 9; i++)
		if (this->grid[row][i] == number)
			return false;
	return true;
}

bool Sudoku9::isValidColumn(const int& number, const int& column)
{
	for (int i = 0; i < 9; i++)
		if (this->grid[i][column] == number)
			return false;
	return true;
}

bool Sudoku9::isValidSubMatrix(const int& number, const int& row, const int& column)
{
	int subMatrixRowStart = row - row % 3;
	int subMatrixColStart = column - column % 3;

	for (int i = subMatrixRowStart; i < (subMatrixRowStart + 3); i++)
		for (int j = subMatrixColStart; j < (subMatrixColStart + 3); j++)
			if (this->grid[i][j] == number)
				return false;
	return true;
}

int Sudoku9::countCellsInSubMatrix(const int& row, const int& column)
{
    int count = 0;

    int subMatrixRowStart = row - row % 3;
    int subMatrixColStart = column - column % 3;

    for (int i = subMatrixRowStart; i < (subMatrixRowStart + 3); i++)
        for (int j = subMatrixColStart; j < (subMatrixColStart + 3); j++)
            if (this->grid[i][j] != 0) // is it filled?
                count++;
    return count;
}

bool Sudoku9::anyGreaterThanSix()
{
    // iterating through every submatrix
    for (int i = 0; i <= 6; i += 3)
        for (int j = 0; j <= 6; j += 3) {
            int count = countCellsInSubMatrix(i, j);

            if (count > 6)
                return true;
        }

    return false;
}

bool Sudoku9::solveSudoku(int row, int column)
{
    if (row == 8 && column == 9) // end?
        return true;
    
    if (column == 9) {
        row++;
        column = 0;
    }

    // skip filled cells
    if (this->grid[row][column] != 0)
        return solveSudoku(row, column + 1);

    // trying to put every number
    for (int number = 1; number <= 9; number++)
    {
        if (isValidPosition(number, row, column))
        {
            this->grid[row][column] = number;

            if (solveSudoku(row, column + 1))
                return true;
        }

        this->grid[row][column] = 0; // if current placement do not lead to solution, backtrack
    }
    return false;
}

int Sudoku9::getRandomNumber()
{
    return std::rand() % 9 + 1;
}

int Sudoku9::getRandomCell()
{
    return std::rand() % 81;
}

int Sudoku9::howMuchToRemove()
{
    return std::rand() % 18 + 43;
}

void Sudoku9::fillSubMatrix(const int& row, const int& column)
{
    int number;
    for (int i = row; i < (row + 3); i++)
        for (int j = column; j < (column + 3); j++) {
            do {
                number = getRandomNumber();
            } while (!isValidSubMatrix(number, row, column));

            this->grid[i][j] = number;
        }
}

void Sudoku9::fillDiagonal()
{
    fillSubMatrix(0, 0);
    fillSubMatrix(3, 3);
    fillSubMatrix(6, 6);
}

void Sudoku9::removeCells()
{
    int count = howMuchToRemove();
    while (count != 0) {
        int cell = getRandomCell();
        int row = cell / 9;
        int column = cell % 9;

        int numbersInSubMatrix = countCellsInSubMatrix(row, column);
        bool anyLeft = anyGreaterThanSix();

        // remove it if has more than 6 elements or if there isn't any submatrices with more than 6 elements left
        if (this->grid[row][column] != 0 && (numbersInSubMatrix > 6 || (numbersInSubMatrix <= 6 && !anyLeft))) {
            this->grid[row][column] = 0;
            count--;
        }
    }
}

void Sudoku9::generateSudoku()
{
    resetGrid();
    fillDiagonal(); // filling independent submatrices first to speed up the proccess
    solveSudoku(0, 0); // then solving the sudoku
    removeCells();
}

bool Sudoku9::isSolved()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            // doing this to exclude this cell
            // check every cell in row, column and submatrix except this one
            int cell = this->grid[i][j];
            this->grid[i][j] = -1;

            if (cell == 0 || !isValidPosition(cell, i, j)) {
                this->grid[i][j] = cell;
                return false;
            }
            this->grid[i][j] = cell; // returning original value
        }
    return true;
}

void Sudoku9::calculateStatistics()
{
    this->numberOfValid = 0;
    this->numberOfFaults = 0;
    this->gameCounter++;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            int cell = this->grid[i][j];
            this->grid[i][j] = -1;

            if (cell == 0 || !isValidPosition(cell, i, j))
                this->numberOfFaults++;
            else
                this->numberOfValid++;

            this->grid[i][j] = cell;
        }
}

void Sudoku9::resetGrid()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            this->grid[i][j] = 0;
}
