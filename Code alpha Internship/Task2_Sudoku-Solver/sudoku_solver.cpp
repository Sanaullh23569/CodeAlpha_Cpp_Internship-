#include <iostream>
using namespace std;

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    cout << "\nSolved Sudoku Grid:\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if it's safe to place a number in the given cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // 3x3 box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Solve Sudoku using Backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool empty = false;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    if (!empty)
        return true; // Solved

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0; // backtrack
        }
    }

    return false; // Trigger backtracking
}

int main() {
    // 0 represents empty cells
    int grid[N][N] = {
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

    cout << "Solving Sudoku...\n";
    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists." << endl;

    return 0;
}
