#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Files {
private:
	std::string fileName;
	std::ofstream oFile;
	std::ifstream iFile;

public:
	Files(std::string fileName);

	void writeIntoFile(const int grid[9][9]);
	void readFromFile(int grid[9][9]);
};