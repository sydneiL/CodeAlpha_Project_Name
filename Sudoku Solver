//  Sudoku Solver
//  C++ Task Project For CodeAlpha
//  Created by Sydnei Lang on 3/2/24.


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place 'num' at grid[row][col]
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is already present in the current row or column
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is already present in the current 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col = 0;

    // Find an empty cell
    bool isEmpty = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If no empty cell found, puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers 1 to 9
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recur to solve rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing the number doesn't lead to solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No solution found for current configuration, backtrack
    return false;
}

// Function to generate a solved Sudoku grid
void generateSolvedSudoku(vector<vector<int>>& grid) {
    solveSudoku(grid);
}

// Function to generate Sudoku puzzle of varying difficulty levels
void generateSudoku(vector<vector<int>>& puzzle, int difficulty) {
    // Generate a solved Sudoku grid
    vector<vector<int>> solvedGrid(N, vector<int>(N, 0));
    generateSolvedSudoku(solvedGrid);

    // Copy the solved grid to create a puzzle
    puzzle = solvedGrid;

    // Remove digits based on difficulty level
    int numToRemove;
    switch (difficulty) {
        case 1: numToRemove = 40; break;  // Easy
        case 2: numToRemove = 50; break;  // Medium
        case 3: numToRemove = 60; break;  // Hard
        default: throw invalid_argument("Invalid difficulty level");
    }

    // Remove digits randomly while ensuring solvability
    int removed = 0;
    while (removed < numToRemove) {
        int row = rand() % N;
        int col = rand() % N;
        if (puzzle[row][col] != 0) {
            int backup = puzzle[row][col];
            puzzle[row][col] = 0;

            // Check if puzzle still has a unique solution
            vector<vector<int>> tempGrid = puzzle;
            if (!solveSudoku(tempGrid)) {
                puzzle[row][col] = backup;
            } else {
                ++removed;
            }
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> puzzle(N, vector<int>(N, 0));
    generateSudoku(puzzle, 2); // Generate medium difficulty puzzle
    printGrid(puzzle);
    return 0;
}
