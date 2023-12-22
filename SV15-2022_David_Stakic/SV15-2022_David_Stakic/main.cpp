#include <iostream>
#include "Sudoku9.hpp"
#include "menu.hpp"

int main() {
	printMenu();

	std::string option;

	do {
		std::cout << "Opcija >> ";
		std::cin >> option;
	} while (option != "1" && option != "2");

	if (option == "2")
		return 0;

	printSettingPicker();

	do {
		std::cout << "Opcija >> ";
		std::cin >> option;
	} while (option != "1" && option != "2");

	if (option == "1") {
		
	}
	else {
		
	}

	printSolutionPicker();

	do {
		std::cout << "Opcija >> ";
		std::cin >> option;
	} while (option != "1" && option != "2");

	if (option == "1") {

	}
	else {

	}

	return 0;
}