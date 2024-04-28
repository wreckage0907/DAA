#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

bool isSafe(vector< vector<int> >& grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector< vector<int> >& grid) {
    int row, col;
    bool found = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(vector< vector<int> >& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector< vector<int> > grid;
    int temp;
    /*
    5 3 0 0 7 0 0 0 0
    6 0 0 1 9 5 0 0 0
    0 9 8 0 0 0 0 6 0
    8 0 0 0 6 0 0 0 3
    4 0 0 8 0 3 0 0 1
    7 0 0 0 2 0 0 0 6
    0 6 0 0 0 0 2 8 0
    0 0 0 4 1 9 0 0 5
    0 0 0 0 8 0 0 7 9
    */
    for(int i=0; i<9; i++) {
        vector<int> temp1;
        for(int j=0; j<9; j++) {
            cin >> temp;
            temp1.push_back(temp);
        }
        grid.push_back(temp1);
   }

    if (solveSudoku(grid)) {
        cout << "Solution:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists.";
    }

    return 0;
}
