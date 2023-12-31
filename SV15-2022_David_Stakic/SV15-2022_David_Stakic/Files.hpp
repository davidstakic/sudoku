/**
 * @file Files.hpp
 * @brief Defines the Files class, providing functionality for reading from and writing to files for Sudoku grid data.
 * @author David Stakic
 * @date 2023-12-26
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
	std::string fileName; /* name of the file */
	std::ofstream oFile; /* Output file stream object used for writing data to a file. */
	std::ifstream iFile; /* Input file stream object used for reading data from a file. */
public:
	/**
	* @brief Default constructor for the Files class.
	* Initializes an instance of the Files class.
	*/
	Files();
	/**
	 * @brief Constructs a Files object with the specified file name.
	 * @param fileName The name of the file to be read from or written to.
	*/
	Files(const std::string& newFileName);
	/**
	 * @brief Destructor for the Files class, removes the associated file.
	 */
	~Files();

	/**
	 * @brief Sets the name of the file that is used by the Files class.
	 * @param fileName The name of the file to be associated with the Files class.
	 * This function allows changing the file name during runtime.
	*/
	void setFileName(const std::string& fileName);

	/**
	 * @brief Writes the provided Sudoku grid into the associated file.
	 * @param grid The 9x9 Sudoku grid to be written into the file.
	*/
	void writeIntoFile(const int grid[9][9]);

	/**
	 * @brief Reads a Sudoku grid from the associated file into the provided array.
	 * @param grid The array where the read Sudoku grid will be stored.
	*/
	void readFromFile(int(*grid)[9]);
};