#include "Sudoku9.hpp"

Sudoku9::Sudoku9() : files("test.txt")
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			grid[i][j] = 0;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

const int(*Sudoku9::getGrid() const)[9]{
    return grid;
}

void Sudoku9::setGrid(const int newGrid[9][9])
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            grid[i][j] = newGrid[i][j];
}

bool Sudoku9::isValidPosition(int number, int row, int column)
{
	return isValidRow(number, row) && isValidColumn(number, column) && isValidSubMatrix(number, row, column);
}

bool Sudoku9::isValidRow(int number, int row)
{
	for (int i = 0; i < 9; i++)
		if (grid[row][i] == number)
			return false;
	return true;
}

bool Sudoku9::isValidColumn(int number, int column)
{
	for (int i = 0; i < 9; i++)
		if (grid[i][column] == number)
			return false;
	return true;
}

bool Sudoku9::isValidSubMatrix(int number, int row, int column)
{
	int subMatrixRowStart = row - row % 3;
	int subMatrixColStart = column - column % 3;

	for (int i = subMatrixRowStart; i < (subMatrixRowStart + 3); i++)
		for (int j = subMatrixColStart; j < (subMatrixColStart + 3); j++)
			if (grid[i][j] == number)
				return false;
	return true;
}

int Sudoku9::countNumbersInSubMatrix(int row, int column)
{
    int count = 0;

    int subMatrixRowStart = row - row % 3;
    int subMatrixColStart = column - column % 3;

    for (int i = subMatrixRowStart; i < (subMatrixRowStart + 3); i++)
        for (int j = subMatrixColStart; j < (subMatrixColStart + 3); j++)
            if (grid[i][j] != 0)
                count++;
    return count;
}

bool Sudoku9::anyGreaterThanSix()
{
    for (int i = 0; i <= 6; i += 3)
        for (int j = 0; j <= 6; j += 3) {
            int count = countNumbersInSubMatrix(i, j);

            if (count > 6)
                return true;
        }

    return false;
}

bool Sudoku9::solveSudoku(int row, int column)
{
    if (row == 8 && column == 9)
        return true;

    if (column == 9) {
        row++;
        column = 0;
    }

    if (grid[row][column] != 0)
        return solveSudoku(row, column + 1);

    for (int number = 1; number <= 9; number++)
    {
        if (isValidPosition(number, row, column))
        {
            grid[row][column] = number;

            if (solveSudoku(row, column + 1))
                return true;
        }

        grid[row][column] = 0;
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

void Sudoku9::fillSubMatrix(int row, int column)
{
    int number;
    for (int i = row; i < (row + 3); i++)
        for (int j = column; j < (column + 3); j++) {
            do {
                number = getRandomNumber();
            } while (!isValidSubMatrix(number, row, column));

            grid[i][j] = number;
        }
}

void Sudoku9::fillDiagonal()
{
    fillSubMatrix(0, 0);
    fillSubMatrix(3, 3);
    fillSubMatrix(6, 6);
}

void Sudoku9::removeNumbers()
{
    int count = howMuchToRemove();
    while (count != 0) {
        int cell = getRandomCell();
        int row = cell / 9;
        int column = cell % 9;

        int numbersInSubMatrix = countNumbersInSubMatrix(row, column);
        bool anyLeft = anyGreaterThanSix();

        if (column != 0)
            --column;
        if (grid[row][column] != 0 && (numbersInSubMatrix > 6 || (numbersInSubMatrix <= 6 && !anyLeft))) {
            grid[row][column] = 0;
            count--;
        }
    }
}

void Sudoku9::generateSudoku()
{
    resetGrid();
    fillDiagonal();
    solveSudoku(0, 0);
    removeNumbers();
}

void Sudoku9::resetGrid()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            grid[i][j] = 0;
}
