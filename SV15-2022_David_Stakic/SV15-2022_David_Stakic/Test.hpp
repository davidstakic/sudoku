/**
 * @file Test.hpp
 * @brief Defines the Test class, which is designed for testing Sudoku-related functionalities.
 * The class includes various test methods to validate Sudoku-solving algorithms,
 * as well as file-related operations using the Sudoku9 and Files classes.
 * @author David Stakic
 * @date 2023-12-26
 */

#pragma once
#include "Sudoku9.hpp"
#include "Files.hpp"
#include <iostream>

/**
 * @class Test
 * @brief Class for testing Sudoku-related functionalities.
 */
class Test {
public:
    /**
     * @brief Constructor for the Test class.
     */
    Test();

    /**
     * @brief Runs all tests and print results.
     */
    void runTests();

private:
    Sudoku9 sudoku; /* Sudoku9 object used for testing. */
    Files file;     /* Files object used for testing file-related operations. /

    /**
     * @brief Tests the isValidPosition function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testIsValidPosition();

    /**
     * @brief Tests the isValidRow function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testIsValidRow();

    /**
     * @brief Tests the isValidColumn function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testIsValidColumn();

    /**
     * @brief Tests the isValidSubMatrix function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testIsValidSubMatrix();

    /**
     * @brief Tests the solveSudoku function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testSolveSudoku();

    /**
     * @brief Tests the isSolved function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testIsSolved();

    /**
     * @brief Tests the generateSudoku function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testGenerateSudoku();

    /**
     * @brief Tests the fillSubmatrix function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testFillSubmatrix();

    /**
     * @brief Tests the fillDiagonal function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testFillDiagonal();

    /**
     * @brief Tests the removeCells function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool removeCells();

    /**
     * @brief Tests the countCellsInSubMatrix function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testCountCellsInSubMatrix();

    /**
     * @brief Tests the anyGreaterThanSix function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testAnyGreaterThanSix();

    /**
     * @brief Tests the calculateStatistics function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testCalculateStatistics();

    /**
     * @brief Tests the resetGrid function of the Sudoku9 class.
     * @return True if the test passes, false if not.
     */
    bool testResetGrid();

    /**
     * @brief Tests file-related operations using the Files class.
     * @return True if the test passes, false if not.
     */
    bool testFiles();

    /**
     * @brief Prints the result of a test.
     * @param testName The name of the test.
     * @param result True if the test passes, false otherwise.
     */
    void printResult(const std::string& testName, bool result);
};