// https://leetcode.cn/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row_max(n), col_max(n);
        for (int i = 0; i < n; ++i) {
            int val_max = 0;
            for (int j = 0; j < n; ++j) {
                val_max = max(val_max, grid[i][j]);
            }
            row_max[i] = val_max;
        }
        for (int j = 0; j < n; ++j) {
            int val_max = 0;
            for (int i = 0; i < n; ++i) {
                val_max = max(val_max, grid[i][j]);
            }
            col_max[j] = val_max;
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return res;
    }
};
