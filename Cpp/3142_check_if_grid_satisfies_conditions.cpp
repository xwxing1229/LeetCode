// https://leetcode.cn/problems/check-if-grid-satisfies-conditions/

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows-1; ++i) {
            for (int j = 0; j < cols-1; ++j) {
                if (grid[i][j] != grid[i+1][j]) return false;
                if (grid[i][j] == grid[i][j+1]) return false;
            }
        }
        for (int i = 0; i < rows-1; ++i) {
            if (grid[i].back() != grid[i+1].back()) return false;
        }
        for (int j = 0; j < cols-1; ++j) {
            if (grid.back()[j] == grid.back()[j+1]) return false;
        }
        return true;
    }
};