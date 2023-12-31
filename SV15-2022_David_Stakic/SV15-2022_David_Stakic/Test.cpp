#include "Test.hpp"

Test::Test() : sudoku(), file() {}

bool Test::testIsValidPosition()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	bool v1 = sudoku.isValidPosition(4, 0, 0);
	bool v2 = sudoku.isValidPosition(9, 6, 3);
	bool v3 = sudoku.isValidPosition(3, 5, 7);
	bool v4 = sudoku.isValidPosition(5, 6, 1);

	return !v1 && !v2 && v3 && v4;
}

bool Test::testIsValidRow()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	bool v1 = sudoku.isValidRow(9, 0);
	bool v2 = sudoku.isValidRow(2, 1);
	bool v3 = sudoku.isValidRow(6, 2);
	bool v4 = sudoku.isValidRow(9, 1);

	return v1 && v2 && !v3 && !v4;
}

bool Test::testIsValidColumn()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	bool v1 = sudoku.isValidColumn(1, 0);
	bool v2 = sudoku.isValidColumn(5, 5);
	bool v3 = sudoku.isValidColumn(4, 2);
	bool v4 = sudoku.isValidColumn(8, 7);

	return v1 && v2 && !v3 && !v4;
}

bool Test::testIsValidSubMatrix()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	bool v1 = sudoku.isValidSubMatrix(1, 0, 0);
	bool v2 = sudoku.isValidSubMatrix(4, 6, 6);
	bool v3 = sudoku.isValidSubMatrix(7, 0, 3);
	bool v4 = sudoku.isValidSubMatrix(9, 3, 3);

	return v1 && v2 && !v3 && !v4;
}

bool Test::testSolveSudoku()
{
	sudoku.generateSudoku();
	bool v1 = sudoku.solveSudoku(0, 0);

	file.setFileName("../../SV15-2022_David_Stakic/test/testUnsolvable.txt");
	file.readFromFile(sudoku.getGrid());

	bool v2 = sudoku.solveSudoku(0, 0);

	return v1 & !v2;
}

bool Test::testIsSolved()
{
	sudoku.generateSudoku();
	sudoku.solveSudoku(0, 0);

	bool v1 = sudoku.isSolved();
	
	file.setFileName("../../SV15-2022_David_Stakic/test/solvedError.txt");
	file.readFromFile(sudoku.getGrid());

	bool v2 = sudoku.isSolved();

	return v1 & !v2;
}

bool Test::testGenerateSudoku()
{
	sudoku.generateSudoku();

	int(*grid)[9] = sudoku.getGrid();

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			int cell = grid[i][j];
			grid[i][j] = 0;

			if (cell != 0 && !sudoku.isValidPosition(cell, i, j)) {
				grid[i][j] = cell;
				return false;
			}

			grid[i][j] = cell;
		}

	return true && !sudoku.anyGreaterThanSix();

}

bool Test::testFillSubmatrix()
{
	sudoku.resetGrid();
	sudoku.fillSubMatrix(0, 0);

	int(*grid)[9] = sudoku.getGrid();

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			int cell = grid[i][j];
			grid[i][j] = 0;

			if (!sudoku.isValidPosition(cell, i, j)) {
				grid[i][j] = cell;
				return false;
			}

			grid[i][j] = cell;
		}

	return true;
}

bool Test::testFillDiagonal()
{
	sudoku.resetGrid();
	sudoku.fillDiagonal();

	int(*grid)[9] = sudoku.getGrid();

	// Iterate through each submatrix along the main diagonal
	for (int k = 0; k < 9; k += 3)
		for (int i = k; i < k + 3; ++i)
			for (int j = k; j < k + 3; ++j) {
				int cell = grid[i][j];
				grid[i][j] = 0;

				if (!sudoku.isValidPosition(cell, i, j)) {
					grid[i][j] = cell;
					return false;
				}

				grid[i][j] = cell;
			}

	return true;
}

bool Test::removeCells()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/solved.txt");
	file.readFromFile(sudoku.getGrid());

	sudoku.removeCells();

	int count = 0;

	const int(*grid)[9] = sudoku.getGrid();

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (grid[i][j] == 0)
				++count;

	if (count >= 43 && count <= 60)
		return true;

	return false;
}

bool Test::testCountCellsInSubMatrix()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	int n1 = sudoku.countCellsInSubMatrix(0, 0);
	int n2 = sudoku.countCellsInSubMatrix(3, 0);
	int n3 = sudoku.countCellsInSubMatrix(6, 6);

	bool v1 = n1 == 6;
	bool v2 = n2 == 7;
	bool v3 = n3 == 5;

	return v1 && v2 && v3;
}

bool Test::testAnyGreaterThanSix()
{
	sudoku.resetGrid();
	sudoku.generateSudoku();

	bool v1 = sudoku.anyGreaterThanSix();

	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	bool v2 = sudoku.anyGreaterThanSix();

	return !v1 && v2;
}

bool Test::testCalculateStatistics()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/solved.txt");
	file.readFromFile(sudoku.getGrid());

	sudoku.calculateStatistics();

	if (sudoku.getNumberOfValid() != 81 || sudoku.getNumberOfFaults() != 0)
		return false;

	file.setFileName("../../SV15-2022_David_Stakic/test/solvedError.txt");
	file.readFromFile(sudoku.getGrid());

	sudoku.calculateStatistics();

	if (sudoku.getNumberOfValid() != 72 || sudoku.getNumberOfFaults() != 9)
		return false;

	return true;
}

bool Test::testResetGrid()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testValid.txt");
	file.readFromFile(sudoku.getGrid());

	sudoku.resetGrid();

	const int (*grid)[9] = sudoku.getGrid();

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (grid[i][j] != 0)
				return false;

	return true;
}

bool Test::testFiles()
{
	file.setFileName("../../SV15-2022_David_Stakic/test/testFiles.txt");

	int gridToWrite[9][9] = {
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

	int gridToRead[9][9];


	file.writeIntoFile(gridToWrite);
	file.readFromFile(gridToRead);

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (gridToWrite[i][j] != gridToRead[i][j])
				return false;

	return true;
}

void Test::printResult(const std::string& testName, bool result)
{
	std::cout << testName << ": " << (result ? "Passed" : "Failed") << std::endl;
}

void Test::runTests()
{
	printResult("testIsValidPosition", testIsValidPosition());
	printResult("testIsValidRow", testIsValidRow());
	printResult("testIsValidColumn", testIsValidColumn());
	printResult("testIsValidSubMatrix", testIsValidSubMatrix());

	printResult("testSolveSudoku", testSolveSudoku());
	printResult("testIsSolved", testIsSolved());

	printResult("testGenerateSudoku", testGenerateSudoku());
	printResult("testFillSubmatrix", testFillSubmatrix());
	printResult("testFillDiagonal", testFillDiagonal());
	printResult("removeCells", removeCells());
	printResult("testCountCellsInSubMatrix", testCountCellsInSubMatrix());
	printResult("testAnyGreaterThanSix", testAnyGreaterThanSix());

	printResult("testCalculateStatistics", testCalculateStatistics());
	printResult("testResetGrid", testResetGrid());

	printResult("testFiles", testFiles());
}
