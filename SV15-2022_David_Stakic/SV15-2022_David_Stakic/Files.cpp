#include "Files.hpp"

Files::Files(std::string fileName) : fileName(fileName), oFile(fileName), iFile(fileName) {}

void Files::writeIntoFile(const int grid[9][9])
{
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) {
            oFile << "-------------------------\n";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) {
                oFile << "| ";
            }
            if (grid[i][j] == 0) {
                oFile << "  ";
            }
            else {
                oFile << grid[i][j] << ' ';
            }
            if (j == 8) {
                oFile << "|";
            }
        }
        oFile << "\n";
    }
    oFile << "-------------------------";
    oFile.close();
}

int** Files::readFromFile()
{
    int** grid = new int* [9];
    char c;
    for (int i = 0; i < 9; ++i) {
        grid[i] = new int[9];
        for (int j = 0; j < 9; ++j) {
            iFile.get(c);
            while (c < '0' || c > '9') {
                iFile.get(c);
                if (c == '-' || c == '\n') {
                    continue;
                }
                else if (c == '|') {
                    iFile.get(c);
                }
                else if (c == ' ') {
                    c = '0';
                }
            }
            grid[i][j] = c - '0';
        }
    }

    iFile.close();

    return grid;
}
