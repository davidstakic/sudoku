#include <iostream>
#include <cstring>
#include "Sudoku9.hpp"
#include "Files.hpp"
#include "menu.hpp"
#include "Test.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	if (strcmp(argv[1], "tests") == 0) {
		Test tests;

		tests.runTests();

		return 0;
	}

	const std::string fileName = argv[1];
	Sudoku9 sudoku;
	Files file(fileName);

	file.writeIntoFile(sudoku.getGrid());

	bool isSolved;

	std::string option;

	while (true) {

		printMenu();

		do {
			std::cout << "Opcija >> ";
			std::cin >> option;
		} while (option != "1" && option != "2");

		if (option == "2")
			return 0;

		sudoku.resetGrid();
		file.writeIntoFile(sudoku.getGrid());

		printSettingPicker();

		do {
			std::cout << "Opcija >> ";
			std::cin >> option;
		} while (option != "1" && option != "2");

		if (option == "1") {
			file.readFromFile(sudoku.getGrid());
		}
		else {
			sudoku.generateSudoku();
			file.writeIntoFile(sudoku.getGrid());
		}

		printSolutionPicker();

		do {
			std::cout << "Opcija >> ";
			std::cin >> option;
		} while (option != "1" && option != "2");

		if (option == "1") {
			file.readFromFile(sudoku.getGrid());

			isSolved = sudoku.isSolved();
		}
		else {
			isSolved = sudoku.solveSudoku(0, 0);

			file.writeIntoFile(sudoku.getGrid());
		}

		if (isSolved) {
			std::cout << "Sudoku zagonetka je uspesno resena!" << std::endl;
		}
		else {
			std::cout << "Sudoku zagonetka nije uspesno resena!" << std::endl;
		}

		sudoku.calculateStatistics();

		printStats(sudoku.getNumberOfValid(), sudoku.getNumberOfFaults(), sudoku.getGameCounter());

	}

	return 0;
}