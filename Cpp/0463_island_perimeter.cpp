// https://leetcode.cn/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n_one = 0, n_adj = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    n_one += 1;
                    // Check right and down.
                    if ((j + 1 < cols) && (grid[i][j+1] == 1)) {
                        n_adj += 1;
                    }
                    if ((i + 1 < rows) && (grid[i+1][j] == 1)) {
                        n_adj += 1;
                    }
                }
            }
        }
        int res = n_one * 4 - n_adj * 2;
        return res;
    }
};
