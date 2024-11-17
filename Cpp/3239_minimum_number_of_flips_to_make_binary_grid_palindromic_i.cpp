// https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res_row = 0, res_col = 0;
        for (auto &row: grid) {
            int left = 0, right = n-1;
            while (left < right) {
                if (row[left] != row[right]) {
                    res_row += 1;
                }
                left += 1;
                right -= 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            int up = 0, down = m-1;
            while (up < down) {
                if (grid[up][j] != grid[down][j]) {
                    res_col += 1;
                }
                up += 1;
                down -= 1;
            }
        }
        return min(res_row, res_col);
    }
};
