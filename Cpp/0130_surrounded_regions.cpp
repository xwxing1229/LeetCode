// https://leetcode.cn/problems/longest-consecutive-sequence/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int row = 0; row < rows; ++row) {
            backtrack(board, rows, cols, row, 0);
            backtrack(board, rows, cols, row, cols-1);
        }
        for (int col = 1; col < cols-1; ++col) {
            backtrack(board, rows, cols, 0, col);
            backtrack(board, rows, cols, rows-1, col);
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'A') {
                    board[row][col] = 'O';
                }
                else if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
            }
        }
    }

    void backtrack(vector<vector<char>>& board, int rows, int cols, int row, int col) {
        if ((row < 0) || (row >= rows) || (col < 0) || (col >= cols) || (board[row][col] != 'O'))
            return;

        board[row][col] = 'A';

        backtrack(board, rows, cols, row+1, col);
        backtrack(board, rows, cols, row-1, col);
        backtrack(board, rows, cols, row, col+1);
        backtrack(board, rows, cols, row, col-1);
    }
};
