/*To use this program:

Replace the example Sudoku grid with your own puzzle (use 0 for empty cells).
Compile and run the program.
It will print the solved Sudoku grid or indicate if no solution exists.*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Size of the Sudoku grid (9x9)

// Check if it's safe to place 'num' at position (row, col)
bool isSafe(vector<vector<int>> &grid, int row, int col, int num)
{
    // Check row and column
    for (int i = 0; i < N; ++i)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i)
    {
        for (int j = startCol; j < startCol + 3; ++j)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(vector<vector<int>> &grid)
{
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; ++num)
                {
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                        {
                            return true;
                        }
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // All cells filled
}

// Print the Sudoku grid
void printGrid(const vector<vector<int>> &grid)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> sudokuGrid(N, vector<int>(N, 0));

    // Input your Sudoku puzzle (0 for empty cells)
    // Example:
    // sudokuGrid = {
    //     {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //     ...
    // };

    if (solveSudoku(sudokuGrid))
    {
        cout << "Sudoku solution:\n";
        printGrid(sudokuGrid);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}
