/**
 * @file Files.hpp
 * @brief Defines the Files class, providing functionality for reading from and writing to files for Sudoku grid data.
 * @author David Stakic
 * @date 2023-12-22
 */

#pragma once
#include <string>
#include <iostream>
#include <fstream>

 /**
 * @class Files
 * @brief Manages file operations for reading and writing Sudoku grid data.
 */
class Files {
private:
	std::string fileName;
	std::ofstream oFile;
	std::ifstream iFile;

public:
	/**
	 * @brief Constructs a Files object with the specified file name.
	 * @param fileName The name of the file to be read from or written to.
	*/
	Files(std::string fileName);

	/**
	 * @brief Writes the provided Sudoku grid into the associated file.
	 * @param grid The 9x9 Sudoku grid to be written into the file.
	*/
	void writeIntoFile(const int grid[9][9]);

	/**
	 * @brief Reads a Sudoku grid from the associated file into the provided array.
	 * @param grid The array where the read Sudoku grid will be stored.
	*/
	void readFromFile(int grid[9][9]);
};