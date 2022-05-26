// https://leetcode.cn/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check_row[9][9] = {0};
        int check_col[9][9] = {0};
        int check_blk[9][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    int val = c - '0' - 1;
                    check_row[i][val] = check_row[i][val] + 1;
                    check_col[j][val] = check_col[j][val] + 1;

                    int idx_blk = 3 * (i/3) + j/3;
                    check_blk[idx_blk][val] = check_blk[idx_blk][val] + 1;

                    if ((check_row[i][val] > 1) || (check_col[j][val] > 1)
                        || (check_blk[idx_blk][val] > 1)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};