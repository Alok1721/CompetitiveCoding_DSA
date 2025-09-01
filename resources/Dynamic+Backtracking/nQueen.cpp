#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> result;
            vector<string> board(n, string(n, '.'));
            solve(0, n, board, result);
            return result;
        }
    
    private:
        // Backtracking function
        void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
            if (row == n) {
                result.push_back(board);
                return;
            }
    
            for (int col = 0; col < n; col++) {
                if (isSafe(board, row, col, n)) {
                    board[row][col] = 'Q';       // place queen
                    solve(row + 1, n, board, result); // move to next row
                    board[row][col] = '.';       // backtrack
                }
            }
        }
    
        // Safety check (only look above current row)
        bool isSafe(vector<string>& board, int row, int col, int n) {
            // check vertical (column)
            for (int i = 0; i < row; i++) {
                if (board[i][col] == 'Q') return false;
            }
    
            // check upper-left diagonal
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }
    
            // check upper-right diagonal
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }
    
            return true;
        }
    };
    
    int main() {
        int n;
        cin >> n;
        Solution solution;
        vector<vector<string>> result = solution.solveNQueens(n);
        for (const auto& board : result) {
            for (const auto& row : board) {
                cout << row << endl;
            }
            cout << endl;
        }
        return 0;
    }