// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols, 0);
        for (int i = 0; i < rows; ++i) {
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < cols; ++j) {
                dp[j] = max(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp[cols-1];
    }
};
