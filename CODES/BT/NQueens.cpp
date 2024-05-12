#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector< vector<int> >& board) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board.size(); j++) {
            if(board[i][j]) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

bool isSafe(vector< vector<int> >& board, int row, int col) {
    for(int i=0; i<col; i++) {
        if(board[row][i]) {
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j]) {
            return false;
        }
    }
    for(int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
        if(board[i][j]) {
            return false;
        }
    }
    return true;
}

bool nQueens(vector< vector<int> >& board, int col) {
    int len = board.size();
    if(col >= len) {
        return true;
    }
    for(int i=0; i<len; i++) {
        if(isSafe(board, i, col)) {
            board[i][col] = 1;
            if(nQueens(board, col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > board(n, vector<int>(n, 0));
    if(nQueens(board, 0)) {
        printBoard(board);
    }
    else {
        cout << "Solution does not exist"  << endl;
    }
}