// https://leetcode.cn/problems/shift-2d-grid/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            int moves = (j+k) / n, col = (j+k) % n;
            for (int i = 0; i < m; ++i) {
                int row = (i+moves) % m;
                res[row][col] = grid[i][j];
            }
        }
        return res;
    }
};