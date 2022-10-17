// https://leetcode.cn/problems/battleships-in-a-board/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int rows = board.size(), cols = board[0].size();
        if (board[0][0] == 'X') {
            res = 1;
        }
        // Just check the upper and left sides.
        for (int col = 1; col < cols; ++col) {
            if ((board[0][col] == 'X') && (board[0][col-1] == '.')) {
                res = res + 1;
            }
        }
        for (int row = 1; row < rows; ++row) {
            if ((board[row][0] == 'X') && (board[row-1][0] == '.')) {
                res = res + 1;
            }
        }
        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (board[row][col] == 'X') {
                    if ((board[row-1][col] == 'X') || (board[row][col-1] == 'X')) {
                        continue;
                    }
                    res = res + 1;
                }
            }
        }
        return res;
    }
};
