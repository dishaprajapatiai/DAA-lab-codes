#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
    // check upper column
    for(int i = 0; i < row; i++)
        if(board[i][col] == 'Q') return false;

    // upper left diagonal
    for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 'Q') return false;

    // upper right diagonal
    for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
        if(board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, vector<string> &board, int n, vector<vector<string>> &ans) {
    if(row == n) {
        ans.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, n, ans);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, board, n, ans);

   cout << "\nSolutions for " << n << " Queens:\n\n";
for (auto &solution : ans) {
    
    for (auto &row : solution) {
        for(char c : row){
            cout << c << "  "; // <-- EXTRA SPACE
        }
        cout << "\n";
    }
    cout << "\n------------------------\n\n"; // separator
}

    return 0;
}
