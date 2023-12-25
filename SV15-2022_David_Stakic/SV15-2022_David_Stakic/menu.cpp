#include "menu.hpp"

void printMenu()
{
	std::cout << "---- SUDOKU ----" << std::endl;
	std::cout << "(1) Nova igra" << std::endl;
	std::cout << "(2) Izlazak iz aplikacije" << std::endl;
}

void printSettingPicker()
{
	std::cout << "---- SUDOKU ----" << std::endl;
	std::cout << "(1) Ucitaj sudoku zagonetku iz datoteke" << std::endl;
	std::cout << "(2) Izgenerisi postavku sudoku zagonetke" << std::endl;
}

void printSolutionPicker()
{
	std::cout << "---- SUDOKU ----" << std::endl;
	std::cout << "(1) Ucitaj resenje sudoku zagonetke iz datoteke" << std::endl;
	std::cout << "(2) Izgenerisi resenje sudoku zagonetke" << std::endl;
}

void printStats(const int& numberOfValid, const int& numberOfFaults, const int& gameCounter)
{
	std::cout << "Broj tacnih: " << numberOfValid << ", Broj pogresnih: " << 
		numberOfFaults << ", Redni broj igre: " << gameCounter << std::endl;
}
