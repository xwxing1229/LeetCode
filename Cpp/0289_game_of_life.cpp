// https://leetcode.cn/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Check one cell.
                int cnt = 0;
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        int r = row + i, c = col + j;
                        if ((r < 0) || (r >= rows) || (c < 0) || (c >= cols)) {
                            continue;
                        }
                        if ((r == row) && (c == col)) {
                            continue;
                        }
                        // 2: 0 -> 1
                        // 3: 1 -> 0
                        if ((board[r][c] == 1) || (board[r][c] == 3)) {
                            cnt = cnt + 1;
                        }
                    }
                }
                // Update rules.
                if (board[row][col] == 1) {
                    if ((cnt < 2) || (cnt > 3)) {
                        board[row][col] = 3;
                    }
                }
                else {
                    if (cnt == 3) {
                        board[row][col] = 2;
                    }
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 3) {
                    board[row][col] = 0;
                }
                else if (board[row][col] == 2) {
                    board[row][col] = 1;
                }
            }
        }
    }
};
