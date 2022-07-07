// https://leetcode.cn/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int res = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    res = res + 1;
                    dfs(grid, row, col);
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> neighbors = {
            {row+1, col}, {row-1, col}, {row, col+1}, {row, col-1}
        };
        for (vector<int> neigh: neighbors) {
            int r = neigh[0], c = neigh[1];
            if ((r >= 0) && (r < rows) && (c >= 0) && (c < cols) && (grid[r][c] == '1')) {
                dfs(grid, r, c);
            }
        }
    }
};
