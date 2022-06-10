// https://leetcode.cn/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols, grid[rows-1][cols-1]);

        for (int col = cols-2; col >= 0; --col) {
            dp[col] = grid[rows-1][col] + dp[col+1];
        }

        for (int row = rows-2; row >= 0; --row) {
            dp[cols-1] = grid[row][cols-1] + dp[cols-1];
            for (int col = cols-2; col >= 0; --col) {
                dp[col] = grid[row][col] + min(dp[col], dp[col+1]);
            }
        }

        return dp[0];
    }
};
