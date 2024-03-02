//  Header.h
//  Sudoku Solver
//  Created by Sydnei Lang on 3/2/24.


#ifndef Header_h
#define Header_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int WINDOW_SIZE = 600;
const int GRID_SIZE = 9;
const int CELL_SIZE = WINDOW_SIZE / GRID_SIZE;

std::vector<std::vector<int>> puzzle = {
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

sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Sudoku Solver");
sf::Font font;

bool isValid(int row, int col, int num) {
    // Check if the number exists in the same row
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (puzzle[row][i] == num) {
            return false;
        }
    }

    // Check if the number exists in the same column
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (puzzle[i][col] == num) {
            return false;
        }
    }

    // Check if the number exists in the same 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (puzzle[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyCell(int& row, int& col) {
    for (row = 0; row < GRID_SIZE; ++row) {
        for (col = 0; col < GRID_SIZE; ++col) {
            if (puzzle[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku() {
    int row, col;
    if (!findEmptyCell(row, col)) {
        return true; // Puzzle solved
    }

    for (int num = 1; num <= GRID_SIZE; ++num) {
        if (isValid(row, col, num)) {
            puzzle[row][col] = num;
            if (solveSudoku()) {
                return true;
            }
            puzzle[row][col] = 0; // Backtrack
        }
    }

    return false; // No solution found
}

void drawGrid() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
            cell.setOutlineThickness(2);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
        }
    }
}

void drawNumbers() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (puzzle[i][j] != 0) {
                sf::Text text(std::to_string(puzzle[i][j]), font, 30);
                text.setPosition(j * CELL_SIZE + 15, i * CELL_SIZE + 5);
                window.draw(text);
            }
        }
    }
}

int main() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Font not found!" << std::endl;
        return -1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    if (solveSudoku()) {
                        std::cout << "Puzzle solved successfully!\n";
                    } else {
                        std::cout << "No solution exists!\n";
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        drawGrid();
        drawNumbers();
        window.display();
    }

    return 0;
}

#endif
/* Header_h */
